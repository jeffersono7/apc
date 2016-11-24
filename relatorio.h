#include "input_data.h"

void relatorio_geral()
// precisa abrir todos os arquivos de tabelas, use função.
{
    //FILE *arq_codigo,*arq_nome,*arq_idade,*arq_dependentes,*arq_nivel,*arq_hrEntrada,*arq_hrSaida,*arq_horasExtras,*arq_salario;
    //status=abre_arquivo(&arq_codigo,&arq_nome,&arq_idade,&arq_dependentes,&arq_nivel,&arq_hrEntrada,&arq_hrSaida,&arq_horasExtras,&arq_salario,"r");
    //status bool

    struct funcionario rel_func;
    int contador;//para for abaixo
    int pesquisa_status=0;

    do
    {
        for(contador=0;;contador++)
        {
            pesquisa_status=existe_posicao(contador);//-1:falha ao abrir -2:nao existe aquela posição no arquivo

            if(pesquisa_status!=-1 && pesquisa_status!=-2 &&(!(ler_arquivo(&rel_func,contador))))
            {
                //exibir dados    -funcionando, basta fazer aqui a implementação

                //aqui os printf para exibir os dados da struct
                printf("\n\nExibe dados");

                //exibir de acordo com o enter do usuário, como se estivesse vendo logs.

                return 0;


            }
            else
            {
                if(contador==0) //tratamento para erro.
                {
                    printf("\n\nInfelizmente não foi possível acessar o relatório!\n\n");
                    printf("\n\n\t\tDeseja tentar novamente? (s ou n): ");
                    fflush(stdin);

                    if(getchar()=='n')
                        return 0;
                    else
                        break;
                }
                else
                {
                    printf("\n\n\n\n------------------------------------------------------------");
                    printf("\n\nFIM DO RELATÓRIO!");
                    printf("\n\nPressione qualquer tecla para voltar ao menu...");
                    fflush(stdin);
                    getchar();

                }
            }
        }
        //debug
        printf("erro");
        fflush(stdin);
        getchar();
        //debug

    }while(1);
}


void relatorio_individual(int rel_posicao)
// precisa abrir todos os arquivos de tabelas, use função.
{
    struct funcionario rel_func;

    do
    {
        if(!(ler_arquivo(&rel_func,rel_posicao)))
        {
            //exibir dados    -funcionando, basta fazer aqui a implementação

            //aqui os printf para exibir os dados da struct


            //exibir de acordo com o enter do usuário, como se estivesse vendo logs.

            break;
        }
        else
        {
            printf("Não foi possível acessar o relatório!\n\n");
            printf("\n\n\t\tDeseja tentar novamente? (s ou n");

            if(getchar()=='n')
                break;
        }

    }while(1);
}

inline int existe_posicao(int posicao) //verifica se existe a posicao no arquivo
{
    int temp_posicao_file;

    FILE *arq=fopen("data\\codigo.txt", "r");

    if(arq==NULL)
    {
        return -2;
    }
    else
    {
        fscanf(arq,"%d %d \n", &temp_posicao_file);
        if(temp_posicao_file==posicao)
        {
            fclose(arq);
            return 0;
        }
        else
        {
            fclose(arq);
            return -1;
        }
    }
}
