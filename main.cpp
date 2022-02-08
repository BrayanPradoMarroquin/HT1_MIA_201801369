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

int main() {
    cout<<"Bienvenido como estas"<<endl;

    return 0;
}
