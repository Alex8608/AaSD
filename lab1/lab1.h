#pragma once
#include <random>

namespace myset {
#define kEpsilon 0.001f

	template<typename T>
	class MySet {
	private:
		T* data_;

		int size_;

		int ElementIsHere(T* data, int size, const T& value) {
			for (int i = 0; i < size; ++i)
			{
				if (data[i] == value)
					return i;
			}
			return -1;
		}

		T* GetUniqueData(T* data, int size, int* newsize) {
			T* unique_data = new T[size]();
			int i = 0;
			int j = 0;
			while (i < size && j < size) {
				if (ElementIsHere(unique_data, *newsize, data[j]) == -1) {
					unique_data[i] = data[j];
					*newsize += 1;
					++i;
					++j;
				}
				else ++j;
			}
			return unique_data;
		}

		void Sort() {
			for (int i = 0; i < size_; ++i)
			{
				for (int j = 0; j < size_ - 1; j++)
				{
					if (data_[j] > data_[j + 1]) {
						T temp = data_[j];
						data_[j] = data_[j + 1];
						data_[j + 1] = temp;
					}
				}
			}
		}
	public:
		MySet() :data_(nullptr), size_(0) {}

		MySet(T* data, int size) {
			int* newsize = new int(0);

			data_ = GetUniqueData(data, size, newsize);

			size_ = *newsize;

			this->Sort();

			delete newsize;
		}

		int GetSize() const {
			return size_;
		}

		const T* getdata() const {
			return data_;
		}

		T& operator[](int index) {
			if (index < 0 || index >= size_) {
				throw std::out_of_range("MySet::operator[], index is out of range");
			}
			return data_[index];
		}

		const T& operator[](int index) const {
			if (index < 0 || index >= size_) {
				throw std::out_of_range("MySet::operator[] const, index is out of range");
			}
			return data_[index];
		}

		~MySet() {
			delete[] data_;
			size_ = 0;
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& out, MySet<T>& set) {
		for (int i = 0; i < set.GetSize(); ++i)
		{
			std::cout << set[i] << " ";
			if (i == 9) std::cout << "\n";
		}
		return out;
	}
}