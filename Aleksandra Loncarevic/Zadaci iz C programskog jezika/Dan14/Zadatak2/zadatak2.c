#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_TEXT_LEN 80

typedef struct sTime {
    int hours, minutes;
} Time;

typedef struct sActivity {
    Time startTime, endTime;
    char description[DEFAULT_TEXT_LEN + 1];
} Activity;

typedef struct sListElement {
    Activity*pActivity;
    struct sListElement*next;
} ListElement;

ListElement*insert(ListElement*l, Activity*act);
Activity*readActivity(FILE*f);
ListElement*removeOverlappedActivities(ListElement*aList, FILE*output);
void printActivity(Activity*actv, FILE*f);
void printActivityList(ListElement*aList, FILE*f);
int isOverlaped(Activity*a1, Activity*a2);
int isTimeBeforeOrEqual(Time t1, Time t2);
int isActivityBeforeOrEqual(Activity*a1, Activity*t2);
int isTimeBefore (Time t1, Time t2);
int isActivityBefore(Activity*a1, Activity*a2);
void dealocate(ListElement*actv);

int main() {
    ListElement*activityList = NULL;
    Activity*currActivity;
    int s = 0;
    FILE*scheduleFile = fopen("kalendar.txt", "r");
    FILE*overlapingFile = fopen("preklapanja.txt", "w");
    if (scheduleFile == NULL) {
        fprintf(stderr, "Cannot open input file.\n");
        s = 1;
        goto END;
    }
    if (overlapingFile == NULL) {
        fprintf(stderr, "Cannot open output file.\n");
        s = 1;
        goto END;
    }
    while ((currActivity = readActivity(scheduleFile)) != NULL) {
        activityList = insert(activityList, currActivity);
    }
    printActivityList(activityList, stdout);
    removeOverlappedActivities(activityList, overlapingFile);
    printActivityList(activityList, stdout);
    END: if (scheduleFile)  fclose(scheduleFile);
    if (overlapingFile)     fclose(overlapingFile);
    dealocate(activityList);
    return s;
}

Activity*readActivity(FILE*f) {
    int numOfData;
    Activity*actv = (Activity*)malloc(sizeof(Activity));
    if(!actv) {
        printf("Error in memory allocation");
        exit(2);
    }
    numOfData = fscanf(f, "%d:%d-%d:%d ",&actv->startTime.hours, &actv->startTime.minutes,&actv->endTime.hours,   &actv->endTime.minutes);
    if (numOfData == EOF) {
        free(actv); //nepotrebno smo alocirali
        return NULL;
    }
    fgets(actv->description, DEFAULT_TEXT_LEN, f);
    return actv;
}

ListElement*insert(ListElement*lstFirst, Activity*actv) {
    ListElement*newActv = (ListElement*) malloc(sizeof(ListElement));
    newActv->pActivity = actv;
    ListElement*curr = lstFirst,*prev = NULL;
    while (curr) {
        if (isActivityBeforeOrEqual(curr->pActivity, actv))
            prev = curr, curr = curr->next;
        else break; // pronasli smo mesto!
    }
    if (!prev) lstFirst = newActv; //prvi element
    else prev->next = newActv;
    newActv->next = curr; // ulancavanmo u postojecu
    return lstFirst; // vracamo glavu liste
}

ListElement*removeOverlappedActivities(ListElement*aList, FILE*output) {
    ListElement*pi = aList,*pj = NULL,*pjPrev,*old;
    while (pi) {
        pj = pi->next;
        while (pj) {
            if (isOverlaped(pi->pActivity, pj->pActivity)) {
                printActivity(pj->pActivity, output);
                pi->next = pj->next;
                free(pj->pActivity);
                free(pj);
                pj = pi->next;
            } else {
                pj = pj->next;
            }
        }
        pi = pi->next;
    }
    return aList;
}

int isOverlaped(Activity*a1, Activity*a2) {
    return     ( isTimeBeforeOrEqual(a1->startTime, a2->startTime)
                && isTimeBefore(a2->startTime, a1->endTime) )
                || ( isTimeBeforeOrEqual(a2->startTime, a1->startTime)
                && isTimeBefore(a1->startTime, a2->endTime) );
}

int isTimeBeforeOrEqual(Time t1, Time t2) {
    return (t1.hours < t2.hours) ||
           (t1.hours == t2.hours && t1.minutes <= t2.minutes);
}

int isTimeBefore(Time t1, Time t2) {
    return (t1.hours < t2.hours) ||
           (t1.hours == t2.hours && t1.minutes < t2.minutes);
}

int isActivityBeforeOrEqual(Activity*a1, Activity*a2) {
    return isTimeBeforeOrEqual(a1->startTime, a2->startTime);
}

void printActivity(Activity*actv, FILE*f) {
    fprintf(f, "%d:%d-%d:%d ", actv->startTime.hours, actv->startTime.minutes,
                               actv->endTime.hours, actv->endTime.minutes);
    fputs(actv->description, f);
    fprintf(f,"\n");
}

void printActivityList(ListElement*aList, FILE*f) {
    ListElement*p = aList;
    while (p) {
        printActivity(p->pActivity, f);
        p = p->next;
    }
}

void dealocate(ListElement*actv){
    ListElement*tmp;
    while(actv){
        tmp = actv;
        actv = actv->next;
        /*Obavezno osloboditi i memoriju koju zauzima dinamicki alocirana733162struktura koja predstavlja aktivnost!*/
        free(tmp->pActivity);
        free(tmp);
    }
}
