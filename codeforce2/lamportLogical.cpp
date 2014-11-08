#include "bits/stdc++.h"
using namespace std;

int d = 1;


class Process{
public:
	int timestamps[100];
	int increments[100];
	int n;
	Process(int NumberofEvents):n(NumberofEvents){
		memset(increments,0,sizeof(increments));
		for(int i=1;i<=n;i++) timestamps[i] = i*d;
	}
	void update(){
		int temp = 0;
		for(int i=1;i<=n;i++){
			temp += increments[i]; 
			timestamps[i] += temp;
			increments[i] = 0;  
		}
	}
	bool sendmessage(int localEventNumber, Process &otherProcess, int otherProcessEvent){
		update();
		otherProcess.recieve(timestamps[localEventNumber],otherProcessEvent);
	}
	void recieve(int timestamp, int localEventNumber){
		update();
		if(timestamps[localEventNumber] > (timestamp + d) ){}
		else{
			increments[localEventNumber] = timestamp + d - timestamps[localEventNumber];
		}
	}
	void desc(){
		update();
		for(int i=1;i<=n;i++) printf("Event[%d] = %d\n",i,timestamps[i]);
	}
};

int main(){
	Process proceses[] = {0,7,5}; /*  Pg. 103 Singhal and Shivratri Example */

	proceses[1].sendmessage(2,proceses[2],3);
	proceses[2].sendmessage(2,proceses[1],5);
	proceses[1].sendmessage(6,proceses[2],5);
	proceses[2].sendmessage(4,proceses[1],7);


	printf("Description of Process 1\n");
		proceses[1].desc();

	printf("Description of Process 2\n");
		proceses[2].desc();

	return 0;
}