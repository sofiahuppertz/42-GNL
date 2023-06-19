#include "get_next_line.h"
#include  <fcntl.h>
#include <stdio.h>



//tests for the get_next_line function.
int	main(int argc, char *argv[])
{
    int		fd;
    char	*line;
    int		i;
    
    if(argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);

    i = 0;
    while (i < 5)
    {
        line = get_next_line(fd);
        printf("%s\n", line);
        free(line);
        i++;
    }
    close(fd);
    return (0);
}