/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    if (!head || !head.next) return head; // Handle empty list or single node

    // Find the middle of the list
    let slow = head, fast = head;
    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // Reverse the second half of the list
    let prev = null, curr = slow.next;
    slow.next = null; // Disconnect the first half
    while (curr) {
        const next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }

    // Merge the first half and the reversed second half
    let p1 = head, p2 = prev;
    while (p2) {
        const next1 = p1.next, next2 = p2.next;
        p1.next = p2;
        p2.next = next1;
        p1 = next1;
        p2 = next2;
    }
};

function reverse(head) {
    let prev = null;
    let curr = head;
    while (curr !== null) {
        const next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}