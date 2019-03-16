#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define GPIO49_PATH "/sys/class/gpio/gpio49"

void writeLED(char filename[], char value[]);
void removeTrigger();

int main(int argc, char* argv[]) {
    if (argc!=2){
        printf("Usage is blinky and one of:\n");
        printf("   on, off, flash or status\n");
        printf(" e.g. blinky flash\n");
        return 2;
    }
    printf("Starting the blinky program\n");
    printf("The current LED Path is: " GPIO49_PATH "\n");
    // select whether command is on, off, flash or status
    if (strcmp(argv[1],"on")==0){
        printf("Turning the LED on\n");
        writeLED("/value", "1");
    }
    else if (strcmp(argv[1],"off")==0){
        printf("Turning the LED off\n");
        writeLED("/value", "0");
    }
    else if (strcmp(argv[1],"flash")==0){
        printf("Flashing the LED\n");
        writeLED("/value", "1");
        sleep(1);
        writeLED("/value", "0");
        sleep(1);
        writeLED("/value", "1");
        sleep(1);
        writeLED("/value", "0");
        sleep(1);
        writeLED("/value", "1");
        sleep(1);
        writeLED("/value", "0");
        sleep(1);
    }
    else if (strcmp(argv[1], "status")==0){
        FILE* fp;
        char fullFileName[100];
        char line[80];
        sprintf(fullFileName, GPIO49_PATH "/trigger");
        fp = fopen(fullFileName, "rt");
        while (fgets(line, 80,fp) != NULL) {
            printf("%s", line);
        }
        fclose(fp);
    }
    else{
        printf("Invalid command!\n");
    }
    printf("Finished the blinky program\n");
    return 0;
}

void writeLED(char filename[], char value[]) {
    FILE* fp;
    char fullFileName[100];
    sprintf(fullFileName, GPIO49_PATH "%s", filename);
    fp = fopen(fullFileName, "w+");
    fprintf(fp, "%s", value);
    fclose(fp);
}

/*
void removeTrigger(){
    writeLED("/trigger", "none");
}
*/