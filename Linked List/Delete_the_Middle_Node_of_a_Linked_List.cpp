/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;

        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return NULL;

        int cnt = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            cnt++;
        }
        int middle = cnt / 2;
        
        cnt = 0;
        ListNode* travTemp = head;
        ListNode* delNode = NULL;

        while(cnt < middle - 1)
        {
            travTemp = travTemp -> next;
            cnt++;
        }

        delNode = travTemp -> next;
        travTemp -> next = delNode -> next;
        delNode -> next = NULL;
        delete delNode;
        return head;
    }
};