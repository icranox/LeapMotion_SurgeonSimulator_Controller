Hello Reader,
Thanks for reading this readme :D
This is my second Surgeon Simulator Leap controller. The first one was kind of an abomination (and I probably don't have it anymore - I cannot find it at least) but this one turned out quite nice ;)
This program could be modified to work with other games as well... forget what I said, it would probably lead to a complete rewrite x3
But you are able to tweak the program by modifying certain values.
In line 166 in the main.cpp you can change the sensitivity of the mouse movements
In line 4 - 6 in the main.cpp you can comment those out to disable certain controls (mouse movement, mouseclicks, hand open/close)
In line 50 and 51 in the LeapListener.h you can change the heights of both left and right click

It may also be possible to make the code more efficient using bitmasks and such but this suffices^^

Well, if you happen to reuse something it would be nice to give me a little bit of credit, thanks in advance :)

- Tom Collins "Icranox" 

Also a little side note here:
I removed everything that was contained in the Leap SDK because I am not sure if I am allowed to share it.
Just throw in the stuff from your SDK copy and it is ready to go^^