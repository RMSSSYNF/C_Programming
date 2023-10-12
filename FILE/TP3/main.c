#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule *LISTE;
typedef struct cellule
{
    int val;
    LISTE next;
    LISTE prev;
} CELLULE;
void initListe(LISTE L)
{
    L = NULL;
}

void afficher(LISTE L)
{
    if (!L)
    {
        puts("La liste est vide");
        return;
    }

    LISTE p = L;
    printf("%d  ->", p->val);
    if (p = p->next)
        for (; p != L; p = p->next)
            printf("%d  ->", p->val);
}

LISTE createCellule(int x)
{
    LISTE Nv;
    Nv = (LISTE)malloc(sizeof(LISTE));
    Nv->val = x;
    Nv->next = Nv;
    Nv->prev = Nv;
    return Nv;
}

void pushBefore(int x, LISTE L)
{
    if (!L)
    {
        L = createCellule(x);
        return;
    }
    LISTE Nv = createCellule(x);
    Nv->next = L;
    L->prev->next = Nv;
    Nv->prev = L->prev;
    L->prev = Nv;
}

void pushAfter(int x, LISTE L)
{
}

int main(int argc, char const *argv[])
{

    return 0;
}
