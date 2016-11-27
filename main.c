#pragma optimize(-O3)  //Para ficar rápido
//#pragma -std=c++14 //Para usar compilador mais recente


//#include "file.h"
//#include "input_data.h"
#include "relatorio.h"
//#include <thread> //Para usar threads


// Declarações das funções a serem usadas
int menu(); //maxwell
void cabecalho(); //Wagton
int escreve_arquivo(); //jefferson
int ler_arquivo(); //jefferson
void entrada_dados(struct funcionario *func1); //gabriel usar chave primaria, incrementando a cada gravação, e buscar no arquivo se ja existe
void relatorio_individual(int rel_posicao);//wesley usar a funcao pesquisa
void relatorio_geral(); //exibe todos os dados nas tabelas, usar getchar para ir descendo os dados exibidos, igual nos unix e linux.
int procura_posicao();// procura posicao vazia para ser usada.
inline int existe_posicao(int); //verifica se existe no arquivo aquela posicao no arquivo, e retorna o status.
//Fim declarações

int main()
{
    //configura utf-8
    setlocale(LC_ALL,"");

    int opcao;
    struct funcionario entrada_funcionario;
    int posicao;

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
        usleep(5000);

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

            case 2:
                posicao=pesquisa(); // Possui bug caso tenha algum nome igual, também tem erro ao pesquisar nome que nao existe.

                if(posicao!=0 && posicao!=-1 && posicao!=-2)
                {
                    relatorio_individual(posicao);
                    break;
                }
                else
                    break;

            case 3:
                relatorio_geral();
                break;

            default:
                break;
        }

    }while(opcao!=0);

    return 0;
}



//---------------------------------------------------------------
int pesquisa() //retorna chave primaria do elemento encontrado,para entao depois usar ler_arquivo #desenvolver
//caso nao encontrado, retorna -1, e 0 para retornar ao menu
//retorna -2 caso não consiga abrir arquivo
//possui erro ao pesquisar nome inexistente --corrigido
//possui falha ao tentar abrir arquivo que ainda nao foi criado, tratar isso --corrigido
{
    char temp_nome[30],temp_nome_file[30];
    int temp_posicao=0,temp_posicao_file=0,opcao=0,temp_codigo=0,temp_codigo_file;

    system("cls"); //Exibe opcao de pesquisa
    do{
        printf("\n1-Pesquisar por código do funcionário\n");
        printf("\n2-Pesquisar por nome do funcionário\n");
        printf("\n0-Para voltar\n\n");
        printf("\nDigite uma opcao: ");

        fflush(stdin);
        scanf("%d",&opcao);

        if(opcao==1)
            break;
        if(opcao==2)
            break;
        if(opcao==0)//retorna ao menu
            return 0;
    }while(1);

    if(opcao==1)
    {
        system("cls");
        printf("Digite o código do funcionário: ");
        //fprintf(stdin,"%s",&temp_codigo);
        fflush(stdin);
        scanf("%d",&temp_codigo);

        //Abre arquivo da tabela codigo
        FILE *arq=fopen("data\\codigo.txt","r");

        //tratamento de erro, caso arq==NULL
        if(arq==NULL)
        {
            printf("\n\n\nErro ao tentar abrir arquivo!\n");
            printf("\n\nPor favor, verifique se inseriu algum cadastro!\n\n");
            printf("\nPressione qualquer tecla para retornar ao menu...");
            fflush(stdin);
            getchar();
            return -2;
        }

        //faz busca nos valores.
        do
        {
            if(!(feof(arq)))
            {
                fscanf(arq,"%d %d \n", &temp_posicao_file,&temp_codigo_file);

                //compara ao código inserido, se sucesso retorna posicao
                if(temp_codigo==temp_codigo_file)
                {
                    temp_posicao=temp_posicao_file;

                    fclose(arq);

                    return temp_posicao;
                }
            }else //talvez um bug aqui!
            {
                printf("\n\nNão encontrado!");
                printf("\n\nPressione qualquer tecla para retornar ao menu...");
                fflush(stdin);
                getchar();

                fclose(arq);
                return -1;
            }
        }while(1);



    }else if(opcao==2)
    {
        system("cls");
        printf("Digite o nome do funcionário: ");
        //fprintf(stdin,"%s",&temp_nome);
        fflush(stdin);
        gets(temp_nome);

        //Abre arquivo da tabela nome
        FILE *arq=fopen("data\\nome.txt","r");

        //tratamento de erros, caso arq==NULL
        if(arq==NULL)
        {
            printf("\n\n\nErro ao tentar abrir arquivo!\n");
            printf("\n\nPor favor, verifique se inseriu algum cadastro!\n\n");
            printf("\nPressione qualquer tecla para retornar ao menu...");
            fflush(stdin);
            getchar();
            return -2;
        }

        //variavel para trocar espaços e '_'
        int espaco;

        //faz busca nos valores.
        do
        {
            if(!(feof(arq)))
            {
                fscanf(arq,"%d %s \n", &temp_posicao_file,&temp_nome_file);

                for(espaco=0;espaco<30;espaco++) //troca '_' por (espaço) ' '
                {
                    if(temp_nome_file[espaco]=='_')
                    {
                        temp_nome_file[espaco]=' ';
                    }
                }
                //compara ao nome inserido, se sucesso retorna posicao
                 if(strcmp(temp_nome,temp_nome_file)==0)
                {
                    temp_posicao=temp_posicao_file;

                    fclose(arq);

                    return temp_posicao;
                }
            }else//talvez um bug aqui!
            {
                printf("\n\nNão encontrado!");
                printf("\n\nPressione qualquer tecla para retornar ao menu...");
                fflush(stdin);
                getchar();

                fclose(arq);
                return -1;
            }
        }while(1);


    }

}



// menu()
int menu()
{
    int menu;

    do{
        system("cls");
        cabecalho();
        printf("\t\t******************************************\n");
        printf("\t\t******** 1 Inserir funcionários **********\n");
        printf("\t\t******** 2 Relatório individual **********\n");
        printf("\t\t******** 3 Relatório geral      **********\n");
        printf("\t\t******** 0 Sair                 **********\n");
        printf("\t\t******************************************\n\n");
        printf("Escolha uma opção: ");

        fflush(stdin);
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
