#include "common.h"



class match{
	private:
		float* buckets;
		float* var;
		int units;
		int times;

	public:
		match();
		match(int);
		void update(float*, float*);
		void up(float*, float*);
		~match();
		float compare(float*);
		void printer();

};
