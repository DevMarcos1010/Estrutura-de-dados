/* ============================================================
   ListaDinEncadCirc.c
   Estrutura de Dados I - UFPB - Aula 07
   Lista dinamica encadeada circular

   Implementacao identica a apresentada nos slides da Aula 07.
   A definicao de struct elemento esta aqui, e nao no .h: e isso
   que torna Lista um tipo opaco. Quem usa a biblioteca enxerga
   apenas Lista* e os prototipos declarados no cabecalho.

   Qualquer funcao nova que precise percorrer a lista no a no
   tem de ser escrita NESTE arquivo, porque e aqui que os campos
   dados e prox sao visiveis.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadCirc.h"

/* Definicao do tipo lista: oculta de quem usa a biblioteca. */
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

/* --- Implementação das funções da Lista -------------------- */

// Q1
void imprime_lista(Lista* li) {
    Elem *no = *li; 

    do {
        printf("%d ", no->dados.matricula);
        no = no->prox;

    } while(no->prox == *li);
    println("");
}

// Q2
int maior_matricula(Lista* li, int *mat) {
    Elem *no = *li;
    *mat = NULL;

    do {
        if(no->dados.matricula > *mat)  *mat = no->dados.matricula; 

    }while(no->prox == li);

    if(*mat != NULL) return 1;

    return 0;
}

// Q3

/* 1o defeito) caso-base do while incorreto: com isso, o loop não encontra o caso de saída
 e o loop é executado indefinidamente, uma vez que em uma lista circular, o último elemento da lista
  aponta para o mesmo elemento que *li */

/* 2o defeito) */

int conta_aprovados(Lista* li){
    int cont = 0;
    Elem *no = *li;

    while(no != NULL){
        float media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3;
        if(media >= 7.0)
            cont++;
        no = no->prox;
    }
    return cont;
}

// Q4
int busca_ciclica(Lista* li, int k, struct aluno *al){
    if(k <= 0 || li == NULL || *li == NULL) return 0;

    Elem *no = *li; 
    int n = tamanho_lista(li);
    int m = k;
    int i = m % n; 
    
    if(i == 0) i = n;

    while(i != 0) {
        no = no->prox;
        i--;
    }

    *al = no->dados;
}

// Q5
int remove_lista_pos(Lista* li, int pos) {
    if(pos <= 0|| li == NULL || *li == NULL) return 0;
    int n =  tamanho_lista(li);
    int counter = 0;
    if(pos > n) return 0;
    Elem *aux, *no = li;

    do {
        if(pos == 1) remove_lista_inicio(li);

        counter++;
        aux = no;
        no = no->prox;

    }while(no->prox == *li || counter == pos);

    aux = no;
    no = no->prox;
    free(no);

    return 1;
}

// Q6
int rotaciona_lista(Lista* li, int k) {
    if(k <= 0 || li == NULL || *li == NULL) return 0;
    Elem *no = *li;

    for(int i = 0; i < k; i++) {
        no = no->prox;
    }

    *li = no;
    return 1;

}

// pergunta 1: para k pequeno, pode-se realizar a rotação da lista em O(1) empilhando o operador de seta k vezes. 
//(Ex.: p/ k =2, para acessar o elemento k+1, empilah-se (->) da seguinte maneira, partindo de *li: *li->prox->prox)

// pergunta 2: em uma lista encadeada não circular, para ter-se o efeito de rotação da ordem da lista, seria necessário
//  percorrer a lista inteira para resgatar o último elemento e, em seguida, realizar sucessivas operações para mover 
//  os k primeiros elementos para o final da lista. No pior caso, o custo dessa função seria de O(n^2).

// Q7
int concatena_listas(Lista* li1, Lista* li2) {
    if(li1 == NULL || li2 == NULL) return 0;
    if(*li1 == NULL) {
        *li1 = *li2;
        *li2 = NULL;
        return 1;
    }
    if(*li2 == NULL) {
        return 1;
    }

    Elem *no1 = *li1;
    Elem *no2 = *li2;

    do {
        no1 = no1->prox;
    } while(no1->prox != li1);

    do {
        no2 = no2->prox;
    } while(no2->prox != li2);

    no1->prox = *li2;
    no2->prox = *li1;

    *li2 = NULL;
}

// pergunta 1) Caso a representação da lista armazenasse o final da lista em *li, o custo dessa operação de concatenação seria O(1)

// Q8
int josephus(Lista* li, int k, int *sobrevivente) {
    if(li == NULL || *li == NULL || )
}

