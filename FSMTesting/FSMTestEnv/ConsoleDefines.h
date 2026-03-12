#pragma once

#if _WIN
    #define pause "pause"
    #define cls "cls"
#else
    #define pause "read o"    
    #define cls "tput clear"
#endif