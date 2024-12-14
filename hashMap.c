#include "hashMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hash tables
hash_entry* command_table[TABLE_SIZE];
hash_entry* register_table[TABLE_SIZE];

// Simple hash function (could be more complex if needed)
unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str;
        str++;
    }
    return hash % TABLE_SIZE;  // Ensure it stays within bounds
}

// Insert into the hash table with linear probing
void insert(hash_entry* hash_table[], const char* key, int value) {
    unsigned int idx = hash(key);
    unsigned int original_idx = idx;

    // Linear probing: if the slot is occupied, move to the next one (wrap around)
    while (hash_table[idx] != NULL) {
        // If the key already exists, update the value
        if (strcmp(hash_table[idx]->key, key) == 0) {
            hash_table[idx]->value = value;
            return;
        }
        idx = (idx + 1) % TABLE_SIZE;  // Wrap around if we go out of bounds
        if (idx == original_idx) {
            printf("Hash table is full, unable to insert\n");
            return;
        }
    }

    // Create a new entry and insert it
    hash_entry* new_entry = (hash_entry*) malloc(sizeof(hash_entry));
    new_entry->key = key;
    new_entry->value = value;
    hash_table[idx] = new_entry;
}

// Lookup in the hash table using linear probing
int lookup(hash_entry* hash_table[], const char* key) {
    unsigned int idx = hash(key);
    unsigned int original_idx = idx;

    // Linear probing: keep checking the next slot if there's a collision
    while (hash_table[idx] != NULL) {
        if (strcmp(hash_table[idx]->key, key) == 0) {
            return hash_table[idx]->value;
        }
        idx = (idx + 1) % TABLE_SIZE;  // Wrap around if we go out of bounds
        if (idx == original_idx) {
            break;  // We've looped around, so the key is not in the table
        }
    }
    return -1;  // Key not found
}

// Clean up the hash table
void cleanup(hash_entry* hash_table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            free(hash_table[i]);
        }
    }
}

// Load both command and register tables
void loadTables() {
    // Example command insertions (with opcodes)
    insert(command_table, "MOV", 0x0);
    insert(command_table, "PNT", 0x1);
    insert(command_table, "CPY", 0x2);
    insert(command_table, "AND", 0x3);
    insert(command_table, "OR", 0x4);
    insert(command_table, "XOR", 0x5);
    insert(command_table, "ADD", 0x6);
    insert(command_table, "SUB", 0x7);

    // Example register insertions (with register numbers)
    insert(register_table, "R1", 0x1);
    insert(register_table, "R2", 0x2);
    insert(register_table, "R3", 0x3);
    insert(register_table, "R4", 0x4);
    insert(register_table, "R5", 0x5);
    insert(register_table, "R6", 0x6);
    insert(register_table, "R7", 0x7);
    insert(register_table, "R8", 0x8);
    insert(register_table, "PC", 0x9);
    insert(register_table, "SP", 0xA);
}
