#ifndef _VATTU_
#define _VATTU_
#include"Struct.h"

using namespace std  ;


BSTNode* creatBSTNode (VATTU vt ) {
      BSTNode* node = new BSTNode ;
      node->vt = vt ;
      node->left = NULL ;
      node->right = NULL ;
      return node ;
}
void insertBSTNode (BSTNode* &root , VATTU vt) {
      if (root != NULL) {
          if (strcmp(root->vt.MAVT,vt.MAVT)==0) {
              return ;
          } else if (strcmp(root->vt.MAVT,vt.MAVT)<0) {
              insertBSTNode(root->right, vt) ;
          } else if (strcmp(root->vt.MAVT,vt.MAVT)>0) {
              insertBSTNode(root->left, vt) ;
          }
      } else {
          root = new BSTNode ;
          root->vt = vt ;
          root->left = NULL ;
          root->right = NULL ;
          return ;
      }
}
void maxRight (BSTNode* &root , BSTNode* &p) {
     if (p->right != NULL) {
           maxRight (root, p->right) ;
     } else {
         root->vt = p->vt ;
         root = p ;
         p = p ->left ;
     }
}
void deleteBSTNode (BSTNode* &root , char id[10]) {
         if (root != NULL) {
               if (strcmp(root->vt.MAVT,id)<0) {
                   deleteBSTNode(root->right, id) ;
               } else if (strcmp(root->vt.MAVT,id)>0) {
                   deleteBSTNode(root->left, id) ;
               } else {
                   BSTNode*p = root ;
                   if (!root->left) {
                        root = root->right ;
                   } else if (!root->right) {
                       root = root->left ;
                   } else {
                       maxRight(p , root->left) ;
                   }
                   delete p ;
               }
         } else {
             return ;
         }
}
BSTNode* findVATTU(BSTNode* root, char id[10])  {
    if(root == NULL)
        return NULL;
    else if(strcmp(id,root->vt.MAVT)<0) {
        return findVATTU(root->left, id);
    }
    else if(strcmp(id,root->vt.MAVT)>0) {
        return findVATTU(root->right, id);
    }
    else
        return root;
}
void fixVATTU (BSTNode* &Node,VATTU vt ) {
    Node->vt.TENVT = vt.TENVT;
    Node->vt.sl =vt.sl;
    Node->vt.DVT =vt.DVT;
}

#endif
