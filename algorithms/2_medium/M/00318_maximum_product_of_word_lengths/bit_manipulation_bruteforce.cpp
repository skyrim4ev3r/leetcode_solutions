class Solution {
public:
    int maxProduct(vector<string>& words) {
        const size_t len{ words.size() };
        vector<int> masks(len, 0);

        for (size_t i{ 0 }; i < len; ++i) {
            int mask{ 0 };

            for (const auto& ch : words[i]) {
                mask = mask | (1 << (ch - 'a'));
            }

            masks[i] = mask;
        }

        size_t max_product_len{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            for (size_t j{ i + 1 }; j < len; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    max_product_len = std::max(max_product_len, words[i].size() * words[j].size());
                }
            }
        }

        return static_cast<int>(max_product_len);
    }
};
