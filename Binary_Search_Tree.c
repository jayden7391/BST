#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode{        
	int data;        
	struct treeNode *left;        
	struct treeNode *right;
}

treeNode * Insert(treeNode *node,int data){        
	if(node==NULL)        
	{                
		treeNode *temp;                
		temp = (treeNode *)malloc(sizeof(treeNode));                
		temp -> data = data;                
		temp -> left = temp -> right = NULL;                
		return temp;      
	}     
	
	else if(data >(node->data))        
		{                
			node->right = Insert(node->right,data);        
		}        
	else if(data < (node->data))        
		{                
			node->left = Insert(node->left,data);        
		}        
		/* Else there is nothing to do as the data is already in the tree. */        
		return node;
}
treeNode * Find(treeNode *node, int data){
	if(node==NULL)        
	{                
		/* Element is not found */                
		return NULL;        
	}        
	if(data > node->data)        
	{                
		/* Search in the right sub tree. */                
		return Find(node->right,data);        
	}        
	else if(data < node->data)        
	{                
		/* Search in the left sub tree. */                
		return Find(node->left,data);        
	}        
	else        
	{                
		/* Element Found */                
		return node;        
	}
}

void PrintPreorder(treeNode *node){        
	if(node==NULL)        
	{                
		return;        
	}        
	printf("%d ",node->data);        
	PrintPreorder(node->left);       
	PrintPreorder(node->right);
}
			
int main(){    
	treeNode *root = NULL;   
	int n, od, d, i;
	printf("Input number of input data : ");
	scanf("%d",&n);
	for(i = 0; i<n; i++){
		printf("Input data : ");
		scanf("%d",&d);
		root = Insert(root, d);
		PrintPreorder(root);
		printf("\n");
	}

	printf("Input number of data which you want to find : ");
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		printf("Input data which you want to find : ");
		scanf("%d",&d);
		temp = Find(root,d); 
		if(temp==NULL)       
		{           
			printf("Element %d not found\n",d);    
		}       
		else   
		{      
			printf("Element %d Found\n",d); 
		} 
	}
}
