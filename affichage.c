//
// Created by Mael LLADO on 09/05/2026.
//

#include "affichage.h"
#include <stdio.h>
#include "inventaire.h"
#include <stdlib.h>


void MenuStart(void) {
    int user = 0;
    while (user != 8) {
        printf("\n===== INVENTAIRE DE L'AVENTURIER ===== \n");
        printf("1. Initialiser l'inventaire \n");
        printf("2. Ajouter un objet \n");
        printf("3. Aﬃcher l'inventaire \n");
        printf("4. Modifier le poids d'un objet \n");
        printf("5. Supprimer le dernier objet \n");
        printf("6. Aﬃcher le poids total\n");
        printf("7. Aﬃcher l'objet le plus lourd\n");
        printf("8. Quitter\n \n");
        printf("Votre choix : \n");
        scanf("%d", &user);
        switch (user) {
            case 1:
                initialiser_inventory();
                break;
            case 2:
                addObject_inventory();
                break;

            case 3:
                show_invenotry();
                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            case 8:
                return;
            default:
                printf("choisisez un nombre entre 1 et 8.");
                break;
        }
    }
}