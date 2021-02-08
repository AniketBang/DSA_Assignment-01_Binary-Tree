/*
 * main.cpp
 *
 *  Created on: 01-Feb-2021
 *      Author: aniket
 */
#include <iostream>
using namespace std;

class node
{
private:
	node* lc;
	node* rc;
	int data;

public:
	friend class binarytree;

	node(int x)
	{
		lc = NULL;
		rc = NULL;
		data = x;
	}

};

class binarytree
{

private:
	node* root;

public:
	binarytree()
	{
		root = NULL;
	}

	void create(int x)
	{
		if (root == NULL)
		{
			node* tem= new node(x);
			root = tem;
		}

		else
		{
			cout<<"Already created... Call insert Function";
		}
	}

	node* insert(node* val, int x)
	{
		node* temp;

		if(root==NULL)
		{
			cout<<"Create Root First  ";
		}

		if (val == NULL)
		{
			temp= new node(x);
			return temp;
		}

		else
		{
			cout<<"Press 'L' for Left Child \nPress'R' for Right Child \nEnter your Choice: ";
			char j;
			cin>> j;

			if (j == 'l' or j == 'L')
				{
					val->lc = insert(val->lc, x);
				}

			else
				{
					val->rc = insert(val->rc, x);
				}
		}

		return val;
	}

	void inorder(node* t)
	{
		if (t != NULL)
		{
			inorder(t->lc);
			cout<< t->data;
			inorder(t->rc);
		}
	}

	void preorder(node* t)
	{
		if (t != NULL)
		{
			cout<<t->data;
			preorder(t->lc);
			preorder(t->rc);
		}
	}

	void postorder(node* t)
	{
		if(t!= NULL)
		{
			postorder(t->lc);
			postorder(t->rc);
			cout<< t->data;
		}
	}

	int height(node* t)
		{

			int ldepth, rdepth;

			if (t== NULL)
			{
				return 0;
			}

			if (t->lc == NULL && t->rc == NULL)
			{
				return 0;
			}

			ldepth = height(t->lc);
			rdepth = height(t->rc);

			if (ldepth > rdepth)
				{
					return(ldepth +1);
				}

			else
				{
					return(rdepth + 1);
				}
		}

	void mirror(node* val)
	{
		if (val== NULL)
		{
			return;
		}

		else
		{
			node* temp;

			//Move to Subtrees
			mirror(val->lc);
			mirror(val->rc);

			// Swapping
			temp= val->lc;
			val->lc = val->rc;
			val->rc= temp;

		}
	}

	int leafnodes(node* val)
	{
		if(val == NULL)
		{
			return 0;
		}

		else if(val-> lc == NULL && val->rc == NULL)
		{
			return 1;
		}

		else
		{
			return (leafnodes(val->lc) + leafnodes(val->rc) );
		}
	}

	int internalnodes(node* val)
	{
		if (val == NULL || (val->lc == NULL && val->rc == NULL))
		{
			return 0;
		}

		else
		{
			return (1 + internalnodes(val->lc) + internalnodes(val->rc));
		}
	}

	void deletenode(node* val)
		{
			if (val == NULL)
			{
				return;
			}

			deletenode(val->lc);
			deletenode(val->rc);

			cout<<"Deleting: "<< val->data<< endl;
			delete val;
		}


	node* call()
	{
		return root;
	}

};

class stack
{

};

