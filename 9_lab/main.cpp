#include "flight.h"
#include "container.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Flight_container cont(10);
	int num;
	cont.read_File("flight.txt");

	do {
		cout << "Выберите действие: " << endl;
		cout << "1. Добавить рейс" << endl;
		cout << "2. Вывод рейсов" << endl;
		cout << "3. Поиск рейса" << endl;
		cout << "4. Вывод общей протяжённости рейсов из Москвы" << endl;
		cout << "5. Вывод самой высокой средней скорости полёта" << endl;
		cin >> num;

		switch (num) {
		case 1:
			cont.add_new_flights();
			cont.write_to_file("flight.txt");
			break;
		case 2:
			cont.display_flights();
			break;
		case 3:
			cont.find_Flight("flight.txt");
			break;
		case 4:
			cont.TotalDistanceFromMoscow();
			break;
		case 5:
			cont.FastestFlight();
			break;
		case 0:
			cout << "Выход" << endl;
			break;
		}
	} while (num != 0);
	return 0;
}