class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap{};

        for (const int& stone : stones) {
            heap.push(stone);
        }

        while (heap.size() > 1) {
            const int x{heap.top()};
            heap.pop();
            const int y{heap.top()};
            heap.pop();

            if (x != y) {
                heap.push(x - y);
            }
        }

        return heap.size() == 0 ? 0 : heap.top();
    }
};
