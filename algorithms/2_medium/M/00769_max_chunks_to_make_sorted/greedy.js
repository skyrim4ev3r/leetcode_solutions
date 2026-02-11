/**
 * @param {number[]} arr
 * @return {number}
 */
const maxChunksToSorted = (arr) => {
    const len = arr.length;
    let curr_best = 0;
    let count = 0;

    for (let i = 0; i < len; i += 1) {
        curr_best = Math.max(curr_best, arr[i]);

        if (i === curr_best) {
            count += 1;
        }
    }

    return count;
};
