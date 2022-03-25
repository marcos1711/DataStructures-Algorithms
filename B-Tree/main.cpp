//
//  main.cpp
//  B-Tree Marcos Ramos
//
//  Created by Marcos Martinez on 4/27/20.
//  Copyright © 2020 Marcos Martinez. All rights reserved.
//

#include <iostream>
using namespace std;
class bTreeNode
{
    int *keys;
    int t;
    bTreeNode **c;
    int n;
    bool leaf;
    
public:
    bTreeNode(int _t, bool leaf);
    void traverse();
    bTreeNode *search(int k);
    void insertNonFull(int k);
    void splitChild(int i, bTreeNode *y);
    int findKey(int k);
    void remove(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPred(int idx);
    int getSucc(int idx);
    void fill(int idx);
    void borrowFromNext(int idx);
    void borrowFromPrev(int idx);
    void merge(int idx);
    friend class BTree;
};
class BTree
{
    bTreeNode *root;
    int t;
public:
    BTree(int _t)
    {root = NULL; t = _t;}
    
    void traverse()
    { if (root != NULL) root -> traverse();}
    
    bTreeNode* search (int k)
    { return (root == NULL)? NULL: root -> search(k); }
    
    void insert(int k);
    
    void remove(int k);
};

bTreeNode::bTreeNode(int _t, bool _leaf1)
{
    t = _t;
    leaf = _leaf1;
    keys = new int[2*t-1];
    c = new bTreeNode*[2*t];
    
    n = 0;
}
void bTreeNode::traverse()
{
    int i;
    for(i = 0; i < n; i++){
        if (leaf == false)
            c[i] -> traverse();
        cout << " " << keys[i];
    }
    if(leaf == false)
        c[i] -> traverse();
}
bTreeNode *bTreeNode::search(int k)
{
    int i = 0;
    while(i <n && k > keys[i])
        i++;
    
    if(keys[i] == k)
        return this;
    
    if(leaf == true)
        return NULL;
    
    return c[i] -> search(k);
}
void BTree::insert(int k)
{
    if(root == NULL)
    {
        root = new bTreeNode(t, true);
        root -> keys[0] = k;
        root -> n = 1;
    }
    else
    {
        if(root -> n == 2*t-1)
        {
            bTreeNode *s = new bTreeNode(t,false);
            s->c[0] = root;
            s-> splitChild(0, root);
            
            int i = 0;
            if(s -> keys[0] < k)
                i++;
            s -> c[i] -> insertNonFull(k);
            
            root = s;
        }
        else
            root -> insertNonFull(k);
    }
}
void bTreeNode::insertNonFull(int k)
{
    int i = n-1;
    if(leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1]=keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    }
    else
    {
        while(i >= 0 && keys[i] > k)
            i--;
        
        if(c[i+1] -> n == 2*t-1)
        {
            splitChild(i+1, c[i+1]);
            if(keys[i+1] < k)
                i++;
        }
        c[i+1] -> insertNonFull(k);
    }
}
void bTreeNode::splitChild(int i, bTreeNode *y)
{
    bTreeNode *z = new bTreeNode (y -> t, y -> leaf);
    z -> n = t -1;
    
    for( int j = 0; j < t-1; j++)
        z -> keys[j] = y -> keys[j+1];
    if( y -> leaf == false)
    {
        for(int j = 0; j < t; j++)
            z -> c[j] = y -> c[j+1];
    }
    y -> n = t -1;
    
    for(int j = n; j >= i+1; j--)
        c[j+1] = c[j];
    
    c[i+1] = z;
    
    for(int j = n -1; j >= i; j--)
        keys[j+1] = keys[j];
    
    keys[i] = y -> keys[t-1];
    
    n = n+1;
}

