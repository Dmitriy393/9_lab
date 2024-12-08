#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight {
private:
    int number;
    string airline;
    string from;
    string to;
    double distance;
    double duration;
    string aircraft;
    int passengers;
public:
    Flight() : number(0), airline(""), from(""), to(""), distance(0.0), duration(0.0), aircraft(""), passengers(0) {}
    Flight(int num, string al, string fr, string t, double dist, double dur, string ac, int pass);
    int get_num();
    string get_from();
    double get_distance();
    double get_duration();
    string get_aircraft();

    friend bool operator==(Flight flight1, Flight flight2);
    friend ostream& operator << (ostream& os, const Flight& flight);
    friend istream& operator >> (istream& is, Flight& flight);
    friend ofstream& operator << (ofstream& ofs, const Flight& flight);
    friend ifstream& operator >> (ifstream& ifs, Flight& flight);

    virtual void display();

};

class agencies_flight : public Flight {
private:
    int price;
    string agencies;
public:
    agencies_flight() : Flight(), price(0), agencies("") {};
    agencies_flight(int num, string al, string fr, string t, double dist, double dur, string ac, int pass, int pr, string ag) : Flight(num, al, fr, t, dist, dur, ac, pass), price(pr), agencies(ag) {};
    friend bool operator==(agencies_flight agflight1, agencies_flight agflight2);
    friend ostream& operator << (ostream& os, const agencies_flight& fl1);
    friend istream& operator >> (istream& is, agencies_flight& fl1);
    friend ofstream& operator << (ofstream& ofs, const agencies_flight& fl1);
    friend ifstream& operator >> (ifstream& ifs, agencies_flight& fl1);

    void display();
};

#endif