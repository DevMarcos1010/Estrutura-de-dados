
#include <stdio.h>
#include <string.h>
#include "ListaDinEncadCirc.h"

int main(void){
    struct aluno a1, a2, a3;
    Lista *li = cria_lista();

    int mats[] = {10, 22, 32, 43, 42};
    int notas[] = {7, 9, 10};

    a1.n1 = a2.n1 = a3.n1 = notas[0];
    a1.n2 = a2.n2 = a3.n2 = notas[1];
    a1.n3 = a2.n3 = a3.n3 = notas[2];

    a1.matricula = mats[0];
    a2.matricula = mats[1];
    a3.matricula = mats[2];

    insere_lista_inicio(li, a1);
    insere_lista_inicio(li, a2);
    insere_lista_inicio(li, a3);

    imprime_lista(li);
    int mat;
    maior_matricula(li, &mat);
    printf("%d\n", mat);
    printf("%d\n", conta_aprovados(li));
    struct aluno al;
    busca_ciclica(li, 2, &al);
    printf("%d | n = %lf\n", al.matricula, al.n1);
    printf("%d\n", remove_lista_pos(li, 2));

    printf("%d\n", rotaciona_lista(li, 1));
    Lista* li2 = cria_lista();
    concatena_listas(li2, li);
    imprime_lista(li2);

    int sobrevivente;
    josephus(li, 2, &sobrevivente);
    printf("%d\n", sobrevivente);

}