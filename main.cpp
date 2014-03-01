#include "main.h"
//#include "hidden_unit0.h"
//#include "hidden_unit1.h"
//#include "output_unit.h"
//#include "match.h"

#define SAMPLING_RATE 44100
#define BIT_RATE  721920 //705
//#define path "c:\\Users\\dohertjp\\Documents\\Courses\\ECE583\\Voice Database\\sounds\\1name1.wav"
#define path "C:\\Users\\kowalsif\\Desktop\\pattern recognition\\voice\\spectrum.txt"

#define path2 "C:\\Users\\kowalsif\\Desktop\\sounds\\%d%c%d.txt"
//#define path2 "C:\\Users\\dohertjp\\Downloads\\transformDatabase\\fourier\\%d%c%d.txt"


using namespace std;

int main(int argc, char* argv[]){

	char filename[350];
	//BYTE *sound_buffer;
	//BYTE* data_buffer;
	//BYTE* freq_buffer;
	//int data_buffer[61];
	//DWORD length;

	//int mode = atoi(argv[1]);
	char allexp[] = "nap";
	
	
	//sprintf(filename, path2, 1, allexp[0], 1);
	
	//cout << filename << endl;
	float buckets[16]; //687.5
	float var[32];

	//C:\Users\dohertjp\Documents\Courses\ECE583\Voice Database\sounds
	//readFourier(filename, buckets);

	hidden_unit0 *hidden0;
	hidden0 = (hidden_unit0*) malloc(sizeof(hidden_unit0)*16);
	hidden_unit0 h0(16);
	hidden0[0] = h0;
	hidden_unit0 h1(16);
	hidden0[1] = h1;
	hidden_unit0 h2(16);
	hidden0[2] = h2;
	hidden_unit0 h3(16);
	hidden0[3] = h3;
	hidden_unit0 h4(16);
	hidden0[4] = h4;
	hidden_unit0 h5(16);
	hidden0[5] = h5;
	hidden_unit0 h6(16);
	hidden0[6] = h6;
	hidden_unit0 h7(16);
	hidden0[7] = h7;
	hidden_unit0 h8(16);
	hidden0[8] = h8;
	hidden_unit0 h9(16);
	hidden0[9] = h9;
	hidden_unit0 h10(16);
	hidden0[10] = h10;
	hidden_unit0 h11(16);
	hidden0[11] = h11;
	hidden_unit0 h12(16);
	hidden0[12] = h12;
	hidden_unit0 h13(16);
	hidden0[13] = h13;
	hidden_unit0 h14(16);
	hidden0[14] = h14;
	hidden_unit0 h15(16);
	hidden0[15] = h15;
	
	//hidden0[1] =  hidden_unit0(16);
	//hidden_unit0 hidden0[16];
	hidden_unit1 *hidden1;
	hidden1 = (hidden_unit1*) malloc(sizeof(hidden_unit1)*16);
	hidden_unit1 c0(16);
	hidden1[0] = c0;
	hidden_unit1 c1(16);
	hidden1[1] = c1;
	hidden_unit1 c2(16);
	hidden1[2] = c2;
	hidden_unit1 c3(16);
	hidden1[3] = c3;
	hidden_unit1 c4(16);
	hidden1[4] = c4;
	hidden_unit1 c5(16);
	hidden1[5] = c5;
	hidden_unit1 c6(16);
	hidden1[6] = c6;
	hidden_unit1 c7(16);
	hidden1[7] = c7;
	hidden_unit1 c8(16);
	hidden1[8] = c8;
	hidden_unit1 c9(16);
	hidden1[9] = c9;
	hidden_unit1 c10(16);
	hidden1[10] = c10;
	hidden_unit1 c11(16);
	hidden1[11] = c11;
	hidden_unit1 c12(16);
	hidden1[12] = c12;
	hidden_unit1 c13(16);
	hidden1[13] = c13;
	hidden_unit1 c14(16);
	hidden1[14] = c14;
	hidden_unit1 c15(16);
	hidden1[15] = c15;

	output_unit *output;
	output = (output_unit*) malloc(sizeof(output_unit)*2);
	output_unit d0(16);
	output[0] = d0;
	output_unit d1(16);
	output[1] = d1;
	//hidden0(16);
	//for (int i = 0; i < 16; i++){
		//cout << "generate" << endl;
		//hidden0[i] =  hidden_unit0(16);
		//hidden1[i] = hidden_unit1(16);
	//}
	//for (int i = 0; i < 2; i++){
		//output[i] = output_unit(16);
	//}
//	hidden_unit0 hidden0(16);
//	hidden_unit1 hidden1(16);
//	output_unit output(16);

	float d[3];
	d[0] = 1;
	d[1] = -1;
	d[2] = 1;
	float J;
	//for(int iterations = 0; iterations < 100; iterations++){
	for (int np = 0; np < 3; np++){ //10
		for (int i = 1; i <= 1; i++){ //alternate between intruder and not //5
			for (int j = 0; j < 1; j++){ //2
				for (int k = 1; k <= 5; k++){ //5
					float net0b, net1b, out;
					float z1[16];
					float z2[16];
					float y[3];
					//z1[16] = 1;
					//z2[16] = 1;
					sprintf(filename, path2, i, allexp[j], k);
					readFourier(filename, buckets);
					printf("iteration: %d ", i);
					//cout << buckets[0] << endl;
					//send it in for an answer
					for (int l = 0; l < 16; l++){
						printf(" b%d: %f ", l, buckets[l]);
						z1[l] =  hidden0[l].net((buckets));
						printf("z1: %f ", y[l]);
						//cout << " results: " << hidden0[l].getWeight(0);
					} 
					//cout << endl;
					for (int l = 0; l < 16; l++){
						z2[l] = hidden1[l].net(z1);
						//printf("z2: %f ", y[l]);
						cout << " results: " << z2[l];
						//cout << " results: " << hidden1[l].getWeight(0);
					}
					for (int l = 0; l < 2; l++){
						y[l] = output[l].net(z2);
						//printf("y: %f ", y[l]);
						//output[l].getWeight(1);
					}
					printf("\n\n");

					//propagation to rebalance
					//h1
				
					for (int m = 0; m < 2; m++){
						for (int n = 0; n < 16; n++){
							output[m].backPropogation(y[m], d[i%2 + m], z2[n], n);
						}
					}

					//h0
					for (int m = 0; m < 16; m++){
						for (int n = 0; n < 16; n++){
							for (int o = 0; o < 2; o++){
								float w2 = output[o].getWeight(n);
								hidden1[m].backPropogation(y[o], d[i%2 + o], w2, z1[n], n);
							}
						}
					}
					//input
					for (int m = 0; m < 16; m++){
						for (int n = 0; n < 16; n++){
							float w1 = hidden1[n].getWeight(m);
							float net2 = hidden1[n].getNet();
							for (int o = 0; o < 2; o++){
								float w2 = output[o].getWeight(n);
								for (int p = 0; p < 16; p++){
									hidden0[m].backPropogation(y[o], d[i%2 + o], w2, w1, net2, buckets[p], p);
								}
							}
						}
					}
				}
			}
		}	
	//}
		for (int m = 0; m < 16; m++){
			hidden0[m].update();
			hidden1[m].update();
		}
		for (int m = 0; m < 2; m++){
			output[m].update();
		}
	}
	
/*	//initialize the system
	float z1[16];
	float z2[16];
	float y[2];
    sprintf(filename, path2, 5, allexp[1], 5);
	readFourier(filename, buckets);
	cout << buckets[0] << endl;
	for (int l = 0; l < 16; l++){
		z1[l] =  hidden0[l].net(buckets);
	} 
	for (int l = 0; l < 16; l++){
		z2[l] = hidden1[l].net(z1);
	}
	for (int l = 0; l < 2; l++){
		y[l] = output[l].net(z2);
	}

	cout << "y0: " << y[0] << " y1: " << y[1] << endl;


	sprintf(filename, path2, 1, allexp[0], 1);
	readFourier(filename, buckets);
	cout << buckets[0] << endl;
	for (int l = 0; l < 16; l++){
		z1[l] =  hidden0[l].net(buckets);
	} 
	for (int l = 0; l < 16; l++){
		z2[l] = hidden1[l].net(z1);
	}
	for (int l = 0; l < 2; l++){
		y[l] = output[l].net(z2);
	}
*/
//	cout << "y0: " << y[0] << " y1: " << y[1] << endl;
	//kill the system
	//for (int i = 0; i < 16; i++){
		//delete &hidden0[i];
		//delete &hidden1[i];
	//}
	//for (int i = 0; i < 2; i++){
		//delete &output[i];
	//}

	free(hidden0);
	free(hidden1);
	free(output);

	
	//return -1;
	//length = readWAV(filename, sound_buffer);
}


