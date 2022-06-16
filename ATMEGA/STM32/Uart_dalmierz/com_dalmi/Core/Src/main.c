/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include <math.h>
#include "vl53l0x_api.h"
#include "StepMotor.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t r;

uint16_t j,n,m;
char Rx[20],s1[10],s2[10],s3[10];

int x;
int y;
int z;

int16_t ho;

int16_t no;

volatile int flaga_1 = 1;

int8_t a = 0;


uint8_t Message[64];
uint8_t MessageLen;

VL53L0X_RangingMeasurementData_t RangingData;
VL53L0X_Dev_t  vl53l0x_c; // center module
VL53L0X_DEV    Dev = &vl53l0x_c;


int16_t pomiar = 0;								// Zmienne pomocnicze
int16_t licznik = 0;
int16_t Ppros = 0;								// Dlugosc przeciwprostokatnej

int16_t xs = 0;									// Wspolrzedne punktu
int16_t ys = 0;
int16_t zs = 0;

int xo = 0;									// Wspolrzedne punktu
int yo = 0;
int zo = 0;

int16_t prom = 130;									// Odleglosc czujnika od srodka
float kat = 0;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void walec();
int _write(int file, char *ptr, int len);
void kalibruj();

void send(int xwy, int ywy, int zwy);

void resetuj();

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	//
	// VL53L0X initialisation stuff
	//
    uint32_t refSpadCount;
    uint8_t isApertureSpads;
    uint8_t VhvSettings;
    uint8_t PhaseCal;


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */

  Dev->I2cHandle = &hi2c1;
  Dev->I2cDevAddr = 0x52;
  //
  // VL53L0X init for Single Measurement
  //

  VL53L0X_WaitDeviceBooted( Dev );
  VL53L0X_DataInit( Dev );
  VL53L0X_StaticInit( Dev );
  VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
  VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING);

  // Enable/Disable Sigma and Signal check
  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 33000);
  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);

  __HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);

  //printf("\r\n Rozpoczeto skanowanie \r\n");


  //half_step_motor_right(1024,2);


  //half_step_motor_right(1024,1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  walec();


  while(z != 987){
	  HAL_Delay(100);
  }

  no = x;
  ho = y;

  kalibruj();


  //HAL_Delay(4000);
  send(8889,8889,8889);

  while(z != 944){
 	  HAL_Delay(100);
   }

  //while (1)
 // {
	while((zo<20)&&(licznik<40)&&z!=997){						// Pętla powtarzająca się 20 razu

		for(int a=1; a<65 ;a++){
			VL53L0X_PerformSingleRangingMeasurement(Dev, &RangingData);
				if(z == 997){
					send(144,144,144);
				}
				if(RangingData.RangeStatus == 0){
					pomiar = RangingData.RangeMilliMeter;
				}

				pomiar = pomiar - 10;

				//printf("%d\r\n",pomiar);
				//HAL_Delay(1000);

				if(pomiar<prom){											// Odrzucanie błędnych pomiarów

					licznik = 0;
					kat = (2*M_PI*a*8)/512;									// Oblicza kąt w radianach
					Ppros = prom - pomiar;						// Oblicza odległosc od srodka silnika krokowego
					xo = Ppros*cosf(kat);					// Wspolrzedna X
					yo = Ppros*sinf(kat);					// Wspolrzedna Y
					send(xo,yo,3*zo);
				}											// Zapisane dane nie zostaja stracone
				else{
					licznik++;								// Zwiekszenie licznika
				}
				half_step_motor_right(8,1);

		}
		zo++;
		SM_it();
		half_step_motor_right(1024,2);
		SM_it();
	}
  	send(144,144,144);


  return 0;


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
 // }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


void walec(){

	uint16_t flag1 = 0;

	while(flag1 < 4){						// Pętla powtarzająca się 20 razu

		for(int a=1; a<65 ;a++){
			    flag1++;

				//printf("%d\r\n",pomiar);
				//HAL_Delay(1000);
											// Odrzucanie błędnych pomiarów

				kat = (2*M_PI*a*8)/512;									// Oblicza kąt w radianach
				Ppros = 40;						// Oblicza odległosc od srodka silnika krokowego
				xo = Ppros*cosf(kat);					// Wspolrzedna X
				yo = Ppros*sinf(kat);					// Wspolrzedna Y
				send(xo,yo,3*zo);
															// Zapisane dane nie zostaja stracone

		}
		zo++;

	}

}

void kalibruj(){

	uint8_t flaga = 1;

	//printf( "Kalibracja skanera \r\n");				// Wyswietla komunikat

	while(flaga){

		half_step_motor_left(256,2);			// uruchamia silnik krokowy
		SM_it();
		  VL53L0X_PerformSingleRangingMeasurement(Dev, &RangingData);

		  if(RangingData.RangeStatus == 0){
			if(RangingData.RangeMilliMeter < 200){						// Jezeli pomiar jest mniejszy od 20cm
				flaga = 0;

				//printf("Skalibrowano skaner\r\n");	// Wyswietla komunikat
			}
		}
	}

	half_step_motor_right(512,2);				// Uruchamia 2 silnik krokowy
	SM_it();
}




int _write(int file, char *ptr, int len){

	  if(HAL_UART_Transmit(&huart2, (uint8_t *) ptr, len, 100) != HAL_OK){
		  Error_Handler();
	  }

	return len;
}

void send(int xwy, int ywy, int zwy){

	 	// Zapisanie wspolrzednych do bufora
	printf("X %d %d %d\n",xwy,ywy,zwy );

}

void resetuj(char *tab){

	int8_t k = 0;

	k = strlen(tab);

	while(k>=-1){
		tab[k] = '\0';
		k--;
	}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	//resetuj();


	switch(r){





	case ' ':

		if(flaga_1){
			strncpy(s1,Rx,j);
			sscanf(s1, "%d", &x);
			flaga_1 = 0;
			j=0;
			resetuj(s1);
			break;
		}else{
			strncpy(s2,Rx,j);
			sscanf(Rx, "%d", &y);
			j=0;
			resetuj(s2);
			break;
		}

		break;

	case '@':
		strncpy(s3,Rx,j);
		sscanf(Rx, "%d", &z);
		j=0;
		flaga_1 = 1;
		resetuj(s3);
		break;

	default: Rx[j++]=r;

	}



}













/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
