---
created: 2024.08.26_12:08
tags: 
---

# Day 0: C Programming & Microcontrollers Overview

## C Programming Benchmark
Do this  [[2024.08 C prerequisite check|C prerequisite benchmark >>]]

### Notes

Test your code! 
- I left everything commented out so that you could compile & run as you go.

Do not tolerate compiler warnings!
- Fix warnings when they occur
- Most errors in submitted code were flagged by the compiler!

Useful tool: Windows Calculator (Programmer Mode)
### Fixed-Width Types

Be explicit about your data types when working with bits! (E.g. addresses, registers, bytes, etc.)

Must `#include <stdint.h>`

Unsigned:
- `uint8_t`
- `uint16_t`
- `uint32_t`

Signed:
- `int8_t`
- `int16_t`
- `int32_t`


### Arithmetic
Floating-point vs integer division:

```c
int divide_this = 4;

// Both numbers integers --> Integer result
divide_this / 3;         // 1

// Literal double / float
divide_this / 3.0        // 1.333
divide_this / 3.0f       // 1.333

// Cast any of the numbers to float
float(divide_this) / 3;  // 1.333
```


### Casting

Note that `printf()` implicitly converts type to `double`.
```c
uint16_t x = 0x7EE1;
uint8_t x8 = (uint8_t)x8;    // Convert to 8-bit (Decimal: 225)
                             // Binary: 1110_0001
printf("As a signed number x8 = %d \n", x8); // Does not work as expected
                                             // Outputs 225
// Sign extended from unsigned (uint8_t) as 32-bit double:
// 0000_0000_0000_0000_0000_0000_1110_0001

printf("As a signed number x8 = %d \n", (int8_t)x8 ); // Outputs -31
// Sign extended from signed (int8_t) as 32-bit double:
// 1111_1111_1111_1111_1111_1111_1110_0001
```


### Bit Manipulations

#### Consider Using Hexadecimal Output
Recommend using hexadecimal output (`%x`) for bit manipulations. This is easier to follow than decimal, for example:

| Hex  | Binary      | Decimal |
| ---- | ----------- | ------- |
| 0xFE | `1111_1110` | 254     |
| 0x0E | `0000_1110` | 14      |

`0xFE` and `0x0E` look similar and form a clear relationship, whereas in decimal, it isn't clear how 254 and 14 relate.

#### Write Hex Values With Leading `0x`

Recommend writing hex values with a `0x` prefix to denote hexadecimal. Consider:

`The value of the variable is: 3003`

Depending on the `printf()` statement, this variable is either:
- 3003 (decimal)
- `0x3003` -> 12291 (decimal)

If we always prefix hexadecimal output with `0x`, we will always know the base.
```c
uint16_t knownValue = 0x3003;
printf("The value of this variable is: 0x%x \n", knownValue); // Prints 0x3003
printf("In decimal, this is %u \n", knownValue); // Prints 12291
```

#### Bit Set & Clear

This will be very important! Let's get good at setting and clearing individual / collections of bits.

```c
/* Setting Bits */

// Set bit 0
x = x | (0x01);

// Set bit 1
x = x | (0x01 << 1);

// Set bit 2
x = x | (0x01 << 2);

// Set bit 3
x = x | (0x01 << 3);

// In general: you can shift N positions to target that bit.

// You can even set multiple bits:

// Set bits 5 and 4
x = x | (0x03 << 4);   //  0x03        = 0000_0011
                       // (0x03 << 4)  = 0011_0000 


/* Clearing Bits */

// Clear bit 0
x = x & ~(0x01);        //   0x01  = 0000_0001
						// ~(0x01) = 1111_1110
						// It clears the bits you target in parenthesis.

// Clear bit 1
x = x & ~(0x01 << 1);    //  (0x01 << 1) = 0000_0010
                         // ~(0x01 << 1) = 1111_1101

// Clear bit 2
x = x & ~(0x01 << 2);

// Clear bits 5 and 4
x = x & ~(0x03 << 4);   //   0x03       = 0000_0011
						//  (0x03 << 4) = 0011_0000
						// ~(0x03 << 4) = 1100_1111
```

Specifying bit "sets" (`1`) and "clears" (`0`) as a single number (e.g. `1110_0011` to set bits 7, 6, 5, 1, and 0) is called a **mask**.

### Arrays

#### Easier Initialization

Two ways to pre-initialize arrays to 0:
```c
// Mass initializations
int myArray[5] = {0};

// Individual initialization
int myArray2[5] = {0, 0, 0, 0, 0};
```


#### Char* From String

C processes strings and automatically converts them to arrays:
```c
char* word = "Hello";    // Stores as {'H', 'e', 'l', 'l', 'o'};`
```


#### You (Probably) Don't Want An Array Of Pointers

This code creates an array of `char` pointers, instead of the intended array of `char`:
```c
char* char_array[6] = "Hello";  // Creates an array of 5 char* (pointers to chars)
```

Either:

```c
char char_array1[6] = "Hello"; // Explicit array sizing — use this to make a larger array
char* char_array2 = "Hello";   // Implicitly sizes the array
```


### Pointers

#### Arrays as Pointers

This gives a warning:

```c
char myVar[] = {0xAA, 0x55};
uint8_t* myVar_ptr = &myVar;
```

`myVar` is an array, which C treats as a _pointer to_ the start of the array. For non-arrays, it would be correct to use `&` operator. With arrays, the correct way to do this is:

```c
// Method 1: myVar already points to the array 1st element!
uint8_t* myVar_ptr = myVar;

