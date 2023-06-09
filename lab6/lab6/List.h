#pragma once
#include <iostream>


using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    class Iterator {
    private:
        Node* current;

    public:
        Iterator() : current(nullptr) {}
        Iterator(Node* node) : current(node) {}

        T& operator*() const;
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

        T& get_value(int index);
    };

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() { clear(); }
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void clear();
    void insert(const T& value, int index);
    void erase(int index);
    void print();
    bool empty() ;
    int get_size() { return size; }
    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
    
    T& get_value(int index);
    T& operator[](int index);
};

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node* nodeToRemove = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete nodeToRemove;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    Node* nodeToRemove = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete nodeToRemove;
    size--;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::insert(const T& value, int index) {
    if (index < 0 || index > size) {
        return;
    }
    if (index == 0) {
        push_front(value);
    }
    else if (index == size) {
        push_back(value);
    }
    else {
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::erase(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    if (index == 0) {
        pop_front();
    }
    else if (index == size - 1) {
        pop_back();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* nodeToRemove = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete nodeToRemove;
        size--;
    }
}

template <typename T>
void DoublyLinkedList<T>::print() {
    if (head == NULL) {
        std::cout << "Empty";
        return;
    }

    for (Iterator it = begin(); it != end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool DoublyLinkedList<T>::empty() {
    return head == NULL;
}


template<typename T>
T& DoublyLinkedList<T>::get_value(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}


template<typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    return get_value(index);
}


template <typename T>
T& DoublyLinkedList<T>::Iterator::operator*() const {
    return current->data;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
    Iterator iterator = *this;
    ++(*this);
    return iterator;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
    current = current->prev;
    return *this;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
    Iterator iterator = *this;
    --(*this);
    return iterator;
}

template <typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template <typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}





template <typename T>
void menu(DoublyLinkedList<T>& list) {
    int choice;
    T value;
    int index;

    while (true) {
        cout << "---------- Menu ----------" << endl;
        cout << "1. Push Front" << endl;
        cout << "2. Push Back" << endl;
        cout << "3. Pop Front" << endl;
        cout << "4. Pop Back" << endl;
        cout << "5. Insert" << endl;
        cout << "6. Erase" << endl;
        cout << "7. Print" << endl;
        cout << "8. Clear" << endl;
        cout << "9. Get Value at Index" << endl; // New option added
        cout << "10. Exit" << endl; // Updated option number
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to push front: ";
            cin >> value;
            list.push_front(value);
            cout << "Value pushed to the front." << endl;
            cout << "List: ";
            list.print();
            break;
        case 2:
            cout << "Enter the value to push back: ";
            cin >> value;
            list.push_back(value);
            cout << "Value pushed to the back." << endl;
            cout << "List: ";
            list.print();
            break;
        case 3:
            if (list.empty()) {
                cout << "Cannot pop from an empty list." << endl;
            }
            else {
                list.pop_front();
                cout << "Value popped from the front." << endl;
                cout << "List: ";
                list.print();
            }
            break;
        case 4:
            if (list.empty()) {
                cout << "Cannot pop from an empty list." << endl;
            }
            else {
                list.pop_back();
                cout << "Value popped from the back." << endl;
                cout << "List: ";
                list.print();
            }
            break;
        case 5:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the index to insert at: ";
            cin >> index;
            if (list.get_size() < index) {
                cout << "Index out of range";
                break;
            }
            list.insert(value, index);
            cout << "Value inserted at index " << index << "." << endl;
            cout << "List: ";
            list.print();
            break;
        case 6:
            cout << "Enter the index to erase: ";
            cin >> index;
            if (list.get_size() < index) {
                cout << "Index out of range";
                break;
            }
            list.erase(index);
            cout << "Value erased from index " << index << "." << endl;
            cout << "List: ";
            list.print();
            break;
        case 7:
            cout << "List: ";
            list.print();
            break;
        case 8:
            list.clear();
            cout << "List cleared." << endl;
            cout << "List: ";
            list.print();
            break;
        case 9:
            cout << "Enter the index to get value: ";
            cin >> index;
            if (list.get_size() < index) {
                cout << "Index out of range";
                break;
            }
            cout << "Value at index " << index << ": " << list[index] << endl;
            break;
        case 10:
            cout << "Exiting..." << endl;
            return;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << endl;
    }
}

