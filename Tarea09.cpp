#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void pedirDato();
void llenarMatriz();
void mostrarMatriz();
void calcularPromedios();
void liberarMatriz();
double **puntero_matriz;
int n;

int main (){
    pedirDato();
    llenarMatriz();
    mostrarMatriz();
    calcularPromedios();
    liberarMatriz();
    return 0;
}

void pedirDato(){
    cout<<"Digite el numero de aeropuertos: ";
    cin>>n;
    puntero_matriz=new double*[n];
    for(int i=0;i<n;i++){
        puntero_matriz[i]=new double[n];
    }
}
void llenarMatriz(){
    srand(time(0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                puntero_matriz[i][j]=0;
            }else{
                puntero_matriz[i][j]=100.0 + static_cast<double>(rand()) / RAND_MAX * (1500.0 - 100.0);
            }
        }
    }
}
void mostrarMatriz(){
    cout<<"\nMatriz de distancias: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<puntero_matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
void calcularPromedios(){
    double minPromedio;
    double minAeropuerto;
    cout<<"Promedio de distancias del por Aeropuerto"<<endl;
    for(int i=0;i<n;i++){
        double suma=0;
        for(int j=0;j<n;j++){
            if(i!=j){
                suma=suma+*(*(puntero_matriz+i)+j);
            }
        }
        double promFila;
        promFila=suma/(n-1);
        cout<<"Aeropuerto: "<<i+1<<promFila<<endl;
        if(i==0){ //base para comparar
            minPromedio=promFila;
            minAeropuerto=1;
        }else if(promFila<minPromedio){
            minPromedio=promFila;
            minAeropuerto=i+1;
        }
    }
    cout<<"\nEl aeropuerto con menor distancia promedio es el "<<minAeropuerto<< " con: " << minPromedio << " km." << endl;
}
void liberarMatriz(){
    for(int i=0;i<n;i++){
        delete[] puntero_matriz[i];
    }
    delete[] puntero_matriz;
}