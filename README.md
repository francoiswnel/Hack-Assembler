# Hack Assembler
`chasm` is an assembler for the Hack language implemented in C++.

Since the Hack assembly language is very simple, the assembler is little more than a string processor which can also handle a few pseudo instructions, namely variables and labels. Even so, I have documented the code fairly verbosely so that anyone can glance at it and understand what it is doing.

# Examples of Hack assembly instructions

Here's an example program that determines the larger number of two given numbers, authored by Shimon Schocken and Noam Nisan, the creators of the Hack language and computer architecture.

    // This file is part of www.nand2tetris.org
    // and the book "The Elements of Computing Systems"
    // by Nisan and Schocken, MIT Press.
    // File name: projects/06/max/Max.asm
  
    // Computes R2 = max(R0, R1)  (R0,R1,R2 refer to  RAM[0],RAM[1],RAM[2])
  
      @R0
      D=M              // D = first number
      @R1
      D=D-M            // D = first number - second number
      @OUTPUT_FIRST
      D;JGT            // if D>0 (first is greater) goto output_first
      @R1
      D=M              // D = second number
      @OUTPUT_D
      0;JMP            // goto output_d
    (OUTPUT_FIRST)
      @R0             
      D=M              // D = first number
    (OUTPUT_D)
      @R2
      M=D              // M[2] = D (greatest number)
    (INFINITE_LOOP)
      @INFINITE_LOOP
      0;JMP            // infinite loop

There are only three instruction formats: A-instructions, C-instructions and L-instructions. 

A-instructions are addressing instructions, and start with an '@', followed by either a direct address, a location, or a variable. For example:

* `@100`
* `@LOCATION`
* `@var`
  
C-instructions are compute instructions, and are used for general purpose commands, including storing values, performing computations, and jumping to memory locations. Examples include:

* `D=A`
* `D=D-M`
* `0; JMP`
* `D; JGT`

L-instructions, or labels, are psuedo commands only used by the assembler to determine address locations. These are not converted into machine code. Examples:

* `(LOOP)`
* `(END)`
* `(JUMP_HERE)`

# Usage

`$ chasm <inputfilename.asm> <(optional) outputfilename.hack>`

# Download

Coming soon.
