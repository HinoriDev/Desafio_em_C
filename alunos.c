#include <stdio.h>

#define MAXiMO_ALUNOS 100
#define TAMANHO_MAXIMO_NOME  50

    int menu() {
        int opcao;
        do{ 
            printf("\n========[ Menu]========\n");
            printf("[1] - Registrar Aluno \n");
            printf("[2] - Listar Aluno\n");
            printf("[3] - Salvar em Arquivo\n");
            printf("[4] - Carregar Arquivo\n");
            printf("[0] - Sair\n");
            printf("[Escolha uma Opção (0-4): ");
            scanf("%d", &opcao);
            while (getchar() != '\n');
            if(opcao < 0 || opcao > 4) {
                printf("Opção Invalida\n");
            }
        
        }while (opcao < 0 || opcao > 4);

        return opcao;
    }

    void registrar_aluno(char nomes[][TAMANO_MAXIMO_NOME], int notas[], int *total) {
        if(*total >= MAXIMO_ALUNOS) {
            printf("Limite de alunos atingido\n");
            return;
        }

        printf("Digite o nome do aluno: ");
        fgets(nomes[*total], TAMANHO_MAXIMO_NOME, stdin);

        printf("Digite a nota: ");
        scanf("%d", &notas[*total]);
        while (getchar() != '\n');

        (*total)++;
    }

int  main() {
    char nomes[MAXIMO_ALUNOS][TAMANHO_MAXIMO_NOME];
    int notas[MAXIMO_ALUNOS];
    int total = 0;
    int opcao;
    do { 

        opcao = menu();

        switch (opcao)
        {
            case 1:
                registrar_aluno(nomes, notas, &total);
                printf("Ultimo Valor: %s : %d", nomes[total - 1], notas[total - 1] );
                break;
            case 2:
                printf("Listar\n");
                break;
            case 3:
                printf("Salvar Arquivo\n");
                break;
            case 4:
                printf("Carregar Arquivo\n");
                break;
            case 0:
                printf("Sair\n");
                break;
        } 
     } while (opcao != 0);

    return 0;
}
