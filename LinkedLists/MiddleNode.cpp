 ListNode *getMiddleNode(ListNode *head) {
        ListNode *slow = head;
        while(head && head->next) {
            slow = slow->next;
            head = head->next->next;
        }
        return slow;
    }