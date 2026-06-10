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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto lambda=[](ListNode* a,ListNode* b){
            return a->val > b->val;

        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(lambda)>pq(lambda);
        for(ListNode* node:lists){
            if(node!=nullptr){
            pq.push(node);
            }
        }
        if(pq.empty()) return nullptr;
        
            ListNode*head=pq.top();
            pq.pop();

            if(head->next!=nullptr)
          pq.push(head->next);
        

          ListNode*tail=head;
         
        
          while(!pq.empty()){
            ListNode*curr=pq.top();
            pq.pop();
            tail->next=curr;
            tail=tail->next;
            if(curr->next!=nullptr)
              pq.push(curr->next);

          }
               
        


   return head;


    }
};