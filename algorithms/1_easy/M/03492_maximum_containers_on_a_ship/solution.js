/**
 * @param {number} n
 * @param {number} w
 * @param {number} maxWeight
 * @return {number}
 */
const maxContainers = (n, w, maxWeight) => {
    return Math.min(Math.floor(maxWeight / w), n * n);
};
