#include<iostream>
using namespace std;
typedef struct node{
    int e;
    node *left, *right; //unlike the list we need left and right pointers not just next 
}Node;
typedef struct tree{
    Node *root;
    int size , depth;
}Tree;
void createTree(Tree *pt);
int treeEmpty(Tree *pt);
int treeFull(Tree *pt);
void inorder(Tree*pt, void (*fun)(int));
void inorderRec(Node**pt,void(*fun)(int));
void clearTreeRec(Node *pt);
void clearTree(Tree *pt);
void insertTreeRec(Node **pn,int *pe,int *d);
void insertTree(Tree *pt,int *pe);
void display(int i);
int treeSize(Tree*pt);
int treeDepth(Tree*pt);
void insertITRV(Tree *pt,int *e);
int findItemTreeRec(Node **pn,int *pe);
int findItemTree(Tree *pt,int *pe);
int findItemITRV(Tree *pt,int e);
int deleteItemTree(Tree *pt,int *pe);
void deleteNode(Node **pn);
int main(){
    Tree tree;
    createTree(&tree);
    int e=32;
    insertITRV(&tree,&e);
    insertTree(&tree,&e);
    e=465;
    insertTree(&tree,&e);
    e=6345;
    insertTree(&tree,&e);
    e=3;
    insertTree(&tree,&e);
    e=65;
    insertTree(&tree,&e);
    e=0;
    insertTree(&tree,&e);
    e=571;
    insertTree(&tree,&e);
    inorder(&tree,&display);
    cout<<"\n";
    cout<<"depth: "<<treeDepth(&tree)<<endl<<"size: "<<treeSize(&tree)<<endl;
    // clearTree(&tree);
    // inorder(&tree,display);
    // cout<<"depth: "<<treeDepth(&tree)<<endl<<"size: "<<treeSize(&tree)<<endl;
    // if(findItemTree(&tree,&e)){
    //     cout<<"exist\n";
    // }else cout<<"NOTFOUND\n";
    // e=5;
    // if(findItemTree(&tree,&e)){
    //     cout<<"exist\n";
    // }else cout<<"NOTFOUND\n";
    // if(findItemITRV(&tree,2)){
    //     cout<<"exist\n";
    // }else cout<<"NOTFOUND\n";
    // if(findItemITRV(&tree,8943)){
    //     cout<<"exist\n";
    // }else cout<<"NOTFOUND\n";
    e=465;
    deleteItemTree(&tree,&e);
    inorder(&tree,display);
    cout<<"\n";
    e=123;
    insertITRV(&tree,&e);
    inorder(&tree,display);
    cout<<"\n";
    e=32;
    deleteItemTree(&tree,&e);
    inorder(&tree,display);
    return 0;
}
void createTree(Tree *pt){
    pt->depth=0;
    pt->size=0;
    pt->root=NULL;
}
int treeEmpty(Tree *pt){
    return !(pt->root);
}
int treeFull(Tree *pt){
    return 0;
}
//only for the root
//it takes pointer to node and the root is pointer to node
void inorderRec(Node**pt,void(*fun)(int)){//LVR, so start bulid the stack from the left
    if(*pt){//pt not null
    inorderRec(&(*pt)->left,fun);
    (*fun)((*pt)->e);
    inorderRec(&(*pt)->right,fun);
    }
}
void inorder(Tree*pt, void (*fun)(int)){//LVR, recersive so we can imagine stack hold the values till we find flag to stop us the flag here is pointer == null
//this function take struct as argument so it's easier to build another function take the root only and do the recursive jop
    inorderRec(&pt->root,fun);
}
void clearTreeRec(Node **pt){
    if(*pt){
        clearTreeRec(&(*pt)->left);
        clearTreeRec(&(*pt)->right);
        free(*pt);
        *pt=NULL;
    }
}
void clearTree(Tree *pt){
    clearTreeRec(&pt->root);
    pt->depth=0;
    pt->size=0;
}
void insertTreeRec(Node **pn,int *pe,int *pdepth){
    if(!*pn){
        *pn=(Node*)malloc(sizeof(Node));
        (*pn)->e=*pe;
        (*pn)->left=NULL;
        (*pn)->right=NULL;
    }
    else if(*pe < (*pn)->e )insertTreeRec( &(*pn)->left , pe , pdepth );
    else insertTreeRec(&(*pn)->right,pe,pdepth);
    ++(*pdepth);
}
void insertTree(Tree *pt,int *pe){
    int d=0;
    insertTreeRec(&(pt->root),pe,&d);
    if (pt->depth < d)pt->depth=d;
    pt->size++;
}
void display(int i ){
    cout<<i<<"\t";
}
int treeSize(Tree*pt){
    return pt->size;
}
int treeDepth(Tree*pt){
    return pt->depth;
}
void insertITRV(Tree *pt,int *e){
    int d=1;
    Node *pn=(Node *)malloc(sizeof(Node)), *cur=pt->root, *pre=NULL; //current will stop when it reach null so i need pre to keep track and don't lose my posotion
    pn->e=*e;
    pn->right=NULL;
    pn->left=NULL;
    if(!pt->root){//if the tre is empty
        pt->root=pn;
    }
    else {
        while(cur){
            pre=cur;
            if(*e < cur->e){
                cur=cur->left;
            }
            else cur=cur->right;
            d++;//with every loop i go one level so we see if we go more levels than we have or not with that variable
        }
        //we need to use the if again cause the cur moved to the left or right but the pre didn't so the pre don't know where to save the new node
        if(*e < pre->e){
                pre->left=pn;
            }
            else pre->right=pn;
    }
    if (pt->depth < d)pt->depth=d; // to know if we need to increase the depth or no
    pt->size++;
}
int findItemTreeRec(Node **pn,int *pe){
    if(!*pn){//if i reach null means i got to the end of the tree and didn't find the item i want
        return 0;
    }
    else if((*pn)->e == *pe){//i found the item
        return 1; //for the seek of the code
        // but the tree should be ordered in respect to key and the find should return whole set of data, now the function only till us if the data exist or not
    }
    else if(*pe < (*pn)->e){//left
        findItemTreeRec(&(*pn)->left,pe);
    }
    else findItemTreeRec(&(*pn)->right,pe);
}
int findItemTree(Tree *pt,int *pe){
    return findItemTreeRec(& pt->root,pe);
}
int findItemITRV(Tree *pt,int e){
    Node *temp = pt->root;
    while(temp){
        if(temp->e==e)return 1;
        else if(e < temp->e) temp=temp->left;
        else temp=temp->right;
    }
    return 0;
}
int deleteItemTree(Tree *pt,int *pe){
    //first should search for the item 
    Node *curr=pt->root , *pre=NULL;
    while(curr){
        if(curr->e == *pe)break;
        pre=curr;
        if( *pe < curr->e)curr=curr->left;
        else curr=curr->right;
    }
    if(curr){//to not give error if the tree is empty or not found
        //DO THE DELETE
        if(!pre){//deleting the root
            // cout<<&pt->root<<endl<<pt->root;
            deleteNode(&pt->root);
        }
        else if(*pe < pre->e){
            deleteNode(&pre->left);
        }
        else deleteNode(&pre->right);
    }
    else return 0;
    return 1;
}
void deleteNode(Node **pn){
    Node *temp=*pn, *r=NULL;
    if(!(*pn)->left){//fir case on'y right subtree
        *pn= (*pn)->right;
    }
    else if(!(*pn)->right){//only left
        *pn=(*pn)->left;
    }else{//third case there's left and right subtree
        temp=temp->left;
        if(!temp->right){//if the left subtree doesn't have right at all (special case)
            (*pn)->e=temp->e;
            (*pn)->left=temp->left;
        }
        else{
            do{
                r=temp;
                temp=temp->right;
            }while(temp->right);//temp holding most right , r holding its parent
            (*pn)->e=temp->e;
            r->right=temp->left;
        }
    }
    free(temp);
}