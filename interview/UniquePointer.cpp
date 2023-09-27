// based on https://medium.com/dev-genius/unique-pointer-and-implementation-in-c-ec6599a518e5

#include <iostream>

template <typename T>
class UniquePointer {
public:
    // Constructor
    explicit UniquePointer(T* ptr = nullptr) : ptr_(ptr) {}

    // Destructor
    ~UniquePointer() {
        delete ptr_;
    }

    // Copy constructor and assignment operator deleted
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer &operator=(const UniquePointer&) = delete;

    // Move constructor and assignment operator
    UniquePointer(UniquePointer &&other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    UniquePointer &operator=(UniquePointer&& other) {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    operator bool() const {
        return ptr_ != nullptr;
    }

    T* get() const {
        return ptr_;
    }

    T* release() {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

private:
    T* ptr_;
};

int main() {

	return 0;
}

