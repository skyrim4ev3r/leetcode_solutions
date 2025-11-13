class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack{};

        for (const string& op : operations) {
            if (op == "+") {
                stack.push_back(*(stack.cend() - 1) + *(stack.cend() - 2));
            } else if (op == "D") {
                stack.push_back(2 * stack.back());
            } else if (op == "C") {
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
            }
        }

        return reduce(stack.cbegin(), stack.cend(), 0);
    }
};
