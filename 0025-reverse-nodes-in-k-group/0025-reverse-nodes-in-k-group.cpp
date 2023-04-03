class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *newHead = NULL, *c_node = NULL, *temp = NULL;
    while (head != NULL) {
        int i = 0;
        ListNode *current = head;
        while(i<k and current!=NULL){
            i++;
            current = current->next;
        }
        if(i == k) {
            i = 0;
            while (head != NULL and i < k) {
                ListNode *next = head->next;
                head->next = prev;
                prev = head;
                if (c_node == NULL) {
                    c_node = prev;
                }
                head = next;
                i++;
            }
            if (newHead == NULL) {
                newHead = prev;
                temp = c_node;
            } else {
                temp->next = prev;
                temp = c_node;
            }
            c_node = NULL;
            prev = NULL;
        }
        else {
            if(newHead == NULL){
                return head;
            }
            else{
                temp->next = head;
                break;
            }
        }

    }
    return newHead;
    }
};