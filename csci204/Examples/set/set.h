// ****************************************************************
//
//  Ch17Proj10.cpp
//
// Write a template-based class that implements a set of items.  A set is
// a collection of items in which no item occurs more than once. 
// Internally you may represent the set using the data structure of your
// choice (e.g. list, vector, arrays, etc.)   However, the class should
// externally support the following functions:
// a)	Add a new item to the set.  If the item is already in the set then
//    nothing happens.
// b)	Remove an item from the set.  
// c)	Return the number of items in the set.
// d)	Determine if an item is a member of the set.  
// e)	Return a pointer to a dynamically created array containing each
//    item in the set.  The caller of this function is responsible for
//    de-allocating the memory.
//
// The program in this solution uses a dynamic array to implement the
// set.  Note that the implementation of the class has been placed
// in the .H file to avoid compiler issues.
// ****************************************************************

// File Name: set.h
// Author: 
// Email Address:
// Project Number: 17.10
// Description: Interface (and implementation) for the Set template class
// Last Changed: October 14, 2007
    
#ifndef _SET_H
#define _SET_H
    
namespace setisenhour
{
    template<class T>
    class Set
    {
	private:
        T *items;
        int set_size;
    
    public:
        Set();
        // Constructs a new set

        Set(const Set<T>& other);
        // Constructs a new set

		~Set();
		// Destructor

		void operator=(const Set<T>& right_side);
		// Assignment operator
    
		void add(T item);
		// Adds an item to the set. Ignored if the item
		// is already in the set.
    
		void remove(T item);
		// Removes an item from the set. Ignored if the
		// item is not in the set.
    
		int size() const;
		// Returns the number of items in the set
    
        bool contains(T item) const;
        // Returns true if the item is in the set
    
        T *to_array() const;
        // Returns a dynamically allocated array with the
        // set's contents, or NULL if the set is empty. The
        // caller is responsible for de-allocating the array.
    };

    // Constructs a new set
    template<class T>
    Set<T>::Set() : items(NULL), set_size(0)
    {
    }

    // Constructs a new set
    template<class T>
    Set<T>::Set(const Set<T>& other) 
    {
	set_size = other.set_size;
	items = other.to_array();
    }

    // Destructor
    template<class T>
    Set<T>::~Set() 
    {
	delete[] items;
    }

    // Assignment operator
    template<class T>
    void Set<T>::operator=(const Set<T>& right_side)
    {
	if (set_size > 0)
	{
	    delete[] items;
	}
	set_size = right_side.set_size;
	items = right_side.to_array();
    }

    
    // Adds an item to the set. Ignored if the item
    // is already in the set.
    template<class T>
    void Set<T>::add(T item)
    {
        if (! contains(item))
        {
    	    T *new_items = new T[set_size + 1];
    	    for (int i = 0; i < set_size; i++)
    	    {
    	        new_items[i] = items[i];
    	    }
    	    new_items[set_size] = item;
    	    if (set_size > 0)
    	    {
    	        delete[] items;
    	    }
    	    set_size++;
    	    items = new_items;
        }
    }
    
    // Removes an item from the set. Ignored if the
    // item is not in the set.
    template<class T>
    void Set<T>::remove(T item)
    {
        if (contains(item))
        {
    	    T *copy = NULL;
    	    if (set_size > 1)
    	    {
    	        copy = new T[set_size - 1];
    	        for (int i = 0, j = 0; i < set_size; i++)
    	        {
    		    if (items[i] != item)
    		    {
    		        copy[j++] = items[i];
    		    }
    	        }
    	    }
    	    delete[] items;
    	    items = copy;
    	    set_size--;
        }
    }
    
    // Returns the number of items in the set
    template<class T>
    int Set<T>::size() const
    {
        return set_size;
    }
    
    // Returns true if the item is in the set
    template<class T>
    bool Set<T>::contains(T item) const
    {
        bool found = false;
        for (int i = 0; (i < set_size) && (! found); i++)
        {
    	    found = (items[i] == item);
        }
        return found;
    }
    
    // Returns a dynamically allocated array with the
    // set's contents, or NULL if the set is empty. The
    // caller is responsible for de-allocating the array.
    template<class T>
    T *Set<T>::to_array() const
    {
        T *copy = NULL;
        if (set_size > 0)
        {
    	    copy = new T[set_size];
    	    for (int i = 0; i < set_size; i++)
    	    {
    	        copy[i] = items[i];
    	    }
        }
        return copy;
    }
    
}

#endif SET_H



