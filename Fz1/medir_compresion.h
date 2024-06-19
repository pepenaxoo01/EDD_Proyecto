
#pragma once
#include <string>
#include <iostream>

// Función que revisa si la string es una cadena de 1s y 0s
bool isBinaryString(const std::string& s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Devuelve el tamaño en bits de la string (Si es binario se almacena en string pero muestra el tamaño que debería tener en bits)
size_t size_bits(const std::string& s) {
    if (!isBinaryString(s)) {
        return s.size() * 8;
    } else {
        return s.size();
    }
}

void print_size_bits(const std::string& s) {
    std::cout << "Size of: '" << s << "': " << size_bits(s) << " bits." << std::endl;
}
