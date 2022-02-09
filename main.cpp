#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Profesor
{
    int id_profesor;
    char cui[13];
    char nombre[25];
    char curso[25];
};

struct Estudiante
{
    int id_estudiante;
    char cui[13];
    char nombre[25];
    char carnet[10];
};

void escribirProfesor(int id, string cui, string nombre, string curso){
    Profesor prof;

    prof.id_profesor = id;
    strcpy(prof.cui, cui.c_str());
    strcpy(prof.nombre, nombre.c_str());
    strcpy(prof.curso, curso.c_str());

    // AQUÍ ABRIMOS COMO LECTURA Y ESCRITURA (rb+) EL ARCHIVO BINARIO
    string path = "./archivo.bin";
    FILE *disk_file = fopen(path.c_str(), "rb+");

    // FSEEK NOS POSICIONA DENTRO  DEL ARCHIVO
    fseek(disk_file, 0, SEEK_SET); // EL SEGUNDO PARAMETROS ES LA POSICIÓN (0 EN ESTE CASO)

    // CON FWRITE GUARDAMOS EL STRUCT LUEGO DE POSICIONARNOS
    fwrite(&prof, sizeof(Profesor), 1, disk_file); // EL TERCER PAREMETRO ES LA CANTIDAD DE STRUCTS A GUARDAR (EN ESTE CASO SOLO 1)

    // CERRAR STREAM (importante)
    fclose(disk_file);
}

void escribirEstudiante(int id, string cui, string nombre, string curso){
    Estudiante alumno;

    alumno.id_estudiante = id;
    strcpy(alumno.cui, cui.c_str());
    strcpy(alumno.nombre, nombre.c_str());
    strcpy(alumno.carnet, curso.c_str());

    // AQUÍ ABRIMOS COMO LECTURA Y ESCRITURA (rb+) EL ARCHIVO BINARIO
    string path = "./archivo.bin";
    FILE *disk_file = fopen(path.c_str(), "rb+");

    // FSEEK NOS POSICIONA DENTRO  DEL ARCHIVO
    fseek(disk_file, 0, SEEK_SET); // EL SEGUNDO PARAMETROS ES LA POSICIÓN (0 EN ESTE CASO)

    // CON FWRITE GUARDAMOS EL STRUCT LUEGO DE POSICIONARNOS
    fwrite(&alumno, sizeof(Profesor), 1, disk_file); // EL TERCER PAREMETRO ES LA CANTIDAD DE STRUCTS A GUARDAR (EN ESTE CASO SOLO 1)

    // CERRAR STREAM (importante)
    fclose(disk_file);
}

void read()
{
    // STRUCT QUE VAMOS A LEER
    Profesor data;

    // AQUÍ ABRIMOS COMO LECTURA Y ESCRITURA (r+) EL ARCHIVO BINARIO
    string path = "./binario.bin";
    FILE *disk_file = fopen(path.c_str(), "r+");

    // FSEEK NOS POSICIONA DENTRO  DEL ARCHIVO
    fseek(disk_file, 0, SEEK_SET); // EL SEGUNDO PARAMETROS ES LA POSICIÓN (0 EN ESTE CASO)

    // CON FWRITE GUARDAMOS EL STRUCT LUEGO DE POSICIONARNOS
    fread(&data, sizeof(Profesor), 1, disk_file); // EL TERCER PAREMETRO ES LA CANTIDAD DE STRUCTS A GUARDAR (EN ESTE CASO SOLO 1)

    // CERRAR STREAM (importante)
    fclose(disk_file);

    // AQUÍ MOSTRAMOS EL STRUCT
    cout << data.id_profesor << endl
         << data.cui << endl
         << data.nombre << endl
         << data.curso;
}

int main() {
    cout<<"Bienvenido como estas"<<endl;
    cout<<"Brayan Hamllelo Estevem Prado Marroquin - 201801369"<<endl;

    return 0;
}
