# Login System C

Este projeto é um sistema de login simples escrito em C que permite cadastrar, alterar senha, realizar login e excluir usuários. Os dados dos usuários são salvos em um arquivo de texto.
Ele ainda está em desenvolvimento e algumas funcionalidades ainda não foram implementadas. Mais ataulizações em breve!

## Funcionalidades

- **Cadastrar Usuário:** Permite ao usuário criar um novo cadastro.
- **Alterar Senha:** Opção para alterar a senha de um usuário existente.
- **Login:** Realiza o login de um usuário com as credenciais cadastradas.
- **Excluir Usuário:** Remove um usuário do sistema.
- **Salvar Usuários em TXT:** Todos os dados dos usuários são armazenados em um arquivo de texto (`users.txt`).

## Tecnologias Utilizadas

- **C**: Linguagem de programação utilizada para desenvolver o sistema.
- **Bibliotecas:** 
  - `stdio.h`: Para manipulação de entrada/saída.
  - `locale.h`: Para definir a formatação de idioma.
  - `string.h`: Para manipulação de strings.

## Como Usar

1. **Clone este repositório usando comando abaixo:**

   ```bash
   git clone https://github.com/alanmugiwara/login-system-c
   ```

2. **Compile o Código:**
   - Navegue até o diretório do projeto e compile o código:

     ```bash
     gcc login-system-c.c -o login-system-c
     ```

3. **Execute o Programa:**
   - Após a compilação, execute o programa com o comando abaixo ou apenas execute o .exe gerado:

     ```bash
     ./login-system-c
     ```

4. **Interaja com o Menu:**
   - Escolha uma das opções do menu:
     - `1`: Cadastrar um novo usuário.
     - `2`: Alterar a senha de um usuário.
     - `3`: Realizar o login.
     - `4`: Excluir um usuário.
     - `5`: Sair do programa.

## Estrutura do Código

### Funções Principais

- `lang_format()`: Define a formatação de idioma para o sistema.
- `cadastrar()`: Permite cadastrar um novo usuário e salvar os dados em um arquivo TXT.
- `logar()`: Realiza o login com as credenciais fornecidas.
- `alterar_senha()`: Função destinada para alterar a senha de um usuário.
- `excluir_usuario()`: Função destinada para excluir um usuário do sistema.

### Switch Case
- A estrutura `switch case` é utilizada para oferecer um menu de opções ao usuário, controlando o fluxo de cada operação de acordo com o valor inserido.

Para dúvidas, sugestões ou problemas, entre em contato com Álan Cruz:

<div>
<a href="https://instagram.com/alancruz_tec" target="_blank"><img loading="lazy" src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" alt="Instagram"></a>
<a href="mailto:contato@alancruz.tec.br"><img loading="lazy" src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="E-mail"></a>
<a href="https://linkedin.com/in/alansilvadacruz" target="_blank"><img loading="lazy" src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="Linkedin"></a>
</div>