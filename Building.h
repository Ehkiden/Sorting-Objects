/* 
 * File:   Building.h
 * Purpose: provide the declaration of the class Building
 * Author: pike
 *
 */

#ifndef BUILDING_H
#define	BUILDING_H

#include <iostream>
#include <string>

using namespace std;

class Building
{
  public:
    Building();
    Building(string name, string id, string position);
    string get_Name() const;
    string get_ID() const;
    string get_Coordinate() const;
    static int compareByName(Building B1, Building B2);
    static int compareByID(Building B1, Building B2);
    static int compareByReverseCoordinate(Building B1, Building B2);
    friend ostream &operator<<(ostream &out, const Building &B); 
    friend class BuildingList;
  private:
    string name;        // building name
    string ID;          // building ID
    string coordinate;  // building coordinate in the map  
};

#endif	/* BUILDING_H */

