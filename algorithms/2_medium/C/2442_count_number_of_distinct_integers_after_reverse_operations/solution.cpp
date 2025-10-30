class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> nums_set{};

        for (int &num: nums) {
            nums_set.insert(num);

            int rev_num{0};
            while (num > 0) {
                rev_num *= 10;
                rev_num += num % 10;
                num /= 10;
            }
    
            nums_set.insert(rev_num);
        }
    
        return nums_set.size();
    }
};
