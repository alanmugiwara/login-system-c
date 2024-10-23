// O QUE SERÁ UTILIZADO

// 1. Setlocale
// 2. função e chamada de função [OK]
// 3. função void                [OK]
// 4. switch case                [OK]

// PROJETO

// 1. Possuir Menu de opções                [OK]
// 2. Cadastrar novo usuário                [OK]
// 3. Alterar senha do usuário              [OK]
// 4. Realizar o login                      [OK]
// 5. Exclusão de usuário                   [OK]
// 6. Opção de saída                        [OK]
// 7. Necessário salvar os usuários em TXT  [OK]
// 8. Cadastro de cliente na função login   [X]

#include <stdio.h> // Importa a biblioteca "Standart Input Output Header(cabecalho)"
#include <locale.h> // Importa a biblioteca para Formatação de idiomas
#include <stdlib.h> // Importa a biblioteca Standartt Librabry. Necessária para trabalhar com idiomas, especialmente strings e caracteres.
#include <string.h> // Importa a biblioteca para manipulação de strings

// Variáveis globais para armazenar dados do último usuário cadastrado
char user_destino[100], pass_destino[100];

// Função que define o idioma de entrada de dados
void lang_format() { // "void" declara a função como tipo vazio

#ifdef _WIN32
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Para Windows
    system("chcp 65001 > NULL"); // chcp (Change Code Page) força a execução do código em UTF-8. "> NULL" oculta a exibição do "chcp 65001" no programa
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
    char user[100], new_pass[100];
    char linha[200], usuario_existente[100], senha_existente[100];
    int user_found = 0;

    FILE *data_backup; // FILE estrutura dedados pra gerenciar operações com arquivos. data_back é uma variável setada pra criação do arquivo
    data_backup = fopen("users.txt", "r+"); // Atribui-se à variável a função "fopen" para abrir o arquivo "users.txt". 
    if (data_backup == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("=======================\nAlterar senha:\n=======================\n");
    printf("\nNome de usuário: ");
    scanf("%s", user);
    printf("Nova senha: ");
    scanf("%s", new_pass);
    // Cria um arquivo temporário para armazenar dados alterados
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(data_backup);
        return;
    }

    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), data_backup)) {
        sscanf(linha, "%s %s", usuario_existente, senha_existente);
        if (strcmp(usuario_existente, user) == 0) {
            // Usuário encontrado, escreve nova senha
            fprintf(temp_file, "%s %s\n", user, new_pass);
            user_found = 1; // Marca que o usuário foi encontrado
        } else {
            // Copia a linha original para o arquivo temporário
            fputs(linha, temp_file);
        }
    }

    if (user_found) {
        printf("Senha alterada com sucesso para o usuário >>%s<<!\n", user);
    } else {
        printf("Usuário não encontrado.\n");
    }

    fclose(data_backup); // Encerra a interação com o .txt
    fclose(temp_file); // Encerra o arquivo temporário

    // Substitui o arquivo original pelo temporário
    remove("users.txt"); // Remove o arquivo original
    rename("temp.txt", "users.txt"); // Renomeia o temporário para o original
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

    // A função "strcmp" (StreamComparation) compara as vaiáveis que lêem o txt. Se resultar em "0" elas são iguis e o resultado é "true"
    while (fscanf(data_backup, "%s %s", user_txt, pass_txt) == 2) {         // O "fscanf" está puxando as variáveis de login e enquanto receber 2 valores vai rodar a condição
        if (strcmp(user_login, user_txt) == 0 && strcmp(pass_login, pass_txt) == 0) {
            printf("\nUsuário >>%s<< logado com sucesso!\n", user_login); // %s% pra formatar e "user_login" pra chamar a variável no print
            login_check = 1; // Atribui um novo valor "true" a variável "login_check"
            break; // Encerra o loop criado pelo while
        }
    }
    if (login_check == 0) { // Em C, obrigatóriamente condicionais "if, else", etc. deve ficar entrep parênteses
        printf("Usuário ou senha incorretos.\n");
    }

    fclose(data_backup); // Fecha a variável que recebe os parâmetros de abertura do txt. Logo fecha o documento.
}

void excluir_usuario () {
    char user[100];
    char linha[200], user_found[100], pass_found[100];
    int user_verify = 0;

    // Abre o arquivo original para leitura
    FILE *data_backup = fopen("users.txt", "r");
    if (data_backup == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Cria um arquivo temporário para armazenar dados
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(data_backup);
        return;
    }

    printf("=======================\nExcluir usuário:\n=======================\n");
    printf("\nNome de usuário a excluir: ");
    scanf("%s", user);

    // Lê o arquivo original linha por linha
    while (fgets(linha, sizeof(linha), data_backup)) {
        sscanf(linha, "%s %s", user_found, pass_found);
        if (strcmp(user_found, user) != 0) {
            // Se o usuário não for o que queremos excluir, copia para o temporário
            fputs(linha, temp_file);
        } else {
            user_verify = 1; // Marca que o usuário foi encontrado
        }
    }

    if (user_found) {
        printf("Usuário >>%s<< excluído com sucesso!\n", user);
    } else {
        printf("Usuário não encontrado.\n");
    }

    fclose(data_backup); // Encerra a interação com o .txt
    fclose(temp_file); // Encerra o arquivo temporário

    // Substitui o arquivo original pelo temporário
    remove("users.txt"); // Remove o arquivo original
    rename("temp.txt", "users.txt"); // Renomeia o temporário para o original

}

int main () {

    lang_format(); // Chama a função de formatar o odioma
    int user_input; // Define a variável que recebe os inputs o usuário

    do {

    // Exibe menu de opções
    printf("==============================\nDigite um valor correspondente\nPara executar uma das opções\n==============================\n\n"
            "Opção 1 - Cadastrar\n"
            "Opção 2 - Alterar senha\n"
            "Opção 3 - Logar\n"
            "Opção 4 - Excluir usuário\n"
            "Opção 5 - Sair\n\n");

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
            alterar_senha();
            break;

        case 3:
            logar();
            break;

        case 4:
            excluir_usuario();
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