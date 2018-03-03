#include <iostream>

using namespace std;

class Vector{
    int capacity_;
    int size_;
    int* buffer_;
public:
    Vector(int capacity)
    : capacity_(capacity),
    size_(0),
    buffer_(new int[capacity])
    {}

    ~Vector() {
        delete [] buffer_;
    }


    int size() const {
        return size_; 
    }

    bool empty() const {
        return size_ == 0;
    }

    int& operator[](int n){
        return buffer_[n];
    }

    const int& operator[](int n) const {
        return buffer_[n];
    }

    void clear(){
        size_ = 0;
    }

    int capacity() const {
        return capacity_;
    }

    int& front(){
        return buffer_[0];
    }

    const int& front() const {
        if(size_ >= 0 && size_ <= capacity_)
        return buffer_[0];
    }

    int& back(){
        return buffer_[size_];
    }

    void resize(){
        buffer_ = new buffer_[capacity_ * 2];
        for(int i = 0; i < capacity_; i++){
            
        }
    }

    int& back() const {
        if(size_ >= 0 && size_ <= capacity_)
        return buffer_[size_];
    }

    void push_back(const int& value){
        if
        buffer_[size + 1]
    }
};

int main(){


    return 0;
}