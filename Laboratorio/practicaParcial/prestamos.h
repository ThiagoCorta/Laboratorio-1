
typedef struct
{
    int idPrestamo;
    int idLibro;
    int idSocio;
    eFecha fechaPrestamo;
    int isEmpty;

}ePrestamos;
void initPrestamos(ePrestamos* list, int len);
int idPrestamo();
int findEmptySlotPrestamo(ePrestamos* list, int len);
int altaPrestamo(ePrestamos* list, int len, eLibros* libros, int tamL, eSocios* socios, int tams);
void printPrestamo(ePrestamos list);
void printPrestamos(ePrestamos* list, int len);
int menuPrestamo();
void funcPrestamos(ePrestamos* list, int len, eLibros* libros, int taml, eSocios* socios,int tams);

