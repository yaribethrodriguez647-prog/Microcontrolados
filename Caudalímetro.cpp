#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char buffer[100];
    
    int ultimo = 0;
    int mayor = -1;
    int menor = 100;
    int suma = 0;
    int contador = 0;
    
    int valor;
    
    while(1) {
        // Simula recepción por serial
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        // Verificar formato {'caudal': VALOR}
        if(sscanf(buffer, "{'caudal': %d}", &valor) == 1) {
            
            // Verificar rango
            if(valor >= 0 && valor <= 99) {
                
                ultimo = valor;
                
                if(valor > mayor) {
                    mayor = valor;
                }
                
                if(valor < menor) {
                    menor = valor;
                }
                
                suma += valor;
                contador++;
                
                float promedio = (float)suma / contador;
                
                printf("{'ultimo': %d, 'mayor': %d, 'menor': %d, 'promedio': %.2f}",
                       ultimo, mayor, menor, promedio);
            }
        }
    
    }
    
    return 0;
}
