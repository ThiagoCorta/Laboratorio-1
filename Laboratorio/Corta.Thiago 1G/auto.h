typedef struct
{
    int idMarca;
    char descripcion[20];
}eMarca;

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

typedef struct{
 int idColor;
 char nombreColor[20];
}eColor;

typedef struct{
int idAuto;
int idMarca;
int idColor;
int modeloAnio;
int isEmpty;
char patente[7];

}eAuto;

typedef struct{
int idServicio;
char descripcion[25];
int precioServicio;
}eServicio;

/** \brief pongo el estado de los autos en 0
 *
 * \param array autos
 * \param tamanio del array
 * \return nada
 *
 */
void initAutos(eAuto* list, int len);

/** \brief busco un indice del array vacio
 *
 * \param array autos
 * \param tamanio del array
 * \return el indice vacio
 *
 */
int findEmptyAuto(eAuto* list, int len);

/** \brief se le pasa una patente por referencia y la busca en el array autos
 *
 * \param array uatos
 * \param tamanio del array
 * \param patente que se busca en formato char
 * \return el indice si la encontro o -1 si no.
 *
 */
int findAutoByPatente(eAuto* list, int len, char* patente);

/** \brief genera un id autoincremental para los autos
 * \return devuelve el id.
 *
 */
int getIdAuto();

/** \brief pide los datos necesarios para agregar un nuevo auto, los valida y los ingresa.
 *
 * \param array auto
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \param array colores
 * \param tamanio del array
 * \return devuelve 1 si pudo agregar un nuevo auto.
 *
 */
int addAuto(eAuto* list, int len, eMarca* marcas, int lenM, eColor* colores, int lenC);

/** \brief se le ingresa un msg o un mensaje error y pregunta si esta seguro.
 *
 * \param msg
 * \param msg error
 * \return s si esta seguro n si no.
 *
 */
char preguntarSiEstaSeguro(char* msg, char* msgerror);

/** \brief muestra los autosm pide la patente y da la baja logica si el usuario lo desea.
 *
 * \param array autos
 * \param tamanio del array
 * \return 1 si dio la baja -1 si no.
 *
 */
int removeAuto(eAuto* list, int len);

/** \brief esta funcion sabe mostrar un auto
 *
 * \param un auto
 * \param array colores
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \return no devuelve nada, solo muestra un auto.
 *
 */
void printAuto(eAuto list, eColor* color,int lenc,eMarca* marcas, int lenM);

/** \brief esta funcion sabe mostrar muchos autos
 *
 * \param array autos
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \param array colores
 * \param tamanio del array
 * \return no devuelve nada, solo muestra los autos
 */
void printAutos(eAuto* list, int len, eMarca* marca, int lenM, eColor* color, int lenC);

/** \brief muestra un menu de opciones para acceder a modificaciones
 *
 * \param
 * \param
 * \return la opcion elegida en ese menu.
 *
 */
int menuModificar();

/** \brief esta funcion modifica parametros de un auto
 *
 * \param array autos
 * \param tamanio del array
 * \param array color
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \return devuelve 1 si pudo modificarlo -1 si no pudo.
 */
int modifyAuto(eAuto* list, int len, eColor* color, int lenc, eMarca* marcas, int lenM);

/** \brief muestra un menu de opciones del abm
 *
 * \param
 * \param
 * \return la opcion elegida en ese menu.
 *
 */
int menuAbm();

/** \brief muestra los modelos su id e descripcion.
 *
 * \param array marcas
 * \param tamanio array
 * \return nada
 *
 */
void mostrarModelos( eMarca* marca, int len);

/** \brief muestra los servicicios, su id e precios..
 *
 * \param array servicios
 * \param tamanio array
 * \return nada
 *
 */
void mostrarServicios(eServicio* servicio, int lenS);

/** \brief muestra los colores id e descripcion.
 *
 * \param array colores
 * \param tamanio array
 * \return nada
 *
 */
void mostrarColores( eColor* color, int lenC);

/** \brief obtiene la descripcion de los colores
 *
 * \param array colores
 * \param tamanio del array
 * \param un ID de color
 * \param un puntero a char para copiar la desc del color.
 * \return devuelve 1 si pudo copiar la desc del color en el puntero que se ingreso por referencia.
 *
 */
int obtenerColores(eColor* colores, int lenC, int idColor, char* desc);

/** \brief obtiene la descripcion de los marcas
 *
 * \param array marcas
 * \param tamanio del array
 * \param un ID de marca
 * \param un puntero a char para copiar la desc de la marca.
 * \return devuelve 1 si pudo copiar la desc de la marca en el puntero que se ingreso por referencia.
 *
 */
int obtenerMarcas(eMarca* marcas, int lenM, int idMarca, char* desc);

/** \brief ordena los autos por marcas y patentes.
 *
 * \param array autos
 * \param tamanio del arrray
 * \return nada
 *
 */
void sortAutos(eAuto* list, int len);

/** \brief se le pasa una id Servicio y la busca en el array servicios
 *
 * \param array servicios
 * \param tamanio del array
 * \param id Servicio que se busca en formato int
 * \return el indice si lo encontro o -1 si no.
 *
 */
int findServicioById(eServicio* servicio, int lenS, int idServicio);

/** \brief veo si hay algun auto cargado en el array para poder setear las flags.
 *
 * \param array autos
 * \param tamanio array
 * \return !=-1 si esta cargado o -1 si esta vacio.
 *
 */
int findArrayAuto(eAuto* autos, int lenA);

/** \brief pasa una cadena a mayuscula
 *
 * \param puntero a la cadena
 * \return nada modifica la cadena y la pasa a mayuscula
 *
 */
void Tstrupr(char* cadena);

/** \brief hardcodea autos en el array.
 *
 * \param array autos
 * \param tamanio del array
 * \return nada, solo los ingresa al sistema.
 *
 */
void hardCodearAutos(eAuto* autos, int tam);
