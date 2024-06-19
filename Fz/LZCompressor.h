#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

// Clase para manejar la compresión LZ
class LZCompressor {
public:
    // Función para comprimir una cadena usando LZ
    std::vector<std::pair<int, int>> comprimir(const std::string& str);

    // Función para descomprimir usando LZ
    std::string descomprimir(const std::vector<std::pair<int, int>>& compressed);

private:
    std::unordered_map<std::string, int> diccionario;
};

// Implementación de la función para comprimir
std::vector<std::pair<int, int>> LZCompressor::comprimir(const std::string& str) {
    std::vector<std::pair<int, int>> resultado;
    int n = str.size();
    int i = 0;
    while (i < n) {
        std::string subcadena;
        int posicion = -1;
        int longitud = 0;
        for (int j = 1; i + j <= n; ++j) {
            subcadena = str.substr(i, j);
            if (diccionario.find(subcadena) != diccionario.end()) {
                posicion = diccionario[subcadena];
                longitud = j;
            } else {
                break;
            }
        }
        if (longitud > 0) {
            resultado.emplace_back(posicion, longitud);
            diccionario[subcadena] = i;
            i += longitud;
        } else {
            resultado.emplace_back(str[i], 0);
            diccionario[std::string(1, str[i])] = i;
            ++i;
        }
    }
    return resultado;
}

// Implementación de la función para descomprimir
std::string LZCompressor::descomprimir(const std::vector<std::pair<int, int>>& compressed) {
    std::string resultado;
    for (const auto& par : compressed) {
        if (par.second == 0) {
            resultado += static_cast<char>(par.first);
        } else {
            resultado += resultado.substr(par.first, par.second);
        }
    }
    return resultado;
}
