#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *Nom;
    float Note;
} Etudiant;

struct Cellule
{
    Etudiant Eleve;
    struct Cellule *Next;
};

typedef struct Cellule *Liste;

Etudiant Read_Student(char *Nom, float Note)
{
    Etudiant etd;
    etd.Nom = (char *)malloc(strlen(Nom) * sizeof(char));
    strcpy(etd.Nom, Nom);
    etd.Note = Note;
    return etd;
}

void Write_Student(Etudiant etd)
{
    printf("Nom : %s\nNote : %.3f\n----------------------------------------------------------\n", etd.Nom, etd.Note);
}

void Read_Array_Student(Etudiant *etd, int nb)
{
    char Nom[50];
    float Note;
    int i;
    for (i = 0; i < nb; i++)
    {
        printf("Information du %d e eleve :\n", i + 1);
        // gets(Nom);
        scanf("%s %f", Nom, &Note);
        etd[i] = Read_Student(Nom, Note);
    }
}

void Write_Array_Student(Etudiant *etd, int nb)
{
    int i;
    for (i = 0; i < nb; i++)
        Write_Student(etd[i]);
}

void Affiche(Liste L)
{
    Liste cp;
    for (cp = L; cp; cp = cp->Next)
    {
        Write_Student(cp->Eleve);
    }
}

Liste To_List(Etudiant *etd, int nb)
{
    Liste L, cp;
    Etudiant *p = etd;
    int i;
    if (!nb)
        return NULL;
    L = (Liste)malloc(sizeof(Liste));
    cp = L;
    L->Eleve = Read_Student(p->Nom, p->Note);
    L->Next = NULL;
    p++;
    for (i = 1; i < nb; i++, p++)
    {
        cp->Next = (Liste)malloc(sizeof(Liste));
        cp = cp->Next;
        cp->Eleve = Read_Student(p->Nom, p->Note);
        cp->Next = NULL;
    }
    return L;
}

Liste Search(Liste L, char *nom)
{
    Liste cp;
    for (cp = L; cp && strcmp(cp->Eleve.Nom, nom); cp = cp->Next)
        ;
    return cp;
}

Liste To_List_SortByName(Etudiant *etd, int n)
{
    Etudiant tmp, *change, *cp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        change = NULL;
        cp = etd + i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(cp->Nom, etd[j].Nom) == 1)
                change = etd + j;
            cp = etd + j;
        }
        if (change)
        {
            tmp = etd[i];
            etd[i] = *change;
            *change = tmp;
        }
    }

    return To_List(etd, n);
}

Liste To_List_SortByScore(Etudiant *etd, int n)
{
    Etudiant tmp, *change, *cp;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        change = NULL;
        cp = etd + i;
        for (j = i + 1; j < n; j++)
        {
            if (cp->Note < etd[j].Note)
                change = etd + j;
            cp = etd + j;
        }
        if (change)
        {
            tmp = etd[i];
            etd[i] = *change;
            *change = tmp;
        }
    }

    return To_List(etd, n);
}

int main(int argc, char const *argv[])
{
    Liste L;
    Etudiant etd[10];
    //     etd = Read_Student("SYLLA", 19.5);
    //     Write_Student(etd);
    Read_Array_Student(etd, 3);
    Write_Array_Student(etd, 3);
    L = To_List(etd, 3);
    puts("Par ordre alphabetique\n=====================================");
    // Affiche(L);
    // if (Search(L, "Salut"))
    // {
    //     puts("Existe dans la liste ");
    //     puts(Search(L, "Salut")->Eleve.Nom);
    // }
    // else
    //     puts("Oups Non");
    L = To_List_SortByName(etd, 3);
    Affiche(L);
    puts("Par ordre de notation\n=====================================");
    L = To_List_SortByScore(etd, 3);
    Affiche(L);
    //	putc(strcmp("Bonjour","Bonjour"));
    return 0;
}
