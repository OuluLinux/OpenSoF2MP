/*
This file is part of Jedi Academy.

    Jedi Academy is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Jedi Academy is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Jedi Academy.  If not, see <http://www.gnu.org/licenses/>.
*/
// Copyright 2001-2013 Raven Software

// snd_local.h -- private sound definations

#ifndef SND_LOCAL_H
#define SND_LOCAL_H

// EAX variables will be declared normally regardless of platform
// The implementation will be stubbed for Linux

#include "../game/q_shared.h"
#include "../qcommon/qcommon.h"
#include "snd_public.h"
#include "../mp3code/mp3struct.h"

// Open AL Specific
#include <AL/al.h>
#include <AL/alc.h>
#ifndef __linux__
#include "eax/eax.h"
#include "eax/EaxMan.h"
#endif

// Define missing Windows types for Linux
#ifdef __linux__
// Define GUID structure for Linux if not already defined
#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;
#endif // GUID_DEFINED

// Basic Windows types for Linux compatibility
#ifndef HINSTANCE
#define HINSTANCE void*
#endif

#ifndef HRESULT
typedef long HRESULT;
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define EAX_OK                          0x00000000
#define EAXERR_INVALID_OPERATION        0x80004001
#define EAXERR_INVALID_VALUE            0x80004002
#define EAXERR_NO_MORE_ITEMS            0x80004003
#endif

// Define missing Windows functions for Linux
#define timeGetTime() (int)(Sys_Milliseconds())
#define OutputDebugString(s) Com_Printf("%s", s)
#define LoadLibrary(name) NULL
#define FreeLibrary(handle) do {} while(0)
#define GetProcAddress(handle, name) NULL

// EAX constants
#define EAX_MAX_FXSLOTS 4

// Declare EAX GUID constants as extern variables instead of macros
extern const GUID EAXPROPERTYID_EAX40_FXSlot0;
extern const GUID EAXPROPERTYID_EAX40_FXSlot1;
extern const GUID EAXPROPERTYID_EAX40_FXSlot2;
extern const GUID EAXPROPERTYID_EAX40_FXSlot3;
extern const GUID EAXPROPERTYID_EAX40_Context;
extern const GUID EAXPROPERTYID_EAX40_Source;
extern const GUID EAX_NULL_GUID;
extern const GUID EAX_PrimaryFXSlotID;
extern const GUID EAX_REVERB_EFFECT;

// EAX function pointer types
typedef ALenum (*EAXSet)(const GUID*, ALuint, ALuint, ALvoid*, ALuint);
typedef ALenum (*EAXGet)(const GUID*, ALuint, ALuint, ALvoid*, ALuint);

// EAX Manager types (stubbed for Linux)
typedef struct EAXMANAGER *LPEAXMANAGER;
typedef long (*LPEAXMANAGERCREATE)(LPEAXMANAGER*);

// EAX Manager interface stub
#define EM_OK EAX_OK
#define EMFLAG_LOADFROMMEMORY 0x00000001
#define EMFLAG_LOCKPOSITION   0x00000002

// EAX Vector structure
typedef struct EAXVECTOR {
    float x;
    float y;
    float z;
} EAXVECTOR;

// EAX property structures
typedef struct EAXREVERBPROPERTIES {
    long lEnvironment;
    float flEnvironmentSize;
    float flEnvironmentDiffusion;
    long lRoom;
    long lRoomHF;
    long lRoomLF;
    float flDecayTime;
    float flDecayHFRatio;
    float flDecayLFRatio;
    long lReflections;
    float flReflectionsDelay;
    float flReflectionsPan[3];
    long lReverb;
    float flReverbDelay;
    float flReverbPan[3];
    float flEchoTime;
    float flEchoDepth;
    float flModulationTime;
    float flModulationDepth;
    float flAirAbsorptionHF;
    float flHFReference;
    float flLFReference;
    float flRoomRolloffFactor;
    long lFlags;
} EAXREVERBPROPERTIES;

typedef struct EAXOBSTRUCTIONPROPERTIES {
    long lObstruction;
    float flObstructionLFRatio;
} EAXOBSTRUCTIONPROPERTIES;

