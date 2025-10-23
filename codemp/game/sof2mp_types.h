#ifndef __SOF2MP_TYPES_H__
#define __SOF2MP_TYPES_H__

// Basic type definitions
typedef float vec_t;
typedef vec_t vec3_t[3];

// Basic definitions for SOF2MP types that are missing

// Forward declarations
struct gentity_s;
typedef struct gentity_s gentity_t;

// Simple saber info structure (minimal version)
typedef struct saberInfo_s {
	char name[64];
	int type;
	int numBlades;
} saberInfo_t;

// Saber colors
typedef enum {
	SABER_RED,
	SABER_ORANGE, 
	SABER_YELLOW,
	SABER_GREEN,
	SABER_BLUE,
	SABER_PURPLE,
	NUM_SABER_COLORS
} saber_colors_t;

// Force powers
typedef enum {
	FP_HEAL = 0,
	FP_LEVITATION,
	FP_SPEED,
	FP_PUSH,
	FP_PULL,
	FP_TELEPATHY,
	FP_GRIP,
	FP_LIGHTNING,
	FP_RAGE,
	FP_PROTECT,
	FP_ABSORB,
	FP_TEAM_HEAL,
	FP_TEAM_FORCE,
	FP_DRAIN,
	FP_SEE,
	FP_SABER_OFFENSE,
	FP_SABER_DEFENSE,
	FP_SABERTHROW,
	NUM_FORCE_POWERS
} forcePowers_t;

// Siege personality types
typedef enum {
	SIEGEPERS_GALAKMEEK,
	SIEGEPERS_CLONETROOPER,
	SIEGEPERS_CLONETROOPER_CAPTAIN,
	SIEGEPERS_CLONETROOPER_COMMANDER,
	SIEGEPERS_SABOTEUR,
	SIEGEPERS_SABOTEUR_CIVILIAN,
	SIEGEPERS_DESANN,
	SIEGEPERS_JAN,
	SIEGEPERS_LUKE,
	SIEGEPERS_MONMOTHA,
	SIEGEPERS_TAVION,
	SIEGEPERS_ALORA,
	SIEGEPERS_REBEL,
	SIEGEPERS_REBEL_CAPTAIN,
	SIEGEPERS_REBEL_COMMANDER,
	SIEGEPERS_BARTENDER,
	SIEGEPERS_MORGANKATARN,
	SIEGEPERS_RODIAN,
	SIEGEPERS_IMPERIAL,
	SIEGEPERS_IMPWORKER,
	SIEGEPERS_GRAN,
	SIEGEPERS_NIGHTSISTER,
	SIEGEPERS_GAMORREAN,
	SIEGEPERS_JAWA,
	SIEGEPERS_REBORN,
	SIEGEPERS_REBORN_NEW,
	SIEGEPERS_REBORN_ROSH,
	SIEGEPERS_TUSKEN,
	SIEGEPERS_WEEQUAY,
	SIEGEPERS_PROTOCOL,
	SIEGEPERS_MONCALAMARI,
	SIEGEPERS_WHAMPRIDER,
	NUM_SIEGE_CLASSES
} siegePers_t;

// Material type
typedef enum {
	MAT_METAL = 0,
	MAT_GLASS,
	MAT_ELECTRICAL,
	MAT_ELEC_METAL,
	MAT_ROCK,
	MAT_DIRT,
	MAT_FLESH,
	MAT_GRATE,
	MAT_VENT,
	MAT_PLANT,
	MAT_FOOTWRAP, //footwrap is for cloth sounds
	MAT_NO_SOUND, //no impact sound, but still flesh blood
	MAT_BLOOD, //for g_spskill -> g_dismember
	MAT_WPNTABLE, // Weapon table materials
	MAT_ARMOR,
	MAT_JEDI, //special jedi hit sound (not used in SOF2)
	MAT_STONE,
	MAT_GENMETAL,
	MAT_GLASS_METAL,
	MAT_ELECTRICAL_METAL,
	MAT_SNIPER,
	MAT_CLONE,
	MAT_MAX
} material_t;

// Force data structure (simplified)
typedef struct forceData_s {
	int forcePowersKnown;
	int forcePowersActive;
	int forcePowerSelected;
	int forcePower;
	int forcePowerMax;
	int forcePowerRegenDebounceTime;
	int forcePowerLevel[NUM_FORCE_POWERS];		//so we know the max forceJump power you have
	int forcePowerBaseLevel[NUM_FORCE_POWERS];
	int forceUsingAdded;
	float forceJumpZStart;				//So when you land, you don't get hurt as much
	float forceJumpCharge;				//you're current forceJump charge-up level, increases the longer you hold the force jump button down
	int forceGripEntityNum;				//what entity I'm gripping
	vec3_t forceGripOrg;				//where the gripped ent should be lifted to
	int forceHealCount;
	int forceRageRecoveryTime;
	int forceDodgeCount;
	int forcePanicSaveTime;
	int forceFuryTime;
	int forceGripCripple;
	int forceGripBeingGripped;
	int forceGripDamageDebounce;
	int forceGripUseTime;
	int forceDrainEntityNum;
	vec3_t forceDrainOrg;
	float forceDrainTime;
	int forceSpeedRecoveryTime;
	int forceSpeedDuration;
	int forceGripQuickKeyPress;
	int forceRageDuration;
	int forceRageRecovery;
	int forceProtectDuration;
	int forceAbsorbDuration;
	int forceForceReplentishDebounce;
	int forceLightsaberRuneUse;
	int forceAllowDeactivateTime;
	int forceRageDrainTime;
	int forceDrainEntNum;
	int forcePowersForced;
	int pullAttackEntNum;
	int pullAttackTime;
	int lastKickedEntNum;
	int saberAnimLevel;
	
	// Mind trick target indices
	int forceMindtrickTargetIndex;
	int forceMindtrickTargetIndex2;
	int forceMindtrickTargetIndex3;
	int forceMindtrickTargetIndex4;
	
	// Additional force members
	int forceSide;
} forceData_t;

// Saber styles
typedef enum {
	SS_NONE = 0,
	SS_SINGLE,
	SS_STAFF,
	SS_DUAL,
	SS_NUM_SABER_STYLES
} saber_styles_t;

// Quad directions
typedef enum {
	QFRONT = 0,
	QRIGHT,
	QLEFT,
	QBACK,
	NUM_QUADS
} quad_direction_t;

#endif // __SOF2MP_TYPES_H__