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


void initialiser_inventory(int nb) {
    InventorySize = nb;
    printf("initialiser inventaire :\n");
    if (Inventory != NULL) {
        free(Inventory);
    }
    Inventory = NULL;

    for (int i = 0; i < nb; i++) {
        Object obj;
        printf("Donne le nom de l'object %d a ajouter dans ton inventaire :\n", i + 1);
        scanf("%s", obj.name);
        printf("Donne le poids de l'object %d a ajouter dans ton inventaire :\n", i + 1);
        scanf("%f", &obj.weight);

        printf("\nVoici ton object Name : %s \n", obj.name);
        printf("Voici ton object Poids : %.1f \n\n", obj.weight);

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
    nb--;
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

void rmLastObject_inventory(void) {
    printf("\nL'object : %s ", Inventory[InventorySize - 1].name);
    printf("vas etre Supprimer voulez vous vraimer faire sa (1 = oui 0 = non) \n");
    int nb = 0;
    scanf("%d", &nb);
    if (nb != 0) {
        InventorySize--;
        Object *tmp = realloc(Inventory, InventorySize * sizeof(Object));
        if (tmp == NULL) {
                printf("Erreur de mémoire !\n");
                return;
        }
        Inventory = tmp;
        printf("Objet supprime avec succes.\n");
    } else {
        printf("Suppression annulee.\n");
    }
}