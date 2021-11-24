//INPUT_OUTPUT.cpp - INPUT and OUTPUT IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

    #include "INPUT_OUTPUT.h"

    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::cerr;
    using std::ios;

//---------------------------------------------------------------------------------

        //Reads input from file
    bool read_FileInput(DataMap &loc_Map)
    {
        ifstream infile;
        string input_File;
        unsigned file_Count = 0;

        infile.open(input_Dir + input_TxtFile);

        if( !infile )
        {
            cerr << "TEXT FILE " << input_TxtFile << " NOT FOUND! ";
            return false;
        }

        //Insert data from files into weatherlog
        while(getline(infile, input_File))
        {
            input_File = input_Dir + input_File;
            ifstream csvFile(input_File);

            if(csvFile)
            {
                cout << "READING " << input_File << "..." << endl;
                read_FileData(csvFile,loc_Map);
                csvFile.close();
                file_Count++;
            }
            else
                cerr << "WARNING: " << input_File << " NOT FOUND!" << endl;
        }

        if(file_Count == 0){
            cerr << '\n' << "PROGRAM CONTAINS NO DATA! ";
            return false;
        }

        infile.close();
        cout << endl;

        return true;
    }

       // HELPER - Reads data from input file and inserts data into a Map containing weather data
    void read_FileData(ifstream &input, DataMap &loc_W_Map)
    {
        string input_String;
        unsigned column_Index = 0, row_Index = 0, prev = 0;
        bool disp_Dup = true;
        bool is_ValidLine = true;

        DateTime temp_DT;
        WeatherData temp_WD;

            //Ignores first line (containing field codes)
        getline(input, input_String,'\n');

        while(getline(input,input_String))
        {
            std::stringstream data(input_String);

            while(is_ValidLine == true && ((getline(data, input_String, ',') || column_Index <= 17)))
            {
                switch(column_Index)
                {
                    case 0: //DATE AND TIME
                        if(!add_DateTime(input_String,temp_DT,row_Index))
                            is_ValidLine = false;
                        break;
                    case 10: //SPEED
                        if(is_Num(input_String) == true)
                            temp_WD.speed = stof(input_String);
                        break;
                    case 11: //SOLAR RADIATION
                        if(is_Num(input_String) == true)
                            temp_WD.solar_Rad = stof(input_String);
                        break;
                    case 17: //AMBIENT AIR TEMP
                        if(is_Num(input_String) == true)
                            temp_WD.amb_AirTemp = stof(input_String);
                        break;
                }
                column_Index++;
            }

            if(is_ValidLine == true){   // Insert temp Weather type
                loc_W_Map.insert(std::pair<DateTime,WeatherData>(temp_DT,temp_WD));

                if(prev == loc_W_Map.size() && disp_Dup == true)
                {
                    cout << "Duplicate time/s were detected and have been discarded!" << endl;
                    disp_Dup = false;
                }

                prev = loc_W_Map.size();
                temp_DT.d.reset_Date();
                column_Index = 0;
            }

            is_ValidLine = true;
            row_Index++;
        }
    }


        //HELPER - Reads date and time from input string and into a DateTime type
    bool add_DateTime(string input_Str, DateTime &loc_DT, unsigned row_Index)
    {
        string local_Str;
        Date temp_Date;
        Time temp_Time;
        bool is_ValidDT = true;

        std::stringstream dateTime(input_Str);
        getline(dateTime,local_Str, ' ');
        is_ValidDT = add_Date(local_Str,temp_Date);

        if(is_ValidDT == true)
        {
            getline(dateTime,local_Str);
            is_ValidDT = add_Time(local_Str,temp_Time);
        }

        if(is_ValidDT == false)
        {
            cerr << "Date and time is invalid in the file at Row# " << row_Index+2;
            cerr << ". This row has been discarded!" << endl;
            return false;
        }

        loc_DT.d = temp_Date;
        loc_DT.t = temp_Time;

        return true;
    }

        //HELPER - Adds a date from input string to a Date object
    bool add_Date(string input_Str, Date &loc_Date)
    {
        string local_Str;

        try{
            std::stringstream date(input_Str);

            getline(date,local_Str, '/');
            loc_Date.set_Day(stoi(local_Str));
            getline(date,local_Str, '/');
            loc_Date.set_Month(stoi(local_Str));
            getline(date,local_Str);

            if(stoul(local_Str) < MIN_YEAR || stoul(local_Str) > MAX_YEAR)
              throw std::out_of_range("Error");
            else
                loc_Date.set_Year(stoi(local_Str));
        }catch(...){
            return false;
        }

        return true;
    }

        //HELPER - Adds time from input string to a Date object
    bool add_Time(string input_Str, Time &loc_Time)
    {
        string local_Str;

        try{
            std::stringstream time(input_Str);

            getline(time,local_Str,':');
            loc_Time.set_Hours(stoi(local_Str));
            getline(time,local_Str);
            loc_Time.set_Mins(stoi(local_Str));
        }catch(...){
            return false;
        }

        return true;
    }

        //Gets the start and end indexes of where each month is located
    void get_PeriodIndex(const Vector<WeatherType> & W, WeatherData_YrMap &loc_Yr_Map)
    {
        PeriodIndex mth_Period;
        Bst<PeriodIndex> mth_PeriodBST;
        Vector<string> monthStr;
        unsigned month = 0, year = 0;

            //Get month (word) strings
        insert_MthStringVec(monthStr);

        for(unsigned index = 0; index < W.get_Size(); index++)
        {
            if(W[index].DT.d.get_Month() != month)
            {
                    //Set end index for previous month and insert PeriodIndex object
                    //containing the previous month into BST (if not 0)
                if(month != 0)
                {
                    mth_Period.set_EndIndex(index-1);
                    mth_PeriodBST.insert_Elem(mth_Period);
                }
                    //Insert BST containing all months for the year into the map
                if(W[index].DT.d.get_Year() != year)
                {
                    if(year != 0)
                    {
                        loc_Yr_Map.insert(std::pair<unsigned,Bst<PeriodIndex>>(year,mth_PeriodBST));
                        mth_PeriodBST.delete_Tree();
                    }
                        //Set current year to next indexed year in vector
                    year = W[index].DT.d.get_Year();
                }
                    //Set current month to next indexed month in vector
                month = W[index].DT.d.get_Month();
                mth_Period.set_Month(monthStr[month]);
                    //Set start index for current month
                mth_Period.set_StartIndex(index);
            }
        }

        if(year !=0 && month !=0)
        {
            mth_Period.set_EndIndex(W.get_Size()-1);
            mth_PeriodBST.insert_Elem(mth_Period);
            loc_Yr_Map.insert(std::pair<unsigned,Bst<PeriodIndex>>(year,mth_PeriodBST));
            mth_PeriodBST.delete_Tree();
        }
    }

        //Read a choice from the keyboard
        //If a choice is not equal to '1','2','3','4','5' or '6', the user must try again.
    unsigned read_Choice()
    {
        string str;
        bool valid;

        do{
            valid = true;

            try{

                str = read_Str();

                if(strchr("123456",str[0]) == NULL || str.size() > 1)
                {
                    throw std::invalid_argument("");
                }
            }catch(std::exception e){
                cerr << "INVALID INPUT! Please try again." << endl;
                valid = false;
            }

        }while(valid == false);

        return (stoi(str));
    }


        //Reads input from the user as a string
    string read_Str()
    {
        string str;
        bool valid;

        do{
            valid = true;

            try{
                getline(cin,str);
                cout << endl;

                if(str.empty())
                    throw std::invalid_argument("");
            }catch(std::exception e){
              cerr << "INVALID INPUT! Please try again." << endl;
              valid = false;
            }
        }while(valid == false);

        return str;
    }

            //Reads month and year from the user and returns by reference
        //If the input is not valid, the user must try again.
    void read_Period(unsigned &local_Mth, unsigned &local_Yr, unsigned choice)
    {
        string temp_Mth = "1", temp_Yr;
        bool valid, valid_Mth = false;

            //Loop will continue until user enters a valid year (and month - option 1)
        do{
            valid = true;

            try{
                    //If choice is '1', user is to enter a month
                if(choice == 1 && valid_Mth == false)
                {
                    cout << "Please enter a month (must be numeric. i.e. 1 for January): ";
                    getline(cin,temp_Mth);

                    if(is_Num(temp_Mth) == false || ((stoi(temp_Mth)<1) || (stoi(temp_Mth) > 12))){
                        valid_Mth = false;
                        throw std::out_of_range("");
                    }

                    valid_Mth = true;
                }

                cout << "Please enter a year: ";
                getline(cin,temp_Yr);
                cout << endl;

                if((is_Num(temp_Yr) == false) || (stoul(temp_Yr) < MIN_YEAR) || (stoul(temp_Yr) > MAX_YEAR))
                {
                    throw std::out_of_range("");
                }
            }catch(std::out_of_range){
                cout << endl << "INVALID INPUT! Please try again." << endl << endl;
                valid = false;
            }
        }while(valid == false);

        if(choice == 1)
            local_Mth = stoi(temp_Mth);

        local_Yr = stoi(temp_Yr);
    }

        //Displays maximum solar radiation (in W/m2) for a specified date
    void display_MaxSolRad(unsigned loc_MaxSolRad, const Vector<Time> &loc_Times)
    {
        cout << "High solar radiation for the day: " << loc_MaxSolRad << " W/m2" << endl << endl;
        cout << "Times: " << endl;

        for(unsigned i = 0; i < loc_Times.get_Size(); i++)
        {
                cout << loc_Times[i].get_Hours() << ':';

                if(loc_Times[i].get_Mins() < 10)
                    cout << '0';

                cout << loc_Times[i].get_Mins() << endl;
        }
    }

        //Displays requested information to the screen.
    void display_Data(string local_Mth, unsigned local_Yr, float local_mean, float local_StDev, float local_Total, unsigned dataSize, unsigned choice)
    {
        switch(choice)
        {
            case 1: //Choice '1'
                cout << local_Mth << ' ' << local_Yr << ": ";

                if(dataSize != 0)
                {
                    cout << '\n' << "Average speed: " << std::fixed
                         << std::setprecision(1) << local_mean << " km/h" << endl;
                    cout << "Sample stdev: " << std::fixed
                         << std::setprecision(1) << local_StDev << '\n' << endl;
                }
                else
                    cout << "No Data" << '\n' << endl;
                break;
            case 2: //Choice '2'
                if(dataSize !=0)
                    cout << local_Mth << ": " << "average: " << std::fixed
                         << std::setprecision(1) << local_mean << " degrees C, stdev: " << std::fixed
                         << std::setprecision(1) << local_StDev << endl;
                else
                    cout << local_Mth << ": " << "No Data" << endl;
                break;
            case 3: //Choice '3'
                if(dataSize !=0)
                    cout << local_Mth << ": " << std::fixed
                         << std::setprecision(1) << local_Total << " kWh/m2" << endl;
                else
                    cout << local_Mth << ": " << "No Data" << endl;
                break;
        }
    }

        //Prints average wind speed, average ambient air temperature and total solar
        //radiation in kWh/sqm for each month of a specified year to a specified CSV file.
    bool output_ToFile(unsigned local_Yr, string local_Mth, float local_MeanSpeed, float local_MeanTemp,
                          float local_StDevSpeed, float local_StDevAirTemp, float local_TotalRad, unsigned speedSize, unsigned tempSize, unsigned solarSize)
    {
        ofstream ofile(output_File, ios::app);
        if(!ofile)
        {
            cout << "FILE COULD NOT OPEN! Please check file is not open before trying again." << endl;
			return false;
        }
		else
		{

			static unsigned counter = 0;    // Number of lines printed
			static unsigned empty_Counter = 0;  //Number of months with no data

				//Prints the year on the first line
			if(counter == 0)
				ofile << local_Yr << endl;
				//If data exists for the month, print data. Otherwise increment empty counter.
			if(!(speedSize == 0 && tempSize == 0 && solarSize == 0))
			{
				ofile << local_Mth << ',';

				if(speedSize != 0)
					ofile << std::fixed << std::setprecision(1) << local_MeanSpeed << '(' << local_StDevSpeed << "),";
				else
					ofile << " ,";  //No speed data

				if(tempSize != 0)
					ofile << std::fixed << std::setprecision(1) << local_MeanTemp << '(' << local_StDevAirTemp << "),";
				else
					ofile << " ,";  //No temperature data

				if(solarSize != 0)
					ofile << std::fixed << std::setprecision(1) << local_TotalRad;

				ofile << endl;
			}
			else
				empty_Counter++;  //No data for the month

			counter++;
				//If the year has been printed, set counters to 0.
			if(counter == 12)
			{       //If the year contains no data, print "No Data".
				if(empty_Counter == 12)
					ofile << "No Data" << endl;

				empty_Counter = 0;
				counter = 0;
			}
		}

		return true;
    }

// ------------------------------------------------------------------------------------------------------
// END of Input and Output IMPLENTATION FILE
