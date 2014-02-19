#include "main.h"

using namespace std;

int hidden_unit0_input_test(void);
int hidden_unit1_input_test(void);
int output_unit_input_test(void);
void simple_network_test(void);

int main(int argc, char* argv[]){
	int results;
	cout << "Test begin\n";
	results = hidden_unit0_input_test();
	if(results){
		cout << "TESTS FAILED!\n";
		return 1;
	}
	results = hidden_unit1_input_test();
	if(results){
		cout << "TESTS FAILED!\n";
		return 1;
	}
	results = output_unit_input_test();
	if(results){
		cout << "TESTS FAILED!\n";
		return 1;
	}
	//simple_network_test();
	cout << "Test end\n";
	return 0;
}

int hidden_unit0_input_test(){
	int ret = 0;
	float input[1];
	input[0] = 1.0;
	hidden_unit0 hidden0(1);
	if((hidden0.net(input) - 0.731059) < 0.000001){
		cout << "hidden_unit0_input_test part 1 - PASS\n";
	} else {
		cout << "hidden_unit0_input_test part 1 - FAIL\n";
		ret = 1;
	}
	input[0] = 0.0;
	if(hidden0.net(input) == 0.5){
		cout << "hidden_unit0_input_test part 2 - PASS\n";
	} else {
		cout << "hidden_unit0_input_test part 2 - FAIL\n";
		ret = 1;
	}
	return ret;
}

int hidden_unit1_input_test(){
	int ret = 0;
	float input[1];
	input[0] = 1.0;
	hidden_unit1 hidden1(1);
	if((hidden1.net(input) - 0.731059) < 0.000001){
		cout << "hidden_unit1_input_test part 1 - PASS\n";
	} else {
		cout << "hidden_unit1_input_test part 1 - FAIL\n";
		ret = 1;
	}
	input[0] = 0.0;
	if(hidden1.net(input) == 0.5){
		cout << "hidden_unit1_input_test part 2 - PASS\n";
	} else {
		cout << "hidden_unit1_input_test part 2 - FAIL\n";
		ret = 1;
	}
	return ret;
}

int output_unit_input_test(){
	int ret = 0;
	float input[1];
	input[0] = 1;
	output_unit output(1);
	if((output.net(input) - 1) < 0.00001){
		cout << "output_unit_input_test part 1 - PASS\n";
	} else {
		cout << "output_unit_input_test part 1 - FAIL\n";
		ret = 1;
	}
	input[0] = 0.0;
	if(output.net(input) < 0.00001){
		cout << "output_unit_input_test part 1 - PASS\n";
	} else {
		cout << "output_unit_input_test part 1 - FAIL\n";
		ret = 1;
	}
	return ret;
}

void simple_network_test(){
	hidden_unit0 layer1(1);
	hidden_unit1 layer2(1);
	output_unit layer3(1);
	float x[2],z1[2],z2]2],y,d,J=100;
	int count = 0;
	while(J > 1){
		x[0] = 1;
		z1[0] = 1;
		z2[0] = 1;
		x[1] = 1;
		d = 0;
		z1 = layer1.net(x);
		z2 - layer2.net(z1);
		y = layer3.net(z2);
		J = 0.5*(d-y)*(d-y);
		layer3.backPropogation(y,d);
		layer2.backPropogation(y,d);
		layer1.backPropogation(y,d);
		x[1] = 0;
		d = 1;
		z1 = layer1.net(x);
		z2 - layer2.net(z1);
		y = layer3.net(z2);
		J = 0.5*(d-y)*(d-y);
		layer3.backPropogation(y,d);
		layer2.backPropogation(y,d);
		layer1.backPropogation(y,d);
		layer1.update();
		layer2.update();
		layer3.update();
	}
	cout << "simple test completed in " << count << " iterations.\n";
}
		
	