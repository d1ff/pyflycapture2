from _FlyCapture2Defs_C cimport *

cdef extern from "_utils.h":
    fc2Error PollForTriggerReady( fc2Context pCam )
