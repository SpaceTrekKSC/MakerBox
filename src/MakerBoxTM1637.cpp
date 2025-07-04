//  Author:Fred.Chu
//  Date:9 April,2013
//
//  Applicable Module:
//        4-Digit Display by catalex
//        4-Digit Display (D4056A) by catalex
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
//  Modified record:
//
/*******************************************************************************/
#include "MakerBoxTM1637.h"
#include <Arduino.h>
int8_t TubeTab[] = {0x3f,0x06,0x5b,0x4f,
                           0x66,0x6d,0x7d,0x07,
                           0x7f,0x6f,0x77,0x7c,
                           0x39,0x5e,0x79,0x71,
                           0x40,0x00};//0~9,A,b,C,d,E,F,"-"," "  

TM1637::TM1637(uint8_t Clk, uint8_t Data)
{
  Clkpin = Clk;
  Datapin = Data;
  pinMode(Clkpin,OUTPUT);
  pinMode(Datapin,OUTPUT);
}

void TM1637::init(uint8_t DispType)
{
  _DispType = DispType;
  BlankingFlag = 1;
  DecPoint = 3;
  set();
  clearDisplay();
}

void TM1637::writeByte(int8_t wr_data)
{
	uint8_t data = wr_data;
	
	 // 8 Data Bits
	 for(uint8_t i = 0; i < 8; i++) {
	   // CLK low
	   pinMode(Clkpin, OUTPUT);
	   bitDelay();
	
	   // Set data bit
	   if (data & 0x01)
		 pinMode(Datapin, INPUT);
	   else
		 pinMode(Datapin, OUTPUT);
	
	   bitDelay();
	
	   // CLK high
	   pinMode(Clkpin, INPUT);
	   bitDelay();
	   data = data >> 1;
	 }
	
	 // Wait for acknowledge
	 // CLK to zero
	 pinMode(Clkpin, OUTPUT);
	 pinMode(Datapin, INPUT);
	 bitDelay();
	
	 // CLK to high
	 pinMode(Clkpin, INPUT);
	 bitDelay();
	 uint8_t ack = digitalRead(Datapin);
	 if (ack == 0)
	   pinMode(Datapin, OUTPUT);
	
	
	 bitDelay();
	 pinMode(Clkpin, OUTPUT);
	 bitDelay();

}
//send start signal to TM1637
void TM1637::start(void)
{
  pinMode(Datapin, OUTPUT);
  bitDelay();
} 
//End of transmission
void TM1637::stop(void)
{
  pinMode(Datapin, OUTPUT);
	bitDelay();
	pinMode(Clkpin, INPUT);
	bitDelay();
	pinMode(Datapin, INPUT);
	bitDelay(); 
}
//display function.Write to full-screen.
void TM1637::display(int8_t DispData[])
{
  int8_t SegData[4];
  uint8_t i;
  for(i = 0;i < 4;i ++)
  {
    SegData[i] = DispData[i];
  }
  coding(SegData);
  start();          //start signal sent to TM1637 from MCU
  writeByte(ADDR_AUTO);//
  stop();           //
  start();          //
  writeByte(Cmd_SetAddr);//
  for(i=0;i < 4;i ++)
  {
    writeByte(SegData[i]);        //
  }
  stop();           //
  start();          //
  writeByte(Cmd_DispCtrl);//
  stop();           //
}
//******************************************
void TM1637::display(uint8_t BitAddr,int8_t DispData)
{
  int8_t SegData;
  SegData = coding(DispData);
  start();          //start signal sent to TM1637 from MCU
  writeByte(ADDR_FIXED);//
  stop();           //
  start();          //
  writeByte(BitAddr|0xc0);//
  writeByte(SegData);//
  stop();            //
  start();          //
  writeByte(Cmd_DispCtrl);//
  stop();           //
}

