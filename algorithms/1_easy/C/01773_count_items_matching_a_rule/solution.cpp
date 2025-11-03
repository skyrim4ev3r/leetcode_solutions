class Solution {
public:
    int countMatches(vector<vector<string>>& items, string rule_key, string rule_value) {
        int count{0};

        for (const auto &item: items) {

            if ((rule_key == "type" && rule_value == item[0])
                || (rule_key == "color" && rule_value == item[1])
                || (rule_key == "name" && rule_value == item[2]))
            {
                count += 1;
            }
        }

        return count;
    }
};
