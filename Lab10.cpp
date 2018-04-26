//Project: Lab Assignment 10
//Date: 04/04/2017
//Purpose: to apply sorting algorithm to the objects of Building class 
//         first order: sort objects in lexicographical order by buildings' names
//         second order: sort objects in lexicographical order by buildings' IDs (four-digit ID)
//         third order: sort objects in reverse-lexicographical order by coordinates in the map
//         three different types of orders are defined as three functions respectively, in the Building class
//         Pass in "the pointer to function" to the bubble_sort member function of BuildingList class
//         to implement sorting by first order, second order and third order respectively
//         use operator overloading of "<<" for the Building class to send the object of Building class directly to the standard output
//Author: Jared Rigdon

/*
This program will basically read a file and sort it in 3 different ways
The file is provided for the user
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Building.h"
#include "BuildingList.h"

using namespace std;

int main(int argc, char** argv) { 
    ifstream in_file;

    // Check if missing command line argument
    if (argc != 2)
    {
        cout << "It needs one command line argument: <input filename>!" << endl;
        return 1;
    }

    // Check if opening the file successfully
    in_file.open(argv[1]);
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << argv[1] << endl;	
       return 2;
    }
    
    // Read data from the file and store into the BuildingList object
    // Assume "good data" from the file
    BuildingList UKY_buildingList;
    while (!in_file.eof())
    {
        string line;
        getline(in_file, line);
        string name, ID, position;
        istringstream iss(line);
        getline(iss, name, '\t');

        // separate the rest part into ID and coordinate in the map, and also extra white space
        iss >> ws >> ID >> ws >> position;

        if (name != "")
        {    
            Building newbuilding(name, ID, position);
            UKY_buildingList.insertAtTail(newbuilding);
        }    
    }    
    // close the file after finishing reading data from
    in_file.close(); 

    //First, display the original sequence of objects
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    UKY_buildingList.print();
    
    // Sort the objects in lexicographical order by buildings' names
    int (*compare)(Building B1, Building B2);
    compare = &Building::compareByName;
    UKY_buildingList.bubble_sort((*compare));
    cout << endl;
    cout << "The sequence of objects after sorting in lexicographical order by buildings' names: " <<endl;
    UKY_buildingList.print();
    
    // Sort the objects in lexicographical order by buildings' names
    //int (*compare)(Building B1, Building B2);
    compare = &Building::compareByID;
    UKY_buildingList.bubble_sort((*compare));
    cout << endl;
    cout << "The sequence of objects after sorting in lexicographical order by buildings' IDs: " <<endl;
    UKY_buildingList.print();

    // Sort the objects in reverse-lexicographical order by buildings' names
    //int (*compare)(Building B1, Building B2);
    compare = &Building::compareByReverseCoordinate;
    UKY_buildingList.bubble_sort((*compare));
    cout << endl;
    cout << "The sequence of objects after sorting in reverse-lexicographical order by buildings' coordinates in the map: " <<endl;
    UKY_buildingList.print();
    
    return 0;
}

