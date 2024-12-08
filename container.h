#ifndef CONTAINER_H
#define CONTAINER_H

#include "flight.h"
#include <string>


using namespace std;


class Flight_container {
private:
	int num_flights; 
	int max_flights;
	Flight** aflights; 
public:

	Flight_container(int mx_flight);
	~Flight_container();

	void operator += (agencies_flight& fl1);

	void read_File(const string& filename);
	void write_to_file(const string& filename);
	void add_new_flights();
	void display_flights();
	void find_Flight(const string& filename);
	double TotalDistanceFromMoscow();
	double FastestFlight();
};



#endif