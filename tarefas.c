#include <stdio.h>

#define MAXIMO_TAREFAS 100
#define TAMANHO_MAXIMO_DESCRICAO 100

int menu() {
    int opcao;
    do{
        printf("\n======[ Menu ]=====\n");
        printf("[1] - Adicionar Nova Tarefa\n");
        printf("[2] - Listar Todas as Tarefas\n");
        printf("[3] - Listar Tarefas Pendentes\n");
        printf("[4] - Marcar Tarefa como Concluída\n");
        printf("[0] - Sair\n");
        printf("[1] - Escolha uma opção (0-4): ");
        scanf("%d", &opcao);
        while (getchar() != '\n');
        if(opcao < 0 || opcao > 4) {
            printf("opção invalida\n");
        }
    } while (opcao < 0 || opcao > 4 );

    return opcao;
}

int carregar_arquivo(char tarefas[][TAMANHO_MAXIMO_DESCRICAO], int concluido[]) {
    FILE *arquivo = fopen("tarefas.txt", "r"); // primeiro o FILE para a leitura do arquivo, depois o *arquivo que é a direção que o file aponta o que ira salvar e por ultimo o = fopen que ira abrir o arquivo ("endereço do arquivo", "modo que ira abrir o arquivo").
    if(arquivo == NULL) {
        printf("Arquivo 'tarefas.txt' não encontrado\n");
    }

    int total = 0;
    while (fscanf(arquivo, "%100[^;];%d\n", tarefas[total], &concluido[total]) == 2)
    {
        total++
        if(total >- MAXIMO_TAREFAS) {
            break;
        }
    }

    fclose(arquivo);
    return total;
}

void listar_tarefas(char tarefas[][TAMANHO_MAXIMO_DESCRICAO], int concluido [], int total) {
    if(total == 0) {
        printf("Nenhuma Tarefa.\n");
        return;
    }

    printf("\n=====[ LISTA DE TAREFAS ]=====\n");
    for(int indice = 0;indice < total;indice++) {
        if(concluido[indice] == 0) {
            printf("[PENDENTE] ");
        } else {
            printf("[CONCLUIDO] ");
        }
        printf("%s\n", tarefas[indice]);
    }
}

void salvar_arquivo(char tarefas[][TAMANHO_MAXIMO_DESCRICAO], int concluido [], int total) {
    FILE *arquivo = fopen("tarefa.txt", "w");
    if(arquivo != NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for(int indice = 0;indice < total;indice++) {
        fprintf(arquivo, "%s;%d\n", tarefas[indice], concluido[indice]);
    }
    fclose(arquivo);
}

void registrar_tarefa(char tarefas[][TAMANHO_MAXIMO_DESCRICAO], int concluido[], int *total) {
    if(*total >= MAXIMO_TAREFAS) {
        printf("Limite de Tarefas Antingido\n");
        return;
    }

    printf("Descreva a Tarefa: ");
    fgets(tarefas[*total], TAMANHO_MAXIMO_DESCRICAO, stdin);

    int indice =0;
    while (tarefas[*total][indice] != '\0')
    {
        if(tarefas[*total][indice] == '\n') {
            tarefas[*total][indice] == '\0';
            break;
        }
        indice++;
    }
    concluido[*total] = 0;
    (*total)++;
}

int main() {
    char tarefas[MAXIMO_TAREFAS][TAMANHO_MAXIMO_DESCRICAO];
    int concluido[MAXIMO_TAREFAS];
    int total = 0 
    int opcao;
    total = carregar_arquivo(tarefas, concluido);
    do {
        opcao = menu();
        switch (opcao)
        {
            case 1 :
                registrar_tarefa(tarefas, concluido, &total);
                salvar_arquivos(tarefas, concluido, total);
                break;
            case 2 :
                listar_tarefas(tarefas, concluido, total);
                break;
            case 3 :
                break;
            case 4 :
                break;
            case 0 :
                break;
        }
    } while (opcao != 0);

    return 0;
}