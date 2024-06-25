# Trabalho de estrutura de dados

<h3> por Felipe Trentin, Gabriela Rocha e Marina J. Ramalho </h3>

 _Sumário_ 
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

O dataset será ordenado previamente para que seja separado um número de ocorrências a serem atendidas em cada fase.  Os arquivos carregados serão transpostos para uma lista circular, que servirá como roleta e sorteará um caso para ser atendido, conforme um número aleatório. Em seguida, o caso sorteado será transposto para uma   lista  com prioridade, e as ocorrências chamadas irão aparecer na tela do jogador. A ordem dos itens será dada por uma prioridade, calculada a partir de uma função que leva em consideração o nível do ocorrido (normal, urgência ou emergência) e o tempo corrido após o chamado. Haverá uma contagem de tempo a cada ocorrência e um tempo limite para atendê-la. Caso o tempo corrido chegue a zero, a ocorrência é dada como não atendida, o jogador recebe uma penalidade, e o acúmulo de penalidades leva a demissão do jogador de sua função de expedidor, assim perdendo o jogo.
Cada unidade de atendimento (carro de polícia, caminhão de bombeiro, ambulância, etc.) é tratada como um mesmo objeto, independente de seu tipo, mas possuem valores específicos como identificador único, capacidade de atendimento, tipo de atendimento (bitmask) e velocidade para movimentação. Estas unidades estão livres para percorrer o mapa e visitar postos de atendimento. 
Por exemplo, um caminhão de bombeiros pode ter o mesmo tipo de atendimento que um carro dos bombeiros, porém sua capacidade de atendimento será menor. Entretanto, o carro dos bombeiros pode ser mais rápido e por isso contar como vantagem para o jogador.
De maneira similar, os postos de atendimento estão dispersos pelo mapa, e podem armazenar unidades assim como recarregar a capacidade de atendimento das mesmas. Apenas certos tipos de unidade podem ser comportadas em cada posto, com certas unidades não recarregando a sua capacidade, e outras sendo impossíveis de se alojar no local.  Além disso, as unidades serão alojadas dentro do posto de atendimento  em arrays (sem ordem), pilhas (Last In First Out) ou em filas (First In First Out), dependendo do alojamento. Dessa forma, o jogador deve controlar a ordem que coloca as unidades, para não ter que deslocar várias unidades para liberar uma em específico.
Para manter o controle da situação, o jogador estará acompanhado de um software de alta tecnologia, o Assistente JJ, capaz de computar o caminho mais curto de unidades até as ocorrências, através de Matrizes de Adjacência, além de mostrar possíveis soluções para certas ocorrências, utilizando árvores de decisão. Porém as suas observações serão apenas superficiais, e seus conselhos serão ingênuos, portanto basta ao jogador escolher se deve seguir a interpretação do robô, ou seguir seu próprio raciocínio.

Estruturas implementadas:
- [Lista encadeada simples](src/LinkedList.cpp)
- [Lista circular](src/CircularList.cpp)
- [Lista com prioridade](src/PriorityList.cpp)
- [Fila](scr/NonWorking/Stack.cpp)
- [Pilha](scr/NonWorking/Queue.cpp)
- [Árvore de Decisão](src/DecisionTree.cpp)
- [Árvore AVL](src/AvlTree.cpp)
- [Matrizes de Adjacência e Grafos](src/graph.cpp)

## Estruturas
### Lista Encadeada Simples
Complexidade para o caso médio:

Tempo:
Inserção $O(1)$
Remoção $O(1)$
Busca $O(n)$

Espaço $O(n)$

A Lista Ligada traz como vantagens a alocação dinâmica de memória, que não precisa estar em blocos contíguos como um array, além da facilidade de inserção e remoção de informações. O que possibilidade maior flexibilidade ao armazenar e manipular os dados. Contudo, como precisa guardar seus dados e um ponteiro, acaba ocupando mais espaço do que um array comum.

### Lista Circular
Complexidade para o caso médio:

Tempo:
Inserção $O(1)$
Remoção $O(1)$
Busca $O(n)$

Espaço $O(n)$

Funciona com as mesmas vantagens da lista ligada, contudo, o último elemento da sua lista tem um ponteiro que aponta para o primeiro. Essa estrutura foi escolhida para fazer o lançamento de ocorrências a serem solucionadas pelo jogador, a fim de trazer aleatoriedade como uma espécie de roleta de ocorrências. Essa estrutura foi utilizada pois além de facilitar a remoção, inserção e flexibilidade de alocação de memória, ela poderia ser percorrida circularmente por um determinado número de vezes, sem muito esforço. 

### Lista com prioridade
É uma combinação entre Fila com prioridade e lista ligada. Precisávamos de uma estrutura que armazenasse a prioridade, porém permitisse a remoção em qualquer ponto, sem utilizar outras estruturas auxiliares. Logo, implementou-se a lista com prioridade.

### Fila
Complexidade para o caso médio:

Tempo:
Inserção $O(1)$
Remoção $O(1)$
Busca $O(n)$

Espaço $O(n)$

Estrutura de dados que armazena contiguamente a informação, com ajuda de dois sentinelas (de inicio e fim, ou cabeça e cauda). Utiliza o princípio do First In First Out (FiFO) para gerenciar suas operações de remoção e inserção. A inserção só é feita a partir do último nó e sempre o primeiro que pode ser removido. Foi escolhida essa estrutura de dados para servir como um estacionamento  "drive-thru"  para os veículos, que estará presente em alguns locais (vértices dos grafos). Assim, por seguir essas condições mais específicas de remoção e inserção, ela traz mais diversidade para o jogo.

### Pilha
Complexidade para o caso médio:

Tempo:
Inserção $O(1)$
Remoção $O(1)$
Busca $O(n)$

Espaço $O(n)$

A pilha funciona de modo semelhante à fila, porém se baseia no princípio do Last in First Out. A inserção só é feita no topo, e também só se pode remover do topo. Ela foi implementada para funcionar como um estacionamento de apenas uma saída, em que o último a entrar precisa ser o primeiro a sair.

### Árvore de Decisão
Complexidade para o caso médio:

Tempo:
Inserção $O(log(n))$
Remoção $O(log(n))$
Busca $O(log(n))$

Espaço $O(n)$

A árvore de decisão será implementada no AssistenteJJ que vai auxiliar o jogador a tomar a melhor decisão de caminho para atender as ocorrências.

## Árvore AVL
Complexidade para o caso médio:

Tempo:
Inserção $O(log(n))$
Remoção $O(log(n))$
Busca $O(log(n))$

Espaço $O(n)$

A árvore AVL possui a característica de ser uma árvore binária de busca balanceada, o que reduz o tempo de comparação, pois mantém seu balanceamento. Por isso ela foi escolhida para desempenhar o gerenciamento dos veículos no mapa. Ela controla a inserção, movimentação e remoção dos veículos do mapa, bem como sua busca, que é mais eficiente do que a de outras estruturas. Além disso ela permite fácil remoção e inserção, de forma organizada a manter seu balanceamento, bem como aloca memória dinamicamente. Isso foi essencial pois os veículos são tratados aqui como estruturas dinâmicas. 

### Matrizes de Adjacência e Grafos
Complexidade para o caso médio:

Tempo $O(n^2)$
Espaço $O(n^2)$

Matrizes de adjacência é um dos jeitos que se pode visualizar um grafo. Ela é a base para o nosso mapa, com os vértices sendo os locais, por exemplo casas, hospitais, postos de polícia etc, e as arestas sendo as ruas e avenidas por onde os carros irão passar. 