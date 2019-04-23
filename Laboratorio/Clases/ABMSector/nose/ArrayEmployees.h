typedef struct
{
    int id;
    char descripcion[20];
}eSector;

typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo;
    int sector;
    float sueldo;
    int ocupado;

} eEmpleado;

/** \brief Para inicializar a todos los empleados les pone el estado en 0 (vacio)
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return no devuelve nada.
 */
void inicializarEmpleados(eEmpleado vec[], int tam);





/** \brief Busca entre los estados de la estructura eEmpleados cual esta en 1 y cual en 0, cuando encuentra uno en 0 para.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return el primer indice que encontro que el estado era vacio.
 *
 */
int buscarVacio(eEmpleado vec [], int tam);



/** \brief le paso una funcion que sabe mostrar 1 empleado y con un un bucle for hago que muestre todos los que tengan el estado en 1.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return no devuelve nada, solo muestra los empleados.
 */
void mostrarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);



/** \brief Sabe mostrar un solo empleado.
 *
 * \param un empleado.
 * \return no devuelve nada, solo lo muestra.
 *
 */
void mostrarEmpleado(eEmpleado emp, eSector sectores [], int tam);



/** \brief Busca un empleado entre los activos segun el legajo que ingresemos, si lo encuentra te da el indice y si no -1.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \param legajo del empleado que queremos buscar.
 * \return indice del empleado o en su caso -1 de no encontrarlo.
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);



/** \brief Menu del ABM solo muestra.
 *
 * \return devuelve la opcion elegida.
 *
 */
int menuAbm();



/** \brief Da de alta un empleado, le genera un legajo o id automatico, le pide nombre, apellido, sexo, sueldo, y sector de trabajo.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return devuelve algo distinto a -1 si pudo dar de alta al empleado.
 *
 */
int altaEmpleado(eEmpleado vec[], int tam);


/** \brief Da de baja un empleado, te muestra los empleados ingresados, te pide el legajo del que quieras dar de baja, y lo da de baja.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return por ahora no devuelve nada, solo pone el estado del empleado en 0.
 *
 */
void bajaEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tamSec);



/** \brief pide un entero y valida que lo que ingresaste solo sea un entero y no otra cosa.
 *
 * \param le pasamos un mensaje que muestre a la hora de pedir un entero.
 * \return el entero validado.
 *
 */
int pedirEntero(char mensaje[]);



/** \brief Ingresa un nombre, valida que no se pase del tamanio del array nombre.
 *
 * \param la estructura de eEmpleado.
 * \param indice del empleado que queremos agregar, junto con otras funciones se lo pasamos.
 * \return no devuelve nada, solo lo guarda en el array nombre ya validado.
 *
 */
void ingresarNombre(eEmpleado vec[], int indice);



/** \brief Nos permite modificar un empleado, nos muestra la lista de empleados, nos pide el legajo o id del que queremos modificar, se abre un meno de opciones para elegir que modificar y permite modificarlo.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return no devuelve nada por ahora, solo modifica la opcion que hayas elegido.
 *
 */
void modificarEmpleado(eEmpleado vec[], int tam);



/** \brief Es el menu que te aparece cuando llamas la funcion modificarEmpleado.
 *
 * \return muestra el menu y devuelve la opcion elegida.
 *
 */
int menuModificar();



/** \brief
 *
 * \param Hace que el nombre ingresado quede acomodado con las primeras letras, se complementa con otra funcion de esta libreria.
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return lo modifica en el array.
 *
 */
void ajustarNombre(char vec[],int tam);



/** \brief Ingresa un apellido, valida que no se pase del tamanio del array apellido.
 *
 * \param la estructura de eEmpleado.
 * \param indice del empleado que queremos agregar, junto con otras funciones se lo pasamos.
 * \return no devuelve nada, solo lo guarda en el array apellido ya validado.
 *
 */
void ingresarApellido(eEmpleado vec[], int indice);




/** \brief pide un flotante y valida que sea un flotante o en su defecto un entero.
 *
 * \param le pasamos el mensaje que queremos que muestre a la hora de pedir el float.
 * \return el float validado que es un flotante o en su defecto un entero en forma de float.
 *
 */
float pedirFloat(char mensaje[]);



/** \brief Ordena la estructura con los apelldios ordenados alfabeticamente y por sector.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return no devuelve nada, solo ordena la estructura.
 *
 */
void ordenarEstructura(eEmpleado vec[], int tam);



/** \brief funcion para saber cuantos empleados superan el promedio de salario.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return la cantidad de empleados que superan el salario promedio.
 *
 */
int cantidadSuperaPromedio(eEmpleado vec [], int tam);


/** \brief Funcion que suma todos los salarios de todos los empleados ingresados que estan en forma activa.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return devuelve la suma de todos los salarios entre los empleados activos.
 *
 */
float totalSalarios(eEmpleado vec [], int tam);


/** \brief Calcula el promedio de salario entre todos los empleados activos.
 *
 * \param la estructura de eEmpleado.
 * \param Tamanio de la estructura
 * \return devuelve el promedio de salario entre los empleados activos.
 */
float promedioSueldos(eEmpleado vec[], int tam);


void hardCodearEmpleados(eEmpleado vec[], int tam);

void pedirSexo(eEmpleado vec[], int indice);


int esSoloLetras(char str[]);


int getStringLetras(char mensaje[],char input[]);


void getValidString(char requestMessage[],char errorMessage[], char input[]);

void getString(char mensaje[],char input[]);

char preguntarSiEstaSeguro(char mensaje[]);
