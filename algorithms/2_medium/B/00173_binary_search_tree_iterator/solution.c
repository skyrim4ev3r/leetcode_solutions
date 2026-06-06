/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static inline size_t max_usize(const size_t a, const size_t b)
{
    return a > b ? a : b;
}

typedef struct {
    struct TreeNode** ptr;
    size_t len;
    size_t cap;
} BSTIterator;

static inline void bst_iter_push(BSTIterator* bst_iter, struct TreeNode* node)
{
    if (bst_iter->cap == bst_iter->len) {
        const size_t new_cap = max_usize(2 * bst_iter->cap , 4);
        bst_iter->ptr = realloc(bst_iter->ptr, new_cap * sizeof(*bst_iter->ptr));
        bst_iter->cap = new_cap;
    }

    bst_iter->ptr[bst_iter->len] = node;
    bst_iter->len += 1;
}

static inline struct TreeNode* bst_iter_pop(BSTIterator* bst_iter)
{
    bst_iter->len -= 1;
    return bst_iter->ptr[bst_iter->len];
}

static inline void bst_iter_insert_node_and_all_left_childs(BSTIterator* bst_iter, struct TreeNode* curr)
{
    while (curr != NULL) {
        bst_iter_push(bst_iter, curr);
        curr = curr->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
    BSTIterator* bst_iter = malloc(sizeof(*bst_iter));
    bst_iter->cap = 0;
    bst_iter->len = 0;
    bst_iter->ptr = NULL;

    bst_iter_insert_node_and_all_left_childs(bst_iter, root);

    return bst_iter;
}

int bSTIteratorNext(BSTIterator* bst_iter)
{
    struct TreeNode* curr = bst_iter_pop(bst_iter);
    bst_iter_insert_node_and_all_left_childs(bst_iter, curr->right);
    return curr->val;
}

bool bSTIteratorHasNext(BSTIterator* bst_iter)
{
    return bst_iter->len != 0;
}

void bSTIteratorFree(BSTIterator* bst_iter)
{
    free(bst_iter->ptr);
    bst_iter->ptr = NULL;
    bst_iter->len = 0;
    bst_iter->cap = 0;
    free(bst_iter);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
