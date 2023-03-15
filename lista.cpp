#include <stdio.h>

struct No{

    int valor;
    No *prox;

};

struct Lista {

    No *cabeca, *cauda;
    int n;

    Lista(){

        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia(){

        return (cabeca == NULL);
    }

    void inserirInicio(int v){

        No *novo = new No();
        novo->valor = v;

        if(vazia()){

            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        }
        else{
            novo->prox = cabeca;
            cabeca = novo;
        }

        n++;
    }

    void inserirFinal(int v){

        No *novo = new No();
        novo->valor = v;

        if(vazia()){

            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        }
        else{
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }

        n++;

    }

    void imprimir(){

        if(vazia()){
            printf("Lista vazia!\n");
        }

        No *aux = cabeca;

        while(aux != NULL) {

            printf("%d\n", aux->valor);
            aux = aux->prox;

        }
    }

    /*
    int tamanho(){

        int t = 0;

        No* aux = cabeca;

        while(aux != NULL){

            t++;
            aux = aux->prox;
        }

        return t;
    }
    */

    int tamanho(){

        return n;

    }


    void excluirFinal(int x){

        if(n < x){

            cabeca = cauda = NULL;
            n = 0;
            return;

        }

        No* atual = cabeca;
        No* anterior = NULL;

        for(int i = 0; i < tamanho() - x; i++){
            anterior = atual;
            atual = atual->prox;
        }

        if(anterior == NULL){
            cabeca = NULL;
        }
        else{
            anterior->prox = NULL;
        }

        cauda = anterior;
        n = n - x;
    }


    void excluirSegundoElemento(){

        if(n <= 1){
            return;
        }

        No* segundo = cabeca->prox;

        cabeca->prox  = segundo->prox;
        delete segundo;

        n--;
    }

    void inserirTamanhoFinal(){

        inserirFinal(tamanho());

    }

    void inserirUmAteN(int x){

        for(int i = 1; i <= x; i++){
            inserirFinal(i);
        }

    }

    void inserirPenultimaPos(int v){

        if(n <= 1){
            return;
        }

        No* novo = new No();

        No* penultimo = cabeca;

        while(penultimo->prox != cauda){
            penultimo = penultimo->prox;
        }

        novo->valor = v;
        novo->prox = penultimo->prox;
        penultimo->prox = novo;

        n++;
    }

};


int main(){

    Lista l;

    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);

    l.imprimir();
    printf("\n");

    l.excluirFinal(9);

    l.imprimir();
    printf("\n");

    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(10);
    l.inserirFinal(8);
    l.inserirFinal(2);
    l.inserirFinal(3);

    l.imprimir();
    printf("\n");

    l.excluirFinal(2);

    l.imprimir();
    printf("\n");

    l.excluirSegundoElemento();

    l.imprimir();
    printf("\n");

    l.inserirTamanhoFinal();

    l.imprimir();
    printf("\n");

    l.inserirUmAteN(9);
    l.imprimir();
    printf("\n");

    l.inserirPenultimaPos(133);
    l.imprimir();

    return 0;
}
