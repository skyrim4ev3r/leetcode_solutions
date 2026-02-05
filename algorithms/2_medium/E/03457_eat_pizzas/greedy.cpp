class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        ranges::sort(pizzas);

        const size_t len{ pizzas.size() };
        const size_t total_days{ len / 4 };
        const size_t odd_days{ (total_days / 2) + (total_days & 1) };
        const size_t even_days{ (total_days / 2) };
        long long sum{ 0 };
        size_t curr_index{ len - 1 };

        for (size_t i{ 0 }; i < odd_days; ++i) {
            sum += static_cast<long long>(pizzas[curr_index]);
            curr_index -= 1;
        }

        for (size_t i{ 0 }; i <  even_days; ++i) {
            curr_index -= 1;
            sum += static_cast<long long>(pizzas[curr_index]);
            curr_index -= 1;
        }

        return sum;
    }
};
