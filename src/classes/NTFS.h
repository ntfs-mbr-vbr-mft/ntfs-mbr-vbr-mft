#include "VBR.h"
#ifndef NTFS_MBR_VBR_MFT_NTFS_H
#define NTFS_MBR_VBR_MFT_NTFS_H


class NTFS {
private:
    int starting_sector;
    int total_sectors;
    VBR vbr;
public:
    NTFS(char *device_file, int starting_sector, int total_sectors);
};


#endif //NTFS_MBR_VBR_MFT_NTFS_H
