It is widely under-appreciated that active inbreeding -- and especially
*biparental* inbreeding -- can be adaptive and therefore favoured by
natural selection. Biparental inbreeding specifically refers to the
situation in which two different, but genetically related, organisms
breed and thereby produce inbred offspring. This situation differs from
self-fertilisation, in which an organism inbreeds with itself, as is
perhaps most commonly studied in plants (e.g., Barrett1996; Vogler and
Kalisz 2001). The addition of a second parent complicates how inbreeding
will affect individual fitness, partly because we have -- by definition
-- two different individuals to consider (a female and a male), but also
because biparental inbreeding can occur between any number of different
types of relatives (e.g., siblings, cousins, etc.). I'll explain these
complications in more detail below, but first I want to note two
important general points about inbreeding, the combination of which
makes the evolution of inbreeding particularly interesting.

The first point is that individuals that inbreed typically produce
offspring that have lower fitness than individuals that outbreed (e.g.,
they have offspring with a lower probability of survival), a phenomenon
called ''inbreeding depression''. That inbreeding depression occurs is
well-known, and I won't get into the details of what causes it (see B.
Charlesworth and Charlesworth 1999; Charlesworth and Willis 2009). The
second point is that despite the occurrence of inbreeding depression in
inbred **offspring**, this does not necessarily mean that inbreeding
**parents** themselves have lower fitness than parents that avoid
inbreeding. This second point isn't intuitive, and was first articulated
by Geoff Parker (1979) for the case of biparental inbreeding.

Parker's model of biparental inbreeding
---------------------------------------

