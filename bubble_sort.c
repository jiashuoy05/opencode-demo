#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 氣泡排序法 - 一種簡單的排序演算法
// 時間複雜度：O(n²)
// 空間複雜度：O(1)

// 函數：交換兩個整數的值
// 參數：a - 第一個整數指標，b - 第二個整數指標
// 返回值：無
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 函數：基礎氣泡排序 - 升序排列
// 參數：arr - 陣列指標，n - 陣列大小
// 返回值：無
// 說明：逐次比較相鄰的元素，如果順序錯誤則交換
void bubbleSort(int* arr, int n) {
    // 外層迴圈：控制排序的輪次
    // 最多需要 n-1 輪就能完全排序
    for (int i = 0; i < n - 1; i++) {
        // 內層迴圈：每一輪中比較相鄰的元素
        // 注意：每一輪後，最大的元素會被推到陣列末尾
        // 因此可以減少比較次數 (n - i - 1)
        for (int j = 0; j < n - i - 1; j++) {
            // 如果左邊的元素大於右邊的元素，則交換
            // 這樣可以將較大的元素逐步向右移動
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 函數：優化的氣泡排序 - 升序排列
// 參數：arr - 陣列指標，n - 陣列大小
// 返回值：無
// 說明：如果在某一輪中沒有進行任何交換，表示陣列已排序完成，可提前結束
void bubbleSortOptimized(int* arr, int n) {
    // 外層迴圈：控制排序的輪次
    for (int i = 0; i < n - 1; i++) {
        // 標記：用於檢測本輪是否有進行交換
        int swapped = 0;

        // 內層迴圈：每一輪中比較相鄰的元素
        for (int j = 0; j < n - i - 1; j++) {
            // 如果左邊的元素大於右邊的元素，則交換
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                // 標記表示已進行交換
                swapped = 1;
            }
        }

        // 如果本輪沒有進行任何交換，表示陣列已完全排序
        // 無需再繼續執行後續輪次，可直接結束排序
        if (!swapped) {
            break;
        }
    }
}

// 函數：顯示陣列內容
// 參數：arr - 陣列指標，n - 陣列大小
// 返回值：無
void displayArray(int* arr, int n) {
    printf("陣列內容：[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// 函數：複製陣列
// 參數：source - 來源陣列指標，dest - 目的陣列指標，n - 陣列大小
// 返回值：無
void copyArray(int* source, int* dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// 主程式：測試氣泡排序法
int main() {
    // 定義測試資料的大小
    int size = 8;

    // 建立第一個陣列用於測試基礎版本
    // 初始化的陣列包含未排序的整數
    int arr1[] = {64, 34, 25, 12, 22, 11, 90, 88};

    // 建立第二個陣列用於測試優化版本
    // 使用相同的資料以便進行比較
    int arr2[] = {64, 34, 25, 12, 22, 11, 90, 88};

    printf("========== 氣泡排序法演示 ==========\n\n");

    // ===== 測試 1：基礎氣泡排序 =====
    printf("【測試 1：基礎氣泡排序】\n");
    printf("排序前：");
    displayArray(arr1, size);

    // 呼叫基礎版本的氣泡排序
    bubbleSort(arr1, size);

    printf("排序後：");
    displayArray(arr1, size);
    printf("\n");

    // ===== 測試 2：優化版氣泡排序 =====
    printf("【測試 2：優化版氣泡排序】\n");
    printf("排序前：");
    displayArray(arr2, size);

    // 呼叫優化版本的氣泡排序
    bubbleSortOptimized(arr2, size);

    printf("排序後：");
    displayArray(arr2, size);
    printf("\n");

    // ===== 測試 3：邊界情況 - 已排序的陣列 =====
    printf("【測試 3：已排序的陣列】\n");
    int arr3[] = {1, 2, 3, 4, 5};
    printf("排序前：");
    displayArray(arr3, 5);

    // 優化版本應該立即完成，因為陣列已排序
    bubbleSortOptimized(arr3, 5);

    printf("排序後：");
    displayArray(arr3, 5);
    printf("\n");

    // ===== 測試 4：邊界情況 - 反序陣列 =====
    printf("【測試 4：反序陣列】\n");
    int arr4[] = {5, 4, 3, 2, 1};
    printf("排序前：");
    displayArray(arr4, 5);

    // 需要最多次數的交換
    bubbleSort(arr4, 5);

    printf("排序後：");
    displayArray(arr4, 5);
    printf("\n");

    // ===== 測試 5：邊界情況 - 單一元素 =====
    printf("【測試 5：單一元素陣列】\n");
    int arr5[] = {42};
    printf("排序前：");
    displayArray(arr5, 1);

    bubbleSort(arr5, 1);

    printf("排序後：");
    displayArray(arr5, 1);
    printf("\n");

    // ===== 測試 6：邊界情況 - 含有重複元素 =====
    printf("【測試 6：含有重複元素的陣列】\n");
    int arr6[] = {5, 2, 5, 2, 1, 5, 3};
    printf("排序前：");
    displayArray(arr6, 7);

    bubbleSort(arr6, 7);

    printf("排序後：");
    displayArray(arr6, 7);
    printf("\n");

    // ===== 測試 7：邊界情況 - 含有負數 =====
    printf("【測試 7：含有負數的陣列】\n");
    int arr7[] = {-3, 5, -1, 2, -4, 0, 3};
    printf("排序前：");
    displayArray(arr7, 7);

    bubbleSort(arr7, 7);

    printf("排序後：");
    displayArray(arr7, 7);
    printf("\n");

    printf("========== 測試完成 ==========\n");

    return 0;
}
