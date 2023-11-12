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

		MySet(int size, const T begin, const T end) : size_(size), data_(new T[size]) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> dis(begin, end);
			for (int i = 0; i < size; ++i) {
				auto value = 0.0;
				int index = 0;
				while (index != -1) {
					value = dis(gen);
					index = ElementIsHere(data_, size_, value);
				}
				data_[i] = value;
			}
			this->Sort();
		}

		MySet(const MySet& rhs) : size_(rhs.GetSize()), data_(new T[rhs.GetSize()]) {
			for (int i = 0; i < rhs.GetSize(); i++)
			{
				data_[i] = rhs[i];
			}
		}

		MySet& operator=(const MySet& rhs) {
			MySet copy(rhs);
			swap(copy);
			return *this;
		}

		bool operator==(const MySet& rhs) {
			if (size_ != rhs.GetSize()) return false;
			for (int i = 0; i < size_; i++)
			{
				if (std::abs(data_[i] - rhs[i]) >= kEpsilon) return false;
			}
			return true;
		}

		bool operator!=(const MySet& rhs) {
			return !(*this == rhs);
		}

		int Find(const T& value) const {
			for (int i = 0; i < size_; i++)
			{
				if (data_[i] == value) return i;
			}
			return -1;
		}

		MySet<T> Intersection(const MySet<T>& rhs) {
			auto dif = *this - rhs;

			return (*this - dif);
		}

		int GetSize() const {
			return size_;
		}

		int& GetSize() {
			return size_;
		}

		const T* GetData() const {
			return data_;
		}

		T*& GetData() {
			return data_;
		}

		void Swap(MySet<T>& rhs) noexcept {
			std::swap(data_, rhs.GetData());
			std::swap(size_, rhs.GetSize());
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

		MySet& operator+=(const MySet& rhs) {
			int new_size = size_ + rhs.GetSize();

			T* new_data = new T[new_size]();

			for (int i = 0; i < size_; ++i)
			{
				new_data[i] = data_[i];
			}

			int j = 0;

			for (int i = size_; i < new_size; ++i)
			{
				new_data[i] = rhs[j];
				++j;
			}

			delete[] data_;

			int* actual_size = new int(0);

			data_ = GetUniqueData(new_data, new_size, actual_size);

			delete[] new_data;

			size_ = *actual_size;

			this->Sort();

			return *this;
		}

		MySet& operator-=(const MySet& rhs) {
			for (int i = 0; i < rhs.GetSize(); i++)
			{
				int index = ElementIsHere(data_, size_, rhs[i]);
				if (index != -1) {

					this->Remove(index);
				}
			}
			return *this;
		}

		MySet& operator+=(const T& value) {
			if (ElementIsHere(data_, size_, value) != -1) {
				return *this;
			}
			int new_size = size_ + 1;
			T* new_data = new T[new_size];
			for (int i = 0; i < size_; i++)
			{
				new_data[i] = data_[i];
			}
			new_data[new_size - 1] = value;
			delete[] data_;
			data_ = new_data;
			size_ = new_size;
			this->Sort();
			return *this;
		}

		MySet& operator-=(const T& value) {
			int index = ElementIsHere(data_, size_, value);
			if (index == -1) {
				return *this;
			}
			this->Remove(index);
			return *this;
		}

		void Remove(int index) {
			if (index < 0 || index >= size_) {
				throw std::out_of_range("MySet::remove, index is out of range");
			}
			for (int i = index; i < size_ - 1; i++)
			{
				T temp = data_[i];
				data_[i] = data_[i + 1];
				data_[i + 1] = temp;
			}
			size_--;
		}

		template<typename R>
		MySet operator+(const R& rhs) {
			MySet copy(*this);
			return copy += rhs;
		}

		template<typename R>
		MySet operator-(const R& rhs) {
			MySet copy(*this);
			return copy -= rhs;
		}

		~MySet() {
			delete[] data_;
			size_ = 0;
		}
	};

	template <>
	MySet<std::string>::MySet(int size, std::string begin, std::string end) : size_(size), data_(new std::string[size])
	{
		int asc_start = begin[0];
		int asc_end = end[0];
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(asc_start, asc_end);
		for (int i = 0; i < size_; i++)
		{
			char* word = new char[6]();
			for (int j = 0; j < 5; j++)
			{
				word[j] = dis(gen);
			}
			word[6] = '\n';
			data_[i] = std::string(word);
		}
	}

	template <>
	MySet<std::pair<int, double>>::MySet(int size, std::pair<int, double> begin, std::pair<int, double> end) : size_(size), data_(new std::pair<int, double>[size])
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis_first(begin.first, end.first);
		std::uniform_real_distribution<> dis_second(begin.second, end.second);
		for (int i = 0; i < size; i++)
		{
			data_[i] = std::make_pair(dis_first(gen), dis_second(gen));
		}
	}

	template<typename T, typename R>
	std::ostream& operator<<(std::ostream& out, std::pair<T, R>& pair) {
		out << "(" << pair.first << ", " << pair.second << ")";
		return out;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, MySet<T>& set) {
		for (size_t i = 0; i < set.GetSize(); i++)
		{
			out << set[i] << " ";
			if (i == 9) out << "\n";
		}
		return out;
	}
}