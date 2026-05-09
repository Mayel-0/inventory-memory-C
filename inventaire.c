//
// Created by Mael LLADO on 09/05/2026.
//

#include "inventaire.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[30];
    float weight;
}Object;

Object *Inventory = NULL;
int InventorySize = 0;


void initialiser_inventaire(void) {
    printf("initialiser inventaire :\n");
    Inventory = NULL;
    free(Inventory);
    InventorySize = 0;

    for (int i = 0; i < 3; i++) {
        Object obj;
        printf("Donne le nom de l'object %d a ajouter dans ton inventaire :\n", i);
        scanf("%s", obj.name);
        printf("Donne le poids de l'object %d a ajouter dans ton inventaire :\n", i);
        scanf("%f", &obj.weight);

        printf("\nVoici ton object Name : %s \n", obj.name);
        printf("Voici ton object Poids : %.1f \n\n", obj.weight);
        InventorySize++;
        Inventory = realloc(Inventory, InventorySize * sizeof(Object));
        Inventory[i] = obj;
    }

    printf("\n ===== INVENTAIRE DE L'AVENTURIER ===== \n");
    printf("Nombre d'objets %d : \n\n", InventorySize);
    for (int y = 0; y < InventorySize; y++) {
        Object obj = Inventory[y];
        printf("Emplacement %d : %s = ", y, obj.name);
        printf("%.1f \n", obj.weight);
    }
    printf("\nEntre un numero(0-9) pour coontinuer :\n");
    int finish;
    scanf("%d", &finish);
}
