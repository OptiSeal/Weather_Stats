// MENU.h - HEADER FILE
//-----------------------------------------------------------------------------------------------
//
// 	A group of functions related to the execution of the WeatherStats program.
//  These functions display and execute a range of options from a specified menu
//  displayed to the screen.
//  These functions have been seperated to declutter the main.cpp file.
//
//  Author:  Daniel Dobson
//  Version: 02
//  Date:    09/06/2020
//
//         - Functions have been modified to accomodate a map holding the indexes
//           held for each month of weather data
//         - Functions involving user input and output have been moved to a
//           dedicated file called INPUT_OUTPUT
//         - An additional menu option has been added to allow the user to view
//           the highest solar radiation of a specified day with the times at which
//           it occured.
//
//-----------------------------------------------------------------------------------------------

    #ifndef MENU_H
    #define MENU_H

//-----------------------------------------------------------------------------------------------

    #include <cmath>

    #include "INPUT_OUTPUT.h"

//-----------------------------------------------------------------------------------------------
// MENU FUNCTION DECLARATIONS

        /**
        * 	\brief Displays a menu to the screen with a prompt to enter a selection for the user.
        */
    void menu();

        /**
        * 	\brief Choice selected is executed from this method.
        *
        *   Execution will call a method dedicated to the choice selected.
        *   Choice 5 will exit the program.
        *
        *   \param W - Contains all WeatherType data
        *   \param loc_yrMap - A map holding the indexes held for each month of weather data
        *   \param ch - Selected choice
       */
    void execute_Choice(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, unsigned choice);

        /**
        * 	\brief Executes choice one
        *
        *   Displays the average wind speed (in km/h) and sample standard deviation for a specified
        *   month and year.
        *
        *   \param W - Contains all WeatherType data
        *   \param loc_yrMap - A map holding the indexes held for each month of weather data
        *   \param local_MthStr - Contains months of the year as a Vector of strings
       */
    void choice_One(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> local_MthStr);

        /**
        * 	\brief Executes choice two
        *
        *   Displays the average ambient air temperature (in degrees C) and sample standard deviation for
        *   each month of a specified year.
        *
        *   \param W - Contains all WeatherType data
        *   \param loc_yrMap - A map holding the indexes held for each month of weather data
        *   \param local_MthStr - Contains months of the year as a Vector of strings
       */
    void choice_Two(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> local_MthStr);

        /**
        * 	\brief Executes choice three
        *
        *   Displays the total solar radiation (in kWh/m2) for each month of a specified year.
        *
        *   \param W - Contains all WeatherType data
        *   \param loc_yrMap - A map holding the indexes held for each month of weather data
        *   \param local_MthStr - Contains months of the year as a Vector of strings
       */
    void choice_Three(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> local_MthStr);

        /**
        * 	\brief Executes choice four
        *
        *   Print to file - Average wind speed (km/h), average ambient air temperature (in degrees C) and
        *   total solar radiation (in kWh/sqm) for each month of a specified year.
        *   The standard deviation is printed in () next to the average.
        *
        *   \param W - Contains all WeatherType data
        *   \param loc_yrMap - A map holding the indexes held for each month of weather data
        *   \param local_MthStr - Contains months of the year as a Vector of strings
       */
    void choice_Four(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> local_MthStr);

        /**
        *   \brief Executes choice five
        *
        *   Displays the highest solar radiation (W/m2) of a specified day with the times at which it occured.
        *   The function seperates the month specified from the vector containing all weather data to a seperate
        *   vector before calling 'find_MaxSolRad'. The called function returns the maximum solar radiation value
        *   and times at which it occured.
        *
        *   If there is no data contained for the day specified by the user, the function will skip the call to
        *   the 'find_MaxSolRad' function and will display "No Data" to the user.
        *
        *   \param W - Contains all WeatherType data
        *   \param loc_yrMap - A map holding the indexes held for each month of weather data
        *   \param loc_MthStr - A vector holding month (word) strings
        */
	void choice_Five(const Vector<WeatherType> & W, WeatherData_YrMap &loc_yrMap, Vector<string> loc_MthStr);

        /**
        *   \brief Finds maximum solar radiation and times at which it occured for a specified day
        *
        *   Function searches through the provided vector and finds the maximum solar radiation for
        *   the day provided. Times at which the solar radiation occurs is inserted into a vector
        *   and returned by reference. The maximum solar radiation is also returned by reference.
        *   A boolean value will return true if the day specified was found in the vector provided;
        *   otherwise it will return false.
        *
        *   \param loc_Period - Period containing weather data for a specified month and year
        *   \param loc_Times - A vector containing the Time/s of the maximum solar radiation observation
        *   \param loc_MaxSolRad - Maximum solar radiation value (in W/m2)
        *   \param loc_Day - Day specified by the user
        */
	bool find_MaxSolRad(const Vector<WeatherType> &loc_Period, Vector<Time> &loc_Times, unsigned &loc_MaxSolRad, unsigned loc_Day);

//---------------------------------------------------------------------------------------------------------------------------------
#endif  // MENU_H
