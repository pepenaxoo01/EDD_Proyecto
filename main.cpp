#include "Huffman.h"
#include <iostream>
#include <string>

int main(void) {
	std::string str = "alabar_a_la_alabarda";
	Huffman huffman(str);

	std::string str_cod = huffman.getStringCodificada();
	std::map<char, std::string> tabla = huffman.getTabla();

	std::cout << str_cod << std::endl;

	for (auto it = tabla.begin(); it != tabla.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
}
