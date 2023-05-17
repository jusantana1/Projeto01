#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>


    struct dados
    {
    char musica[20];
    char autor[20];
    int qtd;
    float preco;
    };


void registro (struct dados *pdados)
{
    FILE *arq;
    arq= fopen("arq.txt", "a");

    printf("\nMusica: ");
    scanf("%s", &pdados -> musica[0]);
    printf("\nAutor: ");
    scanf("%s", &pdados -> autor[0]);
    printf("\nQuantidade: ");
    scanf("%d", &pdados -> qtd);
    printf("\nPreço: ");
    scanf("%f", &pdados -> preco);
    fwrite(pdados, sizeof(*pdados),1, arq);

    fclose(arq);

}

 void listar(struct dados *pdados)
{
    int r;

    FILE *arq;
    arq= fopen("arq.txt", "r");

    if(arq == NULL)
    {
        printf("Erro na leitura do arquivo!");
        exit(0);
    }
    for(; ;)
    {
        r = fread(pdados, sizeof(*pdados),1, arq);
        if (r ==0){
            break;
    }
        if (*pdados-> musica != '!'){

        printf("\n MUSICA:\t%s", pdados -> musica );
        printf("\n AUTOR:\t%s", pdados -> autor);
        printf("\n QUANTIDADE: %d", pdados -> qtd);
        printf("\n PREÇO:\t%.2f", pdados -> preco);
        printf("\n----------------------------------------------\n");
   }
    }
    fclose(arq);

}

int pesq_musc (struct dados *pdados)
{
    char nome[30];
    int cont, r, x=0;

    printf("Digite o nome da música: \n");
    scanf("%s", &nome);

    FILE *arq;
    arq= fopen("arq.txt", "r");

    for(; ;)
    {
        r= fread(pdados, sizeof(*pdados),1, arq);
        if (r ==0)
        {
            printf("\n MUSICA NAO ENCONTRADA\n");
            fclose(arq);
            return -1;

        }

        for (cont=0; nome[cont] != '\0' ; cont++)
            if (nome[cont] !=  pdados -> musica[cont] )
            {
                break;
            }
        if (nome[cont] == '\0' && pdados -> musica[cont] =='\0')
        {
            printf("\n********MUSICA ENCONTRADA**********\n\n");
            printf(" MUSICA: %s\n", pdados -> musica );
            printf(" AUTOR:  %s\n", pdados -> autor);
            printf(" QUANTIDADE:  %d\n", pdados -> qtd);
            printf(" PREÇO:  %.2f\n", pdados -> preco);
            printf("\n--------------------------------------------------\n");
            fclose(arq);
            return x;

        }
        x++;
    }
}

void pesq_autor (struct dados *pdados)
{
    char nomeautor[30];
    int cont, r;

    printf("Digite o nome do autor: \n");
    scanf("%s", &nomeautor);
    printf("\n");

    FILE *arq;
    arq= fopen("arq.txt", "r");

    for(; ;)
    {
        r= fread(pdados, sizeof(*pdados),1, arq);
        if (r ==0)
        {
            printf("MUSICA NAO ENCONTRADA\n");
            break;
        }

        for (cont=0; nomeautor[cont] != '\0' ; cont++)
            if (nomeautor[cont] !=  pdados -> autor[cont] )
            {
                break;
            }
        if (nomeautor[cont] == '\0' && pdados -> autor[cont] =='\0')
        {
            printf("\n********MUSICA ENCONTRADA**********\n\n");
            printf(" MUSICA: %s\n", pdados -> musica );
            printf(" AUTOR:  %s\n", pdados -> autor);
            printf(" QUANTIDADE:  %d\n", pdados -> qtd);
            printf(" PREÇO:  %.2f\n", pdados -> preco);
            printf("\n\n");
            break;
        }

    }

    fclose(arq);
}

void pesq_preco (struct dados *pdados)
{
    float preco1, preco2;
    int cont, r;

    printf("Digite o valor minimo: \n");
    scanf("%f", &preco1);
    printf("Digite o valor maximo: \n");
    scanf("%f", &preco2);

    FILE *arq;
    arq= fopen("arq.txt", "r");

    for(; ;)
    {
        r= fread(pdados, sizeof(*pdados),1, arq);
        if (r ==0)
        {
            break;
        }

        else if (pdados -> preco >= preco1 && pdados -> preco <= preco2)
        {
            for(; ;)
            {
                printf("\n********MUSICA ENCONTRADA**********\n\n");
                printf(" MUSICA: %s\n", pdados -> musica );
                printf(" AUTOR:  %s\n", pdados -> autor);
                printf(" QUANTIDADE:  %d\n", pdados -> qtd);
                printf(" PREÇO:  %.2f\n", pdados -> preco);
                printf("\n\n");
                break;
            }
        }
    }

    fclose(arq);
}


