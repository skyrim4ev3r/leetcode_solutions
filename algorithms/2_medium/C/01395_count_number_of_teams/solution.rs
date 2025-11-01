impl Solution {
    pub fn num_teams(rating: Vec<i32>) -> i32 {
        
        let mut count = 0;

        // use j for middle value
        for j in 1..rating.len()-1 {

            //  count(rating[i]) < rating[j] < count(rating[k])
            let mut count_smaller_i = (0..j).filter(|&i| rating[i] < rating[j]).count() as i32;
            let mut count_bigger_k = (j+1..rating.len()).filter(|&k| rating[j] < rating[k]).count() as i32;
            
            //  count(rating[i]) > rating[j] > count(rating[k])
            let mut count_bigger_i = (j as i32 - 0) - count_smaller_i; // (j - 0) is total numbers count on left side of j ==> its just for easier reading
            let mut count_smaller_k= (rating.len() as i32 - (j as i32 + 1)) - count_bigger_k; // (rating.len() - ( j + 1)) ==> total number on right side of j 

            count += count_smaller_i * count_bigger_k + count_bigger_i * count_smaller_k;
        }

        count
    }
}
