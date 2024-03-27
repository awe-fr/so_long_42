#include "../headers/major.h"

int map_parsing(char *map_path)
{
    if (open(map_path, O_RDONLY) == -1)
        bad_path();
    
}