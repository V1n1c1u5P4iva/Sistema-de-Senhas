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
        printf("Erro: não foi possível alocar memória para o cliente.\n");
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
        printf("Não há mais clientes na fila.\n");
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
            printf("A posição do cliente %s é: %d\n", nome, pos);
            return;
        }
        temp = temp->prox;
        pos++;
    }
    printf("Cliente não encontrado na fila.\n");
}

void listar_quantidade(Fila* f) {
    printf("O número de clientes atendidos é: %d\n", f->atendidos);
}
