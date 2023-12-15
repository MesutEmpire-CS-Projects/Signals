
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/resource.h>


int main() {
    DIR* dir;
    struct dirent* entry;

    dir = opendir("/proc");

    if (dir == NULL) {
        perror("Error opening /proc directory");
        return 1;
    }

    printf("%-10s %-15s %-15s\n", "PID", "Priority", "Parent PID");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
            int pid = atoi(entry->d_name);

            int priority = getpriority(PRIO_PROCESS, pid);
            int parent_pid = getppid();

            printf("%-10d %-15d %-15d\n", pid, priority, parent_pid);
        }
    }

    closedir(dir);
    return 0;
}
