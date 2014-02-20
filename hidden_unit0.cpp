#include "hidden_unit0.h"

using namespace std;

#define Beta 1.0
#define Eta 0.0001


hidden_unit0::hidden_unit0(int numUnits){
	units = numUnits;
	weights = (float*)malloc(sizeof(float)*(units));
	weight_updates = (float*)malloc(sizeof(float)*(units));
	for(int i=0; i<numUnits; i++){
		weights[i] = 1;
		weight_updates[i] = 0;
	}
	//weights[numUnits] = 1;
	//weight_updates[numUnits] = 0;
}

hidden_unit0::hidden_unit0(float* weights, int numUnits){
	this->weights = weights;
	units = numUnits;
	weight_updates = (float*)malloc(sizeof(float)*(units));
}

hidden_unit0::~hidden_unit0(){
	//cout << "hidden_unit0 deleted\n";
	if(weights){
		free(weights);
		weights = NULL;
	}
	if(weight_updates){
		free(weight_updates);
		weight_updates = NULL;
	}
}

float hidden_unit0::f(float net){
	z = (float) 1/(1+exp(-1*(Beta*sum)));
	return z;
}
float hidden_unit0::net(float* inputs){
	//sum inputs * weights
	sum = 0;
	for(int i=0; i<units; i++){
		sum += inputs[i] * weights[i];
	}
	//sum += weights[units];
	return f(sum);
}

void hidden_unit0::backPropogation(float d, float y, float w2, float w1, float net2, float x, int weightIndex){
	//cout << d << " " << y << " " << w2 << " " << w1 << " " << net2 << " " << x << "\n";
	float a,b,c,e,f,g,h,i,j;
	a = exp(-Beta*net2);
	b = exp(-Beta*sum);
	c = -1*(d-y)*w2*w1*x;
	e = (1+a)*(1+a);
	f = Beta * a;
	g = f / e;
	h = Beta * b;
	i = (1+b)*(1+b);
	j = h/i;
	weight_updates[weightIndex] += c*g*j;
}

void hidden_unit0::update(){
	for(int i=0; i<units; i++){
		weights[i] = weights[i] - (Eta * weight_updates[i]);
		weight_updates[i] = 0;
	}
}

void hidden_unit0::save(){
	//TODO

}

void hidden_unit0::load(){
	//TODO

}

float hidden_unit0::getWeight(int index){
	return weights[index];
}

float hidden_unit0::getNet(){
	return sum;
}

float hidden_unit0::getZ(){
	return z;
}
