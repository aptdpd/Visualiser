#include<iostream>
#include<math.h>
#include<graphics.h>
#include<queue>
#include<deque>
#include<vector>
#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

int gdriver=DETECT,gmode;


int var=0;

//class for max heap
class MaxHeap {
    int capacity;
    int sz;
    public:
    int *arr;
    int *x1,*y1;
    MaxHeap(int c){
    x1=new int[c];
    y1=new int[c];
    arr=new int[c];
    capacity=c;
    sz=0;
    for(int i=0;i<c;i++)
    {
        arr[i]=x1[i]=y1[i]=0;
    }
    }

    int parent(int i){
    return (i-1)/2;
    }

    int left(int i){
    return 2*i+1;
    }

    int right(int i){
    return 2*i+2;
    }

    int getMax() {
    return arr[0];
    }

    void insrt(int a) {
        if(sz==capacity) {
            cout<<"Overflow\n";
            return;
        }
        sz++;
        int i=sz-1;
        arr[i]=a;

        while( i>0 && (int)arr[parent(i)] < (int)arr[i] ) {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }

    int extractMax(){
    if(sz==0)return 0;
    sz--;
    int r=(int)arr[0];
    arr[0]=arr[sz];
    heapify(0);
    return r;
    }

    void heapify(int i) {
    int lrg=i;
    int l=left(i);
    int r=right(i);
    if(l<sz && (int)arr[l]>(int)arr[lrg])
        lrg=l;
    if(r<sz && (int)arr[r]>(int)arr[lrg])
        lrg=r;
    if(lrg!=i){
        swap(arr[lrg],arr[i]);
        heapify(lrg);
    }
    }

    void disp(){
    for(int i=0;i<sz;i++)
        cout<<arr[i]<<" ";
    }
};


// Class for BST node
class node {

    int data;
    node *left;
    node *right;
    bool thread;

    public:

        int x1,y1;

    node(){
        x1=0;
        y1=0;
        left=NULL;
        right=NULL;
        thread=false;
    }


    void hasThread(){
        thread=true;
    }

    bool isThread(){
        return thread;
    }

    void assgn(int a) {
        data=a;
    }
    int geta(){
        return data;
    }

    node *lft(){
        return left;
    }
    void l1(node *l){
        left=l;
    }

    void l2(node *r){
        right=r;
    }

    node *rt(){
        return right;
    }

};



//class for AVL nodes
class AVL {

    int data;
    AVL *left;
    AVL *right;
    int height;

    public:

        int x1,y1;

    AVL(){
        x1=0;
        y1=0;
        left=NULL;
        right=NULL;
        height=1;
    }

    int ht() {
        return height;
    }

    void setH(int a){
        height=a;
    }

    void assgn(int a) {
        data=a;
    }

    int geta(){
        return data;
    }

    AVL *lft(){
        return left;
    }

    void l1(AVL *l){
        left=l;
    }

    void l2(AVL *r){
        right=r;
    }

    AVL *rt(){
        return right;
    }

};



//   BST functions ////////////////////////////////

node *insrt( node *s ,int v ) {

if(s==NULL){

node *temp=new node;
temp->assgn(v);
s=temp;
return s;

}

else {

if(v< s->geta())
s->l1(insrt(s->lft(),v));

else
s->l2(insrt(s->rt(),v));

}
return s;
}

void bfs(node *root) {

deque<node *>mv;
mv.push_back(root);

while( !mv.empty() ) {

    node *e=mv.front();
   // cout<<e->geta()<<" ";
        int intToConvert =e->geta();
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,470,intAsString);
        var+=60;
    if( e->lft()!=NULL )
    mv.push_back(e->lft());
    if( e->rt()!=NULL )
    mv.push_back(e->rt());

    mv.pop_front();
}

}




void preorder(node *s) {

if(s!=NULL){

        int intToConvert =s->geta();
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,530,intAsString);
        var+=60;

preorder(s->lft());
preorder(s->rt());
}
return;
}




void inorder(node *s) {

if(s!=NULL){
inorder(s->lft());

        int intToConvert =s->geta();
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,570,intAsString);
        var+=60;

inorder(s->rt());
}
return;

}




void postorder(node *s) {

if(s!=NULL){

    postorder(s->lft());
    postorder(s->rt());
        int intToConvert =s->geta();
       // cout<<s->geta()<<" ";
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,630,intAsString);
        var+=60;
}
return;
}




