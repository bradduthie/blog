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
used in the language, as this is a learning curve when getting started.

All variables initialised in C need to be stored in some address in the
computer's memory. We can conceptualise the memory of a computer as a
large block of locations where information can be stored. Each location
specifies a single <https://en.wikipedia.org/wiki/Byte>, and blocks of
bytes are used to store numeric values (Dennis Kubes discusses [Basics
of memory addresses in
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
7fc010 at Location 1 and end at 7fc017 at Location 8. To make it easier,
we can just replace these with their equivalent values in [base
10](https://en.wikipedia.org/wiki/Decimal).

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

The `#include<stdio.h>` tells the compiler to add the necessary code for
standard input and output functions (in this case `printf`), and the
program is compiled by running the below on the command line from within
the directory that the program is saved.

    gcc -Wall variable_eg.c -o variable_eg

The program variable\_eg produced by compiling above is run below.

    ./variable_eg

And the output of the `variable_eg` is shown below.

    Value of variable_1 is 10 

This is simple enough for storing a single number, but if we want to
store an array, we need to initialise a *pointer* -- that is, a
*variable that contains an address in the computer's memory*. This
address will 'point' to the location of the values of interest;
specifically, it will point to the first location in a block of
addresses that can store multiple numeric values.

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

------------------------------------------------------------------------

References
----------
