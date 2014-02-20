#include "common.h"

class hidden_unit1{
	private:
		float* weights;
		float* weight_updates;
		float f();
		float sum;
		float z;
	public:
		int units;
		
		hidden_unit1(int); //for training
		hidden_unit1(float*, int); //done training, demonstrations
		~hidden_unit1();
		
		float net(float*); //evaluate
		void backPropogation(float, float, float, float, int); //send output and expected result back to hidden unit
		void update(); //perform batch update
		void save();
		void load();
		float getWeight(int);
		float getNet();
		float getZ();
};
	
