class Solution {
public:
    int countCollisions(string directions) {
        string stack{};
        int count{0};

        for (const char& ch : directions) {
            switch (ch) {
                case 'L':
                    if (!stack.empty()) {
                        if (stack.back() == 'S') {
                            count += 1;
                        } else {
                            count += 2;
                            stack.pop_back();

                            while (!stack.empty() && stack.back() == 'R') {
                                count += 1;
                                stack.pop_back();
                            }

                            stack.clear();
                            stack.push_back('S');
                        }
                    }
                    break;
                case 'R': 
                    stack.push_back('R');
                    break;
                case 'S':
                    while (!stack.empty() && stack.back() == 'R') {
                        count += 1;
                        stack.pop_back();
                    }

                    stack.clear();
                    stack.push_back('S');
                    break;
                default:
                    break;
            }
        }

        return count;
    }
};
