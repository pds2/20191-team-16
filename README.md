# 20191-team-16

# TP de PDS2 - Sistema de gerenciamento (email local)

Programa que simula um sistema de email local que possibilita as seguintes funções:

- login/registro
- escrever e enviar novas mensagens
- gerenciar emails enviados e recebidos
- configurar alguns detalhes da conta do usuario em sessão

# User Stories

# 1º)
Como usuario desse sistema desejo poder enviar uma mensagem escrita para um ou
mais usuarios também cadastrados de uma vez, para evitar ter de usar o mesmo comando
mais de uma vez.

Critérios para aceitação:

 *Inserir o nome dos destinatarios, um a um, até que nada mais seja inserido(Enter sem nada inserido).
 *Verificar se os usuarios inseridos estão cadastrados no sistema e enviar as mensagens um a um.
 *Retornar uma mensagem de erro, caso a mensagem não ter sido enviada para um usuario selecionado
  por ele nao estar cadastrado no sistema.

# 2º)
Como um usuario desse sistema queria que fosse possivel compartilhar uma
mensagem enviada para a minha caixa de entrada com outros usuários cadastrados,
para poupar o tempo de ter de re-escrever a respectiva mensagem e enviá-la manualmente.

Critérios para aceitação:

 -Fornecer a opção, de dentro da caixa de entrada re-enviar uma mensagem, como se fosse um email próprio,
  seguindo os mesmos procedimentos de envio padrão para um ou mais destinatários.
 
# 3º)
Como usuario desse sistema espero poder, caso eu precise, modificar o meu nome
de usuário e/ou a senha, dentro do programa, para não ser necessário a criação
de uma nova conta e mover toda a caixa de entrada e saída.

Critérios para aceitação:

 -Inserir o novo nome da conta.
 -Verificar se ha conflito com o nome de outros usuários cadastrados.
 -Substituir o antigo nome no sistema.
 
 -Inserir a nova senha da conta.
 -Substituir a senha antiga.
 
 -Fechar a sessão para serem válidas as alterações feitas.

# 4º)
Como usuario desse sistema, gostaria poder listar as mensagens mais antigas
(de mais de um mes atrás) para deletá-las da caixa de entrada, com facilidade.

Critérios para aceitação:

 -Verificar na caixa de entrada as mensagens cujas variaveis que armazenam a data do envio
  tenham mais de um mês de diferença em relação a data atual e listá-las na tela.
 -Deletá-las a pedido do usuário.

# 5º)
Como usuario desse sistema, desejaria poder deletar minha conta , de dentro do programa,
apagando todos os dados referentes ao meu usuario, incluindo seus respectivos diretórios,
para amenizar um pouco o espaço ocupado pelo programa.

Critérios para aceitação:

 -Perguntar ao usuário se ele realmente deseja realizar essa ação.
 -Caso sim, remover o seu nome da lista de cadastrados no sistema.
 -Deletar os diretórios reservados às suas caixas de mensagens enviadas e recebidas.
 -Finalizar a sessão.

# 6º)
Como usuario desse sistema, queria poder escolher entre listar na caixa de entrada apenas
as mensagens não lidas/lidas, para facilitar na visualização da caixa de entrada.

Critérios para aceitação:

 -Escolha de qual tipo de mensagem deve ser listada exclusivamente.
 -Verificar na caixa de entrada, as mensagens cuja variável do tipo bool de seus objetos correspondem
  com a escolha feita.
 -Listar na tela essas mensagens.
