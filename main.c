//Autor: Gustavo de Mazo Silva

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200
char nome_A[SIZE][50],nome_B[SIZE][50], modalidade[SIZE][40], pais[SIZE][40];
char nome_C[SIZE][50],nome_D[SIZE][50],email[SIZE][60],senha[SIZE][30];
int medalha,ouro[SIZE] ,prata[SIZE] ,bronze[SIZE],total[SIZE];
static int linha;
static int line;
struct rgAgora {
  int dia, mes, ano;
  int h, m, s;
};
void hora(){
    char ds[7][4] = {"dom", "seg", "ter", "qua", "qui", "sex", "sab"};

    struct tm tempo;
    time_t tempoSeg;

    time(&tempoSeg);
    tempo = *localtime(&tempoSeg);

    struct rgAgora agora;

    agora.dia = tempo.tm_mday;
    agora.mes = tempo.tm_mon + 1;
    agora.ano = tempo.tm_year + 1900;
    agora.h = tempo.tm_hour;
    agora.m = tempo.tm_min;
    agora.s = tempo.tm_sec;

    printf("%02d/%02d/%d (%s) %02d:%02d:%02d horas.\n",
        agora.dia, agora.mes, agora.ano, ds[tempo.tm_wday], agora.h, agora.m, agora.s);

}

//Tela de cadastro
void cadastro(){
    system("cls");
    int i;

    printf("**********************************************************************\n");
    printf("*   \t\t\t    Tela de Cadastro                         * \n");
    printf("**********************************************************************\n");
    printf("\t\t");hora();

    printf("\n\nPrimeiro nome: \n");
    scanf("%s", &nome_C[line]);

    printf("Sobrenome: \n");
    scanf("%s", &nome_D[line]);

    printf("Email: \n");
    scanf("%s", &email[line]);

    printf("Senha: \n");
    scanf("%s", &senha[line]);

    for(i=0;i<line;i++){
        if(strcmp(email[i],email[line])==0){
            printf("Email já existente!!\n\n");
            system("pause");
        }
    }

    line++;
}
void entrar(){
    int i;
    system("cls");
    char pesq_email[60];
    char pesq_senha[30];

    printf("**********************************************************************\n");
    printf("*   \t\t\t    Tela de Login                            * \n");
    printf("**********************************************************************\n");
    printf("\t\t");hora();

    printf("\n\nEmail:  \n");
    scanf("%s",&pesq_email);

    printf("Senha:  \n");
    scanf("%s",&pesq_senha);

    for(i=0;i<SIZE;i++){
        if(strcmp(email[i],pesq_email)==0 && (strcmp(senha[i],pesq_senha)==0)){
            op_principal();
        }else{
            printf("EMAIL ou SENHA incorretos....\n\n");
            system("pause");
        }break;
    }
     menu_login();
}

void menu_login(){
    system("cls");

    printf("**********************************************************************\n");
    printf("*   \t\tBem-vindo as olimpiadas de Paris de 2024!            * \n");
    printf("**********************************************************************\n");
    printf("\t\t");hora();
    printf("\n\n\t\t1- Logar     2- Cadastro     5- Sair \n");
    printf(" \n");
    printf("Digite: \n");

}
void covid(){
    system("cls");
    int numero;
    printf("\t\tPREVENÇÃO\n\n1. Lave bem as mãos e com frequência, usando álcool em gel ou água e sabão.\n\n");
    printf("2. Mantenha uma distância mínima de 1 metro entre você e qualquer pessoa que tosse ou espirra.\n\n");
    printf("3. Evite tocar nos olhos, nariz e boca.\n\n");
    printf("4. Fique em casa se não estiver bem. Se você tiver febre, tosse e falta de ar, procure atendimento médico e ligue com antecedência para o posto de saúde, UPA ou pronto-socorro.\n\n");

    system("pause");
    op_principal();

}

