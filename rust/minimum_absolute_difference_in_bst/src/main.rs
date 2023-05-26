// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

use std::cell::RefCell;
use std::rc::Rc;
type OptNode = Option<Rc<RefCell<TreeNode>>>;

fn in_order_traverse(node: &OptNode, v: &mut Vec<i32>) {
    if let Some(node) = node {
        let node = node.borrow();
        in_order_traverse(&node.left, v);
        v.push(node.val);
        in_order_traverse(&node.right, v);
    }
}

fn main() {
    let mut min_diff = i32::MAX;
    let mut v = Vec::new();
    in_order_traverse(&root, &mut v);

    v.iter()
        .zip(v[1..].iter())
        .for_each(|(&x, &y)| min_diff = min_diff.min(y - x));

    min_diff
}
