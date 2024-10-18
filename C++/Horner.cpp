// Código creado por Joshua Mijangos López, 17/10/24
// Este código está hecho para que los polinomios que se le aplicará el método de Horner se modifiquen desde aquí
// Este código no acepta de datos de ingreso desde consola, recomiendo ejecutarlo desde Powershell
// En algunas líneas utilizo "cout" y en otras "printf" debido a los caracteres especiales

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para evaluar el polinomio utilizando el método de Horner
double horner(const vector<double>& coefs, double x) {
    double result = coefs[0];
    for (size_t i = 1; i < coefs.size(); i++) {
        result = result * x + coefs[i];
    }
    return result;
}

// Función para calcular los coeficientes de la derivada del polinomio
vector<double> derivada(const vector<double>& coefs) {
    vector<double> deriv(coefs.size() - 1);
    for (size_t i = 0; i < coefs.size() - 1; i++) {
        deriv[i] = coefs[i] * (coefs.size() - 1 - i);
    }
    return deriv;
}

// Función para evaluar la derivada en un punto x
double evaluar_derivada(const vector<double>& deriv_coefs, double x) {
    return horner(deriv_coefs, x);
}

int main() {
    // Coeficientes del polinomio P(x) = 2x^4 - 3x^2 + 3x - 4
    vector<double> coefs = {2, 0, -3, 3, -4};

    // Aproximación inicial
    double x0 = -2;
    
    // Tolerancia y número máximo de iteraciones
    double tol = 1e-5;
    int nmax = 100;
    double error = 100;
    int niter = 0;

    // Calcular la derivada del polinomio
    vector<double> deriv_coefs = derivada(coefs);

    printf("Resultados del m%ctodo de Horner aplicado con Newton:\n", 130);

    // Método de Newton usando Horner
    while (error > tol && niter < nmax) {
        double fx0 = horner(coefs, x0);    // Evaluar P(x0) con Horner
        double dfx0 = evaluar_derivada(deriv_coefs, x0);  // Evaluar P'(x0)

        if (dfx0 == 0) {
            cout << "La derivada es cero, no se puede aplicar el método de Newton.\n";
            break;
        }

        double x1 = x0 - fx0 / dfx0;  // Fórmula de Newton

        // Actualizar el error y el valor de x0
        error = fabs(x1 - x0);
        x0 = x1;
        niter++;
    }

    // Imprimir el resultado final
    if (error <= tol) {
        printf("\nLa ra%cz aproximada del polinomio P(x) es %.5f", 161, x0); 
    } else {
        printf("El m%ctodo no convergi%c en el n%cmero m%cximo de iteraciones.", 130, 162, 163, 160);
    }

    return 0;
}
