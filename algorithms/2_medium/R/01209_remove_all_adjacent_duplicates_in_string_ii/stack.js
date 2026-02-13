/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
const removeDuplicates = (s, k) => {
    const stack = [];

    for (const ch of s) {
        if (stack.length != 0 && stack[stack.length - 1][0] === ch) {
            stack[stack.length - 1][1] += 1;

            if (stack[stack.length - 1][1] === k) {
                stack.pop();
            }
        } else {
                stack.push([ch, 1]);
        }
    }

    let res = [];

    for (const [ch, freq] of stack) {
        for (let i = 0; i < freq; ++i) {
            res.push(ch);
        }
    }

    return res.join('');
};
