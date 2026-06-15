#define MAX_KEY 1000000
#define MIN_KEY 0

typedef struct {
    bool seen[MAX_KEY + 1];
} MyHashSet;

MyHashSet* myHashSetCreate()
{
    MyHashSet* init = calloc(1, sizeof(*init));
    return init;
}

void myHashSetAdd(MyHashSet* obj, int key)
{
    assert(key <= MAX_KEY && key >= MIN_KEY);
    obj->seen[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key)
{
    assert(key <= MAX_KEY && key >= MIN_KEY);
    obj->seen[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key)
{
    assert(key <= MAX_KEY && key >= MIN_KEY);
    return obj->seen[key];
}

void myHashSetFree(MyHashSet* obj)
{
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
