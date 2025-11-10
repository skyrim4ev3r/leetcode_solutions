class Solution {
public:
    int numDifferentIntegers(string word) {

        string num_str{};
        bool is_seen_new_num{false};
        bool is_seen_zero{false};

        unordered_set<string> nums_str{};

        for (const char &ch: word) {
            if ((ch > '0' && ch <= '9') || (ch == '0' && is_seen_new_num)) {
                num_str.push_back(ch);
                is_seen_new_num = true;
                is_seen_zero = false;
            } else if (ch == '0' && !is_seen_new_num){
                is_seen_zero = true;
            } else {
                if (is_seen_new_num) {
                    is_seen_new_num = false;
                    nums_str.insert(num_str);
                    num_str = "";
                } else if (is_seen_zero) {
                    nums_str.insert("0");
                }
            }
        }

        if (is_seen_new_num) {
            nums_str.insert(num_str);
        } else if (is_seen_zero) {
            nums_str.insert("0");
        }

        return nums_str.size();
    }
};
