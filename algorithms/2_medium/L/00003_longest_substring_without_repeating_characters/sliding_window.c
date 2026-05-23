#define MAP_LEN 256 // Cover all possible unsigned char values (0–255)

int lengthOfLongestSubstring(const char* s)
{
    if (s == NULL) {
        return 0;
    }

    int32_t last_seen[MAP_LEN];
    memset(last_seen, -1, sizeof(last_seen));
    size_t max_len = 0;
    size_t left = 0;

    for (size_t right = 0; s[right] != '\0'; ++right) {
        const size_t idx = (unsigned char) s[right];

        const size_t new_left = (size_t) (last_seen[idx] + 1);
        if (left < new_left) {
            left = new_left;
        }

        const size_t curr_len = right - left + 1;
        if (curr_len > max_len) {
            max_len = curr_len;
        }

        last_seen[idx] = (int32_t) right;
    }

    return (int) max_len;
}
