% Código creado por Joshua Mijangos López, 23/10/24
% Este código está hecho para que las funciones del método se modifiquen desde aquí
% Este código no acepta de datos de ingreso desde consola

% Definimos la función f(x)
f = @(x) x.^3 - 6*x.^2 + 11*x - 6.1;  % Ejemplo de un polinomio con tres raíces cercanas a 1, 2 y 3

% Definimos las variables iniciales para las iteraciones
x0 = 3.5;  % Primera aproximación inicial
x1 = 3.0;  % Segunda aproximación inicial
x2 = 2.5;  % Tercera aproximación inicial
tol = 1e-5;  % Tolerancia
nmax = 100;  % Número máximo de iteraciones
error = 100;
niter = 0;

% Imprimimos los encabezados de la tabla de resultados
fprintf('# de Iteración\t\t x_0 \t\t\t x_1 \t\t\t x_2 \t\t\t f(x_1) \t\t f(x_2) \t\t f(x_3) \t\t Error\n');

% Método de Müller
while error > tol && niter < nmax
    % Evaluamos la función en los puntos iniciales
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);

    % Calculamos los coeficientes a, b y c
    h0 = x1 - x0;
    h1 = x2 - x1;
    delta0 = (fx1 - fx0) / h0;
    delta1 = (fx2 - fx1) / h1;

    a = (delta1 - delta0) / (h1 + h0);  % Coeficiente cuadrático
    b = a * h1 + delta1;  % Coeficiente lineal
    c = fx2;  % Coeficiente independiente

    % Determinamos el discriminante
    discriminante = sqrt(b^2 - 4*a*c);

    % Calculamos las dos posibles soluciones de x3
    if abs(b + discriminante) > abs(b - discriminante)
        x3 = x2 - (2*c) / (b + discriminante);
    else
        x3 = x2 - (2*c) / (b - discriminante);
    end

    % Calculamos el error
    error = abs(x3 - x2);

    % Imprimimos los resultados de la iteración actual
    if niter == 0
        fprintf('%d\t\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %s\n', niter+1, x0, x1, x2, fx1, fx2, f(x3), 'N/A');
    else
        fprintf('%d\t\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\t\t %6.6f\n', niter+1, x0, x1, x2, fx1, fx2, f(x3), error);
    end

    % Actualizamos las variables para la siguiente iteración
    x0 = x1;
    x1 = x2;
    x2 = x3;
    niter = niter + 1;
end

% Resultado final
if error <= tol
    fprintf('\nSe realizaron %d iteraciones.\n', niter);
    fprintf('La raíz aproximada del Polinomio P(x) es %6.6f con un error de %6.5f\n', x2, tol);
else
    fprintf('El método no convergió en el número máximo de iteraciones.\n');
end
