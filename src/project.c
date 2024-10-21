// O QUE SERÁ UTILIZADO

// 1. Setlocale
// 2. função e chamada de função [OK]
// 3. função void                [OK]
// 4. switch case                [OK]

// PROJETO

// 1. Possuir Menu de opções
// 2. Cadastrar novo usuário
// 3. Alterar senha do usuário
// 4. Realizar o login
// 5. Exclusão de usuário
// 6. Opção de saída
// 7. Necessário salvar os usuários em TXT.

#include <stdio.h> // Importa a biblioteca "Standart Input Output Header(cabecalho)"
#include <locale.h> // Importa a biblioteca para Formatação de idiomas
#include <string.h> // Importa a biblioteca para manipulação de strings

// Variáveis globais para armazenar dados do último usuário cadastrado
char user_destino[100], pass_destino[100];

// Função que define o idioma de entrada de dados
void lang_format() { // "void" declara a função como tipo vazio

#ifdef _WIN32
    setlocale(LC_ALL, "Portuguese"); // Para Windows
#else
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Para Linux e macOS
#endif
}

// Definição de funções

// Funções da lógica do menu
void cadastrar() {
    // "char"é uma tipagem que armazena apenas 1 caractere
    // É obrigatório definir um valor de "array" enre colchetes pra obter mais que isso
    
    char user[100], pass[100];

    FILE *data_backup; // FILE estrutura dedados pra gerenciar operações com arquivos. data_back é uma variável setada pra criação do arquivo
    data_backup = fopen("users.txt", "a"); // Atribui-se à variável a função "fopen" para abrir o arquivo "users.txt". 
    // O argumento "a" (append) abre o arquivo para escrita, criando-o se não existir. O conteúdo existente não é apagado, e os novos dados são adicionados no final.

    printf("=======================\nCadastrar novo usuário:\n=======================\n");
    printf("\nNome de usuário: ");
    scanf("%s", user);
    printf("Senha de usuário: ");
    scanf("%s", pass);

    // Copia os dados para as variáveis destino
    strcpy(user_destino, user);
    strcpy(pass_destino, pass);

    // Escreve os dados no arquivo
    fprintf(data_backup, "%s %s\n", user_destino, pass_destino); //"fprint" sempre pra "printar" em um arquivo de saída. %s, %s formata as duas variáveis em string
    fclose(data_backup); // Encerra a interação com o .txt

    printf("\nUsuário >>%s<< cadastrado com sucesso!\n", user);
}
                                     
void alterar_senha () {
    
}

void logar () {
    char user_login[100], pass_login[100]; // Novas variáveis para receber o input para logar
    char user_txt[100], pass_txt[100]; // Variáveis para ler os dados do .txt
    int login_check = 0; // Variável "tipaada como inteira". Será o true/false da verificação de login. Definida usando "fail-fast" boa prática defensiva
    printf("=======================\nLogin:\n=======================\n"); // Assim como o "%d" define que um tipo "inteiro" será lido
    printf("\nNome de usuário: ");
    scanf("%s", user_login);
    printf("Senha de usuário: ");
    scanf("%s", pass_login);

    FILE *data_backup = fopen("users.txt", "r"); // Aqui a função fopen está acessando o txt em modo leitura "r" (read)

    //---------------------------
    // int estaCorreto = 0; // FALSE
    
    // do {
    //     fscanf(data_backup, "%s %s", user_txt, pass_txt)

    //     if (strcmp(user_login, user_txt) == 0 && strcmp(pass_login, pass_txt) == 0) {
    //         if (strcmp(user_login, user_txt) == 0 && strcmp(pass_login, pass_txt) == 0) 
    //         printf("\nUsuário >>%s<< logado com sucesso!\n", user_login); // %s% pra formatar e "user_login" pra chamar a variável no print
    //         login_check = 1; // Atribui um novo valor "true" a variável "login_check"
    //         break; // Encerra o loop criado pelo while
    //     }

    // } while (estaCorreto == 0);

    //---------------------------

    // A função "strcmp" (StreamComparation) compara as vaiáveis que lêem o txt. Se resultar em "0" elas são iguis e o resultado é "true"
    while (fscanf(data_backup, "%s %s", user_txt, pass_txt) == 2) {         // O "fscanf" está puxando as variáveis de login e enquanto receber 2 valores vai rodar a condição
        if (strcmp(user_login, user_txt) == 0 && strcmp(pass_login, pass_txt) == 0) {
            printf("\nUsuário >>%s<< logado com sucesso!\n", user_login); // %s% pra formatar e "user_login" pra chamar a variável no print
            login_check = 1; // Atribui um novo valor "true" a variável "login_check"
            break;
        } // Encerra o loop criado pelo while
    }
    if (login_check == 0) { // Em C, obrigatóriamente condicionais "if, else", etc. deve ficar entrep parênteses
        printf("Usuário ou senha incorretos.\n");
    }

    fclose(data_backup); // Fecha a variável que recebe os parâmetros de abertura do txt. Logo fecha o documento.
}

void excluir_usuario () {
    
}

int main () {

    lang_format(); // Chama a função de formatar o odioma
    int user_input; // Define a variável que recebe os inputs o usuário

    do {

    // Exibe menu de opções
    printf("==============================\nDigite um valor correspondente\nPara executar uma das opções\n==============================\n\n");
    printf("Opção 1 - Cadastrar\n");
    printf("Opção 2 - Alterar senha\n");
    printf("Opção 3 - Logar\n");
    printf("Opção 4 - Excluir usuário\n");
    printf("Opção 5 - Sair\n\n");

    // "%d" define que "scanf' vai receber aepenas valores inteiros
    // "&" e obrigatório antes de uma variável, ele seta a mesma na memória
    scanf("%d", &user_input);                        

    // Possibilidades pro usuário 
    switch(user_input) {
        case 1: 
            cadastrar();
            break;
            // O "break" é passar pro próximo bloco de código assim que este for executado.
            // Sem o "break" pode haver looping

        case 2:
            printf("Alterar senha: \n");
            break;

        case 3:
            logar ();
            break;

        case 4:
            printf("Excluir usuário: \n");
            break;

        case 5:
            printf("Sair\n");
            return 0; // O return 0 aqui finaliza completamente execução do código diferente do break nas outras condições. 

        default:
            printf("Opção inválida\n");
            break;

    }

    } while (user_input != 5);
     
    return(0);
}