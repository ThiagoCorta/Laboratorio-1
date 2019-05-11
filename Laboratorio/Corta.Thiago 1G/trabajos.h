typedef struct
{
    int idTrabajo;
    int patente;
    int idServicio;
    eFecha fechaIng;
    int isEmpty;

}eTrabajo;

void initTrabajos(eTrabajo* list, int lenT);
int findEmptyTrabajo(eTrabajo* list, int lenT);
int getIdTrabajo();
int addTrabajo(eTrabajo* list, int lenT, eAuto* autos, int lenA, eServicio* servicio, int lenS, eMarca* marca, int lenM, eColor* color, int lenC);
int obtenerServicios(eServicio* servicio, int lenS, int idServicio, char* desc);
void printTrabajo(eTrabajo list, eServicio* servicios, int lenS);
void printTrabajos(eTrabajo* list, int len, eServicio* servicios, int lenS);
int findArrayTrabajo(eTrabajo* list, int lent);
