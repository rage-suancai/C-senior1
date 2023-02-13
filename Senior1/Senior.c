#include <stdio.h>

void add(int arr[]);
int findMin(int arr[], int len);

void test1_0(void) {

    //char c = getchar();

    printf("Fuck World");

}

//int a = 10;
void test2_0() {

    /*for (int i = 0; i < 10; ++i) {
        printf("%d", i);
    }
    i += 10;*/

    /*for (int i = 0; i < 10; ++i) {

    }
    for (int i = 0; i < 20;) ++i {

    }*/

    int i;
    for (i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    i += 10;

    /*if(1) {
        int a = 10;
    }
    a = 20;*/

    /*a += 10;
    printf("%d", a;)*/

}

void test3_0(int a, int b) {

    printf("%d", a+b);
    
}
void test3_1() {

    /*int a  = 10, b = 20;
    swap(a, b);
    printf("a = %d, b = %d", a, b);*/

    int arr[] = {4, 3, 8, 2, 1, 7, 5, 6, 9, 0};
    add(arr);
    printf("%d", arr[0]);
    
}
void test3_2(int a) {

    /*a += 10;
    printf("%d\n", a);*/

    static int count = 0;
    printf("函数被调用了: %d 次, a的值为: %d\n", ++count, a);

}
void test3_3() {
    
    /*static int a = 20;
    a += 20;
    printf("%d ", a);*/

    /*int a = 10, b = 20;
    int result = sum(a, b);
    printf("a+b=%d", result);*/

    int arr[] = {1, 4, -9, 2, -4, 7};
    int min = findMin(arr, 6);
    printf("第一个小于0的数是: %d", min);

}

int test4_0(int n) {

    /*printf("Fuck Wolrd");
    test4_0();*/
    
    if (n == 1) return 1;
    return test4_0(n - 1) * n;

}

int fbl(int n){

    // 斐波那契数列解法其三
    if(n <= 1 || n == 2) return 1;
    return fbl(n - 1) + fbl(n - 2);

}
void hanoi(char a, char b, char c, int n) {
    
    // 汉诺塔
    if(n == 0) return;
    hanoi(a, c, b, n-1);
    printf("第%d个圆盘: %c --> %c\n", n, a, c);
    hanoi(b, a, c, n-1);

}
void quickSort(int arr[], int left, int right) {

    // 快速排序
    if(left >= right) return;

    int base = arr[left], l = left, r = right;
    while (l < r) {
        while (l < r && arr[r] >= base) r--;
        arr[l] = arr[r];
        while (l < r && arr[l] <= base) l++;
        arr[r] = arr[l];
    }
    arr[r] = base;
    quickSort(arr, left, r - 1);
    quickSort(arr, r + 1, right);

}

int main() {

    /*int a = 10; test1_0();
    if (a > 20) test1_0();
    switch (a) {
        case 30:
            test1_0();
    }*/

    /*a += 10;
    test2_0();*/

    //test3_0(88, 88);

    //test3_1();

    /*int a = 10;
    test3_2(a);
    test3_2(a);*/

    /*int a = 10;
    test3_2(a);
    test3_2(a);*/

    /*test3_3();
    test3_3();*/
    
    //test3_3();

    //printf("%d", test4_0(3));

    //printf("%d", fbl(20));

    //hanoi('A', 'B', 'C', 3);

    /*int arr[] = {4, 3, 8, 2, 1, 7, 5, 6, 9, 0};
    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }*/

}

void swap(int a, int b) {

    int tmp = a;
    a = b;
    b = tmp;
    
}

void add(int arr[]) {

    arr[0] = 999;

}

int sum(int a, int b) {

    return a + b;

}

int findMin(int arr[], int len) {

    
    for (int i = 0; i < len; ++i) {
        if (arr[i] < 0) return arr[i];
    }
    return 0;

}