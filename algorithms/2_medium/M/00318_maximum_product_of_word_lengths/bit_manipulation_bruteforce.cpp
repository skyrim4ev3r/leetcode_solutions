class Solution {
public:
    static int maxProduct(const vector<string>& words) {
        const ptrdiff_t len = std::ssize(words);
        auto masks = vector<int>(len, 0);

        for (ptrdiff_t i = 0; i < len; i += 1) {
            int mask = 0;

            for (const auto& ch : words[i]) {
                mask |= (1 << (ch - 'a'));
            }

            masks[i] = mask;
        }

        ptrdiff_t max_product_len = 0;

        for (ptrdiff_t i = 0; i < len; i += 1) {
            for (ptrdiff_t j = i + 1; j < len; j += 1) {
                if ((masks[i] & masks[j]) == 0) {
                    max_product_len = std::max(max_product_len, std::ssize(words[i]) * std::ssize(words[j]));
                }
            }   
        }

        assert(max_product_len <= numeric_limits<int>::max());
        return static_cast<int>(max_product_len);
    }
};
