#include "Huffman.h"
#include "medir_compresion.h"
#include <iostream>
#include <string>

int main(void) {
	Huffman huffman;
	std::string str = "alabar_a_la_alabarda";
	std::string str_cod = huffman.codificar(str);
	std::cout << "Codificado: " << str_cod << std::endl;
	std::cout << "Decodificado: " << huffman.decodificar(str_cod) << std::endl;

	print_size_bits(str);
	print_size_bits(str_cod);

}
