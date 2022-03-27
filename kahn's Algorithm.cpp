#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> *adj,int u,int v){
	adj[u].push_back(v);
}
void topological(vector<int> *adj,int v){
	vector<int> in_degree(v,0);
	for(int i=0;i<v;i++){
		for(int x:adj[i])
			in_degree[x]++;
	}
	queue<int> q;
	for(int i=0;i<v;i++){
		if(in_degree[i]==0)
			q.push(i);
	}
	while(q.empty()==false){
		int temp=q.front();
		q.pop();
		cout<<temp<<" ";
		for(int x:adj[temp]){
			if(--in_degree[x]==0)
				q.push(x);
		}
	}
}
int main(){
	int v=5;
	vector<int> adj[v];
	addedge(adj,0,2);
	addedge(adj,0,3);
	addedge(adj,1,3);
	addedge(adj,1,4);
	addedge(adj,2,3);
	topological(adj,v);
	return 0;
}
