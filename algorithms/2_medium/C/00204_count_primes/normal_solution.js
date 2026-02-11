/**
 * @param {number} n
 * @return {number}
 */
const countPrimes = (n) => {
    if (n < 3) {
        return 0;
    }

    let is_prime = new Array(n).fill(true);
    let ceil_sqrt_n = Math.ceil(Math.sqrt(n))

    is_prime[0] = false;
    is_prime[1] = false;

    for (let i = 0; i <= ceil_sqrt_n; i += 1) {
        if (is_prime[i]) {
            for (let j = i * 2; j <n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime.filter(p => p === true).length;
};
