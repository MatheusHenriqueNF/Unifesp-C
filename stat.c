/***************************************************************************
 * Nome: Matheus Henrique Nascimento de Freitas                            *
 * RA: 168.680                                                             *
 * Ex 1 - Estatisticas                                                     *
 * Professor: Paulo Paiva                                                  *
 * Data: 04/09/2023                                                        *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 *************************************************************************** 
*/


#include <stdio.h>
#include <math.h>

#define TAM_MAX 100

//Calcular a média
float calcularMedia(float num[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += num[i];
    }
    return soma / n;
}

//Trocar dois valores
void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

//Ordenar o vetor em ordem crescente
void bubbleSort(float num[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                trocar(&num[j], &num[j + 1]);
            }
        }
    }
}

//Calcular a mediana
float calcularMediana(float num[], int n) {
    bubbleSort(num, n);
    
    if (n % 2 == 1) {
        return num[n / 2];
    } 
    
    else {
        float mediana = (num[n / 2 - 1] + num[n / 2]) / 2.0;
        return mediana;
    }
}

//Calcular o desvio padrão
float calcularDesvioPadrao(float num[], int n) {
    float media = calcularMedia(num, n);
    float somaDosQuadrados = 0;

    for (int i = 0; i < n; i++) {
        float diferenca = num[i] - media;
        somaDosQuadrados += diferenca * diferenca;
    }

    float variancia = somaDosQuadrados / n;
    float desvioPadrao = sqrt(variancia);
    return desvioPadrao;
}

int main() {
    int n;
    float num[TAM_MAX], media, mediana, menor, maior,dvp;
    
    do{
        printf("Quantos numeros na sua serie (N): ");
        scanf("%d", &n);
        
        if (n > TAM_MAX) {
            printf("Numero de serie superior ao limite 100!\n\n");
        }
        
        if(n == 0 || n == 1){
            printf("Quantidade de serie insuficiente!\n\n");
        }
        
    }while(TAM_MAX < n || n == 0 || n == 1);

    // Ler os valores da série
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%f", &num[i]);
    }
    
    // Inicializar menor e maior com o primeiro elemento do vetor
    menor = num[0];
    maior = num[0];
    
    for (int i = 1; i < n; i++) {
        if (num[i] < menor) {
            menor = num[i];
        }
        if (num[i] > maior) {
            maior = num[i];
        }
    }
    
    // Calcular a média
    media = calcularMedia(num, n);
    
    // Calcular a mediana
    mediana = calcularMediana(num, n);
    
    // Calcular desvio-padrao
    dvp = calcularDesvioPadrao(num, n);
    
    printf("---------------------------RESULTADO---------------------------");    
    printf("\nValor minimo: %.2f", menor);
    printf("\nValor maximo: %.2f", maior);
    printf("\nMedia: %.2f", media);
    printf("\nMediana da serie: %.2f\n", mediana);
    printf("Desvio Padrão das notas: %f", dvp);

    return 0;
}
