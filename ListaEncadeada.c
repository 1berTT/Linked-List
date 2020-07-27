#include <stdlib.h>
#include <stdio.h>

struct no{
	int elemento;
	struct no *prox;
};
typedef struct no NO;

struct hash{
    NO *lista;
};
typedef struct hash HASH;

NO *inicio;
NO *fim;
int tam = 0;

void addInicio(int elemento){

	NO *novo = malloc (sizeof(NO));
	novo->elemento = elemento;
	novo->prox=NULL;
	if(tam == 0){ //inicio == null
		inicio=novo;
		fim=novo;
	}else{
		novo->prox = inicio;
	}
	inicio = novo;
	tam++;
}

void addFim(int elemento){
    NO *novo = malloc (sizeof(NO));
    novo->elemento = elemento;
    novo->prox = NULL;
    if(tam == 0){
        inicio=novo;
    }else{
        fim->prox=novo;
    }
    fim=novo;
    tam++;
}

void addMeio(int elemento, int posicao){
    NO *novo = malloc (sizeof(NO));
    novo->elemento = elemento;
    novo->prox = NULL;
    if(posicao >= 0 && posicao <= tam){
        if(posicao == 0){
            addInicio(elemento);
        }else{
            if(posicao == tam){
                addFim(elemento);
            }else{
                NO *aux = inicio;
                aux=inicio;
                for(int i=0; i<posicao-1; i++){
                    aux = aux->prox;
                }
                novo->prox=aux->prox;
				aux->prox=novo;
				tam++;
            }
        }

    }
}

void removerInicio(){
    if(tam>0){
        NO *lixo=inicio;
        if(tam == 1){
            inicio=NULL;
            fim=NULL;
        }else{
            inicio=inicio->prox;
        }
        tam--;
        free(lixo);
    }
}

void removerFim(){
	if(tam>0){
        if(tam==1){
            removerInicio();
        }else{
            NO *aux = inicio;
            for(int i=0; i<tam-2;i++){
                aux = aux->prox;
            }
            aux->prox = NULL;
            tam--;
        }
	}
}

void removerPosicao(int posicao){
    if(posicao == 0){
        removerInicio();
    }else if(posicao == tam-1){
        removerFim();
    }else{
        NO *aux = inicio;
        for(int i=0; i<posicao-1; i++){
            aux = aux->prox;
        }
        NO *lixo = aux->prox;
        aux->prox = aux->prox->prox;
        free(lixo);
        tam--;
    }
}

void imprime() {
   NO *aux;
   for (aux = inicio; aux != NULL; aux = aux->prox){
    	printf ("%d ", aux->elemento);
   }
   printf("\n");
}

int funcaoHash(int chave){
    return chave % 5;
}

void main(){
//    addInicio(20);
  //  addInicio(30);
   // addFim(21);
 //   addInicio(44);
   // addMeio(3, 0);
  //  printf("%i", tam);
  //  printf("\n");
   // imprime();
    //removerInicio();
    //removerFim();
    //removerFim();
    //removerPosicao(1);
    //imprime();

    int vetorHash[10];
    int chave = 13;
    int x = funcaoHash(chave);
    vetorHash[x] = chave;
    printf("%i", x);




}
