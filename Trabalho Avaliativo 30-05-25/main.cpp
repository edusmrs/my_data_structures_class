#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "lista.h"

int main() {
    srand(time(NULL));
    Celula *lista1 = NULL;
    Celula *lista2 = NULL;

    for (int i = 0; i < (rand() % 75 + 25); i++) {
        lista1 = inserir(rand() % 100, lista1);
        lista2 = inserir(rand() % 100, lista2);
    }

    cout << "======================== LISTA 1 ========================"<< endl;
    cout << "\n"<< endl;
    exibir(lista1);
    cout << "======================== LISTA 2 ========================"<< endl;
    cout << "\n"<< endl;
    exibir(lista2);
    
    
    
    Celula *lista3 = unirListas(lista1, lista2);


    cout << "======================== LISTA UNIÃO ========================"<< endl;
    cout << "\n"<< endl;
    exibir(lista3);
    

    cout << "======================== LISTA UNIÃO ORDENADA ========================"<< endl;
    cout << "\n"<< endl;
    
    ordenarBolha(lista3);
    exibir(lista3);

    cout << "======================== LISTA UNIÃO DELETADO ========================"<< endl;
    cout << "\n"<< endl;
    
    limparLista(lista3);
    lista3 = NULL;
    exibir(lista3);

    return 1;
}