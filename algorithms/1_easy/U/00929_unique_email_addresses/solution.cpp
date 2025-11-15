class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hashset{};

        for (const string& email : emails) {
            string unique;
            const size_t pos = email.find('@');

            for (size_t i = 0; i < pos; ++i) {
                if (email[i] == '+') {
                    break;
                } else if (email[i] != '.') {
                    unique += email[i];
                }
            }

            unique += email.substr(pos);
            hashset.insert(unique);
        }

        return static_cast<int>(hashset.size());
    }
};
