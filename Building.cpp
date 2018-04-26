#include "Building.h"

Building::Building()
{

}

Building::Building(string name, string id, string position)
{
	this->name = name;
	ID = id;
	coordinate = position;
}

string Building::get_Name() const
{
	//if this causes an wrror then use return string(name); same for the others
	return name;
}

string Building::get_ID() const
{
	return ID;
}

string Building::get_Coordinate() const
{
	return coordinate;
}

int Building::compareByName(Building B1, Building B2)
{
	if (B1.name > B2.name) {
		return -1;
	}
	else {
		return 1;
	}
}

int Building::compareByID(Building B1, Building B2)
{
	if (B1.ID > B2.ID) {
		return -1;
	}
	else {
		return 1;
	}
}

int Building::compareByReverseCoordinate(Building B1, Building B2)
{
	if (B1.coordinate > B2.coordinate) {
		return -1;
	}
	else {
		return 1;
	}
}

ostream & operator<<(ostream & out, const Building & B)
{
	// TODO: insert return statement here
	out << B.name << "\t" << B.ID << "\t" << B.coordinate;
	return out;
}
