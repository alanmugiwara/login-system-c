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

    FILE *data_backup; // FILE (arquivo) um ponteiro para gerenciar operações com arquivos. data_back é uma variável setada
    data_backup = fopen("users.txt", "a"); // Atribui-se a varável a função "fopen" para abrir o .txt e pargumento "a" de "append" cria o .txt em leitura/escrita recusrsivas.
    
if (data_backup == NULL) {
    printf("Erro ao abrir o arquivo.\n");
} else {
    printf("Txt salvo com sucesso!.\n");
}

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
    char user_login[100], pass_login[100];
    printf("=======================\nLogin:\n=======================\n"); // Assim como o "%d" define que um tipo "inteiro" será lido
    printf("\nNome de usuário: ");
    scanf("%s", user_login);
    printf("Senha de usuário: ");
    scanf("%s", pass_login);
    

    // Verificação das credenciais se fore iguais a "0" que indica equivalência
    if (strcmp(user_login, user_destino) == 0 && strcmp(pass_login, pass_destino) == 0) {
        printf("\nUsuário >>%s<< logado com sucesso!\n", user_login);
    } else {
        printf("Usuário ou senha incorretos.\n");
    }
}

void excluir_usuario () {
    
}

int main () {

    lang_format(); // Chama a função de formatar o odioma
    int user_input; // Define a variável que recebe os inputs o usuário

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
        break;

        default:
        printf("Opção inválida\n");
        break;

    }
    return(0);
}