#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"

void KLB_loadDictionary(KLB_HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("\n\n❌ Fichier \"%s\" introuvable.\n", filename);
        perror("\nVeuillez créer le fichier et y ajouter des mots avant de relancer l'application.\n");
     
        exit(EXIT_FAILURE);
    }
    char key[256], value[256];
    while (fscanf(file, "%s %s", key, value) != EOF) {
        KLB_insert(table, key, value);
    }
    fclose(file);
}
