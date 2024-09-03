// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            val,
            next: None,
        }
    }
}

pub fn add_two_numbers(
    l1: Option<Box<ListNode>>,
    l2: Option<Box<ListNode>>,
) -> Option<Box<ListNode>> {

    let mut sum = 0;
    let mut carry = 0;
    let mut l1_temp = l1;
    let mut l2_temp = l2;
    let mut head = Box::new(ListNode::new(0));
    let mut current = &mut head;

    while l1_temp.is_some() || l2_temp.is_some() {
        let x = l1_temp.as_ref().map_or(0, |node|node.val);
        let y = l2_temp.as_ref().map_or(0, |node|node.val);

        println!("{}" , x);
        println!("{}" , y);

        sum = carry + x + y;

        carry = sum / 10;

        
        current.next = Some(Box::new(ListNode::new(sum%10)));
        current = current.next.as_mut().unwrap();

        if let Some(node) = l1_temp {
            l1_temp = node.next;
        }
        if let Some(node) = l2_temp {
            l2_temp = node.next;
        }

    }

    if carry > 0 {
        current.next = Some(Box::new(ListNode::new(carry)));
    }

    head.next
}

fn main() {
    // Example 1:
    let l1 = Some(Box::new(ListNode {
        val: 2,
        next: Some(Box::new(ListNode {
            val: 4,
            next: Some(Box::new(ListNode {
                val: 3,
                next: None,
            })),
        })),
    }));

    let l2 = Some(Box::new(ListNode {
        val: 5,
        next: Some(Box::new(ListNode {
            val: 6,
            next: Some(Box::new(ListNode {
                val: 4,
                next: None,
            })),
        })),
    }));

    let result = add_two_numbers(l1, l2);
    println!("{:?}", result); // Output: [7, 0, 8]
}