// Codigo del arbol binario como template
// Eduardo Antonio Mora Hernández - A10774400
// Ultima Modificación el 24 de octubre del 2024
#pragma once
#include "NodoArbol.h"
#include <iostream>

template<typename T>
class ArbolBinario {
private:
    NodoArbol<T> *root;
    bool insertaRecursivo(NodoArbol<T> *&nodo, T dato);
    NodoArbol<T>* buscarRecursivo(NodoArbol<T> *actual, T dato);
    void imprimeInOrderRecursivo(NodoArbol<T> *actual);
    void imprimePreOrderRecursivo(NodoArbol<T> *actual);
    void imprimePostOrderRecursivo(NodoArbol<T> *actual);
    bool borrarRecursivo(NodoArbol<T> *&nodo);
    bool borrarNodoRecursivo(NodoArbol<T> *&actual, T dato);

public:
    ArbolBinario();
    ~ArbolBinario();
    bool inserta(T dato);
    T* buscar(T dato);
    void imprimeInOrder();
    void imprimePreOrder();
    void imprimePostOrder();
    bool borrarArbol();
    bool borrarNodo(T dato);
    NodoArbol<T>* getRoot();
};

template<typename T>
ArbolBinario<T>::ArbolBinario() : root(nullptr) {}

template<typename T>
ArbolBinario<T>::~ArbolBinario() {
    borrarArbol();
}

// Funcion publica para insertar un dato en el arbol binario, recibe el tipo de dato que el usuario desea y retorna un booleano
template<typename T>
bool ArbolBinario<T>::inserta(T dato) {
    return insertaRecursivo(root, dato);
}

// Funcion auxiliar para insertar de forma recursiva un dato al arbol, recibe la raiz del arbol y un dato dado por el usuario, retorna un bool
template<typename T>
bool ArbolBinario<T>::insertaRecursivo(NodoArbol<T> *&nodo, T dato) {
    if (!nodo) {
        nodo = new(std::nothrow) NodoArbol<T>(dato);
        return nodo != nullptr;
    }
    if (dato < nodo->info) {
        return insertaRecursivo(nodo->left, dato);
    } else if (dato > nodo->info) {
        return insertaRecursivo(nodo->right, dato);
    }
    return false;
}

// Funcion auxiliar para el metodo de busqueda de un dato, recibe un nodo y el dato que busca, regresa el nodo si es encontrado, si no regresa nullptr
template<typename T>
NodoArbol<T>* ArbolBinario<T>::buscarRecursivo(NodoArbol<T> *actual, T dato) {
    if (!actual) return nullptr;
    if (dato < actual->info) {
        return buscarRecursivo(actual->left, dato);
    } else if (dato > actual->info) {
        return buscarRecursivo(actual->right, dato);
    }
    return actual;
}
// Funcion publica que recibe un dato y busca ese dato con la funcion buscarRecursivo(), si encuentra nodo con el dato, regresa el nodo, si no lo encuentra regresa nullptr
template<typename T>
T* ArbolBinario<T>::buscar(T dato) {
    NodoArbol<T> *resultado = buscarRecursivo(root, dato);
    return resultado ? &(resultado->info) : nullptr;
}

// Funcion auxiliar para imprimir el arbol inOrder, recibe el root del arbol y no regresa nada, solo imprime el dato de los nodos que recorre
template <typename T>
void ArbolBinario<T>::imprimeInOrderRecursivo(NodoArbol<T> *actual) {
    if (!actual) return;
    imprimeInOrderRecursivo(actual->left);
    std::cout << actual->info << " ";
    imprimeInOrderRecursivo(actual->right);
}

// Funcion publica para imprimir inOrder el arbol con el apoyo de imprimeInOrderRecursivo
template <typename T>
void ArbolBinario<T>::imprimeInOrder() {
    imprimeInOrderRecursivo(root);
    std::cout << std::endl;
}

// Funcion auxiliar para imprimir el arbol preOrder, recibe el root del arbol y no regresa nada, solo imprime el dato de los nodos que recorre
template <typename T>
void ArbolBinario<T>::imprimePreOrderRecursivo(NodoArbol<T> *actual) {
    if (!actual) return;
    std::cout << actual->info << " ";
    imprimePreOrderRecursivo(actual->left);
    imprimePreOrderRecursivo(actual->right);
}

// Funcion publica para imprimir preOrder el arbol con el apoyo de imprimePreOrderRecursivo()
template <typename T>
void ArbolBinario<T>::imprimePreOrder() {
    imprimePreOrderRecursivo(root);
    std::cout << std::endl;
}

// Funcion auxiliar para imprimir el arbol postOrder, recibe el root del arbol y no regresa nada, solo imprime el dato de los nodos que recorre

template <typename T>
void ArbolBinario<T>::imprimePostOrderRecursivo(NodoArbol<T> *actual) {
    if (!actual) return;
    imprimePostOrderRecursivo(actual->left);
    imprimePostOrderRecursivo(actual->right);
    std::cout << actual->info << " ";
}

// Funcion publica para imprimir postOrder el arbol con el apoyo de imprimePostOrderRecursivo()
template <typename T>
void ArbolBinario<T>::imprimePostOrder() {
    imprimePostOrderRecursivo(root);
    std::cout << std::endl;
}

// Funcion publica que borrara el arbol, regresa un bool si se borro o no el arbol
template<typename T>
bool ArbolBinario<T>::borrarArbol() {
    return borrarRecursivo(root);
}

// Funcion auxiliar para borrar el arbol, recibe el root del arbol y regresa verdadero o falso si borro o no el arbol
template<typename T>
bool ArbolBinario<T>::borrarRecursivo(NodoArbol<T> *&nodo) {
    if (!nodo) return true;
    borrarRecursivo(nodo->left);
    borrarRecursivo(nodo->right);
    delete nodo;
    nodo = nullptr;
    return true;
}

// Funcion auxiliar para borrar un nodo con un dato dado por el usuario, recibe el root cuando se llama y el dato a buscar a borrar, regresa un verdadero o falso si se borro o no el nodo
template<typename T>
bool ArbolBinario<T>::borrarNodoRecursivo(NodoArbol<T> *&actual, T dato) {
    if (!actual) return false;
    if (dato < actual->info) {
        return borrarNodoRecursivo(actual->left, dato);
    } else if (dato > actual->info) {
        return borrarNodoRecursivo(actual->right, dato);
    } else {
        if (!actual->left && !actual->right) {
            delete actual;
            actual = nullptr;
        } else if (!actual->left) {
            NodoArbol<T> *temp = actual;
            actual = actual->right;
            delete temp;
        } else if (!actual->right) {
            NodoArbol<T> *temp = actual;
            actual = actual->left;
            delete temp;
        } else {
            NodoArbol<T> *temp = actual->right;
            while (temp->left) temp = temp->left;
            actual->info = temp->info;
            borrarNodoRecursivo(actual->right, temp->info);
        }
        return true;
    }
}

// Funcion publica para borrar un nodo que recibe un dato especifico y regresa verdadero o falso si se borro o no el nodo
template <typename T>
bool ArbolBinario<T>::borrarNodo(T dato) {
    return borrarNodoRecursivo(root, dato);
}

// Funcion para devolver un nodo, regresa un nodo
template<typename T>
NodoArbol<T>* ArbolBinario<T>::getRoot() {
    return root;
}
