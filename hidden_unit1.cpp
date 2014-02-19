#include "hidden_unit1.h"

using namespace std;

#define Beta 1.0
#define Eta 0.001

hidden_unit1::hidden_unit1(int numUnits){
	units = numUnits;
	weights = (float*)malloc(sizeof(float)*units);
	weight_updates = (float*)malloc(sizeof(float)*units);
	for(int i=0; i<numUnits; i++){
		weights[i] = 1;
		weight_updates[i] = 0;
	}
}

hidden_unit1::hidden_unit1(float* weights, int numUnits){
	this->weights = weights;
	units = numUnits;
	weight_updates = (float*)malloc(sizeof(float)*units);
}

hidden_unit1::~hidden_unit1(){
	cout << "hidden_unit1 deleted\n";
	if(weights){
		free(weights);
		weights = NULL;
	}
	if(weight_updates){
		free(weight_updates);
		weight_updates = NULL;
	}
}

float hidden_unit1::f(){
	return (float) 1/(1+exp(-1*(Beta*sum)));
}
float hidden_unit1::net(float* inputs){
	//sum inputs * weights
	sum = 0;
	for(int i=0; i<UNITS; i++){
		sum += inputs[i] * weights[i];
	}
	return f();
}

void hidden_unit1::backPropogation(float y, float d, float *w2, int sizeW2, float *z1){
	//TODO
	float a, b, c, e, f;
	for(int i=0; i<units; i++){
		for(int j=0; j<sizeW2; j++){
			a = (-1)*(d-y) * w2[j] * z1[i];
			b = exp(-1 * Beta * sum);
			c = Beta * b;
			e = (1 + b) * (1 + b);
			f = c/e;
			weight_updates += a * f;
		}
	}
}

void hidden_unit1::update(){
	for(int i=0; i<units; i++){
		weights[i] = weights[i] + Eta * weight_updates[i];
		weight_updates[i] = 0;
	}
}

void hidden_unit1::save(){
	//TODO

}

void hidden_unit1::load(){
	//TODO

}
