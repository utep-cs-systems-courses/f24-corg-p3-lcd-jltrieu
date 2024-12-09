CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: project.elf

project.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o switches.o buzzer.o main.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: project.elf
	msp430loader.sh $^


clean:
	rm -f *.o *.elf
