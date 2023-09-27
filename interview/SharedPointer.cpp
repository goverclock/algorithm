#include <iostream>

template<typename T>
class SharedPointer {
public:
	SharedPointer(T *ptr = nullptr) : ptr_(ptr), count_(new int(1)) {}

	~SharedPointer() {
		(*count_)--;
		if (*count_ == 0) {
			delete ptr_;
			delete count_;
		}
	}

	SharedPointer(const SharedPointer &other) {
		ptr_ = other.ptr_;
		count_ = other.count_;
		(*count_)++;
	}

	SharedPointer &operator=(const SharedPointer &other) {
		if (this == &other) {
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

	T &operator*() const {
		return *ptr_;
	}

	T *operator->() const {
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

