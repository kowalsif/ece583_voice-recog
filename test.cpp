#include "main.h"

using namespace std;

void hidden_unit0_input_test(void);
void hidden_unit1_input_test(void);

int main(int argc, char* argv[]){
	cout << "Test begin\n";
	hidden_unit0_input_test();
	hidden_unit1_input_test();
	cout << "Test end\n";
	return 0;
}

void hidden_unit0_input_test(){
	float input[1];
	input[0] = 1.0;
	hidden_unit0 hidden0(1);
	if((hidden0.net(input) - 0.731059) < 0.000001){
		cout << "hidden_unit0_input_test part 1 - PASS\n";
	} else {
		cout << "hidden_unit0_input_test part 1 - FAIL\n";
	}
	input[0] = 0.0;
	if(hidden0.net(input) == 0.5){
		cout << "hidden_unit0_input_test part 2 - PASS\n";
	} else {
		cout << "hidden_unit0_input_test part 2 - FAIL\n";
	}
}

void hidden_unit1_input_test(){
	float input[1];
	input[0] = 1.0;
	hidden_unit1 hidden1(1);
	if((hidden1.net(input) - 0.731059) < 0.000001){
		cout << "hidden_unit1_input_test part 1 - PASS\n";
	} else {
		cout << "hidden_unit1_input_test part 1 - FAIL\n";
	}
	input[0] = 0.0;
	if(hidden1.net(input) == 0.5){
		cout << "hidden_unit1_input_test part 2 - PASS\n";
	} else {
		cout << "hidden_unit1_input_test part 2 - FAIL\n";
	}
}