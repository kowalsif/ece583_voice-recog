#include <stdio>
#include <stdlib>
#include <iostream>

class hidden_unit0{
	private:
		float weights[UNITS];
		float f(float);
	public:
		int units;
		
		hidden_unit0(void); //for training
		hidden_unit0(float[]); //done traing, demonstrations
		
		float net(float[]); //evaluate
		void update(float); //update the method
		void save();
		void read();

} hidden0;
	