int bTreeNode::findKey(int k)
{
    int idx = 0;
    while(idx < n && keys[idx] < k)
        ++idx;
    return idx;
}
void bTreeNode::remove(int k)
{
    int idx = findKey(k);
    
    if(idx < n && keys[idx] == k)
    {
        if(leaf)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    }
    else
    {
        
        if(leaf)
        {
            cout << "The key " << k << " does not exist in the tree\n";
            return;
        }
        bool flag = ((idx ==n)? true: false);
        
        if(c[idx] -> n < t)
            fill(idx);
        
        if(flag && idx > n)
            c[idx] -> remove(k);
        else
            c[idx] -> remove (k);
    }
    return;
}
void bTreeNode::removeFromLeaf(int idx)
{
    for(int i = idx +1; i < n; i++)
        keys[i -1] = keys[i];
    
    n--;
    return;
}
void bTreeNode::removeFromNonLeaf(int idx)
{
    int k = keys[idx];
    
    if(c[idx] -> n >= t)
    {
        int pred = getPred(idx);
        keys[idx] = pred;
        c[idx] -> remove(pred);
    }
    else if(c[idx] -> n >= t)
    {
        int succ = getSucc(idx);
        keys[idx] = succ;
        c[idx+1] -> remove(succ);
    }
    else
    {
        merge(idx);
        c[idx] -> remove(k);
    }
    return;
}
int bTreeNode::getPred(int idx)
{
    bTreeNode *cur = c[idx];
    while(!cur -> leaf)
        cur = cur -> c[cur -> n];
    
    return cur -> keys[cur -> n-1];
}
int bTreeNode::getSucc(int idx)
{
    bTreeNode * cur = c[idx +1];
    while(!cur -> leaf)
        cur = cur -> c[0];
    return cur -> keys[0];
}
void bTreeNode::fill(int idx)
{
    if(idx !=0 && c[idx-1] -> n >= t)
        borrowFromPrev(idx);
    
    else if(idx != n && c[idx +1] -> n >= t)
        borrowFromNext(idx);
    
    else
    {
        if(idx != n)
            merge(idx);
        else
            merge(idx -1);
    }
    return;
}

void bTreeNode::borrowFromPrev(int idx)
{
    bTreeNode *child = c[idx];
    bTreeNode *sibling = c[idx -1];
    
    
    for(int i = child ->n-1; i >= 0; i--)
        child -> keys[i+1] = child -> keys[i];
    
    if(!child -> leaf)
    {
        for(int i = child-> n; i >= 0; i--)
            child -> c[i+1] = child ->c[i];
    }
    
    child -> keys[0] = keys[idx - 1];
    
    if(!child -> leaf)
        child -> c[0] = sibling -> c[sibling->n-1];
    
    keys[idx-1] = sibling -> keys[sibling -> n-1];
    
    child -> n += 1;
    sibling -> n -= 1;
    
    return;
}
void bTreeNode::borrowFromNext(int idx)
{
    bTreeNode *child = c[idx];
    bTreeNode *sibling = c[idx +1];
    child -> keys[(child -> n)] = keys[idx];
    
    if(!(child  -> leaf))
    {
        child -> c[(child -> n) +1] = sibling -> c[0];
    }
    keys[idx] = sibling ->keys[0];
    
    for(int i = 1; i <sibling -> n; ++i)
        sibling -> keys[i-1] = sibling -> keys [i];
    
    if(!sibling -> leaf)
    {
        for(int i = 1; i <= sibling -> n; ++i)
            sibling -> c[i-1] = sibling -> c[i];
    }
    
    child ->n += 1;
    sibling -> n -= 1;
    return;
    
}
void bTreeNode::merge(int idx)
{
    bTreeNode *child = c[idx];
    bTreeNode *sibling = c[idx +1];
    
    child -> keys[t-1] = keys[idx];
    
    for(int i =0; i < sibling -> n; ++i)
        child -> keys[i+t] = sibling -> keys[i];
    
    if(!child -> leaf)
    {
        for(int i = 0; i <= sibling -> n; ++i)
            child -> c[i+t] = sibling -> c[i];
    }
    
    for(int i = idx +1; i< n; ++i)
        keys[i-1] = keys[i];
    
    
    for(int i = idx +2; i <= n; ++i)
        c[i-1] = c[i];
    
    child -> n += sibling -> n+1;
    n--;
    delete(sibling);
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    BTree t(3);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(70);
    t.insert(50);
    t.insert(80);
    t.insert(90);
    t.insert(10);
    
    
    cout << "Traversla of the constructed tree is ";
    t.traverse();
    
    int k = 20;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    
    k = 90;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present" << endl;
    
    t.remove(10);
    t.traverse();
    
    return 0;
}
 
//
