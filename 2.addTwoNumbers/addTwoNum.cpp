#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int val) : val(val),next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val),next(next) {}
};



ListNode* addTwoNumHelp(ListNode* l1,ListNode* l2, int carry){
    
    //Base case
    // case where both list is empty but carry is not zero
    if(l1 == NULL && l2 == NULL){
        if(carry > 0 && carry < 10){
            ListNode* node{new ListNode(carry)};
            return node;
        }else{
            return NULL;
        }
    }
    
    // List1 is not null but list2 is null and wise a versa
    if(l1 == NULL && l2 != NULL){
        int sum{l2->val + carry};
        if(sum > 9){
            carry = sum / 10;
            sum = sum % 10;
        }else{
            carry = 0;
        }
        ListNode* node{new ListNode(sum)};
        node->next = addTwoNumHelp(l1,l2->next,carry);
        return node;
    }else if(l1 != NULL && l2 == NULL){
        int sum{l1->val + carry};
        if(sum > 9){
            carry = sum / 10;
            sum = sum % 10;
        }else{
            carry = 0;
        }
        ListNode* node{new ListNode(sum)};
        node->next = addTwoNumHelp(l1->next,l2,carry);
        return node;
    }

    // If both list is same length
    int sum{l1->val + l2->val + carry};
    if(sum > 9){
        carry = sum / 10;
        sum = sum % 10;
    }else{
        carry = 0;
    }
    ListNode* head{new ListNode(sum)};
    head->next = addTwoNumHelp(l1->next,l2->next,carry);
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    return addTwoNumHelp(l1,l2,0);
}

int main(){
    int data;
    ListNode* head1{nullptr};
    ListNode* tail1{nullptr};
    cin >> data;
    while(data != -1){
        ListNode* node{new ListNode(data)};
        if(head1 == NULL){
            head1 = node;
            tail1 = node;
        }else{
            tail1->next = node;
            tail1 = node;
        }
        cin >> data;
    }
    ListNode* head2{nullptr};
    ListNode* tail2{nullptr};
    cin >> data;
    while(data != -1){
        ListNode* node{new ListNode(data)};
        if(head2 == NULL){
            head2 = node;
            tail2 = node;
        }else{
            tail2->next = node;
            tail2 = node;
        }
        cin >> data;
    }
    ListNode* head{addTwoNumbers(head1,head2)};
    ListNode* tmp{head};
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }cout << endl;
}