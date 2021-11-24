// DATE.h - Date HEADER FILE
//---------------------------------------------------------------------------------

    #ifndef DATE_H
    #define DATE_H

//---------------------------------------------------------------------------------

        /**
         * \class   Date
         * \brief   A class that stores a Date
         *
         * This class stores the date a mark was obtained for a unit. The date is seperated
         * into the day of the month, month and year as positive integers.
         *
         * \author  Daniel Dobson
         * \version 06
         *
         *          Overloaded operator for less than '<' has been added to compare
         *          dates against each other.
         *          The equality method has been modified to an overloaded operator '==' for consistency
         *
         * \date    17/05/2020
        */
    class Date
    {
        public:

                /**
                * 	\brief Default Constructor
                *
                * 	A default constructor to set the date
                *
                */
            Date();

                /**
                * 	\brief Constructor
                *
                * 	A constructor to set the date with parameters
                *
                *   \param initial_Day
                *	\param initial_Month
                *	\param initial_Year
                */
            Date(unsigned initial_Day, unsigned initial_Month, unsigned initial_Year);

                /**
                 * \brief Copies other date to this date
                 *
                 * Copies the day of the month, month and year
                 *
                 * \param new_Date (const)
                 */
            void copy_Date(const Date& new_Date);

                /**
                 * \brief Reset date to default values
                 */
            void reset_Date();

                /**
                 * \brief Set day of the month
                 *
                 * \param new_Day
                 * \pre Day must be valid against existing month and year values in the Date class!
                 */
            void set_Day(unsigned new_Day);

                /**
                 * \brief Retrieves day of the month
                 *
                 * \warning The method cannot change the 'day' variable belonging to the Date class!
                 * \return day of the year
                 */
            unsigned get_Day() const;

                /**
                 * \brief Set month
                 *
                 * \param new_Month
                 * \pre Month must be valid against existing day and year values in the Date class!
                 */
            void set_Month(unsigned new_Month);

                /**
                 * \brief Retrives month
                 *
                 * \warning The method cannot change the 'month' variable belonging to the Date class!
                 * \return month
                 */
            unsigned get_Month() const;

                /**
                 * \brief Set year
                 *
                 * \param new_Year
                 * \pre Year must be valid against existing day and month values in the Date class!
                 */
            void set_Year(unsigned new_Year);

                /**
                 * \brief Retrives year
                 *
                 * \warning The method cannot change the 'year' variable belonging to the Date class!
                 * \return year
                 */
            unsigned get_Year() const;

                /**
                 * \brief Compares dates and checks if they are equal
                 *
                 * \return Returns true if equal; otherwise, returns false
                 */
            bool operator==(const Date &o_Date) const;

                /**
                 * \brief Compares dates and checks if this date is less than the other date object
                 *
                 * \return Returns true if less; otherwise, returns false
                 */
            bool operator<(const Date &o_Date) const;

        private:
                /// Day of the year
            unsigned day;
                /// Month
            unsigned month;
                /// Year
            unsigned year;

                /**
                 * \brief Checks if date is valid
                 *
                 *  This method checks the validity of the date provided. The day will be checked against the month and
                 *  the year will be checked for the special case of a leap year by calling the 'is_LeapYear' method.
                 *
                 * \return true or false
                 */
            bool isValid_Date(unsigned d, unsigned m, unsigned y);

                /**
                 * \brief Checks if the year provided is a leap year
                 *
                 * \return true or false
                 */
            bool is_LeapYear(unsigned y);
    };

//---------------------------------------------------------------------------------
#endif // DATE_H
