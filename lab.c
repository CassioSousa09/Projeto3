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
