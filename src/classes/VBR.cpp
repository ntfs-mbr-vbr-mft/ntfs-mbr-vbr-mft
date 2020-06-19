#include "VBR.h"
#include <algorithm>
#include <string>
#include <stdio.h>

VBR::VBR() {

}

VBR::VBR(unsigned char buf[512]) {
    unsigned char OEM_ID[] = {0, 0, 0, 78, 84, 70, 83, 32, 32, 32, 32};

    bool valid = true;
    for (int i = 3; i < 11; i++) {
        if (buf[i] != OEM_ID[i]) {
            valid = false;
        }
    }

    if (valid) {
        printf("Reached beginning of VBR for NTFS\n");
    } else {
        printf("VBR does not have matching OEM_ID \"NTFS    \"\n");
    }
}
