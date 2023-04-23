#include "UI.h"


void UI_ADD(List *L)
{
    RDV rdv;
    Scane(&rdv);
    *L = Inserer(rdv, *L);
}
void UI_MODIFIE(List *L)
{
    int K;
    printf("\n");
    Afficher(*L);
    printf("\nWitch one : ");
    scanf("%d", &K);
    modifier(*L, K);
}
void UI_DELETE(List *L)
{
    int index;
    printf("\n");
    Afficher(*L);
    printf("\n");
    printf("Which one you want to delete >>");
    scanf("%d", &index);
    *L = Delete(index, *L);
}
void UI_AFFICHER(List *L)
{
    Afficher(*L);
}
void UI_AFFICHER_IN_THE_DATE(List *L)
{
    Date date ;
    Scane_Date(&date);
    Afficher_by_date(*L , date);
}

void UI_VIDEAR(List *L)
{
    int log = 0;
    printf("are you sure [0 for no | any thing for yes]");
    scanf("%d", &log);
    if (log)
        Vider(&(*L));
}
