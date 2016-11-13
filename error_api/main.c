#include "error_api.h"

int main(int argc, char *argv[])
{
    setprogname("main");
    eprintf("can't open %s:", "mapan");
    return 0;
}
