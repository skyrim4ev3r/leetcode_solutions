/**
 * @param {number[]} nums
 * @return {number[]}
 */
const mergeAdjacent = (nums) => {
    const stack = [];

    for (const num of nums) {
        let temp = num;

        while (stack.length != 0 && stack[stack.length - 1] === temp) {
            temp *= 2;
            stack.pop();
        }

        stack.push(temp);
    }

    return stack;
};
