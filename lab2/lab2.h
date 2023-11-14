#pragma once
#include <iostream>
namespace mylist {

	template<typename T>
	struct Node {
		T value_;
		Node<T>* next_;

		Node(const T& value) : value_(value), next_(nullptr) {}
	};

	template<typename T>
	class LinkedList {
	private:
		Node<T>* head_;

		int size_;

		Node<T>* GetHead() const {
			return head_;
		}

		Node<T>*& GetHead() {
			return head_;
		}

	public:
		LinkedList() : head_(nullptr), size_(0) {}

		LinkedList(const LinkedList<T>& rhs) : head_(nullptr), size_(0) {
			for (int i = 0; i < rhs.GetSize(); i++)
			{
				this->PushTail(rhs[i]->value_);
			}
		}

		LinkedList& operator=(const LinkedList<T>& rhs) {
			LinkedList<T> copy(rhs);
			Swap(copy);
			return *this;
		}

		void Swap(LinkedList<T>& rhs) {
			std::swap(size_, rhs.GetSize());
			std::swap(head_, rhs.GetHead());
		}

		int GetSize() const {
			return size_;
		}

		int& GetSize() {
			return size_;
		}

		const Node<T>* operator[](int index) const {
			if (index < 0 || index >= size_) {
				throw std::out_of_range("LinkedList::operator[], index is out of range");
			}
			Node<T>* p = head_;
			while (index != 0) {
				p = p->next_;
				--index;
			}
			return p;
		}

		Node<T>* operator[](int index) {
			if (index < 0 || index >= size_) {
				throw std::out_of_range("LinkedList::operator[], index is out of range");
			}
			Node<T>* p = head_;
			while (index != 0) {
				p = p->next_;
				--index;
			}
			return p;
		}

		void PushTail(const T& value) {
			Node<T>* p = new Node<T>(value);
			if (head_ == nullptr) {
				head_ = p;
				++size_;
				return;
			}
			Node<T>* h = head_;
			while (h != nullptr && h->next_ != nullptr) {
				h = h->next_;
			}
			h->next_ = p;
			++size_;
		}

		~LinkedList() {
			while (head_ != nullptr) {
				Node<T>* p = head_;
				head_ = p->next_;
				delete p;
			}
			size_ = 0;
		}
	};


	template<typename T>
	std::ostream& operator<<(std::ostream& out, LinkedList<T>& list) {
		for (int i = 0; i < list.GetSize(); ++i)
		{
			out << list[i]->value_ << '\n';
		}
		if (list.GetSize() == 0) {
			out << '\n';
			out << "--------";
			out << '\n';
		}
		out << '\n';
		return out;
	}
}