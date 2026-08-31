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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*temp=head->next;
        ListNode*prev=head;
        
       int index=1;
       int first=-1;
      int last=-1;
       int maxi=-1;
       int mini=INT_MAX;
        while(temp->next!=nullptr){
            if(temp->val > prev->val && temp->val > temp->next->val|| 
            temp->val < prev->val && temp->val < temp->next->val){
               
                if(first==-1){
                    first=index;
                }
                else{
                    mini=min(mini,index-last);
                    maxi=max(maxi,index-first);

                }
                last=index;
            }
                prev=temp;
               temp=temp->next;
                
            index++;

        }
        if(mini==INT_MAX) return {-1,-1};
      

      return {mini,maxi};


    }
};