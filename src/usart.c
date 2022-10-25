#include "usart.h"

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART2_UART_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		/* Error_Handler();*/ // Could be used to handle errors
	}
}

/**
  * @brief Send string to usart2
  * @param char *buf buffer to be sent.
  * @retval None
  */
void send_string_usart2(char *buf) {
	int i;
	uint8_t newline[2];
	newline[0] = '\r';
	newline[1] = '\n';

	/* Just for demo purposes. Do not use in real code. You could improve this
	   by sending the full buffer, not one by one */
	for(i=0; buf[i]!= '\0' && i < 100; i++)
		HAL_UART_Transmit(&huart2, (uint8_t*) &buf[i], 1, HAL_MAX_DELAY);

	HAL_UART_Transmit(&huart2, newline, sizeof(newline), HAL_MAX_DELAY);
}