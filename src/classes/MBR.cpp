#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include "MBR.h"

using namespace std;

MBR::MBR(char *device_file) {
    int fd = open(device_file, O_RDONLY);
    unsigned char mbr[512];
    read(fd, mbr, 512);
    close(fd);

    for (int i = 0; i < 4; i++) {
        instantiatePartition(mbr, i);
    }
}

void MBR::instantiatePartition(unsigned char mbr[512], int partitionNumber) {
    unsigned char partition[16];
    int start = 446 + 16 * partitionNumber;
    copy(mbr + start, mbr + start + 16, partition);
    partitions[partitionNumber] = MBRpartition(partition);
}