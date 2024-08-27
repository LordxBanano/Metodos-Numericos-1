def f(x):
    return x**2 - 4

def df(x):
    return 2 * x

def newton_raphson(x0, tol):
    x = x0
    while abs(f(x)) > tol:
        x = x - f(x) / df(x)
    return x

# Parámetros de entrada
x0 = 3  # Valor inicial
tolerancia = 0.0001  # Tolerancia para la precisión

# Encontrar la raíz
raiz = newton_raphson(x0, tolerancia)
print(f"La raíz de la función es aproximadamente: {raiz:.4f}")
