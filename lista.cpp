#include<stdio.h>

struct No {

    int valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};


struct Lista {

    No* inicio, * fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return inicio == NULL;
    }

    void inserirInicio(int valor) { // O(1)
        n++;
        No* novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        novo->prox = inicio;
        inicio = novo;
    }

    void inserirFinal(int valor) { // O(1)
        n++;
        No* novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;
    }

    void imprimir() { // O(n)
        No* aux = inicio;

        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");
    }

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (tamanho() <= 1) {
            delete (inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No* remover = inicio;
        inicio = inicio->prox;
        delete (remover);
        n--;
    }

    void removerFinal() { // O(n)
        if (tamanho() <= 1) {
            delete (inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No* penultimo = inicio;
        while (penultimo->prox != fim) {
            penultimo = penultimo->prox;
        }
        delete (fim);
        penultimo->prox = NULL;
        fim = penultimo;
        n--;
    }

    void inserir(int valor, int pos) { // O(n)
        if (pos >= tamanho()) {
            inserirFinal(valor);
            return;
        }

        if (pos < 1) {
            inserirInicio(valor);
            return;
        }

        No* aux1 = inicio;
        for (int i = 0; i < pos - 1; i++) {
            aux1 = aux1->prox;
        }
        No* aux2 = aux1->prox;

        No* novo = new No(valor);
        aux1->prox = novo;
        novo->prox = aux2;
        n++;
    }

    void remover(int pos) { // O(n)
        if (pos <= 1) {
            removerInicio();
            return;
        }

        if (pos >= tamanho()) {
            removerFinal();
            return;
        }

        No* aux1 = inicio;
        for (int i = 0; i < pos - 2; i++) {
            aux1 = aux1->prox;
        }
        No* remover = aux1->prox;
        No* aux2 = remover->prox;
        aux1->prox = aux2;
        delete (remover);
        n--;
    }

    void removerUltimosN(int N) { // O(n)
        if (N >= n) {
            while (!vazia()) {
                removerInicio();
            }
        } else {
            int tamanhoOriginal = n;
            for (int i = 0; i < tamanhoOriginal - N; i++) {
                removerFinal();
            }
        }
    }

    void removerSegundoElemento() { // O(1)
        if (n >= 2) {
            No* aux = inicio->prox;
            inicio->prox = aux->prox;
            delete aux;
            n--;
        }
    }

    void inserirTamanhoNoFinal() { // O(1)
        inserirFinal(n);
    }

    void inserirNumerosDe1AteN(int N) { // O(N)
        for (int i = 1; i <= N; i++) {
            inserirFinal(i);
        }
    }

    void inserirNaPenultimaPosicao(int valor) { // O(n)
        if (n <= 1) {
            inserirInicio(valor);
        } else {
            inserir(valor, n - 1);
        }
    }
};

int main() {
    Lista l;

    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.inserir(13, 2);
    l.inserir(0, 0);
    l.inserir(50, 50);

    l.remover(4);
    l.remover(2);
    l.remover(1);

    l.imprimir();

    printf("%d\n", l.tamanho());

    l.removerUltimosN(2);
    l.removerSegundoElemento();
    l.inserirTamanhoNoFinal();
    l.inserirNumerosDe1AteN(5);
    l.inserirNaPenultimaPosicao(99);

    l.imprimir();

    return 0;
}

