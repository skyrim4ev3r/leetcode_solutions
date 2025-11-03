class Solution {
public:
    bool judgeCircle(string moves) {

        if ((moves.size() & 1) == 1) {
            return false;
        }

        int lr{0};
        int ud{0};

        for (const char &ch: moves) {
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
                default:
                    break;
            }
        }

        return lr == 0 && ud == 0;
    }
};
