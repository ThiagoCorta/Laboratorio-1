typedef struct
{
    int idTrabajo;
    char patente[6];
    int idServicio;
    eFecha fechaIng;
    int isEmpty;

}eTrabajo;

void initTrabajos(eTrabajo* list, int lenT);
int findEmptyTrabajo(eTrabajo* list, int lenT);
int getIdTrabajo();
int addTrabajo(eTrabajo* list, int lenT, eAuto* autos, int lenA, eServicio* servicio, int lenS, eMarca* marca, int lenM, eColor* color, int lenC);
int obtenerServicios(eServicio* servicio, int lenS, int idServicio, char* desc);
void printTrabajo(eTrabajo list, eServicio* servicios, int lenS, eAuto* autos, int lenA,eMarca* marcas, int lenM);
void printTrabajos(eTrabajo* list, int lenT, eServicio* servicios, int lenS, eAuto* autos, int lenA,eMarca* marcas, int lenM);
int findArrayTrabajo(eTrabajo* list, int lent);
void hardCodearTrabajos(eTrabajo* works, int tam);
int menuAbmConsultas();
void trabajosPorServicios(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM);
void funcConsultas(eAuto* autos,int lenA,eTrabajo* trabajos,int lenT,eServicio* servicios,int lenS,eColor* colores,int lenC,eMarca*marcas,int lenM);
void servicioMasPopular(eAuto* autos,int lenA,eTrabajo* trabajos, int lenT, eServicio* servicios, int lenS, eColor* colores, int lenC,eMarca* marcas,int lenM);





