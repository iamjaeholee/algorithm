fn main() {
    let mut nums1: Vec<i32> = Vec::new();
    let mut nums2: Vec<i32> = Vec::new();
    let m = nums1.len() as i32;
    let n = nums2.len() as i32;

    merge(&mut nums1, m, &mut nums2, n);

    println!("test")
}

pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    let mut nums3: Vec<i32> = Vec::new();
    let mut p1 = 0;
    let mut p2 = 0;
    let mut v1 = 0;
    let mut v2 = 0;

    loop {
        if p1 >= m && p2 >= n {
            *nums1 = nums3;
            break ();
        }

        if p1 >= m {
            nums3.push(nums2[p2 as usize]);
            p2 = p2 + 1;
        } else if p2 >= (n) {
            nums3.push(nums1[p1 as usize]);
            p1 = p1 + 1;
        } else {
            v1 = nums1[p1 as usize];
            v2 = nums2[p2 as usize];

            if v1 < v2 {
                nums3.push(v1);
                p1 = p1 + 1;
            } else {
                nums3.push(v2);
                p2 = p2 + 1;
            }
        }
    }
}
