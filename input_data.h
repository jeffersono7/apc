#include "file.h"

void entrada_dados(struct funcionario *func_input)
{
    do{
        system("cls");


        fflush(stdin);
        printf("\nInsira o código do funcionário: ");
        scanf("%d", &func_input->codigo);  //parou aqui, falta corrigir erros e bugs

        fflush(stdin);
        printf("\nDigite o nome do funcionário: ");
        gets(func_input->nome);

        fflush(stdin);
        printf("\nInsira a data de nascimento: (Digite o dia/mes/ano separadamente e seguido de um enter)");
        scanf("%d %d %d", &func_input->idade.dia, &func_input->idade.mes, &func_input->idade.ano);


        fflush(stdin);
        printf("\nInsira a quantidade de dependentes: ");
        scanf("%d", &func_input->dependentes);

        fflush(stdin);
        printf("\nInsira o seu nível (B, M, S)\n");
        printf("\tB = Básico\n");
        printf("\tM = Médio\n");
        printf("\tS = Superior\n");
        gets(func_input->nivel);

        fflush(stdin);
        printf("\nInsira a hora de entrada: (Digite as horas e minutos separadamente e seguido de um enter)");
        scanf("%d %d", &func_input->hrEntrada.hora, &func_input->hrEntrada.minuto);

        fflush(stdin);
        printf("\nInsira a hora de saida: (Digite as horas e minutos separadamente e seguido de um enter)");
        scanf("%d %d", &func_input->hrSaida.hora, &func_input->hrSaida.minuto);

        fflush(stdin);
        printf("\nInsira a quantidade de horas extras: ");
        scanf("%d", &func_input->horasExtras);

        fflush(stdin);
        printf("\nInsira o seu salário: ");
        scanf("%f", &func_input->salario);

        // escreve no arquivo
        int status=escreve_arquivo(*func_input);

        //trata erros
        system("cls");

        if(status==0)
        {
            printf("\nGravado com sucesso!");
        }else
        {
            if(status==1)
            {
                printf("\nErro ao gravar no arquivo...");
                printf("\n\tTentar gravar novamente? ('s' para sim, outro qualquer para não)");
                char gravar;
                getc(gravar);

                if(gravar == 's')
                {
                    status=escreve_arquivo(*func_input);

                    if(status==0)
                    {
                        printf("\nGravado com sucesso!");
                        getchar();
                    }else
                    {
                        printf("\n\nNão foi possível gravar os dados. Pressione qualquer tecla para retornar ao menu...\n\n");
                        getchar();
                        break;
                    }
                }
            }
        }

        printf("\n\n\n\nDESEJA ADICIONAR OUTRO FUNCIONARIO? [s/n]: ");

        if(getchar()=='s')
            system("cls");
        else
            break;

    }while(1);

}

