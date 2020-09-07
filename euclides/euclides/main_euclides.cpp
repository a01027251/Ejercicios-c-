//
//  main.cpp
//  euclides
//
//  Created by Jorge Becker on 8/26/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#include <iostream>
using namespace std;
int euclides(int a, int b){
    if (a==0){
        return b;
    }
    else{
        return euclides(b%a,a);
    }
        
}

int main(){
    int a,b;
    cout<<"Numero 1: ";
    cin>>a;
    cout<<"Numero 2: ";
    cin>>b;
    cout<<"El maximo comun divisor es: "<<euclides(a, b)<< endl;
    return 0;
    
};
