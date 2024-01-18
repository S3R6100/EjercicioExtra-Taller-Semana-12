#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_NOMBRE 50

void leerCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int *numClientes) {
    int numeroClientesALeer;

    printf("Cuantos clientes desea leer?\n");
    scanf(" %d", &numeroClientesALeer);

    for (int i = 0; i < numeroClientesALeer && *numClientes < MAX_CLIENTES; i++) {
        printf("\nIngrese el nombre del cliente %d:\n", *numClientes + 1);
        scanf(" %s", nombres[*numClientes]);

        printf("Ingrese la cédula del cliente %d:\n", *numClientes + 1);
        scanf(" %ld", &cedulas[*numClientes]);

        printf("Ingrese la edad del cliente %d:\n", *numClientes + 1);
        scanf(" %d", &edades[*numClientes]);

        (*numClientes)++;
    }

    if (*numClientes >= MAX_CLIENTES) {
        printf("La lista de clientes está llena. No se pueden agregar más clientes.\n");
    }
}

void mandarCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int numClientes) {
    FILE *archivo = fopen("baseDatosClientes.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        fprintf(archivo, "%d\t", i + 1);
        fprintf(archivo, "%s\t", nombres[i]);
        fprintf(archivo, "%ld\t", cedulas[i]);
        fprintf(archivo, "%d\t", edades[i]);
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

void mostrarClientes() {
    FILE *archivo = fopen("baseDatosClientes.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    printf("\n*** Lista de clientes ***\n");

    char linea[MAX_NOMBRE + 2 + 1 + sizeof(long) + 1 + 2 + 1];  

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        char nombre[MAX_NOMBRE];
        long cedula;
        int edad;

        if (sscanf(linea, "%*d %s %ld %d", nombre, &cedula, &edad) == 3) {
            printf("%s - Cédula: %ld - Edad: %d\n", nombre, cedula, edad);
        }
    }

    fclose(archivo);
}

int buscarCliente(const char nombreBuscar[MAX_NOMBRE], char nombres[MAX_CLIENTES][MAX_NOMBRE], int numClientes) {
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            return i;
        }
    }
    return -1;
}

void eliminarCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int *numClientes) {
    printf("\n*** Eliminar cliente ***\n");

    mostrarClientes();

    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del cliente que desea eliminar: ");
    scanf("%49s", nombreBuscar);

    int indiceCliente = buscarCliente(nombreBuscar, nombres, *numClientes);

    if (indiceCliente != -1) {
        for (int i = indiceCliente; i < *numClientes - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            cedulas[i] = cedulas[i + 1];
            edades[i] = edades[i + 1];
        }

        (*numClientes)--;  

        printf("Cliente \"%s\" eliminado con éxito.\n", nombreBuscar);

        FILE *archivo = fopen("baseDatosClientes.txt", "w");
        if (archivo == NULL) {
            printf("Error al abrir el archivo para escritura.\n");
            return;
        }

        for (int j = 0; j < *numClientes; j++) {
            fprintf(archivo, "%d\t", j + 1);
            fprintf(archivo, "%s\t", nombres[j]);
            fprintf(archivo, "%ld\t", cedulas[j]);
            fprintf(archivo, "%d\t", edades[j]);
            fprintf(archivo, "\n");
        }
        fclose(archivo);
    } else {
        printf("Cliente \"%s\" no encontrado.\n", nombreBuscar);
    }
}

void mostrarMenu() {
    printf("\n*** Buffet De Abogados Suarez Vaca ***\n");
    printf("1. Agregar cliente\n");
    printf("2. Mostrar clientes\n");
    printf("3. Editar cliente\n");
    printf("4. Eliminar cliente\n");
    printf("5. Salir\n");
}

void editarCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int numClientes) {
    printf("\n*** Editar cliente ***\n");

    mostrarClientes();

    char nombreBuscar[MAX_NOMBRE];
    printf("Ingrese el nombre del cliente que desea editar: ");
    scanf("%s", nombreBuscar);

    int indiceCliente = buscarCliente(nombreBuscar, nombres, numClientes);

    if (indiceCliente != -1) {
        printf("Ingrese el nuevo nombre del cliente: ");
        scanf("%s", nombres[indiceCliente]);
        printf("Ingrese la nueva cédula del cliente: ");
        scanf("%ld", &cedulas[indiceCliente]);
        printf("Ingrese la nueva edad del cliente: ");
        scanf("%d", &edades[indiceCliente]);

        printf("Cliente \"%s\" editado con éxito.\n", nombreBuscar);

        FILE *archivo = fopen("baseDatosClientes.txt", "w");
        if (archivo == NULL) {
            printf("Error al abrir el archivo para escritura.\n");
            return;
        }

        for (int j = 0; j < numClientes; j++) {
            fprintf(archivo, "%d\t", j + 1);
            fprintf(archivo, "%s\t", nombres[j]);
            fprintf(archivo, "%ld\t", cedulas[j]);
            fprintf(archivo, "%d\t", edades[j]);
            fprintf(archivo, "\n");
        }
        fclose(archivo);
    } else {
        printf("Cliente \"%s\" no encontrado.\n", nombreBuscar);
    }
}