/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F25K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set YB aliases
#define YB_TRIS                 TRISAbits.TRISA6
#define YB_LAT                  LATAbits.LATA6
#define YB_PORT                 PORTAbits.RA6
#define YB_WPU                  WPUAbits.WPUA6
#define YB_OD                   ODCONAbits.ODCA6
#define YB_ANS                  ANSELAbits.ANSELA6
#define YB_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define YB_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define YB_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define YB_GetValue()           PORTAbits.RA6
#define YB_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define YB_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define YB_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define YB_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define YB_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define YB_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define YB_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define YB_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set YA aliases
#define YA_TRIS                 TRISAbits.TRISA7
#define YA_LAT                  LATAbits.LATA7
#define YA_PORT                 PORTAbits.RA7
#define YA_WPU                  WPUAbits.WPUA7
#define YA_OD                   ODCONAbits.ODCA7
#define YA_ANS                  ANSELAbits.ANSELA7
#define YA_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define YA_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define YA_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define YA_GetValue()           PORTAbits.RA7
#define YA_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define YA_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define YA_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define YA_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define YA_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define YA_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define YA_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define YA_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set XA aliases
#define XA_TRIS                 TRISBbits.TRISB0
#define XA_LAT                  LATBbits.LATB0
#define XA_PORT                 PORTBbits.RB0
#define XA_WPU                  WPUBbits.WPUB0
#define XA_OD                   ODCONBbits.ODCB0
#define XA_ANS                  ANSELBbits.ANSELB0
#define XA_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define XA_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define XA_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define XA_GetValue()           PORTBbits.RB0
#define XA_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define XA_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define XA_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define XA_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define XA_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define XA_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define XA_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define XA_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set XB aliases
#define XB_TRIS                 TRISBbits.TRISB1
#define XB_LAT                  LATBbits.LATB1
#define XB_PORT                 PORTBbits.RB1
#define XB_WPU                  WPUBbits.WPUB1
#define XB_OD                   ODCONBbits.ODCB1
#define XB_ANS                  ANSELBbits.ANSELB1
#define XB_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define XB_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define XB_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define XB_GetValue()           PORTBbits.RB1
#define XB_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define XB_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define XB_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define XB_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define XB_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define XB_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define XB_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define XB_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set AnalogY aliases
#define AnalogY_TRIS                 TRISCbits.TRISC2
#define AnalogY_LAT                  LATCbits.LATC2
#define AnalogY_PORT                 PORTCbits.RC2
#define AnalogY_WPU                  WPUCbits.WPUC2
#define AnalogY_OD                   ODCONCbits.ODCC2
#define AnalogY_ANS                  ANSELCbits.ANSELC2
#define AnalogY_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define AnalogY_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define AnalogY_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define AnalogY_GetValue()           PORTCbits.RC2
#define AnalogY_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define AnalogY_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define AnalogY_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define AnalogY_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define AnalogY_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define AnalogY_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define AnalogY_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define AnalogY_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set AnalogX aliases
#define AnalogX_TRIS                 TRISCbits.TRISC3
#define AnalogX_LAT                  LATCbits.LATC3
#define AnalogX_PORT                 PORTCbits.RC3
#define AnalogX_WPU                  WPUCbits.WPUC3
#define AnalogX_OD                   ODCONCbits.ODCC3
#define AnalogX_ANS                  ANSELCbits.ANSELC3
#define AnalogX_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define AnalogX_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define AnalogX_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define AnalogX_GetValue()           PORTCbits.RC3
#define AnalogX_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define AnalogX_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define AnalogX_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define AnalogX_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define AnalogX_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define AnalogX_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define AnalogX_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define AnalogX_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC4
#define LED_LAT                  LATCbits.LATC4
#define LED_PORT                 PORTCbits.RC4
#define LED_WPU                  WPUCbits.WPUC4
#define LED_OD                   ODCONCbits.ODCC4
#define LED_ANS                  ANSELCbits.ANSELC4
#define LED_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED_GetValue()           PORTCbits.RC4
#define LED_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/