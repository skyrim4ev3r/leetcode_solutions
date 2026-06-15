#define MAX_KEY 1000000
#define MIN_KEY 0
#define DELETED_CELL_VAL -1

typedef struct {
   int table[MAX_KEY + 1];
} MyHashMap;

MyHashMap* myHashMapCreate()
{
    MyHashMap* init = malloc(sizeof(*init));
    assert(init != NULL);
    for (ptrdiff_t i = 0; i < MAX_KEY + 1; i += 1) { init->table[i] = DELETED_CELL_VAL; }
    return init;
}

void myHashMapPut(MyHashMap* obj, int key, int value)
{
    assert(obj != NULL && key <= MAX_KEY && key >= MIN_KEY);
    obj->table[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key)
{
    assert(obj != NULL && key <= MAX_KEY && key >= MIN_KEY);
    return obj->table[key];
}

void myHashMapRemove(MyHashMap* obj, int key)
{
    assert(obj != NULL && key <= MAX_KEY && key >= MIN_KEY);
    obj->table[key] = DELETED_CELL_VAL;
}

void myHashMapFree(MyHashMap* obj)
{
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
