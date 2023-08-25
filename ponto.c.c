//ponto.c - implementacao das funcoes que estão no ponto.h

#include "ponto.h" //incluindo o arquivo ponto.h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	struct ponto_{
		float x; //coord1
		float y; //coord2
	};


	PONTO* ponto_criar(float x, float y){ //PONTO é do tipo estruturado ponto

		PONTO* p = (PONTO*)malloc(sizeof(struct ponto_));

		if (p == NULL)
			exit(1);

		p->x = x; 
		p->y = y;

		return p; //ponteiro que aponta ao inicio da mem onde a struct PONTO do tipo ponto foi alocada dinamicamente
	}
	
	void ponto_apagar(PONTO *p){
		if(p != NULL) {  
		free(p);
		}
	}

    bool ponto_set(PONTO *p, float x, float y){ //apontando o ponteiro para outro valor
	    if (p == NULL) {
	        return false; // Ponteiro inválido
	    }
	    p->x = x;
	    p->y = y;

	    return true; // Modificação bem-sucedida

    }




	void escreverPonto(PONTO* p) {
		if (p != NULL){
			printf("Coordenadas do ponto: x = %.2f, y = %.2f\n", p->x, p->y);
		}else{
			printf("Ponto inválido\n");
		}
	}

