static inline size_t max_usize(const size_t a, const size_t b)
{
    return a > b ? a : b;
}

struct vec_int {
    int* ptr;
    size_t len;
    size_t cap;
};

static inline struct vec_int vec_int_new()
{
    struct vec_int init_vec = {ptr: NULL, len: 0, cap: 0};
    return init_vec;
}

static inline void vec_int_change_at(struct vec_int* vec, const size_t index, const int val)
{
    vec->ptr[index] = val;
}

static inline void vec_int_push(struct vec_int* vec, const int val)
{
    if (vec->len == vec->cap) {
        const size_t new_cap = max_usize(2 * vec->cap, 4);
        vec->ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        vec->cap = new_cap;
    }

    vec->ptr[vec->len] = val;
    vec->len += 1;
}

static inline int* vec_int_into_owned(struct vec_int* vec)
{
    int* res = vec->ptr;
    vec->ptr = NULL;
    res = realloc(res, vec->len * sizeof(*res));
    vec->cap = 0;
    vec->len = 0;
    return res;
}

void dfs(struct vec_int* res, struct TreeNode* curr, const size_t depth)
{
    if (curr == NULL) {
        return;
    }

    if (depth >= res->len) {
        vec_int_push(res, curr->val);
    } else {
        vec_int_change_at(res, depth, curr->val);
    }

    dfs(res, curr->left, depth + 1);
    dfs(res, curr->right, depth + 1);
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
int* rightSideView(struct TreeNode* root, int* return_size)
{
    struct vec_int res = vec_int_new();

    dfs(&res, root, 0);

    *return_size = res.len;
    return vec_int_into_owned(&res);
}
