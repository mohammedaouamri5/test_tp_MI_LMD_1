
#include "Agenda.h"

enum INPUT
{
    EXIT,
    ADD,
    MODIFIE,
    DELETE,
    AFFICHER,
    VIDEAR,
    CLEAR
};
// #define EXIT 0
// #define ADD 1
// #define MODIFIE 2
// #define DELETE 3
// #define AFFICHER 4
// #define VIDEAR 5
// #define CLEAR 6


void Menu(int *MANAGER)
{
    printf("\nMenu :");
    printf("\n\t%d) EXIT", EXIT);
    printf("\n\t%d) ADD", ADD);
    printf("\n\t%d) MODIFIE", MODIFIE);
    printf("\n\t%d) DELETE", DELETE);
    printf("\n\t%d) AFFICHER", AFFICHER);
    printf("\n\t%d) VIDEAR", VIDEAR);
    printf("\n\t%d) CLEAR", CLEAR);
    printf("\n >> ");
    scanf("%d", MANAGER);
}

int main(int argc, char const *argv[])
{
    List L = NULL;
    while (true)
    {
        _sleep(2);
        int MANAGER;
        Menu(&MANAGER);
        switch (MANAGER)
        {
        case EXIT:
            return 0;

            break;
        case ADD:
            RDV rdv;
            Scane(&rdv);
            L = Inserer(rdv, L);
            test(L);
            break;
        case MODIFIE:
            int K;
            printf("\n");
            Afficher(L);
            printf("\nWitch one : ");
            scanf("%d", &K);
            modifier(L, K);
            break;
        case DELETE:
            int index;
            printf("\n");
            Afficher(L);
            printf("\n");
            printf("Witch one you wont to delete >>");
            scanf("%d", &index);
            L = Delete(index, L);
            break;
        case AFFICHER:
            Afficher(L);
            break;
        case VIDEAR:
            int log = 0;
            printf("are you sure [0 for no | any thing for yes]");
            scanf("%d", &log);
            if (log)
                Vider(&L);
                break;
        case CLEAR:
            system("cls");
            break;

        default:
            break;
        }
    }

    return 0;
}
