/**
 * @file	: lpc17xx_pwm.c
 * @brief	: Contains all functions support for PWM firmware library on LPC17xx
 * @version	: 1.0
 * @date	: 22. Apr. 2009
 * @author	: HieuNguyen
 *----------------------------------------------------------------------------
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 **********************************************************************/

#include "lpc17xx_pwm.h"
#include "lpc17xx_clkpwr.h"
#include "lpc17xx_pinsel.h"


/* If this source file built with example, the LPC17xx FW library configuration
 * file in each example directory ("lpc17xx_libcfg.h") must be included,
 * otherwise the default FW library configuration file must be included instead
 */
#ifdef __BUILD_WITH_EXAMPLE__
#include "lpc17xx_libcfg.h"
#else
#include "lpc17xx_libcfg_default.h"
#endif /* __BUILD_WITH_EXAMPLE__ */

#ifdef _PWM
/************************** PRIVATE VARIABLES *************************/
#ifdef _PWM1
/** @addtogroup Private_Variables
 * @{
 */

/** @defgroup PWM_Private_Variables
 * @{
 */

/** PWM Ouput pin ----------------------------------------------------------------- */
const PINSEL_CFG_Type pwm1_1_pinsel[PWM1_1_MAX_PIN] = \
				{ 	PWM1_1_PINSEL_P1_18, \
					PWM1_1_PINSEL_P2_0 };

const PINSEL_CFG_Type pwm1_2_pinsel[PWM1_2_MAX_PIN] = \
				{ 	PWM1_2_PINSEL_P1_20, \
					PWM1_2_PINSEL_P2_1 };

const PINSEL_CFG_Type pwm1_3_pinsel[PWM1_3_MAX_PIN] = \
				{ 	PWM1_3_PINSEL_P1_21, \
					PWM1_3_PINSEL_P2_2 };

const PINSEL_CFG_Type pwm1_4_pinsel[PWM1_4_MAX_PIN] = \
				{ 	PWM1_4_PINSEL_P1_23, \
					PWM1_4_PINSEL_P2_3 };

const PINSEL_CFG_Type pwm1_5_pinsel[PWM1_5_MAX_PIN] = \
				{ 	PWM1_5_PINSEL_P1_24, \
					PWM1_5_PINSEL_P2_4 };

const PINSEL_CFG_Type pwm1_6_pinsel[PWM1_6_MAX_PIN] = \
				{ 	PWM1_6_PINSEL_P1_26, \
					PWM1_6_PINSEL_P2_5 };

/** PWM Capture input pin --------------------------------------------------------- */
const PINSEL_CFG_Type pwm1_cap0_pinsel[PWM1_CAP0_MAX_PIN] = \
				{ 	PWM1_PINSEL_CAP0_P1_18 };

const PINSEL_CFG_Type pwm1_cap1_pinsel[PWM1_CAP1_MAX_PIN] = \
				{ 	PWM1_PINSEL_CAP1_P1_19 };


/** PWM PCAP input pin (in counter mode ) ----------------------------------------- */
const PINSEL_CFG_Type pwm1_pcap0_pinsel[PWM1_PCAP0_MAX_PIN] = \
				{ 	PWM1_PINSEL_PCAP0_P1_28 };

const PINSEL_CFG_Type pwm1_pcap1_pinsel[PWM1_PCAP1_MAX_PIN] = \
				{ 	PWM1_PINSEL_PCAP1_P1_29 };
#endif /* _PWM1 */

/**
 * @}
 */

/**
 * @}
 */

/************************** GLOBAL/PUBLIC FUNCTIONS *************************/

/** @addtogroup Public_Functions
  * @{
  */

/** @defgroup PWM_Public_Functions
 * @{
 */

/*********************************************************************//**
 * @brief		Set pin used as PWM function corresponding to each channel.
 * @param[in]	PWMx: PWM peripheral, should be PWM1.
 * @param[in]	PWM_Channel PWM channel number, should be in range from
 * 							1 to 6
 * @param[in]	PinselOption PWM pin selection option, PinselOption depends
 * 				on which selected channel as following:
 * 				- PWM_Channel = 1:
 *					+ PWM1_1_P1_18
 *					+ PWM1_1_P2_0
 * 				- PWM_Channel = 2:
 *					+ PWM1_2_P1_20
 *					+ PWM1_2_P2_1
 * 				- PWM_Channel = 3:
 *					+ PWM1_3_P1_21
 *					+ PWM1_3_P2_2
 * 				- PWM_Channel = 4:
 *					+ PWM1_4_P1_23
 *					+ PWM1_4_P2_3
 * 				- PWM_Channel = 5:
 *					+ PWM1_5_P1_24
 *					+ PWM1_5_P2_4
 * 				- PWM_Channel = 6:
 *					+ PWM1_6_P1_26
 *					+ PWM1_6_P2_5
 * @return 		None
 **********************************************************************/
