//
//  Busqueda.h
//  busquedas
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#ifndef Busqueda_h
#define Busqueda_h

#ifndef busqueda_h
#define busqueda_h
#include <stdlib.h>
using namespace std;
#include <vector>

template<typename T>
class Busqueda
{
private:
    vector<T>arr;

public:
    Busqueda();
    ~Busqueda();

    int BusquedaSecuencial(T val);
    int BusquedaOrdenada1(T val);
    int BusquedaOrdenada2 (T val);
    int BusquedaBinaria (T val);
};

