#include <iostream>
#include <CPU.hpp>
#include <Memory.hpp>
#include <Instructions.hpp>
#include <cstring>


int main() {
    CPU cpu;
    Memory memory(1024);

    const char* program = "\x05\x00\x14\x00\x05\x01\x14\x00\x05\x02\x14\x00\x05\x03\x14\x00\x05\x04\x14\x00\x05\x05\x14\x00\x00\x00";
    const char* s = "Hello\n";
    memcpy(memory.buffer, s, 6);
    memcpy(memory.buffer + 6, program, 26);

    memory.dump();

    cpu.PC = 6;
    cpu.stack = 32;

    while (true) {
        // Read opcode
        cpu.R1 = cpu.PC++;
        memory.read(&cpu);

        // Parse opcode
        unsigned char opcode = (*(cpu.CR2A()) & 0xFC) >> 2;
        unsigned char addr_mode = *(cpu.CR2A()) & 0x3;

        // Read operand
        cpu.R1 = cpu.PC++;
        memory.read(&cpu);

        switch (opcode) {
            case HLT: std::cout << "===== PROGRAM HALTED =====" << std::endl; exit(0); break;
            case MOV:
                if (addr_mode == IMMEDIATE_ADDRESS) {
                    cpu.ACC = *(cpu.CR2A());
                } else if (addr_mode == DIRECT_ADDRESS) {
                    cpu.ACC = *(memory.buffer + *(cpu.CR2A()));
                } else if (addr_mode == INDIRECT_ADDRESS) {
                    cpu.ACC = *(memory.buffer + *(memory.buffer + *(cpu.CR2A())));
                } else if (addr_mode == REGISTER) {
                    std::cout << "Register MOV not implemented" << std::endl;
                    exit(-1);
                }
                break;
            case STO: std::cout << "STO not implemented" << std::endl; exit(-1); break;
            case ADD: std::cout << "ADD not implemented" << std::endl; exit(-1); break;
            case SUB: std::cout << "SUB not implemented" << std::endl; exit(-1); break;
            case SCL: 
                if (*(cpu.CSLA()) == CPU::SCL_WRITE_FD) {
                    if (*(cpu.CSLB()) == CPU::SCL_FD_STDOUT) {
                        std::cout << (const char*) &cpu.ACC;
                    }
                    else if (*(cpu.CSLB()) == CPU::SCL_FD_WRITE_MEM) {
                        std::cout << "SCL_WRITE_FD WRITE_MEM not implemented" << std::endl; exit(-1);
                    }
                }
                break;
        }
    }

    return 0;
}