void PWM_PinConfig(PWM_TypeDef *PWMx, uint8_t PWM_Channel, uint8_t PinselOption)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));

	if (PWMx == PWM1)
	{
		CHECK_PARAM(PARAM_PWM1_CHANNEL(PWM_Channel));
		switch (PWM_Channel)
		{
		case 1:
			CHECK_PARAM(PARAM_PWM1_1_PIN(PinselOption));
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_1_pinsel[PinselOption]));
			break;
		case 2:
			CHECK_PARAM(PARAM_PWM1_2_PIN(PinselOption));
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_2_pinsel[PinselOption]));
			break;
		case 3:
			CHECK_PARAM(PARAM_PWM1_3_PIN(PinselOption));
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_3_pinsel[PinselOption]));
			break;
		case 4:
			CHECK_PARAM(PARAM_PWM1_4_PIN(PinselOption));
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_4_pinsel[PinselOption]));
			break;
		case 5:
			CHECK_PARAM(PARAM_PWM1_5_PIN(PinselOption));
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_5_pinsel[PinselOption]));
			break;
		case 6:
			CHECK_PARAM(PARAM_PWM1_6_PIN(PinselOption));
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_6_pinsel[PinselOption]));
			break;
		}
	}
}


/*********************************************************************//**
 * @brief 		Check whether specified interrupt flag in PWM is set or not
 * @param[in]	PWMx: PWM peripheral, should be PWM1
 * @param[in]	IntFlag: PWM interrupt flag, should be:
 * 				- PWM_INTSTAT_MR0: Interrupt flag for PWM match channel 0
 * 				- PWM_INTSTAT_MR1: Interrupt flag for PWM match channel 1
 * 				- PWM_INTSTAT_MR2: Interrupt flag for PWM match channel 2
 * 				- PWM_INTSTAT_MR3: Interrupt flag for PWM match channel 3
 * 				- PWM_INTSTAT_MR4: Interrupt flag for PWM match channel 4
 * 				- PWM_INTSTAT_MR5: Interrupt flag for PWM match channel 5
 * 				- PWM_INTSTAT_MR6: Interrupt flag for PWM match channel 6
 * 				- PWM_INTSTAT_CAP0: Interrupt flag for capture input 0
 * 				- PWM_INTSTAT_CAP1: Interrupt flag for capture input 1
 * @return 		New State of PWM interrupt flag (SET or RESET)
 **********************************************************************/
IntStatus PWM_GetIntStatus(PWM_TypeDef *PWMx, uint32_t IntFlag)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM_INTSTAT(IntFlag));

	return ((PWMx->IR & IntFlag) ? SET : RESET);
}



/*********************************************************************//**
 * @brief 		Clear specified PWM Interrupt pending
 * @param[in]	PWMx: PWM peripheral, should be PWM1
 * @param[in]	IntFlag: PWM interrupt flag, should be:
 * 				- PWM_INTSTAT_MR0: Interrupt flag for PWM match channel 0
 * 				- PWM_INTSTAT_MR1: Interrupt flag for PWM match channel 1
 * 				- PWM_INTSTAT_MR2: Interrupt flag for PWM match channel 2
 * 				- PWM_INTSTAT_MR3: Interrupt flag for PWM match channel 3
 * 				- PWM_INTSTAT_MR4: Interrupt flag for PWM match channel 4
 * 				- PWM_INTSTAT_MR5: Interrupt flag for PWM match channel 5
 * 				- PWM_INTSTAT_MR6: Interrupt flag for PWM match channel 6
 * 				- PWM_INTSTAT_CAP0: Interrupt flag for capture input 0
 * 				- PWM_INTSTAT_CAP1: Interrupt flag for capture input 1
 * @return 		None
 **********************************************************************/
void PWM_ClearIntPending(PWM_TypeDef *PWMx, uint32_t IntFlag)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM_INTSTAT(IntFlag));
	PWMx->IR = IntFlag;
}



