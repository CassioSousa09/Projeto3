#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"
int numTarefas = 0;


// função para cadastrar usuario
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

// função para salvar tarefas
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
// funcao para leitura de arquivo
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

void Filtro_Prioridade(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    int prioridade;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    printf("Tarefas com prioridade %d:\n", prioridade);
    int encontradas = 0;

    for (int i = 0; i < numTarefas; i++) {
      if (tarefas[i].prioridade == prioridade) {
        printf("Tarefa %d:\n", i + 1);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("Prioridade: %d\n\n", tarefas[i].prioridade);
        encontradas = 1;
      }
    }

    if (!encontradas) {
      printf("Nenhuma tarefa encontrada com a prioridade recebida %d.\n",
             prioridade);
    }
  } else {
    printf("Nao ha tarefas cadastradas para filtrar por prioridade.\n");
  }
}

void Filtro_Estado(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    char estado[20];
    printf("Digite qual o estado desejado: ");
    scanf(" %[^\n]s", estado);

    printf("Tarefas com estado %s:\n", estado);
    int encontradas = 0;

    for (int i = 0; i < numTarefas; i++) {
      if (strcmp(tarefas[i].estado, estado) == 0) {
        printf("Tarefa %d:\n", i + 1);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Estado: %s\n\n", tarefas[i].estado);
        encontradas = 1;
      }
    }

    if (!encontradas) {
      printf("Nenhuma tarefa encontrada com o estado %s.\n", estado);
    }
  } else {
    printf("Nao ha tarefas cadastradas para filtrar por estado.\n");
  }
}

// Função de comparação para qsort
int compararPrioridade(const void *a, const void *b) {
  return ((lista_de_tarefas *)b)->prioridade -
         ((lista_de_tarefas *)a)->prioridade;
}

// Funcao para filtrar tarefas por categorias e ordenar por prioridade

void filtrarCategoriaOrdenada(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    char categoria[50];
    printf("Digite a categoria desejada: ");
    scanf(" %[^\n]s", categoria);

    int encontradas = 0;
    lista_de_tarefas tarefasFiltradas[100];

    // Filtra tarefas por categoria
    for (int i = 0; i < numTarefas; i++) {
      if (strcmp(tarefas[i].categoria, categoria) == 0) {
        tarefasFiltradas[encontradas++] = tarefas[i];
      }
    }

    // Ordenar Tarefas Por prioridades
    qsort(tarefasFiltradas, encontradas, sizeof(lista_de_tarefas),
          compararPrioridade);

    // Exibir tarefas filtradas e ordenadas
    printf("Tarefas na categoria '%s', ordenadas por prioridade (da maior para "
           "a menor):\n",
           categoria);
    for (int i = 0; i < encontradas; i++) {
      printf("Tarefa %d:\n", i + 1);
      printf("Descricao: %s\n", tarefasFiltradas[i].descricao);
      printf("Categoria: %s\n", tarefasFiltradas[i].categoria);
      printf("Prioridade: %d\n", tarefasFiltradas[i].prioridade);
      printf("Estado: %s\n\n", tarefasFiltradas[i].estado);
    }

    if (!encontradas) {
      printf("Nenhuma tarefa encontrada na categoria %s.\n", categoria);
    }
  } else {
    printf("Nao ha tarefas cadastradas para filtrar por categoria.\n");
  }
}

void filtroPrioridadeECategoria(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    char categoria[50];
    printf("Digite a categoria desejada: ");
    scanf(" %[^\n]s", categoria);

    int prioridade;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridade);

    int encontradas = 0;
    lista_de_tarefas tarefasFiltradas[100];

    // Filtra tarefas por categoria
    for (int i = 0; i < numTarefas; i++) {
      if (strcmp(tarefas[i].categoria, categoria) == 0 &&
          tarefas[i].prioridade == prioridade) {
        tarefasFiltradas[encontradas++] = tarefas[i];
      }
    }
    // Ordena tarefas por prioridade
    qsort(tarefasFiltradas, encontradas, sizeof(lista_de_tarefas),
          compararPrioridade);

    // Exibe as tarefas filtradas e ordenadas
    printf("Tarefas na categoria '%s' e com prioridade %d:\n", categoria,
           prioridade);
    for (int i = 0; i < encontradas; i++) {
      printf("Tarefa %d:\n", i + 1);
      printf("Descricao: %s\n", tarefasFiltradas[i].descricao);
      printf("Categoria: %s\n", tarefasFiltradas[i].categoria);
      printf("Prioridade: %d\n", tarefasFiltradas[i].prioridade);
      printf("Estado: %s\n\n", tarefasFiltradas[i].estado);
    }

    if (!encontradas) {
      printf("Nenhuma tarefa encontrada na categoria %s e com prioridade %d.\n",
             categoria, prioridade);
    }
  } else {
    printf("Nao ha tarefas cadastradas para filtrar por categoria e "
           "prioridade.\n");
  }
}

