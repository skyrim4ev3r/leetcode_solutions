class Solution {
public:
    int maxDistance(const string& moves) {
        int lr = 0;
        int ud = 0;
        int extra = 0;

        for (const char ch : moves) {
            switch (ch) {
                case 'U':
                    ud += 1;
                    break;
                case 'D':
                    ud -= 1;
                    break;
                case 'R':
                    lr += 1;
                    break;
                case 'L':
                    lr -= 1;
                    break;
                case '_':
                    extra += 1;
                    break;
                default:
                    fprintf(stderr, "invalid input");
                    abort();
                    break;
            }
        }

        return abs(ud) + abs(lr) + extra;
    }
};
