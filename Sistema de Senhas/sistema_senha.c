#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_senha.h"

struct fila {
    Senha* ini;
    Senha* fim;
    int atendidos;
};

struct senha {
    char nome[50];
    struct senha* prox;
};

Fila* fila_cria() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    f->atendidos = 0;
    return f;
}

void insere_cliente(Fila* f, char* nome) {
    Senha* p = (Senha*)malloc(sizeof(Senha));
    if (p == NULL) {
        printf("Erro: n�o foi poss�vel alocar mem�ria para o cliente.\n");
        return;
    }
    strcpy(p->nome, nome);
    p->prox = NULL;

    if (f->ini == NULL) {
        f->ini = p;
    } else {
        f->fim->prox = p;
    }
    f->fim = p;
}

Senha* chamar_cliente(Fila* f) {
    if (f == NULL || f->ini == NULL) {
        printf("N�o h� mais clientes na fila.\n");
        return NULL;
    }
    Senha* p = f->ini;
    f->ini = p->prox;
    if (f->ini == NULL) {
        f->fim = NULL;
    }
    f->atendidos++;
    return p;
}

void consultar_posicao(Fila* f, char* nome) {
    Senha* temp = f->ini;
    int pos = 1;
    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            printf("A posi��o do cliente %s �: %d\n", nome, pos);
            return;
        }
        temp = temp->prox;
        pos++;
    }
    printf("Cliente n�o encontrado na fila.\n");
}

void listar_quantidade(Fila* f) {
    printf("O n�mero de clientes atendidos �: %d\n", f->atendidos);
}
