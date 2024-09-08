
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* dummy = head;
        while (dummy != nullptr) {
            dummy = dummy->next;
            count++;
        }
        int quo = count / k;
        int remainder = count % k;
        vector<ListNode*> v(k);
        ListNode* d = head;
        int q = 0;
        int t = quo;
        for (int i = 0; i < k; i++) {
            d = head;
            if (remainder <= 0)
                t -= 1;
            while (t-- && head != nullptr) {
                head = head->next;
            }
            if (head != nullptr) {
                ListNode* newhead = head->next;
                head->next = nullptr;
                v[q++] = d;
                head = newhead;
            } else {
                v[q] = d;
            }
            remainder--;
            t = quo;
        }
        return v;
    }
};