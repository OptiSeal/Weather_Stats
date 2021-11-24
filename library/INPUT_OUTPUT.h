//INPUT_OUTPUT.h - INPUT and OUTPUT HEADER FILE
//---------------------------------------------------------------------------------
//
// A group of input and output functions required for the WeatherStats program
//
// Author:  Daniel Dobson
// Version: 01
// Date:    09/06/2020
//
//---------------------------------------------------------------------------------

    #ifndef INPUT_OUTPUT_H
    #define INPUT_OUTPUT_H

//---------------------------------------------------------------------------------

    #include <fstream>
    #include <cstring>
    #include <sstream>
    #include <iomanip>

    #include "STRUCTS.h"

//---------------------------------------------------------------------------------

    using std::ifstream;
    using std::ofstream;

    extern const string input_Dir;
    extern const string input_TxtFile;
    extern const string output_File;
    extern const unsigned MIN_YEAR;
    extern const unsigned MAX_YEAR;

//---------------------------------------------------------------------------------
// INPUT AND OUTPUT FUNCTION DECLARATIONS

        /**
        * 	\brief Reads input from file
        *
        *   The text file containing the list of file names is read, with each file
        *   name contained inside this file read in order from first to last. Data
        *   from each of these files are placed inside a map using the 'read_FileData'
        *   HELPER function.
        *
        *   \param loc_Map - A map containing weather data with the date and times as keys
        *   \return true if text file exists; otherwise returns false
       */
    bool read_FileInput(DataMap &loc_Map);

        /**
        * 	\brief HELPER - Reads data from file and inserts data into a Map containing weather data
        *
        *   Data is read from a file and placed inside a map, with duplicates removed.
        *   Data is sorted based on the date and time (as the key) of each entry in the file
        *   (earliest date and time to most recent).
        *   Date and time is stored into the map using the 'add_DateTime' HELPER function.
        *   Speed, solar radiation and ambient air temperature is added directly from this function.
        *
        *   \param input - Input stream
        *   \param loc_W_Map - A map containing weather data with the date and times as keys
       */
    void read_FileData(ifstream &input, DataMap & loc_W_Map);

        /**
        * 	\brief HELPER - Add date and time from input string into a DateTime type
        *
        *   The input string (which contains a date and time) is seperated using a string stream
        *   and added to a DateTime type using the 'add_Date' and 'add_Time' helper functions.
        *
        *   \param input_Str - String containing the date and time
        *   \param loc_DT - A DateTime type containing the date and time objects
        *   \param row_Index - Contains the row index of where the date and time is located
        *   \return true if date and time were valid; otherwise returns false
       */
    bool add_DateTime(string input_Str, DateTime &loc_DT, unsigned row_Index);

        /**
        *   \brief HELPER - Adds a date from input string to a Date object
        *
        *   The input string (which contains a date) is seperated using a string stream
        *   into the day, month and year values. These values are then set into a date object
        *   that is returned by reference back to the caller.
        *
        *   \param input_Str - String containing the date
        *   \param loc_Date - Date object
        *   \return true if a valid date; otherwise returns false
        */
    bool add_Date(string input_Str, Date &loc_Date);

        /**
        *   \brief HELPER - Adds time from input string to a Time object
        *
        *   The input string (which contains a time) is seperated using a string stream
        *   into the hours and minutes. These values are then set into a Time object
        *   that is returned by reference back to the caller.
        *
        *   \param input_Str - String containing the time
        *   \param loc_Time - Time object
        *   \return true if a valid time; otherwise returns false
        */
    bool add_Time(string input_Str, Time &loc_Time);

        /**
        *   \brief Gets the start and end indexes of where each month is located
        *
        *   The function gathers the start and end indexes of where each month is located
        *   in the vector (containing weather data) and stores this data into a map. This map
        *   is returned by reference to the caller
        *
        *   \param W - Vector containing all weather data
        *   \param loc_Yr_Map - A map holding the indexes held for each month of weather data - Year is the key
        */
    void get_PeriodIndex(const Vector<WeatherType> & W, WeatherData_YrMap &loc_Yr_Map);

        /**
        * 	\brief Read a choice from the keyboard
        *
        *   Input must be a number between 1 and 5. User will be prompted to enter
        *   valid input if invalid input is entered.
        *
        *   \return choice - unsigned
       */
    unsigned read_Choice();

        /**
        *   \brief Reads input from the user as a string
        *
        *   \return string containing user input
        */
    string read_Str();

        /**
        * 	\brief Reads month and year from the user and returns by reference
        *
        *   Choice 1 - The user will be prompted to enter a month and year. If invalid input
        *              is entered, the user will be prompted to try again.
        *   Choice 2,3 and 4 - The user will be prompted to enter a year ONLY. If invalid input
        *                      is entered, the user will be prompted to try again.
        *
        *   \param local_Mth - Variable returning the month selected by the user
        *   \param local_Yr - Variable returning the year selected by the user
        *   \param choice - Contains the entered choice
       */
    void read_Period(unsigned &local_Mth, unsigned &local_Yr, unsigned choice);

        /**
        *   \brief Displays maximum solar radiation (in W/m2) for a specified date
        *
        *   Function displays the maximum solar radiation (in W/m2) for a specified date.
        *   The times at which the maximum solar radiation was observed is also
        *   displayed to the user.
        *
        *   \param loc_MaxSolRad - Maximum solar radiation value (in W/m2)
        *   \param loc_Times - A vector containing the Time/s of the maximum solar radiation observation
        */
    void display_MaxSolRad(unsigned loc_MaxSolRad, const Vector<Time> &loc_Times);

        /**
        * 	\brief Displays requested information to the screen.
        *
        *   Choice 1 - Displays the average wind speed (in km/h) and sample standard deviation for a specified
        *              month and year.
        *   Choice 2 - Displays the average ambient air temperature (in degrees C) and sample standard deviation for
        *              each month of a specified year.
        *   Choice 3 - Displays the total solar radiation (in kWh/sqm) for each month of a specified year.
        *
        *   If a month does not contain the requested data, "No Data" will be displayed.
        *
        *   \param local_Mth - Specific month of the year as a string
        *   \param local_Yr - Requested year
        *   \param local_mean - Calculated mean
        *   \param local_Total - Total (sum) of all specified data
        *   \param local_StDev - Sample standard deviation of specified data
        *   \param dataSize - Size (amount) of specified data available
        *   \param choice - Contains the entered choice
       */
    void display_Data(string local_Mth, unsigned local_Yr, float local_mean, float local_Total, float local_StDev,
                      unsigned dataSize, unsigned choice);

        /**
        * 	\brief Prints average wind speed, average ambient air temperature and total solar
        *          radiation in kWh/sqm for each month of a specified year to a specified CSV file.
        *
        *   The year is printed on the first line. On preceeding lines, the month of the year, average wind speed
        *   (in km/h), average ambient air temperature (in degrees C) and total solar radiation (in kWh/sqm) are listed.
        *   Standard deviations are also listed in brackets next to the average wind speed and average ambient
        *   temperature values.
        *
        *   These values are seperated by commas for output to a CSV file.
        *
        *   If data is not available for a particular field, the output field is blank.
        *   If a month contains no data, it will NOT be printed!
        *   This method APPENDS to the file. Any existing data in the CSV file is NOT removed.
        *
        *   \param local_Yr - Requested year
        *   \param local_Mth - Specific month of the year as a string
        *   \param local_MeanSpeed - Mean of wind speeds
        *   \param local_MeanTemp - Mean of ambient air temperatures
        *   \param local_StDevSpeed - Sample standard deviation of wind speeds
        *   \param local_StDevAirTemp - Sample standard deviation of ambient air temperatures
        *   \param local_TotalRad - Total (sum) of solar radiation in kwh/sqm
        *   \param speedSize - Size (amount) of wind speeds available
        *   \param tempSize - Size (amount) of ambient air temperatures available
        *   \param solarSize - Size (amount) of solar radiation data available
       */
    bool output_ToFile(unsigned local_Yr, string local_Mth, float local_MeanSpeed, float local_MeanTemp, float local_StDevSpeed,
                      float local_StDevAirTemp,float local_TotalRad, unsigned speedSize, unsigned tempSize, unsigned solarSize);

//---------------------------------------------------------------------------------
#endif // INPUT_OUTPUT_H
