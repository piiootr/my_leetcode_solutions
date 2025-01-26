/*
3433
https://leetcode.com/problems/count-mentions-per-user/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
    int *mentions;
    int *user_mentioned;
    int *arr_users_timestamp;
    int i, j;
    int time_stamp, time_stamp_h;
    char **event, **event_h;
    char *event_type;
    char *mentions_string;
    int user_id;

    // sort events in timestamp order
    i = 0;
    while(i < (eventsSize - 1)) {
        event = events[i];
        event_h = events[i + 1];
        time_stamp = (int) strtol(&(event[1][0]), NULL, 10);
        time_stamp_h = (int) strtol(&(event_h[1][0]), NULL, 10);

        if(time_stamp > time_stamp_h) {
            events[i + 1] = event;
            events[i] = event_h;
            if(i > 0) i--;
            else i++;
        } else if(time_stamp == time_stamp_h && event[0][0] == 'M' && event_h[0][0] == 'O') {
            events[i + 1] = event;
            events[i] = event_h;
            if(i > 0) i--;
            else i++;
        } else i++;
    }

    mentions = (int*) malloc(sizeof(int) * numberOfUsers);
    user_mentioned = (int*) malloc(sizeof(int) * numberOfUsers);
    arr_users_timestamp = (int*) malloc(sizeof(int) * numberOfUsers);
    for(i = 0; i < numberOfUsers; i++) arr_users_timestamp[i] = user_mentioned[i] = mentions[i] = 0;
    for(i = 0; i < eventsSize; i++) {
        event = events[i];
        event_type = event[0];
        time_stamp = (int) strtol(&(event[1][0]), NULL, 10);
        mentions_string = event[2];

        if(event_type[0] == 'O') {
            user_id = (int) strtol(mentions_string, NULL, 10);
            arr_users_timestamp[user_id] = time_stamp + 60;
        } else if(event_type[0] == 'M') {
            if(mentions_string[0] == 'A') {
                for(j = 0; j < numberOfUsers; j++) mentions[j]++;
            } else if(mentions_string[0] == 'H') {
                for(j = 0; j < numberOfUsers; j++) {
                    if(arr_users_timestamp[j] <= time_stamp) mentions[j]++;
                };
            } else {
                j = 0;
                while(j < strlen(mentions_string)) {
                    if(mentions_string[j] >= '0' && mentions_string[j] <= '9') {
                        user_id = (int) strtol(&(mentions_string[j]), NULL, 10);

                        mentions[user_id]++;
                        user_mentioned[user_id] = 1;

                        if(user_id > 99) j += 3;
                        else if(user_id > 9) j += 2;
                        else j++;
                    }
                    j++;
                }
                for(j = 0; j < numberOfUsers; j++) user_mentioned[j] = 0;
            }

        } else {
            printf("** TODO: Don't know what happend :-( **\n");
        }
    }

    free(user_mentioned);
    free(arr_users_timestamp);
    *returnSize = numberOfUsers;
    return mentions;
}


int main(int argc, char** argv)
{

    return 0;
}