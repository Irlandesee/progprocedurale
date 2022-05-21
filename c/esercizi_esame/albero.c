#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int k;
	struct nodo *sx;
	struct nodo *dx;
}

void visit(struct nodo*);
struct nodo *elimina_foglie(struct nodo *);

int main(int argc, char **argv){

}

void visit(struct nodo *n){
	if(n != NULL) printf("%d\n", n->k);
}

/**
 * Using preorder traversal
 * */
struct nodo *elimina_foglie(struct nodo *root){
	if(root == NULL) return NULL;
	if(root_copy->sx == NULL && root_copy->dx == NULL){
		free(root_copy);
		return NULL;
	}
	if(root_copy->sx != NULL) root->sx = elimina_foglie(root->sx);
	if(root_copy->dx != NULL) root->dx = elimina_foglie(root->dx);
	return root;
}