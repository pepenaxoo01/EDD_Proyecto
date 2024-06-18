#pragma once

//Referencia: https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/

#include "Nodo.h"
#include <iostream>
#include <queue>
#include <map>


class Huffman {
private:
	std::string str_original;
	std::string str_codificada;
	std::map<char, std::string> tabla;
	Nodo* raiz;

	void _obtenerCodigos(Nodo* raiz, std::string str) {
		if (!raiz) {
			return;
		}

		if (raiz->dato != '$') {
			tabla[raiz->dato] = str;
		}

		_obtenerCodigos(raiz->izq, str + "0");
		_obtenerCodigos(raiz->der, str + "1");
	}

	std::string _codificarString(Nodo* raiz, const std::string& str) {

		std::string str_codificada;
		for (char c : str) {
			str_codificada += tabla[c];
		}

		return str_codificada;
	}

public:

	//Funcion que recibe un string y devuelve un puntero a un nodo que representa el arbol de huffman
	std::string codificar(const std::string& str) {
		//Vector de nodos que representan los caracteres del string
		std::priority_queue<Nodo*, std::vector<Nodo*>, compararNodos> cola;

		//Se cuentan los caracteres del string
		std::map<char, int> freq;
		for (char c : str) {
			freq[c]++;
		}

		//Se crean los nodos y se meten en la cola
		for (auto i = freq.begin(); i != freq.end(); i++) {
			cola.push(new Nodo(i->first, i->second));
		}

		Nodo* izq, * der, * top;

		while (cola.size() != 1) {
			//Sacamos los dos nodos con menor frecuencia
			izq = cola.top();
			cola.pop();

			der = cola.top();
			cola.pop();

			//Creamos un nodo con la suma de las frecuencias de los dos nodos anteriores
			//Los nodos sacados se convierten en hijos de este nodo
			//Asumiremos que el caracter '$' no se usara y es para representar un nodo interno
			top = new Nodo('$', izq->freq + der->freq);
			top->izq = izq;
			top->der = der;

			cola.push(top);
		}

		raiz = cola.top();
		_obtenerCodigos(raiz, "");
		str_codificada = _codificarString(raiz, str);
		return str_codificada;
	}

	std::string decodificar(const std::string& str) {
		std::string str_decodificada;
		Nodo* temp = raiz;

		for (char c : str) {
			if (c == '0') {
				temp = temp->izq;
			}
			else {
				temp = temp->der;
			}

			if (temp->isHoja()) {
				str_decodificada += temp->dato;
				temp = raiz;
			}
		}

		return str_decodificada;
	}

	std::string getStringCodificada() {
		return str_codificada;
	}

	std::map <char, std::string> getTabla() {
		return tabla;
	}
};






