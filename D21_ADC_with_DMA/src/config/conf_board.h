/**
 * \file
 *
 * \brief SAM D21 Xplained Pro board configuration.
 *
 * Copyright (c) 2013-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

// Debug Terminal Config
#define DEBUG_USART_MODULE			SERCOM3
#define DEBUG_USART_PINMUX_PAD0		PINMUX_PA22C_SERCOM3_PAD0
#define DEBUG_USART_PINMUX_PAD1		PINMUX_PA23C_SERCOM3_PAD1
#define DEBUG_USART_PINMUX_PAD2		PINMUX_UNUSED
#define DEBUG_USART_PINMUX_PAD3		PINMUX_UNUSED
#define DEBUG_USART_BAUDRATE		115200
#define DEBUG_USART_MUX_SETTING		USART_RX_1_TX_0_XCK_1

// ADC Config
#define P_ADC_RESOLUTION			ADC_RESOLUTION_12BIT
#define P_ADC_CLOCK_PRESCALAR		ADC_CLOCK_PRESCALER_DIV8
#define P_ADC_GAIN_FACTOR			ADC_GAIN_FACTOR_1X
// 1/1.48V<SUB>CC</SUB> reference so
// 1 / 1.48 * 3.3 (ideally) = 2.2297
#define P_ADC_VREF					ADC_REFERENCE_INTVCC0
#define P_ADC_VREF_VAL				(2.2297f)
#define P_ADC_POSITIVE_INPUT_PIN	ADC_POSITIVE_INPUT_PIN4		// PA04
#define P_ADC_NEGATIVE_INPUT_PIN	ADC_NEGATIVE_INPUT_GND
// How many values we want to grab out of our buffer
#define P_ADC_OVERSAMPLE_RATE		16
// How big we want our buffer to be							
#define P_ADC_BUFFER_SIZE			16

#endif /* CONF_BOARD_H_INCLUDED */
