
// Includes
#include "Select_File.h"

#if myUARTtoRF_use == 1

void myUARTtoRF_Initialization() {
    PowerLED = 0;
    LED1 = 1;
    LED2 = 1;
}
//******************************************************************************

void myUARTtoRF_Main() {
    setTxData();
}
#endif
