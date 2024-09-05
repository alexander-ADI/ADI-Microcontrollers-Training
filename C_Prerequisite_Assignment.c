/* Includes */
#include <stdint.h> // For uint8_t, uint32_t, etc.
#include <stdio.h>  // For printf()

/* Typedefs */

typedef enum {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} days_of_the_week_t;

/* Prototypes */


/* Main */
int main(int argc, char* argv) 
{
    // If you can complete this code, you are ready for the NCG training!
    // Please read comments carefully and complete the code where needed.
    // Note: Comments with "..." means your answer would go there.
    // Some code is provided and commented out; this is so that you can compile & run as you go.
    // Please uncomment as needed!

    // You can run the code on this online compiler, if you don't have GCC set up:
    //      https://www.onlinegdb.com/online_c_compiler
    


    /* 01. Numbers, Bits, Types */

    uint8_t x = 0x74;

    // What is x in binary? In decimal?
    // Just write it as comments here:
    //
    // Binary: ... 
    // Decimal: ...
    
    // Now fill in the below printf() statement below to output the value:
    //      - x (hex format)
    //      - x (decimal format)
    // E.g. With a different value for x, the output might look like:
    //      Hex = 0xA, Decimal = 10
    
    printf(".... \n");

    // It should be obvious when a number is hexadecimal or not — make sure your 
    // hex output is formatted with a "0x" prefix to distinguish it from a decimal number.
    // E.g. 0x74, not just "74"

    // Note: The above should pass the _variable_ x, and NOT hard-coded text values.
    // E.g. A hard-coded text answer (with different values) would look like: 
    //      printf("Hex = 0x5, Decimal = 5");
    

    // Use a bitwise-OR to "set" (make 1) bit 0
    // ...

    // Use a bitwise-AND to "clear" (make 0) bit 4
    // ...
    
    // Print the new value of x (in hex). 
    // ...

    // Check the output of your program so far and compare to your predictions.
    // Does the output make sense?
    
    // What advantage does formatting the output as hex provide over decimal when doing bit manipulations?
    // ...


    // Assume the following is output of a temperature probe where every 128 bits represents 1 degree C.
    uint16_t bits = 0x0CD6;

    // Do the (floating-point) math to output the temperature in degrees C:
    // ...
    uint16_t tempC = 0; // <--- this is just a placeholder
    printf("The temperature is %f degrees C", tempC);

    // Sanity check: You should get around 25.672 degrees C.



    // In this next part, we'll have two values: 
    //      - a most-significant byte (MSB) 
    //      - a least-significant byte (LSB)
    uint8_t MSB = 0xF3;
    uint8_t LSB = 0x2A;

    // We can print these to the terminal to look like a single value
    printf("MSB_LSB: 0x%X%X", MSB, LSB);
    
    // But let's actually combine them into a single variable.

    // First, bit shift the MSB left by 8. Store it in a variable called "data".
    // Hint: Consider the number of bits needed to store this value. What type should you use?
    // ...

    // You should now have the following two values:
    // data: 0xF300 (0b_1111_0011_0000_0000)
    // LSB:  0x002A (0b_0000_0000_0010_1010)

    // Use a bitwise operation to combine LSB bits into the "data" variable (the MSB bits)
    // ...

    // Does it print as 0xF32A? (It should!)

    // What is this value as a 16-bit signed number? (It should be negative -- do you know why?)

    // Assume this is another temperature like from before. Print out the signed value. (Should be -25.672 degrees C.)

    
    

    /* Arrays and Loops */
    
    // Let's make an array of 5 unsigned 8-bit integers. (size = 5, type is uint8_t)
    // Call it "int_array"
    // Initialize all values to 0.
    // ...

    // Store the word "Hello" into a character array called hello
    // ...

    // Set the second letter 'e' to 'a' (Hello --> Hallo)
    // ...

    // Print the char array using a for loop. Add newline at the end  => "Hallo\n"
    // ...


    /* Functions & Headers */

    // Make a function called isNonZero():
    //      - Accepts a uint32_t called input
    //      - Return type uint8_t:
    //          Returns 1 if input is non-zero
    //          Returns 0 if input is zero
    //
    // Make this function in this file (main.c) and add its prototype to the 
    // "Prototypes" section AT THE TOP of this file.
    //
    // ALERT: This is an easy mistake to make!
    // Add the prototype at the top (outside main), and implement the function
    // at the bottom of this file (again, outside main). 
    // You should not be trying to do any of this in main()!

    // Testing your function: Just uncomment the 3 lines below. Do not edit them!

    // uint32_t nonZeroInput = 5;
    // uint8_t isNonZero_test = isNonZero( nonZeroInput );
    // printf("nonZeroInput is non-zero? : %u \n", isNonZero_test);
    


    // How comfortable are you working with header (*.h) files?
    // Think about:
    //      - #include statements
    //      - declaring function prototypes inside of headers
    //      - #define statements
    // No need to do anything with these; just please respond for each of the above.
    // Please be honest so I know what you know vs. what you don't know.
    // I will address any knowledge gaps on Day 1.
    
    // Your answer here (as comment or printf, your choice):
    printf("Please modify this to indicate your comfort with using header files... \n");


    /* Pointers */
    
    // Here is a set of variables:
    uint8_t myNum = 5;
    uint8_t myVar[2] = {0x55, 0xAA};      

    // Fun fact: 0x55, 0xAA are both common to use as "test" values in embedded
    // programming because they are easy to see as a signal. (0b_0101_0101 and 0b_1010_1010)

    // Make a pointer to myNum and myVar:
    // uint8_t* myNum_ptr = ...
    // uint8_t* myVar_ptr = ...
    // Uncomment these lines^

    // Make a pointer to the 2nd element of myVar (the 0xAA value) using address-of
    // uint8_t* myVar_ptr2 = ...
    // Uncomment this line^

    // Modify the 2nd element via the pointer (de-addressing) to be 0x11
    // ...

    // What value does the following code point to?
    // uint8_t* unknownPtr = myVar_ptr + 1;
    // Uncomment ^

    // Prove it! 
    // Dereference the pointer to get the value that unknownPtr points to:
    // uint8_t unknownPtr_value = ...
    // printf("UnknownPtr_value = 0x%x \n", unknownPtr_value);
    // Uncomment ^^
    
    

    /* Typedefs: Enums & Structs */

    // Theoretically, you could probably use ChatGPT to fill this in. But...
    //
    // PLEASE DO NOT DO THIS.
    //
    // You don't get "points" for getting anything right in this document. Effort is more
    // important than correctness.
    //
    // The goal is an accurate assessment of everyone's knowledge and ability using C.

    // If this final part takes you forever or is extremely confusing, please just 
    // leave it blank and fill in the printf here to explain what you'd like to review:
    printf("Please modify this line to reflect your familiarity / understanding of typedefs, enums, or structs. \n");


    // In the "Typedefs" section at the top of this file, I defined an enum type for "days of the week".
    // Use this type in the following line to make a variable called "today", with the value "Saturday".
    // ...

    // Write a conditional to check if the value of the day is a weekend; if so, output "It's the weekend!"
    // ...


    // Define a struct type (in the typedefs section, not here) that can hold the following:
    //      - days_of_the_week_t weekday
    //      - float hours_worked
    // Call it week_log_t

    // Then create an instance of this struct and initialize its values to your choice.
    // week_log_t log = ...
    // printf("I have worked %d hours", log); 


    /* That's it!
     * You're done with the pre-work for the microcontroller training.
     * Please send me the completed file via email.
     * Thank you for your work!
     */
}