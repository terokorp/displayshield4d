/*
	displayshield4d.h - Arduino Library for 4Display-Shield by 4d Systems
	Copyright(c) December 2010 Oscar Gonzalez - www.BricoGeek.com

	Licensed under GNU General Public License v3 
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
	
	16bitColor from RGB by YAPAN.org's small utilities for Arduino
	http://www.opensource.org/licenses/bsd-license.php
*/

#include "displayshield4d.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "WProgram.h"

/*******************************************************
	Constructor
 ********************************************************/
DisplayShield4d::DisplayShield4d() {
	// Constructor
}

/*******************************************************
	Function: 	
		Init
	Description:	
		Initialise display. Prior to this function
		you must start serial by Serial.begin()
		For example: Serial.begin(57600);
	Params:	None	
	Return:	0
 ********************************************************/
uint8_t DisplayShield4d::Init()
{
	Reset();  
	delay(OLED_INITDELAYMS);
	Serial.write(OLED_DETECT_BAUDRATE); 
	delay(10);
	return 0;
}

/*******************************************************
	Function:	
		Reset 
	Description:
		Phisicaly reset the display. D7 jumper must be conected
		Also is a good thing to have pinMode(7, OUTPUT) set in Setup function
	Params:	None
	Return: No return
 ********************************************************/
uint8_t DisplayShield4d::Reset() {

	digitalWrite(OLED_RESETPIN, LOW);
	delay(10);                  
	digitalWrite(OLED_RESETPIN, HIGH);
	delay(10); 
}

/*******************************************************
	Function: 
		Clear
	Description:
		Clear entire display
	Params:	None
	Return: Return OLED_ACK is done or OLED_NAK if not
 ********************************************************/
uint8_t DisplayShield4d::Clear() {
	Serial.write(OLED_CLEAR);
	return GetReply();
}

/*******************************************************
	Function: 
		GetReply
	Description:
		Used to get command response
	Params:	None
	Return: Return OLED_ACK is done or OLED_NAK if not
 ********************************************************/
uint8_t DisplayShield4d::GetReply() {

	byte incomingByte = OLED_ACK;
	while (!Serial.available()) { delayMicroseconds(150); }
	incomingByte = Serial.read();
	return incomingByte;
}

/*******************************************************
	Function: 
		get16bitRGB
	Description:
		Returns correct int format for color parm
	Params:	red, green, blue - From 0 to 254
	Return:	None
 ********************************************************/
unsigned int DisplayShield4d::get16bitRGB(uint8_t red, uint8_t green, uint8_t blue) 
{

	char text[255];

	int outR = ((red * 31) / 255);
	int outG = ((green * 63) / 255);
	int outB = ((blue * 31) / 255);

	return (outR << 11) | (outG << 5) | outB;

}

/*******************************************************
	Function: 
		putpixel
	Description:
		Basic function to draw one pixel
	Params:
		x, y and color. Please check your screen size in order to use this function!
	Return: Return OLED_ACK is done or OLED_NAK if not
 ********************************************************/
uint8_t DisplayShield4d::putpixel(uint8_t x, uint8_t y, unsigned int color)
{
	Serial.write(OLED_PUTPIXEL);
	Serial.write(x);
	Serial.write(y);

	// Color
	Serial.write(color >> 8);				// MSB			
	Serial.write(color & 0xFF);				// LSB

    	return GetReply();
}

/*******************************************************
	Function: 
		line
	Description:
	Params:
		x1, y1, x2, y2 and color
		As allways, take care of your screen size!
	Return:	Return OLED_ACK is done or OLED_NAK if not
 ********************************************************/
uint8_t DisplayShield4d::line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, unsigned int color)
{

	Serial.write(OLED_LINE);

	Serial.write(x1);						// X1
	Serial.write(y1);						// Y1
	Serial.write(x2);						// X2
	Serial.write(y2);						// Y2

	// Color
	Serial.write(color >> 8);					// MSB			
	Serial.write(color & 0xFF);					// LSB

	return GetReply();

}

