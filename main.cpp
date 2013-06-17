#include<Windows.h>
#include"LeapListener.h"

#define ENABLE_MOUSECLICK
#define ENABLE_MOUSEMOVE
#define ENABLE_OPEN_CLOSE_HAND

int main()
{
	LeapListener leapListener;
	Controller controller;
	controller.addListener(leapListener);
	//enable/request background listening
	controller.setPolicyFlags(Controller::POLICY_BACKGROUND_FRAMES);

	/*
	==============================================
	Inputs
	It kinda looks ugly for me, but it works :P
	==============================================
	*/

	/*======================
	mouse click inputs
	======================*/
	INPUT inputM;
	inputM.type = INPUT_MOUSE;
	inputM.mi.mouseData = 0;
	inputM.mi.time = 0;
	inputM.mi.dwExtraInfo = 0;
	inputM.mi.dwFlags = MOUSEEVENTF_MOVE;
	inputM.mi.dx = 0;
	inputM.mi.dy = 0;

	/*======================
	mouse click inputs
	======================*/
	//leftDown
	INPUT inputLeftDown;
	inputLeftDown.type = INPUT_MOUSE;
	inputLeftDown.mi.mouseData = 0;
	inputLeftDown.mi.time = 0;
	inputLeftDown.mi.dwExtraInfo = 0;
	inputLeftDown.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	inputLeftDown.mi.dx = 0;
	inputLeftDown.mi.dy = 0;
	//leftUp
	INPUT inputLeftUp;
	inputLeftUp.type = INPUT_MOUSE;
	inputLeftUp.mi.mouseData = 0;
	inputLeftUp.mi.time = 0;
	inputLeftUp.mi.dwExtraInfo = 0;
	inputLeftUp.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	inputLeftUp.mi.dx = 0;
	inputLeftUp.mi.dy = 0;
	//rightDown
	INPUT inputRightDown;
	inputRightDown.type = INPUT_MOUSE;
	inputRightDown.mi.mouseData = 0;
	inputRightDown.mi.time = 0;
	inputRightDown.mi.dwExtraInfo = 0;
	inputRightDown.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	inputRightDown.mi.dx = 0;
	inputRightDown.mi.dy = 0;
	//rightUp
	INPUT inputRightUp;
	inputRightUp.type = INPUT_MOUSE;
	inputRightUp.mi.mouseData = 0;
	inputRightUp.mi.time = 0;
	inputRightUp.mi.dwExtraInfo = 0;
	inputRightUp.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	inputRightUp.mi.dx = 0;
	inputRightUp.mi.dy = 0;

	/*======================
	Keyboard inputs.
	Virtual-Key codes (ki.wVk) can be found here:
	http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx
	======================*/
	//Keyboard input down
	INPUT inputKeyDown[5];
	inputKeyDown[0].type = INPUT_KEYBOARD;
	inputKeyDown[0].ki.dwExtraInfo = 0;
	inputKeyDown[0].ki.dwFlags = NULL;
	inputKeyDown[0].ki.time = 0;
	inputKeyDown[0].ki.wScan = 0;
	inputKeyDown[0].ki.wVk = 0x41;	//Key A

	inputKeyDown[1].type = INPUT_KEYBOARD;
	inputKeyDown[1].ki.dwExtraInfo = 0;
	inputKeyDown[1].ki.dwFlags = NULL;
	inputKeyDown[1].ki.time = 0;
	inputKeyDown[1].ki.wScan = 0;
	inputKeyDown[1].ki.wVk = 0x57;	//Key W

	inputKeyDown[2].type = INPUT_KEYBOARD;
	inputKeyDown[2].ki.dwExtraInfo = 0;
	inputKeyDown[2].ki.dwFlags = NULL;
	inputKeyDown[2].ki.time = 0;
	inputKeyDown[2].ki.wScan = 0;
	inputKeyDown[2].ki.wVk = 0x45;	//Key E

	inputKeyDown[3].type = INPUT_KEYBOARD;
	inputKeyDown[3].ki.dwExtraInfo = 0;
	inputKeyDown[3].ki.dwFlags = NULL;
	inputKeyDown[3].ki.time = 0;
	inputKeyDown[3].ki.wScan = 0;
	inputKeyDown[3].ki.wVk = 0x52;	//Key R

	inputKeyDown[4].type = INPUT_KEYBOARD;
	inputKeyDown[4].ki.dwExtraInfo = 0;
	inputKeyDown[4].ki.dwFlags = NULL;
	inputKeyDown[4].ki.time = 0;
	inputKeyDown[4].ki.wScan = 0;
	inputKeyDown[4].ki.wVk = 0x20;	//Key Space

	//Keyboard input up
	INPUT inputKeyUp[5];
	inputKeyUp[0].type = INPUT_KEYBOARD;
	inputKeyUp[0].ki.dwExtraInfo = 0;
	inputKeyUp[0].ki.dwFlags = KEYEVENTF_KEYUP;
	inputKeyUp[0].ki.time = 0;
	inputKeyUp[0].ki.wScan = 0;
	inputKeyUp[0].ki.wVk = 0x41;	//Key A

	inputKeyUp[1].type = INPUT_KEYBOARD;
	inputKeyUp[1].ki.dwExtraInfo = 0;
	inputKeyUp[1].ki.dwFlags = KEYEVENTF_KEYUP;
	inputKeyUp[1].ki.time = 0;
	inputKeyUp[1].ki.wScan = 0;
	inputKeyUp[1].ki.wVk = 0x57;	//Key W

	inputKeyUp[2].type = INPUT_KEYBOARD;
	inputKeyUp[2].ki.dwExtraInfo = 0;
	inputKeyUp[2].ki.dwFlags = KEYEVENTF_KEYUP;
	inputKeyUp[2].ki.time = 0;
	inputKeyUp[2].ki.wScan = 0;
	inputKeyUp[2].ki.wVk = 0x45;	//Key E

	inputKeyUp[3].type = INPUT_KEYBOARD;
	inputKeyUp[3].ki.dwExtraInfo = 0;
	inputKeyUp[3].ki.dwFlags = KEYEVENTF_KEYUP;
	inputKeyUp[3].ki.time = 0;
	inputKeyUp[3].ki.wScan = 0;
	inputKeyUp[3].ki.wVk = 0x52;	//Key R

	inputKeyUp[4].type = INPUT_KEYBOARD;
	inputKeyUp[4].ki.dwExtraInfo = 0;
	inputKeyUp[4].ki.dwFlags = KEYEVENTF_KEYUP;
	inputKeyUp[4].ki.time = 0;
	inputKeyUp[4].ki.wScan = 0;
	inputKeyUp[4].ki.wVk = 0x20;	//Key Space

	HWND surgeonWindow;
	//Classname and Window name found with WinSpy, check out http://www.catch22.net/software
	//Look for an open/a running instance of Surgeon Simulator
	//And return the handle to me, so I can use it to send input
	surgeonWindow = FindWindow(L"UnityWndClass", L"Surgeon Simulator 2013");
	ShowWindow(surgeonWindow, SW_MAXIMIZE);
	SetForegroundWindow(surgeonWindow);

	Leap::Vector handPos = Leap::Vector();
	Leap::Vector lastHandPos = Leap::Vector();
	Leap::Vector mouseMovement = Leap::Vector();

	float sensitivity = 18.0; //sensitivity setting :3

	//program will terminate automatically, when
	//a. Surgeon Simulator is closed
	//b. is minimized
	//c. etc, everything that causes it to lose the main focus, I think^^
	while (GetForegroundWindow() == surgeonWindow) {
		if (!leapListener.noHand) {
#ifdef ENABLE_MOUSEMOVE
			//mouse movement
			lastHandPos = handPos;
			handPos = leapListener.handPosition;
			mouseMovement = (handPos - lastHandPos) * sensitivity;
			inputM.mi.dx = mouseMovement.x;
			inputM.mi.dy = mouseMovement.z;
			SendInput(1, &inputM, sizeof(INPUT));
#endif
#ifdef ENABLE_OPEN_CLOSE_HAND
			//open hand
			if (leapListener.handOpen && leapListener.stateHandChanged) {
				SendInput(5, &inputKeyUp[0], sizeof(INPUT));
				leapListener.stateHandChanged = false;
			}

			//close hand
			if (!leapListener.handOpen && leapListener.stateHandChanged) {
				SendInput(5, &inputKeyDown[0], sizeof(INPUT));
				leapListener.stateHandChanged = false;
			}
#endif
#ifdef ENABLE_MOUSECLICK
			//leftclick
			if (leapListener.leftClick && leapListener.leftClickStateChanged) {
				SendInput(1, &inputLeftDown, sizeof(INPUT));
				leapListener.leftClickStateChanged = false;
			}
			else {
				if (leapListener.leftClickStateChanged) {
					SendInput(1, &inputLeftUp, sizeof(INPUT));
					leapListener.leftClickStateChanged = false;
				}
			}

			//rightclick
			if (leapListener.rightClick && leapListener.rightClickStateChanged) {
				SendInput(1, &inputRightDown, sizeof(INPUT));
				leapListener.rightClickStateChanged = false;
			}
			else {
				if (leapListener.rightClickStateChanged) {
					SendInput(1, &inputRightUp, sizeof(INPUT));
					leapListener.rightClickStateChanged = false;
				}
			}
#endif
		}
		else {
			//if no hand is detected, close/let the hand closed in order to keep the tool in hand
			handPos = handPos.zero();
			lastHandPos = lastHandPos.zero();
#ifdef ENABLE_MOUSECLICK
			if (leapListener.leftClickStateChanged || leapListener.rightClickStateChanged) {
				SendInput(1, &inputLeftUp, sizeof(INPUT));
				SendInput(1, &inputRightUp, sizeof(INPUT));
				leapListener.leftClickStateChanged = false;
				leapListener.rightClickStateChanged = false;
			}
#endif
		}
	}

	if (leapListener.leftClick) {
		SendInput(1, &inputLeftUp, sizeof(INPUT));
	}

	if (leapListener.rightClick) {
		SendInput(1, &inputRightUp, sizeof(INPUT));
	}
	
	controller.removeListener(leapListener);
	return 0;
}