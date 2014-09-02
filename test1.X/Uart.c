#include<p18f2550.h>

void uart_init() {
    //SPBRG = 25; // Baud : 9600 @ 16MHZ osc clock and
                // BRGH: 0, BRG16: 0

    SPBRG = 38; // Baud : 9600 @ 24MHZ osc clock and
                // BRGH: 0, BRG16: 0
    SYNC = 0;
    TXEN = 1;
    BRGH = 0;
    SPEN = 1;
    CREN = 1;
    BRG16 = 0;
}

void uart_sendbyte(unsigned char ch) {
    while (!TXIF);
    TXREG = ch;
}

unsigned char uart_readbyte() {
    while (!RCIF);
    return RCREG;
}

void uart_printline(unsigned char *line) {
   while ((line != 0) && (*line != 0)) {
       uart_sendbyte(*line++);
   }
}
