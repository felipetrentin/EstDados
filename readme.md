# Trabalho de estrutura de dados

<h1> por Felipe Trentin, Gabriela Rocha e Marina J. Ramalho <h1>

~ Sumário ~
1. [Objetivos](#objetivos)
2. [Proposta](#proposta)
3. [Estruturas](#estruturas)

## Objetivos

**Implementação de Estruturas Básicas de Dados:** Nesta tarefa o objetivo é implementar pelo menos 10 das seguintes estruturas de dados: 
Lista simplesmente encadeada, lista duplamente encadeada, pilha, fila, árvore binária, árvore de busca binária, heap binário, tabela de hash, trie, grafo direcionado, grafo não direcionado, grafo ponderado, fila de prioridade, fila de dupla prioridade, deque, árvore avl, árvore b, árvore b+, fila circular, matriz esparsa, árvore de fenwick, skip list, bitset, bloom filter, árvore de segmentos.

Compare pelo menos 10 estruturas de dados em relação aos seguintes itens para todos os atributos da sua base de dados: (i) tempo de inserção, (ii) tempo de remoção, (iii) tempo de busca, (iv) uso de memória, (v) desempenho em casos extremos, (vi) complexidade assintótica, (vii) número de operações, (viii) fator de carga, (ix) taxa de colisão, (x) estabilidade e (xi) concorrência. Além disso, deve-se realizar uma análise crítica das estruturas de dados e suas vantagens e desvantagens.

**Estruturas e Algoritmos de Dados Avançados:** Nesta tarefa o objetivo é criar três novas estruturas de dados. Avalie-os pelas mesmas métricas do item anterior e realize a análise crítica de sua funcionalidade.
  
**Algoritmos de Otimização e Busca por Melhores Caminhos:** Nesta tarefa o objetivo é otimizar tarefas com base na prioridade (por exemplo, serviços de emergência). Deve-se convergir todos os itens anteriores, de forma que se possa representar cenários urbanos complexos. Avalie o tempo de resposta das soluções propostas e sua eficiência em termos de roteamento e utilização dos recursos.

## Proposta

A ideia deste trabalho é o desenvolvimento de um jogo de gerenciamento de unidades de emergência com base no dataset:  911 Calls for Service [1 Million record] (https://www.kaggle.com/datasets/ahmadrafiee/911-calls-for-service-metadata-1-million-record/data).
O jogo se trata de um “replay” das ocorrências notificadas via o número de emergências 911 dos Estados Unidos, mais especificamente na cidade de Baltimore, Maryland. Será baseado em C/C++ e terá como engine gráfico o SFML (Simple and Fast Multimedia Library).
Dessa forma o jogador, junto com os dados disponíveis em sua mesa de controle, deverá direcionar unidades para as áreas afetadas, escolhendo o melhor caminho e unidade correta para a ação.
O dataset será ordenado previamente para que seja separado um número de ocorrências a serem atendidas em cada fase.  Os arquivos carregados serão transpostos para uma lista circular, que servirá como roleta e sorteará um caso para ser atendido, conforme um número aleatório. Em seguida, o caso sorteado será transposto para uma   lista  com prioridade, e 
As ocorrências chamadas vão aparecer na tela do jogador na forma de uma  lista com prioridade. A ordem dos itens será dada por tal prioridade, calculada a partir de uma função que leva em consideração o nível do ocorrido (normal, urgência ou emergência) e o tempo corrido após o chamado. Haverá uma contagem de tempo a cada ocorrência e um tempo limite para atendê-la. Caso o tempo corrido chegue a zero, a ocorrência é dada como não atendida, o jogador recebe uma penalidade, e o acúmulo de penalidades leva a demissão do jogador de sua função de expedidor, assim perdendo o jogo.
Cada unidade de atendimento (carro de polícia, caminhão de bombeiro, ambulância, etc.) será tratada como um mesmo objeto, independente de seu tipo, mas possuem valores específicos como identificador único, capacidade de atendimento, tipo de atendimento (bitmask) e velocidade para movimentação. Estas unidades estão livres para percorrer o mapa e visitar postos de atendimento. 
Por exemplo, um caminhão de bombeiros pode ter o mesmo tipo de atendimento que um carro dos bombeiros, porém sua capacidade de atendimento será menor. Entretanto, o carro dos bombeiros pode ser mais rápido e por isso contar como vantagem para o jogador.
De maneira similar, os postos de atendimento estarão dispersos pelo mapa, e podem armazenar unidades assim como recarregar a capacidade de atendimento das mesmas. Apenas certos tipos de unidade podem ser comportadas em cada posto, com certas unidades não recarregando a sua capacidade, e outras sendo impossíveis de se alojar no local.  Além disso, as unidades serão alojadas dentro do posto de atendimento  em arrays (sem ordem), pilhas (Last In First Out) ou em filas (First In First Out), dependendo do alojamento. Dessa forma, o jogador deverá controlar a ordem que coloca as unidades, para não ter que deslocar várias unidades para liberar uma em específico.
Para manter o controle da situação, o jogador estará acompanhado de um software de alta tecnologia capaz de computar o caminho mais curto de unidades até as ocorrências, através de Matrizes de Adjacência, além de mostrar possíveis soluções para certas ocorrências, utilizando árvores de decisão. Porém as suas observações serão apenas superficiais, e seus conselhos serão ingênuos, portanto basta ao jogador escolher se deve seguir a interpretação do robô, ou seguir seu próprio raciocínio.

Estruturas implementadas:
- [Lista encadeada simples](src/LinkedList.cpp)
- [Lista circular](src/CircularList.cpp)
- [Lista com prioridade](src/PriorityList.cpp)
- [Fila](scr/NonWorking/Stack.cpp)
- [Pilha](scr/NonWorking/Queue.cpp)
- [Árvore de Decisão](src/)
- [Matrizes de Adjacência e Grafos](src/graph.cpp)

## Estruturas
### Lista Encadeada Simples
Complexidade:

Espaço $O()$

Tempo $O()$

### Lista Circular
Complexidade:

Espaço $O()$

Tempo $O()$


### Fila
Complexidade: 

Espaço $O()$

Tempo $O()$


### Pilha
Complexidade:

Espaço $O()$

Tempo $O()$


### Árvore de Decisão
Complexidade:

Espaço $O()$

Tempo $O()$


### Matrizes de Adjacência e Grafos
Complexidade:

Espaço $O()$

Tempo $O()$
