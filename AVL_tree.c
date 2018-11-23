#include "AVL_tree.h"

AVL_TREE* create_avl_tree(){
		AVL_TREE* tree = (AVL_TREE*)malloc(sizeof(AVL_TREE));

			tree->count = 0;
			tree->root = NULL;
			return tree;
}

T_NODE* rotate_left(T_NODE* root){
	T_NODE* new_root;
	new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;
	return new_root;
}

T_NODE* rotate_right(T_NODE* root){
	T_NODE* new_root;
	new_root = root->left;
	root->left = new_root->right;
	new_root->right = root;
	return new_root;
}

bool AVL_insert(AVL_TREE* tree, int data){
	T_NODE* new_root;
	bool taller;
	new_root = (T_NODE*)malloc(sizeof(T_NODE));

	if(!new_root) return false;

	new_root->balance = EH;
	new_root->right = NULL;
	new_root->left = NULL;
	new_root->data = data;

	tree->root = insert_rotate(tree->root, new_root, &taller);

	(tree->count)++;
	return true;
}

T_NODE* insert_rotate(T_NODE* root, T_NODE* new_root, bool* taller){
	if(root == NULL){
		root = new_root;
		*taller = true;
		return root;
	}
	if((new_root->data)<(root->data)){
		root->left = insert_rotate(root->left, new_root, taller);
		if(*taller){
			switch(root->balance){
				case LH: root = balance_left(root, taller);
				break;
				case EH: root->balance= LH;
				break;
				case RH: root->balance = EH;
				*taller = false;
				break;
			}
		}
		return root;
	}

	else{
		root->right = insert_rotate(root->right, new_root, taller);

		if(*taller){	
			switch(root->balance){
				case LH: root->balance = EH;
						 *taller = false;
						 break;
				case EH: root->balance= RH;
						 break;
				//case RH: root = balance_right(root, taller);		
						 break;
			}
		}
		return root;
	}
return root;
}

T_NODE* balance_left(T_NODE* root, bool* taller){
	T_NODE* right_tree;
	T_NODE* left_tree;

	left_tree = root->left;
	switch(left_tree->balance){
		case LH:
				root->balance = EH;
				left_tree->balance = EH;
				root = rotate_right(root);
				*taller = false;
				break;
		case EH:
				exit(0);
		case RH:
				right_tree = left_tree->right;
				switch(right_tree->balance){
					case LH:
							root->balance = RH;
							left_tree->balance = EH;
							break;
					case EH:
							root->balance = EH;
							left_tree->balance = EH;
							break;
					case RH:
							root->balance = EH;
							left_tree->balance = LH;
							break;
				}
				right_tree->balance = EH;
				root->left = rotate_left(left_tree);
				root = rotate_right(root);
				*taller = false;
	}
	return root;
}

void traverse_preorder(T_NODE* root){
	if(root != NULL){
		printf("%d ",root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void AVL_print(AVL_TREE* tree){
	printf("AVL_TREE\n");
	printf("size : %d\n",tree->count);
	printf("data : ");

	traverse_preorder(tree->root);

	printf("\n");
}
