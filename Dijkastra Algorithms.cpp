#include<bits/stdc++.h>
using namespace std;
vector<int> Dijkastra(vector<pair<int,int>> *adj,int n,int source){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> minheap;
	vector<int> disto(n+1,INT_MAX);
	disto[source]=0;
	minheap.push(make_pair(0,source));
	while( !minheap.empty() ){
		int dist = minheap.top().first;
		int prev = minheap.top().second;
		minheap.pop();
		for(auto x:adj[prev]){
			int next = x.first;
			int nextDist = x.second;
			if( disto[next] > disto[prev] + nextDist){
				disto[next] = disto[prev] + nextDist;
				minheap.push(make_pair(disto[next], next));
			}
		}
	}
	return disto;
}
int main(){
	int n=5,m=6,source=1;
	vector<pair<int,int>> adj[n+1];
	adj[1].push_back({2,2});
	adj[1].push_back({4,1});
	adj[2].push_back({1,2});
	adj[2].push_back({5,5});
	adj[2].push_back({3,4});
	adj[3].push_back({2,4});
	adj[3].push_back({4,3});
	adj[3].push_back({5,1});
	adj[4].push_back({1,1});
	adj[4].push_back({3,3});
	adj[5].push_back({2,5});
	adj[5].push_back({3,1});
	vector<int> ans;
	ans=Dijkastra(adj,n,source);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
