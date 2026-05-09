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
    if (nb <= 0) return;

    if (Inventory != NULL) {
        free(Inventory);
        Inventory = NULL;
    }

    InventorySize = nb;
    changeBySizeInventory();
    if (Inventory == NULL) return;

    for (int i = 0; i < nb; i++) {
        Object obj;

        printf("Donne le nom de l'object %d a ajouter dans ton inventaire :\n", i + 1);
        scanf("%s", obj.name);
        printf("Donne le poids de l'object %d a ajouter dans ton inventaire :\n", i + 1);
        obj.weight = askWeight();

        printf("\nVoici ton object Name : %s \n", obj.name);
        printf("Voici ton object Poids : %.1f \n\n", obj.weight);

        Inventory[i] = obj;
    }
    show_inventory();
}

void addObject_inventory(void) {
    Object obj;
    InventorySize++;
    changeBySizeInventory();
    if (Inventory == NULL) return;

    printf("\n Object a Ajouter :\n");
    printf("Quelle est le nom de l'object :\n");
    scanf("%s", obj.name);

    printf("Quelle est le poids de l'object :\n");
    obj.weight = askWeight();

    Inventory[InventorySize - 1] = obj;
}

void show_inventory(void) {
    if (empty_check()) return;
    printf("\n ===== INVENTAIRE DE L'AVENTURIER ===== \n");
    printf("Nombre d'objets %d : \n\n", InventorySize);
    float total = 0;
    for (int i = 0; i < InventorySize; i++) {
        printf("Emplacement %d : %s = ", i + 1, Inventory[i].name);
        printf("%.1f \n", Inventory[i].weight);
        total += Inventory[i].weight;
    }
    if (Inventory > 0) {
        printf("\nPoids Total %.1f \n",total);
        total = total / InventorySize;
        printf("Moyenne Poids %.1f \n",total);
    }
}

void modifyWeight_inventory(int nb) {
    if (empty_check()) return;

    nb--;
    if (nb > InventorySize || nb < 0) {
        printf("\nVous navez pas rentré un nombre Valide.");
        return;
    }
    printf("Voici l'object selectionner : \n\n");
    printf("Name :%s \n", Inventory[nb].name);
    printf("poids (avant modification) :%.1f \n\n", Inventory[nb].weight);
    Inventory[nb].weight = askWeight();

    printf("Modification effectuer !\n");
}

void rmLastObject_inventory(void) {
    if (empty_check()) return;

    printf("\nL'object : %s ", Inventory[InventorySize - 1].name);
    printf("vas etre Supprimer voulez vous vraimer faire sa (1 = oui 0 = non) \n");
    int nb = 0;
    scanf("%d", &nb);
    if (nb != 0) {
        InventorySize--;
        changeBySizeInventory();
        if (Inventory == NULL) return;
        printf("Objet supprime avec succes.\n");
    } else {
        printf("Suppression annulee.\n");
    }
}

void totalWeight_inventory(void) {
    if (empty_check()) return;

    float totalWeight = 0;
    for (int i = 0; i < InventorySize; i++) {
        totalWeight += Inventory[i].weight;
    }
    printf("\nVoici le point total de votre Inventaire %.1f \n", totalWeight);
}

void weight_inventory(void) {
    if (empty_check()) return;

    float maxWeight = Inventory[0].weight;
    int indexChampion = 0;

    for (int i = 1; i < InventorySize; i++) {
        if (Inventory[i].weight > maxWeight) {
            maxWeight = Inventory[i].weight;
            indexChampion = i;
        }
    }

    printf("\nL'objet le plus lourd est : %s", Inventory[indexChampion].name);
    printf(" avec un poids de %.1f \n", maxWeight);
}

int empty_check(void) {
    if (InventorySize == 0) {
        printf("\n[!] Erreur : L'inventaire est vide !\n");
        return 1;
    }
    if (Inventory == NULL) {
        printf("\n[!] Erreur : L'inventaire est vide !\n");
        return 1;
    }
    return 0;
}

float askWeight(void) {
    float w;
    do {
        printf("Poids (kg) : ");
        if (scanf("%f", &w) != 1) {
            printf("[!] Erreur : Veuillez entrer un nombre valide.\n");
            while (getchar() != '\n');
            w = -1;
            continue;
        }
        if (w < 0) {
            printf("[!] Erreur : Le poids ne peut pas etre negatif.\n");
        }
    } while (w < 0);
    return w;
}

void clear_inventory(void) {
    if (empty_check()) return;
    printf("Voulez vous Vider (supprimer) votre inventaire (1 = oui 0 = non) \n");
    int nb = 0;
    scanf("%d", &nb);
    if (nb != 0) {
        free(Inventory);
        Inventory = NULL;
        InventorySize = 0;
        printf("\nL'inventaire a ete integralement vide.");
    } else {
        printf("\nAction annulee.");
    }
}

void changeBySizeInventory(void) {
    Object *temp = realloc(Inventory, InventorySize * sizeof(Object));
    if (temp == NULL) {
        printf("Erreur de mémoire !\n");
        return;
    }
    Inventory = temp;
}