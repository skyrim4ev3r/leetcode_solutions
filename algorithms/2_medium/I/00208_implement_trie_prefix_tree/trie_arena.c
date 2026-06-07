#define CHILDREN_LEN 26

struct trie_node {
    bool is_end_of_word;
    uint16_t children[CHILDREN_LEN];
};

struct trie_node_vec {
    struct trie_node* ptr;
    size_t len;
    size_t cap;
};

static inline struct trie_node_vec trie_node_vec_new()
{
    struct trie_node* ptr = malloc(sizeof(*ptr));
    assert(ptr != NULL);
    memset(ptr, 0, sizeof(*ptr));
    struct trie_node_vec init_vec = { ptr: ptr, len: 1, cap: 1};
    return init_vec;
}

static inline void trie_node_vec_free_inner(struct trie_node_vec* vec)
{
    free(vec->ptr);
    vec->ptr = NULL;
    vec->len = 0;
    vec->cap = 0;
}

static inline void trie_node_vec_push_default(struct trie_node_vec* vec)
{
    if (vec->len == vec->cap) {
        const size_t new_cap = 2 * vec->cap;
        vec->ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        assert(vec->ptr != NULL);
        vec->cap = new_cap;
    }

    vec->len += 1;
    struct trie_node* select_row = &vec->ptr[vec->len - 1];
    memset(select_row, 0, sizeof(*select_row));
}

typedef struct {
    struct trie_node_vec arena;
} Trie;


Trie* trieCreate()
{
    Trie* init_trie = malloc(sizeof(*init_trie));
    assert(init_trie != NULL);
    init_trie->arena = trie_node_vec_new();
    return init_trie;
}

void trieInsert(Trie* obj, char* word)
{
    size_t curr = 0;

    for (size_t i = 0; word[i] != '\0'; i += 1) {
        const size_t child_idx = (size_t) (word[i] - 'a');
        assert(child_idx < CHILDREN_LEN);

        if (obj->arena.ptr[curr].children[child_idx] == 0) {
            trie_node_vec_push_default(&obj->arena);
            assert(obj->arena.len - 1 <= (size_t) UINT16_MAX);
            obj->arena.ptr[curr].children[child_idx] = (uint16_t) (obj->arena.len - 1);
        }

        curr = (size_t) obj->arena.ptr[curr].children[child_idx];
    }

    obj->arena.ptr[curr].is_end_of_word = true;
}

bool trieSearch(Trie* obj, char* word)
{
    size_t curr = 0;

    for (size_t i = 0; word[i] != '\0'; i += 1) {
        const size_t child_idx = (size_t) (word[i] - 'a');
        assert(child_idx < CHILDREN_LEN);
        curr = (size_t) obj->arena.ptr[curr].children[child_idx];

        if (curr == 0) {
            return false;
        }
    }

    return obj->arena.ptr[curr].is_end_of_word;
}

bool trieStartsWith(Trie* obj, char* prefix)
{
    size_t curr = 0;

    for (size_t i = 0; prefix[i] != '\0'; i += 1) {
        const size_t child_idx = (size_t) (prefix[i] - 'a');
        assert(child_idx < CHILDREN_LEN);
        curr = (size_t) obj->arena.ptr[curr].children[child_idx];

        if (curr == 0) {
            return false;
        }
    }

    return true;
}

void trieFree(Trie* obj)
{
    trie_node_vec_free_inner(&obj->arena);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
