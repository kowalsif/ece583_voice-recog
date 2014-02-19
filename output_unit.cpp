#include "output_unit.h"

using namespace std;

#define Beta 1.0
#define Eta 0.001


output_unit::output_unit(int numUnits){
	units = numUnits;
	weights = (float*)malloc(sizeof(float)*units);
	weight_updates = (float*)malloc(sizeof(float)*units);
	for(int i=0; i<numUnits; i++){
		weights[i] = 1;
	}
}

output_unit::output_unit(float* weights, int numUnits){
	this->weights = weights;
	units = numUnits;
	weight_updates = (float*)malloc(sizeof(float)*units);
}

output_unit::~output_unit(){
	cout << "output_unit deleted\n";
	if(weights){
		free(weights);
		weights = NULL;
	}
	if(weight_updates){
		free(weight_updates);
		weight_updates = NULL;
	}
}


float output_unit::net(float* inputs){
	//sum inputs * weights
	float sum = 0;
	for(int i=0; i<UNITS; i++){
		sum += inputs[i] * weights[i];
	}
	return sum;
}

void output_unit::backPropogation(float output, float expected){
	//TODO
	for(int i=0; i<units; i++){
		weight_updates[i] += 1;//DERIVATIVES;
	}
}

void output_unit::update(){
	for(int i=0; i<units; i++){
		weights[i] = weights[i] + Eta * weight_updates[i];
	}
}

void output_unit::save(){
	//TODO

}

void output_unit::load(){
	//TODO

}
