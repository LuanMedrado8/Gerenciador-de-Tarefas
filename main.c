#include <stdio.h>

#include <stdlib.h>

#include <string.h>
//estrutura para armazenar uma data
typedef struct sData {
  int dia;
  int mes;
  int ano;
}
data;
//estrutura para armazenar uma tarefa, aninhada com a estrutura data
typedef struct sTarefa {
  char nome[40];
  data datainicio;
  data datatermino;
  char status[40];
  int codigo;
}
tarefa;

tarefa t[100]; //Vetor para armazenar um conjunto de tarefas
int posicao = 0; //Variável de controle das posições do vetor

//Função para adicionar uma tarefa no vetor
void adiciona() {
  tarefa nt;
  //A função irá ler valores informados pelo usuário
  printf("\nInsira um nome para a sua tarefa: ");
  scanf("%40[^\n]", nt.nome);
  getchar(); //Função para limpar o buffer do teclado
  printf("Insira o dia de início: ");
  scanf("%d", & nt.datainicio.dia);
  getchar();
  printf("Insira o mes de início: ");
  scanf("%d", & nt.datainicio.mes);
  getchar();
  printf("Insira o ano de início: ");
  scanf("%d", & nt.datainicio.ano);
  getchar();
  printf("Insira o dia de término previsto: ");
  scanf("%d", & nt.datatermino.dia);
  getchar();
  printf("Insira o mes de término previsto: ");
  scanf("%d", & nt.datatermino.mes);
  getchar();
  printf("Insira o ano de término previsto: ");
  scanf("%d", & nt.datatermino.ano);
  getchar();
  //Sempre que uma tarefa é adicionada automaticamente a variável status recebe "Em andamento"
  strcpy(nt.status, "Em andamento"); 
  nt.codigo = posicao; //O código da tarefa será sempre a posição que ele se encontra no vetor
  system("clear"); //Função para limpar o que estiver sendo apresentado na tela 
  printf("Tarefa adicionada com sucesso!");

  t[posicao] = nt; //A primeira posição disponível do vetor recebe a tarefa
  posicao++; //Variável de controle é incrementada para informar qual é a nova primeira posição disponível

}

//Função que imprime uma posição especifica do vetor
void imprime(tarefa it) {
  printf("\nNome da tarefa: %s.\nData de início: %d/%d/%d.\nData de término: %d/%d/%d.\nStatus: %s.\nCódigo da tarefa: %d.\n", it.nome, it.datainicio.dia, it.datainicio.mes, it.datainicio.ano, it.datatermino.dia, it.datatermino.mes, it.datatermino.ano, it.status, it.codigo);
}

