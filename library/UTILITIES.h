// UTILITIES.h - UTILITIES HEADER FILE
//---------------------------------------------------------------------------------
//
// A group of general templated methods.
// These include checking if a string is a number, inserting months of the
// year into a Vector and various conversions and calculations.
//
// Author:  Daniel Dobson
// Version: 01
// Date:    03/05/2020
//
//---------------------------------------------------------------------------------

    #ifndef UTILITIES_H
    #define UTILITIES_H

//---------------------------------------------------------------------------------

    #include <string>
    #include <math.h>

    #include "VECTOR.h"

    using std::string;

//---------------------------------------------------------------------------------
// UTILITIES FUNCTION DECLARATIONS

       /**
        * 	\brief Checks if string is a number
        *
        *   This method checks a string to determine if it is a number.
        *   This includes whole and floating-point numbers. Returns true if string
        *   contains a number, otherwise returns false.
        *
        *   \param str - CONST string by reference
        *   \return true or false - boolean
       */
    bool is_Num(const string& str);

       /**
        * 	\brief Inserts months of the year into a Vector of type string
        *
        *   \param local_Mth - Vector<string> by reference
       */
    void insert_MthStringVec(Vector<string> &local_Mth);

       /**
        * 	\brief Calculates total of a given array
        *
        *   \param local_Array - CONST T type by reference
        *   \param array_Size - unsigned size of array
        *   \return total - float
       */
    template <class T>
    float calc_Total (const T& local_Array, unsigned array_Size);

       /**
        * 	\brief Calculates mean (average) from total and array_Size
        *
        *   \param local_Total - CONST T type by reference
        *   \param array_Size - unsigned size of array
        *   \return mean - float
       */
    template <class T>
    float calc_Mean (const T& local_Total, unsigned array_Size);

       /**
        * 	\brief Calculates sample standard deviation of array from calculated mean
        *
        *   \param local_Array - CONST T type by reference
        *   \param local_Mean - float calculated mean
        *   \param array_Size - unsigned size of array
        *   \return stdev - float
       */
    template <class T>
    float calc_Stdev (const T& local_Array, float local_Mean, unsigned array_Size);

       /**
        * 	\brief Converts Watts per square metre to KiloWatt hour per square metre
        *
        *   \param local_Array - T type by reference
        *   \param array_Size - unsigned size of array
       */
    template <class T>
    void conv_WtoKW(T& local_Array, unsigned array_Size);

       /**
        * 	\brief Converts Meters per second to Kilometres per hour
        *
        *   \param local_Array - T type by reference
        *   \param array_Size - unsigned size of array
       */
    template <class T>
    void conv_MperSec_to_KMperHr(T& local_Array, unsigned array_Size);

//---------------------------------------------------------------------------------
// template IMPLEMENTATION


        //Calculate total of a given array
    template <class T>
    float calc_Total (const T& local_Array, unsigned array_Size)
    {
        float total = 0;

            //Add array elements together in a temporary variable
        for(unsigned i = 0; i < array_Size; i++)
            {
                total += local_Array[i];
            }

            //Return total
        return total;
    }

        //Calculate mean (average)
    template <class T>
    float calc_Mean (const T& local_Total, unsigned array_Size)
    {
        return ((float) local_Total / array_Size);
    }


        //Calculate sample standard deviation of a given array
    template <class T>
    float calc_Stdev (const T& local_Array, float local_Mean, unsigned array_Size)

    {
        float local_Stdev = 0;

        if(array_Size > 1)
        {
                //Add result of squaring array elements minus the local mean to a temporary variable
            for(unsigned i = 0; i < array_Size; i++)
            {
                local_Stdev += (local_Array[i] - local_Mean) * (local_Array[i] - local_Mean);
            }

            local_Stdev = sqrt(local_Stdev / (array_Size - 1));
        }
            //Return standard deviation calculation
        return local_Stdev;
    }


        //Convert Watts per hour to KiloWatts per hour
    template <class T>
    void conv_WtoKW(T& local_Array, unsigned array_Size)
    {
        for(unsigned i = 0; i < array_Size; i++)
        {
            local_Array[i] = ((local_Array[i]/6)/1000);
        }
    }

		//Convert Metres per second to Kilometres per hour
    template <class T>
    void conv_MperSec_to_KMperHr(T& local_Array, unsigned array_Size)
    {
        for(unsigned i = 0; i < array_Size; i++)
        {
            local_Array[i] = (((local_Array[i]*60)*60)/1000);
        }
    }

//---------------------------------------------------------------------------------
#endif // UTILITIES_H
