#include "pusart.h"

void pusart_init(void)
{
	static struct usart_config uconf;
	usart_get_config_defaults(&uconf);
	uconf.pinmux_pad0 = DEBUG_USART_PINMUX_PAD0;
	uconf.pinmux_pad1 = DEBUG_USART_PINMUX_PAD1;
	uconf.pinmux_pad2 = DEBUG_USART_PINMUX_PAD2;
	uconf.pinmux_pad3 = DEBUG_USART_PINMUX_PAD3;
	uconf.mux_setting = DEBUG_USART_MUX_SETTING;
	uconf.baudrate = DEBUG_USART_BAUDRATE;
	stdio_serial_init(&umod, DEBUG_USART_MODULE, &uconf);
	usart_enable(&umod);
}