void readFourier(char* filename, float* buckets){
	FILE *fp;

	fp = fopen(filename, "rb");
	std::fstream myfile(filename, std::ios_base::in);

	//cout << filename << endl;
	
	if (fp){
		//cout << "file read" << endl;
		//float a;
		char b; //22
		for (int i = 0; i < 22; i++){
			myfile >> b;
		}

		float freq[512];
		float db[512];
		int count = 0;
    	
    	while (myfile >> freq[count]) // will be an even number
    	{
        	myfile >> db[count];
        	count++;
    	}

    	myfile.close();
		int bucketstore = 0;
		for (int i = 0; i < 16; i++){
			buckets[i] = 0;
		}
		int min = 1000;
		int max = -1000;
		int bucket = 0;
    	for (int i = 0; i < count; i++){
    		if (freq[i] > (bucket + 1)*1250){
    			buckets[bucket] = buckets[bucket]/bucketstore;
    			//var[bucket] = sqrt(min*min + max*max)/bucketstore;
				bucket++;
				bucketstore = 0;
				min = 1000;
				max = -1000;
    		}
    		bucketstore++;
    		buckets[bucket] += db[i];
    		if (min > db[i]){
				min = db[i];
    		}
    		if (max < db[i]){
				max = db[i];
    		}
			//cout << freq[i] << "   " << db[i] << endl;
    	}

		buckets[bucket] = buckets[bucket]/bucketstore;
		//var[bucket] = sqrt(min*min + max*max)/bucketstore;
    	//return buckets;
	}
	else {
		cout << "read failed, try again" << endl;
	}
	//for (int i = 0; i < 16; i++){
	//	printf(" bucket: %f ", buckets[i]);
	//}
	fclose(fp);
}


