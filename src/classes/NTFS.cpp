#include <fcntl.h>
#include <unistd.h>
#include "VBR.h"
#include "NTFS.h"

NTFS::NTFS(char *device_file, int ss, int ts) {
    starting_sector = ss;
    total_sectors = ts;

    int fd = open(device_file, O_RDONLY);
    unsigned char buf[512];
    lseek(fd, starting_sector*512, SEEK_SET);
    read(fd, buf, 512);

    vbr = VBR(buf);

    close(fd);
}
