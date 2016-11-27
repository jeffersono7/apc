#include "input_data.h"

inline void relatorio_geral()
// precisa abrir todos os arquivos de tabelas, use fun��o.
{
    //FILE *arq_codigo,*arq_nome,*arq_idade,*arq_dependentes,*arq_nivel,*arq_hrEntrada,*arq_hrSaida,*arq_horasExtras,*arq_salario;
    //status=abre_arquivo(&arq_codigo,&arq_nome,&arq_idade,&arq_dependentes,&arq_nivel,&arq_hrEntrada,&arq_hrSaida,&arq_horasExtras,&arq_salario,"r");
    //status bool

    struct funcionario rel_func;

    int contador;//para for abaixo
    int pesquisa_status=0;
    char nivel_pesquisa='\0'; // para receber n�vel desejado

    system("cls"); //limpa tela

    //captura nivel dos cadastros a ser exibidos
    printf("\nDigite o n�vel que deseja exibir o relat�rio (b,m,s): ");
    fflush(stdin);
    scanf("%c", &nivel_pesquisa);

    do
    {
        for(contador=1;;contador++)
        {
            pesquisa_status=existe_posicao(contador);//-1:falha ao abrir -2:nao existe aquela posi��o no arquivo

            if(pesquisa_status!=-1 && pesquisa_status!=-2 && (!(ler_arquivo(&rel_func,contador))))
            {
                //exibir dados    -funcionando, basta fazer aqui a implementa��o

                //aqui os printf para exibir os dados da struct

                //inicio exibi��o
                if(1)//(contador%1)==0 para futuras modifica��es
                {
                    if(rel_func.nivel==nivel_pesquisa)
                    {
                        system("cls");
                        printf("\n####################################");
                        printf("\n####################################");
                        printf("\n#######   Dados Do Usu�rio   ######");
                        printf("\n####################################");
                        printf("\n####################################\n\n");
                        printf("Nome:                      %s\n",rel_func.nome);
                        printf("Idade:                     %d\/%d\/%d\n",rel_func.idade.dia,rel_func.idade.mes,rel_func.idade.ano);
                        printf("N�vel de Escolaridade:     %c\n",rel_func.nivel);
                        printf("Hor�rio de entrada:        %dh%d\n",rel_func.hrEntrada.hora,rel_func.hrEntrada.minuto);
                        printf("Hor�rio de saída:          %dh%d\n",rel_func.hrSaida.hora,rel_func.hrSaida.minuto);
                        printf("Quantidade de dependentes: %d\n",rel_func.dependentes);
                        printf("Horas Extras:              %d horas\n",rel_func.horasExtras);
                        printf("Sal�rio:                   %0.2f\n",rel_func.salario);
                        printf("\n\nDigite ENTER para exibir pr�ximo cadastro: ");
                        fflush(stdin);
                        getchar();
                    }else
                    {
                        if(nivel_pesquisa=='t' || nivel_pesquisa=='T')
                        {
                            system("cls");
                            printf("\n####################################");
                            printf("\n####################################");
                            printf("\n#######   Dados Do Usu�rio   #######");
                            printf("\n####################################");
                            printf("\n####################################\n\n");
                            printf("Nome:                      %s\n",rel_func.nome);
                            printf("Idade:                     %d\/%d\/%d\n",rel_func.idade.dia,rel_func.idade.mes,rel_func.idade.ano);
                            printf("N�vel de Escolaridade:     %c\n",rel_func.nivel);
                            printf("Hor�rio de entrada:        %dh%d\n",rel_func.hrEntrada.hora,rel_func.hrEntrada.minuto);
                            printf("Hor�rio de sa�da:          %dh%d\n",rel_func.hrSaida.hora,rel_func.hrSaida.minuto);
                            printf("Quantidade de dependentes: %d\n",rel_func.dependentes);
                            printf("Horas Extras:                %d horas\n",rel_func.horasExtras);
                            printf("Sal�rio:                   %0.2f\n",rel_func.salario);

                            printf("\n\nDigite ENTER para exibir proximo cadastro: ");
                            fflush(stdin);
                            getchar();
                        }else
                        {
                            if(nivel_pesquisa=='s' || nivel_pesquisa=='m' || nivel_pesquisa=='b')
                            {
                                system("cls");
                                printf("\n\nNenhum cadastro registrado com esse n�vel!");
                                printf("\n\n\nPressione ENTER para voltar ao menu...");
                                fflush(stdin);
                                getchar();
                                return 0;
                            }
                            else
                            {
                                system("cls");
                                printf("\n\nNivel inv�lido\n\n\nEnter para voltar ao menu...");
                                fflush(stdin);
                                getchar();
                                return 0;
                            }
                        }
                    }
                }
                //exibir de acordo com o enter do usu�rio, como se estivesse vendo logs. aqui ou dentro do do{}while;

                //return 0; //para voltar ao menu
            }
            else
            {
                if(contador==1) //tratamento para erro.
                {
                    printf("\n\nInfelizmente n�o foi poss�vel acessar o relat�rio!\n\n");
                    printf("Verifique se existe algum cadastro efetivado!\n\n\n\n");
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
                    printf("\n\nFIM DO RELAT�RIO!");
                    printf("\n\nPressione qualquer tecla para voltar ao menu...");
                    fflush(stdin);
                    getchar();
                    return 0;
                }
            }
        }
    }while(1);
}


