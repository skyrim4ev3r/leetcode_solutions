/**
 * @param {string} s
 * @return {string}
 */
const largestEven = (s) => {
    const stack = s.split("");

    while (stack.length > 0 && stack[stack.length - 1] == '1') {
        stack.pop();
    }

    return stack.join("");
};
