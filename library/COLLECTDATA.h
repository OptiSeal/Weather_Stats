// CollectData.h - Data Collection Class IMPLEMENTATION FILE
//---------------------------------------------------------------------------------

    #ifndef COLLECTDATA_H
    #define COLLECTDATA_H

//---------------------------------------------------------------------------------

	#include "BST.h"
	#include "VECTOR.h"

//---------------------------------------------------------------------------------

    using std::endl;
    using std::cout;

//---------------------------------------------------------------------------------

            /**
             * \class   CollectData
             * \brief   A basic template class that collects and stores data
             *
             *          This class stores data provided to it into a Vector data structure.
             *          Elements can be retrieved by the caller using the [] operator.
             *          The data structure size can be returned to the caller.
             *
             * \author  Daniel Dobson
             * \version 01
             *
             * \date    31/05/2020
            */
    template <class T>
    class CollectData
    {
        public:
                /**
                * 	\brief Default Constructor
                */
            CollectData(){};

				/**
                * 	\brief Collect data (STATIC)
                *
                *   Stores CONST element passed by reference into a Vector data structure
                *
                *   \param data - Data to be inserted into Vector
				*	\post Data is inserted into STL Vector data structure
                */
            static void collData(const T &data);

				/**
                * 	\brief Retreives total number of elements stored
				*
				*	\post Returns size of Vector
                */
            unsigned size() const;

                /**
                * 	\brief Overloaded [] operator
                *
                *   Retreives contents of element specified by caller and returns to caller by reference.
                *
                *   \param k - specified element
				*	\post Contents of element returned by reference
				*	\throw Error message - "Element specified exceeds total number of elements stored!"
                */
            T& operator[](unsigned k);

			    /**
                * 	\brief CONST Overloaded [] operator
                *
                *   Retreives contents of element specified by caller and returns to caller by CONST reference.
                *
                *   \param k - specified element
				*	\post Contents of element returned by CONST reference
				*	\throw Error message - "Element specified exceeds total number of elements stored!"
                */
            const T& operator[](unsigned k)const;

        private:
				/// Vector collecting data (STATIC)
            static Vector<T> A;

    };

		// Global Declaration of a template type vector contained in CollectData class that collects data
    template <class T>
    Vector<T> CollectData<T>::A;

		// Collect Data
    template<class T>
    void CollectData<T>::collData(const T &data)
    {
        A.insert_Elem(data);
    }

		// Retreives total number of elements stored
    template<class T>
    unsigned CollectData<T>::size() const
    {
        return A.get_Size();
    }

		// Overloaded [] operator
		// Throw error message if element provided by caller exceeds size of Vector
    template<class T>
    T& CollectData<T>::operator[](unsigned k)
    {
        if(k < A.get_Size())
            return A[k];
        else
            throw "Element specified exceeds total number of elements stored!";
    }

		// CONST Overloaded [] operator
		// Throw error message if element provided by caller exceeds size of Vector
    template<class T>
    const T& CollectData<T>::operator[](unsigned k)const
    {
        if(k < A.get_Size())
            return A[k];
        else
            throw "Element specified exceeds total number of elements stored!";
    }

// ------------------------------------------------------------------------------------------------------
#endif // COLLECTDATA_H