// Method 2: Get address of 1st element (which is also myVar)
uint8_t* myVar_ptr = &myVar[0];
```

The compiler warning indicates the problem, as well as how to fix it. (Don't ignore compiler warnings!)

![](attachment/918bb9b1b3447811ab512eefbe47b5d5.png)

#### Pointer Indexing

C indexes addresses by pointer size. Therefore, to move to the next element of an 8-bit array:

```c
uint8_t myArray[2] = {0x00, 0x01};
uint8_t* myPtr = myArray;  // Points to first memory address of myArray
myPtr = myPtr + 1; // Points to 2nd element of myArray

// This will not work properly
myPtr = myPtr + 8;
```

The only time you need to be explicit about the number of bits is when C does not know that it is dealing with a pointer:

```c
uint32_t myPtrVal = myArray;  // myPtr holds the integer value of myArray's address
myPtrVal = myPtrVal + 32;       // myPtr holds the integer value of myArray[2]'s address
uint32_t* myPtr = (uint32_t*)myPtrVal;   // Cast to pointer, points to myArray[2]
```

### Functions

Do not place functions inside of `main()` as such:

```c
/* DO NOT DO THIS!! */
int main()
{
	// Function definition inside of main()
	uint8_t isNonZero(uint32_t input) 
	{
		return (input !=0) ? 1 : 0;
	}
	printf("5 is non-zero?  %u \n", )
}
```


Instead, place functions above or below `main()`. 

```c
/* Function Prototype */
uint8_t isNonZero(uint32_t input);

/* Function Definitions */
uint8_t isNonZero(uint32_t input) 
	{
		return (input !=0) ? 1 : 0;
	}

/* Main Program */
int main()
{
	printf("5 is non-zero?  %u \n", isNonZero(5) );
}

```

Standard practice in MSDK is to place `main()` at the bottom of the file:


# Day 1: Orientation

## Scheduling
Mon / Tues / Wed: Day 1-3
Thurs / Fri: (Unofficial) Days 4-5

RF Training will have Days 4-5 officially.

## Checkpoint for Day 0 Activities
Having done the prep and pre-lab for this series, let's ensure that everyone is set up at the same point:

C Programming:
- [x] Review C Programming Benchmark assignment

### Preparation for Training
[[2024.08.12 micros setup pre-work for ncgs]]

Hardware:
- [ ] MAX32670
- [ ] MAX78000
- [ ] MAX31723PMB1 Temperature Sensor
- [ ] 6 Jumper wires
- [ ] USB connector / adapter to demo boards

Software (Environment):
- [x] Verify Maxim PATH in MinGW (`C:/MaximSDK/Tools/MSYS2/msys.bat`)
	- Know where to find this in Explorer!
	- `arm-none-eabi-gcc -v`
	- `arm-none-eabi-gdb -v`
	- `make -v`
	- `openocd -v`
- [x] Build `Hello_World` in VS Code (`MaximSDK/Examples/MAXxxxxx/Hello_World`)
	- Check `/build` directory to verify existence of these files:
		- `HellowWorld.elf`
		- `Hello_World.map`
		- `*.d` (dependency) files
		- `*.o` (object) files

## Slides: Microcontrollers Overview
- Registers
- Architecture
- ADI's MAXIM Microcontrollers

Lab: 
- Solder headers
- Report any issues

### 


# Day 2:  Introduction to MSDK

## Running Code on a Microcontroller: Hello World!

Our first task will be to open a basic "Hello World" example and inspect its code; then, we'll walk through the entire build + flash & run process for `Hello_World` on the MAX78000FTHR board.

### Opening Hello_World

Open the MAX78000 Example `Hello_World` in VS Code.
- **From VS Code:** File -> Open Folder -> `MAX78000/Hello_World`
- **From File Explorer:** Right-click -> "Open with Code"
	- If this option does not appear, you can get it by re-installing VS Code and enabling context menu support.

Every example project folder has the following important anatomy:
- `main.c`: This is the main program. Write your code here.
- `.vscode/`: Holds project-specific configuration files.
- `Makefile`: This file tells VS Code (`make`, really) how to interact with the microcontroller. Do not edit.
- `README.md`: Documentation for the project, including description, build notes, setup, and expected output.

Opening `main.c`, every project's code will follow a similar structure:
1. Boilerplate legal stuff
2. Filename, `@brief` description and further `@details`. Read this.
3. Definitions
4. Globals
5. Functions
6. Main()

Read through the code in `main()` and verify you understand its purpose. Don't worry about _how_ various function calls work; just have an idea what you expect to have happen.

> [!question] Checkpoint
> 1. What do you expect to happen?
> 2. What files are included? Which of these are built-in libraries?

### From Computer to Microcontroller: Build + Flash & Run
1. Plug in the MAX78000FTHR to your computer.
2. Modify the target board to match the FTHR evaluation kit:
	1. Open `.vscode/settings.json`
	2. Change the `board` parameter (line 18) from "EvKit_V1" to "FTHR_RevA"
	3. Save -> `Ctrl+Shift+P` -> `Developer: Reload Window`
3. Clean the project (`Terminal (Ctrl+Shift+B)` -> `Run Build Task` -> `clean`)
	1. Follow the same steps to run the build task `clean-periph`
4. Build the project (`Run Build Task` -> `build`).
5. Flash & run (`Run Build Task` -> `flash & run`).

The MAX78000 will run "Hello World", which outputs an incrementing `count` value over the serial port. In order to view this output, install the [Serial Monitor](https://marketplace.visualstudio.com/items?itemName=ms-vscode.vscode-serial-monitor) extension. Change the `Port` to the MAX78000 (usually `COMn` — try multiple if you don't know which one) and click `Start Monitoring` to see the microcontroller's serial output.

> ![](attachment/c2dfee279fdbae4d8fbcad733bc07269.png)
