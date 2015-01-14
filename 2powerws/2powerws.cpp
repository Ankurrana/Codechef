#include <bits/stdc++.h>
using namespace std;
int n,m,s,i,j,k,t,b[3005];
vector<int> a[3005];
int main() {
	cin>>n>>m;
	for (i=0; i<m; i++) {
		cin>>j>>k;
		a[j].push_back(k);
	}
	for (i=1; i<=n; i++) {
		for (j=0; j<a[i].size(); j++) {
			t = a[i][j];
			for (k=0; k<a[t].size(); k++)
				b[a[t][k]]++;
		}
		for (j=1; j<=n; j++) {
			if (i != j)
				s += b[j]*(b[j]-1)/2;
			b[j] = 0;
		}
	}
	cout<<s;
}