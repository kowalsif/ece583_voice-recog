#include "output_unit.h"
#include "time.h"

using namespace std;

#define Beta 1.0
#define Eta 0.0001


output_unit::output_unit(int numUnits){
	srand(clock());
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
	//weight_updates[numUnits] = 0;
}

output_unit::output_unit(float* weights, int numUnits){
	this->weights = weights;
	units = numUnits;
	weight_updates = (float*)malloc(sizeof(float)*(units+1));
}

output_unit::~output_unit(){
	//cout << "output_unit deleted\n";
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
	for(int i=0; i<units; i++){
		sum += inputs[i] * weights[i];
	}
	//sum += weights[units];
	//y = sum;
	return sum;
}

void output_unit::backPropogation(float y, float d, float z2, int weightIndex){
	//cout << y << " " << d << " " << z2 << "\n";
	weight_updates[weightIndex] += -1 * (d-y)*z2;
}

void output_unit::update(){
	for(int i=0; i<units; i++){
		weights[i] = weights[i] - (Eta * weight_updates[i]);
		weight_updates[i] = 0;
	}
}

void output_unit::save(){
	//TODO

}

void output_unit::load(){
	//TODO

}

float output_unit::getWeight(int index){
	return weights[index];
}

float output_unit::getY(){
	return y;
}
