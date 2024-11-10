// Nodo para la lista ligada
// Eduardo Antonio Mora Hernández - A01799440
// Ultima modificación el 24 de octubre del 2024
#pragma once

template<typename T>
class Nodo {
public:
    Nodo<T> *next, *prev;
    T data;
    Nodo(T obj) : data(obj), next(nullptr), prev(nullptr) {}
};
