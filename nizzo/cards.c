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

const wchar_t* valores[] = {L"A", L"Dois", L"Tres", L"Quatro", L"Cinco", L"Seis", L"Sete", L"Oito", L"Nove", L"Dez", L"J", L"C", L"Q", L"K"};
const wchar_t* naipes[] = {L"Espadas", L"Copas", L"Ouros", L"Paus"};

void printCard(Carta c) {
    wprintf(L"%ls de %ls\n", valores[c.value], naipes[c.suit]);
}

int compareCards(Carta c1, Carta c2) {
    if (c1.value > c2.value) 
    {
        wprintf(L"A maior carta é ");
        printCard(c1);
    } else if (c1.value < c2.value) {
        wprintf(L"A maior carta é ");
        printCard(c2);
    } else if(c1.suit > c2.suit) {
        wprintf(L"A maior carta é ");
        printCard(c1);
    } else {
        wprintf(L"A maior carta é ");
        printCard(c2); 
    }

    return 0;
}

int main() {
    int numCards;
    wprintf(L"Digite o número de cartas: ");
    wscanf(L"%d", &numCards);

    Carta cards[numCards];
    // Aqui você pode preencher o array 'cards' com as cartas que desejar

    if(numCards >= 2) {
        compareCards(cards[0], cards[1]);
    } else {
        for(int i = 0; i < numCards - 1; i++) {
            compareCards(cards[i], cards[i+1]);
        }
    }
    return 0; 
}
