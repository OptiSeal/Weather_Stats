//UTILITIES.cpp - UTILITIES IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

    #include "UTILITIES.h"

//---------------------------------------------------------------------------------

        //Checks if a string is a number
    bool is_Num(const string& str)
    {
        string::const_iterator it = str.begin();

        while (it != str.end() && (std::isdigit(*it) || *it == '.'))
        {
            ++it;
        }

        return (!str.empty() && it == str.end());
    }


        //Inserts months of the year into a Vector of type string
    void insert_MthStringVec(Vector<string> &local_Mth)
    {
        local_Mth.insert_Elem("NONE!");
        local_Mth.insert_Elem("January");
        local_Mth.insert_Elem("February");
        local_Mth.insert_Elem("March");
        local_Mth.insert_Elem("April");
        local_Mth.insert_Elem("May");
        local_Mth.insert_Elem("June");
        local_Mth.insert_Elem("July");
        local_Mth.insert_Elem("August");
        local_Mth.insert_Elem("September");
        local_Mth.insert_Elem("October");
        local_Mth.insert_Elem("November");
        local_Mth.insert_Elem("December");
    }

// ----------------------------------------------------------------------------------
// END of Utilities IMPLENTATION FILE
