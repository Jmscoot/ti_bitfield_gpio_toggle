//#############################################################################
//
// FILE:   empty_bitfield_driverlib_main.c
//
// TITLE:  Empty Example
//
// Empty Bit-Field & Driverlib Example
//
// This example is an empty project setup for Bit-Field and Driverlib 
// development.
//
//#############################################################################
//
// 
// $Copyright:
// Copyright (C) 2013-2026 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"

//
// Main
//
void main(void)
{
// bus에 클록 공급
InitSysCtrl();
// 패리패럴에 클록 공급
// 패리패럴 configuraiton

// gpio configuration
EALLOW;

// cpu1 or cpu2 누가 소유?
GpioCtrlRegs.GPBCSEL1.bit.GPIO34=0;

// gpio용도 설정
GpioCtrlRegs.GPBGMUX1.bit.GPIO34=0;
GpioCtrlRegs.GPBMUX1.bit.GPIO34=0;

// in or out방향?
GpioCtrlRegs.GPBDIR.bit.GPIO34=1;

// pull up
GpioCtrlRegs.GPBPUD.bit.GPIO34=1;

EDIS;

while(1){
    GpioDataRegs.GPBTOGGLE.bit.GPIO34=1;
    DELAY_US(1000000);
}


}

// //
// // End of File
// //
//
// Included Files
//
// #include "driverlib.h"
// #include "device.h"

// //
// // Main
// //
// void main(void)
// {
//     //
//     // ① 시스템 초기화 (버스 클록 + 페리페럴 클록 + 플래시)
//     //   InitSysCtrl()에 해당. 내부에서 DEVICE_SETCLOCK_CFG로 200MHz 설정
//     //
//     Device_init();

//     //
//     // ② GPIO 초기화 (미사용 핀 풀업 등)
//     //
//     Device_initGPIO();

//     //
//     // ③ GPIO34 configuration
//     //
//     GPIO_setMasterCore(34, GPIO_CORE_CPU1);         // CPU1이 소유
//     GPIO_setPinConfig(GPIO_34_GPIO34);              // MUX=0, GMUX=0 → GPIO 기능
//     GPIO_setDirectionMode(34, GPIO_DIR_MODE_OUT);   // 출력
//     GPIO_setPadConfig(34, GPIO_PIN_TYPE_STD);       // 풀업/풀다운 없음

//     //
//     // 초기 LED 상태 (선택)
//     //
//     GPIO_writePin(34, 0);   // LED OFF로 시작

//     //
//     // ④ Main loop
//     //
//     for(;;)
//     {
//         GPIO_togglePin(34);
//         DEVICE_DELAY_US(1000000);   // 1초
//     }
// }
