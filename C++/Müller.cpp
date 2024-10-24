// Código creado por Joshua Mijangos López, 23/10/24
// Este código está hecho para que los polinomios que se le aplicará el método de Müller se modifiquen desde aquí
// Este código no acepta de datos de ingreso desde consola, recomiendo ejecutarlo desde Powershell
// En algunas líneas utilizo "cout" y en otras "printf" debido a los caracteres especiales

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definimos la función f(x), que en este caso será un polinomio de prueba
// Puedes cambiar esta función para probar con diferentes ecuaciones
double f(double x) {
    return pow(x, 3) - 6 * pow(x, 2) + 11 * x - 6.1; // Ejemplo de un polinomio con tres raíces cercanas a 1, 2 y 3
}

int main() {
    // Variables iniciales para las iteraciones
    double x0 = 3.5;  // Primera aproximación inicial
    double x1 = 3.0;  // Segunda aproximación inicial
    double x2 = 2.5;  // Tercera aproximación inicial
    double tol = 1e-5;  // Tolerancia
    int nmax = 100;  // Número máximo de iteraciones
    double error = 100.0;
    int niter = 0;

    // Imprimimos los encabezados de la tabla de resultados
    cout << "# de Iteración\t\tx_0\t\t\tx_1\t\t\tx_2\t\t\tf(x_1)\t\t\tf(x_2)\t\t\tf(x_3)\t\t\tError" << endl;

    // Método de Müller
    while (error > tol && niter < nmax) {
        // Evaluamos la función en los puntos iniciales
        double fx0 = f(x0);
        double fx1 = f(x1);
        double fx2 = f(x2);

        // Calculamos los coeficientes a, b y c
        double h0 = x1 - x0;
        double h1 = x2 - x1;
        double δ0 = (fx1 - fx0) / h0;
        double δ1 = (fx2 - fx1) / h1;

        double a = (δ1 - δ0) / (h1 + h0);  // Coeficiente cuadrático
        double b = a * h1 + δ1;  // Coeficiente lineal
        double c = fx2;  // Coeficiente independiente

        // Determinamos el discriminante
        double discriminante = sqrt(b * b - 4 * a * c);

        // Calculamos las dos posibles soluciones de x3
        double x3;
        if (abs(b + discriminante) > abs(b - discriminante)) {
            x3 = x2 - (2 * c) / (b + discriminante);
        } else {
            x3 = x2 - (2 * c) / (b - discriminante);
        }

        // Calculamos el error
        error = abs(x3 - x2);

        // Imprimimos los resultados de la iteración actual
        if (niter == 0) {
            cout << niter + 1 << "\t\t" << fixed << setprecision(6) << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" 
                 << fx1 << "\t\t" << fx2 << "\t\t" << f(x3) << "\t\tN/A" << endl;
        } else {
            cout << niter + 1 << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << fx1 << "\t\t" 
                 << fx2 << "\t\t" << f(x3) << "\t\t" << error << endl;
        }

        // Actualizamos las variables para la siguiente iteración
        x0 = x1;
        x1 = x2;
        x2 = x3;
        niter++;
    }

    // Resultado final
    
if (error <= tol) {
        printf("\nLa ra%cz aproximada del polinomio P(x) es %.5f con un error de 0.00001", 161, x2); 
    } else {
        printf("El m%ctodo no convergi%c en el n%cmero m%cximo de iteraciones.", 130, 162, 163, 160);
    }

    return 0;
}
