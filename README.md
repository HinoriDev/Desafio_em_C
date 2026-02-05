📚 Sistema de Gerenciamento Acadêmico
Este é um projeto desenvolvido em C para gerenciar registros de alunos, validação de documentos (CPF) e organização de tarefas. O objetivo principal é consolidar conceitos de manipulação de arquivos, structs e lógica de programação.

🚀 Funcionalidades
Cadastro de Alunos: Registro e listagem de estudantes.

Validação de CPF: Módulo dedicado à verificação de integridade de documentos.

Gestão de Tarefas: Criação e acompanhamento de atividades/pendências.

Menu Interativo: Interface via terminal para facilitar a navegação.

📁 Estrutura do Projeto
alunos.c: Contém a lógica de manipulação dos dados dos alunos.

cpf.c: Funções específicas para validação e tratamento de CPF.

tarefas.c: Implementação do sistema de tarefas e menu principal.

.gitignore: Arquivos e diretórios ignorados pelo Git (como executáveis e arquivos temporários).

🛠️ Como Executar
Para compilar e rodar o projeto, você precisará de um compilador C (como o gcc).

Clone o repositório:

Bash
git clone https://github.com/HinoriDev/Desafio_em_C.git
Compile os arquivos:

Bash
gcc tarefas.c alunos.c cpf.c -o sistema
Execute o programa:

Bash
./sistema
