Hello Reader,
Thanks for reading this readme :D
This is my second Surgeon Simulator Leap controller. The first one was kind of an abomination (and I probably don't have it anymore - I cannot find it at least) but this one turned out quite nice ;)
This program could be modified to work with other games as well... forget what I said, it would probably lead to a complete rewrite x3
But you are able to tweak the program by modifying certain values.
In main.cpp at #define SENSITIVITY X you can change the value X to suit your needs
In main.cpp you can comment out #define ENABLE_MOUSECLICK, #define ENABLE_MOUSEMOVE and #define ENABLE_OPEN_CLOSE_HAND to disable certain controls (mouse movement, mouseclicks, hand open/close)
In LeapListener.h you can change the heights of both left and right click at #define HEIGHT_LEFTCLICK	X and #define HEIGHT_RIGHTCLICK	Y



Well, if you happen to reuse some of my code it would be nice to give me a little credit, thanks in advance :)

- Tom Collins "Icranox" 

Also a little side note here:
I removed everything that was contained in the Leap SDK because I am not sure if I am allowed to share it.
You need the SDK. It is found here https://developer.leapmotion.com/downloads
Include Leap.h and LeapMath.h which is found in LeapSDK\include\ and also include the Leap.lib found in LeapSDK\lib\x86\
The Leap.dll has to be placed in the same folder as the exe-file. It is also found in LeapSDK\lib\x86\
You need to compile those files into the exe-files. In order to do so, you need a C++ compiler and/or IDE. I use Microsofts Visual Studio 2012. 
Just create an empty console project put all those files in one folder and include them into the project.

Oh yes, and if you have constructive criticism do not hesitate to tell me. I am not a professional programer but I am always open for anything that makes me a better one :3
