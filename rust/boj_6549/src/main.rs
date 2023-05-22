// 7 2 1 4 5 1 3 3
// 4 1000 1000 1000 1000
// 0

use std::cmp;
use std::fmt::Write;

fn main() {
    let mut output = String::new();

    loop {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut histogram = input
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect::<Vec<i32>>();

        let n = histogram[0];

        if n == 0 {
            break;
        }

        histogram.remove(0);

        let mut i_stack = Vec::<usize>::new();
        let mut result: u64 = 0;

        for (pos, e) in histogram.iter().enumerate() {
            while !i_stack.is_empty() && &histogram[i_stack[i_stack.len() - 1]] >= e {
                let i = i_stack.pop().unwrap();

                let s: u64 = ((if i_stack.is_empty() {
                    pos
                } else {
                    pos - 1 - i_stack[i_stack.len() - 1]
                }) as u64)
                    * histogram[i] as u64;

                result = cmp::max(result, s);
            }

            i_stack.push(pos);
        }

        while !i_stack.is_empty() {
            let i = i_stack.pop().unwrap();

            let s: u64 = ((if i_stack.is_empty() {
                n as usize
            } else {
                n as usize - 1 - i_stack[i_stack.len() - 1]
            }) as u64)
                * histogram[i] as u64;

            result = cmp::max(result, s);
        }

        writeln!(output, "{result}").unwrap();
    }

    print!("{output}");
}
