# include <iostream>
using namespace std;

#include "lista.h"

int main(){
  Celula *lista = NULL;

  lista = inserir(5, lista);
  lista = inserir(5, lista);
  lista = inserir(10, lista);
  lista = inserir(25, lista);
  lista = inserir(20, lista);
  lista = inserir(15, lista);

  ordenarBolha(lista);

  cout << "Lista contem " << contarLista(lista) << " elementos\n";;
  exibir(lista);

  int numero;
  cout << "Digite um numero para pesquisa: ";
  cin >> numero;

  cout << numero << " esta na lista? " << estaNaLista(numero, lista) << endl; 

  cout << "a lista esta ordenada? " << estaOrdenada(lista) << endl;

  cout << "Media da lista: " << media(lista) << endl;

  return 1;
}