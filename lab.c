#include "lab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista_de_tarefas tarefas[100];

//função para cadastrar usuario
void cadastroT(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas < 100) {
    lista_de_tarefas Tarefas;

    printf("Digite a descricao da tarefa: ");
    scanf(" %[^\n]s", Tarefas.descricao);

    printf("Digite a categoria da tarefa: ");
    scanf(" %[^\n]s", Tarefas.categoria);

    printf("Digite a prioridade da tarefa (um numero inteiro): ");
    scanf("%d", &Tarefas.prioridade);

    tarefas[numTarefas] = Tarefas;
    numTarefas++;
    printf("Tarefa cadastrada com sucesso!\n");
  } else {
    printf("A lista de tarefas esta cheia. Não eh possivel cadastrar mais "
           "tarefas.\n");
  }
}

//função para salvar tarefas
void salvarT(lista_de_tarefas *tarefas) {
  FILE *arquivo = fopen("tarefas_salvas.txt", "w");
  int numTarefas = 0;
  if (arquivo) {
    for (int i = 0; i < numTarefas; i++) {
      fprintf(arquivo, "%s;%s;%d;%s\n", tarefas[i].descricao,
              tarefas[i].categoria, tarefas[i].prioridade, tarefas[i].estado);
    }

    fclose(arquivo);

    printf("Tarefas salvas com sucesso no arquivo 'tarefas_salvas.txt'.\n");
  } else {
    printf("Erro ao criar o arquivo 'tarefas_salvas.txt'.\n");
  }
}
// funcao para escrever no arquivo
void escrever_arq(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  int tamanho = numTarefas;
  FILE *binario;
  binario = fopen("file.bin", "wb");
  if (binario) {
    fwrite(tarefas, sizeof(lista_de_tarefas), tamanho, binario);
    fclose(binario);
  }
}
//funcao para leitura de arquivo
int leitura_arquivo(lista_de_tarefas tarefas[], int maxTarefas) {
  FILE *binario = fopen("file.bin", "rb");
  int cont = 0;
  if (binario) {
    while (cont < maxTarefas &&
           fread(tarefas, sizeof(lista_de_tarefas), 1, binario) == 1) {
      cont = cont + 1;
      fclose(binario);
    }
  }
}

void listarT(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < numTarefas; i++) {
      printf("Tarefa %d:\n", i + 1);
      printf("Descricao: %s\n", tarefas[i].descricao);
      printf("Categoria: %s\n", tarefas[i].categoria);
      printf("Prioridade: %d\n\n", tarefas[i].prioridade);
    }
  } else {
    printf("Nao ha tarefas cadastradas.\n");
  }
}

void deletarT(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    int indice;
    printf("Digite o numero da tarefa que deseja deletar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numTarefas) {
      for (int i = indice - 1; i < numTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
      }

      numTarefas--;

      printf("Tarefa deletada com sucesso!\n");
    } else {
      printf("Indice invalido. Por favor, insira um indice valido.\n");
    }
  } else {
    printf("Nao ha tarefas cadastradas para deletar.\n");
  }
}

void alteracao(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    int indice;
    printf("Digite qual tarefa deseja alterar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numTarefas) {
      int opcao;
      printf("Escolha o item a ser alterado:\n");
      printf("1. Descricao\n");
      printf("2. Categoria\n");
      printf("3. Prioridade\n");
      printf("Digite o numero da opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        printf("Digite a nova descricao: ");
        scanf(" %[^\n]s", tarefas[indice - 1].descricao);
        break;
      case 2:
        printf("Digite a nova categoria: ");
        scanf(" %[^\n]s", tarefas[indice - 1].categoria);
        break;
      case 3:
        printf("Digite a nova prioridade: ");
        scanf("%d", &tarefas[indice - 1].prioridade);
        break;
      default:
        printf("Opcao invalida.\n");
        return;
      }

      printf("Tarefa alterada com sucesso!\n");
    } else {
      printf("Indice nao identificado. Por favor, insira um indice valido.\n");
    }
  } else {
    printf("Nao ha tarefas cadastradas para alterar.\n");
  }
}

