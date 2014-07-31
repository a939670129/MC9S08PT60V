/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : AUX_Display_Panel
**     Processor   : MC9S08PT60VLH
**     Component   : MC9S08PT60_64
**     Version     : Component 01.105, Driver 01.40, CPU db: 3.00.007
**     Datasheet   : MC9S08PT60RM Rev. 3 Draft A, 12/2011
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-07-17, 14:13, # CodeGen: 174
**     Abstract    :
**         This component "MC9S08PT60_64" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**     Contents    :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetStopMode - void Cpu_SetStopMode(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.40
** @brief
**         This component "MC9S08PT60_64" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */

#include "TSS1.h"
#include "LED0.h"
#include "RTC.h"
#include "LED1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Events.h"
#include "Cpu.h"


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR register */
volatile byte CCR_lock;                /* Nesting level of critical regions */


/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MC9S08PT60_64)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S08PT60_64)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S08PT60_64)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component MC9S08PT60_64)
**     Description :
**         Sets the low power mode - Stop mode. This method is
**         available only if the STOP instruction is enabled (see
**         <STOP instruction enabled> property).
**         For more information about the stop mode, see the
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S08PT60_64)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

#pragma NO_FRAME
#pragma NO_EXIT
void _EntryPoint(void)
{
  /* ### MC9S08PT60_64 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* WDOG_CNT: CNT=0xC520 */
  setReg16(WDOG_CNT, 0xC520U);         /* First part of the WDG unlock sequence */ 
  /* WDOG_CNT: CNT=0xD928 */
  setReg16(WDOG_CNT, 0xD928U);         /* Second part of the WDG unlock sequence */ 
  /* WDOG_TOVAL: TOVAL=4 */
  setReg16(WDOG_TOVAL, 0x04U);          
  /* WDOG_CS2: WIN=0,FLG=0,??=0,PRES=0,??=0,??=0,CLK=1 */
  setReg8(WDOG_CS2, 0x01U);             
  /* WDOG_CS1: EN=0,INT=0,UPDATE=0,TST=0,DBG=0,WAIT=0,STOP=0 */
  setReg8(WDOG_CS1, 0x00U);            /* Disable watchdog */ 
  /* Common initialization of the write once registers */
  /* SYS_SOPT1: BKGDPE=1,RSTPE=1,FWAKE=1,STOPE=1 */
  setReg8Bits(SYS_SOPT1, 0x0FU);        
  /* PMC_SPMSC1: LVWIE=0,LVDRE=1,LVDSE=1,LVDE=0,BGBDS=0,BGBE=0 */
  clrSetReg8Bits(PMC_SPMSC1, 0x27U, 0x18U); 
  /* PMC_SPMSC2: LVDV=0,LVWV&=~1 */
  clrReg8Bits(PMC_SPMSC2, 0x50U);       
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(uint8_t*)0xFF6FU != 0xFFU) {   /* Test if the device trim value is stored on the specified address */
    ICS_C3 = *(uint8_t*)0xFF6FU;       /* Initialize ICS_C3 register from a non volatile memory */
    ICS_C4 = (uint8_t)((*(uint8_t*)0xFF6EU) & (uint8_t)0x01U); /* Initialize ICS_C4 register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* ICS_C1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=1 */
  setReg8(ICS_C1, 0x07U);              /* Initialization of the ICS control register 1 */ 
  /* ICS_C2: BDIV=0,LP=0,??=0,??=0,??=0,??=0 */
  setReg8(ICS_C2, 0x00U);              /* Initialization of the ICS control register 2 */ 
  /* ICS_C4: LOLIE=0,CME=0 */
  clrReg8Bits(ICS_C4, 0xA0U);           

  /*** End of PE initialization code after reset ***/
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm   jmp _Startup ;               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S08PT60_64)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /* SCG_C1: FTM2=0,FTM1=0,FTM0=0,??=0,??=0,MTIM1=1,MTIM0=1,RTC=1 */
  setReg8(SCG_C1, 0x07U);               
  /* SCG_C2: ??=0,??=0,DBG=1,NVM=1,IPC=0,CRC=0,??=0,??=0 */
  setReg8(SCG_C2, 0x30U);               
  /* SCG_C3: ??=0,SCI2=0,SCI1=0,SCI0=0,SPI1=0,SPI0=0,IIC=0,??=0 */
  setReg8(SCG_C3, 0x00U);               
  /* SCG_C4: ACMP=0,??=0,ADC=0,??=0,IRQ=1,TSI=1,KBI1=0,KBI0=0 */
  setReg8(SCG_C4, 0x0CU);               
  /* Common initialization of the CPU registers */
  /* PORT_PTDD: PTDD7=1 */
  setReg8Bits(PORT_PTDD, 0x80U);        
  /* PORT_PTDPE: PTDPE7=0 */
  clrReg8Bits(PORT_PTDPE, 0x80U);       
  /* PORT_PTDOE: PTDOE7=1 */
  setReg8Bits(PORT_PTDOE, 0x80U);       
  /* PORT_PTDIE: PTDIE7=0 */
  clrReg8Bits(PORT_PTDIE, 0x80U);       
  /* PORT_PTBD: PTBD5=1 */
  setReg8Bits(PORT_PTBD, 0x20U);        
  /* PORT_PTBPE: PTBPE5=0 */
  clrReg8Bits(PORT_PTBPE, 0x20U);       
  /* PORT_PTBOE: PTBOE5=1 */
  setReg8Bits(PORT_PTBOE, 0x20U);       
  /* PORT_PTBIE: PTBIE5=0 */
  clrReg8Bits(PORT_PTBIE, 0x20U);       
  /* SYS_SOPT3: CLKOE=0,BUSREF=0 */
  clrReg8Bits(SYS_SOPT3, 0x0FU);        
  /* IPC_ILRS9: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS9, 0x00U);            
  /* IPC_ILRS8: ILRn3=2,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS8, 0x80U);            
  /* IPC_ILRS7: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS7, 0x00U);            
  /* IPC_ILRS6: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS6, 0x00U);            
  /* IPC_ILRS5: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS5, 0x00U);            
  /* IPC_ILRS4: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS4, 0x00U);            
  /* IPC_ILRS3: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS3, 0x00U);            
  /* IPC_ILRS2: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS2, 0x00U);            
  /* IPC_ILRS1: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS1, 0x00U);            
  /* IPC_ILRS0: ILRn3=0,ILRn2=0,ILRn1=0,ILRn0=0 */
  setReg8(IPC_ILRS0, 0x00U);            
  /* IPC_SC: IPCE=1,??=0,PSE=0,PSF=0,PULIPM=0,??=0,IPM=0 */
  setReg8(IPC_SC, 0x80U);               
      /* Initialization of the PORT module */
  /* ### Shared modules init code ... */
  /* ### TSS_Library "TSS1" init code ... */
  TSS1_Configure();

  /* Write code here ... */

  /* ### BitIO "LED0" init code ... */
  /* ### Free running 8-bit counter "RTC" init code ... */
  RTC_Init();
  /* ### BitIO "LED1" init code ... */
  CCR_lock = (byte)0;
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/* NV_EEPROT: DPOPEN=1,??=1,??=1,??=1,??=1,DPS=7 */
static const uint8_t NV_EEPROT_INIT @0x0000FF7DU = 0xFFU;
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
