using namespace std;
#include "teste.h"


int main(){
    setlocale(LC_ALL, "Portuguese");

    Aluno *inicio = NULL, *fim = NULL;
    int op;
    do {
        printf("\n1- Inserir | 2- Listar\n3- Remover | 4- Limpar\n5- Sair\n");
        scanf("%d", &op);
        switch (op){
            case 1: //inserir
                inserir(&inicio, &fim);
            break;
            case 2: //lista
                listar(inicio);
            break;
            case 3: //remove
                excluir(&inicio, &fim);
            break;
            case 4: //limpa
                inicio = limpar (&inicio, &fim);
            break;
            case 5: //sai
                inicio = limpar (&inicio, &fim);
                printf ("\nSaindo...\n");
            break;
            default:
                printf ("\nOpção inválida\n");
            break;
        }
    }while (op != 5);
    

    return 0;
}