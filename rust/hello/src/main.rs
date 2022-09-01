/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */



fn main() {
    let nums: Vec<i32> = vec!(2,7,11,15);
    let target: i32 = 9;

    let result = two_sum(nums, target);

    println!("hello world");
}

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut result:Vec<i32> = Vec::new();

    for (i, &el) in nums.iter().enumerate() {
      let t = &nums[(i+1)..nums.len()];

      for(j, &jel) in t.iter().enumerate() {
        if el + jel == target {
          result.push(i as i32);
          result.push((i+j+1) as i32);
        }
      }
    }

    return result;
}