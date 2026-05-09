//
// Created by Mael LLADO on 09/05/2026.
//

#include "affichage.h"
#include <stdio.h>
#include "inventaire.h"
#include <stdlib.h>

int nb;

void MenuStart(void) {
    int user = 0;
    while (user != 9) {
        printf("\n===== INVENTAIRE DE L'AVENTURIER ===== \n");
        printf("1. Initialiser l'inventaire \n");
        printf("2. Ajouter un objet \n");
        printf("3. Aﬃcher l'inventaire \n");
        printf("4. Modifier le poids d'un objet \n");
        printf("5. Supprimer le dernier objet \n");
        printf("6. Aﬃcher le poids total\n");
        printf("7. Aﬃcher l'objet le plus lourd\n");
        printf("8. Vider l'Inventaire\n");
        printf("9. Quitter\n \n");
        printf("Votre choix : \n");
        scanf("%d", &user);
        switch (user) {
            case 1:
                printf("\nEntre le nombre d'Object que tu veut mettre dans ton inventaire :");
                scanf("%d", &nb);
                initialiser_inventory(nb);
                finish();
                break;
            case 2:
                addObject_inventory();
                finish();
                break;
            case 3:
                show_inventory();
                finish();
                break;
            case 4:
                show_inventory();
                printf("\nEntre le Numero de l'Emplacement de l'object a modifier :");
                scanf("%d", &nb);
                modifyWeight_inventory(nb);
                finish();
                break;
            case 5:
                rmLastObject_inventory();
                finish();
                break;
            case 6:
                totalWeight_inventory();
                finish();
                break;
            case 7:
                weight_inventory();
                finish();
                break;
            case 8:
                clear_inventory();
                finish();
                break;
            case 9:
                return;
            default:
                printf("choisisez un nombre entre 1 et 8.");
                break;
        }
    }
}

void finish(void) {
    printf("\nAppuyez sur Entree pour continuer...");
    while (getchar() != '\n');
    getchar();
}