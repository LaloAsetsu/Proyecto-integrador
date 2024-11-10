// Codigo de la lista doblemente ligatda como un template
// Eduardo Antonio Mora Hernández - A01799440
// Ultima modificacion 24 de octubre del 2024
#pragma once
#include "Nodo.h"
#include <iostream>

template<typename T>
class LinkedList {
private:
    Nodo<T> *head, *tail;
    Nodo<T>* mergeSortExecute(Nodo<T> *node);
    Nodo<T>* merge(Nodo<T> *left, Nodo<T> *right);
    Nodo<T>* getMiddle(Nodo<T> *head);

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();
    bool insertStart(T data);
    bool insertEnd(T data);
    bool mergeSort();
    void printList() const;
    void deleteList();
    T* getObject(int pos);
};

// Destructor que llama la función que llama a deleteList() para liberar correcctamente la memoria
template<typename T>
LinkedList<T>::~LinkedList() {
    deleteList();
}

// Codigo que inserta un nuevo elemento al inicio de la lista, la funcion recibe el tipo de dato que se necesite y regresa verdadero o falso si el programa funciona o no
template<typename T>
bool LinkedList<T>::insertStart(T data) {
    Nodo<T>* newNode = new(std::nothrow) Nodo<T>(data);
    if (!newNode)
        return false;

    newNode->next = head;
    if (head)
        head->prev = newNode;
    if (!tail)
        tail = newNode;

    head = newNode;
    head->prev = nullptr; 
    return true;
}

// Codigo que inserta un nuevo elemento al final de la lista, la funcion recibe el tipo de dato que se necesite y regresa verdadero o falso si el programa funciona o no
template<typename T>
bool LinkedList<T>::insertEnd(T data) {
    Nodo<T> *newNode = new(std::nothrow) Nodo<T>(data);
    if (!newNode)
        return false;

    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    tail->next = nullptr; 
    return true;
}

// Funcion privada que dividira la lista liga de forma recursiva, se complementa con mergeSortExecute(), recibe los datos del nodo izquierdo y del derecho y retorna un puntero a un nodo
template<typename T>
Nodo<T>* LinkedList<T>::merge(Nodo<T> *left, Nodo<T> *right) {
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        left->next->prev = left; 
        return left;
    } else {
        right->next = merge(left, right->next);
        right->next->prev = right; 
        return right;
    }
}

// Funcion que obtendra la mitad de la lista ligada con con punteros fast & slow, recibe como parametro el head de la lista y retorna el nodo en la mitad
template<typename T>
Nodo<T>* LinkedList<T>::getMiddle(Nodo<T>* head) {
    if (!head)
        return head;

    Nodo<T>* slow = head;
    Nodo<T>* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Funcion que borrara la lista al ser llamada, no retorna ni recibe nada
template<typename T>
void LinkedList<T>::deleteList() {
    while (head != nullptr) {
        Nodo<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

// Funcion que retorna un nodo con una posicion dada por el usuario
template <typename T>
T* LinkedList<T>::getObject(int pos) {
    if (!head || pos < 0)
        return nullptr;

    Nodo<T>* current = head;
    int currentPosition = 0;
    while (current != nullptr && currentPosition < pos) {
        current = current->next;
        currentPosition++;
    }

    if (!current)
        return nullptr;

    return &current->data;
}

// Funcion auxiliar de Merge() la cual ejecutara el merge sort de la lista ligada, este recibe como parametro un nodo, que sera el head este caso
template<typename T>
Nodo<T>* LinkedList<T>::mergeSortExecute(Nodo<T>* node) {
    if (!node || !node->next)
        return node;

    Nodo<T>* middle = getMiddle(node);
    Nodo<T>* nextOfMiddle = middle->next;
    middle->next = nullptr;

    Nodo<T>* left = mergeSortExecute(node);
    Nodo<T>* right = mergeSortExecute(nextOfMiddle);

    return merge(left, right);
}

// Funcion publica para ejecutar el mergeSort()
template<typename T>
bool LinkedList<T>::mergeSort() {
    if (!head)
        return false;

    head = mergeSortExecute(head);
    Nodo<T>* temp = head;
    while (temp && temp->next) {
        temp = temp->next;
    }
    tail = temp;
    return true;
}

// Funcion para imprimir la lista ligada
template<typename T>
void LinkedList<T>::printList() const {
    Nodo<T>* tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}
