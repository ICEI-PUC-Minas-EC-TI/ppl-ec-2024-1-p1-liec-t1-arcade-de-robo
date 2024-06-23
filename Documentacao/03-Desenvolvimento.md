
# Materiais

Os materiais utilizados no projeto foram:
- 3 Esp's 32 
- 2 kits chassis 2wd
- 2 ponte h dupla l298n
- 2 micro servo 9g
- Cabos jumpers femea-femea
- Cabos jumpers macho-femea
- Resistores de 560Ω
- Kit joystick arcade
- 1 protoboard

# Desenvolvimento

Para o desenvolvimento do trabalho, o grupo foi dividido em 4 para a realizacao de cada etapa, sendo 4 grupos de 2 pessoas, 1 grupo para o desenvolvimento do aplicativo, 1 grupo para cada robo e 1 para o arcade. Os materias utiliaados foram separados para cada grupo de acordo com a demanda. Alguns grupos necessitaram de equipamentos como Multimetro, Cola quente e Ferro de Solda.

## Desenvolvimento do Aplicativo

### Interface

O aplicativo foi desenvolvido inicialmente com organizadores horizontais para a separacao de cada funcionalidade com o objetivo de melhorar a interface do app. Fizemos um Cabecalho com a imagem do trabalho e seu nome. Apos isso, foi utilizado um "escolhe lista" para a selecao de dispositivos bluetooth a serem conectados. Alem disso, foram utilizados botoes para ativas as funcionalidades do robo, como atacar, andar para a frente, tras, direira, etc.

### Código

Quando o "escolhe lista" da interface do app for selecionado, aparecera os dispositivos possiveis para conexao. Apos escolhido, sera verificado se o bluetooh esta ou nao conectado ao robo. Caso esteja conectado, ele ira mudar a cor de fundo do "escolhe lista" para azul, indicara "jogador conectado", e enviara um texto "9" para o cliente bluetooth. Alem disso, quando um dos botoes da interface for clicado, caso o cliente esta conectado, enviara um texto de "0" ate "9" com o objetivo de controlar o robo. Caso o cliente bluetooth nao esteja conectado, o texto do "escolhe lista" mudara para "nenhum jogador encontrado" e a cor de fundo para vermelho.

## Desenvolvimento do Hardware

### Montagem

Montagem dos robos: Cada componente foi separado e colocado em sua devida ordem, sendo -> suporte para pilha, motores, roda giratoria, ponte H, e micro servo. Cada componente foi conectado a partir de jumpers macho-femea e femea-femea, alem de cabos vindos no kit chassis 2wd.

Montagem do Arcade: Foi usada a proto board para a conexao de 8 botoes de 30mm, 2 de 2.4mm e um joystick de arcade. Como todos funcionam a partir de botoes, foram conectados no 3.3V e no GND suas saidas, e antes de chegar no GND, foram conectadas as portas digitais indicadas como entradas.

### Desenvolvimento do Código

Para os robos, os codigos necessitaram de incluir as bibliotecas ESP32Servo.h e bluetoothSerial.h. foram criadas variaveis para os motores, para o bluetooth serial, para o servo e para o cooldown do servo. Caso o bluetooh esteja conectado, ele ira receber um valor que sera lido em uma variavel char, e sera conferido para as funcionalidades do robo.

Para o arcade, foi incluido a biblioteca bluetoothSerial.h, variaveis foram criadas para a definicao de portas dos botoes, foi criada uma variavel para o endereco MAC de um dos robos, uma variavel booleana para a verificacao da conexao bluetooth, um procedimento para a verificacao da conexao bluetooh, cada porta indicada pela variavel foi definida como entrada, e no void loop e conferido se o bluetooh esta conectado. Caso nao esteja, ele sera reconectado, e caso esteja, verificara se cada uma das condicoes e atendida e enviara uma informacao para o dispositivo conectado.

## Comunicação entre App e Hardware

Fizemos a comunicacao entre app e hardware via bluetooth. Ela foi feita a partir de variaveis do tipo char para verificar as condicoes para a ativacao de funcionalidades do robo.
