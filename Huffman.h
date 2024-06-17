#pragma once

//Referencia: https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/

#include "Nodo.h"
#include <iostream>
#include <queue>
#include <map>


void printCodigos(Nodo *raiz, std::string str) {
	if (!raiz) {
		return;
	}

	if (raiz->dato != '$') {
		std::cout << raiz->dato << ": " << str << "\n";
	}

	printCodigos(raiz->izq, str + "0");
	printCodigos(raiz->der, str + "1");
}

//Funcion que recibe un string y devuelve un puntero a un nodo que representa el arbol de huffman
void codificar(std::string str) {
	//Vector de nodos que representan los caracteres del string
	std::priority_queue<Nodo*, std::vector<Nodo*>, compararNodos> cola;

	//Se cuentan los caracteres del string
	std::map<char, int> freq;
	for (int i = 0; i < str.size(); i++) {
		freq[str[i]]++;
	}

	//Se crean los nodos y se meten en la cola
	for (auto i = freq.begin(); i != freq.end(); i++) {
		cola.push(new Nodo(i->first, i->second));
	}
	
	Nodo *izq, *der, *raiz;

	while (cola.size() != 1) {
		//Sacamos los dos nodos con menor frecuencia
		izq = cola.top();
		cola.pop();

		der = cola.top();
		cola.pop();

		//Creamos un nodo con la suma de las frecuencias de los dos nodos anteriores
		//Los nodos sacados se convierten en hijos de este nodo
		//Asumiremos que el caracter '$' no se usara y es para representar un nodo interno
		raiz = new Nodo('$', izq->freq + der->freq);
		raiz->izq = izq;
		raiz->der = der;

		cola.push(raiz);
	}

	printCodigos(cola.top(), "");
}

