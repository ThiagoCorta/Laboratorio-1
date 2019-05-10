
typedef struct
{
    int isEmpty;
    int idAutor;
    char nombreAutor[31];
    char apellidoAutor[31];

}eAutor;

int findEmptySlotAutor(eAutor* list, int len);
void initAutor(eAutor* list, int len);
int idAutor();
int altaAutor(eAutor* list, int len);
void printAutor(eAutor list);
void printAutores(eAutor* list, int len);
int findAutorById(eAutor* list, int len, int id);
char preguntarSiEstaSeguro(char* msg, char* msgerror);
int removeAutor(eAutor* list, int len, int id);
int menuAutores();
int menuModificarAutores();
int modifyAutor(eAutor* list, int len);
int sortAutores(eAutor* list, int len);
void hardCodearAutores(eAutor* list, int len);
void funcAutores(eAutor* list, int len);

