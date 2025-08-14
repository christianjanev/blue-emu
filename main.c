#include <stdio.h>
#include <string.h>

#include "instructions.h"

#define GET_INSTRUCTION(INSTRUCTION) ((INSTRUCTION & 0xF000) >> 12)

unsigned char clock_pulse;

void emulate_cycle();
void dump_registers();
void process_tick(uint8_t tick);

int main()
{
	uint16_t program[4] = {
		0xF000,
		0xF003,
		0xF00A,
		0xF0FF
	};

	memset(RAM, 0x00, 4096*sizeof(uint16_t));
	memmove(RAM, program, sizeof(program));

	for (;;)
	{
		emulate_cycle();
		dump_registers();
	}
	return 0;
}

void process_tick(uint8_t tick)
{
	switch (tick)
	{
		case 1:
			break;
		case 2:
			PC++;
			break;
		case 3:
			MBR=0x00;
		case 4:
			IR=0x00;
			MBR=RAM[MAR];
		case 5:
			IR=MBR;
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			break;
	}
	// 1111 (NOP)
	if (GET_INSTRUCTION(IR) == 0xF) nop(tick); 
}

void emulate_cycle()
{
	clock_pulse = 1;
	while (clock_pulse < 9)
	{
		process_tick(clock_pulse++);
	}
}

void dump_registers()
{
	printf("PC: %04x ACC: %04x IR: %04x ZR: %04x MAR: %04x MBR: %04x\n", PC, ACC, IR, ZR, MAR, MBR);
}

void hlt(uint8_t tick)
{

}
void add(uint8_t tick)
{

}
void xor(uint8_t tick)
{

}
void and(uint8_t tick)
{

}
void ior(uint8_t tick)
{

}
void not(uint8_t tick)
{

}
void lda(uint8_t tick)
{

}
void sta(uint8_t tick)
{

}
void srj(uint8_t tick)
{

}
void jma(uint8_t tick)
{

}
void jmp(uint8_t tick)
{

}
void inp(uint8_t tick)
{

}
void out(uint8_t tick)
{

}
void nop(uint8_t tick)
{
	if (tick == 8) MAR=PC;
}
