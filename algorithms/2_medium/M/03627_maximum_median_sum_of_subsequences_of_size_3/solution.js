/**
 * @param {number[]} nums
 * @return {number}
 */

// 1- Sort array
// 2- Choose two largest and one smallest for each sub-array, and second largest will be median
// 3- Add 2nd largest to sum as median

const maximumMedianSum = (nums) => {
    nums.sort((a, b) => b - a);

    let sum = 0;
    const begin = 1;
    const end = 1 + 2 * Math.floor(nums.length / 3);

    for (let i = begin; i < end; i += 2) {
        sum += nums[i];
    }

    return sum;
};
