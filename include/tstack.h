// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T data[size];
    int topIndex;
public:
    TStack() : topIndex(-1) {}

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == size - 1;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        data[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        topIndex--;
    }

    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex];
    }

    void clear() {
        topIndex = -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

#endif  // INCLUDE_TSTACK_H_
