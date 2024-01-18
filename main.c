#include <stdio.h>
#include "funciones.h"

#define MAX_CLIENTES 100
#define MAX_NOMBRE 50

int main() {
    int opcion = 0;
    char nombres[MAX_CLIENTES][MAX_NOMBRE];
    long cedulas[MAX_CLIENTES];
    int edades[MAX_CLIENTES];
    int numClientes = 0;

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                leerCliente(nombres, cedulas, edades, &numClientes);
                mandarCliente(nombres, cedulas, edades, numClientes);
                break;

            case 2:
                mostrarClientes();
                break;

            case 3:
                editarCliente(nombres, cedulas, edades, numClientes);
                break;

            case 4:
                eliminarCliente(nombres, cedulas, edades, &numClientes);
                break;

            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida\n");
        }

    } while (opcion != 5);

    return 0;
}
