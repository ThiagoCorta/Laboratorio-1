typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{
    int isEmpty;
    int idSocio;
    char nombreSocio[31];
    char apellidoSocio[31];
    char emailSocio[31];
    char sexoSocio;
    float telefono;
    eFecha fechaIng;

}eSocios;

void initSocios(eSocios* list, int len);
int findEmptySlot(eSocios* list, int len);
int addSocio(eSocios* list, int len);
int findSocioById(eSocios* list, int len,int id);
int removeSocio(eSocios* list, int len, int id);
int sortSocios(eSocios* list, int len);
void printSocio(eSocios list);
void printSocios(eSocios* list, int len);
int menuModificarSocio();
int modifySocio(eSocios* list, int len);
int menuSocios();
void funcSocios(eSocios* list, int len);
