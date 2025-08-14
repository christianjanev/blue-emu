#ifndef REGISTERS_H
#define REGISTERS_H
#include <stdint.h>

uint16_t ACC;
uint16_t IR;
uint16_t PC = 0x00;
uint16_t SR;
uint16_t MAR;
uint16_t MBR;
uint16_t ZR;

uint16_t RAM[4096];
#endif
