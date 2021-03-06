#include <iostream>
#include <fstream>
#include "Queue.h"

#define NMAX 100

using namespace std;

int a[NMAX][NMAX];
int n;

void citire()
{
    fstream f;
    f.open("input.in", ios::in);

    f>>n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            f>>a[i][j];

    f.close();
}

void afisare()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

const int vl[] = {-1, 0, 1, 0};
const int vc[] = {0, 1, 0, -1};
const int dirN = 4;

void prelucrare()
{
    int count = 1;
    Queue coadaL = newQueue();
    Queue coadaC = newQueue();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                push(i, coadaL);
                push(j, coadaC);
                count++;
            }
            while(coadaL.length != 0)
            {
                int ln = pop(coadaL);
                int col = pop(coadaC);
                a[ln][col] = count;
                for(int k = 0; k < dirN; k++)
                {
                    if(ln+vl[k] >=0 && ln+vl[k] < n &&
                       col+vc[k] >= 0 && col+vc[k] < n &&
                       a[ln+vl[k]][col+vc[k]] == 1)
                    {
                        push(ln+vl[k], coadaL);
                        push(col+vc[k], coadaC);
                    }
                }
            }
        }
    }
}

int main()
{
    citire();
    prelucrare();
    afisare();

    return 0;
}