inline void relatorio_individual(int rel_posicao)
// precisa abrir todos os arquivos de tabelas, use fun��o.
{
    struct funcionario rel_func;

    do
    {
        if(!(ler_arquivo(&rel_func,rel_posicao)))
        {
            //exibir dados    -funcionando, basta fazer aqui a implementa��o

            //aqui os printf para exibir os dados da struct

                printf("\n####################################");
                printf("\n####################################");
                printf("\n#######   Dados Do Usu�rio   #######");
                printf("\n####################################");
                printf("\n####################################\n\n");
                printf("Nome:                      %s\n",rel_func.nome);
                printf("Idade:                     %d\/%d\/%d\n",rel_func.idade.dia,rel_func.idade.mes,rel_func.idade.ano);
                printf("N�vel de Escolaridade:     %c\n",rel_func.nivel);
                printf("Hor�rio de entrada:        %dh%d\n",rel_func.hrEntrada.hora,rel_func.hrEntrada.minuto);
                printf("Hor�rio de sa�da:          %dh%d\n",rel_func.hrSaida.hora,rel_func.hrSaida.minuto);
                printf("Quantidade de dependentes: %d\n",rel_func.dependentes);
                printf("Horas Extras:              %d horas\n",rel_func.horasExtras);
                printf("Sal�rio:                   %0.2f\n",rel_func.salario);
                printf("\n\n");

            fflush(stdin);
            getchar();
            //fim_debug


            //exibir de acordo com o enter do usu�rio, como se estivesse vendo logs.

            break;
        }
        else
        {
            printf("N�o foi poss�vel acessar o relat�rio!\n\n");
            printf("\n\n\t\tDeseja tentar novamente? (s ou n");

            if(getchar()=='n')
                break;
        }

    }while(1);
}

inline int existe_posicao(int posicao) //verifica se existe a posicao no arquivo
{

    int temp_posicao_file,temp_codigo_file;

    FILE *arq=fopen("data\\codigo.txt", "r");

    if(arq==NULL)
    {
        return -2;
    }
    else
    {
        while(!feof(arq))
        {
            fscanf(arq,"%d %d \n", &temp_posicao_file, &temp_codigo_file);

            if(temp_posicao_file==posicao)
            {
                fclose(arq);
                return 0;
            }
        }
        fclose(arq);
        return -1;
    }
}
