% Código creado por Joshua Mijangos López, 02/10/24
% Este código está hecho para que las funciones del método se modifiquen desde aquí
% Este código no acepta de datos de ingreso desde consola

% Definimos la variable simbólica y la función f(x)
syms x;
f_sym = x^3 - x - 1;  % f(x) = x^3 - x - 1
df_sym = diff(f_sym, x);  % Derivada f'(x)

% Convertimos a funciones anónimas para evaluación numérica
f = matlabFunction(f_sym);
df = matlabFunction(df_sym);

% Imprimir las funciones en pantalla
fprintf('Sean las funciones: \n\n');
disp(['f(x) = ', char(f_sym)]);
disp(['f''(x) = ', char(df_sym)]); % Usamos char para convertir la expresión simbólica a texto

fprintf('\n\n')

% Parámetros de entrada
x0 = 1;  % Aproximación inicial
tol = 1e-5;  % Tolerancia
nmax = 100;  % Número máximo de iteraciones
error = 100;
niter = 0;

fprintf('# de Iteración\t\tx_n\t\tf(x_n)\t\tError\n');

% Método de Newton
while error > tol && niter < nmax
    fx0 = f(x0);
    dfx0 = df(x0);
    
    if dfx0 == 0
        disp('La derivada es cero, no se puede aplicar el método de Newton.');
        break;
    end
    
    x1 = x0 - fx0 / dfx0;  % Fórmula del método de Newton
    
    if niter == 0
        fprintf('%d\t\t%.6f\t\t%.6f\t\tN/A\n', niter+1, x0, fx0);
    else
        error = abs(x1 - x0);  % Cálculo del error
        fprintf('%d\t\t%.6f\t\t%.6f\t\t%.6f\n', niter+1, x0, fx0, error);
    end
    
    x0 = x1;
    niter = niter + 1;
end

% Resultado final
if error <= tol
    fprintf('\nSe realizaron %d iteraciones.\n', niter);
    fprintf('La raíz aproximada de la función f(x) es %.6f con un error de %.5f\n', x0, tol);
    % El segundo parámetro %.zf debe de modificarse si lo que se busca es disminuir el error, lo dejé preestablecido para z=5 (Es decir, un error de 10^-5)
else
    disp('El método no convergió en el número máximo de iteraciones.');
end
