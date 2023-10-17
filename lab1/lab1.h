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
			T* uniquedata = new T[size]();
			int i = 0;
			int j = 0;
			while (i < size && j < size) {
				if (ElementIsHere(uniquedata, *newsize, data[j]) == -1) {
					uniquedata[i] = data[j];
					*newsize += 1;
					++i;
					++j;
				}
				else ++j;
			}
			return uniquedata;
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

		int getsize() const {
			return size_;
		}

		const T* getdata() const {
			return data_;
		}
	};
}