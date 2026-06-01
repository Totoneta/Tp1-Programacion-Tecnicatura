#include <stdio.h>
#include <stdlib.h>

// ----------------------------- Funciones -----------------------------

// Menú General
int menuGeneral()
{
    int opcion;
    printf("¡Bienvenido al sistema de inscripción de ArteTotal!\n");
    printf("Seleccione el número de las opciones a seleccionar: \n");
    printf("1 - Agregar alumnos\n");
    printf("2 - Listado general de alumnos\n");
    printf("3 - Listado por taller\n");
    printf("4 - Estado de talleres\n");
    printf("5 - Buscador de alumnos\n");
    printf("6 - Estadiscticas de gestion\n");
    printf("7 - Cerrar sistema.\n\n");
    scanf("%d", &opcion);
    return opcion;
}

// Listado Alumnos
int listadoAlumnos(int alumnos[5][30], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s | %s | %s | %s | %s \n", alumnos[i][0], alumnos[i][0], alumnos[i][0], alumnos[i][0], alumnos[i][0]);
    }
}
// ----------------------------- Main -----------------------------

int main()
{
    // VARIABLES Y ARRAYS
    int cantidadDeAlumnos;
    int opcionvalidada;
    // Tipo int datos alumno
    int cantidadnumerosendni;
    int dninumerico;
    int edadnumerico;
    // Tipo int precio y cantidad de alumnos inscriptos de talleres
    int preciopintura;
    int precioescultura;
    int precioteatro;
    int preciofotografia;
    int cantidadocupadapintura;
    int cantidadocupadaescultura;
    int cantidadocupadateatro;
    int cantidadocupadafotografia;
    // Arrays
    char alumno[5][30];
    char disciplinas[4][4][15] = {
        {"PNT", "Pintura", "25000", "0"},
        {"ESC", "Escultura", "14000", "0"},
        {"THR", "Teatro", "19000", "0"},
        {"FOT", "Fotografía", "23000", "0"},
    };

    // Menú y validación
    opcionvalidada = menuGeneral();
    while (opcionvalidada < 1 || opcionvalidada > 7)
    {
        printf("Opción inválida. Intente nuevamente.\n\n");
        opcionvalidada = menuGeneral();
    }

    switch (opcionvalidada)
    {
    case 1:
        // Cantidad de alumnos y validación
        printf("Cantidad de alumnos que quiere inscribir: ");
        scanf("%d", &cantidadDeAlumnos);

        // Almacenamiento de alumnos
        char alumnos[cantidadDeAlumnos][5][30];

        while (cantidadDeAlumnos < 1)
        {
            printf("Dato inváido. Ingrese que cantidad de alumnos desea inscribir: ");
            scanf("%d", &cantidadDeAlumnos);
        }

        // Pedir datos del alumno, validarlos y almacenarlos
        for (int i = 0; i < cantidadDeAlumnos; i++)
        {
            printf("Ingrese los datos del alumno n° %d \n", i + 1);

            // DNI
            printf("Dni: ");
            scanf("%s", &alumno[0][0]);
            // Pasarlo a int
            dninumerico = strtol(&alumno[0][0], NULL, 10);
            // Contador del dni
            cantidadnumerosendni = strlen(&alumno[0][0]);

            // Validación del DNI
            while (cantidadnumerosendni < 6 || cantidadnumerosendni > 9 || dninumerico < 10000000 || dninumerico > 60000000)
            {
                printf("El dni es inválido, recuerda que debe ser mayor a 10 millones y menor que 60 millones.\n");
                scanf("%s", &alumno[0][0]);
                // Pasarlo a int
                dninumerico = strtol(&alumno[0][0], NULL, 10);
                // Contador del dni
                cantidadnumerosendni = strlen(&alumno[0][0]);
            }

            // NOMBRE APELLIDO Y EDAD
            printf("Apellido: ");
            scanf("%s", &alumno[1][0]);
            printf("Nombre: ");
            scanf("%s", &alumno[2][0]);
            printf("Edad: ");
            scanf("%s", &alumno[3][0]);
            edadnumerico = strtol(&alumno[3][0], NULL, 10);

            // CÓDIGO DE TALLER
            printf("Código del taller: ");
            printf("Recuerda que los códigos són(en mayúsculas): \n ");
            printf("PNT para Pintura. \n ");
            printf("ESC para Escultura. \n ");
            printf("THR para Teatro. \n ");
            printf("FOT para Fotografía. \n ");
            scanf("%s", &alumno[4][0]);

            // MEDIO DE PAGO
            printf("Medio de pago: ");
            printf("1 - Efectivo");
            printf("2 - Crédito");
            scanf("%s", &alumno[5][0]);

            break;
        }

    case 2:
        listadoAlumnos(&alumno, cantidadDeAlumnos);

        break;
    }

    return 0;
}