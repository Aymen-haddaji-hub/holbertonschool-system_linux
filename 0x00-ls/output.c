#include "hls.h"

/**
*long_format - 0
*@read: node of arguments
*/
void print_long_format(struct dirent *read)
{
	struct stat fileStat;
	struct group *grp;
	struct passwd *user;
	char time[24];

	_strncpy(time, ctime(&fileStat.st_mtime), 24);
	lstat((*read).d_name, &fileStat);

	printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

	user = getpwuid(fileStat.st_uid);
	grp = getgrgid(fileStat.st_gid);

	printf(" %lu %s %s %li %s %s\n", fileStat.st_nlink, (*user).pw_name,
	(*grp).gr_name, (intmax_t)fileStat.st_size, time, (*read).d_name);
}
/**
*print_1 - 0
*@read: node of arguments
*@op: array of options
*/
void print_one_by_line(char *read, int *op)
{
	if (op[0] == 1)
	{
		printf("%s\n", read);
	}
	else
	{
		printf("%s ", read);
	}
}
