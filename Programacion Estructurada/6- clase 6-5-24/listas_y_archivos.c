struct Alumno {
    char nombre[20];//miembros de la estructura alumno
    char apellido[20]
};
int main(){
    FILE *archivo; //archivos de tipo file
    fopen(archivo);    //funciones fopen para abrir un archivo, 0--> OK
    fclose(archivo);//funcion fclose para cerrar un archivo
    //un error comun puede ser que no abra el archivo porque no exista.
    a= fopen('/datos.txt', w);//datos es el txt que devuelve y devuelve un puntero que almacena en a y la w es el modo(w-write, r-read, a-abre pero no borra)
    //w por lo general se usa para crear texto.
    return 0;
}