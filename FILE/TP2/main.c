#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int val;
    struct Noeud *Next;
} Noeud;

typedef enum
{
    false,
    true
} Bool;

Noeud *creer_liste_vide()
{
    return NULL;
}

void afficher(Noeud *liste)
{
    if (!liste)
    {
        puts("La liste est vide");
        return;
    }
    Noeud *cp;
    for (cp = liste; cp; cp = cp->Next)
        printf("[ %d | %x ]-->", cp->val, cp->Next);
    printf("[ NULL ]\n");
}

Noeud *ajout_debut(Noeud *liste, int e)
{
    Noeud *Nv;
    Nv = (Noeud *)malloc(sizeof(Noeud));
    Nv->val = e;
    Nv->Next = liste;
    return Nv;
}

Noeud *supprime_debut(Noeud *liste)
{
    Noeud *cp = liste;
    if (liste && liste->Next)
    {
        liste = liste->Next;
        free(cp);
        return liste;
    }
    return NULL;
}

int taille(Noeud *liste)
{
    int tll = 0;
    Noeud *cp;
    if (liste)
    {
        for (cp = liste; cp; cp = cp->Next)
            tll++;
    }
    return tll;
}

int jieme(Noeud *liste, int j)
{
    Noeud *cp;
    int i;
    if (j > taille(liste))
    {
        puts("Il n'y a pas autant d'elements hhh");
        exit(EXIT_FAILURE);
        ;
    }
    for (cp = liste, i = 1; i != j; cp = cp->Next, i++)
        ;
    return cp->val;
}

Noeud *ajout_jieme(Noeud *liste, int j, int e)
{
    Noeud *Nv, *cp, *cq;
    int i;
    if (j > taille(liste))
    {
        puts("Il n'y a pas autant d'elements hhh");
        return liste;
    }
    if (j == 1)
        return ajout_debut(liste, e);
    Nv = (Noeud *)malloc(sizeof(Noeud));
    Nv->val = e;
    for (cp = liste, i = 1; i != j; cq = cp, cp = cp->Next, i++)
        ;
    Nv->Next = cp;
    cq->Next = Nv;
    return liste;
}

Noeud *supprime_jiem(Noeud *liste, int j)
{
    Noeud *cp, *tmp;
    int i;
    if (j > taille(liste))
    {
        puts("Il n'y a pas autant d'elements hhh");
        return liste;
    }
    if (j == 1)
        return supprime_debut(liste);

    for (cp = liste, i = 1; i != j; tmp = cp, cp = cp->Next, i++)
        ;
    tmp->Next = cp->Next;
    free(cp);
    return liste;
}
int main(int argc, char const *argv[])
{
    Noeud *liste;
    liste = creer_liste_vide(liste);
    afficher(liste);
    liste = ajout_debut(liste, 4);
    liste = ajout_debut(liste, 6);
    liste = ajout_debut(liste, 3);
    liste = ajout_debut(liste, 1);
    liste = ajout_debut(liste, 10);
    afficher(liste);
    liste = supprime_jiem(liste, 4);
    afficher(liste);
    liste = ajout_jieme(liste, 2, 6);
    afficher(liste);
    return 0;
}
