//181180056 Ciya Baran ONER
#include <stdio.h>
#include <stdlib.h>

//creating of struct
struct treeNode { // creating of node
    struct treeNode *leftPtr; // the node on the left of node
    int data; // data of in the node
    struct treeNode *rightPtr; // the node on the right of node
}; 
typedef struct treeNode TreeNode; 
typedef TreeNode *TreeNodePtr; 

// fonsk. definations
void insertNode( TreeNodePtr *treePtr, int value );
void inorder( TreeNodePtr treePtr );
void preorder( TreeNodePtr treePtr );
void postorder( TreeNodePtr treePtr );

void printAll( TreeNodePtr treePtr ); // this function will print the tree as preorder, inorder and postorder



int main()
{ 
	TreeNodePtr tree =NULL;  // creating of tree. At first tree is null 
 	int i;	// dummy 
    int upper=25; // max value of random
    int lower=1; // min value of random
    
	for(i=0;i<10;i++){ // adding 10 random values to the tree
		insertNode(&tree,(rand() % (upper - lower + 1) + lower));
	}
		
    printAll(tree); // printing
	
	return 0;
} 
// prints the tree as preorder, inorder and postorder by other functions
void printAll(TreeNodePtr treePtr ){
	
	
	printf( "\npreorder:" );
    preorder( treePtr ); 

    printf( "\ninorder:" );
    inorder( treePtr );

    printf( "\npostorder:" );
    postorder( treePtr );
}



void insertNode( TreeNodePtr *treePtr, int value ) // adding nodes to the tree
{ 
   
    if ( *treePtr == NULL )  // if tree is null, so it has no node.
	{   
        *treePtr = (TreeNode *)malloc( sizeof( TreeNode ) ); // bellekte yer acma islemi 
        (*treePtr) -> data = value; //the first node was created, and its right and left nodes must be null
   		(*treePtr) -> leftPtr = NULL;
        (*treePtr) -> rightPtr = NULL;
    } 
	else if ( value > ( *treePtr )->data ) { // if node is not empty and the value is bigger than data of node, the value will be inserted to the right side of tree
        insertNode( &( ( *treePtr )-> rightPtr ), value );
        
    } 
    else{
    	insertNode( &( ( *treePtr )-> leftPtr ), value );	// if node is not empty and the value is smaller than data of node, the value will be inserted to the left side of tree
		
	}
} 
// printing as inorder
void inorder( TreeNodePtr treePtr )
{ 
	
	 if ( treePtr != NULL ) // if node is not null, it prints as LNR
	 { 
        inorder( treePtr->leftPtr );
        printf( "%d ", treePtr->data );
        inorder( treePtr->rightPtr );
    }

} 
//printing as preorder
void preorder( TreeNodePtr treePtr )
{ 

    if ( treePtr != NULL ) { //if node is not null, it prints as NLR
        printf( "%d ", treePtr->data );
        preorder( treePtr->leftPtr );
        preorder( treePtr->rightPtr );
    } 

}
//printing as postorder
void postorder( TreeNodePtr treePtr )
{ 

    if ( treePtr != NULL ) { // if node is not null, it prints as LRN
        postorder( treePtr->leftPtr );
        postorder( treePtr->rightPtr );
        printf( "%d ", treePtr->data );
    } 

} 
