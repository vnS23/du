#include <stdio.h>
#include <stdlib.h>

typedef struct {

int num;
int saldo;
char nome[99];

}Conta;

int RegConta(Conta conta[], int posi){
int achou = 0;
int num_conta;

    printf("Digite o numero da conta a ser incluida: ");
    scanf("%d", &num_conta);

    for(int i = 0; i< posi; i++){
        if(num_conta == conta[i].num){
            achou = 1;
        }
    }
    if(achou == 1){
        printf("Ja existe conta cadastrada com esse numero \n");
    }else{
        conta[posi].num = num_conta;
        printf("Digite o nome do cliente: ");
        scanf("%s", conta[posi].nome);
        printf("Digite o saldo: ");
        scanf("%d", &conta[posi].saldo);
        printf("\nConta cadastrada com sucesso\n");
        posi++;
    }
    return posi;
}

void consultaCliente(Conta conta[], int posi){
    char nome_cliente[99];
    int achou = 0;

    printf("Digite o nome do cliente a ser consultado: ");
    scanf("%s", nome_cliente);

    for(int i = 0; i < posi; i++){
        if(strcmp(nome_cliente, conta[i].nome) == 0){
            printf("num: %d\nsaldo: %d\n", conta[i].num, conta[i].saldo);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("\nNao existe conta cadastrada para este cliente\n");
    }
}

excluimenorSaldo(Conta conta[], int posi){
    int menor_saldo = conta[0].saldo;
    int i = 1, achou;

    while(i<posi){
        if(conta[i].saldo < menor_saldo){
            menor_saldo = conta[i].saldo;
            achou = 1;
        }

  i = i + 1;

    }

    for(i = achou; i < posi - 1; i++){
        conta[i].num = conta[i+1].num;
        strcpy(conta[i].nome, conta[i+1].nome);
        conta[i].saldo = conta[i+1].saldo;
    }
    printf("\nConta excluida com sucesso\n");
    posi = posi - 1;


    return posi;

}

int main()
{
 Conta conta[15];

int op;
int posi;


    for(int i = 0; i < 15; i++){
        conta[i].num = 0;
        conta[i].nome[99] = "";
        conta[i].saldo = 0;

    }
    posi = 0;

  do{

    printf("Menu de opcoes\n");
    printf("1- Cadastrar contas\n");
    printf("2- Visualizar todas as contas de determinado cliente\n");
    printf("3- Excluir conta de menor saldo\n");
    printf("4- Sair\n");

    printf("Digite sua opcao\n");
    scanf("%d", &op);

    if(op < 1 || op > 4){
        printf("Opcao invalida\n");
    }

    switch(op){

case 1:
    if(posi > 15){
        printf("Todas as contas ja foram cadastradas!\n");
    }else{

    posi = RegConta(conta, posi);
 }
   break;

case 2:
    consultaCliente(conta, posi);


    break;

case 3:
    if(posi == 0){
        printf("Nenhuma conta cadastrada\n");
}else{

    posi = excluimenorSaldo(conta, posi);

 }
    break;

case 4:
    (exit);

  }

  }while(op != 4);

return 0;
}
