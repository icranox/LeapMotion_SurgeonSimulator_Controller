#include"Leap.h"
#include"LeapMath.h"
#pragma comment(lib, "Source\\leap.lib")
using namespace Leap;



/*
Leap device coordinates
Here was a "drawing". I removed it because it was kind of in the documentary and I don't know if this would be against the SDK agreement.
Sorry for your inconvenience :3
===========================================


Drawing


===========================================
*/


class LeapListener : public Listener {
public:
	virtual void onInit(const Controller&);
	virtual void onConnect(const Controller&);
	virtual void onDisconnect(const Controller&);
	virtual void onExit(const Controller&);
	virtual void onFrame(const Controller&);
	virtual void onFocusGained(const Controller&);
	virtual void onFocusLost(const Controller&);

	Vector handPosition;
	float leftHeight;
	float rightHeight;

	bool leftClick;
	bool rightClick;
	bool leftClickStateChanged;
	bool rightClickStateChanged;
	bool noHand;
	bool handOpen;
	bool stateHandChanged;
private:
	Hand hand;
	FingerList fingers;
};

void LeapListener::onInit(const Controller& controller) {
	handPosition = Vector();
	leftHeight = 200.0;
	rightHeight = 400.0;
	noHand = true;
	handOpen = true;
	leftClick = false;
	rightClick = false;

	//I use those states to determine if the state has changed since the last frame
	//so I only send input once a change - I didn't do this on my last controller resulting in an input spamming^^
	//I don't know the English translation for this, maybe flank bit or edge bit? (in German I think this would be called "Flankenbit" ;)
	//P.S. the user of those has to set them false again after usage. Not doing so results in earlier mentioned spamming
	leftClickStateChanged = false;
	rightClickStateChanged = false;
	stateHandChanged = false;
}

void LeapListener::onConnect(const Controller& controller) {
}

void LeapListener::onDisconnect(const Controller& controller) {
}

void LeapListener::onExit(const Controller& controller) {
}

void LeapListener::onFrame(const Controller& controller) {
	Frame frame=controller.frame();
	if (!frame.hands().isEmpty()) {
		noHand = false;
		hand = frame.hands()[0];
		handPosition = hand.palmPosition();

		//is palmPosition vector within boundaries
		if (hand.palmPosition().y > leftHeight && hand.palmPosition().y < rightHeight) {
			//no clicks, set both clicks to false
			//here you might see what I ment earlier
			//the variable will be only set true if there was a change of the state of leftClick
			//again the user has to set the stateChanged variables to false manually
			if (leftClick == true) {
				leftClickStateChanged = true;
			}

			if (rightClick == true) {
				rightClickStateChanged = true;
			}

			leftClick = false;
			rightClick = false;
		}
		else {
			//is not within boundaries
			//is lower than leftHeight -> leftClick
			if (hand.palmPosition().y <= leftHeight) {
				if (leftClick == false) {
					leftClickStateChanged = true;
				}
				leftClick = true;
			}
			else {
				if (leftClick == true) {
					leftClickStateChanged = true;
				}
				leftClick = false;
			}

			//is higher than rightHeight -> rightClick
			if (hand.palmPosition().y >= rightHeight) {
				if (rightClick == false) {
					rightClickStateChanged = true;
				}
				rightClick = true;
			}
			else {
				if (rightClick == true) {
					rightClickStateChanged = true;
				}
				rightClick = false;
			}
		}

		//determine if hand is open based on finger count
		if (!hand.fingers().isEmpty()) {
			fingers = hand.fingers();
			if (fingers.count() >= 3) {
				//Hand is opened
				if (handOpen == false) {
					stateHandChanged = true;
				}
				handOpen = true;
			}
			else {
				//Hand is closed
				if (handOpen == true) {
					stateHandChanged = true;
				}
				handOpen = false;
			}
		}
		else {
			//Hand is closed
			if (handOpen == true) {
				stateHandChanged = true;
			}
			handOpen = false;
		}
	}
	else {
		noHand = true;
	}
	
}

void LeapListener::onFocusGained(const Controller& controller) {
}

void LeapListener::onFocusLost(const Controller& controller) {
}