// AVL functions/////////////////////////////////////

AVL *LL(AVL *s) {

AVL *temp=s->lft();
s->l1(temp->rt());
temp->l2(s);

if( s->lft() && s->rt() )
    s->setH( max(s->lft()->ht(),s->rt()->ht()) + 1 );
else if( s->lft() )
    s->setH(s->lft()->ht()+1);
else if( s->rt() )
    s->setH(s->rt()->ht()+1);
else
    s->setH(1);

if( temp->lft() && temp->rt() )
    temp->setH( max(temp->lft()->ht(),temp->rt()->ht())+1 );
else if( temp->lft() )
    temp->setH(temp->lft()->ht()+1);
else if( temp->rt() )
    temp->setH(temp->rt()->ht()+1);
else
    temp->setH(1);

return temp;

}



AVL *RR(AVL *s) {

AVL *temp=s->rt();
s->l2(temp->lft());
temp->l1(s);


if( s->lft() && s->rt() )
    s->setH( max(s->lft()->ht(),s->rt()->ht()) + 1 );

else if( s->lft() )
    s->setH(s->lft()->ht()+1);

else if( s->rt() )
    s->setH(s->rt()->ht()+1);

else
    s->setH(1);


if( temp->lft() && temp->rt() )
    temp->setH( max(temp->lft()->ht(),temp->rt()->ht())+1 );

else if( temp->lft() )
    temp->setH(temp->lft()->ht()+1);

else if( temp->rt() )
    temp->setH(temp->rt()->ht()+1);

else
    temp->setH(1);


return temp;

}



AVL *insrt( AVL *s ,int v ) {

if(s==NULL){

    AVL *temp=new AVL;
    temp->assgn(v);
    s=temp;
    return s;

}

else {

    if( v< s->geta() )
        s->l1(insrt(s->lft(),v));

    else
        s->l2(insrt(s->rt(),v));
}

if( s->lft() && s->rt() )
    s->setH( max(s->lft()->ht(),s->rt()->ht())+1 );

else if( s->lft() )
    s->setH(s->lft()->ht()+1);

else
    s->setH(s->rt()->ht()+1);



int bal=0;

if( s->lft() && s->rt() )
    bal=s->lft()->ht() - s->rt()->ht();

else if( s->lft() )
    bal=s->lft()->ht();

else
    bal=-s->rt()->ht();

    // LL
    if ( s->lft() && bal > 1 && v < s->lft()->geta() )
        return LL(s);

    // LR
    if ( s->lft() && bal > 1 && v > s->lft()->geta() )
    {
        s->l1(RR(s->lft()));
       return LL(s);
    }

    // RL
    if ( s->rt() && bal < -1 && v < s->rt()->geta() )
    {
        s->l2(LL(s->rt()));
        return RR(s);
    }

    // RR
    if ( s->rt() && bal < -1 && v > s->rt()->geta() )
        return RR(s);

    return s;
}


void bfsAVL(AVL *root) {

deque<AVL *>mv;
mv.push_back(root);
while( !mv.empty() ) {
    AVL *e=mv.front();

    int intToConvert =e->geta();
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,470,intAsString);
        var+=60;

    if( e->lft()!=NULL )
    mv.push_back(e->lft());

    if( e->rt()!=NULL )
    mv.push_back(e->rt());

    mv.pop_front();
}

}


void preorderAVL(AVL *s) {

if(s!=NULL){

        int intToConvert =s->geta();
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,530,intAsString);
        var+=60;

preorderAVL(s->lft());
preorderAVL(s->rt());
}
return;
}




void inorderAVL(AVL *s) {

if(s!=NULL){
inorderAVL(s->lft());

        int intToConvert =s->geta();
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,570,intAsString);
        var+=60;

inorderAVL(s->rt());
}
return;

}




void postorderAVL(AVL *s) {

if(s!=NULL){

    postorderAVL(s->lft());
    postorderAVL(s->rt());
        int intToConvert =s->geta();
       // cout<<s->geta()<<" ";
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(50+var,630,intAsString);
        var+=60;
}
return;
}

// Heap graphics

