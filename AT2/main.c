#include <stdio.h>
#include <stdlib.h>
typedef struct cellule
{
    int Val;
    struct cellule *Next;
} Cellule;

typedef Cellule *ListeC;

ListeC Create()
{
    ListeC Nv = NULL, db = NULL, prcr;
    int val;
    printf("Donner une valeur ou 0 pour sotir\n");
    scanf("%d", &val);
    if (val)
    {
        Nv = (ListeC)malloc(sizeof(ListeC));
        Nv->Val = val;
        Nv->Next = Nv;
        db = Nv;
    }

    while (val)
    {
        scanf("%d", &val);
        if (val)
        {
            prcr = (ListeC)malloc(sizeof(ListeC));
            prcr->Val = val;
            Nv->Next = prcr;
            prcr->Next = db;
            Nv = Nv->Next;
        }
    }

    return db;
}

void display(ListeC L)
{
    ListeC P;
    if (L && L->Next)
        printf("%d", L->Val);
    P = L->Next;
    do
    {
        printf("%d", P->Val);
        P = P->Next;
    } while (P != L);
}

int main(int argc, char const *argv[])
{
    ListeC Ent = NULL;
    Ent = Create();
    display(Ent);

    return 0;
}
