class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(curr, prev):
            if (curr is None):
                return prev
            temp = curr.next
            curr.next = prev
            return self.reverse(temp, curr)
        return reverse(head, None)