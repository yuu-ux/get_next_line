#include "get_next_line.h"

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open the file");
		return (1);
	}
	i = 0;
	while (1)
	{
		printf("[%d]: %s", i, line = get_next_line(fd));
		free(line);
		i++;
		if (!line)
			break ;
	}
	close(fd); // ファイルディスクリプタを閉じる
	return (0);
}
