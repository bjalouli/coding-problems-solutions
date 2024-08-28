#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10000

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    HashNode* table[TABLE_SIZE];
} HashTable;

unsigned int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void hashTableInsert(HashTable* ht, int key, int value) {
    unsigned int index = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int hashTableSearch(HashTable* ht, int key) {
    unsigned int index = hash(key);
    HashNode* node = ht->table[index];
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Indicate not found
}

// void freeHashTable(HashTable* ht) {
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         HashNode* node = ht->table[i];
//         while (node) {
//             HashNode* temp = node;
//             node = node->next;
//             free(temp);
//         }
//     }
// }

int* two_sum(int* nums, int numsSize, int target) {
    HashTable ht = {0};
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = hashTableSearch(&ht, complement);
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            return result;
        }
        hashTableInsert(&ht, nums[i], i);
    }


    return NULL;
}

int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 3;
    
    int* indices = two_sum(nums, sizeof(nums) / sizeof(nums[0]), target);

    if (indices) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
