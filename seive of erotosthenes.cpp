//Time complexity O(n^3/2)
#include<iostream>
#include<vector>
using namespace std;
bool isprime(int n){
	if(n==1)
		return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
void seive(int n){
	vector<bool> isprime(n+1,true);
	for(int i=2;i*i<=n;i++){
		if(isprime[i]){
			for(int j=2*i;j<=n;j=i+j){
				isprime[j]=false;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(isprime[i])
			cout<<i<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	seive(n);
	return 0;
}
