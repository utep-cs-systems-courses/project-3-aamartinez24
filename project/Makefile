# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

p2_interrupt_handler.o: p2_interrupt_handler.c
switches.o: switches.c switches.h
buzzer.o: buzzer.c buzzer.h
stateMachines.o: stateMachines.c stateMachines.h
led.o: led.c led.h

all:lcdtoy.elf

#additional rules for files
lcdtoy.elf: ${COMMON_OBJECTS} main.o p2_interrupt_handler.o switches.o buzzer.o stateMachines.o led.o wdt_handler.o assemMethods.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle -lp2sw

load: lcdtoy.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
