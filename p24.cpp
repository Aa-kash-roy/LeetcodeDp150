// link :: https://leetcode.com/problems/merge-k-sorted-lists/
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
        
        ListNode *ans= new ListNode();
        ListNode *last=ans;
        
        int n=lists.size();
        
        int flag=1;
        while(1)
        {
            int value=INT_MAX,idx=0;
            
            for(int i=0;i<n;i++){
            
                if((lists[i]!=nullptr) && (lists[i]->val < value)){
                    idx=i;
                    value=lists[i]->val;
                    flag=0;
                }
            }
            
            lists[idx]=lists[idx]->next;
            ListNode *temp=new ListNode(value);
            if(ans==NULL){
                ans=temp;
                last=temp;
            }
            else
            {
                last->next=temp;
                last=temp;
            }
        }
        
        return ans;
    }
};
