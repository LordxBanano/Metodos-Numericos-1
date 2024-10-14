% Código creado por Joshua Mijangos López, 13/10/24
% Este código está hecho para que las funciones del método se modifiquen desde aquí
% Este código no acepta de datos de ingreso desde consola

% Definir la función f(x)
f = @(x) cos(x) - 2*x + 3;

% Parámetros iniciales
x0 = 1.5;  % Aproximación inicial
tol = 1e-5;  % Tolerancia
nmax = 100;  % Número máximo de iteraciones
error = 100;  % Inicializar error con un valor alto
niter = 0;  % Contador de iteraciones

% Encabezado de la tabla
fprintf('# de Iteración\t    x_n\t\t\t   f(x_n)\t\t   g\t\t       Error\n');

% Método de Steffensen
while error > tol && niter < nmax
    fx0 = f(x0);

    % Realizamos la aproximación con la fórmula de diferencias divididas
    g = (f(x0 + fx0) - fx0) / fx0;

    % Verificamos si el operador de diferencias divididas es 0
    if g == 0
        disp('El operador de diferencia es cero, no se puede aplicar el método de Steffensen.');
        break;
    end

    % Siguiente aproximación
    x1 = x0 - fx0 / g;

    % En la primera iteración no se imprime el error
    if niter == 0
        fprintf('%5d\t\t%10.6f\t\t%10.6f\t\t%10.6f\t\tN/A\n', niter+1, x0, fx0, g);
    else
        error = abs(x1 - x0);
        fprintf('%5d\t\t%10.6f\t\t%10.6f\t\t%10.6f\t\t%10.6f\n', niter+1, x0, fx0, g, error);
    end

    % Actualizar x0 y el número de iteraciones
    x0 = x1;
    niter = niter + 1;
end

% Imprimir resultado final
if error <= tol
    fprintf('\nSe realizaron %d iteraciones.\n', niter);
    fprintf('La raíz aproximada de la función f(x) = cos(x) - 2x + 3 es %.6f con un error de %.6e\n', x0, tol);
else
    disp('El método no convergió en el número máximo de iteraciones.');
end
