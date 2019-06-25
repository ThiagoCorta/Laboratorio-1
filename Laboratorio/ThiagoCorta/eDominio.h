typedef struct
{
    int id;
    char dominio[50];
    int anio;
    char tipo;
}eDominio;


void eDominio_delete(eDominio* this);
int eDominio_setId(eDominio* this,int id);
int eDominio_getId(eDominio* this,int* id);
int eDominio_setTipo(eDominio* this,char* auxTipo);
int eDominio_getTipo(eDominio* this,char* auxTipo);
int eDominio_setDominio(eDominio* this,char* auxDom);
int eDominio_getDominio(eDominio* this,char* auxDom);
int eDominio_setAnio(eDominio* this,int auxAnio);
int eDominio_getAnio(eDominio* this,int* auxAnio);
eDominio* eDominio_new();
eDominio* eDominio_newParametros(char* idStr,char* dominioStr, char* anioStr);
int eDominio_isValid(eDominio* pAux);
int menu();
int printDominio(eDominio* this);
int compareByName(void* eDom1, void* eDom2);
int eDominio_filterAuto(void* pAux);
void* eDominio_llAutos(void* pAux);
int eDominio_filterMoto(void* pAux);
void* eDominio_llMotos(void* pAux);
