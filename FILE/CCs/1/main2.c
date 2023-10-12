#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cellule
{
    char Val;
    struct cellule *Next;
};

typedef struct cellule *Liste;

void afficher(Liste liste)
{
    if (!liste)
    {
        puts("La liste est vide");
        return;
    }
    Liste cp;
    for (cp = liste; cp; cp = cp->Next)
        printf("[ %c |  ]-->", cp->Val);
    printf("[ NULL ]\n");
}

Liste ChaineToListe(char *ch)
{
    Liste liste, cp;
    char *p = ch;
    liste = (Liste)malloc(sizeof(Liste));
    cp = liste;
    liste->Val = *p;
    liste->Next = NULL;
    p++;
    while (*p)
    {
        cp->Next = (Liste)malloc(sizeof(Liste));
        cp = cp->Next;
        cp->Val = *p;
        cp->Next = NULL;
        p++;
    }
    return liste;
}

Liste EnleverChar(Liste L, char car)
{
    if (!L)
        return NULL;
    Liste cp, q, tmp;
    for (; L && L->Val == car;)
    {
        cp = L;
        L = L->Next;
        free(cp);
    }
    if (L)

        for (q = L, cp = L->Next; cp;)
        {
            if (cp->Val == car)
            {
                q->Next = cp->Next;
                tmp = cp;
                cp = cp->Next;
                free(tmp);
            }
            else
            {
                q = cp;
                cp = cp->Next;
            }
        }
    return L;
}

Liste ReadCrctr(Liste L, char car)
{
    Liste Nv;
    Nv = (Liste)malloc(sizeof(Liste));
    Nv->Val = car;
    Nv->Next = NULL;
    if (L)
        Nv->Next = L;
    return Nv;
}

int ExisteDansListe(Liste L, char car)
{
    for (; L && L->Val != car; L = L->Next)
        ;
    if (L)
        return 1;
    else
        return 0;
}

Liste Intersection(Liste L1, Liste L2)
{
    Liste result = NULL, cp;
    for (cp = L1; cp; cp = cp->Next)
    {
        if (!ExisteDansListe(result, cp->Val) && ExisteDansListe(L2, cp->Val))
            result = ReadCrctr(result, cp->Val);
    }

    return result;
}

int ListeLength(Liste L)
{
    int i;
    for (i = 0; L; L = L->Next)
        i++;
    return i;
}

char *ChaineIntersection(Liste L1, Liste L2)
{
    Liste cp = Intersection(L1, L2), q;
    char *result, *i;
    int k;
    k = ListeLength(cp);
    if (!cp)
        return '\0';
    result = (char *)malloc((k + 1) * sizeof(char));
    for (i = result, q = cp; i < result + ListeLength(cp); i++)
    {
        *i = q->Val;
        q = q->Next;
    }
    *i = '\0';
    return result;
}

int Palindrome(Liste L)
{
    if (!L || !ListeLength(L) % 2)
        return 0;
    int result;
    Liste p, q;
    p = L;
    for (q = L; q->Next; q = q->Next)
    {
    }

    return result;
}

int main(int argc, char const *argv[])
{
    Liste L1 = NULL, L2 = NULL;
    char *ch = "Bonjour";
    L1 = ChaineToListe("Bonjour");
    afficher(L1);
    L2 = ChaineToListe("PourPasjtoi");
    afficher(L2);
    puts("Apres \n");
    afficher(Intersection(L2, L1));
    printf("La taille de L2 est %d\n", ListeLength(L2));
    afficher(L2);
    puts(ChaineIntersection(L2, L1));
    return 0;
}
