#include "match.h"

using namespace std;

match::match(int num){
	//create an empty match unit
	units = num;
	buckets = (float*) malloc(sizeof(int)*num);
	var = (float*) malloc(sizeof(int)*num);
	times = 0;
}

void match::update(float* values, float* range){
	for (int i = 0; i < units; i++){
		buckets[i] = values[i];
		var[i] = range[i];
	}
	times = 1;
}

void match::up(float* values, float* range){
	for (int i = 0; i < units; i++){
		buckets[i] = (buckets[i]*times + values[i])/(times + 1);
		var[i] = (var[i]*times + range[i])/(times + 1);
	}
	times += 1;
}

match::~match(){
	if (buckets){
		free(buckets);
		buckets = NULL;
	}
	if (var){
		free(var);
		var = NULL;
	}
}


int match::compare(float* input){
	int flag = 1;
	for (int i = 0; i < units; i++){
		if (abs(buckets[i]-input[i]) > var[i]){
			flag = 0;
		}
	}

	return flag;
}

void match::printer(){
	for (int i = 0; i < units; i++){
		cout << buckets[i] << "   " <<  var[i] << endl;
	}
}
