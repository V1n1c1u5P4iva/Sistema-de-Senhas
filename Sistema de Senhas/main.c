#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "sistema_senha.h"

int main() {
    Fila* f = fila_cria();
    int opcao, ordem = 1;
    setlocale(LC_ALL, "portuguese");

    do {
        system("CLS");
        printf("+---------------------------------------------+\n");
        printf("| 1-Incluir cliente                           |\n");
        printf("| 2-Realizar chamada                          |\n");
        printf("| 3-Consultar a posição atual de um cliente   |\n");
        printf("| 4-Listar a quantidade de clientes atendidos |\n");
        printf("| 5-Sair                                      |\n");
        printf("+---------------------------------------------+\n");

        printf("| Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char nome[50];
                fflush(stdin);
                printf("Digite o nome do cliente: ");
                scanf("%49[^\n]", nome);
                insere_cliente(f, nome);
                printf("Ordem de atendimento %d\n", ordem);
                ordem++;
                system("PAUSE");
                break;
            }
            case 2: {
                Senha* p = chamar_cliente(f);
                if (p != NULL) {
                    printf("| Cliente %s chamado para atendimento.\n", p);
                    free(p);
                } else {
                    printf("| Não há mais clientes na fila.\n");
                }
                system("PAUSE");
                break;
            }
            case 3: {
                char nome[50];
                printf("| Digite o nome do cliente que deseja consultar: ");
                scanf("%s", nome);
                consultar_posicao(f, nome);
                system("PAUSE");
                break;
            }
            case 4: {
                listar_quantidade(f);
                system("PAUSE");
                break;
            }
            case 5: {
                printf("| Saindo do programa.\n");
                system("PAUSE");
                break;
            }
            default: {
                printf("| Opção inválida. Tente novamente.\n");
                system("PAUSE");
                break;
            }
        }
    } while (opcao != 5);

    return 0;
}


