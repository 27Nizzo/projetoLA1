#include<stdio.h>
#include<wchar.h>

typedef enum {
    A,
    Dois,
    Tres,
    Quatro,
    Cinco,
    Seis,
    Sete, 
    Oito, 
    Nove, 
    Dez, 
    J, C, Q, K
} Valor;

typedef enum {
    Espadas,
    Copas,
    Ouros,
    Paus
} Naipe;


typedef struct {
    Valor value;
    Naipe suit;
} Carta;


int compareCards(Carta c1, Carta c2) {
    if (c1.value > c2.value) 
    {
        return 1;
    } else {
        return 2;
    }

    if(c1.value == c2.value) {
        if(c1.suit > c2.suit) {
            return 1;
        } else {
            return 2; 
        }
    }

    return 0;
}


int main() {
    Carta c1 = {A, Espadas};
    Carta c2 = {K, Copas};

    printf("%d\n", compareCards(c1, c2));
    return 0;
}