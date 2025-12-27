impl Solution {
    const MAX_NUM: usize = 101;

    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut map1 = [0_i32; Self::MAX_NUM];
        let mut map2 = [0_i32; Self::MAX_NUM];
        let mut count1 = 0_i32;
        let mut count2 = 0_i32;

        for num in nums1.into_iter() {
            map1[num as usize] += 1;
        }

        for num in nums2.into_iter() {
            map2[num as usize] +=1;
        }

        for i in 0..Self::MAX_NUM {
            if map1[i] > 0 && map2[i] > 0 {
                count1 += map1[i];
                count2 += map2[i];
            }
        }

        vec![count1, count2]
    }
}
