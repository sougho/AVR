#include<p18f2550.h>

// Clock : Fosc / 4 = 4 Mhz
// i.e, .25 us
// Prescalar : 256 to bring it up to
// 64 us


extern volatile char oneSecTick;
void uart_printline(char *line);

// Polling delay implementation

void delay_onesec() {
    int timerset = (65536 - 15625);
    T0CON = 0x07;
    TMR0 = timerset;
    T0CONbits.TMR0ON = 1;
    while (INTCONbits.TMR0IF == 0);
    T0CONbits.TMR0ON = 1;
    INTCONbits.TMR0IF = 0;
}



void  T0_ISR(void) {
    int timerset = (65536 - 15625);
    TMR0 = timerset;
    INTCONbits.TMR0IF = 0;
    oneSecTick = 1;
}

// interrupt driven
// PIC interrupts are not automatically placed in
// ISR tables
// So for high priority interrupt, the control comes here
// Check for the type of interrupt here and then
// Vector properly

void interrupt high_priority chk_isr(void) {
    di();
    if (INTCONbits.TMR0IF == 1 ) {
        T0_ISR();
    }
    ei();
}

void delay_onesec_int() {
    int timerset = (65536 - 15625);
    T0CON = 0x07;
    TMR0 = timerset;
    INTCONbits.TMR0IE  = 1;
    INTCONbits.TMR0IF  = 0;
    INTCONbits.GIE = 1;
    T0CONbits.TMR0ON = 1;
}

// Clock : Fosc / 4 = 4 Mhz
// i.e, .25 us
// Prescalar : 1

void timer2_init_for_delay_us() {
   /* Not Dedicated OSC*/
   T1CONbits.T1RUN = 0; 
   /* 1:1 Prescale*/
   T1CONbits.T1CKPS0 = 0;
   T1CONbits.T1CKPS1 = 0;
   /* Internal Clock = FOSC/4*/
   T1CONbits.TMR1CS = 0;
}
/*
 * Max Delay: 65536 / 4 = 16384
 * 1 tick : .25 us
 */
void timer2_delay_us(int us) {
    unsigned int timer_val = (65536 - (us * 4));
    TMR1 = timer_val;
    /* Start timer*/
    T1CONbits.TMR1ON = 1;
    while (PIR1bits.TMR1IF == 0);
    T1CONbits.TMR1ON = 1;
    PIR1bits.TMR1IF = 0;
}

