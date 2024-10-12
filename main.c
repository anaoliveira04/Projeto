//declara as bibliotecas 
#include <stdio.h>
#include <locale.h>
#include <string.h>

void menu(); //declara a função menu

void cadastro() 
{
    FILE *arquivo1;
    arquivo1 = fopen("cadastro.txt", "w"); //abre o arquivo em modo edição

    if(arquivo1 == NULL) //verifica se o arquivo foi aberto
    {
        wprintf(L"ERRO! Arquivo não foi aberto!\n");
    }

    else
    {
        //declara as variáveis que vão guardar a senha e o usuário 
        char usuario[30];
        char senha[30];
        wprintf(L"Cadastro iniciado\n");

        wprintf(L"Digite o usuário: ");
        scanf("%s", usuario);

        fprintf(arquivo1, "%s\n", usuario); //escreve no arquivo cadastro
        wprintf(L"Digite a senha: ");
        scanf("%s", senha);

        fprintf(arquivo1, "%s\n", senha); //escreve no arquivo cadastro
        fclose(arquivo1); //fecha o arquivo

        wprintf(L"Cadastro realizado com sucesso!\n");
    }
    menu(); //retorna para o menu
}

void login()
{
    FILE *arquivo1;
    arquivo1 = fopen("cadastro.txt", "r"); //abre o arquivo cadastro em modo leitura
    

    if(arquivo1 == NULL)
    {
        wprintf(L"ERRO! Arquivo não foi aberto!\n");
        return;
    }

    FILE *arquivo2;
    arquivo2 = fopen("login.txt", "w"); //abre o arquivo login em modo edição

    if(arquivo2 == NULL)
    {
        wprintf(L"ERRO! Arquivo não foi aberto!\n");
        return;
    }

    //declara as variáveis que vão armazenar usuário e login do menu
    char user[30];
    char password[30];
    char usuario_cadastro[30], senha_cadastro[30]; //vão armazenar o usuário e senha lidos no arquivo cadastro

    //lê o arquivo cadastro
    fscanf(arquivo1, "%s", usuario_cadastro);
    fscanf(arquivo1, "%s", senha_cadastro);
    fclose(arquivo1); //fecha o arquivo cadastro
        
    wprintf(L"Login iniciado\n");
    wprintf(L"Digite o usuário: "); //solicita o usuário
    scanf("%s", user);

    wprintf(L"Digite a senha: "); //solicita a senha
    scanf("%s", password);

    fprintf(arquivo2, "%s \n %s \n", user, password); //escreve no arquivo login
    fclose(arquivo2); //fecha o arquivo

    //a função strcmp compara duas strings, se for igual retorna 0
    //compara primeiro o user (usuário do login) com o usuário_cadastro 
    //depois compara password (senha do login) com o senha_cadastro
    //se ambas comparações forem verdadeiras aparece a mensagem de realizado com sucesso
    if(strcmp(user, usuario_cadastro) == 0 && strcmp(password, senha_cadastro) == 0)
    {
        wprintf(L"Login realizado com sucesso!\n");
    }

    else //se alguma das comparações não forem verdadeiras aparece a mensagem seguinte
    {
        wprintf(L"Usuário ou senha incorretos!\n");
    }
    menu(); //retorna para o menu 
}

void menu()
{
    int opcao;
    wprintf(L"Escolha uma opcão (1-2): \n");
    wprintf(L"1. Cadastro\n");
    wprintf(L"2. Login\n");
    scanf("%d", &opcao);

    switch (opcao)
        {
            case 1:
                wprintf(L"Opção escolhida: cadastro\n");
                cadastro(); //chama a função cadastro
                break;
                            
            case 2:
                wprintf(L"Opção escolhida: login\n");
                login(); //chama a função login
                break;
                            
            default: //caso insiram uma opção não existente 
                wprintf(L"Opção inválida\n");
                break;
                            
        }
}

int main()
{
    setlocale(LC_ALL, "Portuguese"); //permite acento

    FILE *arquivo1; 
    arquivo1 = fopen("cadastro.txt", "a"); //cria o arquivo no computador
    fclose(arquivo1); //fecha o arquivo

    FILE *arquivo2;
    arquivo2 = fopen("login.txt", "a"); //cria o arquivo no computador
    fclose(arquivo2); //fecha o arquivo

    menu(); //chama a função menu 
    return 0;
}