#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,wt;
	Node(int first,int second,int third){
		u=first;
		v=second;
		wt=third;
	}
};
int main(){
	int n=6;
	vector<Node> edge;
	edge.push_back(Node(0,1,5));
	edge.push_back(Node(1,2,-2));
	edge.push_back(Node(1,5,-3));
	edge.push_back(Node(2,4,3));
	edge.push_back(Node(3,2,6));
	edge.push_back(Node(3,4,-2));
	edge.push_back(Node(5,3,1));
	int source=0;
	vector<int> dist(n,10000000);
	dist[source]=0;
	for(int i=1;i<=n-1;i++){
		for(auto x:edge){
			if(dist[x.u]+x.wt<dist[x.v])
				dist[x.v]=dist[x.u]+x.wt;
		}
	}
	int fl=1;
	for(int i=1;i<=n-1;i++){
		for(auto x:edge){
			if(dist[x.u]+x.wt<dist[x.v]){
				cout<<"Negative Cycle";
				fl=0;
				break;
			}
		}
	}
	if(fl){
		for(int i=0;i<n;i++)
			cout<<dist[i]<<" ";
	}
	return 0;
}
