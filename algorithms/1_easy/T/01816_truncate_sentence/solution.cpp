class Solution {
public:
    static string truncateSentence(const string& s, const int k) {
        istringstream iss{ s };
        ostringstream oss{};
        string part;

        for (int i{ 0 }; i < k; ++i) {
            iss >> part;
            oss << part;

            if (i != k - 1) {
                oss << ' ';
            }
        }

        return oss.str();
    }
};
