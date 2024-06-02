#include "get_next_line.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open the file");
        return 1;
    }
	
    int i = 0;
    while (1)
    {
		printf("[%d]: %s\n", i, line = get_next_line(fd));
        free(line);
        i++;
        if (!line)
        	break;
    }

    // while ((line = get_next_line(fd)) != NULL) {
    //     printf("%s", line);  // 行を出力
    //     free(line);          // メモリ解放
    // }
    close(fd);  // ファイルディスクリプタを閉じる
    return 0;
}



