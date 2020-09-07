//
//  main.cpp
//  skyline
//
//  Created by Jorge Becker on 8/27/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int log(int a[][6],int noCol, int noRow, int col=0,int row=0)
{
    if (a[row][col]==0)
        return col;
    
    else if(noCol<col || noRow<row)
        return -1;
    
    else if (col==noCol)
        log(a,noCol,noRow,0,row+=1);
    
    else if (a[row][col] != 0)
        return log (a,noCol,noRow,col+=1,row);
    return -1;
    
    
}


int main(int argc, char const *argv[]) {
    int skyline [5][6] = {
        {1,1,1,0,1,1},
        {1,1,0,0,0,1},
        {0,1,0,0,0,1},
        {0,1,0,0,0,1},
        {0,0,0,0,0,1},
    };
    cout<<log(skyline, 5, 4)<<endl;
}
//{1,1,1,0,1,1},
//{1,1,0,0,0,1},
//{0,1,0,0,0,1},
//{0,1,0,0,0,1},
//{0,0,0,0,0,1},