void cadastro_atletas(){
    int numero;

    do{
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tCadastro de Atletas e Detalhes                       | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();
    printf("\n\nDigite o primeiro nome \n->:");
    scanf("%s",&nome_A[linha]);

    printf("Digite o sobrenome\n->:");
    scanf("%s",&nome_B[linha]);

    printf("País representado\n->:");
    scanf("%s",&pais[linha]);

    printf("Modalidade Olímpica\n->:");
    scanf("%s",modalidade[linha]);

    vazio();

    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tCadastro de Atletas e Detalhes                       | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();

    printf("\n\nDigite 1 para cadastrar outro Atleta ou qualquer outro numero para sair.\n");
    scanf("%d", &numero);
    linha++;
    }while(numero == 1);
}
void vazio(){
    int num;

    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\t         Cadastro de Medalhas                       | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();
    printf("\n\nDigite 1 se quer cadastrar medalhas para este atleta\n->:");
    scanf("%d", &num);

    if(num==1){medalhas();}

}

void medalhas(){
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\t         Cadastro de Medalhas                        | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();
    printf("\n\nEscolha uma opção abaixo:\n\n1- Ouro      2- Prata      3- Bronze      5- Voltar\n->:");
    scanf("%d",&medalha);
    switch(medalha){
        case 1:
            system("cls");
            printf("----------------------------------------------------------------------\n");
            printf("|  \t\t         Medalhas de Ouro!                           | \n");
            printf("----------------------------------------------------------------------\n\n");
            printf("Digite o numero de medalhas de ouro\n->: ");
            scanf("%d",&ouro[linha]);
            printf("Incluindo %d medalha(s) de ouro\n\n",ouro[linha]);
            system("pause");
            medalhas();
            break;
        case 2:
            system("cls");
            printf("----------------------------------------------------------------------\n");
            printf("|  \t\t       Medalhas de Prata!                            | \n");
            printf("----------------------------------------------------------------------\n\n");
            printf("Digite o numero de medalhas de prata\n->: ");
            scanf("%d",&prata[linha]);
            printf("Incluindo %d medalha(s) de prata\n\n",prata[linha]);
            system("pause");
            medalhas();
            break;
        case 3:
            system("cls");
            printf("----------------------------------------------------------------------\n");
            printf("|  \t\t      Medalhas de Bronze!                            | \n");
            printf("----------------------------------------------------------------------\n\n");
            printf("Digite o numero de medalhas de bronze\n->: ");
            scanf("%d",&bronze[linha]);
            printf("Incluindo %d medalha(s) de bronze\n\n",bronze[linha]);
            system("pause");
            medalhas();
            break;
        case 5:
            vazio();;
            break;
        default:
            printf("Número inválido!!!");
            vazio();
    }
}
void quadro_medalhas(){
    int i;
    int soma;

        printf("País         Ouro    Prata    Bronze    Total\n");
        for(i=0;i<linha;i++){
            total[i]= ouro[i]+prata[i]+bronze[i];
            printf("%s       %d       %d         %d        %d\n\n\n",pais[i],ouro[i],prata[i],bronze[i],total[i]);
        }
    system("pause");
    op_principal();
}
void cadastro_medalhas(){
    char nom_at[50];
    char nom_pm[50];
    int i,gold ,prat,bronz;

    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\t          Cadastro de Medalhas                        | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();

    printf("\n\nEscreva o primeiro nome do Atleta que ganhou a medalha:\n->: ");
    scanf("%s",&nom_at);
    printf("Escreva o segundo nome do Atleta:\n->: ");
    scanf("%s",&nom_pm);

    for(i=0;i<linha;i++){
        if(strcmp(nome_A[i],nom_at)==0 && strcmp(nome_B[i],nom_pm)==0){
            printf("Escolha qual medalha quer vincular a este atleta:\n\n");
            printf("1- Ouro      2- Prata      3- Bronze      5- Voltar\n->:");
            scanf("%d",&medalha);

            switch(medalha){
                case 1:
                    system("cls");
                    printf("----------------------------------------------------------------------\n");
                    printf("|  \t\t         Medalhas de Ouro!                           | \n");
                    printf("----------------------------------------------------------------------\n\n");
                    printf("Digite o numero de medalhas de ouro que deseja acrescentar\n->: ");
                    scanf("%d",&gold);
                    printf("Incluindo %d medalha(s) de ouro\n\n",gold);
                    ouro[i]+= gold;
                    system("pause");
                    medalhas();
                    break;
                case 2:
                    system("cls");
                    printf("----------------------------------------------------------------------\n");
                    printf("|  \t\t       Medalhas de Prata!                            | \n");
                    printf("----------------------------------------------------------------------\n\n");
                    printf("Digite o numero de medalhas de prata que deseja acrescentar\n->: ");
                    scanf("%d",&prat);
                    printf("Incluindo %d medalha(s) de prata\n\n",prat);
                    prata[i]+=prat;
                    system("pause");
                    medalhas();
                    break;
                case 3:
                    system("cls");
                    printf("----------------------------------------------------------------------\n");
                    printf("|  \t\t      Medalhas de Bronze!                            | \n");
                    printf("----------------------------------------------------------------------\n\n");
                    printf("Digite o numero de medalhas de bronze que deseja acrescentar\n->: ");
                    scanf("%d",&bronz);
                    printf("Incluindo %d medalha(s) de bronze\n\n",bronz);
                    bronze[i]+=bronz;
                    system("pause");
                    op_principal();
                    break;
                case 5:
                    op_principal();
                    break;
                default:
                    printf("Número inválido!!!");
                    cadastro_medalhas();
            }
        }else{
            printf("Nome não cadastrado ou incorreto.");
        }
    }
    system("pause");
    op_principal();
}
void op_principal(){
    system("cls");
    int numero;

    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tMenu de opções selecione uma opção abaixo!           | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();

    printf("\n\n1- Atletas     2- Agenda Olímpica / Calendário de eventos    3- Quadro de medalhas\n\n4- Cadastro de Medalhas     5- Informações COVID-19     9- Sair\n\n");
    printf("->:");
    scanf("%d", &numero);


    switch(numero){
    case 1:
        op_atletas();
        break;
    case 2:
        break;
    case 3:
        quadro_medalhas();
        break;
    case 4:
        cadastro_medalhas();
        break;
    case 5:
        covid();
        break;
    case 9:
        printf("Finalizando o programa...\n\n");
        break;
    }


}
void op_atletas(){
    int numero1,numero, i;
    char pesq_nom[40];


    system("cls");

    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tMenu de opções selecione uma opção abaixo!           | \n");
    printf("----------------------------------------------------------------------\n");
    printf("\t\t");hora();
    printf("\n\n1- Cadastro de Atleta     2- Consulta de atletas e detalhes     3-  Local de alojamento\n\n6- Voltar\n\n");
    printf("->: ");
    scanf("%d", &numero1);

    switch(numero1){
    case 1:
        cadastro_atletas();
        return(op_atletas());
        break;
    case 2:
        do{
        system("cls");
        printf("----------------------------------------------------------------------\n");
        printf("|  \t\tConsulta de Atletas e Detalhes                       | \n");
        printf("----------------------------------------------------------------------\n\n");


        printf("Digite o Nome ou o Sobrenome do Atleta\n->:");
        scanf("%s",&pesq_nom);

        for(i=0;i<SIZE;i++){
            if(strcmp(nome_A[i],pesq_nom)==0 || strcmp(nome_B[i],pesq_nom)==0){
                printf("\nNome do Atleta: %s %s\nPaís: %s\nModalidade: %s\n",nome_A[i],nome_B[i],pais[i],modalidade[i]);
                total[i]= ouro[i]+prata[i]+bronze[i];
                printf("Medalhas: %d\nOuro: %d\nPrata: %d\nBronze: %d\n",total[i],ouro[i],prata[i],bronze[i]);
                }
            }

        printf("\nDigite 1 para pesquisar outro nome ou qualquer outro numero para sair.\n");
        scanf("%d", &numero);

        }while(numero == 1);
        return(op_atletas());
        break;
    case 3:
        break;
    case 6:
        op_principal();
        break;
    default:
        printf("Número incorreto\n\n");
        system("pause");
        return(op_atletas());}

}

void test_looping(){
    int numero;

    menu_login();
    scanf("%d", &numero);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    switch(numero){
        case 1:
            entrar();
            break;
        case 2:
            cadastro();
            break;
        case 5:
            printf("Finalizando o programa...\n");
            break;
        default:
            printf("Numero incorreto \n");
            break;
    }

    /*If para fazer com que o usuário que se cadastre
    volte para fazer o login*/

    if(numero == 2){
            test_looping();
    }
    test_looping();
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    test_looping();

    system("pause");
    return 0;
}
