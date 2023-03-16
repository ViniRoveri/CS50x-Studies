# Study Notes Per Week

<br/>

## Week 0

   - Computers use bits to represent data due to it being simple to represent with the transistors and easy to have a lot of data with smaller effort.

   - Computers can represent different type of data with the same bits depending on the context you give it.

   - For characters computer used ASCII that is 7-bit long, then came the Extended ASCII as 8-bit long and lastly unicode that go from 8- to 32-bits.

   - Color can be represented both by Hex or RGB the same way, each red green or blue value is a byte that ranges from 0 to 255.

   - Programming languages are abstractions of the binary the computer understands, so we as developers don't have to worry about how everything is working on a deeper level, and can just write code.

   - Scratch teaches the basic of programming logic with Events, If Statements, Loops, Functions, etc.

<br/>

## Week 1

   - The C programming language provides it's a very low-level implementation of programming logic concepts using types, variables, loops, functions, etc.

   - Types are important to tell the computer how many bits to alocate to a variable AND for it to undestand the context in which to use the given bits to return the correct data AND to make it so the correct methods can be applied on that variable.

   - When using If Statements it's better to invert the boolean when necessary so you don't ident the main code of the program.

   - Numbers use 32 bits to represent a value, making it simple it's 16 for positive values and 16 for negative values, this ranges from roughly positive to negative 2 billion.

   - Integer overflow happens when those 16 bits aren't enough to represent a value.

<br/>

## Week 2

   - The steps of compiling are: Pre-processing, Compiling, Assembling and Linking.

   - Pre-processing is when the program converts the libraries imports to all its functions' declarations.

   - Compiling is the step when the written code is converted to Assembly code.

   - Assembly code is a closer representation to what computers understand, and include mostly arithmetic operations.

   - Assembling is the step in which all that Assembly code is converted to binary.

   - Linking is the process of bringing together the code written by the programmer and all the imported libraries' code.

   - Arrays are a way to store data back-to-back on memory.

   - Strings always take 1 more byte than necessary to store a "NUL" character, which indicates the end of one.

   - It's good design to not call functions repeatedly if their results are gonna be the same.