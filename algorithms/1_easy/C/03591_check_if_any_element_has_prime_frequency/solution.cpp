class Solution {
    inline bool is_prime(int num) {
        if (num == 2) {
            return true;
        }

        if (num <= 1 || num % 2 == 0) {
            return false;
        }

        int sqrt_num{static_cast<int>(sqrt(num))};

        for (int i{3}; i <= sqrt_num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> res{};

        for(const int &num: nums){
            res[num] += 1;
        }

        for (const auto &[val, freqs]: res) {
            if (is_prime(freqs)) {
                return true;
            }
        }
    
        return false;
    }
};
