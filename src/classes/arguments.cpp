#include "arguments.h"

arguments::arguments(int argc, char * argv[]) {
    if (argc != 2) {
        valid = false;
        error_message = (char *)"example: main /dev/sdd";
    } else {
        device_file = argv[1];
        valid = true;
    }
}