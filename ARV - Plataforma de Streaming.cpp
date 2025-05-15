#include<iostream>
using namespace std;

struct filme {
    string nome, genero;
    int duracao, classif, ano;
};

struct node {
	filme info;
	node * left;
	node * right;
};

void insert(node * &curr, filme info){
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

node * search (node * curr, filme info){
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

bool remove (node * &curr, filme info){
	if(curr == NULL){
		return false;
	} else {
		if(curr->info.nome == info.nome){
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
	filme filme_aux;
	
	cin>>aux;
	
	while(aux!=0)
	{
	    if(aux == 1){
	        getline(cin>>ws, filme_aux.nome);
	        getline(cin>>ws, filme_aux.genero);
	        cin>>filme_aux.duracao;
	        cin>>filme_aux.classif;
	        cin>>filme_aux.ano;
	        insert(root,filme_aux);
	    }
	    else if(aux==2) {
	        getline(cin>>ws, filme_aux.nome);
	        node * result = search(root, filme_aux);
        	if(result == NULL) {
	        	cout << "Filme nao encontrado" << endl;
        	} else {
	        	cout <<"Nome: " << result->info.nome << endl;
	        	cout <<"Genero: " << result->info.genero << endl;
	        	cout <<"Duracao: " << result->info.duracao << " mins"<< endl;
	        	cout <<"Classificacao: " << result->info.classif << endl;
	        	cout <<"Ano: " << result->info.ano << endl;
        	}
	         }
        else if (aux!=0) {
            cout<<"Operacao invalida"<<endl;
        }
	    cin>>aux;
	}
	
	return 0;
}







