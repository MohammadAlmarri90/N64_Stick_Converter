/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F25K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/******************************************************************************
Macros & Defines
******************************************************************************/
// clock frequency
#define F_CPU 1000000UL

// +/- minimum range that will be achieved for each axis in standard range mode
#define MIN_RANGE_STD 81
// max. range limit in standard range mode; higher values will be clipped
#define MAX_RANGE_STD 84

// +/- minimum range that will be achieved for each axis in extended range mode
#define MIN_RANGE_XTD 91
// max. range limit in extended range mode, higher values will be clipped
#define MAX_RANGE_XTD 94
/******************************************************************************
Prototypes
******************************************************************************/
// returns a 16 bit ADC value of the potentiometer stick's x axis (0 - 1023)
uint16_t GetX(void);

// returns a 16 bit ADC value of the potentiometer stick's y axis (0 - 1023)
uint16_t GetY(void);

// scales the 16 bit ADC value down to 8 bits: result = raw16 * factor c / 256
uint8_t ScaleDown(uint16_t raw16, uint8_t c);

// rotates a byte left by one bit
uint8_t RotateLeft(uint8_t cData);

// rotates a byte left by one bit
uint8_t RotateRight(uint8_t cData);

// calculates the c factors and saves them into EEPROM
void Calibration(void);

/******************************************************************************
Globals
******************************************************************************/
// factors for x & y axis in standard range mode
uint8_t cx_std = 0;						
uint8_t cy_std = 0;	
uint8_t cx_std_address = 0;						
uint8_t cy_std_address = 1;	

// factors for x & y axis in extended range mode
uint8_t cx_xtd = 0;						
uint8_t cy_xtd = 0;
uint8_t cx_xtd_address = 2;						
uint8_t cy_xtd_address = 3;

// for detecting first power on
uint8_t firstPowerOn = 1;
uint8_t firstPowerOn_address = 4;

// stores the position of the calibration slider switch
uint8_t calibSwitch;
uint8_t calibSwitch_address = 5;
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    int16_t xSteps, ySteps;
	uint16_t x, y, xOld, yOld;
	uint8_t xNeutral8, yNeutral8;
	uint8_t xWheel = 0b11001100;
	uint8_t yWheel = 0b00110011;
	uint16_t xNeutral16, yNeutral16;
	uint8_t xFactor, yFactor, maxRange;
    
    //Set Ports
    XA_SetHigh();
    XB_SetHigh();
    YA_SetHigh();
    YB_SetHigh();
    LED_SetLow();
    __delay_ms(100);
    LED_SetHigh();
    
    //Wait a little bit
    __delay_ms(250);
    
	// extended range mode if ext. range mode button is pushed
//	if ( !(PINA&(1<<PORTA5)) ){
//		xFactor = DATAEE_ReadByte(cx_xtd_address);
//		yFactor = DATAEE_ReadByte(cy_xtd_address);
//		maxRange = MAX_RANGE_XTD;
//	}
	// standard range mode otherwise
//	else{
//		xFactor = DATAEE_ReadByte(cx_std_address);
//		yFactor = DATAEE_ReadByte(cy_std_address);
//		maxRange = MAX_RANGE_STD;	
//	}
    
    xFactor = DATAEE_ReadByte(cx_xtd_address);
    yFactor = DATAEE_ReadByte(cy_xtd_address);
    maxRange = MAX_RANGE_XTD;
    
    ADCC_DisableContinuousConversion();
    
    // first AD conversion; initialize analog circuitry
	xNeutral16 = GetX();	
	
	// get x axis neutral position
	xNeutral16 = GetX();					
	xNeutral8 = ScaleDown(xNeutral16, xFactor);
	xOld = xNeutral8;
	
	// get y axis neutral position
	yNeutral16 = GetY();						
	yNeutral8 = ScaleDown(yNeutral16, yFactor);
	yOld = yNeutral8;
    
    //If First boot, Calibrate
    if (DATAEE_ReadByte(firstPowerOn_address) != 1)	Calibration();
    
    while (1)
    {
        // get x axis position
		x = GetX();
        // limit position to  +/- maxRange
		if ( (x>xNeutral8) && ((x-xNeutral8) > maxRange) ) x = xNeutral8 + maxRange;
		if ( (x<xNeutral8) && ((xNeutral8-x) > maxRange) ) x = xNeutral8 - maxRange;
        
        // get y axis position
		y = GetY();			
		// scale down
		y = ScaleDown(y, yFactor);		
		// limit position to  +/- maxRange
		if ( (y>yNeutral8) && ((y-yNeutral8) > maxRange) ) y = yNeutral8 + maxRange;
		if ( (y<yNeutral8) && ((yNeutral8-y) > maxRange) ) y = yNeutral8 - maxRange;
        
        // calculate the amount of steps (= increments or decrements) for both axes
		xSteps =  (int16_t) x - xOld;
		ySteps =  (int16_t) y - yOld;
		
		// store current stick position for the next cycle
		xOld = x;
		yOld = y;
		
		// while there are still steps left...
        while ( (xSteps!=0) || (ySteps!=0) )
        {
			// rotate the x wheel...					
			if (xSteps<0){
				xWheel = RotateLeft(xWheel);
				xSteps++;				
			}						
			if (xSteps>0){
				xWheel = RotateRight(xWheel);
				xSteps--;			
			}	
			
			// rotate the y wheel...		
			if (ySteps>0){
				yWheel = RotateRight(yWheel);
				ySteps--;				
			}			
			if (ySteps<0){
				yWheel = RotateLeft(yWheel);
				ySteps++;			
			}		
			
			// and put out the new XA/XB and YA/YB values:			
			LATB = (LATB&0b11111100)|(xWheel & 0b00000011); 
			LATA = (LATA&0b00111111)|(yWheel & 0b11000000);		
        }
        // Add your application code
    }
}

