#define MAX_INPUT 100000

struct state {
    int memo[MAX_INPUT + 1];
    int pref[MAX_INPUT + 1];
    int curr_max;
};

int totalWaviness(int num1, int num2)
{
    static struct state state = { curr_max: 0 };
    static pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;

    pthread_mutex_lock(&state_mutex);

    if (state.curr_max <= num2) {
        for (int num = state.curr_max; num <= num2; num += 1) {
            const size_t idx = (size_t) num;
            if (num < 100) {
                state.memo[idx] = 0;
                state.pref[idx] = 0;
            } else {
                const int c = num % 10;
                const int b = (num / 10) % 10;
                const int a = (num / 100) % 10;
                const bool has_wave = (b > a && b > c) || (b < a && b < c);
                const int count = state.memo[idx / 10] + (int) has_wave;

                state.pref[idx] = count + state.pref[idx - 1];
                state.memo[idx] = count;
            }
        }
        state.curr_max = num2 + 1;
    }

    const int res = state.pref[(size_t) num2] - state.pref[(size_t) num1 - 1];
cleanup:
    pthread_mutex_unlock(&state_mutex);
    return res;
}
