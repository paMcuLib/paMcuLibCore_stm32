#include "paCoreHead/paSPI.h"
#include "main.h"
paErr paSPI::init(char spiId)
{
}

paErr paSPI::transmit(char spiId, unsigned char *data, unsigned int len)
{
    HAL_SPI_Transmit(&hspi1, data, len, 100);
}