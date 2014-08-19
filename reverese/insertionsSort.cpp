#include "bits/stdc++.h"
#include "string"
using namespace std;

#define iterate(n) for(i=0;i<n;i++)
#define Diterate(i,s,e) for(int (i) = s ; (i)<=e ; i++)
#define get(a) cin >> a;
#define p(a) cout << a;
#define d(str,a) cout << str << " = " << a << endl
#define dv(str,a,n) iterate(n) { cout << str << "[" << i << "] = " << a[i] << endl; }

typedef long long int lld;

int a[] = {0,2,1,3,63,7,3,47,2,5,7,8};
int n = 11;
int heapLenght = 11; //from 1 to 11
// void Quick(int s, int e){
// 	int l = s;
// 	int r = e;
// 	int pivot ,index ;

// 	if(s < e){
// 		while(l<r){
// 			index = l;
// 			pivot = a[index];
// 			while(a[l] <=pivot && l<e) l++;
// 			while(a[r] > pivot && r>0) r--;
// 			if(l<r) swap(a[l],a[r]);		
// 		}
// 		swap(a[index],a[r]);

// 		Quick(s,r-1);
// 		Quick(r+1,e);
// 	}
// }


void Heapify(int i){
	int left = i<<1;
	int right = left + 1;
	int largest = i;
	if(right<=heapLenght && a[right] > a[largest] )
		largest = right;
	if(left <= heapLenght && a[left] > a[largest])
		largest = left;

	if(largest!=i){ 
		swap(a[largest],a[i]);
		Heapify(largest);
	}
}

void Build_Max_Heap(){
	int i = 1;
	for(i = heapLenght/2; i >=1 ; i--){
		Heapify(i);
	}
}

void HeapSort(){
	Build_Max_Heap();
	while(heapLenght > 1){
		Heapify(1);
		swap(a[1],a[heapLenght--]);
	}

}







int L[10],R[10];

void MergeSort(int s, int e){
	int i;
	if(s==e) return;
	if( (e-s) == 1 ){
		if(a[s] > a[e]) swap(a[s],a[e]);
		return;
	}
	int mid =(s+e)>>1;
	MergeSort(s,mid);
	MergeSort(mid+1,e);
	for(i=s;i<=mid;i++) 
		L[i-s] = a[i];
	for(i=mid+1;i<=e;i++) 
		R[i-(mid+1)] = a[i];
	L[mid-s+1] = 1e7;
	R[e-mid] = 1e7;
	
	int k = s;
	int first = 0,second = 0;

	for(k=s;k<=e;k++)    {
		if(L[first] <= R[second]) a[k] = L[first++];
		else a[k] = R[second++];
	}


}





class comp{
public:
	bool operator()(int a, int b){
		return a>b;
	}
};


class Item{
public:
		int data;
		Item *next;
		Item(int d):data(d){};
};

class LList{
public:
	int count;
	Item * head;
	Item * tail;
	LList(){
		head = NULL;		
		tail = NULL;
		count = 0;
	}
	void Insert(int d){
		if(count == 0){
			Item * a = new Item(d);
			head = a;
			tail = a;
		}else{
			Item *a = new Item(d);
			tail->next = a;
			tail = a;
		}
		count++;
	}
	void showAll(){
		Item *a;
		a = head;
		while(a!=NULL){
			printf("%d\n",a->data);
			a = a->next;
		}
	}

};

int main(){
	ios::sync_with_stdio(false);
	int i,j,t,n;
	int p,q,k,z,l;

	printf("Enter the numbner of Elements you want to eneter into the list\n");
	scanf("%d",&n);

	LList List;

	iterate(n){
		get(k);
		List.Insert(k);
	}
Won an online Algorithmic Event "Algothematics" in Annual Techno-cultural Contest of JSS, Noida.
Won Onsite Linus shell scripting Contest "Crack the Shell" in Annual Technical Contest of JSS, Noida.
Secured Top Most rank of 270 in Codechef Monthly Short Programming Contest (COOK48 ) in July '14.
Secured Top most Rank of 213 in Codechef Long Contest MAY CHALLENGE 2014.
	List.showAll();

	/* Insertion Sort */
	// for(i=1;i<7;i++){
	// 	int k = a[i];
	// 	j = i-1;
	// 	while(j>=0 && k < a[j]){ 
	// 		a[j+1] = a[j];
	// 		j--;
	// 	}
	// 	a[j+1] = k;
	// }


	/* Selection Sort */

	// int index;

	// for(i=0;i<7;i++){
	// 	int min = 1e5;
	// 	for(j=i;j<7;j++){
	// 		if(min > a[j]){ 
	// 			min = a[j];
	// 			index = j;
	// 		}
	// 	}
	// 	swap(a[i],a[index]);		

	// }

	/*  Quick Sort */


	// Quick(0,6);
	// MergeSort(0,11);

	// HeapSort();


	// iterate(12){
	// 	printf("%d\n",a[i] );
	// }

	return 0;
}




