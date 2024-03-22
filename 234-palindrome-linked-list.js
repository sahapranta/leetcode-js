/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
    let current = head;

    function recur(node) {
        if (node == null) {
            return true;
        }
        let ans = recur(node.next);
        if (node.val != current.val) {
            return false;
        }
        current = current.next;
        return ans;
    }

    return recur(head);
};
