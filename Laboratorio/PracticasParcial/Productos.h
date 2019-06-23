typedef struct{
    int cod;
    char desc[50];
    int importe;
    int cant;
    int activo;
}eProducto;

void eProducto_delete(eProducto* this);
int eProducto_setCod(eProducto* this,int auxCod);
int eProducto_getCod(eProducto* this,int* auxCod);
int eProducto_setDesc(eProducto* this,char* auxDesc);
int eProducto_getDesc(eProducto* this,char* auxDesc);
int eProducto_setImporte(eProducto* this,int auxImporte);
int eProducto_getImporte(eProducto* this,int* auxImporte);
int eProducto_setCant(eProducto* this,int auxCant);
int eProducto_getCant(eProducto* this,int* auxCant);
int eProducto_setStatus(eProducto* this,int auxStatus);
int eProducto_getStatus(eProducto* this,int* auxStatus);
eProducto* eProducto_new();
eProducto* eProducto_newParametros(char* auxCod,char* auxDesc,char* auxImporte, char* auxCant, char* auxStatus);
int eProducto_isValidProd(eProducto* this);
int printProduct(eProducto* this);
int menuModify();
int menu();
int compareByDesc(void* emp1, void* emp2);
int addProducto(LinkedList* pArrayList);
int editProducto(LinkedList* pArrayList);
