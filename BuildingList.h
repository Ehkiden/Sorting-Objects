/* 
 * File:   BuildingList.h
 * Purpose: provide the declaration of the class BuildingList
 * Author: pike
 *
 */

#ifndef BUILDINGLIST_H
#define	BUILDINGLIST_H

#include <iostream>
#include "Building.h"

using namespace std;

const int INITIAL_CAPACITY = 5;

class BuildingList
{
  public:
    BuildingList();                             // default constructor, set up the capacity = INITIAL_CAPACITY
    BuildingList(int incapacity);               // constructor, set up the capacity = incapacity
    BuildingList(const BuildingList &other);    // copy constructor
    ~BuildingList();                            // destructor
    void insertAtTail(Building item);           // insert an item at the tail of the list
    int GetSize() const { return size; }
    Building &Element(int x);                   // return reference to an element at index of x
    void print() const; 
    // apply bubble_sort algorithm to the elements in the list
    // pass in function name as the parameter
    // passed in function which defines the comparison between two elements 
    void bubble_sort(int (*compare)(Building B1, Building B2));
    BuildingList &operator=(const BuildingList &other);   // assignment operator overloading

  private:
    int capacity;       // the capacity of the dynamic array(list)
    int size;           // the total number of elements in the list
	Building *p;        // pointer pointing to the first element in the list
};


#endif	/* BUILDINGLIST_H */

