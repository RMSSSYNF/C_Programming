#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// J'ajoute ce commentaire pour ma formation en git
#define Pmax 10

struct Cellule
{
    char Car;
    struct Cellule *Next;
};
typedef struct Cellule FaP[Pmax];

FaP *Inserer(FaP *F, char x)
{
    FaP *Nv;
    Nv = malloc(sizeof(*Nv));
    (*Nv)->Car = x;
    (*Nv)->Next = NULL;
    if (F)
    {
        (*Nv)->Next = *F;
    }

    return *Nv;
}

void AfficherUnit(FaP *F)
{
    if (!F)
    {
        puts("La liste est vide");
        exit(EXIT_FAILURE);
    }
    for (; *F; F = (*F)->Next)
        printf("[%c] ->", (*F)->Car);
    puts("NULL\n");
}

void Afficher(FaP F)
{
    int i;
    for (i = 0; i < Pmax; i++)
    {
        printf("%d", i + 1);
        AfficherUnit(&F[i]);
    }
}

int main(int argc, char const *argv[])
{
    FaP F;

    Afficher(F);

    return 0;
}