#include<bits/stdc++.h>

#include "define.h"

#define MAX 100
#define MIN -100

using namespace std;

int main(int argc, char** argv){
	ofstream file(argv[1]);
	
	srand(time(nullptr));

	int range = MAX - MIN + 1;

	vector<vector<double>> data;

	for(uint i=0; i<NUMBER_OF_DATA; i++){
		vector<double> temp;
		for(uint j=0; j<2; j++){
			temp.push_back(double(rand() % range + MIN));
		}
		data.push_back(temp);
	}

	for(uint i=0; i<NUMBER_OF_DATA; i++){
		file<<data[i][0]<<',';
		file<<data[i][1];
		file<<endl;
	}
	file.close();

	file.open(argv[2]);
	for(uint i=0; i<NUMBER_OF_DATA; i++){
		file<<BETA0 + BETA1*data[i][0] + BETA2*data[i][1]<<endl;
	}
	file.close();
	return 0;
}
