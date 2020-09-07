//
//  main.cpp
//  algoritmos de busqueda
//
//  Created by Jorge Becker on 8/26/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#include <iostream>
#include "busqueda.h"
#include "sort.h"
using namespace std;





int main()
{
    Busqueda<int> o1;
    o1.BusquedaSecuencial(80);
    o1.BusquedaOrdenada1(80);
    o1.BusquedaOrdenada2(80);
    o1.BusquedaBinaria(80);
    
    cout<<o1.BusquedaSecuencial(80);
    
    

}
