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

		void PushHead(const T& value) {
			Node<T>* p = new Node<T>(value);
			p->next_ = head_;
			head_ = p;
			++size_;
		}

		void PushHead(const LinkedList<T>& rhs) {
			LinkedList<int> copy(rhs);
			copy.PushTail(*this);
			Swap(copy);
		}

		Node<T>* PopHead() {
			if (size_ == 0) {
				return nullptr;
			}
			Node<T>* p = head_;
			head_ = p->next_;
			--size_;
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

		void PushTail(const LinkedList<T>& rhs) {
			for (int i = 0; i < rhs.GetSize(); i++)
			{
				this->PushTail(rhs[i]->value_);
			}
		}

		Node<T>* PopTail() {
			if (size_ == 0) {
				return nullptr;
			}
			Node<T>* h = head_;
			while (h->next_ != nullptr && h->next_->next_ != nullptr)
			{
				h = h->next_;
			}
			Node<T>* p = h;
			if (size_ != 1) {
				p = p->next_;
				h->next_ = nullptr;
			}
			--size_;
			return p;
		}

		void DeleteNode(const T del_value) {
			Node<T>* h = head_;
			Node<T>* last_node = nullptr;
			while (h != nullptr) {
				if (h->value_ == del_value) {
					Node<T>* p = h;
					h = h->next_;
					if (head_->value_ == del_value) {
						head_ = h;
						last_node = head_;
					}
					delete p;
					p = nullptr;
					--size_;
					if (last_node != nullptr && last_node != h) {
						last_node->next_ = h;
					}
				}
				else {
					last_node = h;
					h = h->next_;
				}
			}
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