#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
	int n; //numero de usuarios a serem cadastrados
	int x;
	int seguido;

	string nomes[100]; // limite de 100 usuarios
	
	cin>>n;

	list<int> adj[100]; //lista de adjacencia, quem cada usuario segue
	
	//le os nomes dos usuarios
	for(int i=0; i<n; i++)
	{
		getline(cin>>ws, nomes[i]);
	}
	
	//le quem cada usuario segue
	for(int i=0; i<n; i++)
	{
		cin >> seguido;
		while(seguido != -1)
		{
			adj[i].push_back(seguido);
			cin >> seguido;
		}
	}
	
	//usuario de quem queremos ver os seguidores
	cin >> x;
	
	//busca pelos usuarios seguidos por x
	for(int i=0; i<n; i++)
	{
		for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it )
		{
			if(*it == x)
			{
				cout<<nomes[i]<<endl;
				break;
			}
		}
	}
	
	//limpeza 
	int i =0;
	while(!adj[i].empty())
	{
		adj[i].pop_front();
		i++;
	}
	
	return 0;	
}
