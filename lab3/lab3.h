#pragma once
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

class MyClass {
private:
	int value;
public:
	MyClass() : value(0) {};
	MyClass(const int value) : value(value) {};
	int get_value() const {
		return this->value;
	}
	bool operator>(const MyClass& rhs) const {
		return this->value > rhs.value;
	}

	bool operator<(const MyClass& rhs) const {
		return this->value < rhs.value;
	}
};

template<typename T>
stats& SelectionSort(vector<T>& vec) {
	stats stat;
	int index;
	for (int i = 0; i < vec.size() - 1; i++) {
		index = i;
		for (int j = i + 1; j < vec.size(); j++) {
			stat.comparison_count += 1;
			if (vec[j] < vec[index]) index = j;
		}
		if (index != i) {
			swap(vec[i], vec[index]);
			stat.copy_count += 3;
		}
	}
	return stat;
}

template<typename T>
stats& ShakerSort(vector<T>& vec) {
	stats stat;
	int left_mark = 0;
	int control = vec.size() - 1;
	int right_mark = control;
	do {
		for (int i = left_mark; i < right_mark; i++) {
			stat.comarison_count += 1;
			if (vec[i] > vec[i+1]) {
				swap(vec[i], vec[i + 1]);
				control = i;
				stat.copy_count += 3;
			}
		}
		right_mark = control;

		for (int i = right_mark; i > left_mark; i--) {
			stat.comarison_count += 1;
			if (vec[i] < vec[i - 1]) {
				swap(vec[i], vec[i - 1]);
				control = i;
				stat.copy_count += 3;
			}
		}
		left_mark = control;
	} while (left_mark < right_mark);

	return stat;
}

template<typename T>
stats& CombSort(vector<T>& vec) {
	double factor = 1.2473309; // фактор уменьшения
	int step = vec.size() - 1;
	while (step >= 1) {
		for (int i = 0; i + step < vec.size(); i++) {
			if (vec[i] > vec[i + step])	
				swap(vec[i], vec[i + step]);
		}
		step /= factor;
	}
}

template <typename T>
vector<T> RandomVec(size_t size) {
	vector<T> vec(size);
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < size; ++i) {
		vec[i] = rand();
	}
	return vec;
}

template <typename T>
vector<T> SortedVec(size_t size) {
	vector<T> vec(size);
	for (size_t i = 0; i < size; ++i) {
		vec[i] = i;
	}
	return vec;
}

template <typename T>
vector<T> ReverseSortedVec(size_t size) {
	vector<T> vec(size);
	for (size_t i = 0; i < size; ++i) {
		vec[i] = size - i;
	}
	return vec;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T>& data) {
	for (size_t i = 0; i < data.size(); i++) {
		if (i != 0 && i % 10 == 0) {
			cout << endl;
		}
		out << data[i] << ' ';
	}
	out << endl;
	return out;
}

ostream& operator<<(ostream& out, stats& st) {
	out << "comparison_count = " << st.comparison_count << endl;
	out << "copy_count = " << st.copy_count << endl;
	return out;
}

ostream& operator<<(ostream& out, MyClass& me) {
	out << me.get_value() << endl;
	return out;
}