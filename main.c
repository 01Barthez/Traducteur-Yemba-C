#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "file_handler.h"
#include "app_function.h"

int main()
{
    const char words_file[] = "words.txt";
    KLB_HashTable *dictionary = KLB_createHashTable();
    KLB_loadDictionary(dictionary, words_file);

    char test[3];

    do
    {
        displayUserChoice();

        int choice = getUserChoice();

        switch (choice)
        {
        case 1:
            /* Traduire un mot du français vers le yemba */
            translateWord(dictionary);
            break;

        case 2:
            /* Ajouter un mot dans le dictionnaire */
            addWord(dictionary, words_file);
            break;

        case 3:
            /* Voir les mots du dictionnaire */
            displayDictionary(dictionary);
            break;

        case 4:
            /* Quitter le programme */
            cleanApp(dictionary);
            return 0;
            break;

        default:
            break;
        }

        printf("\n\n\n❓ Voulez vous ???? (oui✅ / non ❌)-(o/n):  ");
        scanf("%s", test);
    } while (strcasecmp(test, "oui") == 0 || strcasecmp(test, "o") == 0);

    cleanApp(dictionary);
    return 0;
}
