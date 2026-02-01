class Solution {
public:
    int numSteps(string s) {
        int count{ 0 };

        while (s.size() > 1 && s.back() == '0') {
            count += 1;
            s.pop_back();
        }

        if (s.size() == 1) {
            return count;
        }

        return count + static_cast<int>(s.size()) + 1 + static_cast<int>(std::count(s.begin(), s.end(), '0'));
    }
};
