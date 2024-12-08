#include "container.h" 
#include "flight.h" 
#include <sstream> 
#include <iostream> 
#include <string> 

using namespace std;

Flight_container::Flight_container(int mx_flight) {
	max_flights = mx_flight;
	aflights = new Flight * [max_flights];
	num_flights = 0;
}

Flight_container::~Flight_container() {
	for (int i = 0; i < num_flights; ++i) {
		delete aflights[i];
	}
	max_flights = 0;
	delete[] aflights;
	num_flights = 0;
}

void Flight_container::operator+=(agencies_flight& fl) { 
	if (num_flights < max_flights) {
		aflights[num_flights++] = new agencies_flight(fl);  
	}
}




void Flight_container::read_File(const string& filename) {
	ifstream infile(filename);
	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		int num, pass, pr;
		string al, fr, t, ac, ag;
		double dist, dur;

		ss >> num >> al >> fr >> t >> dist >> dur >> ac >> pass >> pr >> ag; 
		agencies_flight new_flight1(num, al, fr, t, dist, dur, ac, pass, pr, ag);
		*this += new_flight1;
	}
	infile.close();
}

void Flight_container::write_to_file(const string& filename) {
	ofstream outfile(filename);
	for (int i = 0; i < num_flights; ++i) {
		outfile << *(aflights[i]) << endl;
	}
	outfile.close();
}

void Flight_container::add_new_flights() {
	int count;
	cout << "Какое количество рейсов хотите добавить?: ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		int number, passengers, price;
		double distance, duration;
		string airline, from, to, aircraft, agencies;
		cout << "Введите данные о рейсе " << i + 1 << ":" << endl;
		cout << "Номер рейса: " << endl;
		cin >> number;
		cout << "Авиакомпания: " << endl;
		cin >> airline;
		cout << "Пункт отправления: " << endl;
		cin >> from;
		cout << "Пункт прибытия: " << endl;
		cin >> to;
		cout << "Протяжённость: " << endl;
		cin >> distance;
		cout << "Длительность полёта: " << endl;
		cin >> duration;
		cout << "Тип самолёта: " << endl;
		cin >> aircraft;
		cout << "Количество посадочных мест: " << endl;
		cin >> passengers;
		cout << "Цена: " << endl;
		cin >> price;
		cout << "Агенство: " << endl;
		cin >> agencies;
		agencies_flight new_flight1(number, airline, from, to, distance, duration, aircraft, passengers, price, agencies);
		*this += new_flight1;
	}
}


void Flight_container::display_flights() {
	for (int i = 0; i < num_flights; ++i) {
		Flight* flight = aflights[i]; 
		flight->display(); 
		cout << endl; 
	}
}

void Flight_container::find_Flight(const string& filename) {
	ifstream file1("flight.txt");
	int cur_line = 1;
	int line_num = 0;
	string line;
	bool found = false;
	cout << "Номер рейса: " << endl;;
	cin >> line_num;


	while (getline(file1, line)) {
		if (cur_line == line_num) {
			cout << line << " ";
			found = true;
			break;
		}
		cur_line++;
	}
	file1.close();
}



double Flight_container::TotalDistanceFromMoscow() {
	double totalDistance = 0.0;

	for (int i = 0; i < max_flights; ++i) {
		if (aflights[i]->get_from() == "Москва" || aflights[i]->get_from() == "Moscow") {
			totalDistance += aflights[i]->get_distance();
		}
	}

	cout << "Общая протяжённость всех рейсов из Москвы: " << totalDistance << endl;
	return totalDistance;
}

double Flight_container::FastestFlight() {
	double maxSpeed = 0.0;
	Flight* fast = 0;

	for (int i = 0; i < max_flights; ++i) {
		if (aflights[i]->get_duration() > 0) {
			double speed = (aflights[i]->get_distance()) / (aflights[i]->get_duration() / 60.0);
			if (speed > maxSpeed) {
				maxSpeed = speed;
			}
		}
	}
	cout << "Самая высокая средняя скорость полета: " << maxSpeed << " км/ч" << endl;
	cout << "Номер рейса: " << fast->get_num() << endl;
	cout << "Тип самолёта: " << fast->get_aircraft() << endl;
	return maxSpeed;
}