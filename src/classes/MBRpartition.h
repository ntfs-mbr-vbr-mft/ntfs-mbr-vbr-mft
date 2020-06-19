#ifndef NTFS_MBR_VBR_MFT_MBR_PARTITION_H
#define NTFS_MBR_VBR_MFT_MBR_PARTITION_H


class MBRpartition {
public:
    // all values are in decimal format
    unsigned int status;
    unsigned int start_head;
    unsigned int start_sector;
    unsigned int start_cylinder;
    unsigned int partition_type;
    unsigned int end_head;
    unsigned int end_sector;
    unsigned int end_cylinder;
    unsigned int start_sector_lba;
    unsigned int total_sectors;
    MBRpartition();
    MBRpartition(unsigned char partition[16]);
    int getStartingSector();
};


#endif //NTFS_MBR_VBR_MFT_MBR_PARTITION_H
