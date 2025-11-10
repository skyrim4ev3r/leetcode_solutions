class Solution {

    const size_t MAX_SIZE{99};

    void capitalize_first_letter_and_fix_size(string& s) {

        if (s.size() > MAX_SIZE) {
            s.resize(MAX_SIZE);
        }

        s[0] = toupper(s[0]);
        for (size_t i = 1; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
        }
    }

public:
    string generateTag(string caption) {
        istringstream ss(caption);
        string word;
        string res{"#"};

        while (ss >> word && res.size() < MAX_SIZE) {
            capitalize_first_letter_and_fix_size(word);
            res += word;
        }

        //to lower() for first ascii char of first word, which start at index = 1
        if (res.size() > 1) {            
            res[1] = tolower(res[1]);
        }

        return res;
    }
};
