
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// 1. Suma de dos numeros
int suma(int a, int b) {
    return a + b;
}

// 2. Factorial de un numero
int factorial(int n) {
    if (n < 0) return -1; // Manejo de error para numeros negativos
    return (n == 0) ? 1 : n * factorial(n - 1);
}

// 3. area de un circulo
double area_circulo(double radio) {
    return M_PI * radio * radio;
}

// 4. Comprobacion de numero primo
bool es_primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 5. Ordenar un arreglo
void ordenar_arreglo(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 6. Busqueda binaria
int busqueda_binaria(int arr[], int n, int clave) {
    int izquierda = 0, derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == clave) return medio;
        if (arr[medio] < clave) izquierda = medio + 1;
        else derecha = medio - 1;
    }
    return -1;
}

// 7. Matriz transpuesta
void matriz_transpuesta(int matriz[][3], int filas, int columnas, int transpuesta[][3]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

// 8. Juego de adivinanza
void jugar_adivinanza() {
    srand(time(0));
    int numero_secreto = rand() % 100 + 1;
    int intento, intentos = 0;
    printf("Adivina el nÃºmero entre 1 y 100\n");
    do {
        printf("Ingresa tu intento: ");
        scanf("%d", &intento);
        intentos++;
        if (intento > numero_secreto) {
            printf("Demasiado alto\n");
        } else if (intento < numero_secreto) {
            printf("Demasiado bajo\n");
        } else {
            printf("¡Felicidades! Adivinaste el numero en %d intentos\n", intentos);
        }
    } while (intento != numero_secreto);
}

int main() {
    int opcion;
    do {
        printf("\nMenu de opciones:\n");
        printf("1. Suma de dos numeros\n");
        printf("2. Factorial de un numero\n");
        printf("3. area de un circulo\n");
        printf("4. Numeros primos hasta N\n");
        printf("5. Ordenar un arreglo\n");
        printf("6. Busqueda binaria\n");
        printf("7. Matriz transpuesta\n");
        printf("8. Juego de adivinanza\n");
        printf("9. Salir\n");
        printf("Seleccione una opciÃ³n: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                int num1, num2;
                printf("Ingrese dos numeros: ");
                scanf("%d %d", &num1, &num2);
                printf("La suma es: %d\n", suma(num1, num2));
                break;
            }
            case 2: {
                int num;
                printf("Ingrese un numero entero: ");
                scanf("%d", &num);
                int resultado = factorial(num);
                if (resultado == -1) printf("No se puede calcular el factorial de un nÃºmero negativo.\n");
                else printf("El factorial de %d es: %d\n", num, resultado);
                break;
            }
            case 3: {
                double radio;
                printf("Ingrese el radio del circulo: ");
                scanf("%lf", &radio);
                printf("El area del circulo es: %.2lf\n", area_circulo(radio));
                break;
            }
            case 4: {
                int limite;
                printf("Ingrese el limite superior: ");
                scanf("%d", &limite);
                printf("Numeros primos hasta %d:\n", limite);
                for (int i = 2; i <= limite; i++) {
                    if (es_primo(i)) printf("%d ", i);
                }
                printf("\n");
                break;
            }
            case 5: {
                int arr[] = {5, 2, 8, 1, 9};
                int n = sizeof(arr) / sizeof(arr[0]);
                ordenar_arreglo(arr, n);
                printf("Arreglo ordenado: ");
                for (int i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 6: {
                int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                int clave;
                printf("Ingrese el numero a buscar: ");
                scanf("%d", &clave);
                int indice = busqueda_binaria(arr, 9, clave);
                if (indice != -1) printf("Elemento encontrado en el indice: %d\n", indice);
                else printf("Elemento no encontrado\n");
                break;
            }
            case 7: {
                int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, transpuesta[3][3];
                matriz_transpuesta(matriz, 3, 3, transpuesta);
                printf("Matriz transpuesta:\n");
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) printf("%d ", transpuesta[i][j]);
                    printf("\n");
                }
                break;
            }
            case 8: jugar_adivinanza(); break;
        }
    } while (opcion != 9);
    return 0;
}
