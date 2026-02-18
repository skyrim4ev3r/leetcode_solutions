const backtrack = (nums, res, temp, curr_index, len) => {
    const visited = new Set();
    for (let i = curr_index; i < len; ++i) {
        if (visited.has(nums[i])) {
            continue;
        }

        visited.add(nums[i])

        if (temp.length === 0 || nums[i] >= temp[temp.length - 1]) {
            temp.push(nums[i]);
            if (temp.length > 1) {
                res.push([...temp]);
            }
            backtrack(nums, res, temp, i + 1, len);
            temp.pop();
        }
    }
};

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
const findSubsequences = (nums) => {
    const len = nums.length;
    const temp = [];
    const res = [];

    backtrack(nums, res, temp, 0, len);

    return res;
};
