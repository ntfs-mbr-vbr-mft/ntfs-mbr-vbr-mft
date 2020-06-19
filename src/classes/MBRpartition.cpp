#include <algorithm>
#include "MBRpartition.h"

MBRpartition::MBRpartition() {

}

MBRpartition::MBRpartition(unsigned char partition[16]) {
    partition_type = partition[4];
    if (partition_type) {
        status = partition[0];
        start_head = partition[1];
        start_sector = partition[2]&63;
        start_cylinder = ((partition[2] & 192) << 2) + (unsigned int)partition[3];
        end_head = partition[5];
        end_sector = partition[6]&63;
        end_cylinder = ((partition[6] & 192) << 2) + (unsigned int)partition[7];
        start_sector_lba = (partition[11] << 24) + (partition[10] << 16) + (partition[9] << 8) + partition[8];
        total_sectors =  (partition[15] << 24) + (partition[14] << 16) + (partition[13] << 8) + partition[12];
    }
}

int MBRpartition::getStartingSector() {
    return start_sector_lba;
}