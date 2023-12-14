typedef struct fila Fila;

typedef struct senha Senha;

Fila* fila_cria();

void insere_cliente(Fila* f, char* nome);

Senha* chamar_cliente(Fila* f);

void consultar_posicao(Fila *f, char* nome);

void listar_quantidade(Fila* f);


