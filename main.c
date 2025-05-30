﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main()
{
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

// 파일 1의 정보를 가져오는 함수 작성
void filestat1()
{
    stat("text1", &stat1);
}

// 파일 2의 정보를 가져오는 함수 작성
void filestat2()
{
    stat("text2", &stat2);
}

// 파일 1의 시간 정보를 가져오는 함수 작성
void filetime1()
{
    time1 = (struct tm *)malloc(sizeof(struct tm));
    *time1 = *localtime(&stat1.st_mtime);
}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2()
{
    time2 = (struct tm *)malloc(sizeof(struct tm));
    *time2 = *localtime(&stat2.st_mtime);
}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp()
{
    int size_stat1, size_stat2;

    size_stat1 = (int)stat1.st_size;
    size_stat2 = (int)stat2.st_size;

    printf("size compare\n");

    if (size_stat1 > size_stat2)
    {
        printf("text1 is bigger\n\n");
    }
    else if (size_stat1 < size_stat2)
    {
        printf("text2 is bigger\n\n");
    }
    else
    {
        printf("sizes are equal\n\n");
    }
}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp()
{
    int blocks_stat1, blocks_stat2;

    blocks_stat1 = (int)stat1.st_blocks;
    blocks_stat2 = (int)stat2.st_blocks;

    printf("block compare\n");

    if (blocks_stat1 > blocks_stat2)
    {
        printf("text1 is bigger\n\n");
    }
    else if (blocks_stat1 < blocks_stat2)
    {
        printf("text2 is bigger\n\n");
    }
    else
    {
        printf("sizes are equal\n\n");
    }
}

// 두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp()
{
    printf("date compare\n");
    if (time1->tm_mon == time2->tm_mon)
    {
        if (time1->tm_mday < time2->tm_mday)
            printf("text1 is early\n\n");
        else if (time1->tm_mday > time2->tm_mday)
            printf("text2 is early\n\n");
        else
            printf("same date\n\n");
    }
    else if (time1->tm_mon < time2->tm_mon)
        printf("text1 is early\n\n");
    else
        printf("text2 is early\n\n");
}

// 두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp()
{
    printf("time compare\n");
    if (time1->tm_hour == time2->tm_hour)
    {
        if (time1->tm_min < time2->tm_min)
            printf("text1 is early\n\n");
        else if (time1->tm_min > time2->tm_min)
            printf("text2 is early\n\n");
        else
            printf("same time\n\n");
    }
    else if (time1->tm_hour < time2->tm_hour)
        printf("text1 is early\n\n");
    else
        printf("text2 is early\n\n");
}