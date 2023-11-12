typedef struct {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char estado[50];
} lista_de_tarefas;
extern lista_de_tarefas tarefas[100];
// Função para cadastrar tarefa
void cadastroT(lista_de_tarefas *tarefas);
// Função para listar tarefas
void listarT(lista_de_tarefas *tarefas);
// Função para deletar tarefas
void deletarT(lista_de_tarefas *tarefas);
// Função para salvar tarefas
void salvarT(lista_de_tarefas *tarefas);
// Função para escrever no arquivo
void escrever_arq(lista_de_tarefas *tarefas);
// Função para alterar tarefas
void alteracao(lista_de_tarefas *tarefas);
// Função para filtrar por prioridade
void Filtro_Prioridade(lista_de_tarefas *tarefas);
// Função para filtrar por estado
void Filtro_Estado(lista_de_tarefas *tarefas);
// Função para filtrar por categoria e ordenar
void filtrarCategoriaOrdenada(lista_de_tarefas *tarefas);
// Função para filtrar por prioridade e categoria
void filtroPrioridadeECategoria(lista_de_tarefas *tarefas);
// Função para exportar por prioridade
void exportarPorPrioridade(lista_de_tarefas *tarefas);
// Função para exportar por categoria
void exportarCto(lista_de_tarefas *tarefas);
// Função para exportar por prioridade e categoria
void exportarPrioridadeCategoria(lista_de_tarefas *tarefas);
int leitura_arquivo(lista_de_tarefas tarefas[], int maxTarefas);