void TM1637::display(double Decimal)
{
  int16_t temp;
  if(Decimal > 9999)return;
  else if(Decimal < -999)return;
  uint8_t i = 3;
  if(Decimal > 0)
  {
	for( ;i > 0; i --)
	{
	  if(Decimal < 1000)Decimal *= 10;
	  else break;
	}
	temp = (int)Decimal;
	if((Decimal - temp)>0.5)temp++;
  }
   else
  {
	for( ;i > 1; i --)
	{
	  if(Decimal > -100)Decimal *= 10;
	  else break;
	}
	temp = (int)Decimal;
	if((temp - Decimal)>0.5)temp--;
  }
  DecPoint = i;
  
  Serial.println(Decimal);
  BlankingFlag = 0;
  display(temp);
   
}

void TM1637::display(int16_t Decimal)
{
  int8_t temp[4];
  if((Decimal > 9999)||(Decimal < -999))return;
  if(Decimal < 0)
  {
	temp[0] = INDEX_NEGATIVE_SIGN;
	Decimal = abs(Decimal);
	temp[1] = Decimal/100;
    Decimal %= 100;
    temp[2] = Decimal / 10;
    temp[3] = Decimal % 10;
	if(BlankingFlag)
	{
	  if(temp[1] == 0)
	  { 
	    temp[1] = INDEX_BLANK;
	    if(temp[2] == 0) temp[2] = INDEX_BLANK;
	  }
	}
  }
  else
  {
    temp[0] = Decimal/1000;
	Decimal %= 1000;
    temp[1] = Decimal/100;
    Decimal %= 100;
    temp[2] = Decimal / 10;
    temp[3] = Decimal % 10;
	if(BlankingFlag)
	{
	  if(temp[0] == 0)
	  { 
	    temp[0] = INDEX_BLANK;
	    if(temp[1] == 0) 
	    {
	      temp[1] = INDEX_BLANK;
		  if(temp[2] == 0) temp[2] = INDEX_BLANK;
	    }
	  }
	}
  }
  BlankingFlag = 1;
  display(temp);
  
}

void TM1637::clearDisplay(void)
{
  display(0x00,0x7f);
  display(0x01,0x7f);
  display(0x02,0x7f);
  display(0x03,0x7f);  
}
//To take effect the next time it displays.
void TM1637::set(uint8_t brightness,uint8_t SetData,uint8_t SetAddr)
{
  Cmd_SetData = SetData;
  Cmd_SetAddr = SetAddr;
  Cmd_DispCtrl = 0x88 + brightness;//Set the brightness and it takes effect the next time it displays.
}

//Whether to light the clock point ":".
//To take effect the next time it displays.
void TM1637::point(boolean PointFlag)
{
  if(_DispType == D4036B) _PointFlag = PointFlag;
}
void TM1637::coding(int8_t DispData[])
{
  uint8_t PointData;
  if(_PointFlag == POINT_ON)PointData = 0x80;
  else PointData = 0; 
  for(uint8_t i = 0;i < 4;i ++)
  {
    if(DispData[i] == 0x7f)DispData[i] = 0x00;
    else DispData[i] = TubeTab[DispData[i]] + PointData;
  }
  if((_DispType == D4056A)&&(DecPoint != 3))
  {
  	DispData[DecPoint] += 0x80;
	DecPoint = 3;
  }
}
int8_t TM1637::coding(int8_t DispData)
{
  uint8_t PointData;
  if(_PointFlag == POINT_ON)PointData = 0x80;
  else PointData = 0; 
  if(DispData == 0x7f) DispData = 0x00 + PointData;//The bit digital tube off
  else DispData = TubeTab[DispData] + PointData;
  return DispData;
}
/*void TM1637::coding(float Decimal,DispData[])
{
  uint16_t int_part;
  if(Decimal > 9999)return;
  else if(Decimal < -999)return;
  if(Decimal > 0)
  {
	uint8_t i = 0;
	for(i < 3; i ++)
	{
	  if(Decimal < 1000)Decimal *= 10;
	  else break;
	}
	
  }
}*/
void TM1637::bitDelay()
{
	delayMicroseconds(50);
}

