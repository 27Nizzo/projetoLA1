#include <stdio.h>
#include <wchar.h>
#include <string.h>

typedef struct {
    char valor[4]; // Aumento do tamanho da string para acomodar "10"
    wchar_t naipe;
} carta;

int valores(carta c1, carta c2){
    char *ordem[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "C", "Q", "K"}; // Oooga booga 1=10
    wchar_t ordem2[4] = {L'♠', L'♥', L'♦', L'♣'};
    int i,tc1=0,tc2=0,nc1=0,nc2=0;
    
    for(i=0;i<14;i++){
        if (strcmp(c1.valor,ordem[i])){
            tc1 = i;
            break;       
        } 
    }
    for(i=0;i<14;i++){
        if (strcmp(c2.valor,ordem[i])){
            tc2 = i;   
            break;    
        } 
    }

    if (tc1 == tc2){
        for(i=0;i<4;i++){
            if (c1.naipe == ordem2[i]){
                nc1 = i;
                break;       
            } 
        }
        for(i=0;i<4;i++){
            if (c2.naipe == ordem2[i]){
                nc2 = i;
                break;       
            } 
        }
        if(nc1 > nc2) return 1;
        else if (nc1 == nc2) return 0;
        else return 2;
    }
    else{
        if(tc1 > tc2) return 1;
        else return 2;
    }
}

int combinacao(carta mao[14]) {
    int i = 0, n = 0, flag = 0;
    for (i = 0; mao[i].valor[0] != '\0'; i++) {
        n++;
    }

    //Conjunto (0)
    if (n > 0 && n <= 4) {
        for (i = 0; i < 14 && mao[i].valor[0] != '\0'; i++) {
            if (strcmp(mao[i].valor, mao[i + 1].valor) != 0 || mao[i].naipe == mao[i + 1].naipe) { // Correção da comparação de strings
                flag = 1;
            }
        }
        if (flag == 0)
            return 1;
    }
    //Sequência (1)
    //Dupla Sequência (2)
    if (n >= 3) {
        for (i = 0; i < 14 && mao[i].valor[0] != '\0'; i++) {
            if (strcmp(mao[i].valor, mao[i + 1].valor) != 0) { // If sequencia
                if (valores(mao[i], mao[i + 1]) != 2) {
                    return 0;
                }
            } else {
                return 3;
            }
        }
        return 2;
    }
    return 0;
}

int main() {
    int i = 0;
    carta mao[14];

    // Inicializa o array
    for (i = 0; i < 14; i++) {
        mao[i].valor[0] = '\0';
        mao[i].naipe = '\0';
    }

    i = 0;

    while (i<4){  
        wscanf(L"%s %lc", &mao[i].valor, &mao[i].naipe);
        wprintf(L"%s %lc ", mao[i].valor, mao[i].naipe);
        i++;
    }

    int tipo_combinacao = combinacao(mao);

    switch (tipo_combinacao) {
        case 0:
            printf("\nNenhuma combinacao encontrada.\n");
            break;
        case 1:
            printf("\nConjunto encontrado.\n");
            break;
        case 2:
            printf("\nSequencia encontrada.\n");
            break;
        case 3:
            printf("\nDupla sequencia encontrada.\n");
            break;
        default:
            printf("\nTipo de combinacao desconhecido.\n");
    }

    printf("Carta mais alta: %s %lc\n", mao[i - 1].valor, mao[i - 1].naipe); // Correção do acesso ao último elemento
    return 0;
}
