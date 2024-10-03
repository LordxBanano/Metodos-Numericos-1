// Código creado por Joshua Mijangos López, 02/10/24
// Este código está hecho para que las funciones del método se modifiquen desde aquí
// Este código no acepta de datos de ingreso desde consola, recomiendo ejecutarlo desde Powershell
// En algunas líneas utilizo "cout" y en otras "printf" debido a los caracteres especiales

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definimos la función f(x) y su derivada f'(x)
double f(double x) {
    return pow(x, 3) - x - 1;  // f(x) = x^3 - x - 1
}

double df(double x) {
    return 3 * pow(x, 2) - 1;  // f'(x) = 3x^2 - 1
}

int main() {
    double x0 = 1;  // Aproximación inicial
    double tol = 1e-5;  // Tolerancia
    int nmax = 100;  // Número máximo de iteraciones
    double error = 100;
    int niter = 0;

    cout << "# de Iteraciones\t\t  x_n \t\t    f(x_n) \t\t   Error\n";

    // Método de Newton
    while (error > tol && niter < nmax) {
        double fx0 = f(x0);
        double dfx0 = df(x0);

        // Verificar si la derivada es cero
        if (dfx0 == 0) {
            cout << "La derivada es cero, no se puede aplicar el método de Newton." << endl;
            break;
        }

        double x1 = x0 - fx0 / dfx0;  // Fórmula de Newton

        // Primera iteración sin error
        if (niter == 0) {
            cout << "\t" << niter + 1 << "\t\t " << fixed << setprecision(6) << x0 << "\t\t " << fx0 << "\t\t   N/A\n";
        } else {
            error = fabs(x1 - x0);  // Calcula el error
            cout << "\t" << niter + 1 << "\t\t " << fixed << setprecision(6) << x0 << "\t\t " << fx0 << "\t\t " << error << "\n";
        }

        // Actualizar para la siguiente iteración
        x0 = x1;
        niter++;
    }

    // Imprimir resultado final
    if (error <= tol) {
        cout << "\nSe realizaron " << niter << " iteraciones.\n";
        printf("La ra%cz aproximada de la funci%cn f(x) es %.6f, con un error de %.5f\n", 161, 162, x0, tol);
        // El segundo parámetro %.zf debe de modificarse si lo que se busca es disminuir el error, lo dejé preestablecido para z=5 (Es decir, un error de 10^-5)
    } else {
        printf("El m%ctodo no convergi%c en el n%cmero m%cximo de iteraciones.\n", 130, 162, 163, 160 );
    }

    return 0;
}
