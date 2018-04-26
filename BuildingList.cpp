/* 
 * File:   BuildingList.cpp
 * Purpose: provide the implementation of the member functions for the class BuildingList
 * Author: pike
 *
 */
#include <cassert>
#include "BuildingList.h"

BuildingList::BuildingList()
{
    capacity = INITIAL_CAPACITY;
    size = 0;
    p = new Building[capacity];	// create a dynamic array of Building objects with INITIAL_CAPACITY
    assert(p != NULL);          // if the request to the head cannot get satisfied, abort the program
}

BuildingList::BuildingList(int incapacity)
{
	assert(incapacity > 0);     // if incapacity is not greater than 0, abort the program
    capacity = incapacity;
    p = new Building[capacity];	// create a dynamic array of string objects
    assert(p != NULL);
    size = 0;
}

BuildingList::BuildingList(const BuildingList &other) : capacity(other.capacity), size(other.size)
{
    p = new Building[capacity];
    assert(p != 0);
    for (int i = 0; i < size; i++)
    {
        p[i] = other.p[i];
    }
}

BuildingList::~BuildingList()
{
    delete[] p;	// release the dynamic array
}


void BuildingList::insertAtTail(Building item)
{
    size = size + 1;
    if (size >= capacity) 
    {
        // No more room:  allocate more.
        capacity *= 2;
        Building* copy = new Building[capacity];
        assert(copy != NULL);
        // Copy over the data
        for (int i = 0; i < size; i++)
            copy[i] = p[i];
        // Free the old copy and point to the new one.
        delete[] p;
        p = copy;
    }
    // insert at the back of the list
    // Note that the size has been increased by one at the beginning
    // size represents the size after inserting the new item
    p[size-1] = item;   
}

Building &BuildingList::Element(int x)
{
    assert(x >= 0 && x < size);
    return p[x];
}

void BuildingList::print() const
{
    for (int x = 0; x < size; x++)
    {
        cout << p[x] << endl;
    }
}

BuildingList &BuildingList::operator=(const BuildingList &other)
{
    if (this != &other)
    {
        assert(size == other.size);     // only allow the same size of BuildingList objects to use the assignment operator
        for (int i = 0; i < size; i++)
            p[i] = other.p[i];
    }
    return *this;
}

void BuildingList::bubble_sort(int (*compare)(Building B1, Building B2))
{
    Building temp;   // for swapping
    for (int i = 0 ; i < size-1 ; i++)
    {
        for (int j = 0 ; j < size-1 ; j++)
        {
            // if two objects are in the wrong order, swap them
            if ( (*compare)(p[j], p[j + 1]) < 0 )
	        {
                temp = p[j];
		        p[j] = p[j+1];
		        p[j+1] = temp;
            }        
        }
    }
}    

