# Trabalho 1 de Comp 1 2020.1 - Campo Minado
Desenvolvido por: Abid Lohan, Diego Matos e Lia Barcellos.

- [Vídeo](https://youtu.be/aDesnInUEEs)

- [Apresentação utilizada no vídeo](https://docs.google.com/presentation/d/1kPYTy1gmCrNahnZGKLKzQmf1kQleZbtqqvQgXkV9lOw/edit?usp=sharing)


## Objetivos do trabalho

O objetivo do trabalho foi desenvolver um jogo de campo minado que implementasse na prática os conceitos aprendidos em aula.

Buscamos implementar as funcionalidades básicas do Campo Minado e então incrementar o jogo finalizado com pequenas melhorias.

## Premissas consideradas no desenvolvimento do jogo

- 1ª: O usuário deve escolher a dificuldade. Essa dificuldade altera o tamanho do tabuleiro e a quantidade de bombas distribuídas pelo mesmo.

- 2ª: Ao selecionar uma casa que possua uma bomba, o usuário perde.

- 3ª: Quando o jogador termina de abrir todas as casas sem bomba, ele ganha.

- 4ª: Ao selecionar uma casa ≠ bomba, deve-se mostrar um número que representa a quantidade de bombas que existem em volta; ao selecionar uma casa que tenha o valor 0 — sem nenhuma bomba em volta —, o jogo libera as casas em volta automaticamente;

- 5ª: O jogador não pode perder na primeira jogada;

- 6ª: O jogador deve conseguir marcar uma casa em que ele acredite que tenha uma bomba.


## Regras

O jogador deve selecionar os espaços no tabuleiro criado de acordo com as posições indicadas nas bordas.

Se a casa escolhida for uma bomba o jogo acaba. Caso contrário, a casa escolhida é revelada e as casas livres ao redor dela também são. O jogo pede que você escolha uma nova casa dentre as opções ainda não reveladas.

Além disso, também é possível marcar uma casa na qual você ache que tenha uma bomba.

Ao escolher todas as casas sem bomba o jogo acaba e uma mensagem de vitória é exibida no console.

O objetivo do jogo é conseguir limpar o tabuleiro sem atingir nenhuma bomba.


## Saída da execução

A saída é em formato textual no terminal e o jogo se redesenha a cada movimento realizado, mantendo o terminal limpo. Abaixo, alguns prints que mostram o funcionamento do jogo:


### Tela inicial

![Tela Inicial](https://github.com/Trabalho-Comp1/campo-minado-2021/blob/master/images/tela-inicial.png)

### Tela de meio jogo 1

![Tela de Meio de Jogo 1](https://github.com/Trabalho-Comp1/campo-minado-2021/blob/master/images/tela-meio-jogo-1.png)

### Tela de meio jogo 2

![Tela de Meio de Jogo 2](https://github.com/Trabalho-Comp1/campo-minado-2021/blob/master/images/tela-meio-jogo-2.png)

### Tela de meio jogo 3

![Tela de Meio de Jogo 3](https://github.com/Trabalho-Comp1/campo-minado-2021/blob/master/images/tela-meio-jogo-3.png)

### Tela final - Vitória

![Tela Final - Vitória](https://github.com/Trabalho-Comp1/campo-minado-2021/blob/master/images/tela-vitoria.png)

### Tela final - Derrota

![Tela - Derrota](https://github.com/Trabalho-Comp1/campo-minado-2021/blob/master/images/tela-derrota.png)


## Ferramentas utilizadas

Utilizamos o ferramental teórico e prático aprendido ao longo do curso, podendo citar os seguintes conceitos: Elaboração de algoritmos, uso de variáveis e constantes, funções de entrada e saída pelo console, operadores em geral, estruturas condicionais e de repetição, funções, ponteiros, estruturas e modularização.

Utilizamos as bibliotecas básicas stdio.h e stdlib.h. Também utilizamos a biblioteca time.h para gerar um número aleatório na função [sortearMinas](utils/sortearMinas.c).

O código foi desenvolvido de forma colaborativa, parte dele de forma síncrona com o auxílio do [Visual Studio Live Share](https://visualstudio.microsoft.com/pt-br/services/live-share/) e parte de forma assíncrona.

Para compilar o código do jogo:
```
gcc -o build main.c globais.c -Wall -ansi -pedantic
```
