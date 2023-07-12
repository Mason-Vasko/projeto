#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String; // Cria artificialmente um tipo de dado string

typedef struct produto{

  char *nome;
  int quantidade;
  float preco;

}Produto;


char *readLine() { // Essa função lê a entrada até o usuário pressionar enter,
                   // sem deixar poluição na entrada
  char *string = NULL;
  char currentInput;
  int index = 0;
  do {
    // cada caractere obtido da entrada padrão é direcionado para a inserção
    // atual (current input), em seguida é alocado espaço adequado na string
    // para armazenar esse caractere.
    currentInput = (char)getchar();
    string = (char *)realloc(string, sizeof(char) * (index + 1));
    string[index] = currentInput;
    index++;
    if (currentInput ==
        '\r') { // O /r costuma vir antes do /n em sistemas windows.
      currentInput = (char)getchar();
    }
  } while ((currentInput != '\n') && (currentInput != EOF));
  string[index - 1] = '\0'; // substitui o caracter final (a quebra de página)
                            // por /0 para oficializar a string
  return string;
}


char *readString() { // Essa função lê a entrada até o usuário pressionar enter,
                   // sem deixar poluição na entrada
  char *string = NULL;
  char currentInput;
  int index = 0;
  do {
    // cada caractere obtido da entrada padrão é direcionado para a inserção
    // atual (current input), em seguida é alocado espaço adequado na string
    // para armazenar esse caractere.
    currentInput = (char)getchar();
    string = (char *)realloc(string, sizeof(char) * (index + 1));
    string[index] = currentInput;
    index++;
    if (currentInput ==
        '\r') { // O /r costuma vir antes do /n em sistemas windows.
      currentInput = (char)getchar();
    }
  } while ((currentInput != ' ') && (currentInput != EOF) && (currentInput != '\n'));
  string[index - 1] = '\0'; // substitui o caracter final (a quebra de página)
                            // por /0 para oficializar a string
  return string;
}

/*void iniciar_dia(FILE *adda, int *estoque, float *caixa){

    adda = fopen("dia_anterior.txt","r+");
    if(adda == NULL){
        adda = fopen("dia_anterior.txt","w+");
        scanf("%d",estoque);
        scanf("%f",caixa);
        while(getchar() != '\n'); //limpa o /n que polui a entrada

    }
  //  else{


} */

void IP(int *maiorCodigoAtual, Produto *produtos){

  produtos = (Produto*)realloc(produtos, sizeof(Produto)* ((*maiorCodigoAtual) + 1) );
  produtos[*maiorCodigoAtual].nome = readString();
  scanf("%d %f",&produtos[*maiorCodigoAtual].quantidade , &produtos[*maiorCodigoAtual].preco);
  while(getchar() != '\n');
  printf("item %d  \n%s\n%d\n%f\n",*maiorCodigoAtual,produtos[*maiorCodigoAtual].nome,produtos[*maiorCodigoAtual].quantidade,produtos[*maiorCodigoAtual].preco);
  *maiorCodigoAtual += 1;

}

void AE(){

}

void MP(){

}

void VE(){

}

void CE(){

}

void CS(){

}

void FE(){

}

void programa_mercado(){

String comando;
int i = 1;
int maiorCodigoAtual = 0; //É  o número de produtos adicionados -1
Produto *produtos;

while(i){ //Esse loop para quando i for 0. Encerrar o dia transforma i em 0
 
  comando = readString();
  printf("%s\n",comando);

  if(strcmp(comando, "IP") == 0){
    IP(&maiorCodigoAtual, produtos);
  }
  else if(strcmp(comando, "AE") == 0){
    AE();
  }
  else if(strcmp(comando, "MP") == 0){
    MP();
  }
  else if(strcmp(comando, "VE") == 0){
    VE();
  }
  else if(strcmp(comando, "CE") == 0){
    CE();
  }
  else if(strcmp(comando, "CS") == 0){
    CS();
  }
  else if(strcmp(comando, "FE") == 0){
    FE();
    i = 0;
  }


}  


}

int main(void) {

  programa_mercado();
  return 0;
}