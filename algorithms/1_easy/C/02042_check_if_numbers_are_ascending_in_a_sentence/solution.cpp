class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream ss{s};
        string word;
        int curr_max{std::numeric_limits<int>::min()};

        while (ss >> word) {
            if (std::all_of(word.begin(), word.end(), ::isdigit)) {
                int number{std::stoi(word)};

                if (number <= curr_max) {
                    return false;
                }

                curr_max = number;
            }
        }

        return true;
    }
};
