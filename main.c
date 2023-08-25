//main - programa que o user vai testar o meu TAD_circulo

#include "ponto.h"
#include "circulo.h"

#include <stdio.h>


int main(void){

	float xP, yP, xC, yC, raio;
	
	printf("Digite as coordenadas do ponto(x, y): ");
	scanf("%f %f", &xP, &yP); //acessamos à struct normal com ponto pq nao estamos usando ponteiro para usar seta

	PONTO* p = ponto_criar(xP, yP); //chamando a funcao já implementada no ponto.c

	printf("Digite as coordenadas do centro do circulo(x, y): ");
	scanf("%f %f", &xC, &yC);

	printf("Digite o raio do círculo: ");
	scanf("%f", &raio);

    CIRCULO* c = circulo_criar(p, raio);

    escreverPonto(p); // funcao que imprime na tela os pontos fornecidos pelo user


	float dist = distancia_ponto_circulo(p, c);
    printf("Distância entre o ponto e o centro do círculo: %.2f\n", dist);
    
    printf("Área do círculo: %.2f\n", circulo_area(c));
    
    ponto_dentro_circulo(p, c);
    
    ponto_apagar(p);
    //ponto_apagar(centro);
    circulo_apagar(c);

    return 0;
}

