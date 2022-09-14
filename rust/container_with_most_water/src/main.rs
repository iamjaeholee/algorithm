/*
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        
    }
}

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Input: height = [1,1]
Output: 1

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
 */

use std::cmp;

fn main() {
    let height: Vec<i32> = vec!(1,8,6,2,5,4,8,3,7);

    let result = max_area(height);
    println!("{}", result);
}

pub fn max_area(height: Vec<i32>) -> i32 {
  let mut result: i32 = 0;

  for(x, &y) in height.iter().enumerate() {
    let t = &height[(x+1)..height.len()];

    for(nx, &ny) in t.iter().enumerate() {
      let cal = (nx as i32 + 1) * cmp::min(y, ny);
      result = cmp::max(result, cal);
    }
  }

  result
}