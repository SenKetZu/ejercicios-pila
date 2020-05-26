//PILAS SPD
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main() {
    int j=0;
    int k = 0;
    char resultado[50] = {'\0'};
    char ejercicios[50];
    int pila[50];   
    char car[6] = { '*','/','-','+','(',')'};                  
    cin >> ejercicios;
    int cantDig = strlen(ejercicios);
    pila[cantDig] = '\0';
    for (int i = 0; i < cantDig; i++) {
        if (isalpha(ejercicios[i]) || isdigit(ejercicios[i])) {
            resultado[k] = ejercicios[i];
            k++;
        }
        else if (ejercicios[i] == car[4]) {
            pila[j] = 5;
            j++;
            continue;
        }else if (ejercicios[i] == car[0]) {
            pila[j] = 1;
            j++;
        }else if (ejercicios[i] == car[1]) {
            pila[j] = 2;
            j++;
        }else if (ejercicios[i] == car[2]) {
            pila[j] = 3;
            j++;
        }  else if (ejercicios[i] == car[3]) {
            pila[j] = 4;
            j++;
        }
        else if (ejercicios[i]== car[5]) {
            while (pila[j-1]!= 5) {
                switch (pila[j-1])
                {
                case 1: {resultado[k] = car[0]; break; }
                case 2: {resultado[k] = car[1]; break; }
                case 3: {resultado[k] = car[2]; break; }
                case 4: {resultado[k] = car[3]; break; }
                default:
                    break;
                }
                k++;
                j--;
            }
            j--;
        }
        if (j>1) {
            for (int i = j; i >= 2; i--) {
                if (pila[j - 1] == 5 || pila[i - 2] == 5) {
                    break;
                }
                if (pila[j - 1] > pila[i - 2]) {
                    switch (pila[i - 2])
                    {
                    case 1: { resultado[k] = car[0];
                        break; }
                    case 2: { resultado[k] = car[1];
                        break; }
                    case 3: { resultado[k] = car[2];
                        break; }
                    case 4: { resultado[k] = car[3];
                        break; }
                    default:
                        break;
                    }
                    k++;
                    pila[i - 2] = pila[j - 1];
                    pila[j - 1] = 0;
                    j--;
                }
            }
        }
    }
    for (j=j-1; j >= 0;j--) {
        switch (pila[j])
        {
        case 1: {resultado[k] = car[0]; break; }
        case 2: {resultado[k] = car[1]; break; }
        case 3: {resultado[k] = car[2]; break; }
        case 4: {resultado[k] = car[3]; break; }
        default:
            break;
        }
        k++;
    }
    resultado[k] = '\0';
    cout << "\n" << "\n" << "\n";
    cout << resultado;
    return 0;
}