int main()
{
	binarytree n1;

	while(true)
	{
		int n;
		cout<<"Binary Tree Menu -> \n1. Create a Root \n2. Insert a Node \n3. Traverse through Binary tree \n4. Mirror Image of Binary Tree \n5. Height of Tree \n6. Copy Binary Tree \n7. Count Nodes \n8. Delete \n0. Exit \nEnter your Choice: ";
		cin>>n;
		cout<<endl;

		if (n==1)													//Create a Root
		{
			cout<<"Creating a Root !!!"<<endl;
			cout<<"Enter value to your Root: ";
			int i;
			cin>>i;

			// Call create() function
			n1.create(i);
			cout<<endl;
		}

		else if (n==2)												//Insert Nodes
		{
			cout<<"Inserting a Node !!!"<<endl;
			cout<<"Enter value to be inserted: ";
			int j;
			cin>>j;

			//Call insert Function
			n1.insert(n1.call(), j);
			cout<<endl;
		}

		else if(n==3)												//Traversals
		{
			cout<<"Binary Tree Traversal Menu -> \n1. Preorder Traversal \n2.Inorder Traversal \n3. Postorder Traversal \n4. Back to Main Menu \n Enter your choice: ";
			int m;
			cin>>m;

			if(m==1)												// Preorder Traversal
			{
				cout<<"Methods for Preorder Traversal -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
				int k;
				cin>>k;

				if (k==1)					// Recursive Method
				{
					n1.preorder(n1.call());
					cout<<endl;
				}

				else 						// Iterative Method
				{
					cout<<"Remaining to Code";
				}
			}

			else if (m==2)										//Inorder Traversal
			{
				cout<<"Methods for Inorder Traversal -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
				int a;
				cin>>a;

				if(a==1)				//Recursive Method test comment
				{
					n1.inorder(n1.call());
					cout<<endl;
				}

				else					//Iterative Method
				{
					cout<<"Remaining to Code";
				}
			}

			else if (m==3)										//Postorder Traversal
				{
					cout<<"Methods for Postorder Traversal -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
					int b;
					cin>>b;

					if(b==1)				//Recursive Method
					{
						n1.postorder(n1.call());
						cout<<endl;
					}

					else					//Iterative Method
					{
						cout<<"Remaining to Code";
					}
				}
			else
			{
				break;
			}

			cout<<endl;
		}

		else if (n==4)													//Mirror Image
		{
			cout<<"Methods for Mirror Image of Binary Tree -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
			int c;
			cin>>c;

			if(c==1)				//Recursive Method
			{
				n1.mirror(n1.call());
				cout<<"Choose any of the Traversal Method from Option 3";
			}

			else					//Iterative Method
			{
				cout<<"Remaining to Code";
			}

			cout<<endl;
		}

		else if (n==5)												// Height of Tree
		{
			cout<<"Methods for Height of Binary Tree -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
			int e;
			cin>>e;

			if (e==1)				//Recursive Method
			{
				int h =n1.height(n1.call());
				cout<<"Height of Binary Tree: "<< h <<endl;
			}

			else
			{
				cout<<"Remaining ot Code";
			}

			cout<<endl;
		}

		else if (n==6)												// Copy of Tree
		{
			cout<<"Methods for Copying a Binary Tree -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
			int f;
			cin>>f;

			if (f==1)				//Recursive Method
			{
				cout<<"Remaining ot code";
			}

			else
			{
				cout<<"Remaining ot Code";
			}

			cout<<endl;
		}


		else if (n==7)												//Counting Nodes
		{
			cout<<"Binary Tree Counting Nodes Menu \n1. Count Leaf Nodes \n2. Count Internal Nodes \n3. Back to Main Menu";
			int d;
			cin>>d;

			if(d==1)							// Counting Leaf Nodes
			{
				cout<<"Methods for Counting Leaf Nodes -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
				int e;
				cin>>e;

				if(e==1)			//Recursive Method
				{
					int x = n1.leafnodes(n1.call());
					cout<<"Number of Leaf nodes: "<<x<<endl;
				}

				else 				//Iterative Method
				{
					cout<<"Remaining to code";
				}
			}

			if(d==2)							// Counting Internal Nodes
			{
				cout<<"Methods for Counting Internal Nodes -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
				int f;
				cin>>f;

				if(f==1)			//Recursive Method
				{
					int y = n1.internalnodes(n1.call());
					cout<<"Number of Internal nodes: "<< y <<endl;
				}

				else 				//Iterative Method
				{
					cout<<"Remaining to code";
				}
			}

			cout<<endl;
		}

		else if (n==8)												// Delete
		{
			cout<<"Methods for Counting Internal Nodes -> \n1. Recursive \n2.Iterative \nEnter your Choice: ";
			int g;
			cin>>g;

			if(g==1)			//Recursive Method
			{
				n1.deletenode(n1.call());
			}

			else 				//Iterative Method
			{
				cout<<"Remaining to code";
			}
			cout<<endl;
		}

		else if (n==0)
		{
			break;
			cout<<endl;
		}

		else
		{
			cout<<"Enter Valid Choice";
			cout<<endl;
		}
	}

	return 0;
}
