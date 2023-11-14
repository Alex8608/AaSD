#include "lab2.h"
#include <iostream>
#include <string>

using namespace mylist;
using namespace std;

int main() {
	LinkedList<int> list;
	list.PushTail(2);
	list.PushTail(10);
	list.PushTail(50);
	cout << "Size of list: " << list.GetSize() << endl;
	cout << list << endl;

	LinkedList<int> copy_list(list);
	cout << "Size of copy_list: " << copy_list.GetSize() << endl;
	cout << copy_list << endl;

	auto list2 = list;
	cout << "Size of list2: " << copy_list.GetSize() << endl;
	cout << list2 << endl;
}