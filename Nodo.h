#pragma once

#include <iostream>

//Nodo de un arbol de Huffman
struct Nodo {
	//caracter
	char dato;

	//frecuencia del caracter
	size_t freq;

	//punteros a los hijos
	Nodo *izq, *der;

	Nodo(char dato, size_t freq) {
		izq = der = nullptr;
		this->dato = dato;
		this->freq = freq;
	}

	bool isHoja() {
		return izq == nullptr && der == nullptr;
	}
};

//struct para comparar nodos en la priority queue
struct compararNodos {
	//O(1)
	bool operator()(Nodo* izq, Nodo* der) {
		return izq->freq > der->freq;
	}
};
