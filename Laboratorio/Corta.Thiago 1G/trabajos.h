typedef struct
{
    int idTrabajo;
    char patente[6];
    int idServicio;
    eFecha fechaIng;
    int isEmpty;

}eTrabajo;

/** \brief pongo el estado de los trabajos en 0
 *
 * \param array trabajos
 * \param tamanio del array
 * \return nada
 *
 */
void initTrabajos(eTrabajo* list, int lenT);

/** \brief busco un indice del array vacio
 *
 * \param array trabajos
 * \param tamanio del array
 * \return el indice vacio
 *
 */
int findEmptyTrabajo(eTrabajo* list, int lenT);

/** \brief genera un id auto incremental
 *
 * \return el id
 *
 */
int getIdTrabajo();

/** \brief pide los datos necesarios para agregar un nuevo trabajo, los valida y los ingresa.
 *
 * \param array trabajos
 * \param tamanio del array
 * \param array servicios
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \param array colores
 * \param tamanio del array
 * \return devuelve 1 si pudo agregar un nuevo trabajo.
 *
 */
int addTrabajo(eTrabajo* list, int lenT, eAuto* autos, int lenA, eServicio* servicio, int lenS, eMarca* marca, int lenM, eColor* color, int lenC);

/** \brief obtiene la descripcion de los servicios
 *
 * \param array servicios
 * \param tamanio del array
 * \param un ID de servicio
 * \param un puntero a char para copiar la desc del servicio.
 * \return devuelve 1 si pudo copiar la desc del servicio en el puntero que se ingreso por referencia.
 *
 */
int obtenerServicios(eServicio* servicio, int lenS, int idServicio, char* desc);

/** \brief esta funcion sabe mostrar un trabajo.
 *
 * \param un trabajo
 * \param array servicios
 * \param tamanio del array
 * \param array autos
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \return no devuelve nada, solo muestra un trabajo.
 *
 */
void printTrabajo(eTrabajo list, eServicio* servicios, int lenS, eAuto* autos, int lenA,eMarca* marcas, int lenM);

/** \brief esta funcion sabe mostrar muchos trabajos
 *
 * \param array trabajos
 * \param tamanio del array
 * \param array servicios
 * \param tamanio del array
 * \param array autos
 * \param tamanio del array
 * \param array marcas
 * \param tamanio del array
 * \return no devuelve nada, solo muestra los trabajo.
 *
 */
void printTrabajos(eTrabajo* list, int lenT, eServicio* servicios, int lenS, eAuto* autos, int lenA,eMarca* marcas, int lenM);

/** \brief busca un indice vacio en el array trabajo.
 *
 * \param array trabajos
 * \param tamanio dle array
 * \return el indice del lugar vacio para ing nuevo trabajo.
 *
 */
int findArrayTrabajo(eTrabajo* list, int lent);

/** \brief hardcodea trabajos en el array.
 *
 * \param array trabajos
 * \param tamanio del array
 * \return nada, solo los ingresa al sistema.
 *
 */
void hardCodearTrabajos(eTrabajo* works, int tam);

/** \brief menu de consultas
 *
 * \return opcion ingresada
 *
 */
int menuAbmConsultas();
void trabajosPorServicios(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM);
void funcConsultas(eAuto* autos,int lenA,eTrabajo* trabajos,int lenT,eServicio* servicios,int lenS,eColor* colores,int lenC,eMarca*marcas,int lenM);
void servicioMasPopular(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM);


void servicioMasPopular(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM);


void acumuladorAnual(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM);