int altera_qntd (struct dados *pdados)
{
    int i, ende, qtd;

    FILE *arq;

    i = pesq_musc(pdados);

    if(i == -1)
    {
        return;
    }

    arq= fopen("arq.txt", "r+");
    ende = (sizeof(*pdados))*i;

     fseek(arq, ende, 0);

     printf("\n Digite a nova quantidade: ");
     scanf("%d", &qtd);
     printf("\n");

     pdados-> qtd = qtd;

     fseek(arq, ende, 0);
     fwrite(pdados, sizeof(*pdados),1, arq);
     fclose(arq);


}

void altera_pc(struct dados *pdados)
{
    int i, ende;
    float preco;

    FILE *arq;

    i = pesq_musc(pdados);

    if(i == -1)
    {
        return;
    }

    arq= fopen("arq.txt", "r+");
    ende = (sizeof(*pdados))*i;

     fseek(arq, ende, 0);

     printf("\n Digite o novo preço:  ");
     scanf("%f", &preco);
     printf("\n");

     pdados-> preco = preco;

     fseek(arq, ende, 0);
     fwrite(pdados, sizeof(*pdados),1, arq);
     fclose(arq);

}

int altera_dds (struct dados *pdados)
{
    int i, ende;


    FILE *arq;

    i = pesq_musc(pdados);

    if(i == -1)
    {
        return;
    }

    arq= fopen("arq.txt", "r+");
    ende = (sizeof(*pdados))*i;

     fseek(arq, ende, 0);

     printf("Digite o novo nome da musica:  ");
     scanf("%s",  &pdados -> musica[0]);
     printf("\nDigite o nome do autor:  ");
     scanf("%s", &pdados-> autor[0]);
     printf("\nDigite o quantidade:  ");
     scanf("%d",  &pdados-> qtd);
     printf("\n Digite o novo preço:  ");
     scanf("%f", &pdados-> preco);
     printf("\n");

     fseek(arq, ende, 0);
     fwrite(pdados, sizeof(*pdados),1, arq);
     fclose(arq);

}
void excluir (struct dados *pdados)
{
    int i, ende;


    FILE *arq;

    i = pesq_musc(pdados);

    if(i == -1)
    {
        return;
    }
    printf("%d\n", i);
    arq= fopen("arq.txt", "r+");
    ende = (sizeof(*pdados))*i;

    fseek(arq, ende, 0);

    pdados-> musica[0] = '!';
    printf("REGISTRO DE MUSICA EXCLUIDO\n\n");

     fseek(arq, ende, 0);
     fwrite(pdados, sizeof(*pdados),1, arq);
     fclose(arq);

}

void main ()
{
    setlocale(LC_ALL, "");
    struct dados cadastro, *pdados;// estrutura de dados
    pdados= &cadastro;


   int opc;
    for (; ;)
    {
        system("cls");
        printf(" DIGITE UMA OPÇÃO ABAIXO: \n\n");
        printf(" 1- Cadastro de musicas\n");
        printf(" 2- Mostrar musicas cadastradas\n");
        printf(" 3- Pesquisar musica pelo nome\n");
        printf(" 4- Pesquisar pelo nome do autor\n");
        printf(" 5- Pesquisar musica por faixa de preço\n");
        printf(" 6- Alterar quantidade\n");
        printf(" 7- Alterar preço\n");
        printf(" 8- Alterar dados das musicas\n");
        printf(" 9- Excluir dados\n");
        printf(" 10- Sair\n");

        printf("\n>>");
        scanf("%d", &opc);
        getchar();
        system("cls");

        switch (opc)
        {
        case 1: // entrada de dados
            printf("REGISTRO DE MUSICAS:\n\n");
            registro(pdados);
            system("pause");
            break;

        case 2: // listar intens
            printf("   MUSICAS CADASTRADAS:\n\n");
            listar(pdados);
            system("pause");
            break;

        case 3: // pesquisar musc nome completo
            printf("PESQUISAR MUSICA: \n\n");
            pesq_musc(pdados);
            system("pause");
            break;

        case 4: // pesquisar autor nome complt
            printf("PESQUISAR AUTOR:\n\n");
            pesq_autor(pdados);
            system("pause");
            break;

        case 5: // pesquisar por preço
            printf("PESQUISAR POR PREÇO: \n\n");
            pesq_preco(pdados);
            system("pause");
            break;

        case 6: // alterar qntd
            printf("ALTERAR QUANTIDADE:\n\n");
            altera_qntd (pdados);
            system("pause");
            break;

        case 7: //alterar preço nome compt
            printf("ALTERAR PREÇO:\n\n");
            altera_pc(pdados);
            system("pause");
            break;

       case 8: // alterar dados nome
            printf("ALTERAR DADOS: \n\n");
            altera_dds (pdados);
            system("pause");
            break;

        case 9: // excluir dados
            printf("EXCLUIR DADOS: \n\n");
            excluir (pdados);
            system("pause");
            break;

        case 10: // sair
            printf("PROGRAMA ENCERRADO\n\n");
            exit(0);

        default:
            printf("OPÇÃO INVALIDA\n TENTE NOVAMENTE");
            system("pause");
        }
    }
}
