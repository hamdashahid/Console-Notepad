#include<iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    char data;

    ListNode(char d = '\0' , ListNode* n = NULL){
        data = d;
        next = n;
    }

};

struct AVLnode{
    string data;
    AVLnode* right;
    AVLnode* left;

    AVLnode(string d = "" , AVLnode* r = NULL , AVLnode* l = NULL){
        data = d;
        right = r;
        left = l;
    }

};

struct QueueNode{
    string data;
    QueueNode* next;

    QueueNode(string d = " " , QueueNode* nxt = NULL){
        data = d;
        next = nxt;
    }
};

struct StackNode{
    string data;
    StackNode* next;

    StackNode(string d = " " , StackNode* n = NULL){
        data = d;
        next = n;
    }
};

class Queue{

};

class Stack{

};

class List{

};

class AVLtree{

};


void ReadTXT(){

}


int main(){

    cout<<"HELLO WORLD \n";
    return 0;
}