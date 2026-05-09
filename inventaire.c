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


void initialiser_inventory(void) {
    printf("initialiser inventaire :\n");
    if (Inventory != NULL) {
        free(Inventory);
    }
    Inventory = NULL;
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

        Object *temp = realloc(Inventory, InventorySize * sizeof(Object));
        if (temp == NULL) {
            printf("Erreur de mémoire !\n");
            return;
        }
        Inventory = temp;

        Inventory[i] = obj;
    }
    show_inventory();
}

void addObject_inventory(void) {
    Object obj;
    InventorySize++;
    Object *temp = realloc(Inventory, InventorySize * sizeof(Object));
    if (temp == NULL) {
        printf("Erreur de mémoire !\n");
        return;
    }
    Inventory = temp;

    printf("\n Object a Ajouter :\n");
    printf("Quelle est le nom de l'object :\n");
    scanf("%s", obj.name);

    printf("Quelle est le poids de l'object :\n");
    scanf("%f", &obj.weight);

    Inventory[InventorySize - 1] = obj;
}

void show_inventory(void) {
    printf("\n ===== INVENTAIRE DE L'AVENTURIER ===== \n");
    printf("Nombre d'objets %d : \n\n", InventorySize);

    for (int y = 0; y < InventorySize; y++) {
        printf("Emplacement %d : %s = ", y + 1, Inventory[y].name);
        printf("%.1f \n", Inventory[y].weight);
    }
}

void modifyWeight_inventory(int nb) {
    nb = nb - 1;
    if (nb > InventorySize || nb < 0) {
        printf("\nVous navez pas rentré un nombre Valide.");
        return;
    }
    printf("Voici l'object selectionner : \n\n");
    printf("Name :%s \n", Inventory[nb].name);
    printf("poids (avant modification) :%.1f \n\n", Inventory[nb].weight);
    printf("changer sont poids :");
    scanf("%f", &Inventory[nb].weight);

    printf("Modification effectuer !\n");
}