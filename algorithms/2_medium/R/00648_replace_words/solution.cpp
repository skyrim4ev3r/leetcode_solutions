class Solution {
public:
    static string replaceWords(vector<string>& dictionary, const string& sentence) {
        ranges::sort(dictionary, [](const auto& a, const auto& b) {
            return a.size() < b.size();
        });

        ostringstream res{};
        istringstream ss{sentence};
        string word;

        while (ss >> word) {
            bool is_inserted {false};

            for (const auto& d : dictionary) {
                if (word.starts_with(d)) {
                    res << d << ' ';
                    is_inserted = true;
                    break;
                }
            }

            if (!is_inserted) {
                res << move(word) << ' ';
            }
        }

        string final_word {res.str()};

        if (!final_word.empty()) {
            final_word.pop_back(); // to remove last ' ' char
        }

        return final_word;
    }
};
