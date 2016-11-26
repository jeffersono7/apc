#include "input_data.h"

void relatorio_geral()
// precisa abrir todos os arquivos de tabelas, use função.
{
    //FILE *arq_codigo,*arq_nome,*arq_idade,*arq_dependentes,*arq_nivel,*arq_hrEntrada,*arq_hrSaida,*arq_horasExtras,*arq_salario;
    //status=abre_arquivo(&arq_codigo,&arq_nome,&arq_idade,&arq_dependentes,&arq_nivel,&arq_hrEntrada,&arq_hrSaida,&arq_horasExtras,&arq_salario,"r");
    //status bool

    setlocale(LC_ALL,"Portuguese");

    struct funcionario rel_func;
    int contador;//para for abaixo
    int pesquisa_status=0;
    char nivel_pesquisa; // para receber nivel desejado

    system("cls"); //limpa tela

    //captura nivel dos cadastros a ser exibidos
    printf("\nDigite o nivel que deseja exibir o relatorio: ");
    fflush(stdin);
    scanf("%c", &nivel_pesquisa);

    do
    {
        for(contador=1;;contador++)
        {
            pesquisa_status=existe_posicao(contador);//-1:falha ao abrir -2:nao existe aquela posição no arquivo

            if(pesquisa_status!=-1 && pesquisa_status!=-2 && (!(ler_arquivo(&rel_func,contador))))
            {
                //exibir dados    -funcionando, basta fazer aqui a implementação

                //aqui os printf para exibir os dados da struct

                //inicio exibição
                if((contador%1)==0)
                {
                    //Exibe dados de 2 em 2 cadastros.
                    if(rel_func.nivel==nivel_pesquisa)
                    {
                        system("cls");
                        printf("\n####################################");
                        printf("\n####################################");
                        printf("\n#######   Dados Do Usuário   ######");
                        printf("\n####################################");
                        printf("\n####################################\n\n");
                        printf("Nome:                      %s\n",rel_func.nome);
                        printf("Idade:                     %d\/%d\/%d\n",rel_func.idade.dia,rel_func.idade.mes,rel_func.idade.ano);
                        printf("Nível de Escolaridade:     %c\n",rel_func.nivel);
                        printf("Horário de entrada:        %dh%d\n",rel_func.hrEntrada.hora,rel_func.hrEntrada.minuto);
                        printf("Horário de saída:          %dh%d\n",rel_func.hrSaida.hora,rel_func.hrSaida.minuto);
                        printf("Quantidade de dependentes: %d\n",rel_func.dependentes);
                        printf("Horas Extras:                %d horas\n",rel_func.horasExtras);
                        printf("Salário:                   %0.2f\n",rel_func.salario);
                        printf("\n\nDigite ENTER para continuar a exibiçao: ");
                        fflush(stdin);
                        getchar();
                    }else
                    {
                        if(nivel_pesquisa=='t' || nivel_pesquisa=='T')
                        {
                            system("cls");
                            printf("\n####################################");
                            printf("\n####################################");
                            printf("\n#######   Dados Do Usuário   ######");
                            printf("\n####################################");
                            printf("\n####################################\n\n");
                            printf("Nome:                      %s\n",rel_func.nome);
                            printf("Idade:                     %d\/%d\/%d\n",rel_func.idade.dia,rel_func.idade.mes,rel_func.idade.ano);
                            printf("Nível de Escolaridade:     %c\n",rel_func.nivel);
                            printf("Horário de entrada:        %dh%d\n",rel_func.hrEntrada.hora,rel_func.hrEntrada.minuto);
                            printf("Horário de saída:          %dh%d\n",rel_func.hrSaida.hora,rel_func.hrSaida.minuto);
                            printf("Quantidade de dependentes: %d\n",rel_func.dependentes);
                            printf("Horas Extras:                %d horas\n",rel_func.horasExtras);
                            printf("Salário:                   %0.2f\n",rel_func.salario);
                            printf("\n\nDigite ENTER para continuar a exibiçao: ");
                            fflush(stdin);
                            getchar();
                        }else
                        {
                            system("cls");
                            printf("\n\nNivel inválido\n\nVoltando...");
                            fflush(stdin);
                            getchar();
                        }
                    }

                //exibir de acordo com o enter do usuário, como se estivesse vendo logs. aqui ou dentro do do{}while;

                return 0; //para voltar ao menu
                }
                else
                {
                    if(contador==0) //tratamento para erro.
                    {
                        printf("\n\nInfelizmente não foi possível acessar o relatório!\n\n");
                        printf("Verifique se existe algum cadastro efetivado!\n\n\n");
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
        }
    }while(1);
}


void relatorio_individual(int rel_posicao)
// precisa abrir todos os arquivos de tabelas, use função.
{
    setlocale(LC_ALL,"Portuguese");

    struct funcionario rel_func;

    do
    {
        if(!(ler_arquivo(&rel_func,rel_posicao)))
        {
            //exibir dados    -funcionando, basta fazer aqui a implementação

            //aqui os printf para exibir os dados da struct

                printf("\n####################################");
                printf("\n####################################");
                printf("\n#######   Dados Do Usuário   ######");
                printf("\n####################################");
                printf("\n####################################\n\n");
                printf("Nome:                      %s\n",rel_func.nome);
                printf("Idade:                     %d\/%d\/%d\n",rel_func.idade.dia,rel_func.idade.mes,rel_func.idade.ano);
                printf("Nível de Escolaridade:     %c\n",rel_func.nivel);
                printf("Horário de entrada:        %dh%d\n",rel_func.hrEntrada.hora,rel_func.hrEntrada.minuto);
                printf("Horário de saída:          %dh%d\n",rel_func.hrSaida.hora,rel_func.hrSaida.minuto);
                printf("Quantidade de dependentes: %d\n",rel_func.dependentes);
                printf("Horas Extras:                %d horas\n",rel_func.horasExtras);
                printf("Salário:                   %0.2f\n",rel_func.salario);
                printf("\n\n");

            fflush(stdin);
            getchar();
            //fim_debug


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

    setlocale(LC_ALL,"portuguese");

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
