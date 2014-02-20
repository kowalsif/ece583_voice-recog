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
	float temp0[16];

	//C:\Users\dohertjp\Documents\Courses\ECE583\Voice Database\sounds
	readFourier(filename, temp0);
	hidden_unit0 *hidden0;
	hidden0 = (hidden_unit0*) malloc(sizeof(hidden_unit0)*16);
	hidden_unit1 *hidden1;
	hidden1 = (hidden_unit1*) malloc(sizeof(hidden_unit1)*16);
	output_unit *output;
	output = (output_unit*) malloc(sizeof(output_unit)*2);
	//hidden0(16);
	for (int i = 0; i < 16; i++){
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
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 6; k++){
				float net0b, net1b, out;
				float z1[16];
				float z2[16];
				float y[16];
				sprintf(filename, path2, i, allexp[j], k);
				readFourier(filename, temp0);
				for (int l = 0; l < 16; l++){
					z1[l] =  hidden0.net(buckets);
				} 
				for (int l = 0; l < 16; l++){
					z2[l] = hidden1.net(z1[l]);
				}
				for (int l = 0; l < 16; l++){
					y[l] = output.net(z1[l]);
				}
				//net0 = hidden0.net(buckets);
				//net1 = hidden1.net(net0);
				//out = output.net(net1);

				//output.backPropagation(out, 1);
				//hidden1.backPropagation(1, out, );
			}
		}
	}
	*/

	for (int i = 0; i < 16; i++){
		cout << temp0[i] << endl;
	}
	
	//initialize the system

	
	
	//length = readWAV(filename, sound_buffer);

}


void readFourier(char* filename, float* buckets){
	FILE *fp;

	fp = fopen(filename, "rb");
	std::fstream myfile(filename, std::ios_base::in);

	cout << filename << endl;
	
	if (fp){
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



