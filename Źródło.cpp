#include <iostream>
#include <cstdlib>		//prototyp funkcji rand() i srand()
#include <ctime>		//prototyp funkcji time()
#include "Vector.h"
#include <fstream>

int main()
{

	using namespace std;

	using VECTOR::Vector;
	srand(time(0));				//inicjalizacja generatora liczb pseudolosowych;
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	const char nazwa[10][13] = { "marsz_1.txt","marsz_2.txt" ,"marsz_3.txt" ,"marsz_4.txt" ,"marsz_5.txt" ,"marsz_6.txt" ,
		"marsz_7.txt" ,"marsz_8.txt" ,"marsz_9.txt" ,"marsz_10.txt" };
	int numer = 0;
	cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	while (cin >> target)
	{
		cout << "Podaj dlugosc kroku: ";
		if (!(cin >> dstep))
			break;
		ofstream fout;
		fout.open(nazwa[numer]);
		fout << "Dystans do przejscia: " << target << ", dlugosc kroku: " << dstep << endl
			<< "0: (x,y) = " << result << endl;
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
				fout <<steps<<": (x,y) = " << result << endl;
				result.polar_mode();
			}

		result.rect_mode();
		cout << "Po " << steps << " krokach delikwent osiagnal polozenie:\n";
		cout << result << endl;

		fout << "Po " << steps << " krokach delikwent osiagnal polozenie:\n";
		fout << result << endl;

		result.polar_mode();
		cout << "czyli\n" << result << endl;
		cout << "Srednia dlugosc kroku pozornego = "
			<< result.magval() / steps << endl;

		fout << "czyli\n" << result << endl;
		fout << "Srednia dlugosc kroku pozornego = "
			<< result.magval() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		numer++;
		cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
	}
	cout << "Koniec!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();
	return 0;

}