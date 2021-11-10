#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

//Tela de cadastro
void cadastro(){
    system("cls");
    char nome[30];
    char email[60];
    char login[30];
    char senha[30];

     printf("**********************************************************************\n");
    printf("*   \t\t\t    Tela de Cadastro                         * \n");
    printf("**********************************************************************\n\n");

    fgets(nome, 30, stdin);
    printf("Nome: \n");

    fgets(email, 60, stdin);
    printf("Email: \n");

    fgets(login, 30, stdin);
    printf("Login: \n");

    fgets(senha, 30, stdin);
    printf("Senha: \n");

}

//Login
void login(){
    system("cls");
    char login[15];
    char senha[30];

    printf("**********************************************************************\n");
    printf("*   \t\t\t    Tela de Login                            * \n");
    printf("**********************************************************************\n\n");
    fgets(login, 15, stdin);
    printf("Login:  \n");

    fgets(senha, 30, stdin);
    printf("Senha:  \n");

}
//Menu do programa
void menu_login(){
    system("cls");

    printf("**********************************************************************\n");
    printf("*   \t\tBem-vindo as olimpiadas de Paris de 2024!            * \n");
    printf("**********************************************************************\n\n");
    printf("\t\t1- Logar     2- Cadastro     5- Sair \n");
    printf(" \n");
    printf("Digite: \n");

}

void op_principal(){
    system("cls");
    int numero;

    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tMenu de opções selecione uma opção abaixo!           | \n");
    printf("----------------------------------------------------------------------\n\n");

    printf("1- Atletas     2- Locais e treinamentos     3- Relatórios\n\n4- Equipes     5- Informações COVID-19     9- Sair\n\n");
    printf("->:");
    scanf("%d", &numero);


    switch(numero){
case 1:
        op_atletas();
    break;
case 2:
    break;
case 3:
    break;
case 4:
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
    int numero1;
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tMenu de opções selecione uma opção abaixo!           | \n");
    printf("----------------------------------------------------------------------\n\n");
    printf("1- Cadastro de Atletas     2- Consulta de atletas e detalhes     3- Alojamentos     4- Equipamentos     6- Voltar\n\n");
    printf("-> \n");
    scanf("%d", &numero1);

    switch(numero1){
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 6:
        op_principal();
        break;
    default:
        printf("Número incorreto\n\n");
        system("pause");
        return(op_atletas());
    }
}
void covid(){
    system("cls");
    int numero;
    printf("PREVENÇÃO\n\n1. Lave bem as mãos e com frequência, usando álcool em gel ou água e sabão.\n\n");
    printf("2. Mantenha uma distância mínima de 1 metro entre você e qualquer pessoa que tosse ou espirra.\n\n");
    printf("3. Evite tocar nos olhos, nariz e boca.\n\n");
    printf("4. Fique em casa se não estiver bem. Se você tiver febre, tosse e falta de ar, procure atendimento médico e ligue com antecedência para o posto de saúde, UPA ou pronto-socorro.\n\n");
    printf("Pressione qualquer número para voltar: ");
    scanf("%d", &numero);

    if (numero >0 || numero <0){
        op_principal();
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero;
    char tela[30];
    char cadastr[30];

    menu_login();
    scanf("%d", &numero);
    switch(numero){
        case 1:
            login();
            fgets(tela,30,stdin);
            break;
        case 2:
            cadastro();
            fgets(cadastr, 30, stdin);
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
            menu_login();
    scanf("%d", &numero);
    switch(numero){
        case 1:
            login();
            fgets(tela,30,stdin);
            break;
        case 2:
            cadastro();
            fgets(cadastr, 30, stdin);
            break;
        case 5:
            printf("Finalizando o programa...\n");
            break;
        default:
            printf("Numero incorreto \n");
                break;
    }
    }

    op_principal();

    system("pause");
    return 0;
}
