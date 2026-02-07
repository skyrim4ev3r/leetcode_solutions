/**
 * @param {number} n
 * @return {number}
 */
const get_digits = (n) => {
    let digits = [];

    while (n > 0) {
        digits.push(n % 10);
        n = Math.floor(n / 10);
    }

    digits.reverse();

    return digits;
}

const monotoneIncreasingDigits = (n) => {
    if (n < 10) {
        return n;
    }

    const digits = get_digits(n);
    const len = digits.length;
    let res = 0;
    let left = 0;
    let right = 0;

    while (right < len) {
        if (digits[right] == digits[left]) {
            right += 1;
        } else if (digits[right] > digits[left]) {
            while (left < right) {
                res *= 10;
                res += digits[left];
                left += 1;
            }
        } else {
            res *= 10;
            res += digits[left] - 1;
            left += 1;

            while (left < len) {
                res *= 10;
                res += 9;
                left += 1;
            }

            return res;
        }
    }

    // If 'right' reach end, then it means n has monotone increasing digits
    // So simply returning n is enough
    return n;
};
