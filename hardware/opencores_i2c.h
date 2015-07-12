#ifndef __OPENCORES_I2C_H__
#define __OPENCORES_I2C_H__


//#include "alt_types.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include<stdint.h>


void I2C_init(uint32_t base,uint32_t clk,uint32_t speed);
int I2C_start(uint32_t base, uint32_t add, uint32_t read);
uint32_t I2C_read(uint32_t base,uint32_t last);
uint32_t I2C_write(uint32_t base,uint8_t data, uint32_t last);
#define I2C_OK (0)
#define I2C_ACK (0)
#define I2C_NOACK (1)
#define I2C_ABITRATION_LOST (2)

#define OPENCORES_I2C_INSTANCE(name, dev) extern int alt_no_storage
#define OPENCORES_I2C_INIT(name, dev) while (0)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __OPENCORES_I2C_H__ */
