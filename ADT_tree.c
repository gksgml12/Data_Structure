#include "ADT_tree.h"

BST_TREE* create_bst_tree(){
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	tree->count = 0;
	tree->root = NULL;

	return tree;
}

bool BST_insert(BST_TREE* tree, int data){
	T_NODE* new_root;
	new_root = add_bst(tree->root, data);

	if(new_root == NULL)
		return false;
	else
	{
		tree->root = new_root;
		(tree->count)++;
		return true;
	}
}

T_NODE* add_bst(T_NODE* root, int data){
	if(root == NULL)
	{
		T_NODE* new_node = (T_NODE*)malloc(sizeof(T_NODE));
		if(!new_node)
			return NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->data = data;

		return new_node;
	}
	if(data < (root->data)){
		root->left = add_bst(root->left, data);
		return root;
	}
	else{
		root->right = add_bst(root->right, data);
		return root;
	}
}

T_NODE* find_smallest_node(T_NODE* root){
	if(root->left == NULL)
		return root;
	else
		return find_smallest_node(root->left);
}

T_NODE* find_largest_node(T_NODE* root){
	if(root->right == NULL)
		return root;
	else
		return find_largest_node(root->right);
}

T_NODE* search_bst(T_NODE* root, int key){
	if(root==NULL)
		return NULL;
	if(key < (root->data))
		return search_bst(root->left, key);
	else if(key > (root->data))
		return search_bst(root->right, key);
	else
		return root;
}

bool BST_delete(BST_TREE* tree, int data){
	bool success;
	T_NODE* new_root;
	new_root = delete_bst(tree->root, data, &success);

	if(success){
		tree->root = new_root;
		(tree->count)--;
		if(tree->count==0)
			tree->root = NULL;
	}

	return success;
}

T_NODE* delete_bst(T_NODE* root, int data, bool* success){
	T_NODE* new_root;
	T_NODE* deleted_node;
	T_NODE* search;

	if(root == NULL){
		*success = false;
		return NULL;
	}
	
	if(data < (root->data)){
		root->left = delete_bst(root->left, data, success);
	}
	else if(data > (root->data)){
		root->right = delete_bst(root->right, data, success);
	}
	else{
		deleted_node = root; // at first, node to delete is found.
		if(root->left == NULL){ // there is no left son of root.
			new_root = root->right;
			free(deleted_node);
			*success = true;
			return new_root;
		}
		else{
			if(root->right == NULL){ // there is no right son of root.
				new_root = root->left;
				free(deleted_node);
				*success = true;
				return new_root;
			}
			else{ // there are two sons.
				search = root->left;
				while(search->right != NULL) // find until left son's biggest son.
					search = search -> right;
				root->data = search->data;
				root->left = delete_bst(root->left, search->data, success); // still left son's biggest son is alive. therefore, we have to delete it.
			}
		}
	}
	return root;
}

void traverse_inodrder(T_NODE* root){ // left, rooot, right
	if(root != NULL){
		traverse_inodrder(root->left);
		printf("%d.", root->data);
		traverse_inodrder(root->right);
	}
}

void traverse_postorder(T_NODE* root){ // left, right, root
	if(root != NULL){
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d.", root->data);
	}
}

void traverse_preorder(T_NODE* root){ // root, left, right
	if(root != NULL){
		printf("%d.", root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void BST_print(BST_TREE* tree, int method){
	printf("BST_TREE\n");
	printf("size : %d\n", tree->count);
	printf("data : ");

	if(method == 0)
		traverse_preorder(tree->root);
	else if(method == 1)
		traverse_inodrder(tree->root);
	else if(method == 2)
		traverse_postorder(tree->root);
	else
		printf("type error");

	printf("\n");
}

int find_largest_node2(T_NODE* root){
	int h = 1;
	if(root->left == NULL)
		return h;
	else if(root->left->right == NULL)
		return h+1;
	else if(root->left->right->right == NULL)
		return h+2;
	else if(root->left->right->right->right == NULL)
		return h+3;
	else if(root->left->right->right->right->right == NULL)
		return h+4;
	else if(root->left->right->right->right->right->right == NULL)
		return h+5;
	else
		return 0;
}