void exportarPorPrioridade(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    int prioridade;
    printf("Digite a prioridade desejada para exportar as tarefas: ");
    scanf("%d", &prioridade);

    char nomeArquivo[50];
    printf("Digite o nome do arquivo de texto para exportar as tarefas: ");
    scanf(" %[^\n]s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo) {
      fprintf(arquivo, "Prioridade , Categoria , Estado , Descricao\n");

      for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade) {
          fprintf(arquivo, "%d | %s | %s | %s\n", tarefas[i].prioridade,
                  tarefas[i].categoria, tarefas[i].estado,
                  tarefas[i].descricao);
        }
      }

      fclose(arquivo);

      printf("Tarefas exportadas com sucesso para o arquivo '%s'.\n",
             nomeArquivo);
    } else {
      printf("Erro ao criar o arquivo de texto.\n");
    }
  } else {
    printf("Nao ha tarefas cadastradas para exportar por prioridade.\n");
  }
}

void exportarCto(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    char categoria[50];
    printf("Digite a categoria desejada para exportar as tarefas!: ");
    scanf(" %[^\n]s", categoria);

    char nomeArquivo[50];
    printf("Digite o nome do arquivo de texto para exportar as tarefas!: ");
    scanf(" %[^\n]s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo) {
      // Filtra tarefas por categoria
      lista_de_tarefas tarefasFiltradas[100];
      int encontradas = 0;
      for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
          tarefasFiltradas[encontradas++] = tarefas[i];
        }
      }
      // Ordena tarefas por prioridade
      qsort(tarefasFiltradas, encontradas, sizeof(lista_de_tarefas),
            compararPrioridade);
      // Exibe as tarefas filtradas e ordenadas
      fprintf(arquivo, "Prioridade | Categoria | Estado | Descricao\n");
      for (int i = 0; i < encontradas; i++) {
        fprintf(arquivo, "%d | %s | %s | %s\n", tarefasFiltradas[i].prioridade,
                tarefasFiltradas[i].categoria, tarefasFiltradas[i].estado,
                tarefasFiltradas[i].descricao);
      }
      fclose(arquivo);
      printf("Tarefas exportadas com sucesso para o arquivo '%s'.\n",
             nomeArquivo);
    } else {
      printf("Erro ao criar o arquivo de texto.\n");
    }
  } else {
    printf("Nao ha tarefas cadastradas para exportar por categoria.\n");
  }
}

void exportarPrioridadeCategoria(lista_de_tarefas *tarefas) {
  int numTarefas = 0;
  if (numTarefas > 0) {
    char categoria[50];
    printf("Digite a categoria desejada para exportar as tarefas: ");
    scanf(" %[^\n]s", categoria);

    int prioridade;
    printf("Digite a prioridade desejada para exportar as tarefas: ");
    scanf("%d", &prioridade);

    char nomeArquivo[50];
    printf("Digite o nome do arquivo de texto para exportar as tarefas: ");
    scanf(" %[^\n]s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo) {
      // Filtra tarefas por categoria
      lista_de_tarefas tarefasFiltradas[100];
      int encontradas = 0;

      for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0 &&
            tarefas[i].prioridade == prioridade) {
          tarefasFiltradas[encontradas++] = tarefas[i];
        }
      }

      // Ordena tarefas por prioridade
      qsort(tarefasFiltradas, encontradas, sizeof(lista_de_tarefas),
            compararPrioridade);

      // Exibe as tarefas filtradas e ordenadas
      fprintf(arquivo, "Prioridade | Categoria | Estado | Descricao\n");

      for (int i = 0; i < encontradas; i++) {
        fprintf(arquivo, "%d | %s | %s | %s\n", tarefasFiltradas[i].prioridade,
                tarefasFiltradas[i].categoria, tarefasFiltradas[i].estado,
                tarefasFiltradas[i].descricao);
      }

      fclose(arquivo);

      printf("Tarefas exportadas com sucesso!!! '%s'.\n", nomeArquivo);
    } else {
      printf("Erro ao criar o arquivo de texto.\n");
    }
  } else {
    printf("Nao foram econtradas tarefas cadastradas para exportar por "
           "prioridade e categoria.\n");
  }
}
