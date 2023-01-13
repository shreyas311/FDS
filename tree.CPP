/* Shreyas Ganpat bhor   Roll No. 07
PRactical no. 1          Batch ::S1
TITLE:-Perform insert,display ,leaves,longest path & depth operations
*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};

class tree
{
	node *nn,*root,*ptr,*temp;

	public:
	char ch;
	void create();
	void insert(node*,node*);
	void display();
	void inorder(node*);
	void leaf();
	void display_leaves(node *temp);
	void longestpath();
	int depth(node*);
	tree ()
	{
        root=NULL;
    }
};
void tree ::create()
{
	nn=new node();
	nn->left=NULL;
	nn->right=NULL;
	cout<<"\n Enter the number::"<<endl;
	cin>>nn->data;
	if(root==NULL)
	{
		root=nn;
	}
	else	
	{
   		insert(root,nn);
	}
}
void tree :: insert (node *root,node *nn)
{
	cout<<"\nEnter your choice (l/L FOR LEFT and r/R FOR RIGHT )\n"<<endl;
	cin>>ch;
	if(ch=='l'||ch=='L')
	{
		if (root->left==NULL)
     	{
			root->left=nn;
		}
		else 
     	{
			insert(root->left,nn);
		}
	}
	else 
	{     
		if (root->right==NULL)
		{
			root->right=nn;
		}
		else 
       		{
			insert(root->right,nn);
		}
	}
}
void tree ::display()
{
	if(root==NULL)
	{	
		cout<<"\n This is Empty tree";
	}
	else
	{	
		inorder(root);
	}
}
void tree::inorder(node *ptr)
{	
	if(ptr!=NULL)
	{	
		inorder(ptr->left);
		cout<<"\t"<<ptr->data;
		inorder(ptr->right);
	}
}
void tree::leaf()
{
	display_leaves(root);
}
void tree::display_leaves(node *temp)
{
	if(root==NULL)
	{
		cout<<" \n The tree is not created";
	}
	if(temp!=NULL)
	{
		if((temp->left==NULL) && (temp->right==NULL))
		{	
			cout<<"\t"<<temp->data;
		}
		else
		{
			display_leaves(temp->left);
			display_leaves(temp->right);
		}
	}	
}
void tree:: longestpath()
{
	if(root==NULL)  
	{
		cout<<"\n The tree is EMPTY";
	}
	else
	{
		int ldepth=depth(root);
		int rdepth=depth(root);
		if(ldepth > rdepth)
		{
			cout<<"\n The depth of given tree is::"<<ldepth;
		}
		else
		{
			cout<<"\n The depth of given tree is::"<<rdepth;
		}
	}
}
int tree:: depth(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int ldepth=depth(root->left);
		int rdepth=depth(root->right);
		if(ldepth > rdepth)
		{
			return (ldepth +1);
		}
		else
		{
			return(rdepth+1);
		}
	}
}
int main()
{
	int ch2,ch3,ch4;
	tree b;
	do
	{	      
		
		cout<<"\nEnter which operation you want to perform::\n1.Insert node \t 2.Display tree \t3.Display Depth \t4.Display leaf node\n";
		cin>>ch2;
		switch(ch2)
		{
			case 1:
			do
				{
					b.create();
					cout<<"\n Do you want to insert new node in the tree:: \n press::1.yes \t 2.No\n";
					cin>>ch3;
				}while(ch3!=2);
				break;
			case 2:
				b.display();
				break;
			case 3:
				b.longestpath();
				break;
			case 4:
				b.leaf();
				break;
		}
	
	}while(ch4!=2);	
	return 0;
	
}
/*
OUTPUT::--

Enter which operation you want to perform::
1.Insert node    2.Display tree         3.Display Depth         4.Display leaf node
1

 Enter the number::
55

 Do you want to insert new node in the tree::
 press::1.yes    2.No
1

 Enter the number::
44

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

l

 Do you want to insert new node in the tree::
 press::1.yes    2.No
1

 Enter the number::
66

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

r

 Do you want to insert new node in the tree::
 press::1.yes    2.No
1

 Enter the number::
23

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

l

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

l

 Do you want to insert new node in the tree::
 press::1.yes    2.No
1

 Enter the number::
77

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

r

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

l

 Do you want to insert new node in the tree::
 press::1.yes    2.No
1

 Enter the number::
32

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

l

Enter your choice (l/L FOR LEFT and r/R FOR RIGHT )

r

 Do you want to insert new node in the tree::
 press::1.yes    2.No
2

Enter which operation you want to perform::
1.Insert node    2.Display tree         3.Display Depth         4.Display leaf node
2
        23      44      32      55      77      66
Enter which operation you want to perform::
1.Insert node    2.Display tree         3.Display Depth         4.Display leaf node
3

 The depth of given tree is::3
Enter which operation you want to perform::
1.Insert node    2.Display tree         3.Display Depth         4.Display leaf node
4
        23      32      77
Enter which operation you want to perform::
1.Insert node    2.Display tree         3.Display Depth         4.Display leaf node

*/
