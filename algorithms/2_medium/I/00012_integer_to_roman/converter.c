#define TOTAL_STEPS 13

char* intToRoman(int num)
{
    static const char* symbols[TOTAL_STEPS] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    static const int values[TOTAL_STEPS] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* res = malloc(20);
    size_t pos = 0;
    for (size_t i = 0; i < TOTAL_STEPS; i++) {
        while (num >= values[i]) {
            strcpy(res + pos, symbols[i]);
            pos += strlen(symbols[i]);
            num -= values[i];
        }
    }
    res[pos] = '\0';
    return res;
}
