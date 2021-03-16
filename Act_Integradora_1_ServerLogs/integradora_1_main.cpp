//o Descripciónbrevedelprograma.
//o Unalíneaconel/losautor/autores:nombre(s)ymatrícula(s).
//o Unalíneaconlafechadecreación/modificación.

/*
 * Este programa es una actividad en la cual se nos da un archivo de texto a ordenar.
 * Despues se tiene que poner buscar en este archivo un rango de valores que son daados por el usuario
 *
 * Carla Oñate Gardella     A01653555
 * Ultima modificación: 15 Marzo 2021
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Server.h"

//Funcion para llamar Server que dentro está la funcionalidad de la actividad
int main() {
    Server server = Server();
    server.searchLog();
    return 0;
}