The foundational work of biparental inbreeding theory developed by
[Parker](https://en.wikipedia.org/wiki/Geoff_Parker) appears as a
chapter in [*Sexual Selection and Reproductive Competition in
Insects*](https://www.amazon.co.uk/Sexual-Selection-Reproductive-Competition-Insects/dp/0124145760)
(Parker 1979) [1](#foot1). Parker (1979) considered an encounter and the
subsequent reproductive decisions of two focal relatives [2](#foot2).
Below, I'll show the logic of these reproductive decisions first for
females, then for males.

Consider a focal female that can produce *n* offspring -- the exact
number doesn't matter for demonstrating the key point, so to keep things
simple, we can start by assuming that this number will always be the
same. This focal female encounters a first cousin, and upon the
encounter must decide whether or not to inbreed with him. If she does
not inbreed with him, then we'll assume that she is able to find some
other male to breed with to whom she is not related. By avoiding
inbreeding with her cousin and outbreeding instead, she will produce *n*
offspring that do not suffer any inbreeding depression. For simplicitly,
we can set their fitness to a value of 1, and think of this value as the
probability that an outbred offspring survives to adulthood. If she
instead inbreeds with her cousin, then she will produce *n* offspring
whose survival probability will be reduced by some value *δ* due to
inbreeding depression. Hence, if the focal female outbreeds, then she
will produce *n* offspring with a survival probability of 1. And if she
inbreeds with her cousin, then she will produce *n* offspring with a
survival probability of (1 − *δ*). If we only consider the effects of
inbreeding depression, then the *n* × 1 surviving offspring that the
focal female produces by outbreeding will always be favoured by
selection over the *n* × (1 − *δ*) surviving offspring produced by
inbreeding, and the inequality

*n*(1 − *δ*)&gt;*n*
,

will never be true.

But the above inequality leaves out something important to inbreeding
that affects fitness. **If the focal female chooses to inbreed with her
cousin, then his reproductive success will be increased**. Hence, by
inbreeding, she can increase the reproductive success of her relative,
and thereby increase her fitness indirectly -- by how much depends on
her *relatedness* to her potential mate. Assuming the focal female is
herself outbred (i.e., that her own parents did not inbreed), then her
cousin's relatedness to her will be 1/8 [3](#foot3). She should
therefore consider any additional reproductive success of her cousin
that results from her decision with 1/8 the weight of her own
reproductive success. The indirect fitness accrued from the reproductive
success of her cousin plus the direct fitness accrued from her own
reproductive success defines her *inclusive fitness* as accrued through
her reproductive decision; inclusive fitness, more generally, can be
used to determine how selection will act on a particular behaviour
(Hamilton 1964; Grafen 2006). In the case of inbreeding, we can contrast
the inclusive fitness accrued from inbreeding with that of outbreeding,

$$ n(1-\\delta) + \\frac{1}{8}n(1-\\delta) &gt; n $$
.

Now, note that the above inequality isn't always false -- as it
obviously was in the first inequality when indirect fitness was not
taken into account. If we now imagine a very small value of *δ*, then
the left hand side of the above inequality will approach a value of
*n* + (1/8)*n*, higher than the inclusive fitness of outbreeding (*n*).
Yet a large value (close to 1) of *δ* will make the left hand side
closer to zero. Whether inbreeding or avoiding inbreeding yields the
highest inclusive fitness therefore clearly depends on the value of *δ*.
In fact, we can calculate the threshold value below which inbreeding
increases inclusive fitness by isolating the above equation for *δ*,

$$ n(1-\\delta) + \\frac{1}{8}n(1-\\delta) &gt; n $$

$$ (1-\\delta) + \\frac{1}{8}(1-\\delta) &gt; 1 $$

$$ 1 - \\delta + \\frac{1}{8} - \\frac{1}{8}\\delta &gt; 1 $$

$$ 1 + \\frac{1}{8} &gt; 1 + \\delta + \\frac{1}{8}\\delta $$

$$ \\frac{1}{8} &gt; \\delta + \\frac{1}{8}\\delta $$

$$ \\frac{1}{8} &gt; (1 + \\frac{1}{8})\\delta $$

$$ \\frac{1}{8} / (1 + \\frac{1}{8}) &gt; \\delta $$

$$ \\frac{1}{9} &gt; \\delta $$
.

In our example, a focal female will increase her inclusive fitness more
by inbreeding with her cousin than by avoiding inbreeding with him if
*δ* is less than one ninth -- or, put differently, if her inbred
offspring have an 8/9 survival probability. **A focal female can thereby
increase her inclusive fitness if inbreeding depression is sufficiently
weak**.

<!--- Perhaps more interesting, @Parker1979 noted that reproductive interactions between relatives are expected to be characterised by sexual conflict (explain what this means) in a way that self-fertilisation versus outcrossing is not. Explain why this conflict arises, and that it links with other kinds of conflict, citing relevant sources here. Hence, in a few pages of @Parker1979, we have two key theoretical insights; inbreeding should sometimes be adaptive, and reproductive interactions between relatives should lead to sexual conflict. --->
<!--- Note how this work of @Parker1979 still remains less appreciated than perhaps it should, but interesting theory has been developed from its foundation. @Kokko2006 conceptualised the timing of interactions. @Puurtinen2011 (brief note to optimal inbreeding), I think, was the first to note subtely that females but not males could prefer inbreeding (explain why). The other paper on dispersal also boils down to @Parker1979, which was also expressed in a more general paper on sexual conflict in @Parker2006. Perhaps mention @Lehtonen2015 and @Waser1986, noting the costs. Then the conceptual unification between inbreeding theory and parental investment theory, and the model of population genetics. --->
<a name="foot1">\[1\]</a> As an aside, this is a wonderful book that
also includes a chapter written by Bill Hamilton on wing dimorphism in
male fig wasps, likening male-male competition within a fig to ''a
darkened room full of jostling people among whom, or else lurking in
cupboards and recesses which open on all sides, are a dozen or so
maniacal homicides armed with knives'' (Hamilton 1979, 173).

<a name="foot2">\[2\]</a> Parker (1979) considered an encounter between
a female and her full-sibling brother. I'm going to use cousins to
deliberately produce an example with a different numerical result.

<a name="foot3">\[3\]</a> Specifically, her *coefficient of
relatedness*; see, e.g., Michod and Anderson (1979) or Duthie and Reid
(2015) for more detail on how *relatedness* is calculated, particularly
given inbreeding.

References
----------

Charlesworth, Brian, and Deborah Charlesworth. 1999. “The genetic basis
of inbreeding depression.” *Genetical Research* 74 (3): 329–40.

Charlesworth, Deborah, and John H Willis. 2009. “The genetics of
inbreeding depression.” *Nature Reviews Genetics* 10 (11): 783–96.
doi:[10.1038/nrg2664](https://doi.org/10.1038/nrg2664).

Duthie, A Bradley, and Jane M Reid. 2015. “What happens after inbreeding
avoidance? Inbreeding by rejected relatives and the inclusive fitness
benefit of inbreeding avoidance.” *PLoS One* 10 (4): e0125140.
doi:[10.1371/journal.pone.0125140](https://doi.org/10.1371/journal.pone.0125140).

Grafen, Alan. 2006. “Optimization of inclusive fitness.” *Journal of
Theoretical Biology* 238 (3): 541–63.
doi:[10.1016/j.jtbi.2005.06.009](https://doi.org/10.1016/j.jtbi.2005.06.009).

Hamilton, William D. 1964. “The genetical evolution of social behaviour.
I.” *Journal of Theoretical Biology* 7 (1): 1–16.
<http://www.ncbi.nlm.nih.gov/pubmed/5875341>.

———. 1979. “Wingless and fighting males in fig wasps and other insects.”
In *Sexual Selection and Reproductive Competition in Insects*, edited by
Murray S Blum and Nancy A Blum, 167–220. New York: Academic Press, Inc.

Michod, Richard E, and Wyatt W Anderson. 1979. “Measures of genetic
relationship and the concept of inclusive fitness.” *American
Naturalist* 114 (5): 637–47. <http://www.jstor.org/stable/2460734>.

Parker, Geoff A. 1979. “Sexual selection and sexual conflict.” In
*Sexual Selection and Reproductive Competition in Insects*, edited by
Murray S Blum and Nancy A Blum, 123–66. New York: Academic Press, Inc.

Vogler, Donna W, and Susan Kalisz. 2001. “Sex among the flowers: the
distribution of plant mating systems.” *Evolution* 55 (1): 202–4.
doi:[10.1554/0014-3820(2001)055](https://doi.org/10.1554/0014-3820(2001)055).
