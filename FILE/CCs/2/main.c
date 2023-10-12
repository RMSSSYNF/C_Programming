#include <stdio.h>
#include <stdlib.h>

// 1

struct binary
{
    int val;
    struct binary *Next;
} Binary;

typedef struct binary *Bin;

int BinToEntier(Bin b)
{
    if (!b)
        exit(EXIT_FAILURE);
    int dec = 0, pui_2 = 1;
    for (; b; b = b->Next)
    {
        dec += b->val * pui_2;
        pui_2 *= 2;
    }

    return dec;
}

Bin FinListe(Bin b)
{
    Bin q;
    for (q = b; q->Next; q = q->Next)
        ;
    return q;
}

Bin Insert(Bin L1, Bin L2, int x)
{
    Bin q;
    if (L1->val == x)
    {
        q = FinListe(L2);
        q->Next = L1;
        L1 = L2;
        return L1;
    }
    Bin tmp, p;
    for (q = L1, p = L1->Next; p->val != x; q = p, p = p->Next)
        ;
    tmp = FinListe(L2);
    q->Next = L2;
    tmp->Next = p;
    return L1;
}

void afficher(Bin liste)
{
    if (!liste)
    {
        puts("La liste est vide");
        return;
    }
    Bin cp;
    for (cp = liste; cp; cp = cp->Next)
        printf("[ %d ]-->", cp->val);
    printf("[ NULL ]\n");
}

Bin ajout_debut(Bin liste, int e)
{
    Bin Nv;
    Nv = (Bin)malloc(sizeof(Bin));
    Nv->val = e;
    Nv->Next = liste;
    return Nv;
}

int main(int argc, char const *argv[])
{
    Bin b = NULL, c = NULL;
    b = ajout_debut(b, 1);
    b = ajout_debut(b, 0);
    b = ajout_debut(b, 3);
    b = ajout_debut(b, 4);
    c = ajout_debut(c, 2);
    c = ajout_debut(c, 3);
    c = ajout_debut(c, 6);
    c = ajout_debut(c, 4);
    b = ajout_debut(b, 10);
    b = ajout_debut(b, 9);
    c = ajout_debut(c, 1);
    c = ajout_debut(c, 0);
    afficher(b);
    afficher(c);
    afficher(Insert(b, c, 1));

    return 0;
}
