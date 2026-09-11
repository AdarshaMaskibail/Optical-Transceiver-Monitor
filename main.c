#include <stdio.h>
#include <string.h>
#include "optical_monitor.h"

int main(void) {
    OpticalModule module;
    optical_init(&module);

    printf("=== Optical Transceiver Monitor ===\n");
    printf("Type 'help' for commands.\n");

    char command[64];

    while (1) {
        printf("> ");
        if (!fgets(command, sizeof(command), stdin)) break;
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "status") == 0) {
            optical_print_status(&module);
        } else if (strcmp(command, "laser on") == 0) {
            optical_set_laser(&module, 1);
        } else if (strcmp(command, "laser off") == 0) {
            optical_set_laser(&module, 0);
        } else if (strcmp(command, "alarm") == 0) {
            optical_check_alarms(&module);
            optical_print_status(&module);
        } else if (strcmp(command, "help") == 0) {
            printf("status | laser on | laser off | alarm | help | quit\n");
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command. Type 'help'.\n");
        }
    }

    return 0;
}