//Função que edita alguma informação de uma tarefa
void edita() {
  char op;
  int cod;
  system("clear");
  if (posicao == 0) { //Condicional para gerar uma mensagem de erro caso o usuário não tenha tarefas adicionadas
    printf("\nVocê não tem tarefas registradas!");
  } else if (posicao != 0) {
    printf("\nEssas são suas tarefas: \n");
    for (int i = 0; i < posicao; i++) { //Laço de repetição para imiprimir todas as posições preenchidas
      imprime(t[i]);
    } //Menu de edição
    printf("\n\nO que deseja editar?\n\n(1)Editar nome de uma tarefa\n(2)Editar data de início\n(3)Editar data de término\n(4)Editar status");
    printf("\n\nEscolha uma opção: ");
    scanf("%c", & op);
    getchar();

    if (op != '1' && op != '2' && op != '3' && op != '4') { //Erro caso usuário digite uma opção inválida
      system("clear");
      printf("\nErro ao editar, por favor tente novamente!");
    } else if (op == '1') { //Condicional para editar o nome de uma tarefa
      printf("\nDigite o código da tarefa que deseja editar o nome: ");
      scanf("%d", & cod); //A função usa o código da tarefa para indentificá-la
      getchar();
      if (cod >= posicao || cod < 0) { //Erro caso o usuário digite um código inválido
        system("clear");
        printf("\nTarefa não encontrada!");
      } else if (cod < posicao) {
        system("clear");
        printf("\nDigite o novo nome: ");
        scanf("%40[^\n]", t[cod].nome); //Novo nome sobrescreve o antigo
        getchar();
        system("clear");
        printf("\nO nome foi editado com sucesso!");
      }
    } else if (op == '2') {
      printf("\nDigite o código da tarefa que deseja editar a data de inicio: ");
      scanf("%d", & cod);
      getchar();
      if (cod >= posicao || cod < 0) {
        system("clear");
        printf("\nTarefa não encontrada!");
      } else if (cod < posicao) {
        system("clear");
        //Nova data de inicio sobrescreve a antiga
        printf("Insira o dia de início: ");
        scanf("%d", & t[cod].datainicio.dia);
        getchar();
        printf("Insira o mes de início: ");
        scanf("%d", & t[cod].datainicio.mes);
        getchar();
        printf("Insira o ano de início: ");
        scanf("%d", & t[cod].datainicio.ano);
        getchar();
        system("clear");
        printf("\nA data de inicio foi editada com sucesso!");
      }

    } else if (op == '3') {
      printf("\nDigite o código da tarefa que deseja editar a data de término: ");
      scanf("%d", & cod);
      getchar();
      if (cod >= posicao || cod < 0) {
        system("clear");
        printf("\nTarefa não encontrada!");
      } else if (cod < posicao) {
        system("clear");
        //Nova data de término sobrescreve a antiga
        printf("Insira o dia de término : ");
        scanf("%d", & t[cod].datatermino.dia);
        getchar();
        printf("Insira o mes de término : ");
        scanf("%d", & t[cod].datatermino.mes);
        getchar();
        printf("Insira o ano de término : ");
        scanf("%d", & t[cod].datatermino.ano);
        getchar();
        system("clear");
        printf("\nA data de término foi editada com sucesso!");
      }
    } else if (op == '4') {
      char es;
      printf("\nDigite o código da tarefa que deseja editar o status: ");
      scanf("%d", & cod);
      getchar();
      if (cod >= posicao || cod < 0) {
        system("clear");
        printf("\nTarefa não encontrada!");
      } else if (cod < posicao) {
        system("clear");
        //Usuário escolhe entre duas opções para mudar o status
        printf("\nDigte 1 para mudar o status para 'Em andamento' ou digite 2 para mudar o status para 'Concluída': ");
        scanf("%c", & es);
        getchar();
        if (es == '1') { //Muda status para "Em andamento"
          strcpy(t[cod].status, "Em andamento");
          system("clear");
          printf("\nO status foi editado com sucesso!");
        } else if (es == '2') { //Muda status para "Concluída"
          strcpy(t[cod].status, "Concluída");
          system("clear");
          printf("\nO status foi editado com sucesso!");
        } else if (es != '1' && es != '2') { //Erro se o usuário digitar uma opção inválida
          system("clear");
          printf("\nErro ao editar, por favor tente novamente!");
        }
      }
    }

  }
}

//Função que realiza a busca de uma ou mais tarefas pelo nome
void busca() {
  char busca[40];
  char nome[40]; //Variável de comparação
  int cont = 0;

  if (posicao == 0) {
    printf("\nVocê não tem tarefas registradas!");
  } else if (posicao != 0) {
    printf("\nDigite o nome da tarefa que deseja buscar: ");
    scanf("%39[^\n]", busca);
    getchar();
    system("clear");
    //Laço de repetição para verificar todos os nomes de todas as posições adicionadas
    for (int j = 0; j < posicao; j++) { 
      int i = 0;
      strcpy(nome, t[j].nome); //A variável de comparação recebe o nome da posição que está sendo analisada
      //Laço de repetição para verificar se cada posição da string é igual com a que o usuário digitou
      while (nome[i] == busca[i] && nome[i] != '\0' && busca[i] != '\0') {
        i++;
      }
      if (nome[i] == '\0' && busca[i] == '\0') { //Caso seja validada a igualdade, é impressa a tarefa desejada
        printf("\nAqui está a tarefa que você buscou: \n");
        imprime(t[j]);
        cont++;
      }
    }
    if (cont == 0) { //Erro caso nenhuma posição tenha igualdade com o nome que o usuário buscou
      printf("\nA tarefa que você buscou não foi encontrada.\nVerifique se você colocou o nome corretamente.");
    }
  }
}

