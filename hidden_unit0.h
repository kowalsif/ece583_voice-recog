#include "common.h"

class hidden_unit0{
	private:
		float* weights;
		float* weight_updates;
		float f(float);
	public:
		int units;
		
		hidden_unit0(int); //for training
		hidden_unit0(float*, int); //done traing, demonstrations
		~hidden_unit0();
		
		float net(float*); //evaluate
		void backPropogation(float,float); //send output and expected result back to hidden unit
		void update(); //perform batch update
		void save();
		void load();

};
	
