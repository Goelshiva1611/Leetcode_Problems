class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummy1 = head;
        while (head->next != nullptr) {
            ListNode* dummy = new ListNode(__gcd(head->val, head->next->val),head->next);
            head->next = dummy;
            head = dummy->next;
        }
        return dummy1;
    }
};
