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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
        {
            return NULL;
        }
        if(head -> next == NULL)
        {
            return NULL;
        }

        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            cnt++;
        }
        
        temp = head;

        if(cnt == n)
        {
            head = temp -> next;
            temp -> next = NULL;
            delete temp;
            return head;
        }

        ListNode* prevNode = head;
        ListNode* delNode = NULL;
        int prevNodeCnt = 1;
        while(prevNodeCnt < cnt - n)
        {
            prevNode = prevNode -> next;
            prevNodeCnt++;
        }

        delNode = prevNode -> next;
        prevNode -> next = delNode -> next;
        delNode -> next = NULL;
        delete delNode;
        return head;
    }
};