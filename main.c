#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

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
    time1 = localtime(&stat1.st_mtime);
}

// 파일 2의 시간 정보를 가져오는 함수 작성
void filetime2()
{
    time2 = localtime(&stat2.st_mtime);
}

// 두 개의 파일 크기를 비교하는 함수 작성
void sizecmp()
{
    struct stat buf1, buf2;
    int size_buf1, size_buf2;

    stat("text1", &buf1);
    stat("text2", &buf2);

    size_buf1 = (int)buf1.st_size;
    size_buf2 = (int)buf2.st_size;

    if (size_buf1 > size_buf2)
    {
        printf("text1 is bigger\n");
    }
    else if (size_buf1 < size_buf2)
    {
        printf("text2 is bigger\n");
    }
    else
    {
        printf("sizes are equal\n");
    }
}

// 두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp()
{
    struct stat buf1, buf2;
    int blocks_buf1, blocks_buf2;

    stat("text1", &buf1);
    stat("text2", &buf2);

    blocks_buf1 = (int)buf1.st_blocks;
    blocks_buf2 = (int)buf2.st_blocks;

    if (blocks_buf1 > blocks_buf2)
    {
        printf("text1 uses more blocks\n");
    }
    else if (blocks_buf1 < blocks_buf2)
    {
        printf("text2 uses more blocks\n");
    }
    else
    {
        printf("blocks are equal\n");
    }
}

// 두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp()
{
}

// 두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp()
{
}
