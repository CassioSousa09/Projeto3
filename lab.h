typedef struct {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char estado[50];
} lista_de_tarefas;

void cadastroT();
void listarT();
void deletarT();
void salvarT();
void escrever_arq();
void alteracao();
void Filtro_Prioridade();
void Filtro_Estado();
void filtrarCategoriaOrdenada();
void filtroPrioridadeECategoria();
void exportarPorPrioridade();
void exportarCto();
void exportarPrioridadeCategoria();
int leitura_arquivo(lista_de_tarefas tarefas[], int maxTarefas);