typedef struct EAXOCCLUSIONPROPERTIES {
    long lOcclusion;
    float flOcclusionLFRatio;
    float flOcclusionRoomRatio;
    float flOcclusionDirectRatio;
} EAXOCCLUSIONPROPERTIES;

typedef struct EAXACTIVEFXSLOTS {
    GUID guidActiveFXSlots[2];
} EAXACTIVEFXSLOTS;

typedef struct EAXFXSLOTPROPERTIES {
    GUID guidLoadEffect;
    long lVolume;
    long lLock;
    unsigned long ulFlags;
} EAXFXSLOTPROPERTIES;

// EAX constants
#define EAXCONTEXT_PRIMARYFXSLOTID      0x00000001
#define EAXSOURCE_EXCLUSION             0x00000001
#define EAXSOURCE_ACTIVEFXSLOTID        0x00000002
#define EAXSOURCE_OBSTRUCTIONPARAMETERS 0x00000003
#define EAXSOURCE_OCCLUSIONPARAMETERS   0x00000004
#define EAXSOURCE_FLAGS                 0x00000005
#define EAXSOURCE_OCCLUSIONLFRATIO      0x00000006
#define EAXSOURCE_OCCLUSION_ROOMRATIO   0x00000007
#define EAXSOURCE_OCCLUSION_DIRECTRATIO 0x00000008
#define EAXSOURCE_OUTPUTGAIN            0x00000009
#define EAXSOURCE_ROOMFILTERFACTOR      0x0000000A
#define EAXSOURCE_AIRABSORPTIONFACTOR   0x0000000B
#define EAXSOURCE_OBSTRUCTIONLFRATIO    0x0000000C
#define EAXSOURCE_OCCLUSIONLFHFILTER    0x0000000D
#define EAXSOURCE_OCCLUSIONHFREFERENCE  0x0000000E
#define EAXSOURCE_OCCLUSIONLFREFERENCE  0x0000000F
#define EAXSOURCE_EXCLUSIONLFRATIO      0x00000010
#define EAXSOURCE_INCLUSIONLFRATIO      0x00000011
#define EAXSOURCE_INCLUSIONLFHFILTER    0x00000012
#define EAXSOURCE_INCLUSIONDIRECTRATIO  0x00000013
#define EAXSOURCE_INCLUSIONFLAGS        0x00000014
#define EAXSOURCE_DIRECTHFAUTO          0x00000015
#define EAXSOURCE_ROOMAUTO              0x00000016
#define EAXSOURCE_OCCLUSIONAUTO         0x00000017
#define EAXSOURCE_DIRECTAUTO            0x00000018

#define EAXREVERB_ALLPARAMETERS         0x00000001
#define EAXREVERB_ENVIRONMENT           0x00000002
#define EAXREVERB_ENVIRONMENTSIZE       0x00000003
#define EAXREVERB_ENVIRONMENTDIFFUSION  0x00000004
#define EAXREVERB_ROOM                  0x00000005
#define EAXREVERB_ROOMHF                0x00000006
#define EAXREVERB_ROOMLF                0x00000007
#define EAXREVERB_DECAYTIME             0x00000008
#define EAXREVERB_DECAYHFRATIO          0x00000009
#define EAXREVERB_DECAYLFRATIO          0x0000000A
#define EAXREVERB_REFLECTIONS           0x0000000B
#define EAXREVERB_REFLECTIONSDELAY      0x0000000C
#define EAXREVERB_REFLECTIONSPAN        0x0000000D
#define EAXREVERB_REVERB                0x0000000E
#define EAXREVERB_REVERBDELAY           0x0000000F
#define EAXREVERB_REVERBPAN             0x00000010
#define EAXREVERB_ECHOTIME              0x00000011
#define EAXREVERB_ECHODEPTH             0x00000012
#define EAXREVERB_MODULATIONTIME        0x00000013
#define EAXREVERB_MODULATIONDEPTH       0x00000014
#define EAXREVERB_AIRABSORPTIONHF       0x00000015
#define EAXREVERB_HFREFERENCE           0x00000016
#define EAXREVERB_LFREFERENCE           0x00000017
#define EAXREVERB_ROOMROLLOFFFACTOR     0x00000018
#define EAXREVERB_FLAGS                 0x00000019

