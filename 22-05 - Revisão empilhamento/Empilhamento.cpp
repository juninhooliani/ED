using  namespace std;
#include "teste.h"


int main(){
    Aluno *ini = NULL, *fim = NULL, *topo = NULL;

    int op;
    
    do {
        printf ("#########################################################################\n");
        printf ("###   1 - Inserir | 2 - Listar Fila | 3 - Listar Pilha  | 4 - Excluir ###");
        printf("\n###   5 - Empilhar                                                    ###");
        printf("\n###   6 Limpar Fila | 7 - Limpar Pilha | 8 Limpar Tudo | 9 - Sair     ###");
        printf ("\n#########################################################################\n");
        scanf ("%d", &op);
        switch (op){
        case 1:
            inserir (&ini, &fim);
        break;
        case 2:
            listarFila (&ini);
        break;
        case 3:
            listarPilha (topo);
        break;
        case 4:
            excluir (&ini, &fim);
        break;
        case 5:
            limparPilha (&topo);
            empilhar (&ini, &fim, &topo);
        break;
        case 6:
            limparFila (&ini, &fim);
        break;
        case 7:
            limparPilha (&topo);
        break;
        case 8:
            limparFila (&ini, &fim);
            limparPilha (&topo);
        break;
        case 9:
            printf ("\nLimpando Elementos...\n");
            limparFila (&ini, &fim);
            limparPilha (&topo);
            printf ("\nSaindo...\n");
        break;
        default:
            printf ("Opcao invalida");
        break;
        }

    }while (op != 9);
}
