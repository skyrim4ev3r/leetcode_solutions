class Solution {
public:
    int numberOfWays(string corridor) {
        int seat_count = std::count(corridor.begin(), corridor.end(), 'S');

        if (seat_count == 0 || (seat_count & 1) == 1) {
            return 0;
        }

        long long curr_seat_count{0};
        long long continues_plant_count{0};
        const size_t len{corridor.size()};
        const long long MOD_TO{1'000'000'007};
        size_t start_index{0};
        size_t end_index{len - 1};
        long long count{1};

        while (corridor[start_index] != 'S') {
            start_index += 1;
        }

        while (corridor[end_index] != 'S') {
            end_index -= 1;
        }

        for (size_t i{start_index}; i <= end_index; ++i) {
            if (corridor[i] == 'S') {
                curr_seat_count += 1;

                if ((curr_seat_count & 1) == 1) {
                    count = (count * (continues_plant_count + 1)) % MOD_TO;
                }

                continues_plant_count = 0;
            } else {
                continues_plant_count += 1;
            }
        }

        return static_cast<int>(count);
    }
};
