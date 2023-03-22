# Study Notes Per Week

<br/>

## Index:
   
   - ### [Week 0](#week-0-1)
   - ### [Week 1 - C](#week-1---c-1)
   - ### [Week 2 - Arrays](#week-2---arrays-1)
   - ### [Week 3 - Algorithms](#week-3---algorithms-1)

<br/>

## Week 0

   - Computers use bits to represent data due to it being simple to represent with the transistors and easy to have a lot of data with smaller effort.

   - Computers can represent different type of data with the same bits depending on the context you give it.

   - For characters computer used ASCII that is 7-bit long, then came the Extended ASCII as 8-bit long and lastly unicode that go from 8- to 32-bits.

   - Color can be represented both by Hex or RGB the same way, each red green or blue value is a byte that ranges from 0 to 255.

   - Programming languages are abstractions of the binary the computer understands, so we as developers don't have to worry about how everything is working on a deeper level, and can just write code.

   - Scratch teaches the basic of programming logic with Events, If Statements, Loops, Functions, etc.

<br/>

## Week 1 - C

   - The C programming language provides it's a very low-level implementation of programming logic concepts using types, variables, loops, functions, etc.

   - Types are important to tell the computer how many bits to alocate to a variable AND for it to undestand the context in which to use the given bits to return the correct data AND to make it so the correct methods can be applied on that variable.

   - When using If Statements it's better to invert the boolean when necessary so you don't ident the main code of the program.

   - Numbers use 32 bits to represent a value, making it simple it's 16 for positive values and 16 for negative values, this ranges from roughly positive to negative 2 billion.

   - Integer overflow happens when those 16 bits aren't enough to represent a value.

<br/>

## Week 2 - Arrays

   - The steps of compiling are: Pre-processing, Compiling, Assembling and Linking.

   - Pre-processing is when the program converts the libraries imports to all its functions' declarations.

   - Compiling is the step when the written code is converted to Assembly code.

   - Assembly code is a closer representation to what computers understand, and include mostly arithmetic operations.

   - Assembling is the step in which all that Assembly code is converted to binary.

   - Linking is the process of bringing together the code written by the programmer and all the imported libraries' code.

   - Arrays are a way to store data back-to-back on memory.

   - Strings always take 1 more byte than necessary to store a "NUL" character, which indicates the end of one.

   - It's good design to not call functions repeatedly if their results are gonna be the same.

<br/>

## Week 3 - Algorithms

   - Binary search looks at the item in the middle of a list and compare it to the target, based on that it looks to the item in the middle between the current item and the last checked item to the right or left, and keeps doing this logic until it narrows down to the target item slot.

   - The fastest way to search unknown data is through binary search if the data is sorted.

   - For sorting, with 'n' representing the Number of Steps: O(n) represents the worst-case scenario for a search, Omega(n) represents the best-case scenario. Theta(n) is when the best and worst cases are the same.

   - Selection Sort will compare the current item with every one of the remaining and swap it to the correct position.

   - Bubble Sort will compare the current item with the next one and sort them, then it will do the same now with the next item and so on until the end. 

   - Selection Sort has Theta(n^2) and Bubble Sort also has O(n^2) but with Omega(n). Therefore, Bubble Sort can be slightly better but in general there won't be neither a difference nor a consistent winner between them.

   - Merge Sort will consist in dividing the items in half as much as possible and sort the 'left-part' with the 'right part' on and on, comparing the first item of each part, saving the sorted item in a new place in memory, then comparing the first items again and again until the given items are sorted, and repeat these steps until all of the list items get sorted.

   - Merge Sort has Theta(n log n), so even though it uses more data space, it's gonna be the best option in most cases.

   - You would wanna use a recursive function to repeat a set code many times, as long as this function have a stoping condition.

   - Using a function recursively with no stop condition will create an endless loop.

   - The stop condition on a recursive function is called "Base Case", and as the name suggests, is a condition when the function don't need to be executed, breking the cycle.

   - Overall, a recursive function works to break a big problem into smaller, repetitive problems.