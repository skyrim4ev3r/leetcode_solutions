class Solution {
public:
    string convertToTitle(int col_number) {
        auto res = string();

        while (col_number >= 1) {
            const int rem = (col_number - 1) % 26;
            res.push_back(static_cast<char>(rem + 'A'));
            col_number = (col_number - 1) / 26;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};
