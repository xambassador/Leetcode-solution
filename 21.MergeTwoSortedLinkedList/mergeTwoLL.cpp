#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Base case
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        if(l1->val < l2->val) {
            ListNode* myNode {l1};
            ListNode* tmp {l1->next};
            myNode->next = NULL;
            myNode->next = mergeTwoLists(tmp, l2);
            return myNode;
        }else { 
            ListNode* myNode {l2};
            ListNode* tmp {l2->next};
            myNode->next = NULL;
            myNode->next = mergeTwoLists(l1,tmp);
            return myNode;
        }
    }
};


int main() {
    Solution s;
    ListNode* l1{nullptr};
    ListNode* l1Tail {nullptr};
    int data;
    cin >> data;
    while(data != -1) {
        ListNode* node {new ListNode(data)};
        if(l1 == nullptr) {
            l1 = node;
            l1Tail = node;
        }else{
            l1Tail->next = node;
            l1Tail = node;
        }
        cin >> data;
    }    

    ListNode* l2 {nullptr};
    ListNode* l2Tail{nullptr};
    cin >> data;
    while(data != -1) {
        ListNode* node {new ListNode(data)};
        if(l2 == nullptr) {
            l2 = node;
            l2Tail = node;
        }else{
            l2Tail->next = node;
            l2Tail = node;
        }
        cin >> data;
    }

    l1 = s.mergeTwoLists(l1,l2);
    while(l1 != nullptr) {
        cout << l1->val << " ";
        l1 = l1->next;
    }
}