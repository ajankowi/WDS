#ifndef USART_H_
#define USART_H_


#define BUD 9600
#define BRC ((F_CPU/16/BUD)-1)


char *buff;

void USART_Init();
void UART_TxChar(char ch);
void UART_SendString(char *str);
unsigned char UART_RxChar();
void UART_GetString();




#endif /* USART_H_ */
