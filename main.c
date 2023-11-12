#include "lab.h"
#include <stdio.h>
#include <string.h>

lista_de_tarefas tarefas[100];

int main() {
  int escolha;
  lista_de_tarefas lista_de_tarefas[100];
  leitura_arquivo(lista_de_tarefas, 100);
  do {
    printf("\nMenu:\n");
    printf("1. Cadastrar Tarefa\n");
    printf("2. Listar Tarefas\n");
    printf("3. Deletar Tarefa\n");
    printf("4. Alterar Tarefa\n");
    printf("5. Filtrar por Prioridade\n");
    printf("6.Filtrar por Estado\n");
    printf("7.Filtrar por Categoria Ordenada\n");
    printf("8. Filtrar por prioridade e categoria\n");
    printf("9. Exportar por prioridade\n");
    printf("10. Exportar Categoria\n");
    printf("11. Exportar Prioridade e categoria\n");
    printf("12. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
        //digite 1 para cadastro
    case 1:
      cadastroT(tarefas);
      break;
      //digite 2 para tarefas
    case 2:
      listarT(tarefas);
      break;
      //digite 3 para deletar
    case 3:
      deletarT(tarefas);
      break;
//digite 4 para realizar alterações
    case 4:
      alteracao(tarefas);
      break;
//digite 5 para filtro de prioridades 
    case 5:
      Filtro_Prioridade(tarefas);
      break;
    //digite 6 para filtro estado
    case 6:
      Filtro_Estado(tarefas);
      break;
//digite 7 para filtrar categoria ordenada
    case 7:
      filtrarCategoriaOrdenada(tarefas);
      break;
//digite 8 para filtro prioridade e categoria
    case 8:
      filtroPrioridadeECategoria(tarefas);
      break;
//digite 9 exportar por prioridade
    case 9:
      exportarPorPrioridade(tarefas);
      break;
//digite 10 exportar cto
    case 10:
      exportarCto(tarefas);
      break;
//digite 11 para exportar prioridade e categoria
    case 11:
      exportarPrioridadeCategoria(tarefas);
      break;
 //digite 12 para sair"
    case 12:
      escrever_arq(tarefas);
      printf("Saindo...\n");
      break;

    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (escolha != 4);

  return 0;
}