/*****************************************************************************//**
* @brief		Fills each PWM_InitStruct member with its default value:
* 				- If PWMCounterMode = PWM_MODE_TIMER:
* 					+ PrescaleOption = PWM_TIMER_PRESCALE_USVAL
* 					+ PrescaleValue = 1
* 				- If PWMCounterMode = PWM_MODE_COUNTER:
* 					+ CountInputSelect = PWM_COUNTER_PCAP1_0
* 					+ CounterOption = PWM_COUNTER_RISING
* 					+ CountInputPinConfigState =  ENABLE
* @param[in]	PWMTimerCounterMode Timer or Counter mode, should be:
* 				- PWM_MODE_TIMER: Counter of PWM peripheral is in Timer mode
* 				- PWM_MODE_COUNTER: Counter of PWM peripheral is in Counter mode
* @param[in]	PWM_InitStruct Pointer to structure (PWM_TIMERCFG_Type or
* 				 PWM_COUNTERCFG_Type) which will be initialized.
* @return		None
* Note: PWM_InitStruct pointer will be assigned to corresponding structure
* 		(PWM_TIMERCFG_Type or PWM_COUNTERCFG_Type) due to PWMTimerCounterMode.
*******************************************************************************/
void PWM_ConfigStructInit(uint8_t PWMTimerCounterMode, void *PWM_InitStruct)
{
	CHECK_PARAM(PARAM_PWM_TC_MODE(PWMTimerCounterMode));

	PWM_TIMERCFG_Type *pTimeCfg = (PWM_TIMERCFG_Type *) PWM_InitStruct;
	PWM_COUNTERCFG_Type *pCounterCfg = (PWM_COUNTERCFG_Type *) PWM_InitStruct;

	if (PWMTimerCounterMode == PWM_MODE_TIMER )
	{
		pTimeCfg->PrescaleOption = PWM_TIMER_PRESCALE_USVAL;
		pTimeCfg->PrescaleValue = 1;
	}
	else if (PWMTimerCounterMode == PWM_MODE_COUNTER)
	{
		pCounterCfg->CountInputSelect = PWM_COUNTER_PCAP1_0;
		pCounterCfg->CounterOption = PWM_COUNTER_RISING;
		pCounterCfg->CountInputPinConfigState = ENABLE;
	}
}


/*********************************************************************//**
 * @brief 		Initializes the PWMx peripheral corresponding to the specified
 *               parameters in the PWM_ConfigStruct.
 * @param[in]	PWMx PWM peripheral, should be PWM1
 * @param[in]	PWMTimerCounterMode Timer or Counter mode, should be:
 * 				- PWM_MODE_TIMER: Counter of PWM peripheral is in Timer mode
 * 				- PWM_MODE_COUNTER: Counter of PWM peripheral is in Counter mode
 * @param[in]	PWM_ConfigStruct Pointer to structure (PWM_TIMERCFG_Type or
 * 				 PWM_COUNTERCFG_Type) which will be initialized.
 * @return 		None
 * Note: PWM_ConfigStruct pointer will be assigned to corresponding structure
 * 		(PWM_TIMERCFG_Type or PWM_COUNTERCFG_Type) due to PWMTimerCounterMode.
 **********************************************************************/
