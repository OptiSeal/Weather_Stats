// STRUCTS.h - Structs HEADER FILE
//---------------------------------------------------------------------------------

    #ifndef STRUCTS_H
    #define STRUCTS_H

//---------------------------------------------------------------------------------

    #include <map>

// --------------------------------------------------------------------------------

    #include "DATE.h"
    #include "TIME.h"
    #include "PERIODINDEX.h"
    #include "COLLECTDATA.h"
    #include "UTILITIES.h"

//---------------------------------------------------------------------------------
// STRUCT TYPE DECLARATIONS


        /**
         * \struct  DateTime
         *
         * \brief   A struct containing a Date and Time
         *
         * \author  Daniel Dobson
         * \version 01
         * \date    04/06/2020
        */
    struct DateTime
    {
        DateTime():d(), t(){};
            /// Date
        Date d;
            /// Time
        Time t;
    };


        /**
         * \struct  WeatherData
         *
         * \brief   A struct containing Wind Speed, Solar Radiation
         *          and Ambient Air Temperature variables.
         *
         * \author  Daniel Dobson
         * \version 01
         * \date    04/06/2020
        */
    struct WeatherData
    {
            /// Wind Speed
        float speed = -1;
            /// Solar Radiation
        float solar_Rad = -1;
            /// Ambient Air Temperature
        float amb_AirTemp = -100;
    };


        /**
         * \struct  WeatherType
         *
         * \brief   A struct containing a Date, Time, Wind Speed, Solar Radiation
         *          and Ambient Air Temperature variables. Various functions defined
         *          in this header file insert data into specialised vectors.
         *
         * \author  Daniel Dobson
         * \version 01
         * \date    03/05/2020
        */
    struct WeatherType
    {
            /// DateTime struct holding the date and time
        DateTime DT{};
            /// WeatherData struct holding speed, solar radiation and ambient air temperature
        WeatherData WD{};
    };

        /// A map containing weather data for each observation time - Date and Time are keys
    typedef std::map<DateTime,WeatherData> DataMap;
        /// A map holding the indexes held for each month of weather data - Year is the key
    typedef std::map<unsigned,Bst<PeriodIndex>> WeatherData_YrMap;

//---------------------------------------------------------------------------------
// STRUCT RELATED FUNCTION DECLARATIONS

        /**
        *   \relates WeatherType
        * 	\brief Inserts data from the DataMap into a vector of WeatherType
        *
        *   The data contained inside the map is inserted into the vector in order using a
        *   const interator from the beginning of the map to the end.
        *
        *   \param loc_Map - Map containing weather data
        *   \param W - New vector
       */
    void insert_MaptoVec(const DataMap &loc_Map, Vector<WeatherType> &W);

       /**
        *   \relates WeatherType
        * 	\brief Inserts data for a specified month and year into a vector
        *
        *   Elements are inserted into the new vector from an existing vector if the
        *   data contained in the existing vector contains the specified month and
        *   year provided.
        *
        *   A map containing the indexes for the specified month and year are provided to assist
        *   the insertion of elements from the existing vector into the new vector. The new vector
        *   will only contain weather data for the specified month and year (if data exists).
        *
        *   \param W - Existing vector
        *   \param otherW - New vector
        *   \param loc_yrMap - A map holding indexes for each month
        *   \param loc_Mth - unsigned (Specified month)
        *   \param loc_MthStr - Vector containing months as word strings
        *   \param loc_Yr - unsigned (Specified year)
       */
    void insert_PeriodVec(const Vector<WeatherType> & W, Vector<WeatherType> & otherW, WeatherData_YrMap &loc_yrMap, unsigned loc_Mth, Vector<string> loc_MthStr, unsigned loc_Yr);

       /**
        *   \relates WeatherType
        * 	\brief Inserts data containing wind speeds from the specified month and year into a vector
        *
        *   Wind Speed data is inserted into a seperate vector from an existing vector if the
        *   data contained in the existing vector contains wind speed data that is from the month
        *   requested.
        *
        *   \param W - Existing vector
        *   \param otherW - New vector
        *   \param loc_Mth - Specified month
       */
    void insert_WindSpeedVec(const Vector<WeatherType> & W, Vector<float> & otherW, unsigned loc_Mth);

       /**
        *   \relates WeatherType
        * 	\brief Inserts data containing ambient air temperature values in degrees Celcius
        *          from a month of a specified year into a vector
        *
        *   Ambient air temperature data is inserted into a seperate vector from an existing
        *   vector if the data contained in the existing vector contains ambient air temperature data that
        *   is from the month requested.
        *
        *   \param W - Existing vector
        *   \param otherW - New vector
        *   \param loc_Mth - Specified month
       */
    void insert_AmbAirTempVec(const Vector<WeatherType> & W, Vector<float> & otherW, unsigned loc_Mth);

       /**
        *   \relates WeatherType
        * 	\brief Inserts data containing solar radiation values greater than 100 Watts per square metre
        *          from a month of a specified year into a vector.
        *
        *   Solar radiation data is inserted into a seperate vector from an existing
        *   vector if the data contained in the existing vector contains ambient air temperature data that
        *   is from the month requested and is greater than 100 Watts per square metre.
        *
        *   \param W - Existing vector
        *   \param otherW - New vector
        *   \param loc_Mth - Specified month
       */
    void insert_SolRadVec(const Vector<WeatherType> & W, Vector<float> & otherW, unsigned loc_Mth);

        /**
        *   \relates DateTime
        * 	\brief Compares equality of DateTime types
        *
        *   \param this_DT - First DateTime type
        *   \param other_DT - Second DateTime type
        *   \post Returns true if DateTime types are equal; otherwise returns false
       */
    bool operator==(const DateTime &this_DT, const DateTime &other_DT);


        /**
        *   \relates DateTime
        * 	\brief Checks if first DateTime type is less than the other
        *
        *   \param this_DT - First DateTime type
        *   \param other_DT - Second DateTime type
        *   \post Returns true if DateTime types are equal; otherwise returns false
       */
    bool operator<(const DateTime &this_DT, const DateTime &other_DT);

// ------------------------------------------------------------------------------------------------------
#endif // STRUCTS_H
