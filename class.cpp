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
node* mergeOrderList(node* head, node* phead) {
    node* Chead = nullptr;
    node* tmp = nullptr;
    if (head == nullptr && phead == nullptr)
        return nullptr;
    if (head == nullptr)
        return phead;
    if (phead == nullptr)
        return head;
    if (head->data < phead->data) {
        Chead = head;
        head = head->next;
    } else {
        Chead = phead;
        phead = phead->next;
    }
    tmp = Chead;
    while (head->next != nullptr && phead->next != nullptr) {
        if (head->data < phead->data) {
            tmp->next = head;
            head = head->next;
        } else {
            tmp->next = phead;
            phead = phead->next;
        }
        tmp = tmp->next;
    }
    if (head != nullptr)
        tmp->next = head;
    if (phead != nullptr)
        tmp->next = phead;
    return Chead;
}
void insertValOrdered(node* head, int value){
    for(node* tmp = head; tmp->next != nullptr; tmp = tmp->next){
        // if(tmp == nullptr || head->data > x)
        //     return insertAtBeginning(head, x);
        if(tmp->next->data > value && tmp->data < value){
            node* cur = new node();
            cur->next = tmp->next;
            cur->data = value;
            tmp->next = cur;
        }
    }
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
