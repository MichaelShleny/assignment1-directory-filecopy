#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    char user_Input[10]; 
    char directoryN[100]; 
    char newDirectory[100]; 

    while (1) {
        printf("\nSelect the option(s) appropriate by entering the number:\n");
        printf("Enter 1 for creating a directory\n");
        printf("Enter 2 for removing directory\n");
        printf("Enter 3 for printing working directory\n");
        printf("Enter 4 for changing working directory\n");
        printf("Enter 5 for reading the contents of directory\n");
        printf("Enter 6 for closing the current directory\n");
        printf("Enter q to exit the program\n");

        printf("\nEnter a number: "); 
        //scans user input
        scanf("%s", user_Input);
 
        if (user_Input[0] == '1') {
            // Getting dir from the user 
            printf("Enter the Directory name you want to create: ");
            scanf("%s", newDirectory);

            printf("Directory is Created Successfully.");
        }

        else if (user_Input[0] == '2') {
        // Get dir from input/ user
        printf("Enter directory name you want to remove: ");
        scanf("%s", directoryN);

        // Removing dir
        if (rmdir(directoryN) != 0) {
            printf("Error. Make sure directory exists %s: %s\n", directoryN, strerror(errno));
        }
        else{
             printf("Directory is removed Successfully");
        }
    }

        else if (user_Input[0] == '3') {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current Working Directory is: %s\n", cwd);
        } else {
            perror("Unable to pull up the current working directory due to an error.");
        }
    }

    else if (user_Input[0] == '4') {
            //one lvl up 
            chdir("..");
            // Get dir from input/ user
            char cwd[PATH_MAX];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                
                printf("Directory Changed Successfully. \n");
                printf("Working directory After Operation: %s\n", cwd);
            } else {
                perror("Error. Unable to move up one directory");
            }
        }

         else if (user_Input[0] == '5') {
        // Open current directory
        dir = opendir(".");
        if (dir == NULL) {
            printf("Error opening current directory: %s\n", strerror(errno));
        } else {
            // Read entries in directory
            while ((entry = readdir(dir)) != NULL) {
                printf("%s\n", entry->d_name);
            }

            // Close directory
            closedir(dir);
        }
    }
         else if (user_Input[0] == '6') {
        // Close directory
        closedir(dir);
    } else if (user_Input[0] == 'q') {
        // Quit program
        printf("Directory Closed Successfully\n");
        break;
    } else {
        // Invalid input
        printf("Invalid selection\n");
    }
}
return 0;
}