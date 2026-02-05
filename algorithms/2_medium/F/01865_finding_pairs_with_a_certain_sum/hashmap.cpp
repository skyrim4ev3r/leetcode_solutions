class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqs_nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : 
        nums1{ nums1 },
        nums2{ nums2 },
        freqs_nums2{}
    {
        for (const auto& num2 : nums2) {
            freqs_nums2[num2] += 1;
        }
    }

    void add(int index, int val) {
        const int num2_prev_val{ nums2[static_cast<size_t>(index)] };
        const int num2_new_val{ num2_prev_val + val };
        nums2[static_cast<size_t>(index)] += val;

        const auto it{ freqs_nums2.find(num2_prev_val) };
        it->second -= 1;
        if (it->second == 0) {
            freqs_nums2.erase(it);
        }

        freqs_nums2[num2_new_val] += 1;
    }

    int count(int tot) {
        int count{ 0 };

        for (const auto& num1 : nums1) {
            const int other{ tot - num1 };
            const auto it{ freqs_nums2.find(other) };

            if (it != freqs_nums2.end()) {
                count += it->second;
            }

        }

        return count;
    }
};
