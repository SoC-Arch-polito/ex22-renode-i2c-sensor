#include <stm32f4xx_hal.h>

UART_HandleTypeDef huart2;

void MX_USART2_UART_Init(void);
void send_string_usart2(char* buf);