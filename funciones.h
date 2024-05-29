
void ingresarProductos(char productos[][3][30], float costos[], int cantidades[], int total);
void imprimirInventario(char productos[][3][30], float costos[], int cantidades[], int total);
int buscarProductoPorNombre(char productos[][3][30], char nombreBuscado[], int total);
void imprimirProductoPorIndice(char nombreBuscado[], char productos[][3][30], float costos[], int cantidades[], int indice);
void eliminarProducto(char productos[][3][30], float costos[], int cantidades[], int total, char nombreBuscado[]);
