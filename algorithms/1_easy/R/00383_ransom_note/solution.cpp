class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> freqs{};

        for (const char& ch : magazine) {
            freqs[static_cast<size_t>(ch -'a')] += 1;
        }

        for (const char& ch : ransomNote) {
            const size_t index{static_cast<size_t>(ch -'a')};

            if (freqs[index] == 0) {
                return false;
            }

            freqs[index] -= 1;
        }

        return true;
    }
};
