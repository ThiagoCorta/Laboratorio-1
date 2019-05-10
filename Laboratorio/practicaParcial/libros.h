typedef struct
{
    int isEmpty;
    int idLibro;
    int idAutor;
    char titulo[51];


}eLibros;

int findEmptySlotLibro(eLibros* list, int len);
void initLibro(eLibros* list, int len);
int idLibro();
int altaLibro(eLibros* list, int len, eAutor* autores, int lenAut);
void printLibro(eLibros list);
void printLibros(eLibros* list, int len);
int findLibroById(eLibros* list, int len, int id);
int removeLibro(eLibros* list, int len, int id);
int menuLibros();
int modifyLibro(eLibros* list, int len, eAutor* autores, int lenAu);
int sortLibros(eLibros* list, int len);
void hardCodearLibros(eLibros* list, int len);
void funcLibros(eLibros* list, int len, eAutor* autores, int lenAu);
