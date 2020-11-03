#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
int main(int argc, char *argv[]){
    int c;
    float val;
    int do_all, do_help, do_version, do_short, do_create, do_value, do_list;
    char *file, *arr;
    struct option longopts[] = {
        {"all", no_argument, 0, 'a'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"short", no_argument, 0, 's'},
        {"create", required_argument, 0, 'c'},
        {"value", required_argument, 0, 'V'},
        {"list", required_argument, 0, 'l'},
        {0, 0, 0, 0}
    };

    while ((c = getopt_long(argc, argv, "ahvsc:V:l:o::", longopts, NULL)) != -1){
        switch (c){
            case 'a':
                do_all = 1;
                break;
            case 'h':
                do_help = 1;
                break;
            case 'v':
                do_version = 1;
                break;
            case 's':
                do_short = 1;
                break;
            case 'c':
                do_create = 1;
                file = optarg;
                break;
            case 'V':
                do_value = 1;
                val = atof(optarg);
                break;
            case 'l':
                do_list = 1;
                arr = optarg;
                break;
            case '?':
                break;
            default:
                break;

        }
    }
    if (do_all == 1)
        printf("Arg: All\n");
    if (do_help == 1)
        printf("Arg: Help\n");
    if (do_version == 1)
        printf("Arg: Version\n");
    if (do_short == 1)
        printf("Arg: Short\n");
    if (do_create == 1)
        printf("Arg: Create file - %s\n", file);
    if (do_value == 1)
        printf("Arg: Value = %f\n", val);
    if (do_list == 1){
        printf("Arg: Array = [");
        arr = strtok(arr, ",");
        while (1){
            printf("%f", atof(arr));
            arr = strtok(NULL, ",");
            if (arr != NULL)
                printf(", ");
            else
                break;
        }
        printf("]\n");
    }
}
