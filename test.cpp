#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void ReadTXT(){
    // AVLtree avl;
    ifstream in;
    string ch="";
    in.open("dictionary.txt");
        while (!in.eof()){
            // AVLnode* temp;
            getline(in,ch);
            cout<<ch<<" ";
            // avl.insert(temp->data,avl.root);
        }
    in.close();
    // return avl.root;
}

int main() {
    // cout << "Hello, World!" << endl;
    ReadTXT();
    return 0;
}