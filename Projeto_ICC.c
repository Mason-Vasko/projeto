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

/*void iniciar_dia(const char* nomeArquivo, int *estoque, float *caixa){

    FILE *adda;
    adda = fopen(nomeArquivo,"r+");
    char linha[10];
    if (fgets(linha, sizeof(linha), adda) != NULL) {
            *estoque = atoi(linha);
        }

    if (fgets(linha, sizeof(linha), adda) != NULL) {
            *caixa = atof(linha);
        }


    
    if(adda == NULL){
      adda = fopen(nomeArquivo,"w+");
      chamar função para leitura do estoque
      chamar função para leitura do saldo
      
      }

    }
  //  else{


} */

void IP(int *maiorCodigoAtual, Produto *produtos){

  produtos[*maiorCodigoAtual].nome = readString();
  scanf("%d %f",&produtos[*maiorCodigoAtual].quantidade , &produtos[*maiorCodigoAtual].preco);
  while(getchar() != '\n');
  printf("item %d  \n%s\n%d\n%.2f\n",*maiorCodigoAtual,produtos[*maiorCodigoAtual].nome,produtos[*maiorCodigoAtual].quantidade,produtos[*maiorCodigoAtual].preco);
  *maiorCodigoAtual += 1;

}

void AE(Produto *produtos){
  int codigo_do_produto;
  int quantidade_adicionada;
  scanf("%d %d",&codigo_do_produto,&quantidade_adicionada);
  while(getchar() != '\n');
  
  produtos[codigo_do_produto].quantidade += quantidade_adicionada;
  printf("Foram adicionados %d produtos ao produto de codigo %d, agora temos %d produtos\n", quantidade_adicionada , codigo_do_produto ,produtos[codigo_do_produto].quantidade);

}

void MP(Produto *produtos){
  float novo_preco;
  int codigo_do_produto;
  scanf("%d %f",&codigo_do_produto,&novo_preco);
  while(getchar() != '\n');

  produtos[codigo_do_produto].preco = novo_preco;
  printf("%.2f é o novo preço\n",produtos[codigo_do_produto].preco);
}

void VE(Produto *produtos, float *saldo){
  int codigo_do_produto = -2;
  float preco_total = 0;
  while(codigo_do_produto != -1){
    scanf("%d",&codigo_do_produto);
    if(codigo_do_produto == -1){
      break;
    }
    printf("%s %.2f\n",produtos[codigo_do_produto].nome,produtos[codigo_do_produto].preco);
    preco_total += produtos[codigo_do_produto].preco;
    produtos[codigo_do_produto].quantidade--;
  }
  printf("Total: %.2f\n",preco_total);
  *saldo += preco_total;
  for(int i = 0; i < 50; i++){
    printf("-");
  }
  printf("\n");
}

void CE(Produto *produtos, int maiorCodigoAtual){

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

void FE(){

}

void programa_mercado(){



String comando;
int i = 1;
float saldo = 0;
int maiorCodigoAtual = 0; //É  o número de produtos adicionados -1
Produto *produtos = NULL;
produtos = (Produto*)malloc(sizeof(Produto)*1);

while(i){ //Esse loop para quando i for 0. Encerrar o dia transforma i em 0
 
  comando = readString();
  printf("%s\n",comando);

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
    FE();
    i = 0;
  }


}  


}

int main(void) {

  
  //iniciar_dia("caminho/do/arquivo.txt", int *estoque, float *caixa); 
  //talvez nao passar estoque e o caixa, já que esse é pra leitura, e se for pra escrita, chamar a função adequada, na real passar essas variaveis para leitura 
  //fazer passagem por referencia no estoque e no saldo do caixa

  programa_mercado();
  return 0;
}