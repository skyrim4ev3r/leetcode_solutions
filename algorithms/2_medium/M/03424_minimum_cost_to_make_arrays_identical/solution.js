const calc_cost = (arr, brr) => {
    const len = arr.length;
    let cost = 0;

    for (let i = 0; i < len; ++i) {
        cost += Math.abs(arr[i] - brr[i]);
    }

    return cost;
}

/**
 * @param {number[]} arr
 * @param {number[]} brr
 * @param {number} k
 * @return {number}
 */
const minCost = (arr, brr, k) => {
    const by_default_cost = calc_cost(arr, brr);
    arr.sort((a, b) => a - b);
    brr.sort((a, b) => a - b);
    const by_sort_cost = calc_cost(arr, brr) + k;

    return Math.min(by_default_cost, by_sort_cost);
};
