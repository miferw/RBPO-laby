#include <iostream>
#include <new>

template <typename T>
class StackBasedOnBidirectionalLinkedList {
private:
    template <typename T>
    class Node {//класс Node, представляющий узел в двунаправленном связанном списке. 
    public:
        T data;
        Node* next;
        Node* prev;

        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    Node<T>* top;//top - указатель на вершину стека, и size - размер стека.
    int size;

public:

    int GetSize() const {
        return size;
    };
    void clear();
    bool Push(const T& element);
    bool Pop(T& element);
    bool Peek(T& element) const;
    StackBasedOnBidirectionalLinkedList();
    StackBasedOnBidirectionalLinkedList(const StackBasedOnBidirectionalLinkedList<T>& other);
    StackBasedOnBidirectionalLinkedList(StackBasedOnBidirectionalLinkedList<T>&& other);
    StackBasedOnBidirectionalLinkedList(std::initializer_list<T> ilist);
    ~StackBasedOnBidirectionalLinkedList();
    StackBasedOnBidirectionalLinkedList<T>& operator=(const StackBasedOnBidirectionalLinkedList<T>& other);
    StackBasedOnBidirectionalLinkedList<T>& operator=(StackBasedOnBidirectionalLinkedList<T>&& other);
    StackBasedOnBidirectionalLinkedList<T>& operator=(std::initializer_list<T> ilist);
};

template<typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList()
{
    size = 0;
    top = nullptr;
}

template<typename T>
StackBasedOnBidirectionalLinkedList<T>::~StackBasedOnBidirectionalLinkedList() {
    clear();//освобождает память, занятую узлами стека.
}

//Конструктор копирования использует оператор присваивания для копирования содержимого другого стека в текущий.
template <typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList(const StackBasedOnBidirectionalLinkedList<T>& other) : top(nullptr), size(0) {
    *this = other;
}

//Конструктор перемещения также использует оператор присваивания для перемещения содержимого другого стека в текущий.
template <typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList(StackBasedOnBidirectionalLinkedList<T>&& other) : top(nullptr), size(0) {
    *this = std::move(other);
}

//Конструктор инициализации использует оператор присваивания для инициализации стека списком инициализации.
template <typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList(std::initializer_list<T> ilist) : top(nullptr), size(0) {
    *this = ilist;
}


template <typename T>
StackBasedOnBidirectionalLinkedList<T>& StackBasedOnBidirectionalLinkedList<T>::operator=(const StackBasedOnBidirectionalLinkedList<T>& other) {
    if (this != &other) {
        clear();
        if (other.top != nullptr) {
            Node<T>* currentOther = other.top->next;
            do {
                if (!Push(currentOther->data)) {
                    clear();
                    throw std::bad_alloc();
                }
                currentOther = currentOther->next;
            } while (currentOther != other.top->next);
        }
    }

    return *this;
}

template <typename T>
StackBasedOnBidirectionalLinkedList<T>& StackBasedOnBidirectionalLinkedList<T>::operator=(StackBasedOnBidirectionalLinkedList<T>&& other) {
    if (this != &other) {
        clear();
        top = other.top;
        size = other.size;
        other.top = nullptr;
        other.size = 0;
    }

    return *this;
}


template <typename T>
StackBasedOnBidirectionalLinkedList<T>& StackBasedOnBidirectionalLinkedList<T>::operator=(std::initializer_list<T> ilist) {
    clear();
    for (const T& item : ilist) {
        Push(item);
    }
    return *this;
}

template<typename T>
void StackBasedOnBidirectionalLinkedList<T>::clear() {
    Node<T>* nextNode;
    while (size > 0) {
        nextNode = top->next;
        delete top;
        top = nextNode;
        --size;
    }
    top = nullptr;
    top = nullptr;
}

template<typename T>
bool StackBasedOnBidirectionalLinkedList<T>::Push(const T& element) {
    Node<T>* newNode = new(std::nothrow) Node<T>(element);
    if (newNode == nullptr) {
        return false;
    }
    if (size > 0) {
        newNode->next = newNode;

    }
   
    top = newNode;
    size++;
    return true;
}

template<typename T>
bool StackBasedOnBidirectionalLinkedList<T>::Pop(T& element) {
    if (top == nullptr) {
        return false;
    }
    element = top->data;
    Node<T>* toDelete = top;
    
    if (size == 1) {
        top->prev = nullptr;
    }
    else {
        top = toDelete->next;
    }
    delete toDelete;
    --size;
    return true;
}

template<typename T>
bool StackBasedOnBidirectionalLinkedList<T>::Peek(T& element) const {
    if (top == nullptr) {
        return false;
    }
    element = top->data;
    return true;
}


int main() {
    
    return 0;
}