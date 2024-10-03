// Código creado por Joshua Mijangos López, 01/10/24
// Este código está hecho para que las funciones del método y sus despejes se modifiquen desde aquí
// Este código no acepta de datos de ingreso desde consola, recomiendo ejecutarlo desde Powershell
// En algunas líneas utilizo "cout" y en otras "printf" debido a los caracteres especiales

#include <iostream>
#include <cmath>
#include <iomanip> // Para controlar el formato de salida, permite controlar la cantidad de decimales impresos en los resultados

using namespace std;

// Definimos la función f(x) y g(x) para el método del punto fijo
double f(double x) {
    return pow(x, 3) - x - 1;  // Esta es la ecuación f(x)
}

// g(x) = x es la reescritura de f(x) = 0 para obtener una función g(x) que nos permita aplicar el método del punto fijo
double g(double x) {
    return pow(x + 1, 1.0 / 3.0);  // Esta es una posible forma de g(x) basada en la ecuación f(x)
}

int main() {
    // Ingreso datos de entrada
    double x0 = 1;  // Aproximación inicial
    double tol = 1e-5;  // Tolerancia
    int nmax = 100;  // Número máximo de iteraciones
    double error = 100;
    int niter = 0;

    // Imprimir encabezado
    cout << "# de Iteraciones\t    x_n \t\t  g(x_n) \t\t   Error\n";

    // Método del Punto Fijo
    while (error > tol && niter < nmax) {
        double x1 = g(x0);

        // En la primera iteración no se imprime el error
        if (niter == 0) {
            cout << "\t" << niter + 1 << "\t\t" << fixed << setprecision(6) << x0 << "\t\t" << x1 << "\t\t   N/A\n";
        } else {
            error = abs(x1 - x0);
            cout << "\t" << niter + 1 << "\t\t" << fixed << setprecision(6) << x0 << "\t\t" << x1 << "\t\t" << error << "\n";
        }

        // Actualizar x0 para la siguiente iteración
        x0 = x1;
        niter++;
    }

    // Imprimir resultado final
    cout << "\nSe realizaron " << niter << " iteraciones.\n";
    printf("La ra%cz aproximada de la funci%cn f(x) es %.6f, con un error de %.5f\n", 161, 162, x0, tol);
    //# El segundo parámetro %.zf debe de modificarse si lo que se busca es disminuir el error, lo dejé preestablecido para z=5 (Es decir, un error de 10^-5)

    return 0;
}