/* --- criacao e destruicao ---------------------------------- */

Lista* cria_lista(void) {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if (li == NULL)
        return;
    if ((*li) != NULL) {
        Elem *aux, *no = *li;
        /* para quando o seguinte ao atual e o inicio: uma volta completa */
        while ((*li) != no->prox) {
            aux = no;
            no = no->prox;   /* avanca antes de liberar */
            free(aux);
        }
        free(no);
    }
    free(li);               /* libera o bloco do inicio */
}

/* --- informacoes de estado --------------------------------- */

int tamanho_lista(Lista* li) {
    if (li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    do {                    /* do-while: o primeiro elemento tem de ser contado */
        cont++;
        no = no->prox;
    } while (no != (*li));
    return cont;
}

int lista_cheia(Lista* li) {
    (void) li;              /* parametro mantido por simetria com as demais */
    return 0;
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        return 1;           /* lista invalida */
    if (*li == NULL)
        return 1;           /* nenhum elemento alocado */
    return 0;
}

/* --- insercao ---------------------------------------------- */

int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;           /* sem memoria: a lista esta cheia */
    no->dados = al;
    if ((*li) == NULL) {    /* lista vazia: o no aponta para si mesmo */
        *li = no;
        no->prox = no;
    } else {
        Elem *aux = *li;
        while (aux->prox != (*li)) {   /* procura o ultimo */
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;           /* unica linha que difere da insercao no final */
    }
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*li) == NULL) {    /* lista vazia: o no aponta para si mesmo */
        *li = no;
        no->prox = no;
    } else {
        Elem *aux = *li;
        while (aux->prox != (*li)) {   /* procura o ultimo */
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;     /* o inicio nao muda */
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*li) == NULL) {    /* lista vazia */
        *li = no;
        no->prox = no;
        return 1;
    }
    if ((*li)->dados.matricula > al.matricula) {   /* insercao no inicio */
        Elem *atual = *li;
        while (atual->prox != (*li))               /* procura o ultimo */
            atual = atual->prox;
        no->prox = *li;
        atual->prox = no;
        *li = no;
        return 1;
    }
    /* insercao no meio ou no final: ant acompanha atual uma posicao atras */
    Elem *ant = *li, *atual = (*li)->prox;
    while (atual != (*li) && atual->dados.matricula < al.matricula) {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = no;
    no->prox = atual;
    return 1;
}

/* --- remocao ----------------------------------------------- */

int remove_lista_inicio(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;           /* lista vazia */
    if ((*li) == (*li)->prox) {   /* elemento unico: a lista fica vazia */
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while (atual->prox != (*li))  /* procura o ultimo */
        atual = atual->prox;
    Elem *no = *li;
    atual->prox = no->prox;       /* o ultimo passa a apontar para o segundo */
    *li = no->prox;               /* o segundo passa a ser o inicio */
    free(no);
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;           /* lista vazia */
    if ((*li) == (*li)->prox) {   /* elemento unico: a lista fica vazia */
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant = NULL, *no = *li;
    while (no->prox != (*li)) {   /* procura o ultimo, guardando o anterior */
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;         /* o penultimo passa a apontar para o inicio */
    free(no);
    return 1;
}

int remove_lista(Lista* li, int mat) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;           /* lista vazia */
    Elem *no = *li;
    if (no->dados.matricula == mat) {      /* remocao do inicio */
        if (no == no->prox) {              /* a lista fica vazia */
            free(no);
            *li = NULL;
            return 1;
        } else {
            Elem *ult = *li;
            while (ult->prox != (*li))     /* procura o ultimo */
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    /* para ao encontrar a matricula ou ao completar uma volta */
    while (no != (*li) && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if (no == (*li))
        return 0;           /* chave ausente */
    ant->prox = no->prox;
    free(no);
    return 1;
}

/* --- busca ------------------------------------------------- */

int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || (*li) == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    /* para no ultimo elemento ou ao alcancar a posicao desejada */
    while (no->prox != (*li) && i < pos) {
        no = no->prox;
        i++;
    }
    if (i != pos)
        return 0;           /* posicao inexistente */
    else {
        *al = no->dados;
        return 1;
    }
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL || (*li) == NULL)
        return 0;
    Elem *no = *li;
    /* para no ultimo elemento ou ao encontrar a matricula */
    while (no->prox != (*li) && no->dados.matricula != mat)
        no = no->prox;
    if (no->dados.matricula != mat)
        return 0;           /* chave ausente */
    else {
        *al = no->dados;
        return 1;
    }
}
