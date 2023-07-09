#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string; // Cria artificialmente um tipo de dado string

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


int main(void) {

//FILE *arquivo_do_dia_anterior;
int espaço_estoque;
float saldo_do_caixa;
        string nome = NULL;
        string quantidade = NULL;
        string produto = NULL;


//iniciar_dia(arquivo_do_dia_anterior, &espaço_estoque, &saldo_do_caixa);



string comando = readLine();
string token = strtok(comando, " ");
    if((strcmp(token, "IP\0") == 0) && token != NULL){

        printf("Inserindo produto. Isso é apenas um protótipo\n");
        int i = 0;
        while((token = strtok(NULL, " ")) != NULL){
            
            switch (i) {
            case 0:
                nome = strdup(token);
                i++;
                break;
            
            case 1:
                quantidade = strdup(token);
                i++;
                break;
            case 2:
                produto = strdup(token);
                i++;
                break;
            }
        }

    }

    printf("%s\n%s\n%s\n",nome,quantidade,produto);
    free(nome);
    free(quantidade);
    free(produto);

  //fclose(arquivo_do_dia_anterior);
  return 0;
}