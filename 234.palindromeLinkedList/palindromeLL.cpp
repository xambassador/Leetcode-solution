#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


bool isPalindrome(ListNode* head) {
     // Reverse the first half list.
        ListNode *reverse = nullptr, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            const auto head_next = head->next;
            head->next = reverse;
            reverse = head;
            head = head_next;
        }

        // If the number of the nodes is odd,
        // set the head of the tail list to the next of the median node.
        ListNode *tail = fast ? head->next : head;

        // Compare the reversed first half list with the second half list.
        // And restore the reversed first half list.
        bool is_palindrome = true;
        while (reverse) {
            is_palindrome = is_palindrome && reverse->val == tail->val;
            const auto reverse_next = reverse->next;
            reverse->next = head;
            head = reverse;
            reverse = reverse_next;
            tail = tail->next;
        }
            
        return is_palindrome;   
}

int main() {
    int x;
    cin >> x;
    ListNode* head{NULL}, *tail{NULL};
    while(x != -1) {
        ListNode* node {new ListNode(x)};
        if(head == NULL) {
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
        cin >> x;
    }
    bool ans {isPalindrome(head)};
    cout << boolalpha << ans << endl;
}   