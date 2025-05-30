#include <cstddef>
typedef struct no {
    int dado;
    struct no *prox;
} Celula;
 
bool contem(int elemento, Celula *lista){
    for (Celula *p = lista; p; p = p->prox){
        if (p->dado == elemento){
            return true;
        }
    }
    return false;
}

void exibir(Celula *lista) {
    if (lista == NULL) {
        cout << "Lista Vazia" << endl;
    } else {
        for (Celula *p = lista; p; p = p->prox) {
            cout << p->dado << "\t";
        }
        cout << endl;
    }   
}



Celula *inserir (int dado, Celula *lista){
    // alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    // depositar valores que vem do parâmetro
    novo->dado = dado;
    novo->prox = NULL;

    // testar se eh o primeiro elemento a ser interido
    if (!lista) {
        return novo;
    }

    // percorrer a estrutura ate o final
    Celula *p;
    for (p = lista; p->prox; p = p->prox);

    // encadear e retornar
    p->prox = novo;
    return lista;
}

void exibirIguais(Celula *lista1, Celula *lista2){
    Celula *lista3;
    for (Celula *p1 = lista1; p1; p1 = p1->prox){
        for (Celula *p2 = lista2; p2; p2 = p2->prox){
            if(p1->dado == p2->dado && ! contem(p1->dado,lista3)){
                lista3 = inserir(p1->dado,lista3);
            }
        }
    }
    exibir(lista3);
}

// Remove o primeiro nó com valor igual a 'dado'
Celula* excluir(int dado, Celula* lista) {
    Celula *p = lista;
    Celula *pR = NULL;

    for (; p; p = p->prox) {
        if (dado == p->dado) {
            if (p == lista) {
                lista = lista->prox;
                free(p);
                return lista;
            }

            if (!p->prox) {
                pR->prox = NULL;
                free(p);
                return lista;
            }

            pR->prox = p->prox;
            free(p);
            return lista;
        }
        pR = p;
    }

    return lista; 
}

Celula *removePares(Celula *lista) {
    Celula *p = lista;

    while (p != NULL) {
        if (p->dado % 2 == 0) {
            lista = excluir(p->dado, lista);
            p = lista;  
        } else {
            p = p->prox;
        }
    }

    return lista;
}

Celula *unirListas(Celula *lista1, Celula *lista2){
    Celula *p;

    for (p = lista1; p->prox; p = p->prox);

    p->prox = lista2;

    return lista1;
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

void limparLista(Celula *lista){
    Celula *atual = lista;
    Celula *prox;

    for (; atual!=NULL;){
        prox=atual->prox;
        free(atual);
        atual = prox;
    }
        
}


