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

// Game types
typedef enum {
	GT_FFA = 0,              // free for all
	GT_HOLOCRON,             // 
	GT_JEDIMASTER,           // 
	GT_TOURNAMENT,           // one on one tournament
	GT_SINGLE_PLAYER,        // single player tournament
	
	//-- team games go after this --
	GT_TEAM,                 // team deathmatch
	GT_CTF,                  // capture the flag
	GT_CTY,
	GT_SIEGE,                // siege
	GT_DUEL,
	GT_POWERDUEL,
	GT_SINGLE,
	GT_TEAM2,
	GT_CTF2,
	GT_CTY2,
	GT_SIEGE2,
	GT_MAX_GAME_TYPE

// Button definitions
#define BUTTON_GESTURE      22
#define BUTTON_USE_HOLDABLE 23
#define BUTTON_FORCEPOWER   24

// Weapon constants
#define WP_NONE             0
#define WP_STUN_BATON       1
#define WP_MELEE            2
#define WP_SABER            3
#define WP_BRYAR_PISTOL     4
#define WP_BLASTER          5
#define WP_DISRUPTOR        6
#define WP_BOWCASTER        7
#define WP_REPEATER         8
#define WP_DEMP2            9
#define WP_FLECHETTE        10
#define WP_ROCKET_LAUNCHER  11
#define WP_THERMAL          12
#define WP_TRIP_MINE        13
#define WP_DET_PACK         14
#define WP_EMPLACED_GUN     15
#define WP_TURRET           16
#define WP_GAUNTLET         17
#define WP_NUM_WEAPONS      18

// Event constants
#define EV_SABER_ATTACK     100
#define EV_SABER_HIT        101
#define EV_SABER_BLOCK      102
#define EV_SABER_CLASHFLARE 103
#define EV_SABER_UNHOLSTER  104
#define EV_SABER_TAUNT      105
#define EV_FOOTSTEP_METAL   106
#define EV_ROLL             107
#define EV_JETPACK_ENABLE   108
#define EV_JETPACK_DISABLE  109
#define EV_JETPACK_IGNITE   110
#define EV_JETPACK_STOP     111
#define EV_JETPACK_ABORT    112
#define EV_JETPACK_LIFTOFF  113
#define EV_JETPACK_LAND     114
#define EV_ENTITIES_LOOPING_SOUND 115
#define EV_SLIDING          116
#define EV_CUSTOM_PARTICLE_EFFECT 117
#define EV_BOTWAYPOINTMSG   118
#define EV_TEAM_POWER       119
#define EV_ITEM_USE         120
#define EV_ITEM_RESPAWN     121
#define EV_ITEM_POP         122
#define EV_PLAYER_TELEPORT_IN 123
#define EV_PLAYER_TELEPORT_OUT 124
#define EV_GRENADE_BOUNCE   125
#define EV_MISSILE_STICK    126
#define EV_PLAY_EFFECT      127
#define EV_GENERAL_SOUND    128
#define EV_GLOBAL_SOUND     129
#define EV_PAIN             130
#define EV_DEATH1           131
#define EV_DEATH2           132
#define EV_DEATH3           133
#define EV_OBITUARY         134
#define EV_POWERUP          135
#define EV_ERROR_SOUND      136
#define EV_MUTANT_SPLASH    137
#define EV_WATER_TOUCH      138
#define EV_WATER_WADE       139
#define EV_WATER_JUMP       140
#define EV_ITEM_PICKUP      141
#define EV_ITEM_PICKUP_QUIET 142
#define EV_MEDKIT_USED      143
#define EV_WEAPONSOUND      144
#define EV_FIRE_WEAPONB     145
#define EV_FIRE_WEAPON2B     146
#define EV_NOAMMO           147
#define EV_CHANGE_WEAPONB    148
#define EV_ALT_FIREB         149
#define EV_USEB              150
#define EV_ITEM_RESPAWNB     151
#define EV_ITEM_POPB         152
#define EV_PLAYER_TELEPORT_INB 153
#define EV_PLAYER_TELEPORT_OUTB 154
#define EV_GRENADE_BOUNCEB   155
#define EV_MISSILE_STICKB    156
#define EV_PLAY_EFFECTB      157
#define EV_GENERAL_SOUNDB    158
#define EV_GLOBAL_SOUNDB     159
#define EV_PAINB             160
#define EV_DEATH1B           161
#define EV_DEATH2B           162
#define EV_DEATH3B           163
#define EV_OBITUARYB         164
