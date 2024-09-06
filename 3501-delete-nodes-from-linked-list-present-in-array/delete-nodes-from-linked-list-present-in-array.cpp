class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* newdummy = dummy;
        while (dummy->next != nullptr) {
            int t = dummy->next->val;
            if (st.find(t) != st.end()) {
                ListNode* newnode = dummy->next;
                dummy->next = newnode->next;
                continue;
            }
            dummy = dummy->next;
        }
        return newdummy->next;
    }
};