#include "BSTNode.cpp"

class BST {

public:
  BSTNode* root;

  BST() {
    root = nullptr;
  }

  void insert(int value) {
    BSTNode *p , *previous;
    BSTNode* new_node = new BSTNode;
    new_node ->value = value;
    new_node ->left = nullptr;
    new_node ->right =nullptr;
    if(root == nullptr){
        root = new_node;
    }
    else{
        p = root;
        while(p!=nullptr){
            previous = p;
            if(p->value > new_node->value){
                p = p->left;
            }else{
                p = p->right;
            }
        }
        if(previous->value > new_node->value){
            previous->left = new_node;
        }else if(previous->value == new_node->value){
            return;
        }else{
            previous->right = new_node;
        }
    }
    
  }


  void remove(int value) {
    BSTNode* previos = nullptr;
    BSTNode* p = root;
    while(p!=nullptr && p->value != value){ //find node
        previos = p;
        if(value < p->value){
            p = p->left;
        }else{
            p = p->right;
        }
    }
    if(p == nullptr){ //no node
        return;
    }
    if(isLeaf(p)){ //leaf node
        if(p!=root){
            if(previos->left == p){
                previos->left = nullptr;
            }else{
                previos->right = nullptr;
            }
        }else{
            root = nullptr;
        }
        delete(p);
    }else if(p->left && p->right){ //2 children
        BSTNode* lmost = leftMost(p->right);
        int oldlmost = lmost->value;
        remove(lmost->value);
        p->value = oldlmost;
    }else{ //1 child
        if(p!= root){
            if(p == previos->left){
                previos->left = oneChild(p);
            }else{
                previos->right = oneChild(p);
            }
        }
        else{
            root = oneChild(p);
        }
        delete(p);
    }
  }

  int get_depth(int value) {
    BSTNode* previous,*p;
    int count = 0;
    if(root == nullptr){return -1;}
    else{
        p = root;
        
        while(p!=nullptr){
            if(p->value == value){
                return count;
            }
            else if(p->value>value){
                p = p->left;
                count += 1;
                continue;
            }else if(p->value < value){
                p = p->right;
                count += 1;
                continue;
            }
        }return -1;
    }
    
  }

  bool isLeaf(BSTNode* p){ //check leaf node
      return (p->left == nullptr && p->right == nullptr);
  }
  BSTNode* oneChild(BSTNode* p){ //get one child
      if(p->left != nullptr && p->right == nullptr){
          return p->left;
      }else if (p->left == nullptr && p->right != nullptr)
      {
          return p->right;
      }
      
  }
  BSTNode* leftMost(BSTNode* p){ //get leftmost
      while(p->left != nullptr){
          p = p->left;
      }
      return p;
  }


};