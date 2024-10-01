% Código creado por Joshua Mijangos López, 29/09/24
% Este código está hecho para que las funciones del método y sus despejes se modifiquen desde aquí
% Este código no acepta de datos de ingreso desde consola

% Definimos la función f(x) y g(x) para el método del punto fijo
f = @(x) x^3 - x - 1;  % Esta es la ecuación f(x)

% g(x) = x es la reescritura de f(x) = 0 para obtener una función g(x) que nos permita aplicar el método del punto fijo
g = @(x) (x + 1)^(1/3);  % Esta es una posible forma de g(x) basada en la ecuación f(x)

% Ingreso datos de entrada
x0 = 1;  % Aproximación inicial
tol = 10^(-5);  % Tolerancia
nmax = 100;  % Número máximo de iteraciones
error = 100;
niter = 0;

% Imprimir encabezado
fprintf('# de Iteración\t\t    x_n \t\t  g(x_n) \t\t   Error\n');

% Método del Punto Fijo
while error > tol && niter < nmax
    x1 = g(x0);

    % En la primera iteración no se imprime el error
    if niter == 0
        fprintf('\t%d \t\t %6.6f \t\t %6.6f \t\t   N/A\n', niter+1, x0, x1);
    else
        error = abs(x1 - x0);
        fprintf('\t%d \t\t %6.6f \t\t %6.6f \t\t %6.6f\n', niter+1, x0, x1, error);
    end
    
    % Actualizar x0 para la siguiente iteración
    x0 = x1;
    niter = niter + 1;
end

% Imprimir resultado final
fprintf('\nSe realizaron %d iteraciones.\n', niter);
fprintf('La raíz aproximada de la función f(x) es %6.6f con un error de %6.5f\n', x1, tol);
% El segundo parámetro %.zf debe de modificarse si lo que se busca es disminuir el error, lo dejé preestablecido para z=5 (Es decir, un error de 10^-5)
