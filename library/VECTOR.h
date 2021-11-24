// Vector.h - Vector HEADER FILE
//---------------------------------------------------------------------------------

    #ifndef VECTOR_H
    #define VECTOR_H

//---------------------------------------------------------------------------------

    #include <vector>

//---------------------------------------------------------------------------------

    template <class T>

        /**
         * \class   Vector
         * \brief   A Vector class containing an encapsulated array
         *
         *  Provides controlled access to the STL vector class through public methods.
         *  Elements can be inserted provided it has not reached maximum size.
         *  Specific elements can be returned by reference or const reference through read
         *  and read/write operator[] overload methods.
         *  The current size of the vector can also be returned.
         *
         * \author  Daniel Dobson
         * \version 02
         * \date    10/05/2020
         *
         *          This class now utilises the STL vector class. A new clear method has been added for
         *          additional functionality to remove all elements contained within the vector.
         *
         *          The destructor, copy constructor and overload operator= method have been removed as
         *          these functions are handled by the STL vector class.
         *
         *          This class now only provides controlled access to the STL vector and its functions.
        */
    class Vector
    {
        public:

                /**
                * 	\brief Default Constructor
                */
            Vector();

                /**
                * 	\brief Inserts Element into vector
                *
                *   Method inserts the read-only paramater type T to the STL vector.
                *
                *   \param n (const T&)
                */
            void insert_Elem(const T &n);

                /**
                * 	\brief Clears all elements in the vector
                *
                *   All elements in the vector are destroyed, with the size set to 0.
                *
                *   \warning If the elements are pointers, the pointed-to-memory is not touched with this method!
                */
            void clear_AllElem();

                /**
                * 	\brief Returns current size of the vector
                *
                *   \return arr_size
                */
            unsigned get_Size() const;

                /**
                * 	\brief Overload operator[]
                *
                *   Provides access to contents of specified element in the vector by reference.
                *   Read and write access permitted
                *
                *   \param i (Index)
                *   \return *arr[i]
                */
            T & operator[] (unsigned i);

                /**
                * 	\brief Overload operator[] (const)
                *
                *   Provides read-only access to contents of specified element in the vector by reference.
                *
                *   Read-only access permitted
                *
                *   \param i (Index)
                *   \post Array element cannot be modified by the caller
                *   \return *arr[i]
                */
            const T & operator[](unsigned i) const;

        private:
                /// Encapsulates STL Vector
            std::vector<T> arr;
    };

            // CONSTRUCTOR
        template <class T>
        Vector<T>::Vector()
            :arr{}{}


            // INSERT ELEMENT INTO VECTOR
        template <class T>
        void Vector<T>::insert_Elem(const T &n)
        {
            arr.push_back(n);
        }

            // GET CURRENT SIZE OF VECTOR
        template <class T>
        unsigned Vector<T>::get_Size() const
        {
            return arr.size();
        }

            // DELETES ALL ELEMENTS IN VECTOR
        template <class T>
        void Vector<T>::clear_AllElem()
        {
            arr.clear();
        }

           // OVERLOAD OPERATOR []
        template <class T>
        T & Vector<T>::operator[] (unsigned i)
        {
            return arr[i];
        }

            // OVERLOAD OPERATER [] (const)
        template <class T>
        const T & Vector<T>::operator[](unsigned i) const
        {
            return arr[i];
        }

//---------------------------------------------------------------------------------
#endif // VECTOR_H

