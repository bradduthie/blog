This document is a practical guide for getting started using for and while loops in R. My goal is to help readers who are familiar with R, but *unfamiliar* with using loops in R, get started coding with loops. This guide was original written for an event in Stirling Coding Club, and a version of this document (formatted slightly differently) is available [here](https://stirlingcodingclub.github.io/using_loops/loop_notes.html).

------------------------------------------------------------------------

-   [Introduction: What is a loop?](#what_is_loop)
-   [The for loop in R: getting started](#for_gs)
-   [The for loop in R: a real example](#for_re)
-   [The for loop in R: nested loops](#for_more)
-   [The while loop in R](#while_loop)
-   [Practice problems](#practice)
-   [Additional resources](#whatelse)

------------------------------------------------------------------------

<a name="what_is_loop">Introduction: What is a loop?</a>
========================================================

Being able to use loops is a critical skill in programming and working with large arrays of data. Loops make it possible to repeat a set of instructions (i.e., code) `for` a particular set of conditions (e.g., for a range of numbers from 1 to 1000), or `while` a set of conditions still applies (e.g., while a value is still greater than zero). Hence, the use of [for loops](https://en.wikipedia.org/wiki/For_loop) and [while loops](https://en.wikipedia.org/wiki/While_loop) are fundamental for writing and running code efficiently (note that [other types](https://en.wikipedia.org/wiki/Do_while_loop) of loops also exist, but I will not focus on them now). Here I will introduce the key concepts of programming with loops, with particular emphasis on getting started with some practical uses of loops in the R programming language for scientific researchers.

The R programming language includes many base level functions to perform tasks that would otherwise require loops (e.g., functions such as [apply](https://www.rdocumentation.org/packages/base/versions/3.5.2/topics/apply) and [tapply](https://www.rdocumentation.org/packages/base/versions/3.5.2/topics/tapply), which effectively repeat a set of instructions to summarise values in an array). Tens of thousands of downloadable [packages](https://cran.r-project.org/) (code, data, and documentation bundled together, written by and for R users) are available in R, most of which include their own functions that can perform specific tasks required in scientific research (e.g., [vegan](https://github.com/vegandevs/vegan), [dplyr](https://dplyr.tidyverse.org/), and [shiny](https://github.com/rstudio/shiny)). Hence, successful data analysis in R can often just be a matter of finding and using an appropriate and reliable package for a given task. Nevertheless, unique data sets and models often require unique code, so base and package functions cannot always be found to do custom tasks. In many situations, the ability to use loops to repeat tasks will make it possible to quickly and confidently develop reproducible code in data analysis. In the long term, this will likely save time; in the short term, it creates an opportunity to develop and practice coding skills.

Below I will demonstrate how to use [for loops](https://en.wikipedia.org/wiki/For_loop) and [while loops](https://en.wikipedia.org/wiki/While_loop).

-   A **for loop** iterates a set of instructions *for* a predetermined set of conditions (i.e., when you know how many times you need to iterate the same set of instructions)
-   A **while loop** iterates a set of instructions *while* some condition(s) remains satisfied (i.e., when you might not know how many times you need to iterate the same set of instructions, but you do know when the iterations need to stop)

It is not important to completely understand the two definitions above before getting started, just as it is not important to understand a verbal definition of 'multiplication' before learning to multiply two numbers. Seeing examples of loops in practice will make it clear how they work and when to use them. In the next section, I will therefore start with some key examples to show how for loops can be used in R. I will then do the same with while loops. Finally, I will provide some practice problems and additional resources for using loops in programming.

<a name="for_gs">The for loop in R: getting started</a>
=======================================================

Different languages have differ syntaxes for writing for loops. In R, the syntax is as follows:

``` r
for(index in set_of_conditions){
  # Code that gets repeated for each condition
}
```

In the above, anything within the bracketed `{` `}` gets repeated with `index` being substituted, sequentially, for all possible conditions `in` the `set_of_conditions`. A more concrete example will help:

``` r
for(i in 1:10){
  print(i);
}
```

We can interpret the line `for(i in 1:10)` verbally to explain what is going on in plain English:

> Substitute the index `i` for each value from 1 to 10 (i.e., 1, 2, 3, ..., 8, 9, 10), and run the following bracketed code with each value in sequence. In other words, run the bracketed code first with `i = 1`, then with `i = 2`, and so forth until finishing the loop with `i = 10`.

Given the above explanation, we can predict what will happen with the example code above, which I now run below.

``` r
for(i in 1:10){
  print(i);
}
```

    ## [1] 1
    ## [1] 2
    ## [1] 3
    ## [1] 4
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 8
    ## [1] 9
    ## [1] 10

The code has printed integers from 1 to 10. This is obviously a very simple example of using a loop, but it highlights the basic idea. **There are three key points that I want to note with this example before moving on**

**1. the above for loop is effectively doing the same as the code below**

``` r
print(1);
print(2);
print(3);
print(4);
print(5);
print(6);
print(7);
print(8);
print(9);
print(10);
```

    ## [1] 1
    ## [1] 2
    ## [1] 3
    ## [1] 4
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 8
    ## [1] 9
    ## [1] 10

In the above, I have [unrolled](https://en.wikipedia.org/wiki/Loop_unrolling) the for loop that printed off integers from 1 to 10. But the result is the same. The advantage of using the loop is that it avoids the need to repeat the same code more times than is necessary (consider if we wanted to print values from 1 to 10000 -- much less needs to be changed when using the for loop, and much fewer lines of code need to be written). There is no hard rule for when to use a loop versus when to repeat the same line(s) of code multiple times; it is generally best to use whichever method is most readable to (future) you. In practice, when getting started, it might help to think about what the loops would look like if unrolled -- or even write them both ways to confirm that a loop is working as intended.

**2. There is nothing special about `i`**

In a lot of books and online examples introducing loops, the index `i` is used as it is in my above example. But there is nothing special about `i`, just as there is nothing special about the variable `x` in algebra. The index `i` just serves as a placeholder for whatever actual value is going to be substituted from the set of conditions (i.e., values from 1 to 10 in the above example). We get the exact same result with the following code:

``` r
for(value_to_be_printed in 1:10){
  print(value_to_be_printed);
}
```

    ## [1] 1
    ## [1] 2
    ## [1] 3
    ## [1] 4
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 8
    ## [1] 9
    ## [1] 10

The above use of the long `value_to_be_printed` instead of the shorter `i` seems unnecessary at first, but it is actually often helpful to give indices specific names like this to make code more readable. Doing so becomes especially helpful when working with multiple indices and loops within loops (an example of this later), or when the number of lines between the starting `{` and ending `}` brackets becomes larger than can be viewed on a computer screen.

**3. There is nothing special about `1:10`**

A lot of introductions to for loops in R will show the set of values to be iterated in this way, but there are equally acceptable ways to write it. For example, consider the below:

``` r
for(i in c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)){
  print(i);
}
```

    ## [1] 1
    ## [1] 2
    ## [1] 3
    ## [1] 4
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 8
    ## [1] 9
    ## [1] 10

Or even the below, where I first define the set of values with its own variable named `the_set`:

``` r
the_set <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
for(i in the_set){
  print(i);
}
```

    ## [1] 1
    ## [1] 2
    ## [1] 3
    ## [1] 4
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 8
    ## [1] 9
    ## [1] 10

The order of numbers **does** matter. For example, we could reverse the order in which numbers are printed by reversing the set of values:

``` r
for(i in 10:1){
  print(i);
}
```

    ## [1] 10
    ## [1] 9
    ## [1] 8
    ## [1] 7
    ## [1] 6
    ## [1] 5
    ## [1] 4
    ## [1] 3
    ## [1] 2
    ## [1] 1

We could even print off the numbers in a random order with the below:

``` r
random_vec <- sample(x = 1:10, size = 10);
for(i in random_vec){
  print(i);
}
```

    ## [1] 2
    ## [1] 10
    ## [1] 9
    ## [1] 1
    ## [1] 3
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 4
    ## [1] 8

It is unlikely that there would ever be a need to reverse the order of a set, and for most for loops, the simple `1:N` format will usually be all that that is needed. The point is that there is no reason to feel *constrained* to using this format when writing loops.

<a name="for_re">The for loop in R: a real example</a>
======================================================

The examples above were intended only to introduce the general idea of using for loops, and their specific syntax in R. In coding, there is rarely such a need to use for loops to simply print off values. More often, for loops are used to repeat the same set of (often complex) instructions for a set of values. As a real example, I will use use the `nhtemp` data set in R.

``` r
data(nhtemp); # Reads in the data set
```

The `nhtemp` data set includes a vector that stores the mean annual temperature in degrees Fahrenheit in [New Haven](https://www.google.com/maps/place/New+Haven,+CT,+USA/@40.5046762,-74.5979605,6.75z/data=!4m5!3m4!1s0x89e7d8443a8070e5:0xf6a354c659b264ed!8m2!3d41.308274!4d-72.9278835), Connecticut (USA), from 1912 to 1971.

``` r
print(nhtemp);
```

    ## Time Series:
    ## Start = 1912 
    ## End = 1971 
    ## Frequency = 1 
    ##  [1] 49.9 52.3 49.4 51.1 49.4 47.9 49.8 50.9 49.3 51.9 50.8 49.6 49.3 50.6
    ## [15] 48.4 50.7 50.9 50.6 51.5 52.8 51.8 51.1 49.8 50.2 50.4 51.6 51.8 50.9
    ## [29] 48.8 51.7 51.0 50.6 51.7 51.5 52.1 51.3 51.0 54.0 51.4 52.7 53.1 54.6
    ## [43] 52.0 52.0 50.9 52.6 50.2 52.6 51.6 51.9 50.5 50.9 51.7 51.4 51.7 50.8
    ## [57] 51.9 51.8 51.9 53.0

In the above data, the first value 49.9 is therefore the mean temperature from 1912, and the last value 53 is the mean temperature from 1971. We can print these off by using the indices `nhtemp[1]` and `nhtemp[60]` (as there are `length(nhtemp)` = 60 temperature years in `nhtemp`).

``` r
print(nhtemp[1]);
```

    ## [1] 49.9

``` r
print(nhtemp[60]);
```

    ## [1] 53

We might want to use these data to analyse how the temperature in New Haven has changed over the years from 1912-1972. The first task would likely be to convert the temperatures from Fahrenheit to Celsius. The formula for conversion is as follows,

![](../images/Celsius_to_Fehrenheit.png)

To get T<sub>Celsius</sub>, it is not actually necessary to use a for loop in R; this can be done in one line of code:

``` r
T_Celsius <- (5/9) * (nhtemp - 32);
print(T_Celsius);
```

    ## Time Series:
    ## Start = 1912 
    ## End = 1971 
    ## Frequency = 1 
    ##  [1]  9.944444 11.277778  9.666667 10.611111  9.666667  8.833333  9.888889
    ##  [8] 10.500000  9.611111 11.055556 10.444444  9.777778  9.611111 10.333333
    ## [15]  9.111111 10.388889 10.500000 10.333333 10.833333 11.555556 11.000000
    ## [22] 10.611111  9.888889 10.111111 10.222222 10.888889 11.000000 10.500000
    ## [29]  9.333333 10.944444 10.555556 10.333333 10.944444 10.833333 11.166667
    ## [36] 10.722222 10.555556 12.222222 10.777778 11.500000 11.722222 12.555556
    ## [43] 11.111111 11.111111 10.500000 11.444444 10.111111 11.444444 10.888889
    ## [50] 11.055556 10.277778 10.500000 10.944444 10.777778 10.944444 10.444444
    ## [57] 11.055556 11.000000 11.055556 11.666667

But if we know in advance that we will be doing some more complex data manipulation later, in might make sense to start out doing the conversion within a loop instead. To use a loop, we can first define the vector `T_Celsius`, then apply the conversion for each value in `nhtemp`.

``` r
T_Celsius <- NULL;
for(year in 1:length(nhtemp)){
  T_Celsius[year] <- (5/9) * (nhtemp[year] - 32);
}
print(T_Celsius);
```

    ##  [1]  9.944444 11.277778  9.666667 10.611111  9.666667  8.833333  9.888889
    ##  [8] 10.500000  9.611111 11.055556 10.444444  9.777778  9.611111 10.333333
    ## [15]  9.111111 10.388889 10.500000 10.333333 10.833333 11.555556 11.000000
    ## [22] 10.611111  9.888889 10.111111 10.222222 10.888889 11.000000 10.500000
    ## [29]  9.333333 10.944444 10.555556 10.333333 10.944444 10.833333 11.166667
    ## [36] 10.722222 10.555556 12.222222 10.777778 11.500000 11.722222 12.555556
    ## [43] 11.111111 11.111111 10.500000 11.444444 10.111111 11.444444 10.888889
    ## [50] 11.055556 10.277778 10.500000 10.944444 10.777778 10.944444 10.444444
    ## [57] 11.055556 11.000000 11.055556 11.666667

There are a few things to note here.

-   In the first line of the above, using the `rep` function, I have defined `T_Celsius` to be a null vector.
-   I have used the index `year` rather than `i` to make it easier to remember what I am looping over.
-   The loop goes from 1 to the length of `nhtemp` (`length(nhtemp)` = 60). I could have instead just written `1:60`, but the above has the advantage that if the length of `nhtemp` changes for some reason, the loop will still work. As a exercise, try running the above code for `1:40` or `1:80` to see what happens when the number of years to loop over does not match the number of years in `nhtemp`.

Now say that we actually want to know the *change* in temperature from one year to the next, and to make a new vector `Temp_ch` that stores the difference in degrees Celsius from `year` to `year - 1`. While there are ways to make such a vector in R without a loop, using a for loop is probably most intuitive way to do it.

``` r
T_Celsius <- NULL;
Temp_ch   <- NULL;
for(year in 1:length(nhtemp)){
  T_Celsius[year] <- (5/9) * (nhtemp[year] - 32);
  Temp_ch[year]   <- T_Celsius[year] - T_Celsius[year - 1];
}
print(T_Celsius);
```

    ##  [1]  9.944444 11.277778  9.666667 10.611111  9.666667  8.833333  9.888889
    ##  [8] 10.500000  9.611111 11.055556 10.444444  9.777778  9.611111 10.333333
    ## [15]  9.111111 10.388889 10.500000 10.333333 10.833333 11.555556 11.000000
    ## [22] 10.611111  9.888889 10.111111 10.222222 10.888889 11.000000 10.500000
    ## [29]  9.333333 10.944444 10.555556 10.333333 10.944444 10.833333 11.166667
    ## [36] 10.722222 10.555556 12.222222 10.777778 11.500000 11.722222 12.555556
    ## [43] 11.111111 11.111111 10.500000 11.444444 10.111111 11.444444 10.888889
    ## [50] 11.055556 10.277778 10.500000 10.944444 10.777778 10.944444 10.444444
    ## [57] 11.055556 11.000000 11.055556 11.666667

In the new line of code added within the above loop, the temperature in degrees Celsius from the previous year `T_Celsius[year - 1]` is subtracted from the tempurature from the current year `T_Celsius[year]`. The value of this difference is then stored in `Temp_ch[year]`, so at the end of the loop, each element of `Temp_ch` stores the difference between the current year's temperature and the last year's temperature.

Note that this newly added line within the for loop is a bit dangerous because `T_Celsius[year - 1]` does not exist when `year = 1` (i.e., at the start of the loop). Since there is no value at `T_Celsius[1 - 1]`, R returns an `NA`, so the first value of `Temp_ch = NA`. This is what we want, but if we are not careful, trusting R to fill things in appropriately might cause us problems later. It is usually better to err on the side of caution and think carefully about what each line is doing, using comments to help the readability. The example below makes everything a bit cleaner and clearer.

``` r
total_years <- length(nhtemp); # Total years in the data set
# Make vectors with an NA element for each year
T_Celsius   <- rep(x = NA, times = total_years);
Temp_ch     <- rep(x = NA, times = total_years);
for(year in 1:total_years){ # For each year in the data set
  # First calculate the temperature in degrees Celsius
  T_Celsius[year] <- (5/9) * (nhtemp[year] - 32);
  if(year > 1){ # Condition in which difference exists
      Temp_ch[year] <- T_Celsius[year] - T_Celsius[year - 1];
  } # Now T_Celsius[0] will not be attempted
}
print(T_Celsius);
```

    ##  [1]  9.944444 11.277778  9.666667 10.611111  9.666667  8.833333  9.888889
    ##  [8] 10.500000  9.611111 11.055556 10.444444  9.777778  9.611111 10.333333
    ## [15]  9.111111 10.388889 10.500000 10.333333 10.833333 11.555556 11.000000
    ## [22] 10.611111  9.888889 10.111111 10.222222 10.888889 11.000000 10.500000
    ## [29]  9.333333 10.944444 10.555556 10.333333 10.944444 10.833333 11.166667
    ## [36] 10.722222 10.555556 12.222222 10.777778 11.500000 11.722222 12.555556
    ## [43] 11.111111 11.111111 10.500000 11.444444 10.111111 11.444444 10.888889
    ## [50] 11.055556 10.277778 10.500000 10.944444 10.777778 10.944444 10.444444
    ## [57] 11.055556 11.000000 11.055556 11.666667

The use of the `if` above is technically unnecessary, but it serves as a nice reminder that it only makes sense to take the difference between temperatures starting in year 2. Now with `T_Celsius` and `Temp_ch` calculated, we can make a nice table of years and temperature values and changes.

``` r
years <- 1912:1971;
dat   <- cbind(years, nhtemp, T_Celsius, Temp_ch);
```

|  years|  nhtemp|  T\_Celsius|     Temp\_ch|
|------:|-------:|-----------:|------------:|
|   1912|    49.9|    9.944444|           NA|
|   1913|    52.3|   11.277778|   1.33333333|
|   1914|    49.4|    9.666667|  -1.61111111|
|   1915|    51.1|   10.611111|   0.94444444|
|   1916|    49.4|    9.666667|  -0.94444444|
|   1917|    47.9|    8.833333|  -0.83333333|
|   1918|    49.8|    9.888889|   1.05555556|
|   1919|    50.9|   10.500000|   0.61111111|
|   1920|    49.3|    9.611111|  -0.88888889|
|   1921|    51.9|   11.055556|   1.44444444|
|   1922|    50.8|   10.444444|  -0.61111111|
|   1923|    49.6|    9.777778|  -0.66666667|
|   1924|    49.3|    9.611111|  -0.16666667|
|   1925|    50.6|   10.333333|   0.72222222|
|   1926|    48.4|    9.111111|  -1.22222222|
|   1927|    50.7|   10.388889|   1.27777778|
|   1928|    50.9|   10.500000|   0.11111111|
|   1929|    50.6|   10.333333|  -0.16666667|
|   1930|    51.5|   10.833333|   0.50000000|
|   1931|    52.8|   11.555556|   0.72222222|
|   1932|    51.8|   11.000000|  -0.55555556|
|   1933|    51.1|   10.611111|  -0.38888889|
|   1934|    49.8|    9.888889|  -0.72222222|
|   1935|    50.2|   10.111111|   0.22222222|
|   1936|    50.4|   10.222222|   0.11111111|
|   1937|    51.6|   10.888889|   0.66666667|
|   1938|    51.8|   11.000000|   0.11111111|
|   1939|    50.9|   10.500000|  -0.50000000|
|   1940|    48.8|    9.333333|  -1.16666667|
|   1941|    51.7|   10.944444|   1.61111111|
|   1942|    51.0|   10.555556|  -0.38888889|
|   1943|    50.6|   10.333333|  -0.22222222|
|   1944|    51.7|   10.944444|   0.61111111|
|   1945|    51.5|   10.833333|  -0.11111111|
|   1946|    52.1|   11.166667|   0.33333333|
|   1947|    51.3|   10.722222|  -0.44444444|
|   1948|    51.0|   10.555556|  -0.16666667|
|   1949|    54.0|   12.222222|   1.66666667|
|   1950|    51.4|   10.777778|  -1.44444444|
|   1951|    52.7|   11.500000|   0.72222222|
|   1952|    53.1|   11.722222|   0.22222222|
|   1953|    54.6|   12.555556|   0.83333333|
|   1954|    52.0|   11.111111|  -1.44444444|
|   1955|    52.0|   11.111111|   0.00000000|
|   1956|    50.9|   10.500000|  -0.61111111|
|   1957|    52.6|   11.444444|   0.94444444|
|   1958|    50.2|   10.111111|  -1.33333333|
|   1959|    52.6|   11.444444|   1.33333333|
|   1960|    51.6|   10.888889|  -0.55555556|
|   1961|    51.9|   11.055556|   0.16666667|
|   1962|    50.5|   10.277778|  -0.77777778|
|   1963|    50.9|   10.500000|   0.22222222|
|   1964|    51.7|   10.944444|   0.44444444|
|   1965|    51.4|   10.777778|  -0.16666667|
|   1966|    51.7|   10.944444|   0.16666667|
|   1967|    50.8|   10.444444|  -0.50000000|
|   1968|    51.9|   11.055556|   0.61111111|
|   1969|    51.8|   11.000000|  -0.05555556|
|   1970|    51.9|   11.055556|   0.05555556|
|   1971|    53.0|   11.666667|   0.61111111|

In the next section, I will move on to consider a more complicated example using nested for loops (i.e., a for loop inside of another for loop).

<a name="for_more">The for loop in R: nested loops</a>
======================================================

Loops can be nested inside one another, such that the inner loop is run one time for each iteration of the outer loop. A common example of when nested loops are useful is in working with two dimensional arrays (e.g., tables or matrices). I will share a quick example from community ecology theory, in which species interactions within a community are often represented by square matrices like the one below,

![](../images/M_matrix.png)

Community ecology theory is not the focus here, so it is fine to [skip a couple paragraphs](#skip) to just move along to the coding problem. For more context though, each element in the above matrix defines how a slight increase in the density of one species affects the density of another species when species densities are at some equilibrium state. Each row and column in M represents a single species, so there are two species in the above matrix. Where rows and column numbers are identical, we have the diagonal of the matrix; this defines how a species affects its own density (i.e., self-regulation). The off-diagonals define how a slight increase in one species' density affects a different species; in the above example, both species decrease each others densities because each has a negative affect on the other (the species in row 1 is negatively affected by species 2 by a magnitude of M<sub>1,2</sub> = -0.2, and the species in row 2 is negatively affected by species 1 by a magnitude of M<sub>2,1</sub> =-0.3). If one of these two off-diagonal elements were positive and the other were negative (e.g., M<sub>1,2</sub> = 0.2, M<sub>2,1</sub> = -0.3), we could interpret this as a predator-prey interaction. If both off-diagonal elements were positive (e.g., M<sub>1,2</sub> = 0.2, M<sub>2,1</sub> = 0.3), we could interpret this as a mutualistic interaction.

To investigate community stability, theoreticians use random matrix theory to test how likely it is that communities with specific properties will return to equilibrium species densities when perturbed (e.g., Allesina and Tang 2015; Allesina and Tang 2012). Developing this theory sometimes requires generating many large M matrices with random interaction strengths (off-diagonal elements) but uniform interaction types (competitor, predator-prey, or mutualist) and self-regulation (diagonal elements). If we take the case of large M matrices in which all interactions are predator-prey (e.g., a big food web), all pairs of row-column elements need to have opposite signs. In other words, if M<sub>i,j</sub> is positive, then M<sub>j,i</sub> needs to be negative. To generate a random matrix with this property, we need go through the elements of M and change the signs of values where appropriate.

<a name = "skip">The **coding** issue</a> is therefore to build a large matrix in which the sign of M<sub>i,j</sub> is the opposite of M<sub>j,i</sub>. We also want the absolute values of the off-diagonal elements to be random numbers, and the diagonal elements to be -1. These latter two properties can be made with the following lines of code, which will make a 10 ✕ 10 matrix as printed off below:

``` r
M_vals <- rnorm(n = 100, mean = 0, sd = 1);
M_vals <- round(M_vals, digits = 2);
M_mat  <- matrix(data = M_vals, nrow = 10);
diag(M_mat) <- -1; # Adds -1 values to diagonal
print(M_mat);
```

    ##        [,1]  [,2]  [,3]  [,4]  [,5]  [,6]  [,7]  [,8]  [,9] [,10]
    ##  [1,] -1.00  0.28  0.41  0.28 -0.62 -0.54  1.03  0.00 -0.23 -0.73
    ##  [2,]  0.80 -1.00  0.29 -0.17 -0.64 -0.34  0.77  0.47 -0.52  0.93
    ##  [3,]  0.92 -0.34 -1.00  1.37 -0.23  1.07 -0.05 -1.05 -1.50 -3.27
    ##  [4,] -2.05  0.65  0.05 -1.00  0.11 -0.51  0.22 -0.18 -0.01 -1.16
    ##  [5,] -0.79 -1.90  0.73 -2.32 -1.00 -1.04  2.19 -0.71 -0.15 -2.24
    ##  [6,] -1.00  0.23  0.81 -0.40  0.60 -1.00 -0.08  1.09 -0.25  0.05
    ##  [7,] -0.11  1.37  1.32  0.20  0.24  1.83 -1.00  0.15  2.51 -0.52
    ##  [8,] -0.44 -0.22  1.65 -2.01 -0.46 -0.31 -0.35 -1.00 -0.59 -1.18
    ##  [9,] -2.05 -0.11 -1.18 -0.09  0.13  1.17 -0.20  1.15 -1.00 -0.57
    ## [10,] -0.14 -0.05  1.56  0.42  0.61  1.83 -0.63  0.07  1.04 -1.00

The above random matrix has diagonal elements all equal to -1, and off-diagonal elements independently drawn from a standard normal distribution 𝒩(0, 1). **The task is now to to make sure that pairs of off-diagonal elements M<sub}{i, j}</sub> and M<sub}{j, i}</sub> have opposite signs**. In other words, if `M_mat[1, 3]` is positive, then `M_mat[3, 1]` should be negative (recall that R indices in brackets refer first to the row, then the column of a matrix: `M_mat[row, column]`). Unlike the previous problems in these notes, it is difficult to see how to create such a matrix without using loops (or editing the values by hand). We need to iterate over `M_mat` `for` each row and `for` each column, reversing the signs of off-diagonal elements whenever necessary. To do this, we can use a `for` loop within another `for` loop -- the outer loop iterates over rows, and the inner loop iterates over columns. Whenever a pair of elements `M_mat[i, j]` and `M_mat[j, i]` are found to have the same sign, `M_mat[i, j]` is multiplied by -1.

``` r
N_species <- dim(M_mat)[1]; # Get total row & col number
for(i in 1:N_species){ # For each row in the matrix
    for(j in 1:N_species){ # For each column in the row
        if(i < j){ # Only need to look at upper triangle
            elem_sign <- M_mat[i, j] * M_mat[j, i];
            if(elem_sign > 0){
                M_mat[i, j] <- -1 * M_mat[i, j];
            }
        }
    } # Finish all columns in the row
} # Finish all rows
print(M_mat);
```

    ##        [,1]  [,2]  [,3]  [,4]  [,5]  [,6]  [,7]  [,8]  [,9] [,10]
    ##  [1,] -1.00 -0.28 -0.41  0.28  0.62  0.54  1.03  0.00  0.23  0.73
    ##  [2,]  0.80 -1.00  0.29 -0.17  0.64 -0.34 -0.77  0.47  0.52  0.93
    ##  [3,]  0.92 -0.34 -1.00 -1.37 -0.23 -1.07 -0.05 -1.05  1.50 -3.27
    ##  [4,] -2.05  0.65  0.05 -1.00  0.11  0.51 -0.22  0.18  0.01 -1.16
    ##  [5,] -0.79 -1.90  0.73 -2.32 -1.00 -1.04 -2.19  0.71 -0.15 -2.24
    ##  [6,] -1.00  0.23  0.81 -0.40  0.60 -1.00 -0.08  1.09 -0.25 -0.05
    ##  [7,] -0.11  1.37  1.32  0.20  0.24  1.83 -1.00  0.15  2.51  0.52
    ##  [8,] -0.44 -0.22  1.65 -2.01 -0.46 -0.31 -0.35 -1.00 -0.59 -1.18
    ##  [9,] -2.05 -0.11 -1.18 -0.09  0.13  1.17 -0.20  1.15 -1.00 -0.57
    ## [10,] -0.14 -0.05  1.56  0.42  0.61  1.83 -0.63  0.07  1.04 -1.00

Note that in the matrix `M_mat` modified above, all pairs of off-diagonal elements `M_mat[i, j]` and `M_mat[j, i]` have opposite signs. Why did that work? We can start with the loops, the outer of which (`for(i in 1:N_species)`) started going through rows starting with row `i = 1`. While `i = 1`, the inner loop (`for(j in 1:N_species)`) went through all columns from 1 to 10 in row 1. Each unique combination of row `i` and column `j` identified a unique matrix element `M_mat[i, j]`, and the code then checked to see if any action needed to be taken in two ways. First, the code checked to see `if(i < j)` -- if not, then the whole bracketed `if` statement is skipped and we move on to the next column `j`. This `if` statement prevents the code from unnecessarily checking the same `i` and `j` pair twice, and prevents it from changing the diagonal where `i == j`. Second, the code assigning `elem_sign` checks to see if `M_mat[i, j]` and `M_mat[j, i]` have opposing signs by multiplying the two values together (two positives or two negatives multiplied together will equal a positive value for `elem_sign`; one positive and one negative will equal a negative value). If `elem_sign > 0`, then we know that `M_mat[i, j]` and `M_mat[j, i]` are either both positive or both negative, so we fix this by changing the sign of `M_mat[i, j]` (multiplying by -1). The figure below gives a visual representation of what is happening.

![](../images/nested_loops.png)

In the figure above, we start with the case in which `i = 1` (i.e., the first row), and move through each value of `j` from `j = 1` to `j = 10`. If `M_mat[i, j]` is in the upper right triangle of the matrix (i.e., `i < j`; shown in red), then the code checks to see if both `M_mat[i, j]` and `M_mat[j, i]` have the same sign. The loop ends when it has moved through all values of `i` from 1 to 10, hence looking at each element `M_mat[i, j]` in the matrix.

Once the logic of the nested loop makes sense, the rest comes down to remembering the syntax for for coding loops in R correctly. This comes with practice, so I have included some practice problems using loops below. Next, I will have a (briefer) look at the `while` loop in R. The general idea of iterating the same task many times will be the same, but the conditions under which the task is iterated will change slightly.

<a name="while_loop">The while loop in R</a>
============================================

The general idea of a `while loop` is the same as that of a `for loop`. In both cases, we are repeating the same task multiple times. But whereas we could specify the full range of values `in` which to substitute some value (e.g., `i`) within a `for` loop, in a `while` loop, we only specify the conditions under which to continue iterating. The printing of numbers from 1 to 10, as done with the `for` loop above, can also be done with the `while` loop below.

``` r
i <- 1;
while(i <= 10){
    print(i);
    i <- i + 1;
}
```

    ## [1] 1
    ## [1] 2
    ## [1] 3
    ## [1] 4
    ## [1] 5
    ## [1] 6
    ## [1] 7
    ## [1] 8
    ## [1] 9
    ## [1] 10

There are few important things to note.

1.  We need to specify an initial value of `i = 1` (else `print(i)` will not return anything).
2.  The loop will continue as long as `i` is less than or equal to 10 (`while(i <= 10)`).
3.  It is critical to increment `i` within the loop (i.e., add a value of 1 at the end so `i <- i + 1`).

If we had forgotten number 3, then the value of `i` would always be 1. Aside from only printing the number 1 many times (rather than 1-10), notice that the loop would never actually terminate because `i` would *always* stay less than or equal to 10. This situation is called an '[infinite loop](https://en.wikipedia.org/wiki/Infinite_loop)', and will result in a situation where it is necessary to terminate the loop manually (i.e., tell R to stop it, either using the red stop sign in the Rstudio console, or by holding down 'CTRL + C'). This is almost always to be avoided, but to see what happens, remove the line `i <- i + 1;` and run the rest of code above.

Sometimes the use of `for` versus `while` loops is a matter of personal preference, such as with the simple example of printing a set of numbers from 1 to 10. In some cases, however, use of a `while` loop will make coding easier.

Consider a situation in which data need to be randomly sampled from a subset of 100 out of 1000 total different entities (the details do not matter -- these entities could be different lochs, fields, or trees in a park). If we just need to sample 100 values out of 1000 without replacement, we can do this with a single line of R code:

``` r
subset <- sample(x = 1:1000, size = 100, replace = FALSE);
print(subset);
```

    ##   [1] 948  30 978 495 283 552 946 162 533  76  81 564 601 355  33 147 195
    ##  [18] 406 868 185 349 811  54 482 708 799 900 844 214 962 149  96 226 725
    ##  [35] 419 109 693 468 415 530 123 129  59 514 902 779 671 679 746 595 996
    ##  [52] 786 928 739 545 827 822 784 941 395 476  13 517 392 532 662 755 293
    ##  [69] 379 254 249 984 643 322 518 377 362 541 335 855 853 144 795 955 296
    ##  [86] 578 614 343 118 484 228 812 762 208 765  61 528  52 142 750

This is easy enough, but what if, having already chosen these 100 entities, we decide that we need *another* 100, for a total of 200 unique samples (without replacement). We could find a creative way of using `sample` again in R (give this a try), but there is a logical way to do this with a `while` loop. The idea is to sample a single value from `1:1000`, then check to see if that value is already in the `subset`. If it is in the `subset`, then throw it out and keep going. If it is not in the `subset`, add it. Continue until the size of `subset` is 200.

``` r
while(length(subset) <= 200){
    samp <- sample(x = 1:1000, size = 1);
    if(samp %in% subset == FALSE){
        subset <- c(subset, samp);
    }
}
print(subset);
```

    ##   [1] 948  30 978 495 283 552 946 162 533  76  81 564 601 355  33 147 195
    ##  [18] 406 868 185 349 811  54 482 708 799 900 844 214 962 149  96 226 725
    ##  [35] 419 109 693 468 415 530 123 129  59 514 902 779 671 679 746 595 996
    ##  [52] 786 928 739 545 827 822 784 941 395 476  13 517 392 532 662 755 293
    ##  [69] 379 254 249 984 643 322 518 377 362 541 335 855 853 144 795 955 296
    ##  [86] 578 614 343 118 484 228 812 762 208 765  61 528  52 142 750  21 728
    ## [103] 267 411 628  66 856  40 561 957 608 945 704 324 542 551 717  72 887
    ## [120]  46 859 777 893 639 757 732 363 711 143 823 770 178 321 842 905 284
    ## [137] 304 396 756  25 384 233 929 289 191 683 428 138 882 701 881 966 884
    ## [154]  24 773 499 540 782 259 431 879 591 558 474 348 932  28 571  89 255
    ## [171] 611  37 408 863 407 478 422 100 462 358 911 247 471  93 372 490 413
    ## [188] 327 486 658 633  36  23 825 609 553 603 922 875 917 657

The `while` loop above will continue as long as `subset` contains less than 200 numbers. If a randomly selected number from 1 to 1000 is **not** in the `subset`, then it is immediately added to make a bigger `subset` with the new number appended to it. The end result is that the above code has added 100 new unique values to the previous sample of 100.

<a name="practice">Practice problems</a>
========================================

Below are some practice problems for working with loops. **To see the answers**, click on the '**Details**' arrows to the left at the bottom of each question. Note that your answers might differ from mine -- there is more than one way to solve each problem!

1.  Using a `for` or `while` loop, print all of the numbers from 1 to 1000 that are multiples of 17. (*Hint: The mod operator `%%` returns the remainder after division. For example, `14 %% 2` would return a value of 2 because 14/4 = 3 with a remainder of 2.*)

<details>

<pre class="r"><code>for(i in 1:1000){
    if(i %% 17 == 0){
        print(i);
    }
}</code></pre>
</details>

1.  In the `nhtemp`, write a loop to add up the temperatures *for all of the even numbered years*, then divide by the total number of even numbered years to get the average.

<details>

<pre class="r"><code>Y &lt;- 1912:1971; # Years
N &lt;- length(nhtemp); # Total temps
A &lt;- 0; # Added temp
C &lt;- 0; # Count
for(i in 1:N){
    if(Y[i] %% 2 == 0){
        A &lt;- A + nhtemp[i];
        C &lt;- C + 1;
    }
}
avg_A &lt;- A/C;
print(avg_A);</code></pre>
</details>

1.  Using a `while` loop, calculate the sum of the series, Y = (4/1) - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + \[...\] to at least 10000 terms. What does the value Y appear to approach as more terms are added? (*Hint: Use `if(){}`, or an `if(){}else{}` to switch from `+` to `-`*)

<details>

<pre class="r"><code>val  &lt;- 0;
deno &lt;- 1;
iter &lt;- 1;
sign &lt;- 1;
while(iter &lt; 1000000){
    if(sign &lt; 0){
        val  &lt;- val - (4/deno);
    }
    if(sign &gt; 0){
        val &lt;- val + (4/deno);
    }
    sign &lt;- -1 * sign;
    deno &lt;- deno + 2;
    iter &lt;- iter + 1;
}
print(val);</code></pre>
</details>

1.  From [here](https://www.r-exercises.com/2018/03/30/loops-in-r-exercises/), write a while loop that prints out standard random normal numbers (use rnorm()) but stops (breaks) if you get a number bigger than 1.

<details>

<pre class="r"><code>i &lt;- 0;
while(i &lt;= 1){
    i &lt;- rnorm(n = 1);
    print(i);
}</code></pre>
</details>

1.  Create an 8 ✕ 8 matrix `mat` with diagonal values of 1 and off-diagonal values randomly selected from a standard normal distribution 𝒩(0, 1) (using `rnorm`). Using nested `for` loops as in the [above notes](#for_more), swap elements `mat[i, j]` with `mat[j, i]` **only** if `mat[i, j] < mat[j, i]` (so that the higher number is in the lower triangle).

<details>

<pre class="r"><code>mat_v     &lt;- rnorm(n = 64, mean = 0, sd = 1);
mat_v     &lt;- round(mat_v, digits = 2);
mat       &lt;- matrix(data = mat_v, nrow = 8);
diag(mat) &lt;- 1;
N &lt;- dim(mat)[1]; 
for(i in 1:N){ 
    for(j in 1:N){
        if(mat[i, j] &lt; mat[j, i]){
            temp_val  &lt;- mat[i, j];
            mat[i, j] &lt;- mat[j, i];
            mat[j, i] &lt;- temp_val;
        }
    } 
} 
print(mat);</code></pre>
</details>

<a name="whatelse">Additional resources</a>
===========================================

-   The [Essence of Loops](https://www.i-programmer.info/programming/theory/8003-the-essence-of-loops.html)

References
==========

Allesina, Stefano, and Si Tang. 2012. “Stability criteria for complex ecosystems.” *Nature* 483 (7388). Nature Publishing Group: 205–8. doi:[10.1038/nature10832](https://doi.org/10.1038/nature10832).

———. 2015. “The stability–complexity relationship at age 40: a random matrix perspective.” *Population Ecology*, 63–75. doi:[10.1007/s10144-014-0471-0](https://doi.org/10.1007/s10144-014-0471-0).
