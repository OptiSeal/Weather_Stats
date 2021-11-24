//MENU.cpp - MENU IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

    #include "MENU.h"

    using std::cin;
    using std::cout;
    using std::endl;
    using std::cerr;

    extern const string output_File;

//---------------------------------------------------------------------------------
// MENU Implementation


        //Displays a menu to the screen with a prompt to enter a selection for the user.
    void menu()
    {
        cout << "===============================MAIN MENU====================================" << endl;
        cout << "Menu options are:" << '\n' << endl;
        cout << "1. Display average wind speed and sample standard deviation for a specified month and year." << endl;
        cout << "2. Display average ambient air temperature and sample standard deviation for each month of a specified year." << endl;
        cout << "3. Display total solar radiation in kWh/m2 for each month of a specified year." << endl;
        cout << "4. Print to file - Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/sqm for each month of a specified year." << '\n'
             << "   The standard deviation is printed in () next to the average." << endl;
		cout << "5. Display times for the highest solar radiation for a specified date." << endl;
        cout << "6. Exit program." << '\n' << endl;

        cout << "Your selection: ";
    }


        //Choice selected is executed from this method.
    void execute_Choice(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, unsigned choice)
    {
        Vector<string> monthStr;
            //Inserts strings containing months of the year into Vector
        insert_MthStringVec(monthStr);

        switch (choice)
        {
            case 1:
                cout << "You have selected 1." << endl << endl;
                choice_One(W,loc_yrMap,monthStr);
                break;
            case 2:
               cout << "You have selected 2." << endl << endl;
                choice_Two(W,loc_yrMap,monthStr);
                break;
            case 3:
                cout << "You have selected 3." << endl << endl;
                choice_Three(W,loc_yrMap,monthStr);
                break;
            case 4:
                cout << "You have selected 4." << endl << endl;
                choice_Four(W,loc_yrMap,monthStr);
                break;
            case 5:
                cout << "You have selected 5." << endl << endl;
                choice_Five(W,loc_yrMap,monthStr);
                break;
			case 6:
                cout << "You have selected 6." << endl << endl;
                cout << "Program will now exit..." << endl;
                break;
        }
    }


        //Executes choice one
    void choice_One(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> loc_MthStr)
    {
        unsigned month = 1, year;

        Vector<WeatherType> wPeriod;
        Vector<float> total, mean, stdDev;
        Vector<float> speeds;

        read_Period(month, year, 1);
        insert_PeriodVec(W,wPeriod, loc_yrMap, month, loc_MthStr, year);
        insert_WindSpeedVec(wPeriod,speeds, month);
        conv_MperSec_to_KMperHr(speeds,speeds.get_Size());
        total.insert_Elem(calc_Total(speeds,speeds.get_Size()));
        mean.insert_Elem(calc_Mean(total[0],speeds.get_Size()));
        stdDev.insert_Elem(calc_Stdev(speeds,mean[0],speeds.get_Size()));
        display_Data(loc_MthStr[month],year,mean[0],stdDev[0],total[0],speeds.get_Size(), 1);

        cout << endl;
    }


        //Executes choice two
    void choice_Two(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> loc_MthStr)
    {
        unsigned month = 1, year, i = 0;

        Vector<WeatherType> wPeriod;
        Vector<float> total, mean, stdDev;

        read_Period(month, year, 2);
        cout << year << endl;

        do
        {
            Vector<float> amb_AirTemps;

            insert_PeriodVec(W,wPeriod, loc_yrMap, month, loc_MthStr, year);
            insert_AmbAirTempVec(wPeriod,amb_AirTemps, month);
            total.insert_Elem(calc_Total(amb_AirTemps,amb_AirTemps.get_Size()));
            mean.insert_Elem(calc_Mean(total[i],amb_AirTemps.get_Size()));
            stdDev.insert_Elem(calc_Stdev(amb_AirTemps,mean[i],amb_AirTemps.get_Size()));
            display_Data(loc_MthStr[month],year,mean[i],stdDev[i],total[i],amb_AirTemps.get_Size(), 2);
            month++;
            i++;
        }while(month <=12);

        cout << endl;
    }


        //Executes choice three
    void choice_Three(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> loc_MthStr)
    {
        unsigned month = 1, year, i = 0;

        Vector<WeatherType> wPeriod;
        Vector<float> total, mean, stdDev;

        read_Period(month, year,3);
        cout << year << endl;

        do
        {
            Vector<float> sol_Rads;

            insert_PeriodVec(W,wPeriod, loc_yrMap, month, loc_MthStr, year);
            insert_SolRadVec(wPeriod,sol_Rads, month);
            conv_WtoKW(sol_Rads,sol_Rads.get_Size());
            mean.insert_Elem(0);
            stdDev.insert_Elem(0);
            total.insert_Elem(calc_Total(sol_Rads,sol_Rads.get_Size()));
            display_Data(loc_MthStr[month],year,mean[i],stdDev[i],total[i],sol_Rads.get_Size(), 3);
            month++;
            i++;
        }while(month<=12);

        cout << endl;
    }


        //Executes choice four
    void choice_Four(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> loc_MthStr)
    {
        unsigned month = 1, year, i = 0;
		bool is_Written = true;

        Vector<WeatherType> wPeriod;
        Vector<float> total_Speed, total_AirTemp, total_SolRad;
        Vector<float> mean_Speed, mean_AirTemp, stdDev_Speed, stdDev_AirTemp;

        read_Period(month, year, 4);

        do
        {
            Vector<float> speeds, amb_AirTemps, sol_Rads;

            insert_PeriodVec(W,wPeriod, loc_yrMap, month, loc_MthStr, year);
            insert_WindSpeedVec(wPeriod,speeds,month);
            insert_AmbAirTempVec(wPeriod,amb_AirTemps, month);
            insert_SolRadVec(wPeriod,sol_Rads, month);

            conv_MperSec_to_KMperHr(speeds,speeds.get_Size());
            conv_WtoKW(sol_Rads,sol_Rads.get_Size());

            total_Speed.insert_Elem(calc_Total(speeds,speeds.get_Size()));
            total_AirTemp.insert_Elem(calc_Total(amb_AirTemps,amb_AirTemps.get_Size()));
            total_SolRad.insert_Elem(calc_Total(sol_Rads,sol_Rads.get_Size()));
            mean_Speed.insert_Elem(calc_Mean(total_Speed[i],speeds.get_Size()));
            mean_AirTemp.insert_Elem(calc_Mean(total_AirTemp[i],amb_AirTemps.get_Size()));
            stdDev_Speed.insert_Elem(calc_Stdev(speeds,mean_Speed[i],speeds.get_Size()));
            stdDev_AirTemp.insert_Elem(calc_Stdev(amb_AirTemps,mean_AirTemp[i],amb_AirTemps.get_Size()));

            is_Written = output_ToFile(year,loc_MthStr[month],mean_Speed[i],mean_AirTemp[i],
						 stdDev_Speed[i],stdDev_AirTemp[i],total_SolRad[i], speeds.get_Size(),
						 amb_AirTemps.get_Size(),sol_Rads.get_Size());
            month++;
            i++;
        }while((is_Written == true) && (month <=12));

		if(is_Written == true)
			cout << "Successfully written to file: " << output_File << endl << endl;
    }

        //Executes choice five
	void choice_Five(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> loc_MthStr)
    {
        Date input_Date;
        string input_Str;
        unsigned max_SolarRad = 0;
        Vector<WeatherType> wPeriod;
        Vector<Time> maxTimes;
        bool valid, day_Found = false;

        do{
            valid = true;

            cout << "Enter a date in the form d/m/yyyy: ";
            input_Str = read_Str();

                //Inserts month specfied by user into a seperate vector
            if(add_Date(input_Str,input_Date))
            {
                insert_PeriodVec(W,wPeriod,loc_yrMap,input_Date.get_Month(),
                                 loc_MthStr,input_Date.get_Year());

                unsigned day = input_Date.get_Day();
                unsigned month = input_Date.get_Month();
                unsigned year = input_Date.get_Year();

                cout << "Date: " << day << '/' << month << '/'
                                 << year << endl;

                    //Finds maximum solar radiation if month exists
                if(wPeriod.get_Size() != 0)
                    day_Found = find_MaxSolRad(wPeriod,maxTimes,max_SolarRad,day);

                    //Displays "No Data" if month OR day does not exist, otherwise
                    //the maximum solar radiation and times are displayed
                if(wPeriod.get_Size() == 0 || day_Found == false)
                    cout << "No Data" << endl;
                else
                    display_MaxSolRad(max_SolarRad,maxTimes);

                input_Date.reset_Date();
            }else{
                cout << "INVALID INPUT! Please try again." << endl << endl;
                valid = false;
            }
        }while(valid == false);

        cout << endl;
    }

        //Finds maximum solar radiation and times at which it occured for a specified day
    bool find_MaxSolRad(const Vector<WeatherType> &loc_Period, Vector<Time> &loc_Times, unsigned &loc_MaxSolRad, unsigned loc_Day)
    {
        bool day_Found = false;
        unsigned current_SolRad;

        for(unsigned i = 0; i < loc_Period.get_Size(); i++)
        {
                //If the day in the vector matches the specified day check if its the highest solar radiation and >= 100 W/m2.
            if((loc_Period[i].DT.d.get_Day() == loc_Day) && (round(loc_Period[i].WD.solar_Rad)) >= 100)
            {
                day_Found = true;

                current_SolRad = round(loc_Period[i].WD.solar_Rad);

                    //If solar radiation is higher than the previous, clear the time vector, set previous solar radiation to current
                    //and insert the time it occured into the vector.
                if(current_SolRad > loc_MaxSolRad)
                {
                    if(loc_Times.get_Size() != 0)
                        loc_Times.clear_AllElem();

                    loc_MaxSolRad = round(loc_Period[i].WD.solar_Rad);
                    loc_Times.insert_Elem(loc_Period[i].DT.t);
                }
                    //If solar radiation matches the previous, insert the time it occured into the vector.
                else if(current_SolRad == loc_MaxSolRad)
                    loc_Times.insert_Elem(loc_Period[i].DT.t);
            }
        }

        return day_Found;   //Returns true if the day specified exists int he vector; otherwise returns false.
    }

// ------------------------------------------------------------------------------------------------------
// END of Menu IMPLENTATION FILE
