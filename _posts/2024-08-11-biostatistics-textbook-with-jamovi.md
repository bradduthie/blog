## A freely available textbook for statistics in the life and environmental sciences

I recently completed an introductory statistics
[textbook](http://bradduthie.github.io/books.html) that uses
[jamovi](https://www.jamovi.org/) software for all examples and
practical exercises.

> [Fundamental statistical concepts and techniques in the biological and
> environmental sciences: With
> jamovi](https://bradduthie.github.io/stats/)

The book is freely available online (and always will be) on [my
website](https://bradduthie.github.io/stats/) and [on
Bookdown](https://bookdown.org/brad_duthie/Statistical-concepts-and-techniques-with-jamovi-1720789903589/),
and a hard copy can be purchased from
[Routledge](https://www.routledge.com/Fundamental-Statistical-Concepts-and-Techniques-in-the-Biological-and-Environmental-Sciences-With-jamovi/Duthie/p/book/9781032687186)
or
[Amazon](https://www.amazon.com/Fundamental-Statistical-Techniques-Biological-Environmental/dp/1032692375).
Datasets for exercises are freely available for download from the Open
Science Framework (<https://osf.io/dxwyv>), and I have uploaded them [to
GitHub](https://github.com/bradduthie/stats). The book uses [R Shiny
apps](https://bradduthie.github.io/stats/app/) to illustrate some of the
challenging ideas through interactive visualisations. My hope is to have
a free audiobook available around October 2024 (roughly the same time as
a print copy). The book is suitable for a one-semester introductory
statistics (or biostatistics) class, and examples are derived from the
biological and environmental sciences. Nine chapters of practical
exercises using jamovi are interspersed with chapters introducing key
statistical concepts. If you are a teacher wanting to use jamovi in your
class, then I am happy to also share some additional materials that I
have made that complement the text.

This post is primarily a reflection on writing the book, not a
discussion about its contents. What follows is a summary of memories
from my first few years of teaching introductory statistics, and a bit
on academic life more generally. This includes some rather unpleasant
memories of working through the COVID-19 pandemic. Finishing this
textbook has become something of a milestone for me in a slow but steady
recovery from the exhaustion and stress of starting an academic job
during COVID-19. This kind of experience was not unique to me, but I
think it is worth writing down.

# Stepping into university teaching during COVID-19

The whole writing process has taken over two years, and it wasn’t my
intention to write a textbook when I was first getting started. My
original objective was to update the learning content for the
introductory statistics class that I started coordinating in the 2021
spring semester. In late 2020, my role at the University of Stirling
changed from being a research fellow (i.e., entirely research focused)
to being a lecturer (which includes research, teaching, and
administrative roles). Like most of the world, Scotland had been in a
COVID-19 lockdown for quite some time. I had been working remotely since
early 2020, and for public safety reasons, all teaching at the
university had been abruptly moved online. I was just finding my footing
as a lecturer the spring 2021 semester, and most of my time was spent
keeping the introductory statistics class running and producing learning
content that was previously delivered face-to-face. The class included
about 150 students and was taught using
[SPSS](https://www.ibm.com/products/spss-statistics) statistical
software. Lab practicals were especially challenging for both staff and
students. Students had to get SPSS running on their own machines and
work through exercises in isolation over a 3-hour MS Teams meeting.
Teachers and teaching assistants would wait for virtual hands to be
raised, then privately message or call students who needed help; it was
new to all of us and a huge change from the traditional face-to-face
computer labs. Lectures had to be pre-recorded and posted online, which
required time for preparing, filming, and editing. A good 15 minute
video could easily take half a day to make, so creating 2-3 hours of
weekly lecture content took a lot of time. In addition to teaching,
research and administrative work also had to be moved entirely online.
For me, and many of my colleagues, the job never stopped; there was too
much to do. For all seven days of the week, I would get up as early as I
could, then go to bed when I was simply too exhausted to continue.

Unfortunately, I made a bad habit out of this routine. It lasted for
years. Work continued even after the semester of teaching ended; a lot
of grant writing, coding, paper writing, and administrative tasks that
had been put aside to keep classes running now needed to be done. When
autumn rolled around, some limited face-to-face teaching was to be
introduced, but we still needed an online option for students, meaning
that the learning content would take a hybrid approach (I was
coordinating an Evolution and Genetics class in the autumn). In 2021, I
took three days of annual leave: two days in the autumn, and Christmas
Eve. I was working through the weekends. I rarely left the house.

When the 2022 spring semester started, the hybrid approach to teaching
was still being used. Statistics lab practicals could now be attended
face-to-face (with appropriate physical distancing in the computer lab)
or online, with lectures and tests still being entirely online. Rather
than just scrambling to get existing learning content online, now I was
working to update it and improve on the previous year. I wrote new
notes, lectures, practical exercises, and assessments, but there was a
lot more that I wanted to do to improve the class. I realised that SPSS
was holding back student learning. The esoteric protocols required for
navigating SPSS, combined with the somewhat unusual labels for
statistics and tests (e.g., ‘Sig.’ instead of ‘p-value’), made learning
difficult. The fundamental statistical concepts that students were
learning in the notes and lectures did not match up well to the software
we were using to do the practicals, and students were quite sensibly
focusing more on learning SPSS protocols than statistical concepts.
Worse, there were new complications concerning how students accessed
SPSS on their personal computers, and a lot of students reported
difficulties using SPSS during their tests. This made a lot of students
very stressed and anxious, and that was more than enough reason for me
to try something new.

# Switching from SPSS to jamovi

Given the challenges with student access to SPSS, I was keen to find
something free and open-source, which could be easily downloaded and
used by all of my students. I know that many of my colleagues at other
institutions go straight to teaching [R
programming](https://www.r-project.org/) in introductory statistics. I
love the R programming language, and I have been using it to do
statistical analyses, code biological models, create webpages, build
interactive apps, and write manuscripts for over a decade now. But I was
reluctant to use R with students being introduced to statistics for the
first time. For starters, I worried that I would run into some of the
same issues that I did with SPSS. I wanted students to be able to focus
primarily on the challenge of learning statistical concepts and
understanding statistical tools, and less on learning new software. For
its many, many advantages, learning R is its own challenge, and one that
a lot of students find intimidating, especially if they have no prior
experience with programming. At my university, we also have a separate,
more advanced, statistics class that introduces R to third and fourth
year students. Not every introductory statistics student takes this
advanced class, but it is available as an option for students who are
keen. In truth, while I encourage my introductory statistics students to
strongly consider learning R (and even gently introduce it in the last
two weeks of my introductory class), I don’t think that it is necessary
for understanding or doing basic statistics. Instead, I wanted something
user-friendly for students with no previous background in statistics or
coding – something that would be a stepping stone to more advanced
tools, but not distract from the challenges of learning statistical
concepts for the first time.

I started searching for options. I decided that I needed something
reliable, user-friendly, free, and that would work across as many
platforms as possible. I was pessimistic at first, but then I saw that
there were some viable options. I looked at
[PSPP](https://www.gnu.org/software/pspp/), but the interface looked too
much like SPSS (this is by design, of course) for my liking. When I
discovered [JASP](https://jasp-stats.org/), I was relieved. It had all
of the features that I absolutely needed; it was free, open-source,
user-friendly, and worked across Windows, macOS, Linux, and Chromebook.
If nothing else was available, JASP would definitely work! I continued
looking around, then came across [jamovi](https://www.jamovi.org/).

Jamovi looked similar to JASP, but with a slightly more user-friendly
interface. And while many users probably appreciate the many Bayesian
statistics options promoted by JASP, these would have to be ignored for
my introductory statistics class. Jamovi was not focused on promoting a
specific statistical philosophy. Like JASP, it was free and open-source,
and would work across Windows, macOS, Linux, and Chromebook. Jamovi
could even be run directly from a browser using [jamovi
cloud](https://www.jamovi.org/cloud.html), which was a nice touch. I
could be confident that all of my students would have access to jamovi
even after finishing their studies and leaving university. The
spreadsheet feature of jamovi also seemed more advanced than JASP, and
the add-on module options in jamovi seemed especially promising for
teaching. Base jamovi was quite minimalist, but with the option to
expand the number of possible analyses with these modules. This
minimalist baseline with add-on module options was a big pedagogical
benefit in my mind. Students just getting started wouldn’t be
overwhelmed by the interface, but as they gained confidence, the add-ons
could be downloaded to do more advanced analyses or visualisations. I
could even write my own modules and contribute them to the jamovi
project (I’m hoping to write a module for randomisation and
bootstrapping to go with the [final
chapter](https://bradduthie.github.io/stats/Chapter_35.html) of my
book). Even better, jamovi allowed for the R syntax underlying its
analyses to be visible above the output (it’s hidden by default).
Students intending to make the eventual transition to R could turn on
this syntax mode to see the code underlying the jamovi point and click
tools. And the [jmv package](https://cran.r-project.org/package=jmv)
used for analyses was fully accessible in R, meaning that I could run
jamovi analyses and get jamovi output from within R. This was very
useful! Because my tests were still entirely online, I needed to give
each student a custom dataset, then write an R script to get the correct
answers and deliver specific feedback for each student. Jamovi gave me
everything I needed, and it seemed like the my best option for teaching.

# A textbook and lab practicals for jamovi

I then needed a lot of new learning content, especially new practical
exercises for jamovi. The existing exercises were all in SPSS. The
lectures often mentioned SPSS, as did the notes, and the tests were
written with SPSS in mind. A lot would need to be changed, and it wasn’t
just me who needed to update the learning content. Two other faculty
members taught on the introductory statistics class; to my relief, they
were both incredibly supportive of the switch and agreed to make updates
to their own lecture content. I was excited at this point and ready to
rebuild all of the learning content. In the summer of 2022, I scrapped
the old notes and decided to start from scratch. I needed a textbook,
but I wasn’t sure what was available for introductory statistics with
jamovi. As with the statistical software, I wanted the textbook to be
free and open source. I didn’t want my students to have to pay for a
textbook, or to have access through the library, which would become
unavailable once they left university. This was going to be more
difficult. I came across [Navarro and
Foxcroft’s](https://davidfoxcroft.github.io/lsj-book/) online textbook,
and I really liked it. The writing was clear and engaging, the scope of
the statistical content was just about right, and the focus was on
jamovi. The only problem was that it was heavily focused on psychology.
My students, with some exceptions, were in the biological and
environmental sciences. I needed a book more focused on using examples
in these subjects, and ideally with practical exercises that students
could work through each week of the semester. After some searching, I
concluded that there was no such book for introductory statistics using
jamovi. If I wanted one, I was going to have to write it myself. My
initial goal was more modest. I would just write some detailed lecture
notes on key statistical concepts, and rewrite the lab practicals from
scratch. I would post these online for my students, with links to other
useful materials (I still do this, with [Navarro and
Foxcroft’s](https://davidfoxcroft.github.io/lsj-book/) text as
recommended reading along with some other good textbooks). I started
writing sometime around late July 2022 (still, unfortunately, unable to
break the habit of seven day work weeks). I was excited.

At the time, I had no intention for the learning content to reach beyond
the University of Stirling. I wanted the notes to form a coherent
statistics workbook and showcase the interesting, diverse, and
globally-focused research that my colleagues were doing in the
department while also being grounded in Scotland (the final book retains
Scottish words such as ‘loch’ and ‘outwith’, and includes
[exercises](https://bradduthie.github.io/stats/Chapter_14.html) inspired
by data collected in Scotland). I asked my colleagues for examples from
their own projects, which nicely spanned the biological and
environmental sciences from various systems around the world. I also had
plenty of data from my own doctoral research, which focused on
nonpollinating fig wasp communities in Baja, Mexico.

I wanted the workbook to be accessible, and for obvious reasons, I
needed students to be able to engage with it entirely online given the
new era of remote and hybrid teaching. [Bookdown](https://bookdown.org/)
was the best choice (Xie 2016, 2023), and something that I was keen to
learn anyway. I had already been writing [manuscripts in
Rmarkdown](https://bradduthie.github.io/blog/Manuscripts-in-Rmarkdown/)
for quite some time, and bookdown was not a huge leap. I spent a lot of
time during the late summer of 2022 writing, mostly during evenings and
weekends (I had other things to do during the workday), but I only made
it through a draft of about a third of the workbook before the autumn
semester started and my time was consumed by more pressing matters.
Nevertheless, it was a good start. Having taught the class for two
years, I realised that the first week really should be devoted to
teaching three topics: (1) review of basic mathematics, (2) how to
organise datasets and files on a computer, and (3) how to work with
spreadsheets. In the past, we assumed that students had sufficient
background in these topics, but this wasn’t always the case, meaning
that many students felt a bit lost early on in the class. These topics
became the first three chapters of the textbook, which is the content
for the first week of my class. After a few more weeks of content were
written, I put the writing on hold for the autumn semester.

When the autumn semester ended, I had reason to panic. I had resolved to
rewrite the class from scratch, but I didn’t have even half of the
learning material complete. I got back to work in December, writing
statistics learning content whenever I could find the time. I still
didn’t manage to take any time off, save for 24 and 25 December, which
fell on a Saturday and Sunday that year. Outwith that one weekend, I was
always working, and I continued working seven days a week until a very
brief pause that summer. I got a bit more written alongside other tasks
that needed to be completed in teaching, research, and administration
during that time. The spring 2023 semester arrived in January, and I had
enough material banked away to be comfortable, at least for a few weeks.
The online workbook looked good, at least the bits of it that were
written. This was entirely due to [Bookdown](https://bookdown.org/)
being such a useful R package. It looked good viewed from a browser on
my computer, but it also looked good on a mobile phone, which is how I
figured a lot of my students would want to read it. The navigation
between sections was easy, there was a search function built-in, and
there was a pull-down menu that allowed readers to change the font type,
font size, and the colour scheme. This seemed really beneficial for
accessibility; students could make the font as large as they needed to
and generally adjust the settings to read comfortably. The figures had
alternative text. The format seemed almost perfect, but I also thought
that an audio version would be useful. I figured that reading the
workbook aloud would help me spot a lot of typos and bad writing (I was
right about this), even if only a few students had any interest in the
audio version (I was wrong about this – a lot of students used it). I
got to work reading each section aloud. The quality was not the greatest
at the time, but I could at least post the audio files for the students
to download.

Week by week, I continued to write. I would usually start writing on
Friday early evening and finish a week’s worth of content by the end of
the evening on Sunday. It wasn’t a healthy work cycle, but there was
something satisfying about starting with a blank slate every Friday and
having a complete draft by the end of the weekend. I would often think
throughout the week about the best way to approach the next topic on the
agenda, such as hypothesis testing, ANOVA, or regression. I wanted to
lead with concrete examples as much as possible, and with datasets that
I thought would be accessible to my students. I wanted the writing to be
interesting and engaging. At the start of each weekend, I would search
through the peer-reviewed literature on the relevant statistical topic
and look through old statistics textbooks that I had accumulated
throughout the years to try and fill out my understanding of the topic
as much as possible. It was always satisfying to re-learn these topics,
and to discover new nuances and slightly different ways of thinking
about them. By the end of the semester, sometime around April 2023, I
had somehow accidentally written a textbook. Was that really necessary?

In any case, the semester had gone very well. Jamovi was an absolute
success. It was so much of an improvement for student learning that
whenever my students from previous years would get in touch to ask for
statistics help (for other classes or their dissertation research), I
would tell them to switch over to jamovi immediately. At this point, we
had new learning content and a solid foundation for future semesters.
There were adjustments to be made, of course, but nothing went terribly
wrong.

It was around this time, perhaps a few weeks before the end of the
semester, that I seriously considered making the textbook available to
people outside my own institution. It wasn’t ready yet. The content was
too specific to my own university and class, so some more work would
need to be done. But given how much work had been done already, I
figured it would be worth it on the off chance that someone else would
be in the same position that I was a year earlier. Jamovi was still
relatively new, and I thought that other university teachers might be
more inclined to start using it if there was a viable textbook
available.

# Publishing a hard copy

My original plan toward the end of the spring 2023 semester was to make
some hefty edits to what I already had and publish the book on
[bookdown.org](https://bookdown.org/) and my [own
website](https://bradduthie.github.io/stats/). This seemed well worth
the effort given how much work I had already done, and I felt that I
really should contribute something to the [jamovi
community](https://www.jamovi.org/community.html) given how useful
jamovi had been for my teaching. I wanted to make sure that the book
would be freely available online and as an audiobook for any educator
considering making the switch to jamovi. In [a 2017
interview](https://blog.efpsa.org/2017/03/23/introducing-jamovi-free-and-open-statistical-software-combining-ease-of-use-with-the-power-of-r/),
Jonathon Love, co-founder and developer of jamovi, remarked on the need
for content creators to provide supporting materials for the project:

> “People are reluctant to adopt a new platform when not all the
> supporting materials, videos, textbooks, etc. have been created yet.
> At the same time, the content creators are reluctant to provide
> supporting materials, because people seem reluctant to adopt it. In
> this way, markets tend to resist change, and overturning the
> status-quo often poses a frustrating challenge.”

I noticed that a lot of bookdown books had print versions published by
[CRC Press](https://www.routledge.com/corporate/about-us/crc-press). I
had bought and read hard copies of CRC Press books on R programming and
data analysis before, and I saw that a lot of CRC Press books were
freely available in bookdown form, but I never quite understood the
details of how this worked. That several very good books were available
for free online and as print versions intrigued me, and I thought that
it was worth getting in touch with the publisher on the off chance that
they would be interested in what I had written and could disseminate the
book to a broader audience. I sent an email to the publisher in late
April 2023. I was very pleasantly surprised when I received a positive
response inviting me to send a more formal proposal to go out for
review.

This was new territory for me; I had published plenty in peer-reviewed
journals, but never a book. My first experience was excellent all the
way through. I wrote up a proposal and sent what I had for the book. I
received three constructive and positive reviews, and this led to an
agreement for drafting a full book by February 2024. This gave me about
half a year to make edits and additions, and to remove some content that
did not really fit with the overall goal of a textbook for jamovi. I was
(and still am) enthusiastic about a publication model that allowed me to
keep a free copy of the book online. The publisher even allowed me to
retain all rights to the audiobook, so I could make a free audiobook
version too. As far as I can tell, this is a win-win for everyone
involved. CRC Press would be able to sell copies of my book, and I would
benefit by having a version of the book to disseminate in print. I would
also benefit by having a copy editor read through the book and suggest
edits, which would fix any inconsistencies and errors, and this would
feed back to having a better textbook to work from in future years of
teaching.

February 2024 came around, and I submitted a full draft to CRC Press. I
was actively teaching statistics at the time and using some of the new
material I had written. Teaching each week made it easier to spot errors
and inconsistencies, and to make small improvements to the writing based
on informal feedback from students, teaching assistants, and academic
colleagues. I wrote these down; the next phase was working through
copy-edits where I could make further changes. This was in June 2024,
and included new formatting edits and indexing. I was surprised at how
many typos there were still left for me to correct.

During mid June, I attended a workshop on teaching statistics in
Manchester, England, which was immediately followed by the [UK
Conference on Teaching Statistics](https://www.ukcots.org/) (UKCOTS). I
had never been to a conference focused on teaching statistics, and I
wanted to share my new book with colleagues, hear some new perspectives
and insights, and get some ideas for future teaching. The workshop and
conference did not disappoint! I had an incredible time, saw some
outstanding talks, and finished my time in Manchester with a wealth of
new plans for improving my own teaching for spring 2025. I also met
other statistics teachers who use jamovi. Someone introduced me to the
[shinylive](https://posit-dev.github.io/r-shinylive/) R package. I wish
I had written down their name (if you are reading this, thank you
again!) because shinylive gave me the perfect solution to a problem that
I had been ignoring for a long time. The [shiny
apps](https://bradduthie.github.io/stats/app/) that I had written to
complement the book were being hosted by the Posit [shinyapps
server](https://www.shinyapps.io/). This was perfectly fine for a class
of 150 students, but if more people needed to use the apps, then the
cost of hosting them online might become more than I could afford. The
shinylive package completely removed the need for a hosted server by
having everything run from within a browser. I could just post the apps
on GitHub in the [same repository](https://github.com/bradduthie/stats)
as the book. This was a huge relief. In fact, it was such a huge relief
that my brain began to search for something new to worry about on the
way home from Manchester. I found a new worry in the rights to a couple
previously published images ([Figure
30.1](https://bradduthie.github.io/stats/Chapter_30.html) and [Figure
35.1](https://bradduthie.github.io/stats/Chapter_35.html)) that I had
used for two papers in the *American Naturalist* (Duthie et al. 2015;
Duthie and Nason 2016). Fortunately, a quick email exchange on the train
home confirmed that I did not actually need permission to use these.
Everything was fine.

Soon after returning from Manchester, I received the typeset proofs and
again had a chance to make some final edits. I re-read the book (now
nicely typeset), and I was again surprised, and at this point a bit
horrified, by some inconsistencies and errors that still needed to be
fixed at this stage. Again, the publisher was excellent and reassuring
throughout the entire process. There were no problems making the
necessary edits. Nevertheless, I found it very easy to second guess
myself at this stage, and I was nervous that time was running out to
find any errors. I went through four rounds of proofs, with my edits
being a bit more pedantic each time until I really was satisfied that
the job was complete (I was quite tired of reading my own writing by
this point in time). The final version was sent to print on 9 August
2024.

# Next steps and conclusion

It is a huge relief to have finished the book. I now look forward to
seeing it in print in October 2024. My goal is to complete the audiobook
in the next couple of months. I will also need to integrate some of the
improvements that I have made to the book into my own teaching materials
for spring 2025.

Completing this book coincides with what I hope will be the end of a
long period of instability and exhaustion, which began with the start of
COVID-19 and a new academic role. There is a lot that I have left out of
this story. The book has been mostly a side project of mine, and it
usually, rightfully, took a back seat to more pressing matters of
teaching, research, and administration. Nevertheless, I now find myself,
at least temporarily, with time to reflect. After years of continuous
stress that seemed like it would never end, there is some recovery. Not
every evening and weekend needs to be spent working anymore. I look
forward to working hard without harming my health.

I hope that people find the book useful. I will continue to make new
updates here.

# References

Duthie, A. B., Abbott, K. C., & Nason, J. D. (2015). Trade-offs and
coexistence in fluctuating environments: evidence for a key
dispersal-fecundity trade-off in five nonpollinating fig wasps. American
Naturalist, 186(1), 151–158. <https://doi.org/10.1086/681621>

Duthie, A. B., & Nason, J. D. (2016). Plant connectivity underlies
plant-pollinator-exploiter distributions in Ficus petiolaris and
associated pollinating and non-pollinating fig wasps. Oikos, 125(11),
1597–1606. <https://doi.org/10.1111/oik.02629>

Navarro DJ and Foxcroft DR (2022). learning statistics with jamovi: a
tutorial for psychology students and other beginners. (Version 0.75).
DOI: 10.24384/hgc3-7p15

Xie, Y. (2016). Bookdown: Authoring books and technical documents with R
markdown. Chapman & Hall/CRC, Boca Raton, USA.
<https://bookdown.org/yihui/bookdown>

Xie, Y. (2023). Bookdown: Authoring books and technical documents with R
markdown. <https://github.com/rstudio/bookdown>
