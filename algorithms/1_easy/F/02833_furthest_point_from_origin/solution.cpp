class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int balance{0};
        int offset{0};

        for (const char& ch : moves) {
            switch (ch) {
                case 'L':
                    balance -= 1;
                    break;
                case 'R':
                    balance += 1;
                    break;
                default:
                    offset += 1;
                    break;
            }
        }

        if (balance < 0) {
            return abs(balance - offset);
        }

        return balance + offset;
    }
};
