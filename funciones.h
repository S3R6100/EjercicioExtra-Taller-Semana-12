#define MAX_NOMBRE 50
#define MAX_CLIENTES 100

void leerCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int *numClientes);
void mostrarClientes();
void mostrarMenu();
 int buscarCliente(const char nombreBuscar[MAX_NOMBRE], char nombres[MAX_CLIENTES][MAX_NOMBRE], int numClientes);
void editarCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int numClientes);
void eliminarCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int *numClientes);
void mandarCliente(char nombres[MAX_CLIENTES][MAX_NOMBRE], long cedulas[MAX_CLIENTES], int edades[MAX_CLIENTES], int numClientes);
