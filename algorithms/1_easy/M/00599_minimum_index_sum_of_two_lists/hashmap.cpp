class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, size_t> hashmap{};
        vector<string> res{};
        size_t min_index_sum{std::numeric_limits<size_t>::max()};
        const size_t len1{list1.size()};
        const size_t len2{list2.size()};

        for (size_t i{0}; i < len1; ++i) {
            hashmap.emplace(move(list1[i]), i);
        }

        for (size_t i{0}; i < len2; ++i) {
            if (i > min_index_sum) {
                break;
            }

            const auto it = hashmap.find(list2[i]);
            if (it != hashmap.end()) {
                const size_t sum{it->second + i};
                if (sum < min_index_sum) {
                    min_index_sum = sum;
                    res.clear();
                    res.emplace_back(move(list2[i]));
                } else if (sum == min_index_sum) {
                    res.emplace_back(move(list2[i]));
                }
            }
        }

        return res;
    }
};
