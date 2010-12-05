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

#ifndef _DISPLAYSHIELD4D_H_
	#define _DISPLAYSHIELD4D_H_

	#include <inttypes.h>

	#define OLED_BAUDRATE			9600
	#define OLED_RESETPIN			8  
	#define OLED_INITDELAYMS		1000

	#define	OLED_DETECT_BAUDRATE		0x55

	#define	OLED_CLEAR			0x45

	#define	OLED_COMMAND_CONTROL		0x59
	#define	OLED_COMMAND_DISPLAY		0x01
	#define	OLED_COMMAND_CONTRAST		0x02
	#define	OLED_COMMAND_POWER		0x03

	#define OLED_ACK			0x06
	#define OLED_NAK 			0x15

	// Class definition
	class DisplayShield4d 
	{
		public:
			uint8_t Init(uint8_t baurate);
			uint8_t Reset();
			uint8_t Clear();
			uint8_t WaitReply();

		private:

		protected:
	};

#endif