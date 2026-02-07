/**
 * @param {number[]} nums
 * @return {number}
 */
const minMoves = (nums) => {
    const min = Math.min(...nums);
    let count = 0;

    for (const num of nums) {
        count += num - min;
    }

    return count;
};
