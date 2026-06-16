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
void listadoAlumnos(char alumnos[][7][30], int cantidad, int alumnosCargados)
{
    if (alumnosCargados != 0)
    {
        printf("######################\n");
        printf("# LISTADO DE ALUMNOS #\n");
        printf("######################\n");
        for (int i = 0; i < cantidad; i++)
        {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("%s | %s | %s | %s | %s | %s \n", alumnos[i][0], alumnos[i][1], alumnos[i][2], alumnos[i][3], alumnos[i][4], alumnos[i][6]);
        }
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
    }
    else
    {
        printf("################################\n");
        printf("# No hay alumnos cargados aún. # \n");
        printf("################################\n\n");
    }
}
// ----------------------------- Main -----------------------------

int main()
{
    // VARIABLES Y ARRAYS
    // Alumnos ya agregados para no sobreescribirlos
    int alumnosCargados = 0;
    // Agregar alumnos variable
    int cantidadDeAlumnos = 0;
    // Opción de menu
    int opcionvalidada;
    // Transformación de tipo int datos alumnos
    int cantidadnumerosendni;
    int dninumerico;
    int edadnumerico;
    int mediodepagonuemrico;
    int adeudadonumerico = 0;
    char adeudadonumchar[30];
    // Almacenamiento de alumnos
    char alumnos[100][7][30];
    // Talleres
    char disciplinas[4][2][15] = {
        {"PNT", "Pintura"},
        {"ESC", "Escultura"},
        {"THR", "Teatro"},
        {"FOT", "Fotografía"},
    };
    int disciplinasnumerico[4][2] = {
        {25000, 0},
        {14000, 0},
        {19000, 0},
        {23000, 0},
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
            while (cantidadDeAlumnos < 1 || alumnosCargados + cantidadDeAlumnos > 100)
            {
                printf("Dato inváido. Ingrese que cantidad de alumnos desea inscribir: ");
                scanf("%d", &cantidadDeAlumnos);
            }

            // Pedir datos del alumno, validarlos y almacenarlos
            for (int i = alumnosCargados; i < cantidadDeAlumnos + alumnosCargados; i++)
            {
                adeudadonumerico = 0;
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
                    printf("Dni: ");
                    scanf("%s", alumnos[i][0]);
                    // Pasarlo a int
                    dninumerico = strtol(alumnos[i][0], NULL, 10);
                    // Contador del dni
                    cantidadnumerosendni = strlen(alumnos[i][0]);
                }
                
                // Nombre y apellido
                printf("Apellido: ");
                scanf("%s", alumnos[i][1]);
                printf("Nombre: ");
                scanf("%s", alumnos[i][2]);

                // Edad y Validación
                printf("Edad: ");
                scanf("%s", alumnos[i][3]);
                edadnumerico = strtol(alumnos[i][3], NULL, 10);
                while (edadnumerico < 0 || edadnumerico > 100)
                {
                    printf("Edad incorrecta, intente nuevamente. \n ");
                    printf("Edad: ");
                    scanf("%s", alumnos[i][3]);
                    edadnumerico = strtol(alumnos[i][3], NULL, 10);
                }
                if (edadnumerico < 5)
                {
                    adeudadonumerico = adeudadonumerico + 2000;
                }
                

                // Código de taller y validación
                printf("Código del taller \n");
                printf("Recuerda que los códigos són(en mayúsculas): \n ");
                printf("PNT para Pintura. \n ");
                printf("ESC para Escultura. \n ");
                printf("THR para Teatro. \n ");
                printf("FOT para Fotografía. \n ");
                printf("Código del taller: ");
                scanf("%s", alumnos[i][4]);
                while (
                    strcmp(alumnos[i][4], "PNT") != 0 &&
                    strcmp(alumnos[i][4], "ESC") != 0 &&
                    strcmp(alumnos[i][4], "THR") != 0 &&
                    strcmp(alumnos[i][4], "FOT") != 0 )
                {
                    printf("Código no válido. Intente nuevamente. \n ");
                    printf("PNT para Pintura. \n ");
                    printf("ESC para Escultura. \n ");
                    printf("THR para Teatro. \n ");
                    printf("FOT para Fotografía. \n ");
                    printf("Código del taller: ");
                    scanf("%s", alumnos[i][4]);
                }
                
                if ( strcmp(alumnos[i][4], "PNT") == 0)
                {
                    /* code */
                }
                // validacion de cursos y precios
                
                if (strcmp(alumnos[i][4], "PNT") == 0)
                {
                    disciplinasnumerico[0][1] = disciplinasnumerico[0][1] + 1;
                    adeudadonumerico = adeudadonumerico + disciplinasnumerico[0][0];
                }
                else if (strcmp(alumnos[i][4], "ESC") == 0)
                {
                    disciplinasnumerico[1][1] = disciplinasnumerico[1][1] + 1;
                    adeudadonumerico = adeudadonumerico + disciplinasnumerico[1][0];
                }
                else if (strcmp(alumnos[i][4], "THR") == 0)
                {
                    disciplinasnumerico[2][1] = disciplinasnumerico[2][1] + 1;
                    adeudadonumerico = adeudadonumerico + disciplinasnumerico[2][0];
                }
                else if (strcmp(alumnos[i][4], "FOT") == 0)
                {
                    disciplinasnumerico[3][1] = disciplinasnumerico[3][1] + 1;
                    adeudadonumerico = adeudadonumerico + disciplinasnumerico[3][0];
                }
                // MEDIO DE PAGO
                printf("Medio de pago \n");
                printf("1 - Efectivo \n");
                printf("2 - Crédito \n");
                printf("Medio de pago: ");
                scanf("%s", alumnos[i][5]);
                mediodepagonuemrico = strtol(alumnos[i][5], NULL, 10);
                while (mediodepagonuemrico != 1 && mediodepagonuemrico != 2)
                {
                    printf("Medio de pago no válido. Intente nuevamente.\n");
                    printf("1 - Efectivo\n");
                    printf("2 - Crédito\n");
                    printf("Medio de pago: ");
                    scanf("%s", alumnos[i][5]);
                    mediodepagonuemrico = strtol(alumnos[i][5], NULL, 10);
                }
                if (mediodepagonuemrico == 2)
                {
                    adeudadonumerico = adeudadonumerico + (adeudadonumerico * 0.05);
                }
                sprintf(adeudadonumchar, "%d", adeudadonumerico);
                strcpy(alumnos[i][6], adeudadonumchar);
                
            }

            // Actualización de alumnos cargados
            alumnosCargados = alumnosCargados + cantidadDeAlumnos;
        }
        else if (opcionvalidada == 2)
        {
            listadoAlumnos(alumnos, alumnosCargados, alumnosCargados);
            // for (int i = 0; i < 4; i++)
            //  {
            //  printf("%i", disciplinasnumerico[i][1]);
            //  }
        }
    } while (opcionvalidada != 7);
    return 0;
}