#include<iostream>
using namespace std;



struct QueueNode{
    char data;
    QueueNode* next;

    QueueNode(char d ='\0' , QueueNode* nxt = NULL){
        data = d;
        next = nxt;
    }
};



class Queue{
    public:
        QueueNode* front;
        QueueNode* rear;

        Queue(QueueNode* f =NULL , QueueNode* r = NULL){
            front = f;
            rear = r;
        }

        void enqueue(char add){
            if(isEmpty() == true){
                front = new QueueNode(add);
                rear = front;
                return;
            }

            rear->next = new QueueNode(add);
            rear = rear->next;
        }

        char dequeue(){
            if(isEmpty() == true){
                cout<<"QUEUE IS EMPTY \n";
                return '\0';
            }

            QueueNode* temp = front;
            front = front->next;
            if(front == NULL){
                rear = NULL;
            }
            char ch = temp->data;
            delete temp;
            return ch;
        }

        bool isEmpty(){
            return front == NULL && rear == NULL;
        }

        void display(){
            if (isEmpty()) {
                cout << "QUEUE IS EMPTY" << endl;
                return;
            }
            QueueNode* temp = front;
            while(temp != rear){
                cout << temp->data;
                temp = temp->next;
            }
            cout << rear->data << endl;
        }
        
        void makeEmpty(){
            while(!isEmpty()){
                dequeue();
            }
        }
};


int main() {
    Queue q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');

    cout << "Queue after enqueuing A, B, C: ";
    q.display();

    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Queue after dequeuing one element: ";
    q.display();

    q.MAKEeMPTY();
    cout << "Queue after making empty: ";
    q.display();

    return 0;
}