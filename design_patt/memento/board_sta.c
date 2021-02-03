#include<stdio.h>

char board_type_str[6][5] ={
    "PSU",
    "LPU",
    "SFU",
    "FAN",
    "MPU",
    "SHMU",
};
typedef enum {
    BOARD_TYPE_PSU,
    BOARD_TYPE_LPU,
    BOARD_TYPE_SFU,
    BOARD_TYPE_FAN,
    BOARD_TYPE_MPU,
    BOARD_TYPE_SHMU,
    BOARD_TYPE_MAX,
}BoardType;

typedef unsigned          char uint8_t;
typedef enum{
    BOARD_ASSERT = 0,
    BOARD_BUFFER_ST ,
    BOARD_FAN_ST,
    BOARD_HIHG_TEMP,
    BOARD_OVER_TEMP,
    BOARD_POWER_FAULT = 5,
    BOARD_ST_MAX,
}board_state;

#define LPU_BOARD_NUM           16
#define MPU_BOARD_NUM           2
#define SFU_BOARD_NUM           8
#define FAN_BOARD_NUM           4
#define PSU_BOARD_NUM           12
#define SHMU_BOARD_NUM          2

const uint8_t board_stat_num[] = {LPU_BOARD_NUM, SFU_BOARD_NUM, FAN_BOARD_NUM, MPU_BOARD_NUM};

void board_state_print()
{
    char* pwr_fault = NULL;
    char* temp_st = NULL;
    char* fan_st = NULL;
    char* buf_st = NULL;
    char* assert_st = NULL;

    for(uint8_t type=BOARD_TYPE_LPU;type < BOARD_TYPE_SHMU;type++)
    {
        for(uint8_t slot = 1;slot <=board_stat_num[type-1];slot++ )
        {
            if(((uint8_t)(0xc3)>> BOARD_POWER_FAULT)&0x1)
            {
                pwr_fault = "FAULT";
            }
            else
            {
                pwr_fault = "GOOD";
            }
            if(((0xF)>> BOARD_OVER_TEMP)&0x1)
            {
                temp_st = "OVER";
            }
            else if(((uint8_t)(0x4c)>> BOARD_HIHG_TEMP)&0x1)
            {
                temp_st = "HIGH";
            }
            else
                temp_st = "GOOD";
            if(((uint8_t)(0xA)>> BOARD_FAN_ST)&0x1)
            {

                fan_st = "ERROR";
            }
            else
            {

                fan_st = "GOOD";
            }
            if(((uint8_t)(0x6A)>> BOARD_BUFFER_ST)&0x1)
            {

                buf_st = "ERROR";
            }
            else
            {
                buf_st = "GOOD";
            }
            if(((uint8_t)(0x11)>> BOARD_ASSERT)&0x1)
            {
                assert_st = "DEASST";
            }
            else
            {
                assert_st = "ASSERT";
            }


            printf("|%-5s|%-6d|%-6s|%-6s|%-6s|%-6s|%-6s|\n\r",
                    board_type_str[type],
                    slot,
                    pwr_fault,
                    temp_st,
                    fan_st,
                    buf_st,
                    assert_st
                  );
        }
    }
}
int main()
{
    printf("-----*----*----*-----*-----*------*------*------*\n\r");
    printf("|type |slot  |pwst  |temp  |fan_st|buf_st|assert|\n\r");
    printf("-----*----*----*-----*-----*------*------*------*\n\r");
    //printk("|type |temp|board|slot| time      |\n\r");
    board_state_print();
    printf("-----*----*----*-----*-----*------*------*------*\n\r");
}
