#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "registers.h"

void hlt(uint8_t tick);
void add(uint8_t tick);
void xor(uint8_t tick);
void and(uint8_t tick);
void ior(uint8_t tick);
void not(uint8_t tick);
void lda(uint8_t tick);
void sta(uint8_t tick);
void srj(uint8_t tick);
void jma(uint8_t tick);
void jmp(uint8_t tick);
void inp(uint8_t tick);
void out(uint8_t tick);
void ral(uint8_t tick);
void csa(uint8_t tick);
void nop(uint8_t tick);
#endif
