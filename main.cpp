#include "Huffman.h"
#include <iostream>
#include <string>

int main(void) {
	std::string str = "alabar_a_la_alabarda";
	Huffman huffman;

	std::string str_cod = huffman.codificar(str);
	std::cout << "Codificado: " << str_cod << std::endl;
	std::cout << "Decodificado: " << huffman.decodificar(str_cod) << std::endl;

	str = "abalarducha_alabardin";
	str_cod = huffman.codificar(str);
	std::cout << "Codificado: " << str_cod << std::endl;
	std::cout << "Decodificado: " << huffman.decodificar(str_cod) << std::endl;
}
