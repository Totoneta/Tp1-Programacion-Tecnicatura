#include <stdio.h>
#include <string.h>
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
int listadoAlumnos(char alumnos[][6][30], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s | %s | %s | %s | %s \n", alumnos[i][0], alumnos[i][1], alumnos[i][2], alumnos[i][3], alumnos[i][4]);
    }
}
// ----------------------------- Main -----------------------------

int main()
{
    // VARIABLES Y ARRAYS
    int cantidadDeAlumnos = 0;
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
    // Almacenamiento de alumnos
    char alumnos[100][6][30];
    // Talleres
    char disciplinas[4][4][15] = {
        {"PNT", "Pintura", "25000", "0"},
        {"ESC", "Escultura", "14000", "0"},
        {"THR", "Teatro", "19000", "0"},
        {"FOT", "Fotografía", "23000", "0"},
    };

    do
    {
        // Menú y validación
        opcionvalidada = menuGeneral();
        while (opcionvalidada < 1 || opcionvalidada > 7)
        {
            printf("Opción inválida. Intente nuevamente.\n\n");
            opcionvalidada = menuGeneral();
        }

        if (opcionvalidada == 1)
        {
            // Cantidad de alumnos y validación
            printf("Cantidad de alumnos que quiere inscribir: ");
            scanf("%i", &cantidadDeAlumnos);
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
                scanf("%s", alumnos[i][0]);
                // Pasarlo a int
                dninumerico = strtol(alumnos[i][0], NULL, 10);
                // Contador del dni
                cantidadnumerosendni = strlen(alumnos[i][0]);

                // Validación del DNI
                while (cantidadnumerosendni < 6 || cantidadnumerosendni > 9 || dninumerico < 10000000 || dninumerico > 60000000)
                {
                    printf("El dni es inválido, recuerda que debe ser mayor a 10 millones y menor que 60 millones.\n");
                    scanf("%s", alumnos[i][0]);
                    // Pasarlo a int
                    dninumerico = strtol(alumnos[i][0], NULL, 10);
                    // Contador del dni
                    cantidadnumerosendni = strlen(alumnos[i][0]);
                }

                // NOMBRE APELLIDO Y EDAD
                printf("Apellido: ");
                scanf("%s", alumnos[i][1]);
                printf("Nombre: ");
                scanf("%s", alumnos[i][2]);
                printf("Edad: ");
                scanf("%s", alumnos[i][3]);
                edadnumerico = strtol(alumnos[i][3], NULL, 10);

                // CÓDIGO DE TALLER
                printf("Código del taller: ");
                printf("Recuerda que los códigos són(en mayúsculas): \n ");
                printf("PNT para Pintura. \n ");
                printf("ESC para Escultura. \n ");
                printf("THR para Teatro. \n ");
                printf("FOT para Fotografía. \n ");
                scanf("%s", alumnos[i][4]);

                // MEDIO DE PAGO
                printf("Medio de pago: ");
                printf("1 - Efectivo");
                printf("2 - Crédito");
                scanf("%s", alumnos[i][5]);
            }
        }
        else if (opcionvalidada == 2)
        {
            listadoAlumnos(alumnos, cantidadDeAlumnos);

            break;
        }
    } while (opcionvalidada != 7);
    return 0;
}