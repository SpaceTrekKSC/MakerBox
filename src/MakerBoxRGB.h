/*--------------------------------------------------------------------
  This file is part of the Adafruit NeoPixel library.

  NeoPixel is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  NeoPixel is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with NeoPixel.  If not, see
  <http://www.gnu.org/licenses/>.
  --------------------------------------------------------------------*/

#ifndef _MakerBox_RGB_H
#define _MakerBox_RGB_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

// 'type' flags for LED pixels (third parameter to constructor):
#define NEO_RGB     0x00 // Wired for RGB data order
#define NEO_GRB     0x01 // Wired for GRB data order
#define NEO_BRG     0x04
  
#define NEO_COLMASK 0x01
#define NEO_KHZ800  0x02 // 800 KHz data stream
#define NEO_SPDMASK 0x02
// Trinket flash space is tight, v1 NeoPixels aren't handled by default.
// Remove the ifndef/endif to add support -- but code will be bigger.
// Conversely, can comment out the #defines to save space on other MCUs.
#ifndef __AVR_ATtiny85__
#define NEO_KHZ400  0x00 // 400 KHz data stream
#endif

class RGB {

 public:

  // Constructor: number of LEDs, pin number, LED type
  RGB(uint16_t n, uint8_t p=3, uint8_t t=NEO_GRB + NEO_KHZ400);
  ~RGB();

  void
    begin(void),
    show(void),
    setPin(uint8_t p),
    setPixelColor(uint8_t r, uint8_t g, uint8_t b, uint16_t n=0),
    setPixelColor(uint32_t c, uint16_t n=0),
    setBrightness(uint8_t),
    clear();
  uint8_t
   *getPixels(void) const,
    getBrightness(void) const;
  uint16_t
    numPixels(void) const;
  static uint32_t
    Color(uint8_t r, uint8_t g, uint8_t b);
  uint32_t
    getPixelColor(uint16_t n) const;
  inline bool
    canShow(void) { return (micros() - endTime) >= 50L; }

 private:

   const uint16_t numLEDs;       // Number of RGB LEDs in strip
   const uint16_t numBytes;      // Size of 'pixels' buffer below
   uint8_t pin;           // Output pin number
   uint8_t *pixels;        // Holds LED color values (3 bytes each)
   const uint8_t type;          // Pixel flags (400 vs 800 KHz, RGB vs GRB color)
   uint8_t brightness;   
   uint32_t endTime;       // Latch timing reference
   uint8_t rOffset;        // Index of red byte within each 3-byte pixel
   uint8_t gOffset;       // Index of green byte
   uint8_t bOffset;       // Index of blue byte
   
#ifdef __AVR__
  const volatile uint8_t
    *port;         // Output PORT register
  uint8_t
    pinMask;       // Output PORT bit mask
#endif

};

#endif // ADAFRUIT_NEOPIXEL_H
