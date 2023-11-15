#include "lab2.h"
#include <iostream>
#include <string>
#include <fstream>

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
	cout << "Size of list2=list: " << list2.GetSize() << endl;
	cout << list2 << endl;

	list.PushHead(1);
	list.PushHead(2);
	list.PushHead(3);
	cout << "Size of list: " << list.GetSize() << endl;
	cout << list << endl;

	list2.PushTail(list);
	cout << "Size of list2.PushTail(list): " << list2.GetSize() << endl;
	cout << list2 << endl;

	list2.PushHead(list);
	cout << "Size of list2.PushHead(list): " << list2.GetSize() << endl;
	cout << list2 << endl;

	list2.DeleteNode(50);
	cout << "Size of list2.DeleteNode(50): " << list2.GetSize() << endl;
	cout << list2 << endl;

	list2.PopHead();
	list2.PopTail();
	cout << "Size of list2.PopHead() and list2.PopTail(): " << list2.GetSize() << endl;
	cout << list2 << endl;

	cout << "list2[0]=" << list2[0]->value_ << endl;
	list2[0]->value_ = 40;
	cout << "list2[0]=" << list2[0]->value_ << endl <<endl;

	LinkedList<string> strlist;
	strlist.PushTail("C:");
	strlist.PushTail("AaSD");
	strlist.PushTail("lab2");
	strlist.PushTail("file");
	strlist.PushTail("1.txt");
	cout << str(strlist) << endl;
	ifstream file(str(strlist));
	if (!file.is_open())
	{
		cout << "File is not opened" << endl;
	}
	else {
		string filestr;
		file >> filestr;
		cout << filestr;
		file.close();
	}
}