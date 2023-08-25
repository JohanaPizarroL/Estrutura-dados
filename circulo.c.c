//circulo.c - implementacao das funcoes que estão no circulo.h

//ponto.c - implementacao das funcoes que estão no ponto.h

#include "circulo.h"//incluindo o arquivo ponto.h
//#include "ponto.h" 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	struct circulo_{
    PONTO* centro;
    float raio;
	};


    CIRCULO* circulo_criar(PONTO *p, float raio){

		CIRCULO* c = (CIRCULO*)malloc(sizeof(struct circulo_));

		if (c == NULL)
			exit(1);

		c->centro = p; 
		c->raio = raio;

		return c;
	}

	void circulo_apagar(CIRCULO *circ){
	    free(circ);
	}


	float circulo_area(CIRCULO *circ) {
	    // Área = pi * raio^2
	    float area = M_PI * (circ->raio * circ->raio); //uso da constante pi da biblioteca math.h

	    return area; 
	}


	float distancia_ponto_circulo(PONTO *p, CIRCULO *circ){

	    // Calcula a diferença entre as coordenadas x e y do ponto e do centro do círculo
	    float diferencaX = p->x - circ->centro->x;
	    float diferencaY = p->y - circ->centro->y;

	    // Calcula o quadrado da distância horizontal e vertical
	    float quadradoDistanciaX = diferencaX * diferencaX;
	    float quadradoDistanciaY = diferencaY * diferencaY;

	    // Calcula a distância usando o teorema de Pitágoras (hipotenusa do triângulo retângulo)
	    float distancia = sqrt(quadradoDistanciaX + quadradoDistanciaY);

	    return distancia;
	}


	void ponto_dentro_circulo(PONTO *p, CIRCULO *circ) {
	    // Calcula a distância entre o ponto e o centro do círculo usando a função de distância
	    float dist = distancia_ponto_circulo(p, circ);

	    if(dist == circ->raio){
	        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
	    }else if(dist < circ->raio){
	        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
	    }else{
	        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
	    }
	}
