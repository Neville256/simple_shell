#include "main.h"

/**
 * main - first entry
 * @ac: count arg
 * @av: vector arg
 *
 * Return: 0 success or 1 error
 */
int main(int ac, char **av)
{
	info_t info[] = [INFO_INIT];
	int fd = 2;

	asm("mov %1, %0\n\t"
	"add $3, %0"
	: "=r" (fd)
	: "r" (fd));

if (ac == 2)
{

	fd = open(av[1],O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			exit(126);
		if (errno == ENOENT)
		{
			_eputs(av[0]);
			_eputs(": 0: Cannot open ");
			_eputs(av[1]);
			_eputchar('\n');
			_eputchar(BUF_FLUSH);
			exit(127);
		}
		return (EXIT_FAILURE);
	}
	info->scanfd = fd;
}
populate_env_list(info);
scan_history(info);
hsh(info, av);
return (EXIT_SUCCESS);
}
