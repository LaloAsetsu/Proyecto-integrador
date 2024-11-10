// Codigo del nodo del arbol binario
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once

template<typename T>
class NodoArbol {
public:
    T info;
    NodoArbol<T> *left;
    NodoArbol<T> *right;
    NodoArbol(T dato) : info(dato), left(nullptr), right(nullptr) {}
    NodoArbol() : left(nullptr), right(nullptr) {}
    ~NodoArbol() {}
};

