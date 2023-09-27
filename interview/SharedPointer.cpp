#include <iostream>

template<typename T>
class SharedPointer {
public:
	// constructor
	SharedPointer(T* ptr = nullptr) :ptr_(ptr), count_(new int(1)) {}

	// destructor
	~SharedPointer() {
		(*count_)--;
		if (*count_ == 0) {
			delete ptr_;
			delete count_;
		}
	}

	// copy constructor
	SharedPointer(const SharedPointer& other) {
		if (this == &other) {
			return;
		}
		ptr_ = other.ptr_;
		count_ = other.count_;
		(*count_)++;
	}

	// operator= overload
	SharedPointer& operator=(const SharedPointer &other) {
		if (ptr_ == other.ptr_) {
			return *this;
		}
		(*count_)--;
		if (*count_ == 0) {
			delete ptr_;
			delete count_;
		}
		ptr_ = other.ptr_;
		count_ = other.count_;
		(*count_)++;
		return *this;
	}

	//operator* overload
	T& operator*() const {
		return *ptr_;
	}

	//operator-> overload
	T* operator->() const {
		return ptr_;
	}

	int use_count() {
		return *count_;
	}

private:
	T *ptr_;
	int *count_;
};

int main() {


	return 0;
}

