#include "error_api.h"

int main(int argc, char *argv[])
{
    setprogname("test");
    eprintf("can't open %s:", "file");
    return 0;
}
