/*
Gustavo Blois - 13688162
Livia Cardoso - 11299940
João Vitor - 13751131

*/



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


void IP(int *maiorCodigoAtual, Produto *produtos){
  //insere um produto novo, lendo seu nome, sua quantidade e seu preço

  produtos[*maiorCodigoAtual].nome = readString();
  scanf("%d %f",&produtos[*maiorCodigoAtual].quantidade , &produtos[*maiorCodigoAtual].preco);
  while(getchar() != '\n');
  *maiorCodigoAtual += 1;

}

void AE(Produto *produtos){
  int codigo_do_produto;
  int quantidade_adicionada;
  scanf("%d %d",&codigo_do_produto,&quantidade_adicionada);
  //Pede o codigo do produto ao usuario e o numero de itens que serão adicionados ao estoque
  while(getchar() != '\n');
  
  produtos[codigo_do_produto].quantidade += quantidade_adicionada;
  
}

void MP(Produto *produtos){
  //Modifica o preço
  float novo_preço;
  int codigo_do_produto;
  scanf("%d %f",&codigo_do_produto,&novo_preço);
  while(getchar() != '\n');

  produtos[codigo_do_produto].preco = novo_preço;
}

void VE(Produto *produtos, float *saldo){
  //Lê a entrada do usuário até encontrar o -1. Ao final da execução o preço dos produtos vendidos é adicionado ao saldo
  int codigo_do_produto = -2; //É inicializado com -2 porque qualquer numero de -1 até infinito positivo é relevante para a execução
  float preco_total = 0;
  while(codigo_do_produto != -1  ){
    scanf("%d",&codigo_do_produto);
    if(codigo_do_produto == -1){
      break;
    }
    if(produtos[codigo_do_produto].quantidade > 0){
    printf("%s %.2f\n",produtos[codigo_do_produto].nome,produtos[codigo_do_produto].preco);
    preco_total += produtos[codigo_do_produto].preco;
    produtos[codigo_do_produto].quantidade--;
    }
  }
  printf("Total: %.2f\n",preco_total);
  *saldo += preco_total;
  for(int i = 0; i < 50; i++){
    printf("-");
  }
  printf("\n");
}

void CE(Produto *produtos, int maiorCodigoAtual){
  //percorre todos os itens e os imprime na tela
  for(int i = 0; i < maiorCodigoAtual; i++){
    printf("%d %s %d\n",i,produtos[i].nome,produtos[i].quantidade);
  }



  for(int i = 0; i < 50; i++){
    printf("-");
  }
  printf("\n");

}

void CS(float *saldo){
  printf("Saldo: %.2f\n",*saldo);  
  for(int i = 0; i < 50; i++){
    printf("-");
  }
  printf("\n");
}

void FE(Produto *produtos, int maiorCodigoAtual, float saldo){
  //imprime no arquivo a quantidade de itens (maiorCodigoAtual), o saldo e as informações de cada produto
  FILE *arq;
  arq = fopen("dia_anterior.txt","w+");
  fprintf(arq,"%d\n%f\n",maiorCodigoAtual,saldo);
  for(int i = 0; i < maiorCodigoAtual; i++){
    fprintf(arq,"%s %d %f\n",produtos[i].nome,produtos[i].quantidade,produtos[i].preco);
  }

  fclose(arq);

}


void programa_mercado(){

String comando;
int i = 1;
float saldo = 0;
int n_estoque;
int maiorCodigoAtual = 0; //É  o número de produtos adicionados -1
Produto *produtos = NULL;
produtos = (Produto*)malloc(sizeof(Produto)*1);

FILE *arq;
arq = fopen("dia_anterior.txt","r+");
//inicia um arquivo para ler
if(arq == NULL){
//se o arquivo não existir, o usuário que deve fornecer as informações básicas
  scanf("%d",&n_estoque);
  scanf("%f",&saldo);
}
else{
//se o arquivo existir, vai carregar as informações do arquivo para as variáveis do programa
  fscanf(arq,"%d",&maiorCodigoAtual);
  fscanf(arq,"%f",&saldo);

  produtos = (Produto*)realloc(produtos, sizeof(Produto)* ((maiorCodigoAtual) + 1));
  for(int j = 0; j < maiorCodigoAtual; j++){
    produtos[j].nome = malloc(sizeof(char)*100);
    fscanf(arq,"%s %d %f",produtos[j].nome,&produtos[j].quantidade,&produtos[j].preco);
  }
  fclose(arq);
}






while(i){ //Esse loop para quando i for 0. Encerrar o dia transforma i em 0
 
  comando = readString();
//Até o loop parar, vai pegar do usuário um comando e chamar uma função a depender do comando digitado
  if(strcmp(comando, "IP") == 0){
    produtos = (Produto*)realloc(produtos, sizeof(Produto)* ((maiorCodigoAtual) + 1));
    IP(&maiorCodigoAtual, produtos);
  }
  else if(strcmp(comando, "AE") == 0){
    AE(produtos);
  }
  else if(strcmp(comando, "MP") == 0){
    MP(produtos);
  }
  else if(strcmp(comando, "VE") == 0){
    VE(produtos,&saldo);
  }
  else if(strcmp(comando, "CE") == 0){
    CE(produtos,maiorCodigoAtual);
  }
  else if(strcmp(comando, "CS") == 0){
    CS(&saldo);
  }
  else if(strcmp(comando, "FE") == 0){
    FE(produtos,maiorCodigoAtual,saldo);
    free(produtos);
    i = 0;
  }


}  


}

int main(void) {

  programa_mercado();
  return 0;
}