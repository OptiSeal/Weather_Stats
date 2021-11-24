// PeriodIndex.h - Period Index HEADER FILE
//---------------------------------------------------------------------------------

    #ifndef PERIODINDEX_H
    #define PERIODINDEX_H

//---------------------------------------------------------------------------------

    #include <string>

//---------------------------------------------------------------------------------

    using std::string;

//---------------------------------------------------------------------------------

        /**
         * \class  PeriodIndex
         *
         * \brief   A class containing string of months (in words),
         *          starting and ending index values
         *
         * \author  Daniel Dobson
         * \version 01
         * \date    04/06/2020
        */
    class PeriodIndex
    {
        public:
                /**
                * 	\brief Default Constructor
                */
            PeriodIndex();

                /**
                 * \brief Set month
                 *
                 * \param loc_Month
                 */
            void set_Month(string loc_Month);

                /**
                 * \brief Retrieve month
                 *
                 * \return month
                 */
            string get_Month() const;

                /**
                 * \brief Set start index of month
                 *
                 * \param loc_StartIndex
                 */
            void set_StartIndex(unsigned loc_StartIndex);

                /**
                 * \brief Retrieve start index
                 *
                 * \return startIndex
                 */
            unsigned get_StartIndex() const;

                /**
                 * \brief Set end index of month
                 *
                 * \param loc_EndIndex
                 */
            void set_EndIndex(unsigned loc_EndIndex);

                /**
                 * \brief Retrieve end index
                 *
                 * \return endIndex
                 */
            unsigned get_EndIndex();

                /**
                 * \brief Compares period (by month) and checks if they are the same
                 *
                 * \param otherPeriod
                 * \return true if the same; otherwise returns false
                 */
            bool operator==(const PeriodIndex &otherPeriod) const;

                /**
                 * \brief Compares period (by month) and checks if this time is less than the other
                 *
                 * \param otherPeriod
                 * \return true if less than; otherwise returns false
                 */
            bool operator<(const PeriodIndex &otherPeriod) const;

        private:
                /// Month as a string
            std::string month;
                /// Start Index
            unsigned startIndex;
                /// End Index
            unsigned endIndex;
    };

// ------------------------------------------------------------------------------------------------------
#endif // PERIODINDEX_H

