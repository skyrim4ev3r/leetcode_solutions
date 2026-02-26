/**
 * @param {string[]} instructions
 * @param {number[]} values
 * @return {number}
 */
const calculateScore = (instructions, values) => {
    const len = instructions.length;
    let curr_index = 0;
    let curr_score = 0;
    const seen = new Array(len).fill(false);

    while (curr_index >= 0 && curr_index < len && !seen[curr_index]) {
        seen[curr_index] = true;

        if (instructions[curr_index] === "jump") {
                curr_index = curr_index + values[curr_index];
        } else {
            curr_score += values[curr_index];
            curr_index += 1;
        }
    }

    return curr_score;
};
