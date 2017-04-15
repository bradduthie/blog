Working with
[arrays](https://en.wikipedia.org/wiki/Array_data_structure) of data
(e.g., numeric vectors and matrices) is routine for scientific
researchers doing statistics or modelling. In programming languages with
which most researchers are probably familiar (e.g.,
[R](https://www.r-project.org/), [python](https://www.python.org/), and
[MATLAB](https://uk.mathworks.com/products/matlab.html)), setting values
into a some sort of array is straightforward. In R, we can define a
vector `data_vec` with one line of code.

    data_vec <- c(1, 5, 3, 6);
    print(data_vec);

    ## [1] 1 5 3 6

We can similarly define a two by two dimensional matrix.

    data_mat <- matrix(data = c(1, 5, 3, 6), nrow = 2, ncol = 2);
    print(data_mat);

    ##      [,1] [,2]
    ## [1,]    1    3
    ## [2,]    5    6

In C, this kind of assignment doesn't work, which can be intimidating at
first for researchers new to the language. Instead, memory needs to be
allocated appropriately using *pointers*, which identify where in a
computer's memory variables are located. Thinking about and using
pointers effectively can take a bit of getting used to, but being able
to use C to do so can massively speed up computations [\[1\]](#foot1),
making the investment worthwhile for researchers doing computationally
intense statistical or simulation modeling. The intended audience of
this post includes researchers who are newcomers to using C, or might be
interested in learning C as means to speed up their analyses, perhaps
through [integration with R](http://adv-r.had.co.nz/C-interface.html)
(more on this in a future post). I'm not going to focus so much on how
to code in C, but rather the logic of what pointers are and how they are
used in the language, as this is a major learning curve when getting
started.

All variables initialised in C need to be stored in some address in the
computer's memory. We can think about the memory of a computer as a
large block of locations where information can be stored. Each location
specifies a single [byte](https://en.wikipedia.org/wiki/Byte), and
blocks of bytes are used to store numeric values (Dennis Kubes discusses
[Basics of memory addresses in
C](http://denniskubes.com/2012/08/17/basics-of-memory-addresses-in-c/)
in more detail). If we tell C to print off a set of locations, these are
the kinds of values we get.

<table>
<colgroup>
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
</colgroup>
<thead>
<tr class="header">
<th>Location 1</th>
<th>Location 2</th>
<th>Location 3</th>
<th>Location 4</th>
<th>Location 5</th>
<th>Location 6</th>
<th>Location 7</th>
<th>Location 8</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>0x7fc010</td>
<td>0x7fc011</td>
<td>0x7fc012</td>
<td>0x7fc013</td>
<td>0x7fc014</td>
<td>0x7fc015</td>
<td>0x7fc016</td>
<td>0x7fc017</td>
</tr>
</tbody>
</table>

The numbers above are in
[hexidecimal](https://en.wikipedia.org/wiki/Hexadecimal), as indicated
by the `0x` at the start of each. The numbers therefore start from
7fc010 at Location 1 and end at 7fc017 at Location 8. To make it easier
to conceptualise, we can just replace these with their equivalent values
in [base 10](https://en.wikipedia.org/wiki/Decimal).

<table>
<colgroup>
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
<col width="12%" />
</colgroup>
<thead>
<tr class="header">
<th>Location 1</th>
<th>Location 2</th>
<th>Location 3</th>
<th>Location 4</th>
<th>Location 5</th>
<th>Location 6</th>
<th>Location 7</th>
<th>Location 8</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>8372240</td>
<td>8372241</td>
<td>8372242</td>
<td>8372243</td>
<td>8372244</td>
<td>8372245</td>
<td>8372246</td>
<td>8372247</td>
</tr>
</tbody>
</table>

So we have a block of addresses where variable values can be stored.
This is all that we get to work with in C. There is no inherent
structure for representing arrays in C, so if we want to put numbers
into an array of one or more dimensions, then we need to create an array
ourselves. We can do this in C is using the `malloc` function in the [C
standard library](https://en.wikipedia.org/wiki/C_standard_library) to
set aside blocks of memory for multiple numeric values. I'll get to how
to do this below, but first I need to explain how pointers are
initialised in C. When assigning a single number to a variable, it is
not necessary to allocate memory explicitly. For example, we can define
an integer `int variable_1` and assign it to a value of
`variable_1 = 10`. The very short program below does this and prints out
a value of 10 before exiting.

    #include<stdio.h>

    int main(void){

        int variable_1;
        variable_1 = 10;
        printf("\n Value of variable_1 is %d \n", variable_1);

        return 0;
    }

The `#include<stdio.h>` tells the
[compiler](https://en.wikipedia.org/wiki/Compiler) to add the necessary
code for standard input and output functions (in this case `printf`),
and the program is compiled by running the below on the command line
from within the directory that the program is saved.

    gcc -Wall variable_eg.c -o variable_eg

The program `variable_eg` produced by compiling above is run below.

    ./variable_eg

And the output of the `variable_eg` is shown below.

    Value of variable_1 is 10 

**Storing the values of a one-dimensional array**

The above is simple enough for storing a single number, but if we want
to store an array, we need to initialise a *pointer* -- that is, a
*variable that contains an address in the computer's memory*. This
address will 'point' to the location of the values of interest;
specifically, it will point to the first location in a block of
addresses that can store multiple numeric values. Each element in the
array will occupy a single address. To initialise a pointer, we need to
use the [dereference
operator](https://en.wikipedia.org/wiki/Dereference_operator), which in
C is an asterisk (this might seem confusing at first because `*`
performs two functions in C -- dereferencing and multiplying, but the
context makes it easy to tell the two uses apart). When seeing an
asterisk in front of a variable, it can be read as 'the value at', so
`*pointer_1` is 'the value at location `pointer_1`'. We can intialise a
pointer of [data type](https://en.wikipedia.org/wiki/C_data_types)
`double` in C as follows [\[2\]](#foot2).

    double *pointer_1;

We can think of the above instruction as 'initialise a value of type
double at location pointer\_1'. To start assigning numbers to an array,
we need to define how many blocks of size `double` need to be allocated
using the function `malloc`. As an example, we'll start with a simple
one dimensional array of size 5.

    pointer_1 = malloc(5 * sizeof(double));

In the above, we've told C to allocate a block of memory starting at the
location `pointer_1`, and extending to a length the size of five
`double` values. The `sizeof` operator, as you might expect, [returns a
value](https://en.wikipedia.org/wiki/Sizeof) indicating how much memory
the data type takes to store. This will allow us to place five `double`
values in a vector element of five at a location in the memory starting
at `pointer_1`. For the sake of argument, let's assume that
`pointer_1 = 8372240`, and so equals the address in the first location
of our above table.

<table>
<colgroup>
<col width="8%" />
<col width="11%" />
<col width="11%" />
<col width="11%" />
<col width="11%" />
<col width="11%" />
<col width="11%" />
<col width="11%" />
<col width="11%" />
</colgroup>
<thead>
<tr class="header">
<th></th>
<th>pointer_1</th>
<th>Location 2</th>
<th>Location 3</th>
<th>Location 4</th>
<th>Location 5</th>
<th>Location 6</th>
<th>Location 7</th>
<th>Location 8</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>Address</td>
<td>8372240</td>
<td>8372241</td>
<td>8372242</td>
<td>8372243</td>
<td>8372244</td>
<td>8372245</td>
<td>8372246</td>
<td>8372247</td>
</tr>
</tbody>
</table>

Note that 8372240 is the address of the location (`pointer_1`); the
**value** at the location is `*pointer_1`. Using `malloc` in the code
above, we have allocated the five locations 8372240-8372244 for use in
our array. If we want to put a value in the location, we can use the
dereference operator.

    *pointer_1 = 3;

The value stored in location `pointer_1` is now 3. To store values in
the other four locations that we've allocated for use, we can simply add
one to the value of the location with the dereference operator. In this
case the address of **Location 2** in the table above is simply one more
than the value of `pointer_1` itself, `pointer + 1`. So we can put a
value in the this location in the same way by indicating the correct
address.

    *(pointer_1 + 1) = 5;

The above stores the value five in the **Location 2**. On the left hand
side of the equaiton, we can read this as 'value at the location
pointer\_1 plus one'. The parentheses tells C to compute `pointer_1 + 1`
before applying the dereference opeartor, so the correct address is
identified within parentheses and dereferenced with the asterisk outside
of them. We can assign five random values and print them using the
function below.

    #include<stdio.h>

    int main(void){

        int i;
        double *pointer_1;
        
        *pointer_1       = 3;
        *(pointer_1 + 1) = 5;
        *(pointer_1 + 2) = 4;
        *(pointer_1 + 3) = 1;
        *(pointer_1 + 4) = 7;
        
        for(i = 0; i < 5; i++){
            printf("%f\n", *(pointer_1 + i));
        }

        free(pointer_1);

        return 0;
    }

After allocating memory with `malloc`, it is important to free the
memory using `free` when it is no longer needed to avoid a [memory
leak](https://en.wikipedia.org/wiki/Memory_leak).

Note how there are five elements in the array, but the last element in
the array is `*(pointer_1 + 4)` because the array effectively starts at
`*(pointer + 0)`. Hence, arrays in C are [zero
indexed](https://en.wikipedia.org/wiki/Zero-based_numbering); the first
element starts with zero and ends with a value of one less than the
total length of the array. This takes some getting used to for many
researchers who learned to code in R, but it also makes the logic of
`for` loops a bit more intuitive, as is clear from the function above.
This also brings me to the short-hand bracket notation for using arrays
in C. An easier way to write `*(pointer_1 + element)` is simply
`pointer_1[element]`.

Hence, we can usually think about an array that we create in C *as if*
`array_1[i]` means 'the `i`th element of the array `array_1`', but it
it's useful to keep in mind that what it *really* refers to is 'the
value at the memory location `array_1 + i`. With this in mind, we can
re-write the above program as follows, swapping the variable name
`pointer_1` with `array_1`.

    #include<stdio.h>

    int main(void){

        int i;
        double *array_1;
        
        array_1[0] = 3;
        array_1[1] = 5;
        array_1[2] = 4;
        array_1[3] = 1;
        array_1[4] = 7;
        
        for(i = 0; i < 5; i++){
            printf("%f\n", array_1[i]);
        }

        free(array_1);

        return 0;
    }

The above certainly looks a bit cleaner.

This was just a very brief introduction to the logic of pointers and how
to use them to make arrays in C. It is not [everything you need to know
about pointers](http://boredzo.org/pointers/), but a starting point for
being able to work with datasets.

------------------------------------------------------------------------

<a name="foot1">\[1\]</a> This is especially true for researchers coding
in R for computationally intense tasks that include multiple loops.
Running an individual-based model can be 10 to 100 times faster in C
than it is in R or MATLAB, which I was surprised to find out while
writing [the code](https://github.com/bradduthie/Duthie_and_Falcy_2013)
for what would become the [first
chapter](http://www.sciencedirect.com/science/article/pii/S0304380013000021)
of my doctoral dissertation. Since then, I do about half my coding in R,
shifting to C whenever something needs to run fast.

<a name="foot2">\[2\]</a> Double is a precise type of value that can
represent real numbers appropriately for most tasks in scientific
computing. If only integer values are needed, use `int` instead, which
is exact and uses less memory.

------------------------------------------------------------------------

References
----------
