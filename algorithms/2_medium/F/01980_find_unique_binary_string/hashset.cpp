class Solution {
public:
    static string findDifferentBinaryString(const vector<string>& nums) {
        const size_t len {nums.size()};
        const unordered_set<string> exact(nums.begin(), nums.end());
        string bytes(len, '0');

        while (exact.contains(bytes)) {
            size_t i {len - 1};
            bytes[i] += 1;

            while (bytes[i] > '1') {
                bytes[i] -= 2;

                if (i > 0) {
                    bytes[i - 1] += 1;
                    i -= 1;
                } else {
                    break;
                }
            }
        }

        return bytes;
    }
};
