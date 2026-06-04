constexpr size_t MAX_INPUT_NUM = 100000;

struct State {
    int memo[MAX_INPUT_NUM + 1];
    int pref[MAX_INPUT_NUM + 1];
    int curr_max = 0;
};

class Solution {
public:
    static int totalWaviness(const int num1, const int num2) {
        static State state;
        static std::mutex state_mutex;

        std::lock_guard<std::mutex> lock(state_mutex);

        if (state.curr_max <= num2) {
            for (int num = state.curr_max; num <= num2; ++num) {
                const size_t idx = static_cast<size_t>(num);
                if (num < 100) {
                    state.memo[idx] = 0;
                    state.pref[idx] = 0;
                } else {
                    int c = num % 10;
                    int b = (num / 10) % 10;
                    int a = (num / 100) % 10;
                    bool has_wave = (b > a && b > c) || (b < a && b < c);
                    int count = state.memo[idx / 10] + static_cast<int>(has_wave);

                    state.pref[idx] = count + state.pref[idx - 1];
                    state.memo[idx] = count;
                }
            }
            state.curr_max = num2 + 1;
        }

        return state.pref[static_cast<size_t>(num2)] - state.pref[static_cast<size_t>(num1) - 1];
    }
};
