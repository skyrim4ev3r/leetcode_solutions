class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> q{};
        ranges::sort(deck, std::greater<>());

        for (const auto& d : deck) {
            if (!q.empty()) {
                int val{ q.back() };
                q.pop_back();
                q.push_front(val);
            }

            q.push_front(d);
        }

        return vector<int>(q.begin(), q.end());
    }
};
