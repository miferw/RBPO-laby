#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
public:
    virtual int GetSize() const = 0;
    virtual void Push(const T& element) = 0;
    virtual T Pop() = 0;
    virtual T Peek() const = 0;
};

template<typename T>
class StackBasedOnArray : public Stack<T> {
private:
    T* elements;
    int capacity;
    int size;

public:
    
    StackBasedOnArray(int capacity = 10) : capacity(capacity), size(0) {
        elements = new T[capacity];
    }

    ~StackBasedOnArray() {
        delete[] elements;
    }

    int GetSize() const override {
        return size;
    }

    void Push(const T& element) override {
        if (size == capacity) {
            // Расширение массива при необходимости
            capacity *= 2;
            T* newElements = new T[capacity];
            std::copy(elements, elements + size, newElements);
            delete[] elements;
            elements = newElements;
        }

        elements[size++] = element;
    }

    T Pop() override {
        if (size == 0) {
            throw std::out_of_range("Stack underflow");
        }

        return elements[--size];
    }

    T Peek() const override {
        if (size == 0) {
            throw std::out_of_range("Stack is empty");
        }

        return elements[size - 1];
    }

    friend std::ostream& operator<<(std::ostream& os, const StackBasedOnArray& stack) {//Перегруженный оператор вывода:
        for (int i = 0; i < stack.size; ++i) {
            os << stack.elements[i] << " ";
        }
        return os;
    }

    
    void DemonstrateClassViaPointer(Stack<T>* stack) {
        if (stack == nullptr) {
            std::cout << "Null pointer passed." << std::endl;
            return;
        }
        std::cout << "Adding element via pointer." << std::endl;
        stack->Push(7);
        std::cout << "Popping element via pointer: " << stack->Pop() << std::endl;
    }

    
    void DemonstrateClassViaReference(Stack<T>& stack) {
        std::cout << "Adding element via reference." << std::endl;
        stack.Push(4);
        std::cout << "Popping element via reference: " << stack.Pop() << std::endl;
    }
};

int main() {
    
    StackBasedOnArray<int> stack;

    
    stack.DemonstrateClassViaPointer(&stack);

    
    stack.DemonstrateClassViaReference(stack);

    
    std::cout << "Stack: " << stack << std::endl;

    return 0;
}