void drawtree3(MaxHeap *myheap,int x,int y, int index)
{

    int parent= (index-1)/2;
    setcolor(RED);
    circle(x,y,30);

    int intToConvert =myheap->arr[index];
    char intAsString[10]; //int will be stored here as a string
    itoa (intToConvert,intAsString,10);
    //cout << intAsString << endl;
    int len=strlen(intAsString)/2;
    outtextxy(x-len*10, y-8,intAsString);
    setfillstyle(1,GREEN);
    floodfill(x-10,y-10,RED);
    setcolor(GREEN);
  //  settextstyle( BOLD_FONT,HORIZ_DIR,3);
    if(parent!=index)
        line(x,y-10,myheap->x1[parent],myheap->y1[parent]+10);
}

void processtree3(MaxHeap *myheap,int v)
{
    int cntr=0;
    int yoffset=60;
    int windowssizeX=getmaxx();
    //vector< node* > loc_record;
    while(cntr<v)
    {
        //cout<<myheap->arr[cntr]<<" ";
        if(myheap->arr[cntr]!=0 )
        {
            int level= log2(cntr+1);
            int xoffset=windowssizeX/(pow(2,level)+1);
            int x=(cntr+2-pow(2,level)) * ( xoffset );
            int y=(level+1)*yoffset;
            myheap->x1[cntr]=x;
            myheap->y1[cntr]=y;
            drawtree3(myheap,x,y,cntr);
        }
        cntr++;
    }
}

//  AVL graphics  //////////////////////////////
void drawtree2(AVL *root,int x,int y, int index, vector<AVL*> loc_record)
{


    AVL *parent= loc_record[index];
    setcolor(RED);
    circle(x,y,30);

    int intToConvert =root->geta();;
    char intAsString[10]; //int will be stored here as a string
    itoa (intToConvert,intAsString,10);
    int len=strlen(intAsString)/2;
    outtextxy(x-len*10, y-8,intAsString);
    setfillstyle(1,GREEN);
    floodfill(x-10,y-10,RED);
    setcolor(GREEN);
  //  settextstyle( BOLD_FONT,HORIZ_DIR,3);
    if(parent!=NULL)
        line(x,y-10,parent->x1,parent->y1+10);

}



void processtree2(AVL *root,int v)
{

    int cntr=1;
    int yoffset=60;
    int windowssizeX=getmaxx();

    vector< AVL* > loc_record;
    queue< AVL* > record;
    record.push(root);

    while( !record.empty() && cntr<v)
    {
        loc_record.push_back(root);

        if(record.front()!=NULL )
        {
            root=record.front();
            record.pop();
            int level= log2(cntr);
            int xoffset=windowssizeX/(pow(2,level)+1);
            int x=(cntr-pow(2,level)+1) * ( xoffset );
            int y=(level+1)*yoffset;
            root->x1=x;
            root->y1=y;
            if(root->lft()!=NULL)
                record.push(root->lft());
            else
                record.push(NULL);

            if(root->rt()!=NULL)
                record.push(root->rt());
            else
                record.push(NULL);
            drawtree2(root,x,y,cntr/2,loc_record);
        }
        else
        {
            record.pop();
            record.push(NULL);
            record.push(NULL);
        }
        cntr++;
    }
}



//BST graphics
void drawtree(node *root,int x,int y, int index, vector<node*> loc_record)
{

    node *parent= loc_record[index];
    setcolor(RED);
    circle(x,y,30);

    int intToConvert =root->geta();;
    char intAsString[10]; //int will be stored here as a string
    itoa (intToConvert,intAsString,10);
    //cout << intAsString << endl;
    int len=strlen(intAsString)/2;
    outtextxy(x-len*10, y-8,intAsString);
    setfillstyle(1,GREEN);
    floodfill(x-10,y-10,RED);
    setcolor(GREEN);
  //  settextstyle( BOLD_FONT,HORIZ_DIR,3);
    if(parent!=NULL)
        line(x,y-10,parent->x1,parent->y1+10);
}



void processtree(node *root,int v)
{
    int cntr=1;
    int yoffset=60;
    int windowssizeX=getmaxx();
    vector< node* > loc_record;
    queue< node* > record;
    record.push(root);

    while( !record.empty() && cntr<v)
    {
        loc_record.push_back(root);
       // cout<<record.front()<<" ";
        if(record.front()!=NULL )
        {
            root=record.front();
            record.pop();
            int level= log2(cntr);
            int xoffset=windowssizeX/(pow(2,level)+1);
            int x=(cntr-pow(2,level)+1) * ( xoffset );
            int y=(level+1)*yoffset;
            root->x1=x;
            root->y1=y;
            if(root->lft()!=NULL)
                record.push(root->lft());
            else
                record.push(NULL);

            if(root->rt()!=NULL)
                record.push(root->rt());
            else
                record.push(NULL);
            drawtree(root,x,y,cntr/2,loc_record);
        }
        else
        {
            record.pop();
            record.push(NULL);
            record.push(NULL);
        }
        cntr++;
    }
}



