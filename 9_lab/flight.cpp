#include "flight.h"
#include <iostream>
#include <string>


using namespace std;

Flight::Flight(int num, string al, string fr, string t, double dist, double dur, string ac, int pass) {
	number = num;
	airline = al;
	from = fr;
	to = t;
	distance = dist;
	duration = dur;
	aircraft = ac;
	passengers = pass;
}



int Flight::get_num() {
	return number;
}

string Flight::get_from() {
	return from;
}

double Flight::get_distance() {
	return distance;
}

double Flight::get_duration() {
	return duration;
}

string Flight::get_aircraft() {
	return aircraft;
}

ostream& operator << (ostream& os, const Flight& flight) {
	os << flight.number << " " 
	   << flight.airline << " " 
	   << flight.from << " " 
	   << flight.to << " " 
	   << flight.distance << " " 
	   << flight.duration << " " 
	   << flight.aircraft << " " 
	   << flight.passengers;

	return os;
}


istream& operator >> (istream& is, Flight& flight) {
	is >> flight.number >> flight.airline >> flight.from >> flight.to >> flight.distance >> flight.duration >> flight.aircraft >> flight.passengers;

	return is;
}


ofstream& operator << (ofstream& ofs, const Flight& flight) {
	ofs << flight.number << " " <<
		flight.airline << " " <<
		flight.from << " " <<
		flight.to << " " <<
		flight.distance << " " <<
		flight.duration << " " <<
		flight.aircraft << " " <<
		flight.passengers;

	return ofs;
}

ifstream& operator >> (ifstream& ifs, Flight& flight) {
	ifs >> flight.number >> flight.airline >> flight.from >> flight.to >> flight.distance >> flight.duration >> flight.aircraft >> flight.passengers;

	return ifs;
}


void Flight::display() {
	cout << number << " " << airline << " " << from << " " << to << " " << distance << " " << duration << " " << aircraft << " " << passengers << " ";
}




bool operator == (agencies_flight agflight1, agencies_flight agflight2) {
	bool equal_flights = static_cast<Flight>(agflight1) == static_cast<Flight>(agflight2);
	bool equal_price = agflight1.price == agflight2.price;
	bool equal_agencies = agflight1.agencies == agflight2.agencies;
	if (equal_flights && equal_price && equal_agencies) {
		return true;
	}
	return false;
}

ostream& operator << (ostream& os, const agencies_flight& fl1) {
	os << static_cast<const Flight&>(fl1) << " " 
	   << fl1.price << " "
	   << fl1.agencies;
	return os;
}

istream& operator >> (istream& is, agencies_flight& fl1) {
	is >> static_cast<Flight&>(fl1) >> fl1.price >> fl1.agencies;
	return is;
}

ofstream& operator << (ofstream& ofs, const agencies_flight& fl1) {
	ofs << static_cast<const Flight&>(fl1) << " "
		<< fl1.price << " " 
		<< fl1.agencies << endl;
	return ofs;
}

ifstream& operator >> (ifstream& ifs, agencies_flight& fl1) {
	ifs >> static_cast<Flight&>(fl1) >> fl1.price >> fl1.agencies;
	return ifs;
} 


bool operator == (Flight flight1, Flight flight2) {
	if (flight1.number != flight2.number) { return false; }
	if (flight1.airline != flight2.airline) { return false; }
	if (flight1.from != flight2.from) { return false; }
	if (flight1.to != flight2.to) { return false; }
	if (flight1.distance != flight2.distance) { return false; }
	if (flight1.duration != flight2.duration) { return false; }
	if (flight1.aircraft != flight2.aircraft) { return false; }
	if (flight1.passengers != flight2.passengers) { return false; }
	return true;

}
 
void agencies_flight::display(){
	Flight::display(); 
	cout << price << " " << agencies << " ";
}
