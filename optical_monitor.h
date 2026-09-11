#ifndef OPTICAL_MONITOR_H
#define OPTICAL_MONITOR_H

typedef struct {
    float tx_power_dbm;
    float rx_power_dbm;
    float temperature_c;
    float laser_bias_ma;
    float supply_voltage_v;
    int laser_enabled;
    int alarm;
} OpticalModule;

void optical_init(OpticalModule *module);
void optical_set_laser(OpticalModule *module, int enabled);
void optical_check_alarms(OpticalModule *module);
void optical_print_status(const OpticalModule *module);

#endif
