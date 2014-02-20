#include "main.h"

#define SAMPLING_RATE 44100
#define BIT_RATE  721920 //705
//#define path "c:\\Users\\dohertjp\\Documents\\Courses\\ECE583\\Voice Database\\sounds\\1name1.wav"
#define path "C:\\Users\\kowalsif\\Desktop\\pattern recognition\\voice\\spectrum.txt"

#define path2 "C:\\Users\\kowalsif\\Desktop\\sounds\\%d%c%d.txt"


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
	float buckets[16];

	//C:\Users\dohertjp\Documents\Courses\ECE583\Voice Database\sounds
	readFourier(filename, buckets);
	hidden_unit0 *hidden0;
	hidden0 = (hidden_unit0*) malloc(sizeof(hidden_unit0)*16);
	hidden_unit1 *hidden1;
	hidden1 = (hidden_unit1*) malloc(sizeof(hidden_unit1)*16);
	output_unit *output;
	output = (output_unit*) malloc(sizeof(output_unit)*2);
	//hidden0(16);
	for (int i = 0; i < 16; i++){
		cout << "generate" << endl;
		hidden0[i] = hidden_unit0(16);
		hidden1[i] = hidden_unit1(16);
	}
	for (int i = 0; i < 2; i++){
		output[i] = output_unit(16);
	}
//	hidden_unit0 hidden0(16);
//	hidden_unit1 hidden1(16);
//	output_unit output(16);
/*
	float d = 1;
	for (int i = 1; i <= 10; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 1; k <= 3; k++){
				cout << "running" << endl;
				float net0b, net1b, out;
				float z1[16];
				float z2[16];
				float y[16];
				sprintf(filename, path2, i, allexp[j], k);
				readFourier(filename, buckets);
				//send it in for an answer
				for (int l = 0; l < 16; l++){
					z1[l] =  hidden0[l].net(buckets);
				} 
				for (int l = 0; l < 16; l++){
					z2[l] = hidden1[l].net(z1);
				}
				for (int l = 0; l < 2; l++){
					y[l] = output[l].net(z2);
					//output[l].getWeight(1);
				}

				//propagation to rebalance
				//h1

				for (int m = 0; m < 2; m++){
					for (int n = 0; n < 16; n++){
						output[m].backPropogation(d, y[m], z2[n], n);
					}
				}

				//h0
				for (int m = 0; m < 16; m++){
					for (int n = 0; n < 16; n++){
						for (int o = 0; o < 2; o++){
							float w2 = output[o].getWeight(n);
							hidden1[m].backPropogation(d, y[o], w2, z1[n], n);
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
								hidden0[m].backPropogation(d, y[o], w2, w1, net2, buckets[p], p);
							}
						}
					}
				}

			}
		}
	}	
	//initialize the system

*/

	//kill the system
	for (int i = 0; i < 16; i++){
		delete hidden0;
		delete hidden1;
	}
	for (int i = 0; i < 2; i++){
		delete output;
	}
	
	
	//length = readWAV(filename, sound_buffer);
}


void readFourier(char* filename, float* buckets){
	FILE *fp;

	fp = fopen(filename, "rb");
	std::fstream myfile(filename, std::ios_base::in);

	//cout << filename << endl;
	
	if (fp){
		cout << "file read" << endl;
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
		int bucket = 0;
    	for (int i = 0; i < count; i++){
    		if (freq[i] > (bucket + 1)*1375){
    			buckets[bucket] = buckets[bucket]/bucketstore;
				bucket++;
				bucketstore = 0;
    		}
    		bucketstore++;
    		buckets[bucket] += db[i];
			//cout << freq[i] << "   " << db[i] << endl;
    	}
		buckets[bucket] = buckets[bucket]/bucketstore;
		
    	//return buckets;
	}
	else {
		cout << "read failed, try again" << endl;
	}

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



