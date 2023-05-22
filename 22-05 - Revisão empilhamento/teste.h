#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

namespace std {
    typedef struct Aluno {
        int ra;
        char nome;
        Aluno *prox;
    };

    //funções

    Aluno *novoElemento (){
        aluno *aux = (Aluno *)malloc (sizeof(Aluno));
        if (aux == NULL) {
            printf ("Sem espaco na memoria");
            return NULL;
        }
        printf ("Digite o RA: ");
        scanf ("%d", &aux->ra);
        return aux;
    }

    void inserir (Aluno **ini, Aluno **f){
        aluno *aux = novoElemento ();
        aux->prox=NULL;
        if (*ini == NULL) {
            *ini = aux;
            *f = aux;
        } else {
            (*f)->prox = aux;
            *f = aux;
        }
    }

    Aluno *listarFila (Aluno **ini){
        aluno *aux = *ini;
        if (aux == NULL) return NULL;
        printf ("Ra: %d\n", aux->ra);
        listarFila (&aux->prox);
        return aux;
    }

    Aluno *listarPilha (Aluno *t){
        aluno *aux = t;
        if (aux == NULL) return NULL;
        else {
            printf ("RA: %d\n", aux->ra);
            listarPilha (aux->prox);
        }
        return aux;

    }

    

    void excluir (Aluno **ini, Aluno **f){
        if (*ini == NULL) printf ("Lista vazia");
        else if (*ini == *f){ ////////////////////////////////////
            free (*ini);
            *ini = NULL;
            *f = NULL;
        }
        else {
            Aluno *aux = *ini;
            *ini = (*ini)->prox;
            free (aux);
        }
    }

    void limparFila (Aluno **ini, Aluno **f){
        Aluno *aux = *ini;
        while (aux != NULL){
            *ini = (*ini)->prox;
            free (aux);
            aux = *ini;
        }
        *ini = NULL; *f = NULL;
    }

    void limparPilha (Aluno **t){
       while (*t != NULL){/////////////////////////////
        Aluno *aux = *t;
        *t = (*t)->prox;
        free (aux);
       }
    }


    Aluno empilhar (Aluno **ini, Aluno **f, Aluno **t){
        if (*ini == NULL) printf ("Fila vazia");
        else if (*ini == *f) {
            Aluno *aux = (Aluno *) malloc (sizeof(Aluno));
            aux->prox = NULL;
            aux->ra = (*ini)->ra;
            *t = aux;
        }
        else {
            Aluno *auxF = *ini;
            Aluno *aux2, *aux3;
            aux3 = (Aluno *) malloc (sizeof(Aluno));
            aux3->prox=NULL;
            aux2 = aux3; /////////////////////////////////////////////
            while (auxF != NULL){
                aux3->ra = auxF->ra;
                aux3 = (Aluno *)malloc (sizeof(Aluno));
                aux3->prox = aux2;
                aux2 = aux3;
                auxF = auxF->prox;
            }
            *t = aux3;
        }
    }

}
