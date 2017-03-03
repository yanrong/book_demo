// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include <string.h>

#include <fstream>
//#include <cstring>
//#include <cstdio>
#include <string>

#include "stdafx.h"
#include "SoundTouchLib.h"

using namespace std;

#pragma  comment(lib,"SoundTouchLIB_CE.lib")

#define FLOAT_TYPE
#undef FLOAT_TYPE

#ifndef FLOAT_TYPE
#define PATH "E:\\GSM\\pstn start-2.wav"
#else
#define  PATH "E:\\Promises.wav"
#endif


template <typename T>
void write(std::ofstream& stream, const T& t) {
	stream.write((const char*)&t, sizeof(T));
}

/*****
** pack WAV header to naked PCM data & create a correspond file with specified file name(or path)
** outFile : assgined filename
** buf : PCM data buffer
** bufSize : PCM data buffer size
** sampleRate: audio data's Rate
** channels: audio data's channels
***/
template <typename SampleType>
void writeWAVData(const char* outFile, SampleType* buf, size_t bufSize,int sampleRate, short channels)
{
	std::ofstream stream(outFile, std::ios::binary);
	stream.write("RIFF", 4);
	write<int>(stream, 36 + bufSize);
	stream.write("WAVE", 4);
	stream.write("fmt ", 4);
	write<int>(stream, 16);
	write<short>(stream, 1);                                        // Format (1 = PCM)
	write<short>(stream, channels);                                 // Channels //mono/sterio
	write<int>(stream, sampleRate);
#ifdef FLOAT_TYPE
	write<int>(stream, sampleRate * channels * sizeof(float)); // Byterate
	write<short>(stream, channels * sizeof(float));            // Frame size
	write<short>(stream, 8 * sizeof(float));                   // Bits per sample
#else
	write<int>(stream, sampleRate * channels * sizeof(SampleType)); // Byterate
	write<short>(stream, channels * sizeof(SampleType));            // Frame size
	write<short>(stream, 8 * sizeof(SampleType));                   // Bits per sample
#endif
	stream.write("data", 4);
	unsigned int sz = bufSize;
	stream.write((const char*)&sz, 4);
	stream.write((const char*)buf, bufSize);
}

/****
** Read the data from a given file to buffer with bufSize bytes.
** inFile : read data from giving file name.
** buf : to store data read from inFile.
** return how many number sample has been read from file(not bytes !!)
***/

int writeBuff(const char* inFile, short *buf, int bufSize)///,int numElems)
{
	if (!buf || !bufSize){ /// no buffer or size is zero ,just quit
		printf("buff is empty, can not write to assigned buffer %s--------%d"\
			, __FUNCTION__, __LINE__);
		return -1;
	}

	FILE *fptr = fopen(inFile, "rb"); //read file as binary file(important)
	if (!fptr){
		printf("cant not open output file, FAILED!!!! %s--------%d"\
			, __FUNCTION__, __LINE__);
		return -1;
	}
	///Initial buffer value to zero
	memset(buf, 0, bufSize);
	fseek(fptr, 44L, SEEK_SET); /// skip WAV header file
	int len = fread(buf, 1, bufSize, fptr); //read wav file data field(PCM)
	if (len <= 0){
		printf("no more data read from wav file. \n");
		return -1;
	}
	fclose(fptr);

	return len;
}


int main(int argc, char* argv[])
{
	/*******************get a buffer (just for emulating)*********************/
	FILE *fhandle = fopen(PATH, "rb");
	if (!fhandle){
		printf("error!\n");
		return 0;
	}

	fseek(fhandle, 0, SEEK_END); // seek to end of file
	int bufSize = ftell(fhandle); // get current file pointer

	fseek(fhandle, 0, SEEK_SET); // seek back to beginning of file
	fclose(fhandle);

	//omitted head file(total 44 bytes)
	bufSize = bufSize - 44;

	//get buffer
	short* buf = new short[bufSize];
	/**************************end*************************************/
	
	writeBuff(PATH, buf, bufSize);

	FILE *f = fopen("stream", "wb");
	fwrite(buf, 1, bufSize, f);
	fclose(f);
	writeWAVData<short>("callBusy-stream.wav", buf, bufSize, 44100, 1);

	HANDLE handle;
	handle = soundtouch_createInstance();

	soundtouch_setPitchSemiTones(handle, 3);
	soundtouch_setChannels(handle, 1);
	soundtouch_setSampleRate(handle, 44100);
	soundtouch_setSetting(handle);
	
	FILE *f2 = fopen(PATH, "rb");
	if (!f2) return -1;
	fseek(f2, 44L, SEEK_SET);
	const size_t chunkSize = 3528;
	int k = 0;
	int i = 41;
	short* pChunk = new short[chunkSize];
	FILE *temp = fopen("chunk","wb+");
	while (!feof(f2))
	{
		memset(pChunk, 0, chunkSize);
		int num = fread(pChunk, 1, chunkSize, f2);
		//memset(pChunk, 0, chunkSize);
		//memcpy(pChunk, buf + (k/2), chunk);
		printf("\nfread num = %d", num);
		
		soundtouch_process(handle, pChunk, num);
	
		fwrite(pChunk, 1, num, temp);
		memcpy(buf + k / 2, pChunk, num);
		k += num;
		printf("\nfread k = %d\n", k);//soundtouch_destroyInstance(handle);
	}
	fclose(temp);
	//soundtouch_process(handle, buf, bufSize);
	writeWAVData<short>("callBusy-pack.wav", buf, bufSize, 44100, 1);
	
	//fclose(f2);

	
	
	delete[]pChunk;
	delete []buf;
	return 0;
}

