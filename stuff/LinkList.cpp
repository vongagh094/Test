#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node() {
        data = 0;
        next = nullptr;
    }
};
void insertValue(int value, int pos, node* head) {
    if(head == nullptr)
        return;
    for(int i= 0; i< pos - 1; i++, head= head->next) {
        ;
    }
    node* temp= new node();
    temp->data = value;
    temp->next = head->next;
    head->next = temp;
    if(pos == 0) {
        int tmp= temp->data;
        temp->data = head->data;
        head->data = tmp;
    }
}
void removeDuplicate(node* head) {
    if(head == nullptr)
        return;
    while(head) {
        node* cur = head;
        while(cur->next) {
            if(head->data == cur->next->data) {
                node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
        head = head->next;
    }
}
void findValue(node* head, int value) {
    int index= -1;
    for(int i= 0; head->next != nullptr; head=head->next, i++) {
        if(head->data == value) {
            index = i;
            cout << index << " " << endl;
        }
    }
    if(index == -1)
        cout << index;
}
int countElements(node* head) {
    int cnt= 0;
    if(head == nullptr)
        return 0;
    else {
        while(head->next) {
            cnt++;
            head = head->next;
        }
    }
    return cnt;
}
void countFrequency(node* head, int n) {
    if(head == nullptr)
        return;
    bool arr[n]{};
    node* cur= nullptr;
    int j;
    for(int i = 0; head->next != nullptr ; head = head->next, i++) {
        int cnt= 1;
        for(j= i+1, cur = head->next; cur->next != nullptr ; cur = cur->next, j++) {
            if(head->data == cur->data && !arr[j] ) {
                cnt++;
                arr[j] = 1;
            }
        }
        if(cnt == 1)
            continue;
        cout << head->data << " " << cnt << endl;
    }
}
int findMax(node* head) {
    if(head == nullptr)
        return 0;
    int max= INT_FAST8_MIN;
    while(head->next) {
        if(head->data > max)
            max = head->data;
        head = head->next;
    } 
    return max;
}
int findMin(node* head) {
    if(head == nullptr)
        return 0;
    int min= INT_FAST8_MAX;
    while(head->next) {
        if(head->data < min)
            min = head->data;
        head = head->next;
    } 
    return min;
}
void display(node* head) {
    if(head == nullptr) 
        return;
    else {
        while(head->next) {
            cout << head->data << " ";
            head = head->next;
        }
    }
}
void addNode(node* &cur, int value) {
    cur->next = new node();
    cur->data = value;
    cur = cur->next;
}
int main() {
    node* head = new node();
    node* cur = head;
    int x;
    while(cin >> x && x != 0) {
        addNode(cur, x);
    }
    // display(head);
    // cout << endl << findMax(head) << " " << findMin(head);

    // int num = countElements(head);
    // countFrequency(head, num);

    // int value;
    // cin >> value;
    // findValue(head, value);

    // removeDuplicate(head);
    // display(head);

    int value, pos;
    cin >> value >> pos;
    insertValue(value, pos, head);
    display(head);
    return 0;
}


