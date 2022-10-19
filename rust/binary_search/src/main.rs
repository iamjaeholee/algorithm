fn main() {
    let nums: Vec<i32> = vec![-1, 0, 3, 5, 9, 12];
    let target = 9;
    let result = search(nums, target);
    println!("{}", result);
}

pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    let mut l = 0;
    let mut r = (nums.len() as i32) - 1;
    let mut m = 0;

    let result = loop {
        // calc m
        m = (l + r) / 2;
        let c = nums[m as usize] as i32;

        if c == target {
            break m;
        } else if c <= target {
            l = m + 1;
        } else {
            r = m - 1;
        }

        // break if there is no result
        if l > r {
            break -1;
        }
    };

    return result;
}