#define EAXFXSLOT_ALLPARAMETERS         0x00000001
#define EAXFXSLOT_LOADEFFECT            0x00000002
#define EAXFXSLOT_VOLUME                0x00000003
#define EAXFXSLOT_LOCK                  0x00000004
#define EAXFXSLOT_FLAGS                 0x00000005

#define EAXFXSLOTFLAGS_ENVIRONMENT      0x00000001
#define EAXFXSLOT_LOCKED                0x00000001

#define EAX_ENVIRONMENT_GENERIC         0
#define EAX_ENVIRONMENT_PADDEDCELL      1
#define EAX_ENVIRONMENT_ROOM            2
#define EAX_ENVIRONMENT_BATHROOM        3
#define EAX_ENVIRONMENT_LIVINGROOM      4
#define EAX_ENVIRONMENT_STONEROOM       5
#define EAX_ENVIRONMENT_AUDITORIUM      6
#define EAX_ENVIRONMENT_CONCERTHALL     7
#define EAX_ENVIRONMENT_CAVE            8
#define EAX_ENVIRONMENT_ARENA           9
#define EAX_ENVIRONMENT_HANGAR          10
#define EAX_ENVIRONMENT_CARPETEDHALLWAY 11
#define EAX_ENVIRONMENT_HALLWAY         12
#define EAX_ENVIRONMENT_STONECORRIDOR   13
#define EAX_ENVIRONMENT_ALLEY           14
#define EAX_ENVIRONMENT_FOREST          15
#define EAX_ENVIRONMENT_CITY            16
#define EAX_ENVIRONMENT_MOUNTAINS       17
#define EAX_ENVIRONMENT_QUARRY          18
#define EAX_ENVIRONMENT_PLAIN           19
#define EAX_ENVIRONMENT_PARKINGLOT      20
#define EAX_ENVIRONMENT_SEWERPIPE       21
#define EAX_ENVIRONMENT_UNDERWATER      22

#define EAXSOURCE_DEFAULTOCCLUSION        0
#define EAXSOURCE_DEFAULTOCCLUSIONLFRATIO 0.25f
#define EAXSOURCE_DEFAULTOCCLUSIONROOMRATIO 0.5f
#define EAXSOURCE_DEFAULTOCCLUSIONDIRECTRATIO 1.0f
#define EAXSOURCE_DEFAULTOBSTRUCTION      0
#define EAXSOURCE_DEFAULTOBSTRUCTIONLFRATIO 0.0f

// EAX Point structure
typedef struct EMPOINT {
    float fX;
    float fY;
    float fZ;
} EMPOINT;

#endif // __linux__

#ifndef __linux__
#include "eax/eax.h"
#include "eax/EaxMan.h"
#endif

// Define missing Windows types for Linux
#ifdef __linux__
// Include OpenAL first to get AL types
#include <AL/al.h>
#include <AL/alc.h>

// Basic Windows types for Linux compatibility
#ifndef HINSTANCE
#define HINSTANCE void*
#endif

#ifndef HRESULT
typedef long HRESULT;
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define EAX_OK                          0x00000000
#define EAXERR_INVALID_OPERATION        0x80004001
#define EAXERR_INVALID_VALUE            0x80004002
#define EAXERR_NO_MORE_ITEMS            0x80004003
#endif

// GUID will be defined in snd_dma.cpp, just declare the extern constants
extern const GUID EAXPROPERTYID_EAX40_FXSlot0;
extern const GUID EAXPROPERTYID_EAX40_FXSlot1;
extern const GUID EAXPROPERTYID_EAX40_FXSlot2;
extern const GUID EAXPROPERTYID_EAX40_FXSlot3;
extern const GUID EAXPROPERTYID_EAX40_Context;
extern const GUID EAXPROPERTYID_EAX40_Source;
extern const GUID EAX_NULL_GUID;
extern const GUID EAX_PrimaryFXSlotID;
extern const GUID EAX_REVERB_EFFECT;

#endif // __linux__

// EAX function pointer types
typedef ALenum (*EAXSet)(const GUID*, ALuint, ALuint, ALvoid*, ALuint);
typedef ALenum (*EAXGet)(const GUID*, ALuint, ALuint, ALvoid*, ALuint);

// EAX Manager types (stubbed for Linux)
typedef struct EAXMANAGER *LPEAXMANAGER;
typedef long (*LPEAXMANAGERCREATE)(LPEAXMANAGER*);

