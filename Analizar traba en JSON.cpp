#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BUFFER 200

// Función para validar (int o float)
int esNumeroValido(char *str) {
    int punto = 0;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (punto) return 0;
            punto = 1;
        }
        else if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {

    char buffer[MAX_BUFFER];

    while (fgets(buffer, sizeof(buffer), stdin)) {

        char ID[50] = "";
        char temp_str[30] = "";
        char hum_str[30] = "";
        char dist_str[30] = "";

        char *ptr;

        // ID
        ptr = strstr(buffer, "\"ID\"");
        if (ptr) {
            ptr = strchr(ptr, ':');
            if (ptr) {
                ptr++;
                while (*ptr == ' ') ptr++;
                if (*ptr == '\"') {
                    ptr++;
                    int i = 0;
                    while (*ptr != '\"' && *ptr != '\0') {
                        ID[i++] = *ptr++;
                    }
                    ID[i] = '\0';
                } else {
                    continue; //ignorar todo
                }
            }
        }

        // temperatura
        ptr = strstr(buffer, "\"Temperatura\"");
        if (ptr) {
            ptr = strchr(ptr, ':');
            if (ptr) {
                ptr++;
                while (*ptr == ' ') ptr++;
                sscanf(ptr, "%[^,}]", temp_str);
                if (!esNumeroValido(temp_str))
                    continue;
            }
        }

        // Humedad
        ptr = strstr(buffer, "\"Humedad\"");
        if (ptr) {
            ptr = strchr(ptr, ':');
            if (ptr) {
                ptr++;
                while (*ptr == ' ') ptr++;
                sscanf(ptr, "%[^,}]", hum_str);
                if (!esNumeroValido(hum_str))
                    continue;
            }
        }

        // Distancia
        ptr = strstr(buffer, "\"Distancia\"");
        if (ptr) {
            ptr = strchr(ptr, ':');
            if (ptr) {
                ptr++;
                while (*ptr == ' ') ptr++;
                sscanf(ptr, "%[^,}]", dist_str);
                if (!esNumeroValido(dist_str))
                    continue;
            }
        }

        // Claves obligatorias
        if (strlen(ID) == 0) {
            printf("Falta clave ID\n");
            continue;
        }

        if (strlen(temp_str) == 0) {
            printf("Falta clave Temperatura\n");
            continue;
        }

        if (strlen(hum_str) == 0) {
            printf("Falta clave Humedad\n");
            continue;
        }

        if (strlen(dist_str) == 0) {
            printf("Falta clave Distancia\n");
            continue;
        }

        // Convertir valores
        float temperatura = atof(temp_str);
        float humedad = atof(hum_str);
        float distancia = atof(dist_str);

        // Imprimir resultados
        printf("ID: %s\n", ID);
        printf("Temperatura: %.2f\n", temperatura);
        printf("Humedad: %.2f\n", humedad);
        printf("Distancia: %.2f\n", distancia);
        printf("-------------------------\n");
    }

    return 0;
}
