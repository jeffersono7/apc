#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "struct.h"
//#include <thread>

//file.h

//nota: revisar codigo.


//long int posicao=0;

int abre_arquivo(FILE **arq_codigo,FILE **arq_nome,FILE **arq_idade,FILE **arq_dependentes,FILE **arq_nivel,FILE **arq_hrEntrada,FILE **arq_hrSaida,
                FILE **arq_horasExtras,FILE **arq_salario, char modo[]) //return 0 para sucesso, >0 para falha; modo=a-append,w-write,r-read

{

    if((*arq_codigo=fopen("data\\codigo.txt",modo))!=0)
    {
        if((*arq_nome=fopen("data\\nome.txt",modo))!=0)
        {
            if((*arq_idade=fopen("data\\idade.txt",modo))!=0)
            {
                if((*arq_dependentes=fopen("data\\dependentes.txt",modo))!=0)
                {
                    if((*arq_nivel=fopen("data\\nivel.txt",modo))!=0)
                    {
                        if((*arq_hrEntrada=fopen("data\\hrEntrada.txt",modo))!=0)
                        {
                            if((*arq_hrSaida=fopen("data\\hrSaida.txt",modo))!=0)
                            {
                                if((*arq_horasExtras=fopen("data\\horasExtras.txt",modo))!=0)
                                {
                                    if((*arq_salario=fopen("data\\salario.txt",modo))!=0)
                                    {
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1; //erro de abertura de arquivo
}

int fecha_arquivo(FILE *arq_codigo,FILE*arq_nome,FILE *arq_idade,FILE *arq_dependentes,FILE *arq_nivel,FILE *arq_hrSaida,FILE *arq_hrEntrada,
                FILE *arq_horasExtras,FILE *arq_salario) //return 0 para sucesso, >0 para falha
{
    fclose(arq_codigo);
    fclose(arq_nome);
    fclose(arq_idade);
    fclose(arq_dependentes);
    fclose(arq_nivel);
    fclose(arq_hrEntrada);
    fclose(arq_hrSaida);
    fclose(arq_horasExtras);
    fclose(arq_salario);
    return 0; //Sem erros

}

int escreve_arquivo(struct funcionario func1)  //desenvolver

// um arquivo para cada elemento da struct(cada tabela) e um para armazenamento de chave primaria
// banco de dados do tipo chave-valor
// funções como pesquisa vai buscar nas tabelas inserindo a chave primaria do "dado".
{
    int status;
    int posicao;
    FILE *arq_codigo=0,*arq_nome=0,*arq_idade=0,*arq_dependentes=0,*arq_nivel=0,*arq_hrSaida=0,*arq_hrEntrada=0,*arq_horasExtras=0,*arq_salario=0; //desordenado.

    //Procura posição vazia no arquivo
    posicao=procura_posicao();

    if(posicao<0)
    {
        posicao=1;
    }else if(posicao==0)
    {
        posicao=1;
    }else
    {
        posicao+=1;
    }

    // Abre arquivo usando thread
    //std::thread first (status=abre_arquivo, arq_codigo,arq_nome,arq_idade,arq_dependentes,arq_nivel,arq_hrEntrada,arq_hrSaida,arq_horasExtras,arq_salario,'a'); // Verificar se ordem de flags está certa.
    status=abre_arquivo(&arq_codigo,&arq_nome,&arq_idade,&arq_dependentes,&arq_nivel,&arq_hrEntrada,&arq_hrSaida,&arq_horasExtras,&arq_salario,"a");


    //variavel para o for, porque windows é outro nível #g++
    int cont=0;

    for(cont=0;;cont++) // verifica se abriu.
    {
        system("cls");
        printf("\n\n\t\tAbrindo arquivo!\n\n\n"); //status de abertura.
        if(status==0)
            break;

        if((cont>100000) && status != 0)
        {
            printf("\nErro ao abrir arquivo!\n");
            printf("\n\nTente novamento a operação...");
            getchar();
            fecha_arquivo(arq_codigo,arq_nome,arq_idade,arq_dependentes,arq_nivel,arq_hrEntrada,arq_hrSaida,arq_horasExtras,arq_salario);
            return 1; //erro ao abrir arquivo!
        }
    }



    // Escreve no arquivo.

    //table codigo
            fprintf(arq_codigo, "%d %d \n",posicao,func1.codigo);  //posicao é linha. terminar

    //table nome
            fprintf(arq_nome, "%d %s \n",posicao,func1.nome); // ver %s para string func1.nome

    //table idade
            fprintf(arq_idade,"%d %d %d %d \n",posicao,func1.idade.dia,func1.idade.mes,func1.idade.ano);

    //table dependentes
            fprintf(arq_dependentes,"%d %d \n",posicao,func1.dependentes);

    //table nível
            fprintf(arq_nivel,"%d %c \n",posicao,func1.nivel); //verificar isso de posicao na função.

    //table hrEntrada
            fprintf(arq_hrEntrada,"%d %d %d \n",posicao,func1.hrEntrada.hora, func1.hrEntrada.minuto);

    //table hrSaida
            fprintf(arq_hrSaida, "%d %d %d \n",posicao,func1.hrSaida.hora, func1.hrSaida.minuto);

    //table horasExtras
            fprintf(arq_horasExtras, "%d %d \n",posicao,func1.horasExtras);

    //table salario
            fprintf(arq_salario, "%d %f \n",posicao,func1.salario);

    // fim de escrita.

    //fecha arquivo
    fecha_arquivo(arq_codigo,arq_nome,arq_idade,arq_dependentes,arq_nivel,arq_hrEntrada,arq_hrSaida,arq_horasExtras,arq_salario);
    return 0; //operação realizada com sucesso!
}

//--------------------------------------------------------



int ler_arquivo(struct funcionario *func_ler, int posicao) //desenvolver corrigir erro igual do escre_arquivo fecha ao abrir arquivo tbm
{
    //Abre arquivo usando thread
    int status;


    FILE *arq_codigo,*arq_nome,*arq_idade,*arq_dependentes,*arq_nivel,*arq_hrEntrada,*arq_hrSaida,*arq_horasExtras,*arq_salario;
    //std::thread first (status=abre_arquivo(arq_codigo,arq_nome,arq_idade,arq_dependentes,arq_nivel,arq_hrEntrada,arq_hrSaida,arq_horasExtras,arq_salario,'r');

    status=abre_arquivo(&arq_codigo,&arq_nome,&arq_idade,&arq_dependentes,&arq_nivel,&arq_hrEntrada,&arq_hrSaida,&arq_horasExtras,&arq_salario,"r");

    //variavel para o for, #windows_zoeira
    int cont=0;

    for(cont=0;;cont++) // verifica se abriu.
    {
        system("cls");
        printf("\n\n\t\tAbrindo arquivo!"); //status de abertura.
        if(status==0)
            break;
        if((cont>100000) && (status != 0))
        {
            printf("\nErro ao abrir arquivo!\n");
            printf("\n\nTente novamento a operação...");
            fflush(stdin);
            getchar();
            fecha_arquivo(arq_codigo,arq_nome,arq_idade,arq_dependentes,arq_nivel,arq_hrEntrada,arq_hrSaida,arq_horasExtras,arq_salario);
            return 1; //erro ao abrir arquivo!
        }
    } // fim for.
    //limpa tela
    system("cls");

    // desenvolver, capturar nos arquivos os dados pedidos e gravar em um objeto struct temporario (temp_ler)

    int temp_posicao;//para armazenar posição temporaria capturada no arquivo

    //debug
        printf("\n\nApos abrir arquivo!");
        fflush(stdin);
        getchar();

    //debug

    //table codigo
    fseek(arq_codigo,posicao*sizeof("%d %d \n"),SEEK_SET); //verificar sizeof
    //debug
    printf("\n\napos fseek");
    fflush(stdin);
    getchar();
    //debug
    //--
    fscanf(arq_codigo,"%d %d \n",&temp_posicao, &func_ler->codigo);
    //debug
    printf("\nApos fscanf!");
    fflush(stdin);
    getchar();
    //debug

    //--fscanf(arq_codigo,"%d %d \n",temp_posicao,func_ler->codigo);

    //table nome
    fseek(arq_nome,posicao*sizeof("%d %s \n"),SEEK_SET);
    //--
    fscanf(arq_nome,"%d %s \n",&temp_posicao, &func_ler->nome);
    //--fscanf(arq_nome,posicao*sizeof("%d %s \n"),SEEK_SET);

    //table idade
    fseek(arq_idade,posicao*sizeof("%d %d \n"),SEEK_SET);
    //--
    fscanf(arq_idade,"%d %d %d %d \n", &temp_posicao, &func_ler->idade.dia,&func_ler->idade.mes,&func_ler->idade.ano);
    //--fscanf(arq_idade,posicao*sizeof("%d %d \n"),SEEK_SET);

    //table dependentes
    fseek(arq_dependentes,posicao*sizeof("%d %d \n"),SEEK_SET); //arrumar estrutura do sizeof
    //--

    fscanf(arq_dependentes,"%d %d \n", &temp_posicao, &func_ler->dependentes);
    //--fscanf(arq_dependentes,posicao*sizeof("%d %d \n"),SEEK_SET);

    //table nivel
    fseek(arq_nivel,posicao*sizeof("%d %c \n"),SEEK_SET); //arrumar estrutura do sizeof
    //--
    fscanf(arq_nivel,"%d %c \n", &temp_posicao, &func_ler->nivel);
    //--fscanf(arq_nivel,posicao*sizeof("%d %c \n"),SEEK_SET);

    //table hrEntrada
    fseek(arq_hrEntrada,posicao*sizeof("%d %d %d \n"),SEEK_SET); //arrumar estrutura do sizeof
    //--
    fscanf(arq_hrEntrada,"%d %d %d \n", &temp_posicao, &func_ler->hrEntrada.hora,&func_ler->hrEntrada.minuto);

    //--fscanf(arq_hrEntrada,posicao*sizeof("%d %d %d \n"),SEEK_SET);

    //table hrSaida
    fseek(arq_hrSaida,posicao*sizeof("%d %d %d \n"),SEEK_SET); //arrumar estrutura do sizeof
    //--
    fscanf(arq_hrSaida,"%d %d %d \n", &temp_posicao, &func_ler->hrSaida.hora,&func_ler->hrSaida.minuto);

    //--fscanf(arq_hrSaida,posicao*sizeof("%d %d %d \n"),SEEK_SET);

    //table horasExtras
    fseek(arq_horasExtras,posicao*sizeof("%d %d \n"),SEEK_SET); //arrumar estrutura do sizeof
    //--
    fscanf(arq_horasExtras,"%d %d \n", &temp_posicao, &func_ler->horasExtras);
    //--fscanf(arq_horasExtras,posicao*sizeof("%d %d \n"),SEEK_SET);

    //table salario
    fseek(arq_salario,posicao*sizeof("%d %f \n"),SEEK_SET); //arrumar estrutura do sizeof
    //--
    fscanf(arq_salario,"%d %f \n", &temp_posicao, &func_ler->salario);
    //debug
        printf("\n\nfim fscanf");
        fflush(stdin);
        getchar();
    //debug
    //  ***  Fim de leitura ***

    //fecha arquivo
    fecha_arquivo(arq_codigo,arq_nome,arq_idade,arq_dependentes,arq_nivel,arq_hrEntrada,arq_hrSaida,arq_horasExtras,arq_salario);

    return 0; //0-sucesso
    // fim da função
}

int procura_posicao()
{
    int temp_posicao_file=0,temp_posicao_arm=0;

    FILE *arq=fopen("data\\codigo.txt","r");

    if(arq==0)
       return -1;


    do{
        if(!(feof(arq)))
        {
            fscanf(arq, "%d %d \n",&temp_posicao_file);

            if(temp_posicao_file>temp_posicao_arm)
                temp_posicao_arm=temp_posicao_file;
        }
        else
            break;

    }while(1);

    fclose(arq);
    return temp_posicao_arm;
}
