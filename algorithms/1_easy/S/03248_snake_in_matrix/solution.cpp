class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i{0};
        int j{0};

        for (const string& command : commands) {
            if (command == "RIGHT") {
                j += 1;
            } else if (command == "LEFT") {
                j -= 1;
            } else if (command == "UP") {
                i -= 1;
            }  else if (command == "DOWN") {
                i += 1;
            }
        }

        return i * n + j;
    }
};