DWORD readWAV(char* filename, BYTE *sound_buffer){
	//http://www.cpp-home.com/tutorials/333_1.htm
	FILE *fp;
	
	fp = fopen(filename, "rb");
	if(fp)
	{
		char id[5]; //four bytes to hold 'RIFF'
		DWORD size; //32 bit balue to hold file size
		short format_tag, channels, block_align, bits_per_sample;
		DWORD format_length, sample_rate, avg_bytes_sec, data_size;
		
		id[4] = '\0'; //add string termination
		
		fread(id,sizeof(BYTE),4,fp); //read in first four bytes
		cout << id << endl;
		if(!strcmp(id,"RIFF")){
			fread(&size,sizeof(DWORD),1,fp); //read in 32bit size value
			fread(id,sizeof(BYTE),4,fp); //read in 4 byte string
			if(!strcmp(id,"WAVE")){
				fread(id,sizeof(BYTE),4,fp); //read in 4 bytes "fmt "
				fread(&format_length, sizeof(DWORD),1,fp);
				fread(&format_tag,sizeof(short),1,fp);
				fread(&channels,sizeof(short),1,fp);
				fread(&sample_rate,sizeof(DWORD),1,fp);
				fread(&avg_bytes_sec,sizeof(short),1,fp);
				fread(&block_align,sizeof(short),1,fp);
				fread(&bits_per_sample,sizeof(short),1,fp);
				fread(&data_size,sizeof(DWORD),1,fp);//how many bytes of sound data we have
				sound_buffer = (BYTE *) malloc(sizeof(BYTE) * data_size); //define buffer space
				fread(sound_buffer,sizeof(BYTE),data_size,fp); //read in data chunk
				printf("Sampling rate: %d\n", sample_rate);
				return data_size;
			} else {
				printf("Error: RIFF file but not a wave file\n");
			}
		} else {
			printf("Error: not a RIFF file\n");
		}
	} else {
		printf("Error: could not open file\n");
		cout << "could not open file\n";
	}
	
	return 0;
}

//read in multiple wave files and put them in a database
//wav array of wave vectors
//lens array of lengths
void readDatabase(BYTE** wav, DWORD* lens){
	//TODO
}



