#include <stdio.h>
#include <wchar.h>
#include <string.h>

typedef struct{
    char valor[3];
    wchar_t naipe;
}carta;

int valores(carta c1, carta c2){
    char *ordem[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "C", "Q", "K"}; // Oooga booga 1=10
    wchar_t ordem2[4] = {L'♠', L'♥', L'♦', L'♣'};
    int i,tc1=0,tc2=0,nc1=0,nc2=0;

    for(i=0;i<14;i++){
        wprintf(L"%ls %ls\n", c1.valor,ordem[i]);
        if (strcmp(c1.valor,ordem[i]) == 0){
            tc1 = i;
            break;
        } 
    }
    for(i=0;i<14;i++){
        if (strcmp(c2.valor,ordem[i]) == 0){
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

int combinacao(carta mao[14]){
    int i=0,n=0,flag=0;
    for(i=0; mao[i].valor[0] != '\0';i++){
        n++;
    }
    //Conjunto (1)
    if (n > 0 && n <= 4){
        for (i = 0; i < 14 && mao[i+1].valor[0] != '\0'; i++){
            //wprintf(L"mao[i].valor = %ls\n",mao[i].valor);
            if (mao[i].valor[0] != mao[i+1].valor[0]){
                //wprintf(L"%ld\n",i);
                flag = 1;
            }
        }
        if (flag == 0) return 1;
    }
    //Sequência (2)
    //Dupla Sequência (3)
    if(n >= 3){
        for (i = 0; i < 14 && mao[i+1].valor[0] != '\0'; i++){
            if (mao[i].valor[0] != mao[i+1].valor[0]){ // If sequencia
                if(valores(mao[i],mao[i+1]) != 2){
                    return 0; 
                }
            }
            else{
                return 3;
            }
        }
        return 2;
    }
    return 0;
}

int main(){
    int i=0;
    carta mao[14] = {0};
    i=0;

    /*while (wscanf(L"%c %lc", &mao[i].valor, &mao[i].naipe) != EOF){ 
        //wprintf(L"%c %lc", mao[i].valor, mao[i].naipe);
        i++;
    }*/
    /*while (i<3){  
        wscanf(L"%ls %lc", &mao[i].valor, &mao[i].naipe);
        //wprintf(L"%ls %lc ", mao[i].valor, mao[i].naipe);
        i++;
    }

    int tipo_combinacao = combinacao(mao); 

    switch (tipo_combinacao) {
        case 0:
            wprintf(L"Nenhuma combinacao encontrada.\n");
            break;
        case 1:
            wprintf(L"Conjunto encontrado.\n");
            break;
        case 2:
            wprintf(L"Sequencia encontrada.\n");
            break;
        case 3:
            wprintf(L"Dupla sequencia encontrada.\n");
            break;
        default:
            wprintf(L"Tipo de combinacao desconhecido.\n");
    }

    wprintf(L"Carta mais alta: %ls %lc\n", mao[i-1].valor, mao[i-1].naipe);*/
    	
    mao[0].valor[0] = '2';
    mao[0].naipe = L'♠';
    mao[1].valor[0] = '3';
    mao[1].naipe = L'♠';  
    wprintf(L"Carta mais alta: Carta %ld \n", valores(mao[0],mao[1]));

    return 0;
}
