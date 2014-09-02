#include<p18f2550.h>

#include "usb.h"


void usb_init() {
    UCON = 0;
    UCFGbits.PPB0 = 0;
    UCFGbits.PPB1 = 0;
    UCFGbits.UTEYE = 0;
    UCFGbits.UPUEN = 1;
    UCFGbits.FSEN = 0;
    UCONbits.USBEN = 1;

    UIE = 0;
    UIR = 0;
    UEIE = 0;
    UEIR = 0;

}