#include <iostream>
#include <fstream>
#include <stdint.h>
#include <sys/types.h>
#include "classes/arguments.h"
#include "classes/MBR.h"
#include "classes/MBRpartition.h"
#include "classes/NTFS.h"

using namespace std;


MBRpartition chooseNTFSPartition(MBR mbr);

int main (int argc, char * argv[]) {
    arguments args = arguments(argc, argv);
    if (!args.valid) {
        printf("%s", args.error_message);
        return 1;
    } else {
        MBR mbr = MBR(args.device_file);
        MBRpartition c = chooseNTFSPartition(mbr);
        NTFS ntfs = NTFS(args.device_file, c.start_sector_lba, c.total_sectors);
        return 0;
    }
}

MBRpartition chooseNTFSPartition(MBR mbr) {
    MBRpartition ntfs_partitions[4];
    int num_ntfs_partitions = 0;
    for (int i = 0; i < 4; i++) {
        if (mbr.partitions[i].partition_type == 7) {
            ntfs_partitions[num_ntfs_partitions] = mbr.partitions[i];
            num_ntfs_partitions++;
        }
    }

    if (num_ntfs_partitions == 0) {
        printf("no ntfs partitions found\n");
        return 0;
    } else {
        printf("found %u ntfs partition(s)\n", num_ntfs_partitions);
        int i;
        bool ask = true;
        while (ask) {
            printf("choose number between [0, %u]: ", num_ntfs_partitions - 1);
            cin >> i;
            if (i < num_ntfs_partitions && i >= 0) {
                ask = false;
            }
        }
        return ntfs_partitions[i];
    }
}