#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int search_recursive(char *path, int n)
{
	DIR *directory_to_search = opendir(path);
	struct dirent *file_val;

	while ((file_val = readdir(directory_to_search)) != NULL)
	{
		struct stat path_stat;
		char *path_ = malloc(sizeof(path) + sizeof('/') + sizeof(file_val->d_name));
		sprintf(path_, "%s/%s", path, file_val->d_name);
		stat(path_, &path_stat);
		if (S_ISREG(path_stat.st_mode))
		{
			fprintf(stdout, "%s : %d bytes\n", file_val->d_name, path_stat.st_size);
		}
		else if (S_ISDIR(path_stat.st_mode) && strcmp(file_val->d_name, "..") && strcmp(file_val->d_name, "."))
		{
			pid_t child_pid = fork(), wpid;
			int *val;
			if (child_pid == 0)
			{
				search_recursive(path_, n + 1);
				return 0;
			}
			else
			{
				while ((wpid = wait(val)) > 0)
					;
			}
		}
		free(path_);
	}
	return 0;
}

int main(int argc, char *argv[])
{

	if (argc <= 1)
	{
		fprintf(stdout, "Invalid command.");
		return 1;
	}

	search_recursive(argv[1], 0);

	return 0;
}