void PWM_Init(PWM_TypeDef *PWMx, uint32_t PWMTimerCounterMode, void *PWM_ConfigStruct)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM_TC_MODE(PWMTimerCounterMode));

	PWM_TIMERCFG_Type *pTimeCfg = (PWM_TIMERCFG_Type *)PWM_ConfigStruct;
	PWM_COUNTERCFG_Type *pCounterCfg = (PWM_COUNTERCFG_Type *)PWM_ConfigStruct;
	uint64_t clkdlycnt;

	if (PWMx == PWM1)
	{
		CLKPWR_ConfigPPWR (CLKPWR_PCONP_PCPWM1, ENABLE);
		CLKPWR_SetPCLKDiv (CLKPWR_PCLKSEL_PWM1, CLKPWR_PCLKSEL_CCLK_DIV_4);
		// Get peripheral clock of PWM1
		clkdlycnt = (uint64_t) CLKPWR_GetPCLK (CLKPWR_PCLKSEL_PWM1);
	}

	// Clear all interrupts pending
	PWMx->IR = 0xFF & PWM_IR_BITMASK;
	PWMx->TCR = 0x00;
	PWMx->CTCR = 0x00;
	PWMx->MCR = 0x00;
	PWMx->CCR = 0x00;
	PWMx->PCR = 0x00;
	PWMx->LER = 0x00;

	if (PWMTimerCounterMode == PWM_MODE_TIMER)
	{
		CHECK_PARAM(PARAM_PWM_TIMER_PRESCALE(pTimeCfg->PrescaleOption));

		/* Absolute prescale value */
		if (pTimeCfg->PrescaleOption == PWM_TIMER_PRESCALE_TICKVAL)
		{
			PWMx->PR   = pTimeCfg->PrescaleValue - 1;
		}
		/* uSecond prescale value */
		else
		{
			clkdlycnt = (clkdlycnt * pTimeCfg->PrescaleValue) / 1000000;
			PWMx->PR = ((uint32_t) clkdlycnt) - 1;
		}

	}
	else if (PWMTimerCounterMode == PWM_MODE_COUNTER)
	{
		CHECK_PARAM(PARAM_PWM_COUNTER_INPUTSEL(pCounterCfg->CountInputSelect));
		CHECK_PARAM(PARAM_PWM_COUNTER_EDGE(pCounterCfg->CounterOption));
		CHECK_PARAM(PARAM_FUNCTIONALSTATE(pCounterCfg->CountInputPinConfigState));

		PWMx->CTCR |= (PWM_CTCR_MODE((uint32_t)pCounterCfg->CounterOption)) \
						| (PWM_CTCR_SELECT_INPUT((uint32_t)pCounterCfg->CountInputSelect));
		// configure PCAP pin according to its function
		if (pCounterCfg->CountInputPinConfigState == ENABLE)
		{
			// Configure PCAP pin
			if (pCounterCfg->CountInputSelect == PWM_COUNTER_PCAP1_0)
			{
				PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_pcap0_pinsel[0]));
			}
			else if (pCounterCfg->CountInputSelect == PWM_COUNTER_PCAP1_1)
			{
				PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_pcap1_pinsel[0]));
			}
		}
	}
}

/*********************************************************************//**
 * @brief		De-initializes the PWM peripheral registers to their
*                  default reset values.
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @return 		None
 **********************************************************************/
void PWM_DeInit (PWM_TypeDef *PWMx)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));

	// Disable PWM control (timer, counter and PWM)
	PWMx->TCR = 0x00;

	if (PWMx == PWM1)
	{
		CLKPWR_ConfigPPWR (CLKPWR_PCONP_PCPWM1, DISABLE);
	}
}


/*********************************************************************//**
 * @brief	 	Enable/Disable PWM peripheral
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]	NewState	New State of this function, should be:
 * 							- ENABLE: Enable PWM peripheral
 * 							- DISABLE: Disable PWM peripheral
 * @return 		None
 **********************************************************************/
void PWM_Cmd(PWM_TypeDef *PWMx, FunctionalState NewState)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(NewState));

	if (NewState == ENABLE)
	{
		PWMx->TCR	|=  PWM_TCR_PWM_ENABLE;
	}
	else
	{
		PWMx->TCR &= (~PWM_TCR_PWM_ENABLE) & PWM_TCR_BITMASK;
	}
}


/*********************************************************************//**
 * @brief 		Enable/Disable Counter in PWM peripheral
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]	NewState New State of this function, should be:
 * 							- ENABLE: Enable Counter in PWM peripheral
 * 							- DISABLE: Disable Counter in PWM peripheral
 * @return 		None
 **********************************************************************/
void PWM_CounterCmd(PWM_TypeDef *PWMx, FunctionalState NewState)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(NewState));
	if (NewState == ENABLE)
	{
		PWMx->TCR	|=  PWM_TCR_COUNTER_ENABLE;
	}
	else
	{
		PWMx->TCR &= (~PWM_TCR_COUNTER_ENABLE) & PWM_TCR_BITMASK;
	}
}


/*********************************************************************//**
 * @brief 		Reset Counter in PWM peripheral
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @return 		None
 **********************************************************************/
void PWM_ResetCounter(PWM_TypeDef *PWMx)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	PWMx->TCR |= PWM_TCR_COUNTER_RESET;
	PWMx->TCR &= (~PWM_TCR_COUNTER_RESET) & PWM_TCR_BITMASK;
}


/*********************************************************************//**
 * @brief 		Configures match for PWM peripheral
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]   PWM_MatchConfigStruct	Pointer to a PWM_MATCHCFG_Type structure
*                    that contains the configuration information for the
*                    specified PWM match function.
 * @return 		None
 **********************************************************************/
