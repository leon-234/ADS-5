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

    void push(T& value) {
        data[++topIndex] = value;
    }

    void pop() {
        topIndex--;
    }

    T top() {
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
