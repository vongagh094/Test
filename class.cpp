#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node() {
        data = 0;
        next = nullptr;
    }
};
void insertValue(node* &head, int value , int pos){
    node* tmp = new node;
    // int cnt= 0;
    // for(node *i = head; i != nullptr; i = i->next){
    //     cnt++;
    // }
    node* cur= head;
    for(int i= 0; i< pos; i++){
        cur = cur->next;
    }
    tmp->next = cur->next;
    cur->next = tmp;
    tmp->data = value;
    return ;
}
void insertBegin(node*& head, int value){
    node* tmp = new node;
    tmp->next= head->next;
    head->next = tmp;
    tmp->data = head->data;
    head->data = value;
    return;
}
void output(node* head, node *last){
    if(head == nullptr) return; 
    for (node *cur = head; cur != last; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << endl;
}
void deleteLL(node* head){
    node* tmp = head;
    while(head){
        head = head->next;
        delete tmp;
        tmp = head;
    }
}
void delLinkList(node*& head, node* tmp){
    node* cur;
    tmp = head->next;
    cur = head;
    while(tmp != nullptr){
        delete cur;
        cur = tmp;
        tmp = tmp->next;
    }
    head = nullptr;
    return;
}
int main(){
    node* head = new node();
    node* last = head;
    for (int x; cin >> x && x != 0; )
    {
        last->data = x;
        last->next = new node();
        last = last->next;
    }
    node* tmp= NULL;
    int value, pos;
    cin >> value >> pos ; 
    insertValue(head, value, pos);
    output(head, last);
    return 0;
}
