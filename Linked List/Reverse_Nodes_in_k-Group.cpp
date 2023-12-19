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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        if (count < k) {
            return head;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i = 0; i < k; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(next, k);

        return prev;
    }
};