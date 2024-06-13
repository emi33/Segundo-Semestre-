#include <stdio.h>
#include <math.h>

// Función para calcular el valor de Bus de Dirección
void calcular_bus_direccion() {
    // Declare variables
    double memoria_gb; // Memory in GB
    int bus_datos_bits; // Bus de Datos in bits
    double num_direcciones; // Number of memory addresses
    double bus_direccion_cables; // Bus de Dirección in cables

    // Print program purpose
    printf("\nEste programa es para sacar el valor de Bus de Dirección.\n");

    // Get user input
    printf("Ingrese el valor de la memoria en GB: ");
    scanf("%lf", &memoria_gb);
    printf("Ingrese el valor del Bus de Datos en bits: ");
    scanf("%d", &bus_datos_bits);

    // Convert memory from GB to bytes
    double memoria_bytes = memoria_gb * 1024 * 1024 * 1024;

    // Calculate the number of addresses
    num_direcciones = memoria_bytes / (bus_datos_bits / 8);

    // Calculate Bus de Dirección in cables
    bus_direccion_cables = log2(num_direcciones);

    // Print the result
    printf("El valor de Bus de Dirección es: %.0f bits\n", bus_direccion_cables);
}

// Función para calcular cuántos cables tiene el Bus de Datos y el Bus de Dirección
void calcular_cables() {
    // Declare variables
    int bus_datos_bits; // Bus de Datos in bits
    int bus_direccion_bits; // Bus de Dirección in bits
    int bus_datos_cables; // Bus de Datos in cables
    int bus_direccion_cables; // Bus de Dirección in cables

    // Print program purpose
    printf("\nEste programa es para calcular cuántos cables tiene el Bus de Datos y el Bus de Dirección.\n");

    // Get user input for Bus de Datos
    printf("Ingrese el valor del Bus de Datos en bits: ");
    scanf("%d", &bus_datos_bits);

    // Get user input for Bus de Dirección
    printf("Ingrese el valor del Bus de Dirección en bits: ");
    scanf("%d", &bus_direccion_bits);

    // Calculate the number of cables for Bus de Datos
    bus_datos_cables = bus_datos_bits; // Since 1 bit = 1 cable

    // Calculate the number of cables for Bus de Dirección
    bus_direccion_cables = bus_direccion_bits; // Same logic: 1 bit = 1 cable

    // Print the result
    printf("El Bus de Datos tiene: %d cables\n", bus_datos_cables);
    printf("El Bus de Dirección tiene: %d cables\n", bus_direccion_cables);
}

// Función para calcular el tamaño de la celda de memoria
void calcular_tamano_celda() {
    int bus_direccion, bus_datos;
    long double cantidad_celdas, tamano_celda_bytes, tamano_celda_kb;

    // Solicitar al usuario que ingrese los valores del Bus de dirección y del Bus de Datos
    printf("\nEste programa calcula el tamaño de la celda de memoria.\n");
    printf("Ingrese el valor del Bus de dirección en bits: ");
    scanf("%d", &bus_direccion);
    printf("Ingrese el valor del Bus de Datos en bits: ");
    scanf("%d", &bus_datos);

    // Calcular la cantidad de celdas y el tamaño de la celda
    cantidad_celdas = pow(2, bus_direccion);
    tamano_celda_bytes = pow(2, cantidad_celdas) * (bus_datos / 8.0);
    tamano_celda_kb = tamano_celda_bytes / 1024.0;

    // Mostrar los resultados
    printf("Cantidad de celdas: %.0f\n", cantidad_celdas);
    printf("Tamaño de la celda: %.2f bytes\n", tamano_celda_bytes);
    printf("Tamaño de la celda: %.2f KB\n", tamano_celda_kb);
}

// Función para calcular la cantidad de celdas
void calcular_cantidad_celdas() {
    int bus_direccion;
    double cantidad_celdas;

    // Print program purpose
    printf("\nEste programa es para calcular la cantidad de celdas.\n");

    // Get user input for Bus de Dirección
    printf("Ingrese el valor del Bus de Dirección en bits: ");
    scanf("%d", &bus_direccion);

    // Calculate the number of cells
    cantidad_celdas = pow(2, bus_direccion);

    // Print the result
    printf("La cantidad de celdas es: %.0f\n", cantidad_celdas);
}

int main() {
    int opcion;

    do {
        // Mostrar el menú
        printf("\nSeleccione una opción:\n");
        printf("1. Calcular valor de Bus de Dirección\n");
        printf("2. Calcular número de cables\n");
        printf("3. Calcular tamaño de celda de memoria\n");
        printf("4. Calcular cantidad de celdas\n");
        printf("5. Salir\n");

        // Leer la opción del usuario
        scanf("%d", &opcion);

        // Ejecutar la opción seleccionada
        switch (opcion) {
            case 1:
                calcular_bus_direccion();
                break;
            case 2:
                calcular_cables();
                break;
            case 3:
                calcular_tamano_celda();
                break;
            case 4:
                calcular_cantidad_celdas();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}