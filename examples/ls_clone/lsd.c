#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

// Source: https://github.com/CodeMyst/OS2/blob/main/vezbe/04/lsd.c

typedef struct options {
	// sort alphabetically?
	int sort;
	// list of characters to filter with
	// shows only files that start with one of the listed characters
	char* filter;
	// shows only files that are modified after this year
	int year;
	// shows only files that are modified in this month
	int month;
} options;

options opts;

// filter based on first character
int filter(const struct dirent* dir) {
	if (opts.filter == NULL) return 1;

	for (int i = 0; i < strlen(opts.filter); i++) {
		if (dir->d_name[0] == opts.filter[i]) return 1;
	}

	return 0;
}

int list(char* path) {
	printf("%s:\n", path);

	struct dirent** namelist;

	int (*compare)(const struct dirent**, const struct dirent**) = NULL;

	if (opts.sort) {
		compare = alphasort;
	}

	int n = scandir(path, &namelist, &filter, compare);
	if (n == -1) {
		perror("scandir");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		// get child path
		char childPath[256];
		strcpy(childPath, path);
		strcat(childPath, "/");
		strcat(childPath, namelist[i]->d_name);

		// get rid of extra /
		char childResolvedPath[256];
		realpath(childPath, childResolvedPath);

		// get entry stats
		struct stat stats;
		if (stat(childResolvedPath, &stats) == -1) {
			int err = errno;
			printf("%s\n", strerror(err));
			return 1;
		}

		struct tm* time = localtime(&stats.st_ctime);

		// show only files modified after the provided year
		if (opts.year != -1 && 1900 + time->tm_year <= opts.year) continue;

		// show only files modified in the provided month
		if (opts.month != -1 && opts.month != time->tm_mon) continue;

		printf("  %d-%02d-%02d %02d:%02d %s\n", 1900 + time->tm_year, time->tm_mon + 1, time->tm_mday, time->tm_hour, time->tm_min, namelist[i]->d_name);
		free(namelist[i]);
	}

	free(namelist);

	return 0;
}

void parseOptions(int argc, char** argv) {
	opts.sort = 0;
	opts.filter = NULL;
	opts.year = -1;
	opts.month = -1;

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (strcmp(argv[i], "--sort") == 0) {
				opts.sort = 1;
			} else if (strncmp("--S", argv[i], 3) == 0) {
				int n = strlen(argv[i]) - 3;
				char* buff = malloc(n * sizeof(char));
				strncpy(buff, argv[i] + 3, n);

				opts.filter = buff;
			} else if (strncmp("--p", argv[i], 3) == 0) {
				int n = strlen(argv[i]) - 3;
				char* buff = malloc(n * sizeof(char));
				strncpy(buff, argv[i] + 3, n);

				opts.year = atoi(buff);

				free(buff);
			} else {
				if (strcmp(argv[i], "--januar") == 0) {
					opts.month = 0;
				} else if (strcmp(argv[i], "--februar") == 0) {
					opts.month = 1;
				} else if (strcmp(argv[i], "--mart") == 0) {
					opts.month = 2;
				} else if (strcmp(argv[i], "--april") == 0) {
					opts.month = 3;
				} else if (strcmp(argv[i], "--maj") == 0) {
					opts.month = 4;
				} else if (strcmp(argv[i], "--jun") == 0) {
					opts.month = 5;
				} else if (strcmp(argv[i], "--jul") == 0) {
					opts.month = 6;
				} else if (strcmp(argv[i], "--avgust") == 0) {
					opts.month = 7;
				} else if (strcmp(argv[i], "--septembar") == 0) {
					opts.month = 8;
				} else if (strcmp(argv[i], "--oktobar") == 0) {
					opts.month = 9;
				} else if (strcmp(argv[i], "--novembar") == 0) {
					opts.month = 10;
				} else if (strcmp(argv[i], "--decembar") == 0) {
					opts.month = 11;
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	parseOptions(argc, argv);

	for (int i = 1; i < argc; i++) {
		// ignore options
		if (argv[i][0] != '-') {
			int res = list(argv[i]);
			if (res != 0) return res;
		}
	}

	if (opts.filter != NULL) free(opts.filter);

	return 0;
}

