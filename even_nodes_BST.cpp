
//  1)  The program count and display number of even nodes in a tree.

#include <iostream>
using namespace std;

typedef struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
}TNODE;

class BST {
private:
    TNODE *root;
    TNODE * createNode(int data){
        TNODE *newNode = new TNODE;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    TNODE* insert(TNODE *root, int data){
        if(root == NULL) {
            return createNode(data);
        }

        else if(root->data > data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
        return root;
    }

    void preorder(TNODE *root) {
        if(root == NULL)
            return;
        
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TNODE *root) {
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(TNODE *root) {
        if(root == NULL)
            return;
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    TNODE* search(TNODE *root, int data) {
        if(root == NULL)
            return NULL;
        
        else if(root->data == data)
            return root;
        
        else if(root->data > data)
            return search(root->left, data);
        
        else
            return search(root->right, data);
    }
    
    int numberOfNodes(TNODE *root) {
        if(root == NULL)
            return 0;
        return 1 + numberOfNodes(root->left) +  numberOfNodes(root->right);
    }

    int numberOfLeaves(TNODE *root) {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 1;
        return numberOfLeaves(root->left) + numberOfLeaves(root->right);
    }

    int heightOfTree(TNODE *root) {
        if(root == NULL)
            return 0;
        int a = 1 + heightOfTree(root->left);
        int b = 1 + heightOfTree(root->right);
        return a<b?b:a;
    }

    bool isBalanced(TNODE *root, int maxDiff=-1) {
        if(root == NULL)
            return true;
        int a = 1 + heightOfTree(root->left);
        int b = 1 + heightOfTree(root->right);
        if(abs(a-b)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
            
        return  false;
    }

    bool isClone(TNODE *r1, TNODE *r2){
        if(r1 == r2)
            return true;
        else if((r1==NULL && r2!=NULL) || (r1 != NULL && r2==NULL))
            return false;
        else if(r1->data == r2->data && isClone(r1->left, r2->left) && isClone(r1->right, r2->right))
            return true;
        return false;
    }
    void printRapp(TNODE* node, int &counter)
    {
        if (node != NULL) {     //   When "node != NULL", going left nodes firstly
            printRapp(node->left, counter);

            if (node->data % 2 == 0) {   //   Determine the even number in the tree.
                cout << node->data << " ";
                counter++;      //  Counting the number of even nodes.
            }

            printRapp(node->right, counter);    //   When "node == NULL", going right nodes.
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void preorder(){
        preorder(root);
    }
    void inorder(){
        inorder(root);
    }
    void postorder(){
        postorder(root);
    }
    bool search(int data){
        return (search(root, data) == NULL ? false: true);
    }

    int numberOfNodes(){
        return numberOfNodes(root);
    }
    int numberOfLeaves() {
        return numberOfLeaves(root);
    }
    int heightOfTree() {
        return heightOfTree(root);
    }

    bool isBalanced() {
        return isBalanced(root);
    }

    bool isClone(BST tree){
        return isClone(root, tree.root);
    }
    void print() { //   To reach the root, using rapper funct.
        int counter = 0;

        cout << "Even nodes are => ";   //  Printing even nodes.
        printRapp(root, counter);

        cout << "\nNumber of even numbers in the tree => " << counter << " in tree. " << endl; //   Printing even nodes number.
    }


};

int main(){

    BST tree;
    int data;

    cout << "Enter number to add your Binary Search Tree (Enter any negative number to stop): ";
    cin >> data;
    while (data > 0) {
        tree.insert(data);
        cin >> data;
    }
    tree.print();

    return 0;
}

