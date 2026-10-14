
class Solution {
public:
    ListNode* reverse(ListNode* temp) {
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }        
        ListNode* sec = slow->next;
        slow->next = NULL;
        sec = reverse(sec);        
        ListNode* first = head;
        while (sec) {
            ListNode* next1 = first->next;
            ListNode* next2 = sec->next;
            first->next = sec;
            sec->next = next1;
            first = next1;
            sec = next2;
        }
    }
};
