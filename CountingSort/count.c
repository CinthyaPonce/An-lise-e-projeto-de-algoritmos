#include "stdio.h"
#include "stdlib.h"

void printvetor(int vetor[], int tamanho){
	for( int i = 1; i < tamanho; i++ )
		printf("%d ", vetor[i]);
}


void countingsort(int a[], int c[], int c1[], int b[], int k, int p, int tamanho){

    for( int i=0; i <= k; i++)
        c[i] = 0;

    for( int i=0; i <= p; i++)
        c1[i] = 0;


    for(int j=1; j < tamanho; j++){

        if(a[j] >= 0){
            c[a[j]] = c[a[j]] + 1;
        }
        else{
            c1[(-1*a[j])] = c1[(-1*a[j])] + 1;
        }
    }

    for(int i = p-1; i >= 0; i--)
        c1[i] = c1[i] + c1[i+1];

    c[0] = c[0] + c1[0];

    for(int i=1; i <= k; i++)
        c[i] = c[i] + c[i - 1];


    for (int j=tamanho-1; j >= 1; j--){
        if(a[j] >= 0){
            b[c[a[j]]] = a[j];
            c[a[j]] = c[a[j]] - 1;
        }
        else{
            b[c1[-1*a[j]]] = a[j];
            c1[-1*a[j]] = c1[-1*a[j]] - 1;
        }
    }

    for (size_t i = 0; i < tamanho; i++){
        a[i] = b[i];
    }

}

int acharmaior(int vetor[], int tamanho){

    int aux=0;
    for(int i=0; i<tamanho; i++){
        if(vetor[i] > aux)
        aux = vetor[i];
    }
    return aux;
}

int acharmenor(int vetor[], int tamanho){

    int aux=0;
    for(int i=0; i<tamanho; i++){
        if(vetor[i] < aux)
        aux = vetor[i];
    }
    return aux;
}

int main(void){

    char url[60] = "numeros.txt";
    FILE *arq;
    arq = fopen(url, "r");
    char info1[50],info2[50];
    int i=0,tamanho=0;

    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else{
        fgets(info1, sizeof(info1), arq);
        tamanho = atoi(info1);
    }

    int vetor[tamanho];

    while(fgets(info2, sizeof(info2), arq) != NULL){
        vetor[i] = atoi(info2);
        i++;
    }

    fclose(arq);

    int k = acharmaior(vetor, tamanho);
    int p = -1*acharmenor(vetor,tamanho);

    int b[tamanho];
    int c[k+1];
    int c1[p+1];

    printf("\nVetor: ");
    printvetor(vetor, tamanho);

    countingsort(vetor, c,c1, b, k,p, tamanho);

	printf("\n\nVetor processado: ");
	printvetor(vetor, tamanho);

}
