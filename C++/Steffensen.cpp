// Código creado por Joshua Mijangos López, 13/10/24
// Este código está hecho para que las funciones del método se modifiquen desde aquí
// Este código no acepta de datos de ingreso desde consola, recomiendo ejecutarlo desde Powershell
// En algunas líneas utilizo "cout" y en otras "printf" debido a los caracteres especiales

#include <iostream>
#include <cmath>
#include <iomanip>  // Para formateo de salida

using namespace std;

// Definir la función f(x)
double f(double x) {
    return cos(x) - 2 * x + 3;
}

int main() {
    // Aproximación inicial
    double x0 = 1.5;  // Puedes ajustar este valor si lo deseas
    double tol = 1e-5;  // Tolerancia
    int nmax = 100;  // Número máximo de iteraciones
    double error = 100;  // Inicializar error con un valor alto
    int niter = 0;  // Contador de iteraciones

    // Encabezado de la tabla
    cout << "# de Iter\t    x_n\t\t   f(x_n)\t\t   g\t\t       Error" << endl;

    // Método de Steffensen
    while (error > tol && niter < nmax) {
        double fx0 = f(x0);

        // Realizamos la aproximación con la fórmula de diferencias divididas
        double g = (f(x0 + fx0) - fx0) / fx0;

        // Verificamos si el operador de diferencias divididas es 0
        if (g == 0) {
            printf("El operador de diferencia es cero, no se puede aplicar el m%ctodo de Steffensen.", 130);
            break;
        }

        // Siguiente aproximación
        double x1 = x0 - fx0 / g;

        // En la primera iteración no se imprime el error
        if (niter == 0) {
            cout << setw(5) << niter + 1 << "\t\t" << setw(10) << setprecision(6) << x0 << "\t\t" << setw(10) << setprecision(6) << fx0 << "\t\t" << setw(10) << setprecision(6) << g << "\t\t N/A" << endl;
        } else {
            error = fabs(x1 - x0);
            cout << setw(5) << niter + 1 << "\t\t" << setw(10) << setprecision(6) << x0 << "\t\t" << setw(10) << setprecision(6) << fx0 << "\t\t" << setw(10) << setprecision(6) << g << "\t\t" << setw(10) << setprecision(6) << error << endl;
        }

        // Actualizar x0 y el número de iteraciones
        x0 = x1;
        niter++;
    }

    // Imprimir resultado final
    if (error <= tol) {
        cout << "\nSe realizaron " << niter << " iteraciones." << endl;
         printf("La ra%cz aproximada de la funci%cn f(x)= cos(x) - 2x + 3 es %.6f, con un error de %.5f\n", 161, 162, x0, tol);
        // El segundo parámetro %.zf debe de modificarse si lo que se busca es disminuir el error, lo dejé preestablecido para z=5 (Es decir, un error de 10^-5
    } else {
        printf("El m%ctodo no convergi%c en el n%cmero m%cximo de iteraciones.", 130, 162, 163, 160);
    }

    return 0;
}
