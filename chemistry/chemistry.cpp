#include "bits/stdc++.h"
#include "string"
#include "climits"
using namespace std;



#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }




class Node{
public:
	int data;
	int distance; /* Also Finds distance from the source/starting node */
	int parent; /* Index of the parent node */
	int root; /*It is the representative node number for each component , 
				It can be used to check if two nodes belong to the same component of the graph */
	vector< int > AL;
	Node(){
		distance = INT_MAX;
	}	
}N[1000001];


/* Define N a global variable */

class BFS{
public:
	bool isAdded[1000001];
	int numComponents;
	vector< int > ComponentSizes;
	BFS(int n){  /* @n  : number of nodes in the graph */
		numComponents = 0;
		for(int i=1;i<=n;i++){
			if(!isAdded[i]){
				numComponents++;
				 ComponentSizes.push_back(traverseFromASingleNode(i));
			}
		}
	}

	BFS(int n,int s){ // In case of known single Component and Fixed source node , 
	 	numComponents = 1;
	 	ComponentSizes.push_back(traverseFromASingleNode(s));
	}
	bool areSameComponent(int a, int b){
		if(N[a].root == N[b].root) return true;
		return false;
	}

private:
	int traverseFromASingleNode(int s){
		//Distance is calculated from the source node s
		//It returns the size of the component
		//S is also the root node for all the reachable nodes from s;
		int size = 0;
		queue < int > Q;
		N[s].distance = 0;
		isAdded[s] = true;
		Q.push(s);
		vector< int >::iterator it;
		while(!Q.empty()){
			int u = Q.front(); Q.pop();
			N[u].root = s;
			size++;
			for(it = N[u].AL.begin(); it!= N[u].AL.end(); it++){
				if(!isAdded[*it]){
					isAdded[*it] = true;
					Q.push(*it);
					N[*it].parent = u;
					N[*it].distance = N[u].distance + 1;
				}
			}
		}
		return size;
	}	
};


int main(){
	ios::sync_with_stdio(false);
	int i,j,t,n,m;
	int p,q,k,z,l;

	// get(n); get(m);

	get(n); //the number of nodes 
	get(m); //the number of edges

	//Enter the Adjacency list
	iterate(m){
		get(p);
		get(q);
		N[p].AL.push_back(q);
		N[q].AL.push_back(p);
	}


	BFS bfs =  BFS(n);

	// Diterate(i,1,n){
	// 	cout << "Node Number :: "  << i << endl;
	// 	cout << "Distance :: " << N[i].distance << endl;
	// 	cout <<  "Parent :: " <<N[i].parent << endl;
	// 	cout <<  "Root :: "  <<N[i].root << endl;
	// }

	// cout << "Component Sizes " << endl;

	long long int ans = 1;

	for(i=0;i<bfs.numComponents;i++){
		ans <<= bfs.ComponentSizes[i] - 1;
	}

	p(ans);
	return 0;
}




