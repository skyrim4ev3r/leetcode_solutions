impl Solution {
    pub fn max_balanced_shipments(weight: Vec<i32>) -> i32 {

        let mut count = 0_i32;
        let mut index = 1_usize;
        let len = weight.len();

        while index < len {

            // last parcel should strictly less than the maximum weight.
            // to get maximum number, just need to count subarrs as fast as they meet condition
            // which is this simple comparison
            if weight[index - 1] > weight[index] {
                count += 1;

                // Next iter should not check this index any more by:  weight[index - 1]
                index += 2;
            } else {
                index += 1;
            }
        }

        count
    }
}
