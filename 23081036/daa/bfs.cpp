#include<iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
};

Node *root = NULL;

Node *insert(Node *node, int data){
    if(node==NULL){
        node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else if(data < node->data){
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;    
}

bool search(Node *node, int data, int &steps) {
    if (node == NULL) {
        return false; // target not found
    }
    steps++;
    if (data== node->data) {
        return true;
    } else if (data < node->data) {
        return search(node->left, data, steps); 
    } else {
        return search(node->right, data, steps); 
    }
}


int main(){
    int max;
    cout << "Enter the size of an array: ";
    cin >> max;
    int a[max];
    cout << "Enter the data for the array: ";
    for(int i = 0; i < max; i++){
        cin >> a[i];
        int temp = a[i];
        root = insert(root, temp);
    }
    
    int key;
    cout<<"Enter the the data to be searched: ";
    cin>>key;
    int steps=0;
    bool found = search(root, key, steps);

    if (found) {
        cout << "Value " << key << " found in the tree in " << steps << " steps." << endl;
    } else {
        cout << "Value " << key << " not found in the tree. Total steps: " << steps << endl;
    }

	return 0; 
}

