// add and remove from whereever you like [with limitions ofc][inseart from 0 to size][delete from 0 to size-1]
//the limitions automatically aplied if you didin't follow them the function do nothing
#include<iostream>
using namespace std;
#define MAXLIST 10

//ARRAY BASED
typedef struct{
    int entry[MAXLIST];//max 10 items
    int size;
}ListArr;
void createListArr(ListArr *pl);//init stack to remove the garbage
void pushListArr(int pos,int itm,ListArr *pl);
void popListArr(int pos,int *itm,ListArr *pl);
bool listArrEmpty(ListArr *pl);
bool listArrFull(ListArr*pl);
int listArrSize(ListArr *pl);
void clearlistArr(ListArr *pl);

//LIST BASED
typedef struct node{
    int entry;
    struct node *next;
}Node;
typedef struct list{//current and current position to make the loop shorter if possible[when you want to go furhter than last time in push or pop]
    Node *top,*current;
    int size,curpos;
}List;
void createList(List *pl);//init stack to remove the garbage
void pushList(int pos,int itm,List *pl);
void popList(int pos,int *itm,List *pl);
bool listEmpty(List *pl);
bool listFull(List*pl);
int listSize(List *pl);
void clearlist(List *pl);
int main(){
    //ARRAY BASED
    // ListArr list;
    // createListArr(&list);
    // pushListArr(0,1,&list);
    // pushListArr(1,2,&list);
    // pushListArr(1,3,&list);
    // pushListArr(0,4,&list);
    // pushListArr(2,5,&list);
    // pushListArr(5,6,&list);
    // pushListArr(4,7,&list);
    // pushListArr(3,8,&list);
    // pushListArr(7,9,&list);
    // pushListArr(9,10,&list);
    // int itm;
    // for(int i=0;i<12;++i){
    //     if(!listArrEmpty(&list)){
    //         popListArr(0,&itm,&list);
    //         cout<<itm<<endl;
    //     }
    // }

    //LIST BASED
    List listLS;
    createList(&listLS);
    pushList(0,1,&listLS);
    pushList(1,2,&listLS);
    pushList(1,3,&listLS);
    pushList(0,4,&listLS);
    pushList(2,5,&listLS);
    pushList(5,6,&listLS);
    pushList(4,7,&listLS);
    pushList(3,8,&listLS);
    pushList(7,9,&listLS);
    pushList(9,10,&listLS);
    pushList(1,123,&listLS);
    cout<<"size: "<<listSize(&listLS)<<endl;
    clearlist(&listLS);
    cout<<"size: "<<listSize(&listLS)<<endl;
    int itm;
    // popList(0,&itm,&listLS);
    for(int i =0;!listEmpty(&listLS);++i){
        popList(0,&itm,&listLS);
        cout<<itm<<endl;
    }
    return 0;
}
void createListArr(ListArr *pl){//init stack to remove the garbage
    pl->size=0;
}
void pushListArr(int pos,int itm,ListArr *pl){
    if (pos<0||pos>listArrSize(pl))return;
    for(int i=listArrSize(pl)-1;i>=pos;--i){pl->entry[i+1]=pl->entry[i];}
    pl->entry[pos]=itm;
    pl->size++;
}
void popListArr(int pos,int *itm,ListArr *pl){
    if (pos<0||pos>listArrSize(pl)-1)return;
    *itm=pl->entry[pos];
    for(int i = pos+1;i<=listArrSize(pl)-1;++i){
        pl->entry[i-1]=pl->entry[i];
    }
    pl->size--;
}
bool listArrEmpty(ListArr *pl){
    return !pl->size;
}
bool listArrFull(ListArr*pl){
    return pl->size==MAXLIST;
}
int listArrSize(ListArr *pl){
    return pl->size;
}
void clearlistArr(ListArr *pl){
    pl->size=0;
}

//LIST BASED
void createList(List *pl){//init stack to remove the garbage
    pl->top=NULL;
    pl->current=NULL;
    pl->size=0;
    pl->curpos=0;
}
void pushList(int pos,int itm,List *pl){
    //special case if you push at first position or if the list empty
    if (pos<0||pos>listSize(pl))return;
    Node *node=(Node*)malloc(sizeof(Node));
    node->entry=itm;
    node->next=NULL;
    if(pos==0){
        node->next=pl->top;
        pl->top=node;
        pl->current=node;
        pl->curpos=0;
    }
    else{
        if(pos<=pl->curpos){
            pl->curpos=0;
            pl->current=pl->top;
        }
        for(;pl->curpos < pos-1;++pl->curpos ){
            pl->current=pl->current->next;
        }
        node->next=pl->current->next;
        pl->current->next=node;
        
    }
    pl->size++;
}
void popList(int pos,int *itm,List *pl){
    if (pos<0||pos>listSize(pl)-1)return;
    if(pos==0){//special case with pos==0
        pl->current=pl->top;
        pl->top=pl->top->next;
        *itm=pl->current->entry;
        free(pl->current);
        pl->curpos=0;
        pl->current=pl->top;
    }
    else{
        if(pos<= pl->curpos){
            pl->curpos=0;
            pl->current=pl->top;
        }
        for(;pl->curpos < pos-1;++pl->curpos){
            pl->current=pl->current->next;
        }
        Node *temp=pl->current->next;//the one i want delete
        *itm=temp->entry;
        pl->current->next=temp->next;
        free(temp);
    }
    pl->size--;
}
bool listEmpty(List *pl){
    return !pl->top;
}
bool listFull(List*pl){
    return 0;
}
int listSize(List *pl){
    return pl->size;
}
void clearlist(List *pl){
    Node*pn=pl->top;
    while(pn){
        pn=pn->next;
        free(pl->top);
        pl->top=pn;
    }
    pl->current=NULL;
    pl->size=0;
    pl->curpos=0;
}