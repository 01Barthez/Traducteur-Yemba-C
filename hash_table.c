#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

KLB_HashTable* KLB_createHashTable() {
    KLB_HashTable *table = malloc(sizeof(KLB_HashTable));
    for (int i = 0; i < KLB_HASH_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

unsigned int KLB_hashFunction(const char *key) {
    return (key[0] - 'a') % KLB_HASH_SIZE; // Basé sur la première lettre
}

void KLB_insert(KLB_HashTable *table, const char *key, const char *value) {
    unsigned int index = KLB_hashFunction(key);
    KLB_Node *newNode = malloc(sizeof(KLB_Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

const char* KLB_search(KLB_HashTable *table, const char *key) {
    unsigned int index = KLB_hashFunction(key);
    KLB_Node *current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
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