//Função que remove uma tarefa
void Remove() {
  int cod;
  system("clear");
  if (posicao == 0) {
    printf("\nVocê não tem tarefas registradas!");
  } else if (posicao != 0) {
    printf("\nEssas são suas tarefas: \n");
    for (int i = 0; i < posicao; i++) {
      imprime(t[i]);
    }
    printf("\nDigite o código da tarefa que deseja remover: ");
    scanf("%d", & cod);
    getchar();
    if (cod >= posicao || cod < 0) {
      system("clear");
      printf("\nTarefa não encontrada!");
    } else if (cod == posicao - 1) { //Condicional que remove uma tarefa no fim do Vetor
      posicao--;
      system("clear");
      printf("A tarefa foi removida com sucesso!");
    } else if (cod != posicao - 1) { //Condicional que remove uma tarefa no meio ou no inicio
      //Laço de repetição que pega a posição seguinte da que será removida e a realoca na posição anterior
      //Também será feito com todas as posições seguintes para manter o vetor ordenado
      for (int i = cod; i < posicao - 1; i++) { 
        t[cod] = t[cod + 1];
        t[cod].codigo = cod; //Atribuição do novo código da tarefa realocada
        cod++;
      }
      posicao--;
      system("clear");
      printf("A tarefa foi removida com sucesso!");
    }
  }
}

//Função para executar cada funcionalidade do programa
void procedimentos(char opcao) {

  if (opcao == 'A' || opcao == 'a') { //condicional para adicionar
    adiciona();

  } else if (opcao == 'l' || opcao == 'L') { //condicional para imprimir todas as tarefas adicionadas
    system("clear");
    if (posicao == 0) {
      printf("\nVocê não tem tarefas registradas!");
    } else if (posicao != 0) {
      printf("\nEssas são suas tarefas: \n");

      for (int i = 0; i < posicao; i++) {
        imprime(t[i]);
      }
    }
  } else if (opcao == 'E' || opcao == 'e') { //condicional para editar
    edita();
  } else if (opcao == 'B' || opcao == 'b') { //condicional para buscar
    busca();
  } else if (opcao == 'R' || opcao == 'r') { //condicional para remover
    Remove();
  } else
    system("clear");
}

//Função para apresentar o menu de opções
void menu() {
  char opcao;
  printf("\nGERENCIADOR DE TAREFAS\n");
  printf("\nOlá seja bem-vindo! ");
  do { // laço de repetição que roda o programa até a condição de parada ser atingida
    printf("\n");
    printf("\nO que você gostaria de fazer?\n");
    printf("\nA - Adicionar uma tarefa \n");
    printf("B - Buscar uma tarefa\n");
    printf("E - Editar uma tarefa\n");
    printf("R - Remover uma tarefa\n");
    printf("L - Lista com todas as tarefas\n");
    printf("S - Sair\n");
    printf("\n");

    printf("Escolha uma opcao: ");
    scanf("%c", & opcao);
    getchar();
    system("clear");

    if (opcao == 's') { //condicional que volta para a main
      break;
    } else procedimentos(opcao);
  } while (opcao != 'S'); //Condição de parada
}

int main(void) {
  menu();
  printf("Obrigado por usar nosso programa e volte sempre!"); //Mensagem de agradecimento
  return 0;
}