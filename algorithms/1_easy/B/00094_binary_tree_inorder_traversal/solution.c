struct vector {
    int* arr;
    size_t len;
    size_t capacity;
};

static inline struct vector vector_default()
{
    struct vector init_vec = { arr: NULL, len: 0, capacity: 0 };
    return init_vec;
}

static inline void vector_into_owned(struct vector* res, int** arr, int* returnSize)
{
    *arr = (int*) realloc(res->arr, res->len * sizeof(*res->arr));
    res->arr = NULL;
    *returnSize = (int) res->len;
}

static void vector_push(struct vector* res, int val)
{
    if (res->len == res->capacity) {
        size_t new_capacity = res->capacity * 2;

        if (new_capacity == 0) {
            new_capacity = 1;
        }

        res->arr = (int*) realloc(res->arr, new_capacity * sizeof(*res->arr));
        res->capacity = new_capacity;
    }

    res->arr[res->len] = val;
    res->len += 1;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 static void inorder_traversal_helper(struct vector* res, struct TreeNode* curr_node)
 {
    if (curr_node == NULL) {
        return;
    }

    inorder_traversal_helper(res, curr_node->left);
    vector_push(res, curr_node->val);
    inorder_traversal_helper(res, curr_node->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct vector res = vector_default();

    inorder_traversal_helper(&res, root);

    int* arr = NULL;
    vector_into_owned(&res, &arr, returnSize);

    return arr;
}
