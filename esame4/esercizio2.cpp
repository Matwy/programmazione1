#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 10
#define MAXSIZE 10

// NON MODIFICARE IL CODICE SOTTO FINO A "NON MODIFICARE IL CODICE SOPRA"
struct list {
  int info;
  list * next;
};

struct tree {
  int info;
  tree * left;
  tree * right;
};

void insert(tree * & result, const int num) {
		if (result == NULL) {
				result = new tree;
				*result = {num, NULL, NULL};
		} else if (result->info > num) {
				insert(result->left, num);
		} else {
				insert(result->right, num);
		}
}

tree * crea_tree(const int num) {
		tree * result = NULL;
		for(int i = 0; i < num; i++) {
				insert(result, rand()%MAXVALUE);
		}
		return result;
}

void print_tree(const tree * root){
		if (root != NULL) {
				print_tree(root->right);
				std::cout << " " << root->info;
				print_tree(root->left);
  }
}

void delete_tree(tree * & root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
  }
}

void print_array(const int l[], const int l_size) {
  for(int i = 0; i < l_size; i++)
    std::cout << " " << l[i];
  std::cout << std::endl;
}

// NON MODIFICARE IL CODICE SOPRA
int conta_pari(tree *root, int i = 0)
{
	if(root->info % 2 == 0)
		i++;
	if(root->left != NULL)
        i = conta_pari(root->left, i);
    
    if(root->right != NULL)
        i = conta_pari(root->right, i);

	return i;
}
int conta_dispari(tree *root, int i = 0)
{
	if(root->info % 2 == 1)
		i++;
	if(root->left != NULL)
        i = conta_dispari(root->left, i);
    
    if(root->right != NULL)
        i = conta_dispari(root->right, i);

	return i;
}

int aggiungi_pari(tree *root, int* l1, int l1_index=0)
{
	
	if(root->left != NULL)
        l1_index = aggiungi_pari(root->left, l1, l1_index);
    
	if(root->info % 2 == 0)
	{
		l1[l1_index] = root->info;
		l1_index++;
	}
	if(root->right != NULL)
        l1_index = aggiungi_pari(root->right, l1, l1_index);
	return l1_index;
}
int aggiungi_dispari(tree *root, int* l2, int l2_index=0)
{
	
	if(root->left != NULL)
        l2_index = aggiungi_dispari(root->left, l2, l2_index);
    
	if(root->info % 2 == 1)
	{
		l2[l2_index] = root->info;
		l2_index++;
	}
	if(root->right != NULL)
        l2_index = aggiungi_dispari(root->right, l2, l2_index);
	return l2_index;
}

// Add hereafter the declaration of estrai
void estrai(tree *root, int*& l1, int& l1_size, int*& l2, int& l2_size)
{
	l1_size = conta_pari(root);
	l2_size = conta_dispari(root);
	l1 = new int[l1_size];
	l2 = new int[l2_size];
	aggiungi_pari(root, l1);
	aggiungi_dispari(root, l2);
}

// Add here above the declaration of estrai

// NON MODIFICARE IL MAIN
int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(0);
		tree * root = crea_tree(rand()%MAXSIZE);
		std::cout << "Initial tree content: ";
		print_tree(root); std::cout << std::endl;
  int * l1;
  int l1_size;
  int * l2;
  int l2_size;
  estrai(root, l1, l1_size, l2, l2_size);
  delete_tree(root);
		std::cout << "L1 =";
  print_array(l1, l1_size);
		std::cout << "L2 =";
  print_array(l2, l2_size);
  delete [] l1;
  delete [] l2;
}
// NON MODIFICARE IL MAIN

// Add hereafter the definition of estrai

// Add here above the definition of estrai
