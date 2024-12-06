#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

void KLB_toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
}

KLB_HashTable* KLB_createHashTable() {
    KLB_HashTable *table = malloc(sizeof(KLB_HashTable));
    for (int i = 0; i < KLB_HASH_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

unsigned int KLB_hashFunction(const char *key) {
    return (key[0] - 'a') % KLB_HASH_SIZE;
}


void KLB_insert(KLB_HashTable *table, const char *key, const char *value) {
    char *lowerKey = strdup(key);
    KLB_toLowerCase(lowerKey);

    unsigned int index = KLB_hashFunction(lowerKey);

    KLB_Node *newNode = malloc(sizeof(KLB_Node));
    newNode->key = lowerKey;
    newNode->value = strdup(value);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

const char* KLB_search(KLB_HashTable *table, const char *key) {
    char *lowerKey = strdup(key);
    KLB_toLowerCase(lowerKey);

    unsigned int index = KLB_hashFunction(lowerKey);
    KLB_Node *current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, lowerKey) == 0) {
            free(lowerKey);
            return current->value;
        }
        current = current->next;
    }

    free(lowerKey);
    return NULL;
}

void KLB_freeHashTable(KLB_HashTable *table) {
    for (int i = 0; i < KLB_HASH_SIZE; i++) {
        KLB_Node *current = table->buckets[i];
        while (current != NULL) {
            KLB_Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(table);
}
