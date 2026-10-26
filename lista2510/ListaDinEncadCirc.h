#ifndef LISTA_DIN_ENCAD_CIRC_H
#define LISTA_DIN_ENCAD_CIRC_H

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;

Lista* cria_lista(void);

// funções implementadas pela Lista 

void imprime_lista(Lista *li);
int maior_matricula(Lista* li, int *mat);
int conta_aprovados(Lista *li);
int busca_ciclica(Lista *li, int k, struct aluno *al);
int remove_lista_pos(Lista* li, int pos);
int rotaciona_lista(Lista* li, int k);
int concatena_listas(Lista* li1, Lista* li2);
int josephus(Lista* li, int k, int *sobrevivente);

// as outras funções

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_inicio(Lista* li, struct aluno al);

int insere_lista_final(Lista* li, struct aluno al);

int insere_lista_ordenada(Lista* li, struct aluno al);

int remove_lista_inicio(Lista* li);

int remove_lista_final(Lista* li);

int remove_lista(Lista* li, int mat);

int busca_lista_pos(Lista* li, int pos, struct aluno *al);

int busca_lista_mat(Lista* li, int mat, struct aluno *al);

#endif
