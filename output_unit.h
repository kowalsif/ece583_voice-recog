#include "common.h"

class output_unit{
	private:
		float* weights;
		float* weight_updates;
	public:
		int units;
		
		output_unit(int); //for training
		output_unit(float*, int); //done traing, demonstrations
		~output_unit();
		
		float net(float*); //evaluate
		void backPropogation(float,float); //send output and expected result back to hidden unit
		void update(); //perform batch update
		void save();
		void load();
};
	
