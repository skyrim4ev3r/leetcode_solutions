#define MAX_ALLOWED_INPUT_VAL_AND_SIZE 1001
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1_size, int* nums2, int nums2_size, int* return_size)
{
    assert(nums1 != NULL && nums2 != NULL && return_size != NULL);
    assert(nums1_size >= 0 && nums1_size < MAX_ALLOWED_INPUT_VAL_AND_SIZE && 
           nums2_size >= 0 && nums2_size < MAX_ALLOWED_INPUT_VAL_AND_SIZE);

    static bool seen[MAX_ALLOWED_INPUT_VAL_AND_SIZE][2];
    static pthread_mutex_t array_mutex = PTHREAD_MUTEX_INITIALIZER;

    pthread_mutex_lock(&array_mutex);

    for (int i = 0; i < MAX_ALLOWED_INPUT_VAL_AND_SIZE; i += 1) {
        seen[i][0] = false;
        seen[i][1] = false;
    }

    for (int i = 0; i < nums1_size; i += 1) {
        const int num = nums1[i];
        assert(num < MAX_ALLOWED_INPUT_VAL_AND_SIZE);
        seen[num][0] = true;
    }

    for (int i = 0; i < nums2_size; i += 1) {
        const int num = nums2[i];
        assert(num < MAX_ALLOWED_INPUT_VAL_AND_SIZE);
        seen[num][1] = true;
    }

    int count = 0;
    for (int i = 0; i < MAX_ALLOWED_INPUT_VAL_AND_SIZE; i += 1) {
        if (seen[i][0] && seen[i][1]) {
            count += 1;
        }
    }

    int* res = malloc((size_t)count * sizeof(*res));
    assert(res != NULL);

    *return_size = count;

    int res_idx = 0;

    for (int i = 0; i < MAX_ALLOWED_INPUT_VAL_AND_SIZE; i += 1) {
        if (seen[i][0] && seen[i][1]) {
            res[res_idx] = i;
            res_idx += 1;
        }
    }

    pthread_mutex_unlock(&array_mutex);
    return res;
}
