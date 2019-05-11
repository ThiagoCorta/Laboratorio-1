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
int patente;
int idMarca;
int idColor;
int modeloAnio;
int isEmpty;
}eAuto;

typedef struct{
int idServicio;
char descripcion[25];
int precioServicio;
}eServicio;




void initAutos(eAuto* list, int len);
int findEmptyAuto(eAuto* list, int len);
int findAutoById(eAuto* list, int len, int id);
int getIdAuto();
int addAuto(eAuto* list, int len, eMarca* marcas, int lenM, eColor* colores, int lenC);
char preguntarSiEstaSeguro(char* msg, char* msgerror);
int removeAuto(eAuto* list, int len, int id);
void printAuto(eAuto list, eColor* color,int lenc,eMarca* marcas, int lenM);
void printAutos(eAuto* list, int len, eMarca* marca, int lenM, eColor* color, int lenC);
int menuModificar();
int modifyAuto(eAuto* list, int len, eColor* color, int lenc, eMarca* marcas, int lenM);
int menuAbm();
void mostrarModelos( eMarca* marca, int len);
void mostrarServicios(eServicio* servicio, int lenS);
void mostrarColores( eColor* color, int lenC);
int obtenerColores(eColor* colores, int lenC, int idColor, char* desc);
int obtenerMarcas(eMarca* marcas, int lenM, int idMarca, char* desc);
void sortAutos(eAuto* list, int len);
int findServicioById(eServicio* servicio, int lenS, int idServicio);
int findArrayAuto(eAuto* autos, int lenA);
int menuAbm();
