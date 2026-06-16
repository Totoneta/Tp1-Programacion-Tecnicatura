#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ----------------------------- Validaciones -----------------------------
// Validar DNI
int validarDNI(char dni[])
{
    int numero = atoi(dni);
    int longitud = strlen(dni);

    for (int i = 0; i < longitud; i++)
    {
        if (dni[i] < '0' || dni[i] > '9')
        {
            return 0;
        }
    }
    if (longitud != 7 && longitud != 8)
    {
        return 0;
    }
    if ((dni[0] == '5' || dni[0] == '6') || (numero >= 10000000 && numero <= 60000000))
    {
        return 1;
    }
    return 0;
}

// Pedir taller y validación
void talleres(char alumnos[])
{
    printf("Código del taller \n");
    printf("Recuerda que los códigos són(en mayúsculas): \n ");
    printf("PNT para Pintura. \n ");
    printf("ESC para Escultura. \n ");
    printf("THR para Teatro. \n ");
    printf("FOT para Fotografía. \n ");
    printf("Código del taller: ");
    scanf("%s", alumnos);
    while (
        strcmp(alumnos, "PNT") != 0 &&
        strcmp(alumnos, "ESC") != 0 &&
        strcmp(alumnos, "THR") != 0 &&
        strcmp(alumnos, "FOT") != 0)
    {
        printf("Código no válido. Intente nuevamente. \n ");
        printf("PNT para Pintura. \n ");
        printf("ESC para Escultura. \n ");
        printf("THR para Teatro. \n ");
        printf("FOT para Fotografía. \n ");
        printf("Código del taller: ");
        scanf("%s", alumnos);
    }
}

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
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

