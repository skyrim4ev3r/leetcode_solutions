class Solution {
public:
    int secondHighest(string s) {
    
        array<int, 10> is_seen{};

        for (const char &ch: s) {
            if (ch >= '0' && ch <= '9') {
                is_seen[static_cast<size_t>(ch - '0')] = true;
            } 
        }

        int count{0};

        for (size_t i{9}; i < 10; --i) {
            if (is_seen[i]) {
                count += 1;

                if (count == 2) {
                    return i;
                }
            }
        }

        return -1;
    }
};
