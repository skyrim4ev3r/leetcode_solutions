/**
 * @param {string} num
 * @return {boolean}
 */
const isBalanced = (num) => {
    const len = num.length;
    let balance = 0;

    for (let i = 0; i < len; ++i) {
        if ((i & 1) === 1) {
            balance += num.charCodeAt(i) - '0'.charCodeAt(0);
        } else {
            balance -= num.charCodeAt(i) - '0'.charCodeAt(0);
        }
    }

    return balance === 0;
};
