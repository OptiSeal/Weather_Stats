//---------------------------------------------------------------------------------

    #include "PERIODINDEX.h"

//---------------------------------------------------------------------------------

            //DEFAULT CONSTRUCTOR
        PeriodIndex::PeriodIndex()
        :month(""),startIndex(-1),endIndex(-1)
        {

        }

            //Set month
        void PeriodIndex::set_Month(string loc_Month)
        {
            month = loc_Month;
        }

            //Retrieve month
        string PeriodIndex::get_Month() const
        {
            return month;
        }

            //Set start index
        void PeriodIndex::set_StartIndex(unsigned loc_StartIndex)
        {
            startIndex = loc_StartIndex;
        }

            //Retrieve start index
        unsigned PeriodIndex::get_StartIndex() const
        {
            return startIndex;
        }

            //Set end index
        void PeriodIndex::set_EndIndex(unsigned loc_EndIndex)
        {
            endIndex = loc_EndIndex;
        }

            //Retrieve end index
        unsigned PeriodIndex::get_EndIndex()
        {
            return endIndex;
        }

            //Compares period (by month) and checks if they are the same
        bool PeriodIndex::operator==(const PeriodIndex &otherPeriod) const
        {
            return (this->month == otherPeriod.month);
        }

            //Compares period (by month) and checks if this time is less than the other
        bool PeriodIndex::operator<(const PeriodIndex &otherPeriod) const
        {
            return (this->month < otherPeriod.month);
        }

// ------------------------------------------------------------------------------------------------------
// END of PeriodIndex IMPLENTATION FILE
