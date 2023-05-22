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
        Aluno *prox;
    };

    //funções

    Aluno *novoElemento (){
        Aluno *aux = (Aluno *)malloc (sizeof(Aluno));
        if (aux == NULL) {
            printf ("Sem espaco na memoria");
            return NULL;
        }
        printf ("Digite o RA: ");
        scanf ("%d", &aux->ra);
        return aux;
    }

    Aluno *buscarExcluir (Aluno *ini, Aluno *f, int pRa){
        Aluno *aux = ini;
        while((aux != NULL) && (aux->prox->ra != pRa)){
            aux = aux->prox;
        }
        if (aux == NULL) return NULL;
        return aux;
    }


    Aluno *buscarInserir (Aluno *ini, Aluno *f, int pRa){
        Aluno *aux = ini;
        while((aux != NULL) && (aux->ra != pRa)){
            aux = aux->prox;
        }
        if (aux == NULL) return NULL;
        return aux;
    }

    void inserir (Aluno **ini, Aluno **f){
        if (*ini == NULL){
            Aluno *aux = novoElemento();
            *ini = aux;
            (*ini)->prox = NULL;
            *f = aux;
        }
        else if(*ini == *f){
            Aluno *aux = novoElemento();
            (*ini)->prox = aux;
            *f = aux;
            aux->prox = NULL;
        } else {
            int raprocurado;
            Aluno *local;
                printf ("Digite o RA a ser buscado: ");
                scanf ("%d", &raprocurado);
                local = buscarInserir(*ini, *f, raprocurado);
                if (local == NULL) printf ("Elemento não encontrado, digite novamente");
                else {
                    Aluno *aux = novoElemento();
                    aux->prox = local->prox;
                    local->prox = aux;
                }
        }
    }

    void listar (Aluno *ini){
        if (ini == NULL) printf ("Lista Vazia");
        else {
            Aluno *aux = ini;
            while(aux != NULL){
                printf ("RA: %d\n", aux->ra);
                aux = aux->prox;
            }
        }
    }

    void excluir (Aluno **ini, Aluno **f){
        if (*ini == NULL) printf ("Lista Vazia");
        else if (*ini == *f){
            free (*ini);
            *ini = NULL;
            *f = NULL;
        } 
        else {
            int raP;
            printf ("Digite o RA a ser removido: ");
            scanf ("%d", &raP);
            if ((*ini)->ra == raP){
                Aluno *aux = *ini;
                *ini = (*ini)->prox;
                free (aux);
            }
            else {
                Aluno *local = buscarExcluir(*ini, *f, raP);
                if (local == NULL) printf ("Elemento nao encontrado, digite novamente");
                else {
                    Aluno *aux = local->prox;
                    local->prox = aux->prox;
                    free (aux);
                }
            }
        }
    }

    Aluno *limpar (Aluno **ini, Aluno **f){
        
        if (*ini == NULL) return NULL;
        else {
                Aluno *aux = *ini;
                *ini = (*ini)->prox;
                free (aux);
                *ini = limpar (&(*ini)->prox, &*f);
        }
        return *ini;
        
    }



}


