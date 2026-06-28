#define MAX_ALLOWED_NUM 100000
#define MIN_ALLOWED_NUM 0
#define TABLE_LEN (MAX_ALLOWED_NUM - MIN_ALLOWED_NUM + 1)

pthread_mutex_t mutex_raw_map = PTHREAD_MUTEX_INITIALIZER;
static int raw_map[TABLE_LEN];

struct entity {
    int val;
    int freq;
};

struct freq_map {
    struct entity* ptr;
    size_t len;
};

static struct freq_map create_map(const int* nums, const int nums_len, const int min_num1, const int max_num1)
{
    const int need_len = max_num1 - min_num1 + 1;
    for (int i = 0; i < need_len; i += 1) {
        raw_map[i] = 0;
    }

    for (int i = 0; i < nums_len; i += 1) { 
        raw_map[nums[i] - min_num1] += 1;
    }

    int cnt = 0;
    for (int i = 0; i < need_len; i += 1) {
        if (raw_map[i] != 0) {
            cnt += 1;
        }
    }

    struct entity* res = malloc((size_t)cnt * sizeof(*res));
    assert(res != NULL);
    int res_idx = 0;

    for (int i = 0; i < need_len; i += 1) {
        if (raw_map[i] != 0) {
            res[res_idx] = (struct entity){ val: i + min_num1, freq: raw_map[i]};
            res_idx += 1;
        }
    }

    return (struct freq_map){ ptr: res, len: (size_t)cnt};
}

static int count_pairs(const int* nums1, const int nums1_len, const int* nums2, int const nums2_len) 
{
    int min_num1 = MAX_ALLOWED_NUM;
    int max_num1 = MIN_ALLOWED_NUM;
    for (int i = 0; i < nums1_len; i += 1) {
        const int num = nums1[i];
        assert(num >= MIN_ALLOWED_NUM && num <= MAX_ALLOWED_NUM);
        min_num1 = num < min_num1 ? num : min_num1;
        max_num1 = num > max_num1 ? num : max_num1;
    }
    struct freq_map map = create_map(nums1, nums1_len, min_num1, max_num1);
    const int map_len = (int)map.len;
    int res = 0;

    for (int i = 0; i < nums2_len; i += 1) {
        const int num = nums2[i];
        const int64_t sq = (int64_t)num * num;

        for (int j = 0; j < map_len; j += 1) {
            const int val = map.ptr[j].val;
            const int freq = map.ptr[j].freq;

            if (sq % val == 0) {
                const int other = sq / val;
                if (other == val) {
                    res += (int)(freq * (freq - 1) / 2); 
                } else if (other > val && other <= max_num1) {
                    const int other_freq = raw_map[other - min_num1];
                    res += freq * other_freq;
                }
            }
        }
    }

/* cleanup */
    free(map.ptr);
    return res;
}

int numTriplets(int* nums1, int nums1_len, int* nums2, int nums2_len)
{
    assert(nums1 != NULL && nums2 != NULL && nums1_len > 0 && nums2_len > 0);
    pthread_mutex_lock(&mutex_raw_map);
    const int res = count_pairs(nums1, nums1_len, nums2, nums2_len) + count_pairs(nums2, nums2_len, nums1, nums1_len);
    pthread_mutex_unlock(&mutex_raw_map);
    return res;
}