// Listado Alumnos
void listadoAlumnos(char alumnos[][7][30], int alumnosCargados)
{
    if (alumnosCargados != 0)
    {
        printf("######################\n");
        printf("# LISTADO DE ALUMNOS #\n");
        printf("######################\n");
        for (int i = 0; i < alumnosCargados; i++)
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

// Búsqueda de alumnmos individualmente
void buscarAlumno(char alumnos[][7][30], int n)
{
    char clave[30];
    int i = 0;
    int bandera = 0;
    printf("Ingrese el DNI del alumno que desea buscar: \n");
    scanf("%s", clave);

    while (!validarDNI(clave))
    {
        printf("DNI invalido. Intente nuevamente: ");
        scanf("%s", clave);
    }
    while (i < n && bandera == 0)
    {
        if (strcmp(alumnos[i][0], clave) == 0)
        {
            bandera = 1;
        }
        else
        {
            i++;
        }
    }
    if (bandera == 1)
    {
        printf("Alumno encontrado:\n");
        printf("DNI: %s\n", alumnos[i][0]);
        printf("Apellido: %s\n", alumnos[i][1]);
        printf("Nombre: %s\n", alumnos[i][2]);
        printf("Edad: %s\n", alumnos[i][3]);
        printf("Taller: %s\n", alumnos[i][4]);
        printf("Importe final: $%s\n", alumnos[i][6]);
    }
    else
    {
        printf("No existe un alumno con el dni %s. \n", clave);
    }
}

// Filtrado por Taller
void filtradoPorTaller(char alumnos[][7][30], int alumnosCargados)
{
    printf("############# Taller de PINTURA #############\n");
    for (int i = 0; i < alumnosCargados; i++)
    {
        if (strcmp(alumnos[i][4], "PNT") == 0)
        {
            printf("%s | %s | %s | %s | %s\n",
                   alumnos[i][4],
                   alumnos[i][1],
                   alumnos[i][2],
                   alumnos[i][0],
                   alumnos[i][3]);
        }
    }
    printf("############# Taller de ESCULTURA #############\n");
    for (int i = 0; i < alumnosCargados; i++)
    {
        if (strcmp(alumnos[i][4], "ESC") == 0)
        {
            printf("%s | %s | %s | %s | %s\n",
                   alumnos[i][4],
                   alumnos[i][1],
                   alumnos[i][2],
                   alumnos[i][0],
                   alumnos[i][3]);
        }
    }
    printf("############# Taller de TEATRO #############\n");
    for (int i = 0; i < alumnosCargados; i++)
    {
        if (strcmp(alumnos[i][4], "THR") == 0)
        {
            printf("%s | %s | %s | %s | %s\n",
                   alumnos[i][4],
                   alumnos[i][1],
                   alumnos[i][2],
                   alumnos[i][0],
                   alumnos[i][3]);
        }
    }
    printf("############# Taller de FOTOGRAFÍA #############\n");
    for (int i = 0; i < alumnosCargados; i++)
    {
        if (strcmp(alumnos[i][4], "FOT") == 0)
        {
            printf("%s | %s | %s | %s | %s\n",
                   alumnos[i][4],
                   alumnos[i][1],
                   alumnos[i][2],
                   alumnos[i][0],
                   alumnos[i][3]);
        }
    }
}

// Estado de los talleres
void estadoTalleres(char alumnos[][7][30], int alumnosCargados, char disciplinas[][2][15], int disciplinasnumerico[][2])
{
    int totalGeneral = 0;
    int recaudado;

    printf("#############################\n");
    printf("# ESTADO DE LOS TALLERES    #\n");
    printf("#############################\n");

    for (int i = 0; i < 4; i++)
    {
        recaudado = 0;

        for (int j = 0; j < alumnosCargados; j++)
        {
            if (strcmp(alumnos[j][4], disciplinas[i][0]) == 0)
            {
                recaudado += atoi(alumnos[j][6]);
            }
        }
        totalGeneral += recaudado;
        printf("\n");
        printf("Codigo: %s\n", disciplinas[i][0]);
        printf("Taller: %s\n", disciplinas[i][1]);
        printf("Inscriptos: %d\n", disciplinasnumerico[i][1]);
        printf("Recaudado: $%d\n", recaudado);
    }
    printf("\nTOTAL GENERADO: $%d\n", totalGeneral);
}

// Estadisticas de Gestión de Talleres
void estadisticasGestion(char alumnos[][7][30], int alumnosCargados, char disciplinas[][2][15], int disciplinasnumerico[][2])
{
    int menoresPNT = 0;
    int menoresESC = 0;
    int menoresTHR = 0;
    int menoresFOT = 0;
    int mayor = 0;
    int posicionMayor = 0;
    float porcentaje;

    if (alumnosCargados == 0)
    {
        printf("No hay alumnos cargados.\n");
        return;
    }

    printf("################################\n");
    printf("##  ESTADISTICAS DE GESTION  ##\n");
    printf("################################\n\n");
    printf("Porcentaje de alumnos por taller:\n");

    for (int i = 0; i < 4; i++)
    {
        porcentaje = (disciplinasnumerico[i][1] * 100.0) / alumnosCargados;
        printf("%s (%s): %.2f%%\n", disciplinas[i][0], disciplinas[i][1], porcentaje);
    }

    mayor = disciplinasnumerico[0][1];
    for (int i = 1; i < 4; i++)
    {
        if (disciplinasnumerico[i][1] > mayor)
        {
            mayor = disciplinasnumerico[i][1];
            posicionMayor = i;
        }
    }
    if (mayor != 0)
    {
        printf("\nTaller con mayor cantidad de inscriptos:\n");
        printf("%s (%s) con %d alumnos.\n", disciplinas[posicionMayor][0], disciplinas[posicionMayor][1], mayor);
    }
    else
    {
        printf("No hay alumnos inscriptos en ningún taller aun.");
    }

    for (int i = 0; i < alumnosCargados; i++)
    {
        if (atoi(alumnos[i][3]) < 5)
        {
            if (strcmp(alumnos[i][4], "PNT") == 0)
                menoresPNT++;

            else if (strcmp(alumnos[i][4], "ESC") == 0)
                menoresESC++;

            else if (strcmp(alumnos[i][4], "THR") == 0)
                menoresTHR++;

            else if (strcmp(alumnos[i][4], "FOT") == 0)
                menoresFOT++;
        }
    }

    printf("\nPorcentaje de menores de 5 años por taller:\n");
    if (disciplinasnumerico[0][1] > 0)
        printf("PNT: %.2f%%\n", (menoresPNT * 100.0) / disciplinasnumerico[0][1]);
    if (disciplinasnumerico[1][1] > 0)
        printf("ESC: %.2f%%\n", (menoresESC * 100.0) / disciplinasnumerico[1][1]);
    if (disciplinasnumerico[2][1] > 0)
        printf("THR: %.2f%%\n", (menoresTHR * 100.0) / disciplinasnumerico[2][1]);
    if (disciplinasnumerico[3][1] > 0)
        printf("FOT: %.2f%%\n", (menoresFOT * 100.0) / disciplinasnumerico[3][1]);
}
// ----------------------------- Main -----------------------------

int main()
{
    // VARIABLES Y ARRAYS
    // Banderas
    int flagvalidaciontaller = 0;
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
    int mediodepagonumerico;
    int adeudadonumerico = 0;
    char adeudadonumchar[30];
    // Almacenamiento de alumnos
    char alumnos[100][7][30];
    // Talleres
    char disciplinas[4][2][15] = {
        {"PNT", "Pintura"},
        {"ESC", "Escultura"},
        {"THR", "Teatro"},
        {"FOT", "Fotografia"},
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

        // Opción 1 MENU
        if (opcionvalidada == 1)
        {
            alumnosCargados = 0;
            disciplinasnumerico[0][1] = 0;
            disciplinasnumerico[1][1] = 0;
            disciplinasnumerico[2][1] = 0;
            disciplinasnumerico[3][1] = 0;

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
                flagvalidaciontaller = 0;
                adeudadonumerico = 0;
                printf("Ingrese los datos del alumno n° %d \n", i + 1);

                // DNI
                printf("Dni: ");
                scanf("%s", alumnos[i][0]);

                while (!validarDNI(alumnos[i][0]))
                {
                    printf("DNI invalido. Intente nuevamente.\n");
                    printf("Dni: ");
                    scanf("%s", alumnos[i][0]);
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
                    adeudadonumerico = 2000;
                }

                // Código de taller y validación
                // Validación cada curso con menos de 60 personas inscriptas
                while (flagvalidaciontaller == 0)
                {
                    talleres(alumnos[i][4]);

                    if (strcmp(alumnos[i][4], "PNT") == 0 && disciplinasnumerico[0][1] >= 60)
                    {
                        printf("El curso está lleno. Seleccione otro: \n");
                    }

                    else if (strcmp(alumnos[i][4], "ESC") == 0 && disciplinasnumerico[1][1] >= 60)
                    {
                        printf("El curso está lleno. Seleccione otro: \n");
                    }

                    else if (strcmp(alumnos[i][4], "THR") == 0 && disciplinasnumerico[2][1] >= 60)
                    {
                        printf("El curso está lleno. Seleccione otro: \n");
                    }

                    else if (strcmp(alumnos[i][4], "FOT") == 0 && disciplinasnumerico[3][1] >= 60)
                    {
                        printf("El curso está lleno. Seleccione otro: \n");
                    }
                    else
                    {
                        flagvalidaciontaller = 1;
                    }
                }
                // Validación de cursos y precios
                if (strcmp(alumnos[i][4], "PNT") == 0)
                {
                    disciplinasnumerico[0][1]++;
                    if (edadnumerico >= 5)
                    {
                        adeudadonumerico += disciplinasnumerico[0][0];
                    }
                }
                else if (strcmp(alumnos[i][4], "ESC") == 0)
                {
                    disciplinasnumerico[1][1]++;
                    if (edadnumerico >= 5)
                    {
                        adeudadonumerico += disciplinasnumerico[1][0];
                    }
                }
                else if (strcmp(alumnos[i][4], "THR") == 0)
                {
                    disciplinasnumerico[2][1]++;
                    if (edadnumerico >= 5)
                    {
                        adeudadonumerico += disciplinasnumerico[2][0];
                    }
                }
                else if (strcmp(alumnos[i][4], "FOT") == 0)
                {
                    disciplinasnumerico[3][1]++;
                    if (edadnumerico >= 5)
                    {
                        adeudadonumerico += disciplinasnumerico[3][0];
                    }
                }

                // MEDIO DE PAGO
                printf("Medio de pago \n");
                printf("1 - Efectivo \n");
                printf("2 - Crédito \n");
                printf("Medio de pago: ");
                scanf("%s", alumnos[i][5]);
                mediodepagonumerico = strtol(alumnos[i][5], NULL, 10);
                while (mediodepagonumerico != 1 && mediodepagonumerico != 2)
                {
                    printf("Medio de pago no válido. Intente nuevamente.\n");
                    printf("1 - Efectivo\n");
                    printf("2 - Crédito\n");
                    printf("Medio de pago: ");
                    scanf("%s", alumnos[i][5]);
                    mediodepagonumerico = strtol(alumnos[i][5], NULL, 10);
                }
                if (mediodepagonumerico == 2 && edadnumerico >= 5)
                {
                    adeudadonumerico = adeudadonumerico * 1.05;
                }
                sprintf(adeudadonumchar, "%d", adeudadonumerico);
                strcpy(alumnos[i][6], adeudadonumchar);
            }

            // Actualización de alumnos cargados
            alumnosCargados = alumnosCargados + cantidadDeAlumnos;
        }
        // Opción 2 MENU
        else if (opcionvalidada == 2)
        {
            listadoAlumnos(alumnos, alumnosCargados);
        }
        // Opción 3 MENU
        else if (opcionvalidada == 3)
        {
            if (alumnosCargados != 0)
            {
                filtradoPorTaller(alumnos, alumnosCargados);
            }
            else
            {
                printf("No hay alymnos cargados.");
            }
        }
        // Opción 4 MENU
        else if (opcionvalidada == 4)
        {
            if (alumnosCargados != 0)
            {
                estadoTalleres(alumnos, alumnosCargados, disciplinas, disciplinasnumerico);
            }
            else
            {
                printf("No hay alymnos cargados.");
            }
        }
        // Opción 5
        else if (opcionvalidada == 5)
        {
            if (alumnosCargados != 0)
            {
                buscarAlumno(alumnos, alumnosCargados);
            }
            else
            {
                printf("No hay alymnos cargados.");
            }
        }
        else if (opcionvalidada == 6)
        {
            if (alumnosCargados != 0)
            {
                estadisticasGestion(alumnos, alumnosCargados, disciplinas, disciplinasnumerico);
            }
            else
            {
                printf("No hay alymnos cargados.");
            }
        }
    } while (opcionvalidada != 7);

    printf("\nGracias por utilizar ArteTotal.\n");

    return 0;
}