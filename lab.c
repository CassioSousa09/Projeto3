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