main(){

int ch,k;
A:
closegraph();
//initgraph(&gdriver,&gmode,"");
initwindow(1000, 700);
setcolor(RED);


settextstyle( SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(50,50,"Enter your choice:-");
setcolor(GREEN);

outtextxy(50,70,"1 : Make a Binary Search Tree");

outtextxy(50,90,"2 : Make an AVL Tree");

outtextxy(50,110,"3 : Make an MAX HEAP Tree representation");

//outtextxy(50,110,"3: Create a Heap");

cin>>ch;

switch(ch) {

case 1:
        {

        //closegraph();
        //initgraph(&gdriver,&gmode,"");

        cleardevice();

        int n,v;

        setcolor(GREEN);
        outtextxy(0,0,"Enter the number of elements to insert  :-");

        cin>>n;

        int intToConvert =n;
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(0,20,intAsString);

        node *root=NULL;
        int x=20;
        for(int i=0;i<n;i++) {

        cin>>v;
        intToConvert=v;
        intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(x,40,intAsString);
        x+=30;
        if(root==NULL)
        root=insrt(root,v);
        else
        insrt(root,v);
        processtree(root,(int)pow(2,n));

        }

        var=0;
        outtextxy(50,450,"Level order traversal:-");
        bfs(root);

        var=0;
        outtextxy(50,500,"Pre order traversal:-");
        preorder(root);

        var=0;
        outtextxy(50,550,"Inorder traversal:-");
        inorder(root);

        var=0;
        outtextxy(50,600,"Post order traversal:-");
        postorder(root);


        outtextxy(50,680,"Press Esc to go back to main menu");

        int v1=getch();
        if(v1==27)
            goto A;
        else
        break;

        }

case 2:
    {
        //closegraph();
        //initgraph(&gdriver,&gmode,"");

        cleardevice();
        int n,v;
        setcolor(GREEN);
        outtextxy(0,0,"Enter the number of elements to insert  :-");

        cin>>n;

        int intToConvert =n;
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(0,20,intAsString);

        AVL *root=NULL;
        int x=20;
        for(int i=0;i<n;i++){

            cin>>v;
            intToConvert=v;
            intAsString[10]; //int will be stored here as a string
            itoa (intToConvert,intAsString,10);
            outtextxy(x,40,intAsString);
            x+=30;

            root=insrt(root,v);
            //closegraph();
            //initgraph(&gdriver,&gmode,"");
            cleardevice();
            processtree2(root,(int)pow(2,n));

        }


        var=0;
        outtextxy(50,450,"Level order traversal:-");
        bfsAVL(root);

        var=0;
        outtextxy(50,500,"Pre order traversal:-");
        preorderAVL(root);

        var=0;
        outtextxy(50,550,"Inorder traversal:-");
        inorderAVL(root);

        var=0;
        outtextxy(50,600,"Post order traversal:-");
        postorderAVL(root);

        outtextxy(50,680,"Press Esc to go back to main menu");

        int v1=getch();

        if(v1==27)
            goto A;
        else
        break;

    }

case 3:
    {

        cleardevice();
        int n,v;
        setcolor(GREEN);
        outtextxy(0,0,"Enter the number of elements to insert  :-");

        cin>>n;

        int intToConvert =n;
        char intAsString[10]; //int will be stored here as a string
        itoa (intToConvert,intAsString,10);
        outtextxy(0,20,intAsString);

        MaxHeap myheap(n);

        int x=20;
        for(int i=0;i<n;i++){

            cin>>v;
            intToConvert=v;
            intAsString[10]; //int will be stored here as a string
            itoa (intToConvert,intAsString,10);
            outtextxy(x,40,intAsString);
            x+=30;

            myheap.insrt(v);
            //closegraph();
            //initgraph(&gdriver,&gmode,"");
            cleardevice();
            processtree3(&myheap,n);

        }

         outtextxy(50,680,"Press Esc to go back to main menu");

        int v1=getch();

        if(v1==27)
            goto A;
        else
        break;

    }

default:break;
}
cleardevice();

setcolor(GREEN);
outtextxy(50,50,"Press any key to exit");

while(!kbhit()) {

}

}
