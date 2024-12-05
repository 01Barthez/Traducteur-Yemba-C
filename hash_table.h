#ifndef KLB_HASH_TABLE_H
#define KLB_HASH_TABLE_H

#define KLB_HASH_SIZE 26  // Nombre de lettres dans l'alphabet

typedef struct KLB_Node {
    char *key;              // Mot en langue nationale
    char *value;            // Traduction en Yemba
    struct KLB_Node *next;  // Liste chaînée pour collisions
} KLB_Node;

typedef struct {
    KLB_Node *buckets[KLB_HASH_SIZE]; // Tableau de listes chaînées
} KLB_HashTable;

KLB_HashTable* KLB_createHashTable();
unsigned int KLB_hashFunction(const char *key);
void KLB_insert(KLB_HashTable *table, const char *key, const char *value);
const char* KLB_search(KLB_HashTable *table, const char *key);
void KLB_freeHashTable(KLB_HashTable *table);

#endif
