#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
#include "lista.h"
 
int main() {
    srand(time(NULL));
    Celula *lista = NULL;
    for (int i = 0; i < 50; i++) {
        lista = inserirRecursivo(rand() % 100, lista);
    }
    cout << "Total de elementos: " << contarRecursivo(lista) << endl;
    exibirRecursivo(lista);

    int numero = 2;

    Celula *resposta = localizarRecursivo(numero, lista);
    if(resposta){
      cout << "O numero " << resposta->dado << "esta na lista" << endl;
    }else{
      cout << "O numero " << numero << " nao esta na lista" << endl; 
    }

    return 1;
}