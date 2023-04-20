#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h"
#include "time.h"

const int _30[4] = {4, 6, 9, 11};

void Get_String(char *string)
{
    scanf("%s", string);
}

int Date_Test(const Date date)
{

    if (date.MM > 12 || date.MM < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the MM is wrong  we dont have a month number %d\033[0m", date.MM);
        return 1;
    }
    if (date.JJ > 31 || date.JJ < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the JJ is wrong  we dont have a day number %d\033[0m", date.JJ);
        return 1;
    }
    if (date.AAAA < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the JJ is wrong  we dont have a year number %d\033[0m", date.AAAA);
        return 1;
    }

    if (date.MM == 2 &&
        date.JJ > (28 + (!(date.AAAA % 4))))
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the JJ is wrong  we dont have a day number %d in feb%d\033[0m",
               date.JJ, date.AAAA);
        return 1;
    }

    for (int i = 0; i < 4; i++)
        if (date.MM == _30[i] && date.JJ == 31)
        {
            printf("\033[1A\033[2K");
            printf("\033[1A\033[2K");
            printf("\033[1A\033[2K");
            printf("\033[1A\033[2K");
            printf("\033[1;31m! the JJ is wrong  we dont have 31 in %d\033[0m", date.MM);
            return 1;
        }
    return 0;
}
int Temp_Test(const Tempe temp)
{

    if (temp.Heur > 24 ||
        temp.Heur < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the HH is wrong the isnot HH = %d\033[0m",
               temp.Heur);
        return 1;
    }
    if (temp.Min > 60 ||
        temp.Min < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the HH is wrong the isnot Min = %d\033[0m",
               temp.Min);
        return 1;
    }
    return 0;
}
int Duration_test(const Duration duration)
{
    if (To_min(duration.Fin) - To_min(duration.Debut) <= 0)
    {
        printf("\033[1A\033[2K");

        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");

        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m RDV END BEFORE IT START \033[0m");
        return 1;
    }
    return 0;
}

int To_min(Tempe tempe)
{
    return tempe.Min + tempe.Heur * 60;
}

int Includ(int Start, int date, int End)
{
    return Start <= date && date <= End;
}

int Date_Comper(Date a, Date b)
{
    return a.AAAA == b.AAAA &&
           a.MM == b.MM &&
           a.JJ == b.JJ;
}

void Scane_Date(Date *date)
{
    do
    {
        printf("Give Me Date :\n");
        printf("\tGive Me AAAA :");
        scanf("%d", &(*date).AAAA);
        printf("\tGive Me MM :");
        scanf("%d", &(*date).MM);
        printf("\tGive Me JJ :");
        scanf("%d", &(*date).JJ);

    } while (Date_Test(*date));
}
void Scane_Duration(Duration *duration)
{

    do
    {
        printf("Give Me Duration :\n");
        do
        {
            printf("\tGive Me Start :\n");
            printf("\t\tHeure : ");
            scanf("%d", &duration->Debut.Heur);
            printf("\t\tMin : ");
            scanf("%d", &duration->Debut.Min);
        } while (Temp_Test(duration->Debut));
        do
        {

            printf("\tGive Me End :\n");
            printf("\t\tHeure : ");
            scanf("%d", &duration->Fin.Heur);
            printf("\t\tMin : ");
            scanf("%d", &duration->Fin.Min);
        } while (Temp_Test(duration->Fin));

    } while (Duration_test(*duration));
}
void Scane(RDV *Val)
{

    Scane_Date(&Val->date);
    Scane_Duration(&Val->duration);

    printf("Title: ");
    getchar();
    gets(Val->Titer);
    printf("Desc: ");
    getchar();
    gets(Val->Desc);
}

void Print(RDV Val)
{
    printf("\n________________________\n");
    printf("Date (AAAA/MM/JJ)-> ");
    printf("%d/%d/%d\n", Val.date.AAAA, Val.date.MM, Val.date.JJ);
    printf("Duration (H:Min)\n");
    printf("\tFrom %d : %d to ", Val.duration.Debut.Heur, Val.duration.Debut.Min);
    printf(" %d : %d ", Val.duration.Fin.Heur, Val.duration.Fin.Min);
    printf("\nTiter : ");
    printf("%s", Val.Titer);
    printf("\nDesc  : ");
    printf("%s", Val.Desc);
}

List Inserer(RDV rdv, List L)
{

    List P;
    P = (noeud *)malloc(sizeof(noeud));
    P->Val = rdv;
    P->Suiv = L;
    return P;
}

void Afficher(List L)
{

    if (L)
    {
        Print(L->Val);
        Afficher(L->Suiv);
    }
}

List Delete(int index, List L)
{
    if (index < 1)
        return NULL;

    if (L)
    {
        if (index == 1)
        {
            List temp = L->Suiv;
            free(L);
            return temp;
        }
        else
        {
            index--;
            List Me = L->Suiv;
            List After = L;
            while (Me && index != 1)
            {
                After = Me;
                Me = Me->Suiv;
                index--;
            }
            After->Suiv = Me->Suiv;
            free(Me);
            return L;
        }
    }
    else
    {
        return NULL;
    }
}

void test(List L)
{
    int cheng = 0;
testing:

    printf_s("\nTESTING...\n");

    for (List I = L; I != NULL; I = I->Suiv)
    {
        // if (I->Suiv != NULL)
        for (List J = I->Suiv; J != NULL; J = J->Suiv)
        {
            if (Date_Comper(I->Val.date, J->Val.date))
            {
                if (Includ(To_min(I->Val.duration.Debut), To_min(J->Val.duration.Debut), To_min(I->Val.duration.Fin)) ||
                    Includ(To_min(I->Val.duration.Debut), To_min(J->Val.duration.Fin), To_min(I->Val.duration.Fin)))
                {
                    cheng += 1;
                    printf("\nthere is a conflect:");
                    printf("\n\tthe RDV %s ->( %d : %d ) # ( %d : %d )", J->Val.Titer, J->Val.duration.Debut.Heur, J->Val.duration.Debut.Min, J->Val.duration.Fin.Heur, J->Val.duration.Fin.Min);
                    printf("\n\tthe RDV %s ->( %d : %d ) # ( %d : %d )", I->Val.Titer, I->Val.duration.Debut.Heur, I->Val.duration.Debut.Min, I->Val.duration.Fin.Heur, I->Val.duration.Fin.Min);

                    printf("\nDo you want chenge the time of %s RDV (1/0)\n", I->Val.Titer);
                    int log;
                    printf(">> ");
                    scanf("%d", &log);
                    if (log)
                    {

                        Scane_Duration(&I->Val.duration);
                        cheng -= 1;
                        goto testing;
                    }
                }
            }
        }
    }
    if (cheng)
    {
        cheng = 0;
        goto testing;
        /* code */
    }
}

void modifier(List L, int index)
{
    if (index >= 1)
    {
        List fortest = L;
        while (L && index != 1)
        {
            if (L->Suiv)
            {
                L = L->Suiv;
                break;
            }
            index--;
        }
        if (index == 1)
        {
            printf("\nGo modifier %s RDV :\n", L->Val.Titer);
            Scane(&L->Val);
            test(fortest);
        }
        else
        {
            printf("{You dont have that much of RDV}");
        }
    }
}

void Vider(List *L)
{
    List Par;
    while (*L != NULL)
    {
        Par = *L;
        *L = Par->Suiv;
        free(Par);
    }
}