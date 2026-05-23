#define HASH_SIZE 10007

struct Node {
    int key;
    int val;
    struct Node* next;
};

static inline size_t calc_hash(int key)
{
    return (size_t) ((key % HASH_SIZE + HASH_SIZE) % HASH_SIZE);
}

static inline struct Node** hashmap_create()
{
    return (struct Node**) calloc(HASH_SIZE, sizeof(struct Node*));
}

static void hashmap_cleanup(struct Node*** hashmap_ptr)
{
    struct Node** hashmap = *hashmap_ptr;
    if (!hashmap) {
        return;
    }

    for (size_t i = 0; i < HASH_SIZE; ++i) {
        struct Node* curr = hashmap[i];
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashmap);
}

static inline void hashmap_insert(struct Node** hashmap, int key, int val)
{
    const size_t hash = calc_hash(key);
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->val = val;
    node->next = hashmap[hash];
    hashmap[hash] = node;
}

static inline const int * hashmap_find(struct Node** hashmap, int key)
{
    const size_t hash = calc_hash(key);
    struct Node* curr = hashmap[hash];

    while (curr != NULL) {
        if (curr->key == key) {
            return &curr->val;
        }
        curr = curr->next;
    }

    return NULL;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    struct Node** hashmap __attribute__((cleanup(hashmap_cleanup))) = hashmap_create();
    size_t len = numsSize;

    for (size_t i = 0; i < len; ++i) {
        const int* other_val = hashmap_find(hashmap, target - nums[i]);

        if (other_val != NULL) {
            int* res = (int *) malloc(2 * sizeof(int));
            res[0] = *other_val;
            res[1] = (int) i;
            *returnSize = 2;
            return res;
        }

        hashmap_insert(hashmap, nums[i], (int) i);
    }

    *returnSize = 0;
    return NULL;
}