uint16_t GetX(void)
{
    return ADCC_GetSingleConversion(AnalogX);
}

uint16_t GetY(void)
{
    return ADCC_GetSingleConversion(AnalogY);
}

uint8_t RotateLeft (uint8_t cData){
	uint8_t result;
	if ( cData & (1<<7) )
		result = (cData<<1)|(1<<0);
	else 
		result = (cData<<1);	
	return result;
}

uint8_t RotateRight (uint8_t cData){
	uint8_t result;
	if ( cData & (1<<0) )
		result = (cData>>1)|(1<<7);
	else
		result = (cData>>1);	
	return result;
}

void Calibration(void){	
	
	uint16_t temp;
	uint16_t xNeutral16, yNeutral16;
	uint16_t xMin, xMax, yMin, yMax;
	uint16_t counter = 0;
	uint16_t xFactor, yFactor;
	
	// reset firstPowerOn variable in EEPROM
	DATAEE_WriteByte(firstPowerOn_address, 0x00);
						
	// get stick's neutral position
	xNeutral16 = GetX();		
	yNeutral16 = GetY();
				
	// reset both axes' min and max values
	xMin = xNeutral16;								
	xMax = xNeutral16;
	yMin = yNeutral16;
	yMax = yNeutral16;
		
	// do forever	
	while (1)
	{
				
		// check the x axis for new min and max values
		temp = GetX();				
		if (temp > xMax) xMax = temp;					
		if (temp < xMin) xMin = temp;
				
		// check the y axis for new min and max values 
		temp = GetY();				
		if (temp > yMax) yMax = temp;					
		if (temp < yMin) yMin = temp;	
		
		// increase counter			
		counter++;
				
		// periodically calculate and store the c factors
		if (counter>4000)
		{	
			// reset counter
			counter = 0;	
						
			// x axis (standard mode): use the difference between neutral and min or neutral and max, whatever is smaller		
			if ( (xMax - xNeutral16) < (xNeutral16 - xMin) ){
				temp = xMax - xNeutral16;
			}
			else{
				temp = xNeutral16 - xMin;		
			}
			// calculate x axis factor (standard mode)			
			xFactor = ((MIN_RANGE_STD*256)/temp);							
			// if remainder, add one	
			if ( ((MIN_RANGE_STD*256)%temp) > 0  ) xFactor++;			
			// store the c factor in EEPROM				
			DATAEE_WriteByte(cx_std_address, (uint8_t) xFactor);	
					
			// y axis (standard mode): use the difference between neutral and min or neutral and max, whatever is smaller
			if ( (yMax - yNeutral16) < (yNeutral16 - yMin) )
				temp = yMax - yNeutral16;
			else
				temp = yNeutral16 - yMin;		
			// calculate y axis factor (standard mode)					
			yFactor = ((MIN_RANGE_STD*256)/temp);			
			// if remainder, add one		
			if ( ((MIN_RANGE_STD*256)%temp) > 0  ) yFactor++;
			// store the c factor in EEPROM	
			DATAEE_WriteByte(cy_std_address, (uint8_t) yFactor);
			
			
			// x axis (extended range mode): use the difference between neutral and min or neutral and max, whatever is smaller
			if ( (xMax - xNeutral16) < (xNeutral16 - xMin) )
				temp = xMax - xNeutral16;
			else
				temp = xNeutral16 - xMin;
			// calculate x axis factor (extended range mode)	
			xFactor = ((MIN_RANGE_XTD*256)/temp);
			// if remainder, add one
			if ( ((MIN_RANGE_XTD*256)%temp) > 0  ) xFactor++;
			// store the c factor in EEPROM	
			DATAEE_WriteByte(cx_xtd_address, (uint8_t) xFactor);
			
			// y axis (extended range mode): use the difference between neutral and min or neutral and max, whatever is smaller
			if ( (yMax - yNeutral16) < (yNeutral16 - yMin) )
				temp = yMax - yNeutral16;
			else
				temp = yNeutral16 - yMin;
			// calculate y axis factor (extended range mode)	
			yFactor = ((MIN_RANGE_XTD*256)/temp);
			// if remainder, add one
			if ( ((MIN_RANGE_XTD*256)%temp) > 0  ) yFactor++;
			// store the c factor in EEPROM	
			DATAEE_WriteByte(cy_xtd_address, (uint8_t) yFactor);
		}
	}
					
}


uint8_t ScaleDown(uint16_t raw12, uint8_t c){
	return  (uint8_t) ( (raw12*c) >> 4);	
}




/**
 End of File
*/