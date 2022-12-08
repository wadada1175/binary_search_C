#include <stdio.h>
#include <time.h>

#define SIZE 60
/* 探索対象の配列 -- 60個 */
int data[SIZE] = {101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
                  151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
                  199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                  263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
                  317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                  383, 389, 397, 401, 409, 419, 421, 431, 433, 439};

int main(void)
{
    int low, mid, high;//配列の範囲を狭めるための添字
    int target = 433;//探索する値(固定)

    high = SIZE;//配列の右端
    low = 0;//配列の左端

    /* 値が見つかるまで繰り返す */
    clock_t begin = clock();//時間計測開始
    while (low <= high) {
        mid = (low + high) / 2;
        /* 値が見つかればループを抜ける */
        if (data[mid] == target) {
            break;
            /* 値の大小を調べて探索範囲を狭める */
        } else if (data[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    clock_t end = clock();//時間計測終了

    printf("値 %d は配列の %d 番目に見つかりました。\n",
           target, mid);
    printf( "処理時間は%fs\n", (double)(end - begin) / CLOCKS_PER_SEC );
    return 0;
}