// Define missing Windows functions for Linux
#define timeGetTime() (int)(Sys_Milliseconds())
#define OutputDebugString(s) Com_Printf("%s", s)
#define LoadLibrary(name) NULL
#define FreeLibrary(handle) do {} while(0)
#define GetProcAddress(handle, name) NULL

// EAX Manager interface stub
#define EM_OK EAX_OK
#define EMFLAG_LOADFROMMEMORY 0x00000001
#define EMFLAG_LOCKPOSITION   0x00000002

// EAX Vector structure

// EAX GUID constants (will be defined in snd_dma.cpp)
extern const GUID EAXPROPERTYID_EAX40_FXSlot0;
extern const GUID EAXPROPERTYID_EAX40_FXSlot1;
extern const GUID EAXPROPERTYID_EAX40_FXSlot2;
extern const GUID EAXPROPERTYID_EAX40_FXSlot3;
extern const GUID EAXPROPERTYID_EAX40_Context;
extern const GUID EAXPROPERTYID_EAX40_Source;
extern const GUID EAX_NULL_GUID;
extern const GUID EAX_PrimaryFXSlotID;
extern const GUID EAX_REVERB_EFFECT;

// Added for Open AL to know when to mute all sounds (e.g when app. loses focus)
void S_AL_MuteAllSounds(qboolean bMute);

// Forward declaration for Linux compatibility
int Sys_Milliseconds(void);

//from SND_AMBIENT
extern void AS_Init( void );
extern void AS_Free( void );


#define	PAINTBUFFER_SIZE	1024


// !!! if this is changed, the asm code must change !!!
typedef struct {
	int			left;	// the final values will be clamped to +/- 0x00ffff00 and shifted down
	int			right;
} portable_samplepair_t;


// keep this enum in sync with the table "sSoundCompressionMethodStrings"	-ste
//
typedef enum
{
	ct_16 = 0,		// formerly ct_NONE in EF1, now indicates 16-bit samples (the default)
	ct_MP3,			
	//
	ct_NUMBEROF		// used only for array sizing

} SoundCompressionMethod_t;


typedef struct sfx_s {
	short			*pSoundData;
	bool			bDefaultSound;			// couldn't be loaded, so use buzz
	bool			bInMemory;				// not in Memory, set qtrue when loaded, and qfalse when its buffers are freed up because of being old, so can be reloaded
	short			iLastLevelUsedOn;		// used for cacheing purposes
	SoundCompressionMethod_t eSoundCompressionMethod;	
	MP3STREAM		*pMP3StreamHeader;		// NULL ptr unless this sfx_t is an MP3. Use Z_Malloc and Z_Free
	int 			iSoundLengthInSamples;	// length in samples, always kept as 16bit now so this is #shorts (watch for stereo later for music?)
	char 			sSoundName[MAX_QPATH];
	int				iLastTimeUsed;
	float			fVolRange;				// used to set the highest volume this sample has at load time - used for lipsynching

	// Open AL
	ALuint		Buffer;
	char		*lipSyncData;

	struct sfx_s	*next;					// only used because of hash table when registering
} sfx_t;

typedef struct {
	int			channels;
	int			samples;				// mono samples in buffer
	int			submission_chunk;		// don't mix less than this #
	int			samplebits;
	int			speed;
	byte		*buffer;
} dma_t;


#define START_SAMPLE_IMMEDIATE	0x7fffffff

// Open AL specific
typedef struct streamingBuffer_s
{
	ALuint	BufferID;
	ALuint	Status;
	char	*Data;
} STREAMINGBUFFER;

#define NUM_STREAMING_BUFFERS	4
#define STREAMING_BUFFER_SIZE	4608		// 4 decoded MP3 frames

#define QUEUED		1
#define UNQUEUED	2


