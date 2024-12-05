#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"
#include "file_handler.h"

int main() {
    KLB_HashTable *dictionary = KLB_createHashTable();
    KLB_loadDictionary(dictionary, "words.txt");

    char word[256];
    printf("Entrez un mot en langue nationale : ");
    scanf("%s", word);

    const char *translation = KLB_search(dictionary, word);
    if (translation) {
        printf("Traduction en Yemba : %s\n", translation);
    } else {
        printf("Mot non trouvé dans le dictionnaire.\n");
    }

    KLB_freeHashTable(dictionary);
    return 0;
}
