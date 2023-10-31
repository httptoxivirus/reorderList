class Solution {
    ListNode* findNode(ListNode* head, int n) {
        int i = 1;
        ListNode* node = NULL;
        while(i != n-2) {
            node = node->next;
        }
        return node;
    }

    ListNode* myFunction(ListNode* head, ListNode* pehleWali, int n) {
        //base case
        if(head == pehleWali) return head;
        // recurrence relation
        ListNode* chotaHead = myFunction(head->next,findNode(head,n-1),n);
        ListNode* temp = head->next;
        head->next = pehleWali->next;
        pehleWali->next = NULL;
        head->next->next = temp;
        return head;
    }

public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        int n = 2;
        ListNode* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
            n++;
        }
        head = myFunction(head,temp,n);
    }
};
