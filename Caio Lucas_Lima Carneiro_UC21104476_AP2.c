// Nome:Gustavo Henrique Dantas, Caio Lucas Lima Carneiro      Matrícula: UC20100755, UC21104476
#include <stdio.h>   //Biblioteca para printf e scanf.
#include <string.h>  //Biblioteca para strlen e strcmp.
#include <stdlib.h>  //Biblioteca para system.
#include <ctype.h>   //Serve para classificar caracteres ASCII.
#include <locale.h>  //Localizar um programa e fazer adaptações às características de um determinado idioma ou região.
#include <stdbool.h> //Denota em uma função que retorna um valor do tipo bool.

#define TAM_CIDADE 120
#define MAX_PRE 120 //Permite dar um nome a um valor constante antes do programa ser compilado.
#define MAX_JOGOS 450

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILE *presi;

    int i = 0, x = 0, max_x = 0, imax = 0, opcao, y = 0,q = 0,imax_t = 0, j = 0,tam;
    char pres[120], valida_cidade[100],cidade_min[120];

    struct identificacao_jogos
    {
        int id, valor_arr;
        char cidade[TAM_CIDADE];
    };

    do
    {
        presi = fopen("nome.txt","a");

        fflush(stdin);
        printf("Informe o nome do Presidente: \n");
        fgets(pres, 120, stdin);

    } while (strlen(pres) > MAX_PRE || strlen(pres) < 2);
    fprintf(presi,"%s",pres);
    fclose(presi);

    system("cls"); // Limpando a Tela

    
    do
    {
        struct identificacao_jogos jogos[450];
        printf("o i: %d\n",i);

        printf("Insira a opção desejada");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:
            system("cls");
            printf("===== ===== ===== =====\n");
            printf("Até a próxima\n");
            printf("===== ===== ===== =====\n");
            break;

        case 1:
            system("cls");

            do
            {
                
                fflush(stdin);
                printf("o i: %d\n",i);
                printf("Informe a identificação, menor que 10.000 e maior que 300 além de não poder se repetir");
                scanf("%d", &jogos[i].id);

                 
                
                imax = imax_t; 
                        
                while (imax > 0)
                {
                    printf("\nid i: %d\n imax:%d\n",jogos[i].id,jogos[imax-1].id);

                    if (jogos[i].id == jogos[imax-1].id)
                    {

                        printf("Identificação Não pode ser igual a nenhuma já chamada\n");
                        jogos[i].id = 0;
                        
                    }
                imax--;    

                }
                printf("%d", jogos[i].id);
                

            } while (jogos[i].id > 10000 || jogos[i].id < 300);
            
            imax_t++;

            do
            {
                printf("Informe o valor arrecadado, RS 1.000 até 1.000.000: ");
                scanf("%d", &jogos[i].valor_arr);

            } while (jogos[i].valor_arr > 1000000 || jogos[i].valor_arr < 1000);

            do
            {
                fflush(stdin);
                printf("Informe a Cidade onde foi realizado o jogo: \n");
                fgets(jogos[i].cidade, 120, stdin);

             
                



            } while (strlen(jogos[i].cidade) > TAM_CIDADE || strlen(jogos[i].cidade) < 2);

            i++;
            max_x += 1;

            break;

        case 2:
            
            for (int i; i < max_x; i++)
            {
                printf("=====================================================================================\n");
                printf("Nome do Presidente: %s\n",pres);
                printf("ID: %d\n", jogos[i].id);
                printf("ID2: %d\n", jogos[i].id);
                printf("Valor Arrecadado : %d\n", jogos[i].valor_arr);
                strcpy (cidade_min,jogos[i].cidade);
                for (int j =0;j<strlen(cidade_min);j++){
                    cidade_min[j] = tolower(cidade_min[j]);
                } 
                printf("Cidade: %s\n", cidade_min);
                printf("=====================================================================================\n");
            }
            getch();
            break;

        case 3:

            fflush(stdin);
            printf("Insira o nome da cidade, apenas minúsculo: ");
            fgets(valida_cidade, 100, stdin);

            printf("\n%d: %d:\n",max_x,x);

            do
            {
                strcpy (cidade_min,jogos[x].cidade);
                for (int j =0;j<strlen(cidade_min);j++){
                    cidade_min[j] = tolower(cidade_min[j]);
                }
                if (strcmp(valida_cidade, cidade_min) == 0)
                {
                    i = x;
                    y = i;

                    printf("Ocorreu o jogo de id: %d na cidade %s", jogos[x].id,cidade_min);

                }
                x++;

            } while (x < max_x);
            x=0;
            

            if (i != y)
            {
                printf("Não ocorreu jogo na cidade %s", valida_cidade);
            }
            y=0;
            break;
        }
    } while (opcao != 0);
    
    return 0;
}
