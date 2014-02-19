#include "main.h"

#include <iostream>
#include <fstream>

#define SAMPLING_RATE 44100
#define BIT_RATE  721920 //705
//#define path "c:\\Users\\dohertjp\\Documents\\Courses\\ECE583\\Voice Database\\sounds\\1name1.wav"
#define path "C:\\Users\\kowalsif\\Desktop\\pattern recognition\\voice\\spectrum.txt"


using namespace std;

int main(int argc, char* argv[]){

	char filename[350];
	BYTE *sound_buffer;
	//BYTE* data_buffer;
	BYTE* freq_buffer;
	int data_buffer[61];
	DWORD length;

	int mode = atoi(argv[1]);
	
	sprintf(filename, path);
	float temp0[16];

	//C:\Users\dohertjp\Documents\Courses\ECE583\Voice Database\sounds
	readFourier(filename, temp0);

	for (int i = 0; i < 16; i++){
		cout << temp0[i] << endl;
	}
	//length = readWAV(filename, sound_buffer);

}


void readFourier(char* filename, float* buckets){
	FILE *fp;

	fp = fopen(filename, "rb");
	std::fstream myfile("C:\\Users\\kowalsif\\Desktop\\pattern recognition\\voice\\spectrum.txt", std::ios_base::in);
	
	if (fp){
		//float a;
		char b; //22
		for (int i = 0; i < 22; i++){
			myfile >> b;
		}

		float freq[256];
		float db[256];
		int count = 0;
    	
    	while (myfile >> freq[count]) // will be an even number
    	{
        	myfile >> db[count];
        	count++;
    	}
		//cout << count << endl;
		//float buckets[16]; //1375 range per bucket
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