void PWM_ConfigMatch(PWM_TypeDef *PWMx, PWM_MATCHCFG_Type *PWM_MatchConfigStruct)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM1_MATCH_CHANNEL(PWM_MatchConfigStruct->MatchChannel));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_MatchConfigStruct->IntOnMatch));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_MatchConfigStruct->ResetOnMatch));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_MatchConfigStruct->StopOnMatch));

	//interrupt on MRn
	if (PWM_MatchConfigStruct->IntOnMatch == ENABLE)
	{
		PWMx->MCR |= PWM_MCR_INT_ON_MATCH(PWM_MatchConfigStruct->MatchChannel);
	}
	else
	{
		PWMx->MCR &= (~PWM_MCR_INT_ON_MATCH(PWM_MatchConfigStruct->MatchChannel)) \
					& PWM_MCR_BITMASK;
	}

	//reset on MRn
	if (PWM_MatchConfigStruct->ResetOnMatch == ENABLE)
	{
		PWMx->MCR |= PWM_MCR_RESET_ON_MATCH(PWM_MatchConfigStruct->MatchChannel);
	}
	else
	{
		PWMx->MCR &= (~PWM_MCR_RESET_ON_MATCH(PWM_MatchConfigStruct->MatchChannel)) \
					& PWM_MCR_BITMASK;
	}

	//stop on MRn
	if (PWM_MatchConfigStruct->StopOnMatch == ENABLE)
	{
		PWMx->MCR |= PWM_MCR_STOP_ON_MATCH(PWM_MatchConfigStruct->MatchChannel);
	}
	else
	{
		PWMx->MCR &= (~PWM_MCR_STOP_ON_MATCH(PWM_MatchConfigStruct->MatchChannel)) \
					& PWM_MCR_BITMASK;
	}
}


/*********************************************************************//**
 * @brief 		Configures capture input for PWM peripheral
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]   PWM_CaptureConfigStruct	Pointer to a PWM_CAPTURECFG_Type structure
*                    that contains the configuration information for the
*                    specified PWM capture input function.
 * @return 		None
 **********************************************************************/
void PWM_ConfigCapture(PWM_TypeDef *PWMx, PWM_CAPTURECFG_Type *PWM_CaptureConfigStruct)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM1_CAPTURE_CHANNEL(PWM_CaptureConfigStruct->CaptureChannel));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_CaptureConfigStruct->CapPinConfigState));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_CaptureConfigStruct->FallingEdge));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_CaptureConfigStruct->IntOnCaption));
	CHECK_PARAM(PARAM_FUNCTIONALSTATE(PWM_CaptureConfigStruct->RisingEdge));

	if (PWM_CaptureConfigStruct->RisingEdge == ENABLE)
	{
		PWMx->CCR |= PWM_CCR_CAP_RISING(PWM_CaptureConfigStruct->CaptureChannel);
	}
	else
	{
		PWMx->CCR &= (~PWM_CCR_CAP_RISING(PWM_CaptureConfigStruct->CaptureChannel)) \
					& PWM_CCR_BITMASK;
	}

	if (PWM_CaptureConfigStruct->FallingEdge == ENABLE)
	{
		PWMx->CCR |= PWM_CCR_CAP_FALLING(PWM_CaptureConfigStruct->CaptureChannel);
	}
	else
	{
		PWMx->CCR &= (~PWM_CCR_CAP_FALLING(PWM_CaptureConfigStruct->CaptureChannel)) \
					& PWM_CCR_BITMASK;
	}

	if (PWM_CaptureConfigStruct->IntOnCaption == ENABLE)
	{
		PWMx->CCR |= PWM_CCR_INT_ON_CAP(PWM_CaptureConfigStruct->CaptureChannel);
	}
	else
	{
		PWMx->CCR &= (~PWM_CCR_INT_ON_CAP(PWM_CaptureConfigStruct->CaptureChannel)) \
					& PWM_CCR_BITMASK;
	}

	// If Capture Input pin configuration state is enabled
	if (PWM_CaptureConfigStruct->CapPinConfigState == ENABLE)
	{
		switch (PWM_CaptureConfigStruct->CaptureChannel)
		{
		case 0:
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_cap0_pinsel[0]));
			break;

		case 1:
			PINSEL_ConfigPin((PINSEL_CFG_Type *)(&pwm1_cap1_pinsel[0]));
			break;

		default:
			break;
		}
	}
}


/*********************************************************************//**
 * @brief 		Read value of capture register PWM peripheral
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]	CaptureChannel: capture channel number, should be in
 * 				range 0 to 1
 * @return 		Value of capture register
 **********************************************************************/
