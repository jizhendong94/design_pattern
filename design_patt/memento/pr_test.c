#include<stdio.h>
#include<time.h>
typedef unsigned          char uint8_t;
typedef unsigned           int uint32_t;
typedef struct{
    uint8_t max_temp;
    uint8_t min_temp;

    uint8_t max_temp_board_type;
    uint8_t max_temp_slot_id;

    uint8_t min_temp_board_type;
    uint8_t min_temp_slot_id;
}temp_proc_record_info_t;


typedef struct {
    temp_proc_record_info_t cpu_info;
    temp_proc_record_info_t switch_t_info;
    temp_proc_record_info_t opt_info;
    temp_proc_record_info_t retimer_info;
    temp_proc_record_info_t board_info;
}temp_mostval_of_all_borad_t;

typedef struct{
    temp_mostval_of_all_borad_t temp_info;
    uint32_t cpu_time;
    uint32_t switch_time;
    uint32_t opt_time;
    uint32_t retimer_time;
    uint32_t board_time;
}history_temp_info_t;
history_temp_info_t temp_history_info;
struct fan_temp_speed_id {
    char name[8];
    uint8_t lower;
    uint8_t upper;
    uint8_t alert;
    uint8_t overt;
    uint8_t max_temp;
    uint8_t upper_c;
    uint8_t lower_c;
};
struct fan_temp_speed_id temp_ids[] = {
    { "cpu",     45, 65, 85, 90,0,0,0 },
    { "switch",  62, 75, 85, 90,0,0,0 },
    { "opt",     46, 65, 70, 75,0,0,0 },
    { "retimer", 71, 85, 85, 90,0,0,0 },
    { "board"                   }
};

static uint8_t temp_ids_number = (sizeof(temp_ids)/sizeof(temp_ids[0]));

char temp_id_str[5][6] = {
    {"CPU"},
    {"SWCH"},
    {"OPT"},
    {"RTMR"},
    {"BOAD"}
};
static char board_type_str[6][5] ={
    "PSU",
     "LPU",
     "SFU",
     "FAN",
     "MPU",
     "SHMU",
};
void temp_his_print()
{
    struct  tm* time = NULL;
    printf("|%4s |%-4d|%-5s|%-4d| \n\r",
                "CPU",
               temp_history_info.temp_info.cpu_info.max_temp,
               board_type_str[temp_history_info.temp_info.cpu_info.max_temp_board_type],
               temp_history_info.temp_info.cpu_info.max_temp_slot_id
            );
    printf("|%4s |%-4d|%-5s|%-4d| \n\r",
                "SWCH",
                temp_history_info.temp_info.switch_t_info.max_temp,
                board_type_str[temp_history_info.temp_info.switch_t_info.max_temp_board_type],
                temp_history_info.temp_info.switch_t_info.max_temp_slot_id
        );
    printf("|%4s |%-4d|%-5s|%-4d| \n\r",
                    "OPT",
                    temp_history_info.temp_info.opt_info.max_temp,
                    board_type_str[temp_history_info.temp_info.opt_info.max_temp_board_type],
                    temp_history_info.temp_info.opt_info.max_temp_slot_id
                    );
}

int main()
{
    printf("------*----*-----*----*-----------------\n\r");
    printf("|type |temp|board|slot| time      |\n\r");
    printf("------*------*-------*------*-----------\n\r");
    printf("|type |temp|board|slot| time      |\n\r");
    temp_his_print();
    printf("-------*----------*-------*-------*-----------\n\r");
    return 0;
}
