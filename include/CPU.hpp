#ifndef CPU_H
#define CPU_H

class CPU {
public:
    //  +-----------+
    //  | Registers |
    //  +-----------+

    /// @brief Program Counter, holds the address of the next instruction to be fetched from memory
    unsigned long long PC = 0;
    /// @brief System call register, first byte is operation, second is a relevant operand
    unsigned short SCL = 0;
    /// @brief Primary register, used by memory class as address register
    unsigned long long R1 = 0;
    /// @brief Secondary register
    unsigned long long R2 = 0;
    /// @brief Accumulator, ALU register, holds the result of the last arithmetic operation
    unsigned long long ACC = 0;
    /// @brief Stack pointer, points to the top of the stack in memory
    unsigned long long stack = 0;
    /// @brief Flags register
    unsigned char flags = 0;

    //  +------------+
    //  | Flag masks |
    //  +------------+

    static const char FLAG_OVERFLOW = 0b1;
    static const char FLAG_NEGATIVE = 0b10;

    //  +-----------+
    //  | SCL masks |
    //  +-----------+

    /// @brief Write the value in the ACC to specified file descriptor
    static const char SCL_WRITE_FD      = 0;
    /// @brief File descriptor for SCL_WRITE_FD. Writes to console output.
    static const char SCL_FD_STDOUT     = 0;
    /// @brief File descriptor for SCL_WRITE_FD. Writes to memory address given by R1.
    static const char SCL_FD_WRITE_MEM  = 1;

    //  +-----------------------------+
    //  | Sub register access methods |
    //  +-----------------------------+

    unsigned int* IR1A() {
        return (unsigned int*) &R1;
    }

    unsigned int* IR1B() {
        return ((unsigned int*) &R1) + 1;
    }

    unsigned short* SR1A() {
        return (unsigned short*) &R1;
    }

    unsigned short* SR1B() {
        return ((unsigned short*) &R1) + 1;
    }

    unsigned short* SR1C() {
        return ((unsigned short*) &R1) + 2;
    }

    unsigned short* SR1D() {
        return ((unsigned short*) &R1) + 3;
    }

    unsigned char* CR1A() {
        return (unsigned char*) &R1;
    }

    unsigned char* CR1B() {
        return ((unsigned char*) &R1) + 1;
    }

    unsigned char* CR1C() {
        return ((unsigned char*) &R1) + 2;
    }

    unsigned char* CR1D() {
        return ((unsigned char*) &R1) + 3;
    }

    unsigned char* CR1E() {
        return ((unsigned char*) &R1) + 4;
    }

    unsigned char* CR1F() {
        return ((unsigned char*) &R1) + 5;
    }

    unsigned char* CR1G() {
        return ((unsigned char*) &R1) + 6;
    }

    unsigned char* CR1H() {
        return ((unsigned char*) &R1) + 7;
    }



    unsigned int* IR2A() {
        return (unsigned int*) &R2;
    }

    unsigned int* IR2B() {
        return ((unsigned int*) &R2) + 1;
    }

    unsigned short* SR2A() {
        return (unsigned short*) &R2;
    }

    unsigned short* SR2B() {
        return ((unsigned short*) &R2) + 1;
    }

    unsigned short* SR2C() {
        return ((unsigned short*) &R2) + 2;
    }

    unsigned short* SR2D() {
        return ((unsigned short*) &R2) + 3;
    }

    unsigned char* CR2A() {
        return (unsigned char*) &R2;
    }

    unsigned char* CR2B() {
        return ((unsigned char*) &R2) + 1;
    }

    unsigned char* CR2C() {
        return ((unsigned char*) &R2) + 2;
    }

    unsigned char* CR2D() {
        return ((unsigned char*) &R2) + 3;
    }

    unsigned char* CR2E() {
        return ((unsigned char*) &R2) + 4;
    }

    unsigned char* CR2F() {
        return ((unsigned char*) &R2) + 5;
    }

    unsigned char* CR2G() {
        return ((unsigned char*) &R2) + 6;
    }

    unsigned char* CR2H() {
        return ((unsigned char*) &R2) + 7;
    }


    unsigned char* CSLA() {
        return (unsigned char*) &SCL;
    }

    unsigned char* CSLB() {
        return ((unsigned char*) &SCL) + 1;
    }
};

#endif