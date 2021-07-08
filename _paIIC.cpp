#include "paCoreInc/drv/paIIC.h"
// #include "driver/i2c.h"
#include "string.h"
#include "main.h"

#define I2C_SUCC 1
#define I2C_FAIL 0

extern I2C_HandleTypeDef hi2c1;

uint8_t paIIC::init(unsigned char iicId)
{

    return I2C_SUCC;
}

uint8_t paIIC::writeLen(unsigned char iicId,
                        unsigned char addr,
                        unsigned char length, ByteArr data_wr[])
{
    // i2c_cmd_handle_t cmd = i2c_cmd_link_create();

    switch (iicId)
    {
    case 0:
    {
        addr <<= 1;
        for (int i = 0; i < length; i++)
        {
            auto state = HAL_I2C_Master_Transmit(&hi2c1, addr, data_wr[i].arrPtr, data_wr[i].len, 500);
            // auto state = HAL_I2C_Mem_Write(&hi2c1, addr, reg, 1, data_t, length, 100);
            if (state == HAL_StatusTypeDef::HAL_OK)
            {
                return I2C_SUCC;
            }
            else
            {
                return I2C_FAIL;
            }
        }

        // i2c_master_start(cmd);
        // //addr
        // i2c_master_write_byte(cmd, (addr << 1) | I2C_MASTER_READ, ACK_CHECK_EN);
        // // ESP_LOGI("IIC", "addr:%x len:%d", addr, length);
        // for (int i = 0; i < length; i++)
        // {
        //     // for(int j=0;j<data_wr[i].len;)
        //     ESP_LOGI("IIC", "data:%2x %2x", *(data_wr[i].arrPtr), *(data_wr[i].arrPtr + 1));
        //     i2c_master_write(cmd, data_wr[i].arrPtr, data_wr[i].len, ACK_CHECK_EN);
        // }
        // //data
        // // if (size > 1)
        // // {
        // //     i2c_master_read(cmd, data_rd, size - 1, ACK_VAL);
        // // }

        // // i2c_master_read_byte(cmd, data_rd + size - 1, NACK_VAL);
        // i2c_master_stop(cmd);
    }
    break;

    default:
        return 0;
    }
    return 1;
}
