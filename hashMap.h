
#ifndef HASHMAP_H
#define HASHMAP_H

#define TABLE_SIZE 32  // Example table size for hash maps

// Define a structure for hash entries
typedef struct hash_entry {
    const char* key;  // The string key
    int value;        // The integer value (e.g., opcode for commands, register number for registers)
} hash_entry;
extern hash_entry* command_table[TABLE_SIZE];
extern hash_entry* register_table[TABLE_SIZE];
// Function prototypes
unsigned int hash(const char* str);
void insert(hash_entry* hash_table[], const char* key, int value);
int lookup(hash_entry* hash_table[], const char* key);
void cleanup(hash_entry* hash_table[]);
void loadTables(void);

#endif  // HASHMAP_H
