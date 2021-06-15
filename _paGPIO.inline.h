#include "_paGPIO.inline.inc.h"

paErr init(N_paGPIO::Mode gpioMode, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

inline void write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, char status)
{
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, (GPIO_PinState)status);
    // gpio_set_level(pin, status);
}
inline char read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}