// MAIN.cpp - WeatherStats (Assignment 2) MAIN FILE
//
// Author: Daniel Dobson
// Date: 11/06/2020
//
// Opens an input file stream containing a list of file names and the files are read into a WeatherType
// object containing: a list of dates, times, wind speed, ambient air temperature and solar radiation.
// A menu is displayed giving 6 choices for the user to choose from. Depending on the choices 1-4,
// the read data has it's total, mean and standard deviation calculated for a given month and
// year. It is either displayed to the screen or printed into a specified CSV file. Option 5 gives the
// user the option to enter a specific date where the maximum solar radiation value (in W/m2) for the day
// will be displayed and the times at which the maximum radiation value occured. The menu
// will redisplay giving the user the option to select another choice. If the user selects
// choice '6', the program will exit.
//
// main.cpp - contains the main function for the program to execute. All other
//            functions are contained in dedicated files related to their type as shown below.
// ------------------------------------------------------------------------------------------------------
// INPUT_OUTPUT - A group of input and output related functions for the WeatherStats program.
// MENU - A group of functions related to the execution of the WeatherStats program.
//        These functions display and execute a range of options from a specified menu
//        displayed to the screen with user input from the keyboard.
// STRUCTS - Contains structs related to the WeatherStats program with additional functions to assist
//           the with insertion of data into Maps and Vectors of these related structs.
// UTILITIES - A group of general templated functions. These include checking if a string
//             is a number, inserting months of the year into a Vector and various conversions
//             and calculations.
//
//  ------------------------------------------------
//  This program also ultises the following classes:
//  ------------------------------------------------
//  BST - Binary Search Tree
//  COLLECTDATA - A template class that collects and stores data
//  DATE - A class that stores dates
//  TIME - A class that stores times
//  PERIODINDEX - A class containing string of months (in words), starting and ending index values
//  VECTOR - A Vector class containing an encapsulated array
// ------------------------------------------------------------------------------------------------------

    #include "library/MENU.h"

//-------------------------------------------------------------------------------------------------------

    using std::cout;
    using std::endl;
    using std::string;

    const string input_Dir = "data/";
    const string input_TxtFile = "met_index.txt";
    const string output_File = "WindTempSolar.csv";
    const unsigned MIN_YEAR = 1998;
    const unsigned MAX_YEAR = 2020;

//-------------------------------------------------------------------------------------------------------
// MAIN PROGRAM:

    int main()
    {
        string input_File;
        unsigned choice;

        DataMap W_Map;
        WeatherData_YrMap yrMap;
        Vector<WeatherType> weatherlog;

        cout << '\n' << "=========================WELCOME TO THE PROGRAM=============================" << endl;

            //Read input from file/s
        if(read_FileInput(W_Map) == false){
            cout << "Program will exit..." << endl;
            return -1;
        }

            //Insert data from map into vector
        insert_MaptoVec(W_Map, weatherlog);
        W_Map.clear();

            //Get start and end indexes of where each month is located
        get_PeriodIndex(weatherlog, yrMap);

        cout << "WEATHER DATA LOADED SUCCESSFULLY!" << endl << endl;

        //Display menu, get choice and execute choice. Choice '6' exits the program.
        do
        {
            menu();
            choice = read_Choice();
            execute_Choice(weatherlog, yrMap, choice);
        }while(choice != 6);

        return 0;
    }

// ------------------------------------------------------------------------------------------------------
// END OF MAIN PROGRAM
