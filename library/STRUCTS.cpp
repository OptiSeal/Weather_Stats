//STRUCTS.cpp - Structs IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

    #include "STRUCTS.h"

//---------------------------------------------------------------------------------

        //Inserts data from the DataMap into a vector of WeatherType
    void insert_MaptoVec(const DataMap &loc_Map, Vector<WeatherType> &W)
    {
        WeatherType temp_WT;

        DataMap::const_iterator itr;

        for(itr = loc_Map.cbegin(); itr != loc_Map.cend(); ++itr)
        {
            temp_WT.DT.d = itr->first.d;
            temp_WT.DT.t = itr->first.t;
            temp_WT.WD.speed = itr->second.speed;
            temp_WT.WD.solar_Rad = itr->second.solar_Rad;
            temp_WT.WD.amb_AirTemp = itr->second.amb_AirTemp;

            W.insert_Elem(temp_WT);
        }
    }

        //Inserts data containing data for a specified month and year into a vector
    void insert_PeriodVec(const Vector<WeatherType> & W, Vector<WeatherType> & otherW, WeatherData_YrMap &loc_yrMap, unsigned loc_Mth, Vector<string> loc_MthStr, unsigned loc_Yr)
    {
        PeriodIndex mth_Period;
        CollectData<PeriodIndex> C;

        mth_Period.set_Month(loc_MthStr[loc_Mth]);

        if(loc_yrMap[loc_Yr].search_Retrieve(mth_Period,CollectData<PeriodIndex>::collData))
        {
            for(unsigned i = C[C.size()-1].get_StartIndex(); i < C[C.size()-1].get_EndIndex(); i++)
                otherW.insert_Elem(W[i]);
        }
    }


        //Inserts data containing wind speeds from the specified month and year into a vector
    void insert_WindSpeedVec(const Vector<WeatherType> & W, Vector<float> & otherW, unsigned loc_Mth)
    {
        for(unsigned i = 0; i < W.get_Size(); i++)
        {
            if((W[i].DT.d.get_Month() == loc_Mth) && (W[i].WD.speed >= 0))
                otherW.insert_Elem(W[i].WD.speed);
        }
    }


        //Inserts data containing ambient air temperature values in degrees Celcuis from a month of a specified year into a vector
    void insert_AmbAirTempVec(const Vector<WeatherType> & W, Vector<float> & otherW, unsigned loc_Mth)
    {
        for(unsigned i = 0; i < W.get_Size(); i++)
        {
            if((W[i].DT.d.get_Month() == loc_Mth) && (W[i].WD.amb_AirTemp > -100))
                otherW.insert_Elem(W[i].WD.amb_AirTemp);
        }
    }


        //Inserts data containing solar radiation values greater than 100 Watts per square metre from a month of a specified year into a vector.
    void insert_SolRadVec(const Vector<WeatherType> & W, Vector<float> & otherW, unsigned loc_Mth)
    {
        //int counter = 0;

        for(unsigned i = 0; i < W.get_Size(); i++)
        {
            if((W[i].DT.d.get_Month() == loc_Mth) && (W[i].WD.solar_Rad >= 100))
                 otherW.insert_Elem(W[i].WD.solar_Rad);
        }
    }

        //Compares equality of DateTime types
    bool operator==(const DateTime &this_DT, const DateTime &other_DT)
    {
        return ((this_DT.d == other_DT.d) && (this_DT.t == other_DT.t));
    }

        //Compares equality of DateTime types
    bool operator<(const DateTime &this_DT, const DateTime &other_DT)
    {
        return ((this_DT.d < other_DT.d) ||
                ((this_DT.d == other_DT.d) && (this_DT.t < other_DT.t)));
    }

// ------------------------------------------------------------------------------------------------------
// END of Structs IMPLENTATION FILE
