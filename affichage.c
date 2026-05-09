//
// Created by Mael LLADO on 09/05/2026.
//

#include "affichage.h"

#include <stdio.h>

#include "inventaire.h"

void MenuStart(void) {
    int user = 0;
    while (user != 8) {
        printf("===== INVENTAIRE DE L'AVENTURIER ===== \n");
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
        if (user < 1 || user > 8) {
            printf("choisisez un nombre entre 1 et 8.");
        }

        if (user == 1) {
            initialiser_inventaire();
        }
    }
}
