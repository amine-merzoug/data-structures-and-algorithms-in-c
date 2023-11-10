# JEU MASTERMIND

## But 

Dans ce jeu, 2 joueurs s'affrontent : 

- Un codificateur (codemaker). 
- Un décodeur (codebreaker).

[comment]: #![](./fig_1.png)

<img src="fig_1.png" width="350" height="380">

Le décodeur doit deviner, par déductions successives, la couleur et la position de 5 pions cachés derrière un écran placé par le codificateur.

## Jeu 

Le codificateur place 5 pions de son choix, pris parmi 8 couleurs, derrière l'écran.

C'est au décodeur de jouer : il met 5 pions. 

- Si l'un des pions de sa proposition correspond "**par sa couleur et sa position**" à un pion caché, le codificateur l'indique en signalant "**un pion bien placé**". 
- Si l'un des pions correspond uniquement par sa "**couleur**", le codificateur l'indique en signalant "**un pion mal placé**". 
- 
  Le décodeur propose de nouvelles combinaisons jusqu'à ce que le codificateur réponde par "**5 pions bien placés**" ou que le nombre d'essais maximal soit atteint.

## Travail demandé

Avec la structure de données suivante :

```c++
const int NUM_PAWNS    = 5;
const int NUM_COLORS   = 8;
const int NUM_ATTEMPTS = 10;

enum color_t{RED, GREEN, BLUE, YELLOW, BLACK, WHITE, GRAY, PURPLE};

typedef color_t board[NUM_PAWNS];
```

1. Écrire la fonction ```retrieve_proposition()``` qui récupère la proposition du décodeur. 
   
   ```C++ 
   void retrieve_proposition(board proposition);
   ```

2. Écrire la fonction ```evaluate_proposition()``` qui compare la combinaison du codificateur et la proposition du décodeur et déduit le nombre de pions bien placés et le nombre de pions mal placés.

    ```C++
    void evaluate_proposition(board combination, board proposition, int &num_well_placed_pawns, int &num_misplaced_pawns);
    ```

3. Écrire la fonction ```game()``` qui déroule le jeu jusqu'à ce que le décodeur devine la combinaison du
codificateur, ou que le nombre d'essais maximal soit atteint.

    ```C++
    void game();
    ```

![](./fig_2.jpg)