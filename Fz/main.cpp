#include "LZCompressor.h"
#include "medir_compresion.h"
#include <iostream>
#include <string>

int main() {
    LZCompressor compressor;
    std::string str = "tangananica-tanganana";
    std::vector<std::pair<int, int>> compressed = compressor.comprimir(str);
    
    std::cout << "Original: " << str << std::endl;
    std::cout << "Compresión LZ (pares): ";
    for (const auto& par : compressed) {
        if (par.second == 0) {
            std::cout << "(" << static_cast<char>(par.first) << ", " << par.second << ") ";
        } else {
            std::cout << "(" << par.first << ", " << par.second << ") ";
        }
    }
    std::cout << std::endl;

    std::string decompressed = compressor.descomprimir(compressed);
    std::cout << "Descomprimido: " << decompressed << std::endl;

    print_size_bits(str);
    // Convertimos los pares a una representación de string binario para medir el tamaño en bits
    std::string compressedStr;
    for (const auto& par : compressed) {
        if (par.second == 0) {
            compressedStr += static_cast<char>(par.first);
        } else {
            compressedStr += std::to_string(par.first) + "," + std::to_string(par.second) + " ";
        }
    }
    print_size_bits(compressedStr);

    return 0;
}
