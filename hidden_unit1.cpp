#include "hidden_unit1.h"
#include "time.h"

using namespace std;

#define Beta 1.0
#define Eta 0.0001

hidden_unit1::hidden_unit1(int numUnits){
    srand (clock());
	units = numUnits;
	weights = (float*)malloc(sizeof(float)*(units));
	weight_updates = (float*)malloc(sizeof(float)*(units));
	for(int i=0; i<numUnits; i++){
		weights[i] = (rand()%100)/100.0;
		weight_updates[i] = 0;
	}
	for (int i = 0; i < 10000000; i++){ //delay for different rand nums
	}
	//weights[numUnits] = 1;
	//weight_updates[numUnits] = 1;
}

hidden_unit1::hidden_unit1(float* weights, int numUnits){
	this->weights = weights;
	units = numUnits;
	weight_updates = (float*)malloc(sizeof(float)*(units));
}

hidden_unit1::~hidden_unit1(){
	//cout << "hidden_unit1 deleted\n";
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
	z = (float) 1/(1+exp(-1*(Beta*sum)));
	return z;
}
float hidden_unit1::net(float* inputs){
	//sum inputs * weights
	sum = 0;
	for(int i=0; i<units; i++){
		sum += inputs[i] * weights[i];
	}
	//sum += weights[units];
	return f();
}

void hidden_unit1::backPropogation(float d, float y, float w2, float z1, int weightIndex){
	//cout << d << " " << y << " " << w2 << " " << z1 << " " << weightIndex << "\n";
	float a, b, c, e, f;
	a = (-1)*(d-y) * w2 * z1;
	b = exp(-1 * Beta * sum);
	c = Beta * b;
	e = (1 + b) * (1 + b);
	f = c/e;
	weight_updates[weightIndex] += a * f;
}

void hidden_unit1::update(){
	for(int i=0; i<units; i++){
		weights[i] = weights[i] - (Eta * weight_updates[i]);
		weight_updates[i] = 0;
	}
}

void hidden_unit1::save(){
	//TODO

}

void hidden_unit1::load(){
	//TODO

}

float hidden_unit1::getWeight(int index){
	return weights[index];
}

float hidden_unit1::getNet(){
	return sum;
}

float hidden_unit1::getZ(){
	return z;
}
