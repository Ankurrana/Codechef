
#include "iostream"
#include "cstdio"
	
using namespace std;

int myfunc(int x, int (*a)(int) ){  //the function is just an argument
	cout << a(x);
	return x;
}

int twice(int x){
	return x<<1;
}

int thrice(int x){
	return 3*x;
}


	


int main(){
	int (*pointer)(int ,int (*)(int) );
	int a = 10231;
	// scanf("%d\n",&a);

	pointer = &myfunc;

	pointer(a , &thrice);


}