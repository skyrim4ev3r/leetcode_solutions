class Solution {
public:
    bool canConstruct(string ransom_note, string magazine) {
        assert(ransom_note.size() <= numeric_limits<int>::max() && magazine.size() <= numeric_limits<int>::max());
        int freqs[26] = { 0 };

        for (const char ch : magazine) {
            assert(ch >= 'a' && ch <= 'z');
            freqs[ch -'a'] += 1;
        }

        for (const char ch : ransom_note) {
            assert(ch >= 'a' && ch <= 'z');
            int& freq = freqs[ch -'a'];

            if (freq == 0) {
                return false;
            }

            freq -= 1;
        }

        return true;
    }
};
