
//Programa para as Olimpíadas de Paris de 2024
//Autor: Gustavo de Mazo Silva


#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#define ANSI_COLOR_GREEN   "\e[0;32m"
#define ANSI_COLOR_RESET   "\e[0m"
#define ANSI_COLOR_BLUE    "\e[34m"
#define ANSI_COLOR_YELLOW  "\e[33m"
#define ANSI_COLOR_CYAN    "\e[36m"
#include <time.h>
#define SIZE 200

FILE *file;
char nome_A[SIZE][50],nome_B[SIZE][50], modalidade[SIZE][40],paiss[SIZE][40], pais[SIZE][40];
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
//CADASTRAR USUÁRIO
void cadastro(){
    system("cls");
    int i;

    file = fopen("arquivo_login.txt", "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        system("pause");
        return 0;
    }
    printf("**********************************************************************\n");
    printf("*   \t\t\t  Tela de Cadastro                           * \n");
    printf("**********************************************************************\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();

    printf(ANSI_COLOR_RESET"\n\nPrimeiro nome: \n");
    scanf("%s", &nome_C[line]);

    fprintf(file,"%s ", nome_C[line]);

    printf("Sobrenome: \n");
    scanf("%s", &nome_D[line]);

    fprintf(file,"%s ", nome_D[line]);

    printf("Email: \n");
    scanf("%s", &email[line]);

    fprintf(file,"%s ", email[line]);

    printf("Senha: \n");
    scanf("%s", &senha[line]);

    fprintf(file,"%s ", senha[line]);

    for(i=0;i<line;i++){
        if(strcmp(email[i],email[line])==0){
            printf("Email já existente!!\n\n");
            system("pause");
        }
    }
    fclose(file);

    line++;
}
//LOGIN DO PROGRAMA
void entrar(){
    int i;
    system("cls");
    char pesq_email[60];
    char pesq_senha[30];

    printf("**********************************************************************\n");
    printf("*   \t\t\t    Tela de Login                            * \n");
    printf("**********************************************************************\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();

    printf(ANSI_COLOR_RESET"\n\nEmail:  \n");
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
//MENU INICIAL
void menu_login(){
    system("cls");

    printf("**********************************************************************\n");
    printf("*   \t\tBem-vindo as olimpiadas de Paris de 2024!            * \n");
    printf("**********************************************************************\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();
    printf(ANSI_COLOR_RESET ANSI_COLOR_YELLOW"\n\n\t\t\t1- Logar\n\n\t\t\t2- Cadastro\n\n\t\t\t5- Sair \n\n"ANSI_COLOR_RESET);
    printf("Digite: \n");
}
//INFORMAÇÕES DA COVID
void covid(){
    system("cls");
    int numero;
    printf(ANSI_COLOR_YELLOW"\t\tPREVENÇÃO\n\n1. Lave bem as mãos e com frequência, usando álcool em gel ou água e sabão.\n\n");
    printf("2. Mantenha uma distância mínima de 1 metro entre você e qualquer pessoa que tosse ou espirra.\n\n");
    printf("3. Evite tocar nos olhos, nariz e boca.\n\n");
    printf("4. Fique em casa se não estiver bem. Se você tiver febre, tosse e falta de ar, procure atendimento médico e ligue com antecedência para o posto de saúde, UPA ou pronto-socorro.\n\n"ANSI_COLOR_RESET);

    system("pause");
    op_principal();

}
//CADASTRAR ATLETAS
void cadastro_atletas(){
    int numero, i;

    do{
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tCadastro de Atletas e Detalhes                       | \n");
    printf("----------------------------------------------------------------------\n");
    printf(ANSI_COLOR_GREEN"\t\t\T");hora();
    printf(ANSI_COLOR_RESET"\n\nDigite o primeiro nome \n->:");
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
    printf(ANSI_COLOR_GREEN"\t\t");hora();

    printf(ANSI_COLOR_RESET"\n\nDigite 1 para cadastrar outro Atleta ou qualquer outro numero para sair.\n");
    scanf("%d", &numero);
    linha++;
    }while(numero == 1);
}
//OPÇÃO DE CADASTRAR UMA MEDALHA
void vazio(){
    int num;

    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\t         Cadastro de Medalhas                       | \n");
    printf("----------------------------------------------------------------------\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();
    printf(ANSI_COLOR_RESET"\n\nDigite 1 se quer cadastrar medalhas para este atleta\n->:");
    scanf("%d", &num);

    if(num==1){medalhas();}

}
//MEDALHAS NO CADASTRO DE ATLETAS
void medalhas(){
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\t         Cadastro de Medalhas                        | \n");
    printf("----------------------------------------------------------------------\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();
    printf(ANSI_COLOR_RESET"\n\nEscolha uma opção abaixo:\n\n1- Ouro      2- Prata      3- Bronze      5- Voltar\n->:");
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
            printf("%s       %d       %d         %d        %d\n\n",pais[i],ouro[i],prata[i],bronze[i],total[i]);
    }
    system("pause");
    op_principal();
}
//AGENDA DE JOGOS
void agenda(){
    int number;
    system("cls");
    printf("----------------------------------------------------------------------\n");
    printf("|  \t\t          Calendário de Jogos                        | \n");
    printf("----------------------------------------------------------------------\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();
    printf(ANSI_COLOR_RESET ANSI_COLOR_YELLOW"\n\n\n\t\t\t1- Atletismo\t2- Basquete\n\n\t\t\t3- Vôlei\t4- Boxe\n\n\t\t\t5- Natação\t6- Hóquei\n\n\t\t\t7- Handebol\t8- Esgrima\n\n\t\t\t9- Tênis\t10- Polo aquático\n\n\n\n");
    printf(ANSI_COLOR_RESET"Escolha o esporte que deseja ver o horário de jogos:\n");
    scanf("%d",&number);

    switch(number){
        case 1:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tAtletismo\n\n");
            printf("21h00 - 3000m com obstáculos (rodada 1)\n\n21h15 - salto em altura (classificatória)\n\n21h45 - lançamento de disco (classificatória)\n\n21h55 - 800m feminino (rodada 1)\n\n22h55 - 400m com barreiras masculino (rodada 1)\n\n23h40 - 100m feminino (rodada 1).\n\nLocal: Estádio Olímpico.\n\n"ANSI_COLOR_RESET);
            break;
        case 2:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tBASQUETE FEMININO\n\n\n05h20 - Espanha x Sérvia\n\n22h00 - Bélgica x Porto Rico\n\nLocal: Super Arena.\n\n\n\t\t\tBASQUETE MASCULINO\n\n01h40 - Eslovênia x Japão.\n\n09h00 - Espanha x Argentina.\n\nLocal: Super Arena.\n\n"ANSI_COLOR_RESET);
            break;
        case 3:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tVÔLEI FEMININO\n\n\n02h20 - Sérvia x Quênia\n\n04h25 - China x ROC\n\n07h40 - Japão x Brasil\n\n09h45 - Estados Unidos x Turquia\n\nLocal: Arena.\n\n\n\t\t\tVÔLEI MASCULINO\n\n21h00 - Canadá x Venezuela\n\n23h05 - BRASIL x ESTADOS UNIDOS\n\nLocal: Arena.\n\n\n\t\t\tVÔLEI DE PRAIA\n\n\nDas 03h00 às 05h50 - Masculino ou feminino (preliminares).\n\nDas 08h00 às 10h50 - Masculino ou feminino (preliminares).\n\nDas 21h00 às 23h50 - Masculino ou feminino (preliminares).\n\nLocal: Park.\n\n"ANSI_COLOR_RESET);
            break;
        case 4:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tBOXE\n\n");
            printf("Das 05h00 às 08h20 - médio masculino, superpesado masculino e mosca feminino (preliminares).\n\nDas 23h00 (dia 29) às 02h10 (dia 30) - leve feminino (preliminares); meio-médio feminino, meio-médio masculino, meio-pesado masculino e pesado masculino (quartas de final).\n\nLocal: Arena.\n\n"ANSI_COLOR_RESET);
            break;
        case 5:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tNATAÇÃO\n\nDas 07h00 às 09h30 - 800m livre feminino, 100m borboleta masculino, 200m costas feminino, e revezamento 4x100m medley misto.\n\nDa 22h30 (dia 29) à 00h10 (dia 30) - 100m borboleta masculino e 200m costas feminino (semifinais); 200m peito feminino, 200m costas masculino, 100m livre feminino e 200m medley individual masculino (Finais).\n\nLocal: Centro Aquático.\n\n"ANSI_COLOR_RESET);
            break;
        case 6:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\tHÓQUEI SOBRE GRAMA FEMINIINO\n\n\n06h30 - Espanha x China\n\n07h00 - Grã-Bretanha x Países Baixos\n\n08h45 - Japão x Argentina\n\n09h15 - Nova Zelândia x Austrália\n\n21h30 - África do Sul x Alemanha\n\n22h45 - Irlanda x Índia\n\nLocal: Hockey.\n\n\n\t\tHÓQUEI SOBRE GRAMA MASCULINO\n\n\nDa 00h15 - Países Baixos x Grã-Bretanha\n\nDas 22h00 - Austrália x Espanha\n\nLocal: Hockey.\n\n"ANSI_COLOR_RESET);
            break;
        case 7:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tHANDEBOL FEMININO\n\n\n02h15 - Japão x Coreia do Sul\n\n04h15 - Montenegro x Noruega\n\n07h30 - Hungria x ROC\n\n09h30 - Suécia x França\n\nLocal: Estádio.\n\n\n\t\t\tHANDEBOL MASCULINO\n\n\n21h00 - ARGENTINA x BRASIL\n\n23h00 - Bahrein x Japão\n\nLocal: Estádio.\n\n"ANSI_COLOR_RESET);
            break;
        case 8:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tESGRIMA\n\n\nDas 06h30 às 09h30 - Florete por equipes feminino (disputa pelo bronze e final).\n\nDas 22h00 (dia 29) às 03h20 (dia 30) - Espada por equipes masculino (preliminares, quartas de final e semifinais).\n\nLocal: Hall.\n\n"ANSI_COLOR_RESET);
            break;
        case 9:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tTÊNIS\n\n");
            printf("01h00 - Individual masculino e duplas mistas (quartas de final), individual feminino e duplas femininas (semifinais).\n\n03h00 - Individual masculino e duplas mistas (quartas de final), individual feminino e duplas femininas (semifinais).\n\n05h00 - Individual masculino e duplas mistas (quartas de final), individual feminino e duplas femininas (semifinais).\n\nLocal: Tennis Park.\n\n"ANSI_COLOR_RESET);

            break;
        case 10:
            system("cls");
            printf(ANSI_COLOR_YELLOW"\t\t\tAGENDA DO DIA - 29 de julho\n\n\n\n\n");
            printf("\t\t\tPOLO AQUÁTICO MASCULINO\n\n\n02h10 - Estados Unidos x Itáia\n\n03h30 - Croácia x Montenegro\n\n06h20 - Grécia x Japão\n\n07h30 - Sérvia x Austrália\n\nLocal: Centro de Polo Aquático.\n\n"ANSI_COLOR_RESET);
            break;
        default:
            printf("Número incorreto...");
            system("pause");
            agenda();
            break;
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
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();

    printf(ANSI_COLOR_RESET"\n\nEscreva o primeiro nome do Atleta que ganhou a medalha:\n->: ");
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
//MENU PRINCIPAL
void op_principal(){
    system("cls");
    int numero;

    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tMenu de opções selecione uma opção abaixo!           | \n");
    printf("----------------------------------------------------------------------\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();

    printf(ANSI_COLOR_RESET ANSI_COLOR_YELLOW"\n\n\t\t\t1- Atletas\n\n\t\t\t2- Agenda Olímpica / Calendário de eventos\n\n\t\t\t3- Quadro de medalhas\n\n\t\t\t4- Cadastro de Medalhas\n\n\t\t\t5- Informações COVID-19\n\n\t\t\t9- Sair\n\n\n");
    printf(ANSI_COLOR_RESET"->:");
    scanf("%d", &numero);


    switch(numero){
    case 1:
        op_atletas();
        break;
    case 2:
        agenda();
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
        system("pause");
        return 1;
        break;
    }


}

//OPÇÃO ATLETAS NO MENU PRINCIPAL
void op_atletas(){
    int numero1,numero, i;
    char pesq_nom[40];


    system("cls");

    printf("----------------------------------------------------------------------\n");
    printf("|  \t\tMenu de opções selecione uma opção abaixo!           | \n");
    printf("----------------------------------------------------------------------\n");
    printf(ANSI_COLOR_GREEN"\t\t\t");hora();
    printf(ANSI_COLOR_RESET ANSI_COLOR_YELLOW"\n\n\t\t\t1- Cadastro de Atleta\n\n\t\t\t2- Consulta de atletas e detalhes\n\n\t\t\t3- Local de alojamento\n\n\t\t\t6- Voltar\n\n");
    printf(ANSI_COLOR_RESET"->: ");
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
//LOOPING MENU INICIAL
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
            return 1;
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
