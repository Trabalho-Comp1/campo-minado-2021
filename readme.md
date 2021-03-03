# Relatório

[Link do vídeo]

[Apresentação](https://docs.google.com/presentation/d/1kPYTy1gmCrNahnZGKLKzQmf1kQleZbtqqvQgXkV9lOw/edit?usp=sharing)

## Objetivos do trabalho

O objetivo do trabalho foi desenvolver um jogo de campo minado que implementasse na prática os conceitos aprendidos em aula.

Buscamos implementar as funcionalidades básicas do Campo Minado e então incrementar o jogo finalizado com pequenas melhorias.

## Premissas consideradas no desenvolvimento do jogo

1ª: O usuário deve escolher a dificuldade. Essa dificuldade altera o tamanho do tabuleiro e a quantidade de bombas distribuídas pelo mesmo.

2ª: Ao selecionar uma casa que possua uma bomba, o usuário perde.

3ª: Quando o jogador termina de abrir todas as casas sem bomba, ele ganha.

Ao selecionar uma casa ≠ bomba, deve-se mostrar um número que representa a quantidade de bombas que existem em volta; ao selecionar uma casa que tenha o valor 0 — sem nenhuma bomba em volta —, o jogo libera as casas em volta automaticamente;

O jogador não pode perder na primeira jogada;

O jogador deve conseguir marcar uma casa em que ele acredite que tenha uma bomba.

5ª: Ao selecionar uma casa que tenha o valor 0 - nenhuma bomba em volta -, ele libera as casas em volta automaticamente.

6ª: O jogador não pode perder na primeira jogada.

7ª: O jogador pode marcar uma casa, com uma letra diferente, que ele acredite que tenha bomba.

## Regras

O jogador deve selecionar os espaços no tabuleiro criado de acordo com as posições indicadas nas bordas.

Se a casa escolhida for uma bomba o jogo acaba. Caso contrário, a casa escolhida é revelada e as casas livres ao redor dela também são. O jogo pede que você escolha uma nova casa dentre as opções ainda não reveladas.

Além disso, também é possível marcar uma casa na qual você ache que tenha uma bomba.

Ao escolher todas as casas sem bomba o jogo acaba e uma mensagem de vitória é exibida no console.

O objetivo do jogo é conseguir limpar o tabuleiro sem atingir nenhuma bomba.

## Saída da execução

A saída é em formato textual no terminal e o jogo se redesenha a cada movimento realizado, mantendo o terminal limpo.

(Adicionar prints? Tela inicial, escolhendo a dificuldade; tela de meio jogo, selecionando uma casa; tela final, mostrando vitória.)

### Tela inicial

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b66707a7-0035-4023-ab97-8c25a0736657/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b66707a7-0035-4023-ab97-8c25a0736657/Untitled.png)

### Tela de meio jogo 1

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1542743-aa36-45cd-b2e0-a55e2f0c359a/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1542743-aa36-45cd-b2e0-a55e2f0c359a/Untitled.png)

### Tela de meio jogo 2

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/917cf48e-2222-4ed9-a2de-5f95ad6deb76/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/917cf48e-2222-4ed9-a2de-5f95ad6deb76/Untitled.png)

### Tela de meio jogo 3

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b5becf92-017e-4780-82b3-099fdcf51cae/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b5becf92-017e-4780-82b3-099fdcf51cae/Untitled.png)

### Tela final - Vitória

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/245200d4-024a-46d5-ba74-7ee1a6db4565/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/245200d4-024a-46d5-ba74-7ee1a6db4565/Untitled.png)

## Ferramentas utilizadas

Utilizamos várias ferramentas aprendidas ao longo do curso, podendo citar: Elaboração de algoritmos, uso de variáveis e constantes, funções de entrada e saída pelo console, operadores em geral, estruturas condicionais e de repetição, funções, ponteiros e estruturas.

Também utilizamos algumas bibliotecas:

locale.h: usada para alterar a região;

wchar.h: usada para ampliar o conjunto de caracteres;

time.h: 

Além das bibliotecas básicas stdio.h e stdlib.h.