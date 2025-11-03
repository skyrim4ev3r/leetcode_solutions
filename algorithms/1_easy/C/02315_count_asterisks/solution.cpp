class Solution {
public:
    int countAsterisks(string s) {
        int count{0};
        bool can_count{true};

        while (!s.empty()) {
            char ch = s.back();
            s.pop_back();

            switch (ch) {
                case '|':
                    can_count = !can_count;
                    break;
                case '*':
                    if (can_count) {
                        count += 1;
                    }
                    break;
                default:
                    break;
            }
        }

        return count;
    }
};
