# include <cstdlib>
# include <iostream>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;


Celula *inserirRecursivo(int dado, Celula *lista){
  if(lista && dado >= lista->dado){
    if(dado != lista->dado){ // Controle duplicidade
      // Avançar na lista
     lista->prox = inserirRecursivo(dado,lista->prox); 
    }
    return lista;
  }else{ // Cheguei no final da lista
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = dado;
    if(lista){
      novo->prox = lista;
    }else{
      novo->prox = NULL;
    }
    return novo;
  }
}

void exibirRecursivo(Celula *lista){
  if(lista){
    cout << lista->dado << endl;
    exibirRecursivo(lista->prox);
  }
}

int contarRecursivo(Celula *lista){
  if(lista){
    return 1 + contarRecursivo(lista->prox);
  }
  return 0;
}

Celula *localizarRecursivo(int dado, Celula *lista){
  if(lista){
    if(lista->dado == dado){
      return lista; 
    }
    return localizarRecursivo(dado, lista->prox);
  }
  return NULL;
}

Celula *inserir(int dado, Celula *lista){

    // alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    // depositar valores que vem do parâmetro
    novo->dado = dado;
    novo->prox = NULL;

    // testar se é o primeiro elemento a ser inserido
    if (!lista) { // if (lista == NULL)
        return novo; // retorna o novo elemento
    }

    // percorrer a estrutura até o final
    Celula *p;
    for(p = lista; p->prox != NULL; p = p->prox);
    {
      if(p->dado == novo->dado){
          cout << "Valor ja existente" << endl;
          return lista;
      }
    }

    // encadear e retornar

    p->prox = novo; 
    return lista; 
}


void exibir(Celula *lista) {
    for (Celula *p = lista; p != NULL; p = p->prox) {
        cout << p->dado << "\t";

    }
    cout << endl;
}

int contarLista(Celula *lista) {
    int total = 0;
    for (Celula *p = lista; p != NULL; p = p->prox) {
        total++;

    }
    return total;
}

bool estaNaLista(int dado, Celula *lista) {
    for (Celula *p = lista; p != NULL; p = p->prox) {
        if(p->dado == dado) {
            return true;
        }
    }
    return false;
}

// contar ocorrencias de um elemento na lista

int contador(int dado, Celula *lista) {
    int count = 0;
    for (Celula *p = lista; p != NULL; p = p->prox) {
        if(p->dado == dado) {
            count++;
        }
    }
    return count;
}

// verificar se a lista estã ordenada

bool estaOrdenada(Celula *lista){
  Celula *p = lista;

  while(p->prox != NULL){
    if(p->prox->dado < p->dado){
      return false;
    }
    p = p->prox;
  }
  return true;
}

// calcular a media dos elementos da lista
float media(Celula *lista) {
    int count = 0;
    int media = 0;

    for (Celula *p = lista; p != NULL; p = p->prox) count++, media += p->dado;

    return media/count;
}

void ordenarBolha(Celula *lista){
  int tmp;
  bool houveTroca;

  if(!lista || !lista->prox)
    return;

  do{
    houveTroca = false;
    for(Celula *p = lista; p->prox; p = p->prox){
      if(p->dado > p->prox->dado){
        tmp = p->dado;
        p->dado = p->prox->dado;
        p->prox->dado = tmp;
        houveTroca = true;
      }
    } 
  } while (houveTroca == true);
}



