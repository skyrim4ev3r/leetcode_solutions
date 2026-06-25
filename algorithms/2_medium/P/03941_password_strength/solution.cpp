constexpr int table_size = 256;

class Solution {
public:
    static int passwordStrength(const string& password) {
        bool seen[table_size] = { false };

        for (const uint8_t byte : password) {
            seen[byte] = true;
        }

        int score = 0;

        for (int byte = 0; byte < table_size; byte += 1) {
            if (seen[byte]) {
                if ('a' <= byte && byte <= 'z') {
                    score += 1;
                } else if ('A' <= byte && byte <= 'Z') {
                    score += 2;
                } else if ('0' <= byte && byte <= '9') {
                    score += 3;
                } else if (byte == '!' || byte == '@' || byte == '#' || byte == '$') {
                    score += 5;
                }
            }
        }

        return score;
    }
};