uint32_t PWM_GetCaptureValue(PWM_TypeDef *PWMx, uint8_t CaptureChannel)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM1_CAPTURE_CHANNEL(CaptureChannel));

	switch (CaptureChannel)
	{
	case 0:
		return PWMx->CR0;
		break;

	case 1:
		return PWMx->CR1;
		break;

	default:
		return (0);
		break;
	}
}


/********************************************************************//**
 * @brief 		Update value for each PWM channel with update type option
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]	Channel PWM Channel, should be in range from 1 to 6
 * @param[in]	UpdateType Type of Update, should be:
 * 				- PWM_MATCH_UPDATE_NOW: The update value will be updated for
 * 					this channel immediately
 * 				- PWM_MATCH_UPDATE_NEXT_RST: The update value will be updated for
 * 					this channel on next reset by a PWM Match event.
 * @return		None
 *********************************************************************/
void PWM_MatchUpdate(PWM_TypeDef *PWMx, uint8_t MatchChannel, \
					uint32_t MatchValue, uint8_t UpdateType)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM1_MATCH_CHANNEL(MatchChannel));
	CHECK_PARAM(PARAM_PWM_MATCH_UPDATE(UpdateType));

	switch (MatchChannel)
	{
	case 0:
		PWMx->MR0 = MatchValue;
		break;

	case 1:
		PWMx->MR1 = MatchValue;
		break;

	case 2:
		PWMx->MR2 = MatchValue;
		break;

	case 3:
		PWMx->MR3 = MatchValue;
		break;

	case 4:
		PWMx->MR4 = MatchValue;
		break;

	case 5:
		PWMx->MR5 = MatchValue;
		break;

	case 6:
		PWMx->MR6 = MatchValue;
		break;
	}

	// Write Latch register
	PWMx->LER |= PWM_LER_EN_MATCHn_LATCH(MatchChannel);

	// In case of update now
	if (UpdateType == PWM_MATCH_UPDATE_NOW)
	{
		PWMx->TCR |= PWM_TCR_COUNTER_RESET;
		PWMx->TCR &= (~PWM_TCR_COUNTER_RESET) & PWM_TCR_BITMASK;
	}
}


/********************************************************************//**
 * @brief 		Configure Edge mode for each PWM channel
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]	PWMChannel PWM channel, should be in range from 2 to 6
 * @param[in]	ModeOption PWM mode option, should be:
 * 				- PWM_CHANNEL_SINGLE_EDGE: Single Edge mode
 * 				- PWM_CHANNEL_DUAL_EDGE: Dual Edge mode
 * @return 		None
 * Note: PWM Channel 1 can not be selected for mode option
 *********************************************************************/
void PWM_ChannelConfig(PWM_TypeDef *PWMx, uint8_t PWMChannel, uint8_t ModeOption)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM1_EDGE_MODE_CHANNEL(PWMChannel));
	CHECK_PARAM(PARAM_PWM_CHANNEL_EDGE(ModeOption));

	// Single edge mode
	if (ModeOption == PWM_CHANNEL_SINGLE_EDGE)
	{
		PWMx->PCR &= (~PWM_PCR_PWMSELn(PWMChannel)) & PWM_PCR_BITMASK;
	}
	// Double edge mode
	else if (PWM_CHANNEL_DUAL_EDGE)
	{
		PWMx->PCR |= PWM_PCR_PWMSELn(PWMChannel);
	}
}



/********************************************************************//**
 * @brief 		Enable/Disable PWM channel output
 * @param[in]	PWMx	PWM peripheral selected, should be PWM1
 * @param[in]	PWMChannel PWM channel, should be in range from 1 to 6
 * @param[in]	NewState New State of this function, should be:
 * 				- ENABLE: Enable this PWM channel output
 * 				- DISABLE: Disable this PWM channel output
 * @return		None
 *********************************************************************/
void PWM_ChannelCmd(PWM_TypeDef *PWMx, uint8_t PWMChannel, FunctionalState NewState)
{
	CHECK_PARAM(PARAM_PWMx(PWMx));
	CHECK_PARAM(PARAM_PWM1_CHANNEL(PWMChannel));

	if (NewState == ENABLE)
	{
		PWMx->PCR |= PWM_PCR_PWMENAn(PWMChannel);
	}
	else
	{
		PWMx->PCR &= (~PWM_PCR_PWMENAn(PWMChannel)) & PWM_PCR_BITMASK;
	}
}
/**
 * @}
 */

/**
 * @}
 */

#endif /* _PWM */
