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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
         // Right, Down, Left, Up
        vector<pair<int,int>> dir = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        int d = 0;      // current direction
        int r = 0, c = 0;
        while(head){
            ans[r][c]=head->val;
            head=head->next;
            int nr=r+dir[d].first;
            int nc=c+dir[d].second;
            //need to turn 
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || ans[nr][nc] != -1){
                d = (d + 1) % 4;
                nr = r + dir[d].first;
                nc = c + dir[d].second;
            }
            r = nr;
            c = nc;
        }
        return ans;
    }
};
