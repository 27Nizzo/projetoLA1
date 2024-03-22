#include <stdio.h>

void main(){
    char play[8];
    while (scanf("%s", &play) != EOF) {
        switch (play[2]){
        case 'd':
            printf("papel!\nPerdeste!\n");
            break;
        case 'p':
            printf("tesoura!\nPerdeste!\n");
            break;
        case 's':
            printf("pedra!\nPerdeste!\n");
            break;
        default:
            printf("Jogada invalida... Tenta novamente\n");
            break;
        }
    }
}
