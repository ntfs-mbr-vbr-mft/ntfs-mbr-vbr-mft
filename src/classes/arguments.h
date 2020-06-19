#ifndef NTFS_MBR_VBR_MFT_ARGUMENT_H
#define NTFS_MBR_VBR_MFT_ARGUMENT_H


class arguments {
private:
public:
    char *device_file;
    bool valid;
    const char *error_message;
    arguments(int argc, char * argv[]);
};


#endif //NTFS_MBR_VBR_MFT_ARGUMENT_H
