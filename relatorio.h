#include "input_data.h"

void relatorio_geral() //tratamento de erros aqui dentro
// precisa abrir todos os arquivos de tabelas, use fun��o.
{
    FILE *arq_codigo,*arq_nome,*arq_idade,*arq_dependentes,*arq_nivel,*arq_hrEntrada,*arq_hrSaida,*arq_horasExtras,*arq_salario;
//    status=abre_arquivo(&arq_codigo,&arq_nome,&arq_idade,&arq_dependentes,&arq_nivel,&arq_hrEntrada,&arq_hrSaida,&arq_horasExtras,&arq_salario,"a");
    //status bool
/*
    do
    {
        if(!feof(ponteiro de arquivo))
        {

        }
    }*/
}


void relatorio_individual(int rel_posicao) //tratamentos de erros aqui dentro
// precisa abrir todos os arquivos de tabelas, use fun��o.
{
    struct funcionario rel_func;

    do
    {
        if(!(ler_arquivo(&rel_func,rel_posicao)))
        {
            //exibir dados
            printf("\n\nrelatorio");
            printf(("\n%d %s",rel_func.codigo,rel_func.nome));

            fflush(stdin);
            getchar();
        }

    }while(1);
}
