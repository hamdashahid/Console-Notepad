#include<iostream>
using namespace std;


struct ListNode{
    ListNode* next;
    ListNode* prev;
    char data;

    ListNode(char d = '\0' , ListNode* n = NULL , ListNode* p = NULL){
        data = d;
        next = n;
        prev = p;
    }

};



class List{
    public:
        ListNode* head;
        ListNode* tail;

        List(ListNode* h =NULL , ListNode* t = NULL){
            head = h;
            tail = t;
        }

        void append(char c) {
            if (isEmpty()) {
                head = new ListNode(c);  
                tail = head;            
                return;
            }
            
            ListNode* add = new ListNode(c);  
            tail->next = add;                 
            add->prev = tail;                 
            tail = add;                      
        }

        void remove(){
            if(isEmpty()) return;

            ListNode* temp = tail;
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
            delete temp;

            if(tail == NULL) {
                head = NULL;  
            }
        }


        bool isEmpty(){
            return head == NULL;
        }

        void display(){
            ListNode* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};


int main() {
    List myList;

    myList.append('a');
    myList.append('b');
    myList.append('c');

    cout << "List after appending a, b, c: ";
    myList.display();

    myList.remove();
    cout << "List after removing last element: ";
    myList.display();

    myList.remove();
    cout << "List after removing last element: ";
    myList.display();

    myList.remove();
    cout << "List after removing last element: ";
    myList.display();

    return 0;
}