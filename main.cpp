#include <vld.h>
#include "list.h"
#include <iostream>
#include <fstream>


using namespace std;


int main() {
	Circle c1(10, 1, 1);
	Circle c2(22, 2, 2);
	Circle c3(3, 3, 3);

	List list;

	cout << "STARTING" << endl;
	list.apptop(c1);
	list.apptop(c2);
	list.apptop(c3);
	list.append(c1);
	list.append(c2);
	list.append(c3);

	cout << list << endl;
	
	cout << endl << "POP 2: " << list.pop(c2) << endl;
	cout << list << endl;
	
	cout << endl << "REMOVE 1: " << list.remove(c1) << endl;
	cout << list << endl;
	
	cout << endl << "SORT BY ASCENDING" << endl;
	list.sort();
	cout << list << endl;
	
	cout << endl << "SORT BY DESCENDING" << endl;
	list.sort(false);
	cout << list << endl;
	
	cout << endl << "CLEAR" << endl;
	list.clear();
	cout << list << endl;

	cout << endl << "NEW LIST" << endl;
	List newList;
	newList.append(c1);
	newList.append(c2);
	cout << newList;
	
	cout << endl << endl << "ENTER FILE NAME  - ";
	char ar[80];
	cin >> ar;

	cout << endl << "SAVING TO FILE" << endl;
	ofstream fout(ar);
	fout << newList;
	fout.close();

	cout << endl << "READING FROM FILE" << endl;
	ifstream fin;
	fin.open(ar);
	fin >> list;
	fin.close();

	cout << endl << "LAST LIST" << endl;
	cout << list << endl;


	return 0;
}