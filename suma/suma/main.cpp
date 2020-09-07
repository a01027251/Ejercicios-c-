//
//  main.cpp
//  suma
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//


#include <iostream>
using namespace std;

int directo (int numero)//metodo directo para realizar la sumatoria
{
 return (numero*(numero+1))/2;//implementación
}//O=n(1)

int iterativo(long int numero){// metodo iterativo para realizar la sumatoria
    int suma;
    for(int i = 0; i < numero; i++){//for para iterar
        suma = suma + i+1 ;
    }
    return suma-1;
}// complejidad O(n)

int recursiva(int numero){// forma recursiva de realizar la sumatoria
    if(numero==0){
        return 0;
    }
    if(numero>0){
        return recursiva(numero-1) + numero;
    }
    return 0;
}//complejidad O(n)

int main (){
  long int num;
  cout<<"selecciona un numero para realizar su sumatoria: "<<endl;
  cin >>num;
  cout <<"El metodo directo con tu selección es: "<<directo(num)<<endl;
    cout<<"Ejemplo del metodo directo con #5: "<<directo(5)<<endl;
    cout<<"Ejemplo del metodo directo con 10: "<<directo(10)<<endl;
    cout<<"Ejemplo del metodo directo con #20: "<<directo(20)<<endl;
    cout<<endl;
    cout<<endl;
    cout <<"El metodo iterativo con tu eleción es: "<<iterativo(num)<<endl;
    cout<<"Ejemplo del metodo iterativo con #5: "<<iterativo(5)<<endl;
    cout<<"Ejemplo del metodo iterativo con 10: "<<iterativo(10)<<endl;
    cout<<"Ejemplo del metodo iterativo con #20: "<<iterativo(20)<<endl;
    cout<<endl;
    cout<<endl;
    cout <<"El metodo recursivo con tu elección es: "<<recursiva(num)<<endl;
    cout<<"Ejemplo del metodo recursivo con #5: "<<recursiva(5)<<endl;
    cout<<"Ejemplo del metodo directo con 10: "<<recursiva(10)<<endl;
    cout<<"Ejemplo del metodo directo con #20: "<<recursiva(20)<<endl;
    cout<<endl;
    cout<<endl;
}

