// TIME.h - Time HEADER FILE
//---------------------------------------------------------------------------------

    #ifndef TIME_H
    #define TIME_H

//---------------------------------------------------------------------------------

        /**
         * \class   Time
         * \brief   A class that stores the Time
         *
         * This class stores the time. Seperated by hours, minutes and seconds.
         *
         * \author  Daniel Dobson
         * \version 03
         *
         *          An equality method has been added to check if times are the same.
         *          Returns true if the same, otherwise false if not.
         *
         * \date    10/05/2020
        */
    class Time
    {
        public:
                /**
                * 	\brief Default Constructor
                *
                * 	A default constructor to set the time
                *
                */
            Time();

                /**
                * 	\brief Constructor
                *
                * 	A default constructor to set the time with parameters
                *
                * \param initial_Hours
                * \param initial_Mins
                * \param initial_Secs
                * \pre Time values must be valid!
                */
            Time(int initial_Hours, int initial_Mins, int initial_Secs);

                /**
                 * \brief Set time
                 *
                 * \param new_Hours
                 * \param new_Mins
                 * \param new_Secs
                 * \pre Time values must be valid!
                 */
            void set_Time(int new_Hours, int new_Mins, int new_Secs);

                /**
                 * \brief Retrieve hours
                 *
                 * \return hours
                 */
            int get_Hours() const;

                /**
                 * \brief Set hours
                 *
                 * \param new_Hours
                 * \pre Hours must be between 00 and 23!
                 */
            void set_Hours(int new_Hours);

                /**
                 * \brief Retrieve minutes
                 *
                 * \return mins
                 */
            int get_Mins() const;

                /**
                 * \brief Set minutes
                 *
                 * \param new_Mins
                 * \pre Minutes must be between 00 and 59!
                 */
            void set_Mins(int new_Mins);

                /**
                 * \brief Retrieve seconds
                 *
                 * \return secs
                 */
            int get_Secs() const;

                /**
                 * \brief Set seconds
                 *
                 * \param new_Secs
                 * \pre Seconds must be between 00 and 59!
                 */
            void set_Secs(int new_Secs);

                /**
                 * \brief Compares times and checks if they are the same
                 *
                 * \return true if the same, false if not the same
                 */
            bool operator==(const Time &otherT) const;
                /**
                 * \brief Compares is this time is less than the other time
                 *
                 * \return true if less than; otherwise returns false
                 */
            bool operator<(const Time &otherT) const;

        private:
                /// Hours
            int hours;
                /// Minutes
            int mins;
                /// Seconds
            int secs;
    };

//---------------------------------------------------------------------------------
#endif // TIME_H
