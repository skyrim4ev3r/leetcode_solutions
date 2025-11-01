class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int count{0};
        const size_t len{rating.size()};

        // use j for middle value
        for (size_t j{0}; j < len; ++j) {

            int smaller_counts_left{0};
            int bigger_counts_left{0};
            for (size_t i{0}; i < j; ++i) {                
                if (rating[i] < rating[j]) {
                    ++smaller_counts_left;
                } else {
                    ++bigger_counts_left;
                }
            }

            int smaller_counts_right{0};
            int bigger_counts_right{0};
            for (size_t k{j + 1}; k < len; ++k) {
                if (rating[k] < rating[j]) {
                    ++smaller_counts_right;
                } else {
                    ++bigger_counts_right;
                }
            }

            count += smaller_counts_left * bigger_counts_right + bigger_counts_left * smaller_counts_right;
        }

        return count;
    }
};
