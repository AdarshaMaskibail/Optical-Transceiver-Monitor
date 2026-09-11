#include <stdio.h>
#include "optical_monitor.h"

void optical_init(OpticalModule *m) {
    m->tx_power_dbm = 2.8f;
    m->rx_power_dbm = -14.2f;
    m->temperature_c = 42.5f;
    m->laser_bias_ma = 62.0f;
    m->supply_voltage_v = 3.30f;
    m->laser_enabled = 0;
    m->alarm = 0;
}

void optical_set_laser(OpticalModule *m, int enabled) {
    m->laser_enabled = enabled ? 1 : 0;
    printf("Laser: %s\n", m->laser_enabled ? "ON" : "OFF");
}

void optical_check_alarms(OpticalModule *m) {
    m->alarm = 0;

    if (m->temperature_c > 70.0f) {
        printf("ALARM: HIGH_TEMPERATURE\n");
        m->alarm = 1;
    }
    if (m->tx_power_dbm < 0.0f) {
        printf("ALARM: LOW_TX_POWER\n");
        m->alarm = 1;
    }
    if (m->rx_power_dbm < -25.0f) {
        printf("ALARM: LOW_RX_POWER\n");
        m->alarm = 1;
    }
    if (m->laser_bias_ma > 90.0f) {
        printf("ALARM: HIGH_BIAS_CURRENT\n");
        m->alarm = 1;
    }
    if (m->supply_voltage_v < 3.0f) {
        printf("ALARM: LOW_SUPPLY_VOLTAGE\n");
        m->alarm = 1;
    }

    if (!m->alarm) printf("Alarm status: CLEAR\n");
}

void optical_print_status(const OpticalModule *m) {
    printf("\n--- Optical Module Status ---\n");
    printf("Laser          : %s\n", m->laser_enabled ? "ON" : "OFF");
    printf("Tx Power       : %.2f dBm\n", m->tx_power_dbm);
    printf("Rx Power       : %.2f dBm\n", m->rx_power_dbm);
    printf("Temperature    : %.2f C\n", m->temperature_c);
    printf("Laser Bias     : %.2f mA\n", m->laser_bias_ma);
    printf("Supply Voltage : %.2f V\n", m->supply_voltage_v);
    printf("Alarm          : %s\n\n", m->alarm ? "ACTIVE" : "CLEAR");
}
