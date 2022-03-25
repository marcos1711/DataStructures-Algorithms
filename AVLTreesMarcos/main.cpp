#include <iostream>
using namespace std;
class tnode
{
    public:
    int data;
    tnode *left;
    tnode *right;
    int height;
};
int max(int a, int b){
  return (a > b)? a: b;
}
int height(tnode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
  
tnode* newNode(int key){
    tnode* node = new tnode();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
return(node);
}
tnode *rotateRight(tnode* y){
  tnode* x = y -> left;
  tnode* g = x-> right;
  x -> right = y;
  y -> left = g;
  y -> height = max(height(y-> left), height(y->right)) + 1;
  x -> height = max(height(x-> left), height(x-> right)) + 1;

  return x;
}
tnode *leftRotate(tnode *x)
{
    tnode *y = x->right;
    tnode *T2 = y->left;
   
    y->left = x;
    x->right = T2;
   
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
  
    return y;
}
int getBalance(tnode* t){
  if(t == NULL)
  return 0;
  return height(t->left) - height(t->right);
}
tnode* insert(tnode* t, int key){
  if(t == NULL){
    return (newNode(key));
  }
  if (key < t->data)
        t->left = insert(t->left, key);
  else if (key > t->data) {
        t->right = insert(t->right, key);
  }
  else
        return t;
  
    
    t->height = 1 + max(height(t->left),
                        height(t->right));
  
    int balance = getBalance(t);
   
    if (balance > 1 && key < t->left->data)
        return rotateRight(t);
  
   
    if (balance < -1 && key > t->right->data)
        return leftRotate(t);
  
    
    if (balance > 1 && key > t->left->data)
    {
        t->left = leftRotate(t->left);
        return rotateRight(t);
    }
  
    
    if (balance < -1 && key < t->right->data)
    {
        t->right = rotateRight(t->right);
        return leftRotate(t);
    }
  
   
    return t;
}
tnode* minValue(tnode* t){
  tnode* current = t;
  while(current -> left != NULL)
  current = current -> left;

  return current;
}
tnode* deleteTnode(tnode* root, int key){
  if(root == NULL){
    return root;
  }
  if(key < root -> data){
  root -> left = deleteTnode(root -> left, key);
}
else if(key > root -> data){
  root -> right = deleteTnode(root -> right, key);
}
else{
  if((root -> left == NULL) || (root -> right == NULL)){
    tnode* temp = root -> left?
                  root -> right:
                  root -> right;

    if(temp == NULL){
      temp = root;
      root = NULL;
    }
    else *root = *temp;

    delete(temp);
  }
  else{
    tnode* temp = minValue(root -> right);
    root -> data = temp -> data;
    root -> right = deleteTnode(root -> right, temp -> data);
  }
}
if(root == NULL)
return root;

root -> height = 1+ max(height(root -> left), height(root -> right));

int balance = getBalance(root);

if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rotateRight(root);
  
      
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rotateRight(root);
    }
  
      
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
  
    
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return leftRotate(root);
    }
  
    return root;
}
void preOrder(tnode* root){
  if(root != NULL){
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
  }
}
int main() {
  tnode* root = NULL;
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 60);
  root = insert(root, 70);
  root = insert(root, 80);
  root = insert(root, 90);
  preOrder(root);
  cout << endl;
  root = deleteTnode(root, 20);
  preOrder(root);
    cout << endl;
  std::cout << "Hello World!\n";
}
