#include <stdio>
#include <stdlib>
#include <iostream>
#include <math.h>

class hidden_unit1{
	private:
		float weights[UNITS];
		float f(float);
	public:
		int units;
		
		hidden_unit1(void); //for training
		hidden_unit1(float[]); //done traing, demonstrations
		
		float net(float[]); //evaluate
		void backPropogation(float,float); //send output and expected result back to hidden unit
		void update(); //perform batch update
		void save();
		void read();

} hidden1;
	
