#include<iostream>
using namespace std;

struct rocha {
  string nome, tipo;  
};

struct node {
	rocha info;
	node * left;
	node * right;
};

void insert(node * &curr, rocha info){
	if(curr == NULL){
		curr = new node;
		curr->info = info;
		curr->left = NULL;
		curr->right = NULL;
	} else {
		if(info.nome < curr->info.nome){
			insert(curr->left, info);
		} else {
			insert(curr->right, info);
		}
	}
}

node * search (node * curr, rocha info){
	if(curr == NULL){
		return NULL;
	} else {
		if(curr->info.nome == info.nome){
			return curr;
		} else {
			if(info.nome < curr->info.nome){
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

bool remove (node * &curr, rocha info){
	if(curr == NULL){
		return false;
	} else {
		if(curr->info.nome == info.nome && curr->info.tipo == info.tipo){
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
			if(info.nome < curr->info.nome){
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
	int aux;
	rocha rocha_aux;
	cin>>aux;
	
	while(aux!=0)
	{
	    if (aux==1){
	        getline(cin>>ws, rocha_aux.nome);
	        getline(cin>>ws, rocha_aux.tipo);
	        insert(root,rocha_aux);
	    }
	    else if (aux==2){
	        getline(cin>>ws, rocha_aux.nome);
	        node * result = search(root, rocha_aux);
        	if(result == NULL) {
	        	cout << "Rocha nao encontrada" << endl;
        	} else {
	        	cout <<"Nome: " << result->info.nome << endl;
	        	cout <<"Tipo: " << result->info.tipo << endl;
        	}
	    }
	    else if (aux==3){
	        getline(cin>>ws, rocha_aux.nome);
	        getline(cin>>ws, rocha_aux.tipo);
	        if(remove(root, rocha_aux)){
	        	cout << "Rocha removida com sucesso" << endl;
        	} else {
	        	cout << "Rocha nao encontrada para remocao" << endl;
        	}
	    }
	    else if (aux!=0){
	        cout<<"Operacao invalida"<<endl;
	    }
	    cin>>aux;
	}

	return 0;
}







