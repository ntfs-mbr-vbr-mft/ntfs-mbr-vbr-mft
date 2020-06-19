#include "MBRpartition.h"
#ifndef NTFS_MBR_VBR_MFT_MBR_H
#define NTFS_MBR_VBR_MFT_MBR_H


class MBR {
public:
    MBRpartition partitions[4];
    MBR(char *device_file);
    void instantiatePartition(unsigned char mbr[512], int partitionNumber);
};


#endif //NTFS_MBR_VBR_MFT_MBR_H
