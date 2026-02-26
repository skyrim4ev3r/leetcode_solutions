const calc_sum_fact_digit = (n) => {
    const facts = new Array(10).fill(0);
    facts[0] = 1;
    for (let i = 1; i < 10; ++i) {
        facts[i] = i * facts[i - 1];
    }

    let sum = 0;

    while (n > 0) {
        sum += facts[n % 10];
        n = Math.floor(n / 10);
    }

    return sum;
}

const calac_freqs_digits = (n) => {
    const freqs = new Array(10).fill(0);
    while (n > 0) {
        freqs[n % 10] += 1;
        n = Math.floor(n / 10);
    }
    return freqs;
}

/**
 * @param {number} n
 * @return {boolean}
 */
const isDigitorialPermutation = (n) => {
    const sum_fact_digit = calc_sum_fact_digit(n);
    const freqs_digit_sum = calac_freqs_digits(sum_fact_digit);

    return calac_freqs_digits(n).every((num, i) => num === freqs_digit_sum[i]) ;
};
