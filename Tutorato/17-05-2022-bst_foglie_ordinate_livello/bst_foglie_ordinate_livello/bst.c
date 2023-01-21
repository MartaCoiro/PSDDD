#include <stdio.h>
#include "item.h"
#include "bst.h"
#include "queue.h"

struct node{
    Item item;
    struct node *left;
    struct node *right;
};

BST newBST(){
    return NULL;
}

int isEmptyBST(BST bst){
    if(bst==NULL)
        return 1;
    return 0;
}

Item getItem(BST b){
      if(isEmptyBST(b))
        return NULL;
    return b->item;
}

BST getLeft(BST b){
    if(isEmptyBST(b))
        return NULL;
    return b->left;
}

BST getRight(BST b){
    if(isEmptyBST(b))
        return NULL;
    return b->right;
}

void preOrder(BST b){
    if(!isEmptyBST(b)){
        outputItem(b->item);
        preOrder(b->left);
        preOrder(b->right);
    }
}

void postOrder(BST b){
    if(!isEmptyBST(b)){
        postOrder(b->left);
        postOrder(b->right);
        outputItem(b->item);
    }
}

void inOrder(BST b){
    if(!isEmptyBST(b)){
        inOrder(b->left);
        outputItem(b->item);
        inOrder(b->right);
    }
}

int is_leaf(BST b){
  return b->right == NULL && b->left == NULL;
}

Item search(BST b, Item item){
  if(isEmptyBST(b))
    return NULL;
  int temp = cmpItem(item,b->item);

  if(temp == 0)
    return b->item;
  else if(temp < 0)
    return search(b->left,item);
  else
    return search(b->right,item);
}

Item min(BST b){
  if(isEmptyBST(b))
    return NULL;
  while(b->left != NULL)
    b = b->left;
  return b->item;
}

Item max(BST b){
  if(isEmptyBST(b))
    return NULL;
  while(b->right != NULL)
    b = b->right;
  return b->item;
}

void insertBST(BST *b, Item item){
  if(isEmptyBST(*b)){
    *b = malloc(sizeof(struct node));
    (*b)->item = item;
    (*b)->left = NULL;
    (*b)->right = NULL;
    return;
  }
  int temp = cmpItem(item,(*b)->item);
  if(temp < 0)
    insertBST(&((*b)->left),item);
  else
    insertBST(&((*b)->right),item);
}

int _my_abs(int x){
  int mask = x >> sizeof(x) * 8 - 1;
  return (x ^ mask) - mask;
}

int _is_k_balanced(BST b, int *depth, u_int32_t k){
  if(isEmptyBST(b))
    return 1;
  
  int depth_l = 0;
  int depth_r = 0;

  int res_l = _is_k_balanced(b->left, &depth_l, k);
  int res_r = _is_k_balanced(b->right, &depth_r, k);
  
  if(!res_l || !res_r)
    return 0; //Is not K balanced
  
  int diff = depth_l - depth_r;
  // if( _my_abs(diff) > k) //ABS
  //   return 0;

  if(abs(diff) > k)
    return 0;

  *depth = depth_l > depth_r ? depth_l : depth_r;
  (*depth)++; //Depth is children depth + 1
  return 1;
}

int is_k_balanced(BST b, u_int32_t k){
  int depth;
  return _is_k_balanced(b,&depth,k);
}

void print_leaf_ordered(BST b){
  Queue q = newQueue();
  enqueue(q,b);
  while(!isEmptyQueue(q)){
    BST cur = (BST) dequeue(q);

    if(is_leaf(cur)){
      outputItem(cur->item);
      printf(" ");
    }

    if(cur->left != NULL) 
      enqueue(q,cur->left);
    if(cur->right != NULL) 
      enqueue(q,cur->right);
  }
  fflush(stdout);
}