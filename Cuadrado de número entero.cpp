#include <stdio.h>

int main() {
    int N;

    printf("Ingrese un numero: ");
    
    // Validamos que la entrada sea correcta y positiva
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Error Debe ser un numero mayor que 0");
        return 0;
    }

    int suma = 0;
    int impar = 1; 

    // se sumam los primeros N numeros impares para obtener N^2
    for (int i = 0; i < N; i++) {
        suma += impar;
        impar += 2;
    }

    printf("El cuadrado de %d es: %d", N, suma);

    return 0;
}

