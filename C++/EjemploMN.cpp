#include <iostream>
#include <cmath>

// Definir la función f(x)
double f(double x) {
    return x * x - 4;
}

// Definir la derivada de la función f(x)
double df(double x) {
    return 2 * x;
}

// Implementación del Método de Newton-Raphson
double newtonRaphson(double x0, double tol) {
    double x = x0;
    while (std::abs(f(x)) > tol) {
        x = x - f(x) / df(x);
    }
    return x;
}

int main() {
    // Parámetros de entrada
    double x0 = 3.0;  // Valor inicial
    double tolerancia = 1e-4;  // Tolerancia para la precisión

    // Encontrar la raíz
    double raiz = newtonRaphson(x0, tolerancia);

    // Mostrar el resultado
    std::cout << "La raíz de la función es aproximadamente: " << raiz << std::endl;

    return 0;
}
