
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (p && q) {
            if (p->val >= q->val) {
                tail->next = q;
                q = q->next;
            } else {
                tail->next = p;
                p = p->next;
            }

            tail = tail->next;
        }

        tail->next = p ? p : q;

        ListNode* res = dummy->next;
        delete dummy;

        return res;
    }
};
