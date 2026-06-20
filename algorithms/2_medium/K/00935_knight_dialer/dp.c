#define MOD 1000000007

int knightDialer(int n)
{
    int64_t dp[20] = { 0 };
    int64_t* curr = &dp[0];
    int64_t* next = &dp[10];
    for (int i = 0; i < 10; i += 1) { next[i] = 1; }

    for (int i = 1; i < n; i += 1) {
        curr[0] = (next[4] + next[6]) % MOD;
        curr[7] = (next[2] + next[6]) % MOD;
        curr[9] = (next[4] + next[2]) % MOD;
        curr[8] = (next[1] + next[3]) % MOD;
        curr[4] = (next[0] + next[9] + next[3]) % MOD;
        curr[6] = (next[1] + next[7] + next[0]) % MOD;
        curr[1] = (next[6] + next[8]) % MOD;
        curr[2] = (next[7] + next[9]) % MOD;
        curr[3] = (next[4] + next[8]) % MOD;
        curr[5] = 0;

        int64_t* temp = curr;
        curr = next;
        next = temp;
    }

    int64_t sum = 0;
    for (int i = 0; i < 10; i += 1) { sum += next[i]; }

    return (int)(sum % MOD);
}
