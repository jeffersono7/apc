//#pragma optimize (O3)  //Para ficar r�pido
//#pragma -std=c++14 //Para usar compilador mais recente

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include "file.h"
#include "input_data.h"

//#include <thread> //Para usar threads

/*struct data
{
    int dia;
    int mes;
    int ano;
};

struct hora
{
    int hora;
    int minuto;
};

struct funcionario
{
    int codigo;
    char nome[30];
    struct data idade;
    int dependentes;
    char nivel; // B-basico,M-media,S-superior
    struct hora hrEntrada;
    struct hora hrSaida;
    int horasExtras;
    float salario;
};*/

// Declara��es das fun��es a serem usadas
int menu(); //maxwell
void cabecalho(); //Wagton
int escreve_arquivo(); //jefferson
int ler_arquivo(); //jefferson
void entrada_dados(struct funcionario *func1); //gabriel usar chave primaria, incrementando a cada grava��o, e buscar no arquivo se ja existe
int relatorio();//wesley usar a funcao pesquisa


int main()
{
    //configura utf-8
    setlocale(LC_ALL, "portuguese");

    int opcao;
    do
    {
        opcao=menu();
        if(opcao==0)
            break;
                    //continua

        //switch para chamar fun��o para op��o esoclhida.
        switch(opcao)
        {
            case 1:
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
        printf("******** 1 Inserir funcion�rios **********\n");
        printf("******** 2 Relat�rio individual **********\n");
        printf("******** 3 Relat�rio geral      **********\n");
        printf("******** 0 Sair                 **********\n");
        printf("******************************************\n\n");
        printf("Escolha uma op��o: \n");
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
            printf("Op��o Inv�lida!\n");
        }
    }while(1);
}

void cabecalho()
{
    system("cls");
	system("color 02");
	printf("-----------------------------------------------------------------------\n");
	printf("--------------------CADASTRO DE FUNCION�RIOS---------------------------\n");
    printf("-----------------------------------------------------------------------\n\n");
    printf("Trabalho em grupo APC1D                                                \n\n");
	printf("Componetes/Matricula: Gabriel Antonio     1622082022                   \n");
	printf("                      Jefferson Oliveira  1622082027                   \n");
	printf("                      Maxwell Silveira    1612082102                   \n");
	printf("                      Wagton Ferreira     1612081069                   \n");
	printf("                      Weslley Barros      1622082008                   \n\n");

}
