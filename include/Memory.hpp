#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include <CPU.hpp>
#include <time.h>
#include <fstream>
#include <bits/stdc++.h>
 
std::string LongToString(long long_num)
{
    std::stack<char> stringStack;
    std::string signValue = "";
 
    // if long number is negative store the negative sign to
    // the signValue variable
    if (long_num < 0) {
        signValue = "-";
        long_num = -long_num;
    }
 
    // while number is greater than 0, get last digit from it
    // and convert it to character by adding '0' to it, and
    // push to the stack.
    while (long_num > 0) {
        char convertedDigit = long_num % 10 + '0';
        stringStack.push(convertedDigit);
        long_num /= 10;
    }
 
   std::string long_to_string = "";
 
    // while stack is not empty pop the character one by one
    // and append to the resultant string.
    while (!stringStack.empty()) {
        long_to_string += stringStack.top();
        stringStack.pop();
    }
 
    // return the resulatant string value by appending
    // singValue to it.
    return signValue + long_to_string;
}

class Memory {
public:

    unsigned char* buffer;
    int N;

    Memory(int N) {
        buffer = (unsigned char*) malloc(N);
        this->N = N;
    }

    ~Memory() {
        delete buffer;
    }

    /// @brief Read the memory address given by R1 into the C2RA
    /// @param cpu The CPU
    void read(CPU* cpu) {
        *(cpu->CR2A()) = *(buffer + cpu->R1);
    }

    /// @brief Write CR2A into the memory address given by R1
    /// @param cpu The CPU
    void write(CPU* cpu) {
        *(buffer + cpu->R1) = *(cpu->CR2A());
    }

    /// @brief Push R1 and R2 to the stack
    /// @param cpu 
    void stack_push(CPU* cpu) {
        *(buffer + cpu->stack++) = cpu->R2;
        *(buffer + cpu->stack++) = cpu->R1;
    }

    /// @brief Pop R1 and R2 from the stack
    /// @param cpu 
    void stack_pop(CPU* cpu) {
        cpu->R1 = *(buffer + --cpu->stack);
        cpu->R2 = *(buffer + --cpu->stack);
    }

    void dump() {
        std::ofstream file(LongToString(time(0)).append(".dump"), std::ios::binary | std::ios::out);
        
        for (int i = 0; i < N; i++) {
            file << *(buffer + i);
        }

        file.flush();
        file.close();
    }
};

#endif