#ifndef KLB_HASH_TABLE_H
#define KLB_HASH_TABLE_H

#define KLB_HASH_SIZE 26

typedef struct KLB_Node {
    char *key;             
    char *value;           
    struct KLB_Node *next;  
} KLB_Node;

typedef struct {
    KLB_Node *buckets[KLB_HASH_SIZE];
} KLB_HashTable;

KLB_HashTable* KLB_createHashTable();
unsigned int KLB_hashFunction(const char *key);
void KLB_insert(KLB_HashTable *table, const char *key, const char *value);
const char* KLB_search(KLB_HashTable *table, const char *key);
void KLB_freeHashTable(KLB_HashTable *table);

#endif
