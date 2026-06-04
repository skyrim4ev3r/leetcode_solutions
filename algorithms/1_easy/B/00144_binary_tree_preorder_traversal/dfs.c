static inline size_t max(const size_t a, const size_t b)
{
    return a > b ? a : b;
}

struct vec_int {
    int* ptr;
    size_t len;
    size_t cap;
};

static inline void vec_push(struct vec_int* vec, int val)
{
    if (vec->len == vec->cap) {
        const size_t new_cap = max(2 * vec->cap, 1);
        vec->ptr = (int*) realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        vec->cap = new_cap;
    }

    vec->ptr[vec->len] = val;
    vec->len += 1;
}

static inline int* vec_into_owned(struct vec_int* vec)
{
    int* res = vec->ptr;
    vec->ptr = NULL;
    vec->len = 0;
    vec->cap = 0;
    return res;
}

void dfs(struct TreeNode* curr, struct vec_int* res)
{
    if(curr == NULL) {
        return;
    }

    vec_push(res, curr->val);
    dfs(curr->left, res);
    dfs(curr->right, res);
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
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct vec_int res = { ptr: NULL, len: 0, cap: 0};

    dfs(root, &res);
    *returnSize = (int) res.len;

    return vec_into_owned(&res);
}
