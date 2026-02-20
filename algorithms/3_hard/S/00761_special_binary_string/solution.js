/**
 * @param {string} s
 * @return {string}
 */
const makeLargestSpecial = (s) => {
    const len = s.length;
    if (len <= 2) {
        return s;
    }
    let left = 0;
    let balance = 0;
    const parts = [];

    for (let right = 0; right < len; ++right) {
        if (s[right] === '1') {
            balance += 1;
        } else {
            balance -= 1;
        }

        if (balance === 0) {
            parts.push("1" + makeLargestSpecial(s.substr(left + 1, right - left - 1)) + "0");
            left = right + 1;
        }
    }

    parts.sort((a, b) => b.localeCompare(a));
    return parts.join("");
};
