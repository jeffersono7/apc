//#pragma optimize (O3)  //Para ficar rápido
//#pragma -std=c++14 //Para usar compilador mais recente


//#include "file.h"
#include "input_data.h"

//#include <thread> //Para usar threads


// Declarações das funções a serem usadas
int menu(); //maxwell
void cabecalho(); //Wagton
int escreve_arquivo(); //jefferson
int ler_arquivo(); //jefferson
void entrada_dados(struct funcionario *func1); //gabriel usar chave primaria, incrementando a cada gravação, e buscar no arquivo se ja existe
int relatorio();//wesley usar a funcao pesquisa
int procura_posicao();// procura posicao vazia para ser usada.

int main()
{
    //configura utf-8
    setlocale(LC_ALL,"portuguese");

    int opcao;
    struct funcionario entrada_funcionario;

    //animação ao abrir programa
    int color,valor_color;

    //alimenta função de randomização.
    srand((unsigned)time(NULL));

    system("cls");

    //matriz
    printf("\n\n\n\n");
    printf("\t\t\t\t#############################################\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#             ***  INICIANDO  ***           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#          SEJA      BEM      VINDO         #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#                                           #\n");
    printf("\t\t\t\t#############################################\n");
    //fim matriz

    //fim de animação ---------------


    for(color=0;color<20;color++)
    {
        //Delay(faz programa pausar por determinado tempo, até evento acontecer.
        usleep(500);

        //faz pedido de numero aleatório.
        valor_color=1+rand()%7;
        switch(valor_color)
        {
        case 1:
            system("color 10");
            break;

        case 2:
            system("color b1");
            break;

        case 3:
            system("color 78");
            break;

        case 4:
            system("color d0");
            break;

        case 5:
            system("color 94");
            break;

        case 6:
            system("color 0f");
            break;

        case 7:
            system("color 03");
        }

    }
    do
    {
        opcao=menu();
        if(opcao==0)
            break;
                    //continua

        //switch para chamar função para opção esoclhida.
        switch(opcao)
        {
            case 1:
                entrada_dados(&entrada_funcionario);
                break;

            default:
                break;
        }

    }while(opcao!=0);

    return 0;
}



//---------------------------------------------------------------
int pesquisa() //retorna chave primaria do elemento encontrado,para entao depois usar ler_arquivo desenvolver
{

}



// menu()
int menu()
{
    int menu;

    do{
        system("cls");
        cabecalho();
        printf("******************************************\n");
        printf("******** 1 Inserir funcionários **********\n");
        printf("******** 2 Relatório individual **********\n");
        printf("******** 3 Relatório geral      **********\n");
        printf("******** 0 Sair                 **********\n");
        printf("******************************************\n\n");
        printf("Escolha uma opção: ");
        scanf(" %d", &menu);

        if (menu==1){
            return 1;
        }else if (menu==2){
            return 2;
        }else if (menu==3){
            return 3;
        }else if (menu==4){
            return 4;
        }else if (menu==0){
            return 0;
        }else {
            printf("Opção Inválida!\n");
        }
    }while(1);
}

void cabecalho()
{
    system("cls");
	system("color 02");
	printf("-----------------------------------------------------------------------\n");
	printf("--------------------CADASTRO DE FUNCIONÁRIOS---------------------------\n");
    printf("-----------------------------------------------------------------------\n\n");
    printf("Trabalho em grupo APC1D                                                \n\n");
	printf("Componetes/Matricula: Gabriel Antonio     1622082022                   \n");
	printf("                      Jefferson Oliveira  1622082027                   \n");
	printf("                      Maxwell Silveira    1612082102                   \n");
	printf("                      Wagton Ferreira     1612081069                   \n");
	printf("                      Weslley Barros      1622082008                   \n\n");

}
