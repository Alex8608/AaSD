#include "lab1.h"
#include <iostream>

using namespace myset;
using namespace std;

int main() {
	int iarray1[] = { 1, 3, 2, 5, 6, 6, 6, 2, 1 };//5
	int iarray2[] = { 4, 5, 7, 8, 9 };//5
	int iarray3[] = { 1, 2, 3, 4, 5, 3, 2 };//5
	int iarray4[] = { 1, 2, 3, 4, 5, 6, 6, 1 };//6
	int iarray5[] = { 1, 3, 2, 5, 6, 6, 2, 1 };//5
	float farray1[] = { 1.12, 2.3, 1.45, 7.26, 2.33, 2.33, 8.875 };//6
	float farray2[] = { 1.34, 3.23, 1.45, 7.26, 8.34 };//5
	string sarray[] = { "alex", "lab", "on", "laptop" };//4
	pair<int, double> parray1[] = { make_pair(1, 1.12), make_pair(4, 3.14), make_pair(3, 7.12), make_pair(7, 4.12), make_pair(4, 3.14) };//5
	pair<int, double> parray2[] = { make_pair(1, 1.1), make_pair(4, 3.14), make_pair(1, 1.1), make_pair(5, 7.12), make_pair(6, 4.88), make_pair(7, 4.12) };//5

	auto iset1 = MySet<int>(iarray1, 9);
	auto iset2 = MySet<int>(iarray2, 5);

	auto iset3 = MySet<int>(iarray3, 7);
	auto iset4 = MySet<int>(iarray4, 8);
	auto iset5 = MySet<int>(iarray5, 8);

	auto fset1 = MySet<float>(farray1, 7);
	auto fset2 = MySet<float>(farray2, 5);

	auto sset1 = MySet<string>(sarray, 4);

	auto pset1 = MySet<pair<int, double>>(parray1, 5);
	auto pset2 = MySet<pair<int, double>>(parray2, 5);

	cout << "Set of int" << "\n";
	cout << iset1 << "\n\n";
	cout << "Set of float" << "\n";
	cout << fset1 << "\n\n";
	cout << "Set of string" << "\n";
	cout << sset1 << "\n\n";
	cout << "Set of pair" << "\n";
	cout << pset1 << "\n\n";

	cout << "Sum of sets(int):" << "\n";
	cout << iset1 << " + " << iset2 << " = ";
	auto sum = iset1 + iset2;
	cout << sum;
	cout << "\n\n";

	cout << "Difference of sets(float):" << "\n";
	cout << fset1 << "- " << fset2 << " = ";
	auto dif = fset1 - fset2;
	cout << dif;
	cout << "\n\n";

	cout << "Compare int sets" << "\n";
	cout << iset1 << "= " << iset5 << "\n";
	auto b = (iset1 == iset5);
	cout << b << "\n";
	cout << iset1 << "= " << iset3 << "\n";
	b = (iset1 == iset3);
	cout << b << "\n";
	cout << iset1 << "!= " << iset5 << "\n";
	b = (iset1 != iset5);
	cout << b << "\n";
	cout << iset1 << "!= " << iset3 << "\n";
	b = (iset1 != iset3);
	cout << b;
	cout << "\n\n";

	cout << "+= and -= with string set:\n";
	cout << sset1 << "\n";
	sset1 += "samara";
	sset1 -= "lab";
	cout << sset1;
	cout << "\n\n";

	cout << "Difference of sets(pair):" << "\n";
	cout << pset1 << "- " << pset2 << " = ";
	auto dif_pair = pset1 - pset2;
	cout << dif_pair;
	cout << "\n\n";

	cout << "Intersection of sets(int):" << "\n";
	cout << iset1 << "and " << iset2 << " = ";
	auto inter_int = iset1.Intersection(iset2);
	cout << inter_int;
	cout << "\n\n";

	cout << "Unique elements of sets(int):" << "\n";
	cout << iset3 << "and " << iset2 << " = ";
	auto unique_int = FindUniqueElements(iarray3, 7, iarray2, 5);
	cout << unique_int;
	cout << "\n\n";
}