#include <stdexcept>
#include <stdio.h>
#include <string.h>

#include "SoundTouchLib.h"
#include "include/SoundTouch.h"

using namespace soundtouch;
using namespace std;

// Processing chunk size (size chosen to be divisible by 2, 4, 6, 8, 10, 12, 14, 16 channels ...)
//#define BUFF_SIZE           1024

#if _WIN32
#include <io.h>
#include <fcntl.h>

// Macro for Win32 standard input/output stream support: Sets a file stream into binary mode
#define SET_STREAM_TO_BIN_MODE(f) (_setmode(_fileno(f), _O_BINARY))
#else
// Not needed for GNU environment...
#define SET_STREAM_TO_BIN_MODE(f) {}
#endif

static int channels = 0;

static inline int getChannels()
{
	return channels;
}

HANDLE  soundtouch_createInstance()
{
	SoundTouch *p = new SoundTouch;
	return p;
}

/// Destroys a SoundTouch processor instance.
void  soundtouch_destroyInstance(HANDLE h)
{
	if (h != NULL){
		delete h;
		h = NULL;
	}
}

/// Sets pitch change in semi-tones compared to the original pitch
/// (-12 .. +12);
void  soundtouch_setPitchSemiTones(HANDLE h, float newPitch)
{
	SoundTouch *pst = (SoundTouch*)h;
	if (pst == NULL || newPitch == 0)
	{
		printf("error for set pitch\n");
		return;
	}
	pst->setPitchSemiTones(newPitch);
}

/// Sets the number of channels, 1 = mono, 2 = stereo
void  soundtouch_setChannels(HANDLE h, unsigned int numChannels)
{
	SoundTouch *pst = (SoundTouch *)h;
	if (pst == NULL)
	{
		printf("error for set channels\n");
		return;
	}
	pst->setChannels(numChannels);
	channels = numChannels;
}

/// Sets sample rate.
void  soundtouch_setSampleRate(HANDLE h, unsigned int srate)
{
	SoundTouch *pst = (SoundTouch *)h;
	if (pst == NULL)
	{
		printf("error for set sample Rate\n");
		return;
	}
	pst->setSampleRate(srate);
}

void  soundtouch_setSetting(HANDLE h)
{
	SoundTouch *pst = (SoundTouch*)h;
	pst->setSetting(SETTING_USE_QUICKSEEK,0);
	pst->setSetting(SETTING_USE_AA_FILTER, 1);

	pst->setTempoChange(0);
	pst->setRateChange(0);

}

// Processes the sound
///buf : represent PCM data buffer for transform
/// we will write processed data back to buf 
void  soundtouch_process(HANDLE h, short* src, unsigned long bufSize)
{
    int nSamples;
    int nChannels;
    int buffSizeSamples;
	SoundTouch *pSoundTouch = (SoundTouch*)h;

	if ((src == NULL) || (bufSize == 0)) {
		printf("invalided buffer to process!!!\n");
		return;  // nothing to do.
	}
	
	//allocate a temporary buffer to hold source data
	short* pSampleBuffer = new short[bufSize];
	//get a copy 
	memcpy(pSampleBuffer, src, bufSize);

	nChannels = getChannels();
    assert(nChannels > 0);
	buffSizeSamples = (bufSize/sizeof(short)) / nChannels;
	//how many samples should be processed
	int num = bufSize/sizeof(short);
	nSamples = num / getChannels();
	//feed data to process
	pSoundTouch->putSamples(pSampleBuffer,nSamples);
	
	//get processed data numbers 
	nSamples = pSoundTouch->receiveSamples(pSampleBuffer, buffSizeSamples);
	//get final result,copy to src buffer
	memcpy(src, pSampleBuffer, nSamples * nChannels * sizeof(short));
	
	delete[]pSampleBuffer;
	pSampleBuffer = NULL;

	printf("Done!\n");
}
