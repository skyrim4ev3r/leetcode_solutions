typedef struct {
    int* prefix;
    ptrdiff_t len;
} NumArray;

NumArray* numArrayCreate(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size > 0);
    const ptrdiff_t len = nums_size + 1;
    int* ptr = malloc((size_t)len * sizeof(*ptr));
    assert(ptr != NULL);
    ptr[0] = 0;
    for (ptrdiff_t i = 1; i < len; i += 1) {
        ptr[i] = nums[i - 1] + ptr[i - 1];
    }
    NumArray* res = malloc(sizeof(*res));
    assert(res != NULL);
    res->prefix = ptr;
    res->len = len;

    return res;
}

int numArraySumRange(NumArray* obj, int left, int right)
{
    assert(obj != NULL && left >=0 && right >= 0 && left <= right && right < obj->len - 1);
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray* obj)
{
    if (obj == NULL) { return; };
    free(obj->prefix);
    obj->prefix = NULL;
    obj->len = 0;
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
