
#include <stdio.h>
#include <string.h>
#include "ListaDinEncadCirc.h"

static struct aluno mk(int matricula, float n1, float n2, float n3) {
    struct aluno a;
    a.matricula = matricula;
    snprintf(a.nome, sizeof(a.nome), "Aluno %d", matricula);
    a.n1 = n1; a.n2 = n2; a.n3 = n3;
    return a;
}
typedef struct aluno Aluno;

int main(void){
    Aluno a;
    Lista *li;
    int mats[] = {10, 22, 32, 43, 42}

    

}