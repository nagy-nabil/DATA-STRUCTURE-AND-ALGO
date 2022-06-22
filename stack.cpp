//StackArr means Array based implementation, only Satck means with linked list implementation
#include<iostream>
using namespace std;
#define MAXSTACKARR 10
typedef struct 
{
    int top;//know position in the stack,,where to push (empty position)
    int entry[MAXSTACKARR];//stack can handle 10 items
}StackArr;//stack with arrays imp

typedef struct node
{
    int entry;
    struct node *next;
    
}Node;
typedef struct stack
{
    Node *top;
    int size;
}Stack;

//array based
void createStackArr(StackArr *ps);//init stack to remove the garbage
void pushStackArr(int itm,StackArr *ps);
void popStackArr(int *itm,StackArr *ps);
bool stackArrEmpty(StackArr *ps);
bool stackArrFull(StackArr*ps);
int stackArrSize(StackArr *ps);
void clearStackArr(StackArr *ps);

//linked list based
void createStack(Stack *ps);//init stack to remove the garbage
void pushStack(int itm,Stack *ps);
void popStack(int *itm,Stack *ps);
bool stackEmpty(Stack *ps);
bool stackFull(Stack*ps);
int stackSize(Stack *ps);
void clearStack(Stack *ps);

int main(){
    //last in first out
    StackArr stack;//create the stack
    createStackArr(&stack);
    for(int i=0;i<12;++i){
        if (!stackArrFull(&stack)) pushStackArr(i,&stack);
        else cout<<"full\n";
    }
    cout<<"size: "<<stackArrSize(&stack)<<endl;
    while(!stackArrEmpty(&stack))
    {
        int itm;
        popStackArr(&itm,&stack);
        cout<<itm<<endl;
    }
    clearStackArr(&stack);
    cout<<"size: "<<stackArrSize(&stack)<<endl;
    /* ********************************************************************************************************************************** */
    cout<<"LINKED LIST BASED\n";
    Stack stackLS;
    createStack(&stackLS);
    for(int i=0;i<12;++i){
        if (!stackFull(&stackLS)) pushStack(i,&stackLS);
        else cout<<"full\n";
    }
    cout<<"size: "<<stackSize(&stackLS)<<endl;
    while(!stackEmpty(&stackLS))
    {
        int itm;
        popStack(&itm,&stackLS);
        cout<<itm<<endl;
    }
    clearStack(&stackLS);
    cout<<"size: "<<stackSize(&stackLS)<<endl;
    return 0;
}

//arr based
void createStackArr(StackArr *ps){
    ps->top=0;
}
void pushStackArr(int itm,StackArr *ps){
    ps->entry[ps->top]=itm;
    ps->top++;
}
void popStackArr(int *itm,StackArr *ps){
    *itm=ps->entry[--ps->top];
}
bool stackArrEmpty(StackArr *ps){
    return !ps->top;
}
bool stackArrFull(StackArr*ps){
    return ps->top>=MAXSTACKARR;
}
int stackArrSize(StackArr *ps){
    return ps->top;
}
void clearStackArr(StackArr *ps){//it's waste of memory but to keep the logic 
    ps->top=0;
}

//linked list based
void createStack(Stack *ps){//init stack to remove the garbage
    ps->top=NULL;
    ps->size=0;
}
void pushStack(int itm,Stack *ps){
    Node*pn=(Node* )malloc(sizeof(Node));
    pn->entry=itm;
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
}
void popStack(int *itm,Stack *ps){
    *itm=ps->top->entry;
    Node*temp=ps->top;
    ps->top=ps->top->next;
    free(temp);
    ps->size--;
}
bool stackEmpty(Stack *ps){
    return !ps->top;
}
bool stackFull(Stack*ps){
    return false;
}
int stackSize(Stack *ps){
    return ps->size;
}
void clearStack(Stack *ps){
    Node*pn=ps->top;
    while(pn){
        pn=pn->next;
        free(ps->top);
        ps->top=pn;
    }
    ps->size=0;
}