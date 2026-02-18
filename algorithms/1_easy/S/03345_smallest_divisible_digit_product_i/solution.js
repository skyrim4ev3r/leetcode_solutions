const calc_product_digits = (n) => {
    let res = 1 ;

    while (n > 0) {
        res = res * (n % 10);
        n = Math.floor(n / 10);
    }

    return res;
}

/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
const smallestNumber = (n, t) => {
    // In every 10 consecutive numbers, at least one has the digit 0,
    // ensuring a product of 0, which satisfies the condition 0 % t == 0.
    for (let i = n; i < n + 10; ++i) {
        const product_digits = calc_product_digits(i);

        if (product_digits % t === 0) {
            return i;
        }
    }

    throw "Unreachable code executed";
};
