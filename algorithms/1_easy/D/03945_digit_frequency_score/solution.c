#define FREQS_LEN 10

int digitFrequencyScore(int n)
{
    int freqs[FREQS_LEN] = { 0 };

    while (n > 0) {
        freqs[n % 10] += 1;
        n /= 10;
    }

    int score = 0;

    for (int i = 1; i < FREQS_LEN; i += 1) {
        score += i * freqs[i];
    }

    return score;
}
