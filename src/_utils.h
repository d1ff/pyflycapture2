#include "FlyCapture2_C.h"
#include "FlyCapture2Defs_C.h"
#include "FlyCapture2Platform_C.h"

fc2Error PollForTriggerReady( fc2Context pCam )
{
    const unsigned int k_softwareTrigger = 0x62C;
    fc2Error error;
    unsigned int regVal = 0;

    do 
    {
        error = fc2ReadRegister(pCam, k_softwareTrigger, &regVal);//pCam->ReadRegister( k_softwareTrigger, &regVal );
        if (error != FC2_ERROR_OK)
        {
			return error;
        }

    } while ( (regVal >> 31) != 0 );

	return FC2_ERROR_OK;
}
