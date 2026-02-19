class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> hashmap{};
        const size_t k_usize{ static_cast<size_t>(k) };

        for (const auto& w : words) {
            if (w.size() >= k_usize) {
                hashmap[w.substr(0, k_usize)] += 1;
            }
        }

        return static_cast<int>(
            std::count_if(
                hashmap.cbegin(),
                hashmap.cend(),
                [](const auto& pair) {
                    return pair.second > 1;
                }
            )
        );
    }
};
