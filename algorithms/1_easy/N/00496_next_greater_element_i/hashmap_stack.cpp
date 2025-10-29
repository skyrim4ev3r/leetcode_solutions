class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int curr_max{INT_MIN};
        unordered_map<int, int> hashmap{};
        stack<int> stack{};

        for (auto it{nums2.rbegin()}; it != nums2.rend(); ++it) {
            while (!stack.empty() && stack.top() < *it) {
                stack.pop();
            }

            if (!stack.empty()) {
                hashmap[*it] = stack.top();
            } else {
                hashmap[*it] = -1;
            }

            stack.push(*it);
        }

        vector<int> res{};
        res.reserve(nums1.size());

        for (const int &num: nums1) {
            res.push_back(hashmap[num]);
        }

        return res;
    }
};
