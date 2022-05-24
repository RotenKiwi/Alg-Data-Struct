#include<iostream>
using namespace std;

struct node{
int data;
struct node *left,*right;};

class tree{
node *root,*par,*cur;
public:
node *create();
void insert();
void longestpath();
int height(node* n);
void traversal();
void preorder(node* n);
void inorder(node* n);
void postorder(node* n);
void smallest();
void greatest();
void search();
void swapper();
// void swap(node* n);
void swpre(node* n);
void swin(node* n);
void swpost(node* n);};

node *tree::create(){
int val;
node *temp=new(struct node);
cin>>val;
temp->data=val;
temp->left=NULL;
temp->right=NULL;
return temp;}

void tree::insert()
{
cout<<"Enter the data of the node: ";
node *temp=create();
cout<<"Node created!"<<endl;
if(root==NULL)
{root=par=cur=temp;}
else
Code:

{
par=cur=root;
while(cur!=NULL)
{
if(temp->data < cur->data)
{
par=cur;
cur=cur->left;
}
else
{
par=cur;
cur=cur->right;
}
}
if(temp->data < par->data)
{par->left=temp;}
else
{par->right=temp;}
}
}
void tree::longestpath()
{
if(root!=NULL)
{cout<<"No. of nodes in the longest path from root:"<<height(root)+1<<endl;}
else
{cout<<"Tree is empty!"<<endl;}
}
int tree::height(node* n)
{
if(n==NULL)
{return -1;}
else
{
int lht=height(n->left);
int rht=height(n->right);
if (lht>rht)
{return(lht + 1);}
else
{return(rht + 1);}
}
}
void tree::traversal()
{
if(root!=NULL)

{
cout<<"Preorder tree traversal: "<<endl;
preorder(root);
cout<<endl;
cout<<"\nInorder tree traversal: "<<endl;
inorder(root);
cout<<endl;
cout<<"\nPostorder tree traversal: "<<endl;
postorder(root);
cout<<endl;
}
else
{cout<<"Tree is empty!"<<endl;}
}
void tree::preorder(node* n)
{
if(n==NULL)
{return;}
cout<<n->data<<" -> ";
preorder(n->left);
preorder(n->right);
}
void tree::inorder(node* n)
{
if(n==NULL)
{return;}
inorder(n->left);
cout<<n->data<<" -> ";
inorder(n->right);
}
void tree::postorder(node* n)
{
if(n==NULL)
{return;}
postorder(n->left);
postorder(n->right);
cout<<n->data<<" -> ";
}
void tree::smallest()
{
if(root!=NULL)
{
node *temp;
temp=root;
while(temp->left!=NULL)
{

temp=temp->left;
}
cout<<"The smallest data value in the tree: "<<temp->data<<endl;
}
else
{cout<<"Tree is empty!"<<endl;}
}
void tree::greatest()
{
if(root!=NULL)
{
node *temp;
temp=root;
while(temp->right!=NULL)
{
temp=temp->right;
}
cout<<"The greatest data value in the tree: "<<temp->data<<endl;
}
else
{cout<<"Tree is empty!"<<endl;}
}
void tree::search()
{
if(root==NULL)
{
cout<<"Tree is empty!"<<endl;
return;
}
cout<<"Enter the value to be searched: ";
node *temp=create();
if(root->data==temp->data)
{
cur=root;
}
else
{
par=cur=root;
while(cur->data!=temp->data && cur->left!=NULL &&
cur->right!=NULL)
{
if(temp->data < cur->data)
{
par=cur;
cur=cur->left;
}

else
{
par=cur;
cur=cur->right;
}
}
}
if(cur->data==temp->data)
{cout<<"Searched value "<<temp->data<<" found!"<<endl;}
else
{cout<<"Searched value "<<temp->data<<" not found!"<<endl;}
}
void tree::swapper()
{
if(root==NULL)
{
cout<<"Tree is empty!"<<endl;
return;
}
else
{
node *swapr;
swapr=root;
cout<<"Preorder mirror tree traversal: "<<endl;
swpre(swapr);
cout<<endl;
cout<<"\nInorder mirror tree traversal: "<<endl;
swin(swapr);
cout<<endl;
cout<<"\nPostorder mirror tree traversal: "<<endl;
swpost(swapr);
cout<<endl;
}
// node *swapr;
// swapr=root;
// cout<<"Mirror tree traversal: "<<endl;
// swap(swapr);
// cout<<endl;
}
// void tree::swap(node *n)
// {
// if(n==NULL)
// {return;}
// swap(n->right);
// cout<<n->data<<" -> ";
// swap(n->left);

// }
void tree::swpre(node *n)
{
if(n==NULL)
{return;}
cout<<n->data<<" -> ";
swpre(n->right);
swpre(n->left);
}
void tree::swin(node *n)
{
if(n==NULL)
{return;}
swin(n->right);
cout<<n->data<<" -> ";
swin(n->left);
}
void tree::swpost(node *n)
{
if(n==NULL)
{return;}
swpost(n->right);
swpost(n->left);
cout<<n->data<<" -> ";
}
void menu()
{
cout<<"\t***Menu***"<<endl;
cout<<"1. Insert new node"<<endl;
cout<<"2. Find the number of nodes in the longest path from root"<<endl;
cout<<"3. Display preorder, inorder & postorder traversal"<<endl;
cout<<"4. Find the smallest data value"<<endl;
cout<<"5. Find the greatest data value"<<endl;
cout<<"6. Search a value"<<endl;
cout<<"7. Swap the left and right subtrees"<<endl;
cout<<"8. Exit"<<endl;
}
int main()
{
int choice;
tree t;
void menu();
menu();
do
{
cout<<"\nEnter a choice: ";

cin>>choice;
switch(choice)
{
case 1:
t.insert();
break;
case 2:
t.longestpath();
break;
case 3:
t.traversal();
break;
case 4:
t.smallest();
break;
case 5:
t.greatest();
break;
case 6:
t.search();
break;
case 7:
t.swapper();
break;
case 8:
cout<<"Program exited! Thank you!"<<endl;
break;
default:
cout<<"Invalid choice!"<<endl;
break;
}
}
while(choice!=8);
return 0;
}