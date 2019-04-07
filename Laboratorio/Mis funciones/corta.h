
/** \brief obtiene un maximo
 *
 * \param primer entero
 * \param segundo entero
 * \param tercer entero
 * \return el maximo
 *
 */

int obtenerMaximo (int x, int y, int z);


/** \brief Muestra el menu
 *
 * \param primer operando
 * \param segundo operando
 * \param calculo de operaciones
 * \param informar resultados
 * \param salir
 * \return la opcion
 *
 */

 int mostrarMenu();

 /** \brief hace una suma
 *
 * \param primer entero
 * \param segundo entero
 * \return la suma
 *
 */

 int thiagoSuma(int x, int y);

 /** \brief hace una resta
 * \param primer entero
 * \param segundo entero
 * \return la resta
 *
 */

 int thiagoResta(int x, int y);

  /** \brief hace una division
 * \param primer entero
 * \param segundo entero
 * \return la division o 0 si y es = a cero
 *
 */

 float thiagoDivide(int x, int y);



  /** \brief hace una multiplicacion
 * \param primer entero
 * \param segundo entero
 * \return la multiplicacion o 0 si y es = a cero
 *
 */

 int thiagoMultiplica(int x, int y);

   /** \brief Un bucle for que calcura el factorial del numero ing
 * \param primer entero ingresado
 * \return el numero fatorial
 *
 */
double thiagoFactorial(int x);

 /** \brief Muestra el menu
 *
 * \param suma a + b
 * \param resta a - b
 * \param divide a / b
 * \param multiplica a * b
 * \param calcula el factorial a!
 * \param vuelve al menu principal
 * \return la opcion
 *
 */


 int menuOperaciones();

 /** \brief toma y verifica un numero
 *
 * \param numero ingresado
 * \return lo devuelve.
 *
 */



/** \brief pide un nombre y apellido
 *
 * \param le ingreso un vector [][50]
 * \param el tamanio del vector [tam][50]
 * \param lo pide y acomoda con iniciales en mayus
 */


void pedirNomApe(char nomApe[][50], int tam);

/** \brief pide sexos
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param los pide y acomoda
 */


void pedirSexo(char sexo[], int tam);


/** \brief pide legajos
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param los pide y acomoda
 */
void pedirLegajos(int legajos[], int tam);

/** \brief pide edades
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param los pide y acomoda
 */

void pedirEdad(int edad[], int tam);

/** \brief duplica un vector x 2
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param lo duplica
 */

void duplicarVector(int vector[], int tam);

/** \brief ingreso vectores y los ordena por sexo y alfabeticamente
 *
 * \param le ingreso un vector []
 * \param el tamanio del vector [tam]
 * \param lo duplica
 */

void ordenarVectores( int vector[], int vector2[], int vector3[], char vectorSex[], float vectorFloat[],char nomApe[][50], int vector4 [],int tam);
