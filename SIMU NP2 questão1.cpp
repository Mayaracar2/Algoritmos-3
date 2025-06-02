#include <iostream>

using namespace std;

struct dados{
    double id;
    int pf;
};

struct Node {
	dados torta;
	Node * right;
	Node * left;
} ;


void insert(Node *& curr, dados torta){	
	if(curr == NULL){
		curr = new Node;
		curr->torta = torta;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(torta.pf >= curr->torta.pf){
			insert(curr->right, torta);
		} else if(torta.pf < curr->torta.pf) {
			insert(curr->left, torta);
		}		
	}	
}

void show_ordered(Node * curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	    cout << curr->torta.id << ":" << curr->torta.pf << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

Node * disconnect_lesser(Node *& curr){
	Node * aux = curr;
	if(aux->left == NULL){ 	
		curr = curr->right; 
		return aux;			
	} else {				
		return disconnect_lesser(curr->left);
	}
}

void destruct(Node *& curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}

int main ()
{
    Node * root = NULL;
    dados t;
    int i;
    double EM,P,A,D;
    
    cin>>i;
    
    for(int j=0; j<i; j++)
    {
        cin>>EM>>P>>A>>D;
        t.id=j;
        t.pf = (EM*P*A+D+A);
        insert(root, t);
    }
    
    show_ordered(root);
    destruct(root);
    
	return 0;
}
