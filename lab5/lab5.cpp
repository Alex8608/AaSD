#include "lab5.h"

int main() {
	MyHashTable<int, float> table(10);
	table.insert(1, 0.1);
	table.insert(2, 0.2);
	table.insert(5, 0.5);
	table.insert(7, 0.7);
	table.insert(4, 0.4);
	table.insert(11, 0.21);
	table.insert(13, 0.133);
	table.insert(32, 0.32);
	table.insert(17, 0.71);
	table.print();

	table.insert_or_assign(11, 0.87);
	table.insert_or_assign(2, 0.135);
	table.print();
	table.insert_or_assign(2, 0.123);
	table.print();

	cout << table.contains(0.123) << endl;
	cout << table.contains(12.5) << endl << endl;

	auto value1 = table.search(11);
	if (value1) {
		cout << *value1 << endl;
	}
	else {
		cout << "No value with that key" << endl;
	}
	auto value2 = table.search(1000);
	if (value2) {
		cout << *value2 << endl;
	}
	else {
		cout << "No value with that key" << endl;
	}
	cout << endl;

	table.erase(7);
	table.print();
	auto value3 = table.search(7);
	if (value3) {
		cout << *value3 << endl;
	}
	else {
		cout << "No value with that key" << endl;
	}
	cout << endl;

	table.insert(11, 0.121);
	table.print();
	cout << endl;
	cout << "Count 11: " << table.count(11) << endl;
	cout << "Count 7: " << table.count(7) << endl;
	cout << "Count 1: " << table.count(1) << endl;
	cout << endl;

	string s = "Pillow";
	auto hash = pearson_hash(s);
	cout << hash << endl << endl;
	cout << compare_string(hash, "Paris") << endl;
	cout << compare_string(hash, "Pillow") << endl;
	cout << endl;

	MyHashTable<int, string> strtable(10, 5);
	strtable.print();
}