
#include "modbus_test.h"

static modbus_t *ctx;

ComStatus Driver_Modbus_Init(void)
{
    ctx = modbus_new_rtu("/dev/pts/4", 115200, 'N', 8, 1);
    modbus_set_debug(ctx, true);
}

/**
 * @brief 写单个线圈
 * 
 * @param id 
 * @param index 
 * @param data 
 */
void Driver_Modbus_WriteSingleCoil( uint8_t id, uint16_t index,  uint8_t data )
{
    modbus_set_slave(ctx, id);
    modbus_write_bit(ctx, index, data);
}

/**
 * @brief 读单个离散寄存器
 * 
 * @param id 
 * @param index 
 * @param data 
 */
void Driver_Modbus_ReadDiscRegister( uint8_t id, uint16_t index, uint8_t* data )
{
    modbus_set_slave(ctx, id);
    modbus_read_input_bits(ctx, index, 1, data);
}




/**
 * @brief 写多个保持寄存器
 * 
 * @param id 
 * @param index 
 * @param size 
 * @param datas 
 */
void Driver_Modbus_WriteHoldRegisters( uint8_t id, uint16_t index, uint16_t size, uint16_t* datas );

/**
 * @brief 读取多个输入寄存器
 * 
 * @param id 
 * @param index 
 * @param size 
 * @param datas 
 */
void Driver_Modbus_ReadInputRegisters( uint8_t id, uint16_t index, uint16_t size, uint16_t* datas );

/**
 * @brief 回收资源
 * 
 */
void Driver_Modbus_Destory(void)
{
    
}