
#include "Agenda.h"
#include "UI.h" // ! UI men wad knis
enum INPUT
{
    EXIT,
    ADD,
    MODIFIE,
    DELETE,
    AFFICHER,
    AFFICHER_IN_THE_DATE,
    VIDEAR,
    CLEAR
};

void Menu(int *MANAGER)
{
    printf("\nMenu :");
    printf("\n\t%d) EXIT", EXIT);
    printf("\n\t%d) ADD", ADD);
    printf("\n\t%d) MODIFIE", MODIFIE);
    printf("\n\t%d) DELETE", DELETE);
    printf("\n\t%d) AFFICHER", AFFICHER);
    printf("\n\t%d) AFFICHER_IN_THE_DATE", AFFICHER_IN_THE_DATE);
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
        int MANAGER;
        Menu(&MANAGER);
        switch (MANAGER)
        {
        case EXIT:
            return 0;

            break;
        case ADD:
            UI_ADD(&L);
            break;
        case MODIFIE:
            UI_MODIFIE(&L);

            break;
        case DELETE:
            UI_DELETE(&L);

            break;
        case AFFICHER:
            UI_AFFICHER(&L);
        case AFFICHER_IN_THE_DATE:
            UI_AFFICHER_IN_THE_DATE(&L);

            break;
        case VIDEAR:
            UI_VIDEAR(&L);

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

 