typedef struct channel_s
{
// back-indented fields new in TA codebase, will re-format when MP3 code finished -ste
// note: field missing in TA: qboolean	loopSound;		// from an S_AddLoopSound call, cleared each frame
//
	int				startSample;	// START_SAMPLE_IMMEDIATE = set immediately on next mix
	int				entnum;			// to allow overriding a specific sound
	soundChannel_t	entchannel;		// to allow overriding a specific sound
	int				leftvol;		// 0-255 volume after spatialization
	int				rightvol;		// 0-255 volume after spatialization
	int				master_vol;		// 0-255 volume before spatialization


	vec3_t		origin;			// only use if fixed_origin is set

	qboolean	fixed_origin;	// use origin instead of fetching entnum's origin
	sfx_t		*thesfx;		// sfx structure
	qboolean	loopSound;		// from an S_AddLoopSound call, cleared each frame
	//
	MP3STREAM	MP3StreamHeader;
	byte		MP3SlidingDecodeBuffer[50000/*12000*/];	// typical back-request = -3072, so roughly double is 6000 (safety), then doubled again so the 6K pos is in the middle of the buffer)
	int			iMP3SlidingDecodeWritePos;
	int			iMP3SlidingDecodeWindowPos;


	// Open AL specific
	bool	bLooping;	// Signifies if this channel / source is playing a looping sound
//	bool	bAmbient;	// Signifies if this channel / source is playing a looping ambient sound
	bool	bProcessed;	// Signifies if this channel / source has been processed
	bool	bStreaming;	// Set to true if the data needs to be streamed (MP3 or dialogue)
	STREAMINGBUFFER	buffers[NUM_STREAMING_BUFFERS];	// AL Buffers for streaming
	ALuint		alSource;		// Open AL Source
	bool		bPlaying;		// Set to true when a sound is playing on this channel / source
	int			iStartTime;		// Time playback of Source begins
	int			lSlotID;		// ID of Slot rendering Source's environment (enables a send to this FXSlot)
} channel_t;


#define	WAV_FORMAT_PCM		1
#define WAV_FORMAT_ADPCM	2	// not actually implemented, but is the value that you get in a header
#define WAV_FORMAT_MP3		3	// not actually used this way, but just ensures we don't match one of the legit formats


typedef struct {
	int			format;
	int			rate;
	int			width;
	int			channels;
	int			samples;
	int			dataofs;		// chunk starts this many bytes from file start
} wavinfo_t;



/*
====================================================================

  SYSTEM SPECIFIC FUNCTIONS

====================================================================
*/

// initializes cycling through a DMA buffer and returns information on it
qboolean SNDDMA_Init(void);

// gets the current DMA position
int		SNDDMA_GetDMAPos(void);

// shutdown the DMA xfer.
void	SNDDMA_Shutdown(void);

void	SNDDMA_BeginPainting (void);

void	SNDDMA_Submit(void);

//====================================================================

#define	MAX_CHANNELS			32
extern	channel_t   s_channels[MAX_CHANNELS];

extern	int		s_paintedtime;
extern	int		s_rawend;
extern	vec3_t	listener_origin;
extern	vec3_t	listener_forward;
extern	vec3_t	listener_right;
extern	vec3_t	listener_up;
extern	dma_t	dma;

#define	MAX_RAW_SAMPLES	16384
extern	portable_samplepair_t	s_rawsamples[MAX_RAW_SAMPLES];
portable_samplepair_t *S_GetRawSamplePointer();	// TA added this, but it just returns the s_rawsamples[] array above. Oh well...

extern cvar_t	*s_volume;
extern cvar_t	*s_volumeVoice;
extern cvar_t	*s_nosound;
extern cvar_t	*s_khz;
extern cvar_t	*s_allowDynamicMusic;
extern cvar_t	*s_show;
extern cvar_t	*s_mixahead;

extern cvar_t	*s_testsound;
extern cvar_t	*s_separation;

wavinfo_t GetWavinfo (const char *name, byte *wav, int wavlength);

qboolean S_LoadSound( sfx_t *sfx );


void S_PaintChannels(int endtime);

// picks a channel based on priorities, empty slots, number of channels
channel_t *S_PickChannel(int entnum, int entchannel);

// spatializes a channel
void S_Spatialize(channel_t *ch);


//////////////////////////////////
//
// new stuff from TA codebase

byte	*SND_malloc(int iSize, sfx_t *sfx);
void	 SND_setup();
int		 SND_FreeOldestSound(sfx_t *pButNotThisOne = NULL);
void	 SND_TouchSFX(sfx_t *sfx);

void S_DisplayFreeMemory(void);
void S_memoryLoad(sfx_t *sfx);
//
//////////////////////////////////




#endif // SND_LOCAL_H
