#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

//  +------------------------------------------------------------------------+
//  |                           Instruction Format                           |
//  +------------------------------------------------------------------------+
//  | Each instruction takes up 2 bytes, with each bit numbered from 0 - 15. |
//  | The diagram below illustrates which parts of the 2 bytes correspond to |
//  | which parts of the instruction.                                        |
//  +------------------------------------------------------------------------|
//
//  +---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+
//  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
//  +---+---+---+---+---+---+---+---+---+---+----+----+----+----+----+----+
//  | Opcode                | Addr. | Operand                             |
//  |                       | mode  |                                     |
//  |                       |       |                                     |
//  +-----------------------+-------+-------------------------------------+

//  +---------+
//  | Opcodes |
//  +---------+

/// Halt the program.
#define HLT 0
/// Copy the value specified by the addr. mode and the operand to the ACC.
#define MOV 1
/// Copy the value in the ACC to the given register. Note that if the given register is a sub register, only  of the ACC will
/// be copied to the given register. For example: STO CR2B - Store the first byte of the ACC to CR2B.
///
/// Opcode values:
/// Primary registers
/// SCL - 0
/// R1 - 1
/// R2 - 2
/// Sub registers
/// IR1A - 3
/// IR1B - 4
/// IR2A - 5
/// IR2B - 6
///
/// SR1A - 7
/// SR1B - 8
/// SR1C - 9
/// SR1D - 10
/// SR2A - 11
/// SR2B - 12
/// SR2C - 13
/// SR2D - 14
///
/// CSLA - 15
/// CSLB - 16
/// CR1A - 17
/// CR1B - 18
/// CR1C - 19
/// CR1D - 20
/// CR1E - 21
/// CR1F - 22
/// CR1G - 23
/// CR1H - 24
/// CR2A - 25
/// CR2B - 26
/// CR2C - 27
/// CR2D - 28
/// CR2E - 29
/// CR2F - 30
/// CR2G - 31
/// CR2H - 32
#define STO 2
/// Add the value given by the addr. mode and the operand to the ACC.
#define ADD 3
#define SUB 4
#define SCL 5

//  +----------+
//  | Operands |
//  +----------+

#define IMMEDIATE_ADDRESS  0
#define DIRECT_ADDRESS 1
#define INDIRECT_ADDRESS 2
#define REGISTER 3

void mov(CPU* cpu, unsigned char addr_mode) {

}

#endif