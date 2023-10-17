#include "lab1.h"
#include <iostream>

using namespace myset;
using namespace std;

int main() {
	int iarray1[] = { 1, 3, 2, 5, 6, 6 ,6,2,1 };//5
	int iarray2[] = { 4, 5, 7, 8, 9 };//5

	float farray1[] = { 1.12, 2.33, 1.45, 5.76, 2.33, 2.33, 9.875 };//7
	float farray2[] = { 1.34, 3.23, 1.45, 5.76, 8.34 };//5

	auto iset1 = MySet<int>(iarray1, 9);
	auto iset2 = MySet<int>(iarray2, 5);

	auto fset1 = MySet<float>(farray1, 7);
	auto fset2 = MySet<float>(farray2, 5);
}