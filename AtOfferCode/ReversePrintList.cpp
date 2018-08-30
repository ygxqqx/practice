// 题目描述
// 输入一个链表，从尾到头打印链表每个节点的值。

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> numbers;
        if (head != NULL) {
            ListNode* p = head;
            stack<ListNode*> s;
            while (p != NULL) {
                s.push(p);
            	p = p->next;
            }
            while (!s.empty()) {
                p = s.top();
                numbers.push_back(p->val);
                s.pop();
            }
        }
        return numbers;
    }
};
