// based on https://blog.devgenius.io/shared-pointer-and-implementation-in-c-7ac3d299769e

#include <iostream>

template <typename T>
class SharedPointer {
public:
    SharedPointer(T* ptr = nullptr) {
        if (ptr != nullptr) {
            count_ = new int(1);
            ptr_ = ptr;
        }
    }

    ~SharedPointer() {
        release();
    }

    SharedPointer(const SharedPointer& other) {
        ptr_ = other.ptr_;
        count_ = other.count_;
        if (count_ != nullptr) {
            (*count_)++;
        }
    }

    SharedPointer &operator=(const SharedPointer& other) {
        if (this != &other) {
			release();
			ptr_ = other.ptr_;
			count_ = other.count_;
			if (count_ != nullptr) {
				(*count_)++;
			}
		}
       	return *this;
    }

    T &operator*() const {
        return *ptr_;
    }

    T *operator->() const {
        return ptr_;
    }

    int use_count() const {
        return (count_ == nullptr) ? 0 : *count_;
    }

private:
    T *ptr_ = nullptr;
    int *count_ = nullptr;

    void release() {
		if (count_ == nullptr) {
			return;
		}
		(*count_)--;
		if (*count_ == 0) {
			delete ptr_;
			delete count_;
			ptr_ = nullptr;
			count_ = nullptr;
		}
    }
};

int main() {

	return 0;
}

