#ifndef ACF_UDP_DATA_H
#define ACF_UDP_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct UdpHandshake {
	int32_t identifier;
	int32_t version;
	int32_t operationId;
} UdpHandshake;

typedef struct UdpHandshakeResponse {
	char carName[50];
	char driverName[50];

	int32_t identifier;
	int32_t version;

	char trackName[50];
	char trackConfig[50];
} UdpHandshakeResponse;

typedef enum UdpDeviceId {
	IPHONE,
	IPAD,
	ANDROID_PHONE,
	ANDROID_TABLET
} UdpDeviceId;

typedef enum UdpOperation {
	HANDSHAKE,
	SUBSCRIBE_UPDATE,
	SUBSCRIBE_SPOT,
	DISMISS
} UdpOperation;


#pragma pack(push)
#pragma pack(4)

typedef struct UdpCarData {
	char identifier;
	int32_t size;

	f32 speed_Kmh;
	f32 speed_Mph;
	f32 speed_Ms;

	/* The following members should be interpreted as booleans (i.e. if 0
	 * then false, otherwise true). They are represented here as uint8_t
	 * because that is how the protocol sends them and there is no
	 * guarantee in the C and C++ standards that sizeof(bool) == 1
	 */
	uint8_t isAbsEnabled;
	uint8_t isAbsInAction;
	uint8_t isTcInAction;
	uint8_t isTcEnabled;
	uint8_t isInPit;
	uint8_t isEngineLimiterOn;

	f32 accG_vertical;
	f32 accG_horizontal;
	f32 accG_frontal;

	int32_t lapTime;
	int32_t lastLap;
	int32_t bestLap;
	int32_t lapCount;

	f32 gas;
	f32 brake;
	f32 clutch;
	f32 engineRPM;
	f32 steer;
	int32_t gear;
	f32 cgHeight;

	f32 wheelAngularSpeed[4];
	f32 slipAngle[4];
	f32 slipAngle_ContactPatch[4];
	f32 slipRatio[4];
	f32 tyreSlip[4];
	f32 ndSlip[4];
	f32 load[4];
	f32 Dy[4];
	f32 Mz[4];
	f32 tyreDirtyLevel[4];

	f32 camberRAD[4];
	f32 tyreRadius[4];
	f32 tyreLoadedRadius[4];

	f32 suspensionHeight[4];

	f32 carPositionNormalized;

	f32 carSlope;

	f32 carCoordinates[3];
} UdpCarData;

typedef struct LapData {
	int32_t carIdentifierNumber;
	int32_t lap;
	wchar_t driverName[50];
	char carName[50];
	int32_t time;
} LapData;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif //ACF_UDP_DATA_H
