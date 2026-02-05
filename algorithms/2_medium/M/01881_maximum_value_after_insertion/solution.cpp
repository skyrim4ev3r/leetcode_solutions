class Solution {
public:
    string maxValue(string n, int x) {
        const size_t len{ n.size() };
        char ch{ static_cast<char>(x + '0') };

        if (n[0] == '-') {
            size_t i{ 1 };

            while (i < len && n[i] <= ch) {
                ++i;
            }

            n.insert(i, 1, ch);
        } else {
            size_t i{ 0 };

            while (i < len && n[i] >= ch) {
                ++i;
            }

            n.insert(i, 1, ch);
        }

        return n;
    }
};
