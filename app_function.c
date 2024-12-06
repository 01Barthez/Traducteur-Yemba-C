#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"
#include "app_function.h"

void displayUserChoice()
{
    system("clear");
    printf("\n\t🌟✨ *********** Traducteur en Langue Yemba ************* ✨🌟");

    printf("\n\n\t📜 ____ Menu ____ 📜");

    printf("\n\n\t1️⃣ - 📖 Traduire un mot");
    printf("\n\t2️⃣ - ✍️  Ajouter un mot dans le dictionnaire");
    printf("\n\t3️⃣ - 📂 Voir les mots du dictionnaire");
    printf("\n\t4️⃣ - ❌ Quitter");
}

void translateWord(KLB_HashTable *dictionary)
{
    char word[256];
    printf("\n\nEntrez un mot en langue officielle - (Français) 🌍 : ");
    scanf("%s", word);

    const char *translation = KLB_search(dictionary, word);
    if (translation)
    {
        printf("📖 Traduction en Yemba : 🌟 %s 🌟\n", translation);
    }
    else
    {
        char rep[3];

        printf("⚠️ Mot non trouvé dans le dictionnaire 😔.");
        printf("\n\n\n📋 Voulez-vous voir la liste des mots disponibles dans le dictionnaire ? (✅oui/non❌, o/n) : ");
        scanf("%s", rep);

        if (strcasecmp(rep, "oui") == 0 || strcasecmp(rep, "o") == 0)
        {
            displayDictionary(dictionary);
        }
    }
};

void displayDictionary(KLB_HashTable *dictionary)
{
    printf("\n\n📚 Liste des mots disponibles dans le dictionnaire :\n");
    for (int i = 0; i < KLB_HASH_SIZE; i++)
    {
        KLB_Node *current = dictionary->buckets[i];
        while (current)
        {
            printf("\t🔹- %s\n", current->key);
            current = current->next;
        }
    }
};

void addWord(KLB_HashTable *dictionary, const char *filename)
{
    char key[256], value[256];

    // récuperer les infos a l'user...
    printf("\n\n📝 Entrez le mot en langue officielle : ");
    scanf("%s", key);
    printf("✍️ Entrez la traduction en Yemba : ");
    scanf("%s", value);

    // Vérifier si le mot existe déjà
    if (KLB_search(dictionary, key) != NULL)
    {
        printf("\n⚠️ Ce mot existe déjà dans le dictionnaire.\n");
        return;
    }

    KLB_insert(dictionary, key, value);

    FILE *file = fopen(filename, "a");
    if (file)
    {
        fprintf(file, "%s %s\n", key, value);
        fclose(file);
        printf("\n\n\t✅ Mot ajouté avec succès 🎉!\n");
    }
    else
    {
        perror("❌ Erreur lors de l'ouverture du fichier.\n");
    }
}

int getUserChoice()
{
    int choice = 0;

    printf("\n\n\n\t📊 Veillez choisir un numéro: ");
    while (1)
    {
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 4)
        {
            return choice;
        }

        else
        {
            printf("\n\n\t⚠️ Oups, votre nombre doit etre compris entre 1 et 4... ");
            while (getchar() != '\n')
                ;
            printf("\n\t📊 Veillez choisir un numéro: ");
        }
    }

    printf("\n\n");
}

void cleanApp(KLB_HashTable *dictionary)
{
    system("clear");
    printf("\n\n\t🎉 Merci d'avoir utiliser notre application,\n\t\t Barthez vous tire ses reverence 😊 !!\n\n");

    KLB_freeHashTable(dictionary);
}
