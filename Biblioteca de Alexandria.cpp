#include<iostream>
using namespace std;

struct node {
	int info;
	node * left;
	node * right;
};

void insert(node * &curr, int info){
	if(curr == NULL){
		curr = new node;
		curr->info = info;
		curr->left = NULL;
		curr->right = NULL;
	} else {
		if(info < curr->info){
			insert(curr->left, info);
		} else {
			insert(curr->right, info);
		}
	}
}

node * search (node * curr, int info){
	if(curr == NULL){
		return NULL;
	} else {
		if(curr->info == info){
			return curr;
		} else {
			if(info < curr->info){
				return search(curr->left, info);
			} else {
				return search(curr->right, info);
			}
		}
	}
	
}

node * repoint_less(node * & curr){
	if(curr->left == NULL){
		node * aux = curr;
		curr = curr->right;
		return aux;
	} else {
		return repoint_less(curr->left);
	}
}

bool remove (node * &curr, int info){
	if(curr == NULL){
		return false;
	} else {
		if(curr->info == info){
			node * aux = curr;
			if(curr->left == NULL){
				curr = curr->right;
			} else if(curr->right == NULL){
				curr = curr->left;
			} else {
				aux = repoint_less(curr->right);
				curr->info = aux->info;	
			}
			delete aux;
			aux = NULL;
			return true;
		} else {
			if(info < curr->info){
				return remove(curr->left, info);
			} else {
				return remove(curr->right, info);
			}
		}
	}
}

void destruct(node * & curr){
	if(curr != NULL){
		destruct(curr->left);
		destruct(curr->right);
		delete curr;
	}
}

int main(){
	
	node * root = NULL;
	int N, x;
	char aux;
	
    cin>>N;
    
    for (int i=0; i<N; i++)
    {
        cin>>aux;
        cin>>x;
        
        if(aux=='i'){
            insert(root,x);
        }
        else{
            
            node * result = search(root,x);
	            if(result == NULL) {
		            cout << "Não" << endl;
            	} else {
		            cout << "Sim" << endl;
            	}
             }
    }
	return 0;
}
