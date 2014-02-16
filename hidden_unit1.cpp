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
	}
}

hidden_unit1::hidden_unit1(float* weights, int numUnits){
	this->weights = weights;
	units = numUnits;
	weight_updates = (float*)malloc(sizeof(float)*units);
}

float hidden_unit1::f(float net){
	return (float) 1/(1+exp(-1*(Beta*net)));
}
float hidden_unit1::net(float* inputs){
	//sum inputs * weights
	float sum = 0;
	for(int i=0; i<UNITS; i++){
		sum += inputs[i] * weights[i];
	}
	return f(sum);
}

void hidden_unit1::backPropogation(float output, float expected){
	//TODO
	for(int i=0; i<units; i++){
		weight_updates[i] += 1;//DERIVATIVES;
	}
}

void hidden_unit1::update(){
	for(int i=0; i<units; i++){
		weights[i] = weights[i] + Eta * weight_updates[i];
	}
}

void hidden_unit1::save(){
	//TODO

}

void hidden_unit1::load(){
	//TODO

}
