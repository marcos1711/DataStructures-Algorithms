//
//  main.cpp
//  Binary Trees
//
//  Created by Marcos Martinez on 12/4/19.
//  Copyright © 2019 Marcos Martinez. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
class tnode{
public:
    int data;
    tnode* left;
    tnode* right;
    tnode(tnode* left = NULL, tnode* right = NULL, int data = 0){
        this -> left = left;
        this -> right = right;
        this -> data = data;
    }
};
class binaryTree {
private:
    tnode* root;
public:
    binaryTree(){
        root = NULL;
    }
    tnode* returnRoot();
    tnode* copyTree(tnode* t);
    int countLeaf(tnode* t);
    int depth(tnode* t);
    void levelOrderScan(tnode* t);
    bool lookUp(tnode* t, int target);
    int level(tnode* t, int target);
};
tnode* binaryTree::returnRoot(){
    return root;
}
tnode* binaryTree:: copyTree(tnode* t){
    tnode* nLeft;
    tnode* nRight;
    tnode* newNode;
    if(t == NULL){return NULL;}
    nLeft = copyTree(t -> left);
    nRight = copyTree(t -> right);
    newNode = new tnode(nLeft, nRight, t-> data);
    return newNode;
}
int binaryTree::countLeaf(tnode* t){
    if(t == NULL){return 0;}
    
    if(t -> left == NULL && t -> right == NULL){return 1;}
    return countLeaf(t -> left) + countLeaf(t -> right);
}
int binaryTree::depth(tnode* t){
    int depthL;
    int depthR;
    int depthValue;
    if(t == NULL){return -1;}
    depthL = depth(t -> left);
    depthR = depth(t -> right);
    depthValue = 1 +(depthL > depthR ? depthL : depthR);
    return depthValue;
}
void binaryTree::levelOrderScan(tnode* t){
    if(t == NULL){return;}
    queue<tnode*> q;
    tnode* p;
    q.push(t);
    while(!q.empty()){
        p = q.front();
        cout << p-> data << " ";
        if(p -> left != NULL)
            q.push(t -> left);
        if(p -> right != NULL)
            q.push(t -> right);
            
            q.pop();
    }
    
}
bool binaryTree::lookUp(tnode* t, int target){
    if(t == NULL){return false;}
    
    if(t -> data == target){return true;}
    
    return lookUp(t->right, target) || lookUp(t-> right, target);
}
int binaryTree::level(tnode* t, int target){//can be found and if yes return level
    if(t == NULL){return -1;}
    if(lookUp(t, target) == true){
        
    }
    return -1;
}
class node{
public:
    int key;
    int value;
    node* left;
    node* right;
    node(node* left = NULL, node* right = NULL, int key = 0, int value = 0){
        this -> left = left;
        this -> right = right;
        this -> key = key;
        this -> value = value;
    }
};
class binarySearchTree {
private:
    node* root1;
public: binarySearchTree(){
    root1 = NULL;
}
    int search(node* t, int target);
};
int binarySearchTree::search(node* t, int target){
    if(t == NULL){
        return -1;
    }
    if(t -> key == target){
        return t-> value;
    }
    if(t -> key > target){
        return search(t -> left, target);
    }
    if(t -> key < target){
        return search(t -> right, target);
    }
    else {
        return -1;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
