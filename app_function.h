#ifndef KLB_APP_FUNCTION_H
#define KLB_APP_FUNCTION_H

#include "hash_table.h"

void displayUserChoice();
void translateWord(KLB_HashTable *dictionary);
void displayDictionary(KLB_HashTable *dictionary);
void addWord(KLB_HashTable *dictionary, const char *filename);
int getUserChoice();
void cleanApp(KLB_HashTable *dictionary);

#endif
