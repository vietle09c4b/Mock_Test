#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TC 1
#if TC == 1
int n =10;
int arr_b[] ={3,8,5};
int arr_a[7][2] = {{1, 2}, {1, 3}, {2, 4}, {4, 6}, {2, 8}, {6, 9}, {7, 10}};
#elif TC == 2
int n =10;
int arr_b[] ={4,9,2,8};
int arr_a[5][2] = {{10, 7}, {3, 6}, {2, 10}, {5, 6}, {10, 8}};
#elif TC == 3
int n =10;
int arr_b[] ={5,3,7,2};
int arr_a[5][2] = {{9,4}, {6,7}, {2,8}, {3,10}, {8,10}};
#elif TC == 4
int n =6;
int arr_b[] ={2,6,5};
int arr_a[4][2] = {{1,5}, {2,5}, {1,4}, {4,6}};
#elif TC == 5
int n =6;
int arr_b[] ={4,3};
int arr_a[5][2] = {{1,6}, {5,1}, {6,4}, {4,3}, {5,3}};

#endif

#define MAX_GROUP 10
int length_b = sizeof(arr_b)/sizeof(arr_b[0]); // Calculate how many elements of array b
int length_a = sizeof (arr_a)/sizeof (arr_a[0][0]); // Calculate how many elements of array a
int row_a = (sizeof (arr_a)/sizeof (arr_a[0][0]))/2; // Calculate how many couples of array a
int Index_F0 =0;
int Index_F1 =0;
int Index_F2 =0;
int Index_F3 =0;
int Index_F4 =0;
int Severity_arr_a;
int Severity_Fx = 0;
int Number_Group = 0;
int Count_Group_Fa = 0;
int Number_Group_Fx =0;
int Disappear_Person = 0;
int Group_Severity[MAX_GROUP];
typedef struct Person{
    int m_Index;
    int m_F;
    int m_Severity;
} st_Person;
int Group = 0;
int main() {

/* Tạo array pointer các phần tử có kiểu dữ liệu struct để lưu trữ thông tin mảng a truyền vào */
    st_Person * ptr_arr_a[row_a][2]; // Declare an array pointer which contains all elements in array a
        for ( int j = 0; j< row_a; j++){
            for ( int k = 0; k< 2; k++){
                ptr_arr_a[j][k] = malloc(sizeof (st_Person)); // Create memory in heap memory
                if (ptr_arr_a[j][k] == NULL){          // Check NULL
                    printf("Not enough memory!");
                    exit(0);
                }
                ptr_arr_a[j][k]->m_Index = arr_a[j][k]; // Assign Index from array a
                printf("%d ",ptr_arr_a[j][k]->m_Index);
            }
        }
    printf("\n");

    // -----------------------------
    /* Đánh F0 cho mảng array pointer vừa tạo F0: m_F = 1;  m_Severity = 10; */
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            for ( int i = 0; i< length_b; i++){
                if(ptr_arr_a[j][k]->m_Index == arr_b[i]){
                    ptr_arr_a[j][k]->m_F = 1; // Assign F0 = 1
                    ptr_arr_a[j][k]->m_Severity = 10;
                    Severity_arr_a = Severity_arr_a + 10; /* Severity tăng lên 10 */
                }
            }
            printf("%d ", ptr_arr_a[j][k]->m_Severity);
        }
    }
    printf("\n");

    /* Tìm số luượng phần tử F0 */
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 1){
                Index_F0 ++; // Calculate number of F0
            }
        }
    }
    /* Khi F0 ở mảng b xuất hiện ở mảng a --> ít nhất có 1 group lây nhiễm*/
    if(Index_F0 != 0){
        Count_Group_Fa ++;
        Number_Group = Number_Group+ 1;
    }
    printf("Index_F0 = %d ",Index_F0);
    printf("\n");
    /* Đánh F1 : tìm hàng chứa F0 (m_F == 1) --> trong hàng đó nếu không là F0 thì chắc chắn là F1
     Nếu là F0 thì bỏ qua. F1: m_F = 2;  m_Severity = 5; */

    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if(ptr_arr_a[j][k]->m_F == 1)
                {
                    for (int m = 0; m< 2; m++){
                        if (ptr_arr_a[j][m]->m_F != 1){
                            ptr_arr_a[j][m]->m_F = 2;
                            ptr_arr_a[j][m]->m_Severity = 5;
                            Severity_arr_a = Severity_arr_a + 5;
                        }
                    }
                }
            }
        }
    printf("\n");


    /* Tìm số lượng phần tử F1 */
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 2){
                Index_F1 ++;
            }
        }
    }
    printf("Index_F1 = %d ",Index_F1);
    // Assign arr_F1_Index[]

    /* Tạo mảng chứa Index F1 */
    int arr_F1_Index [Index_F1];
    int count_1 = 0;
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 2){
                arr_F1_Index[count_1] = ptr_arr_a[j][k]->m_Index;
                count_1 ++;
            }
        }
    }


    // Print arr_F1_Index[]
    printf("\n");
    for ( int i = 0; i< Index_F1; i++){
        printf("%d ",arr_F1_Index[i]);
    }

    // Assign another F1 + Severity to array in ptr_arr_a
    /* Tìm F1 có cùng Index F1 --> F1: m_F = 2;  */
    for (int q = 0; q < Index_F1; q++){
        for(int i=0; i<row_a; i++){
            for(int j=0; j<2; j++){
                if(arr_F1_Index[q] == ptr_arr_a[i][j]->m_Index){
                    ptr_arr_a[i][j]->m_F = 2;
                }
            }
        }
    }
    printf("\n");
    // -----------------------------
    /* Đánh F2 : Tìm hàng chứa F1 (m_F == 2) --> trong hàng đó nếu không là F0,F1 thì chắc chắn là F2
     Nếu là F1 thì bỏ qua F1: m_F = 2;  m_Severity = 3; */
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if(ptr_arr_a[j][k]->m_F == 2)
            {
                for (int m = 0; m< 2; m++){
                    if (ptr_arr_a[j][m]->m_F != 2 && ptr_arr_a[j][m]->m_F != 1){
                        ptr_arr_a[j][m]->m_F = 3;
                        ptr_arr_a[j][m]->m_Severity = 3;
                        Severity_arr_a = Severity_arr_a + 3;
                    }

                }
            }
        }
    }
    /* Tìm số lượng phần tử F2*/
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 3){
                Index_F2 ++;
            }
        }
    }
    /* Tạo mảng chứa Index F2 */
    printf("Index_F2 = %d ",Index_F2);
    int arr_F2_Index[Index_F2]; // Array of F2 index
    int count_2 = 0;
    // Assign arr_F2_Index[]
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 3){
                arr_F2_Index[count_2] = ptr_arr_a[j][k]->m_Index;
                count_2 ++;
            }
        }
    }
    // Print arr_F2_Index[]
    printf("\n");
    for ( int i = 0; i< Index_F2; i++){
        printf("%d ",arr_F2_Index[i]);
    }
    /* Tìm F2 có cùng Index F2 --> F2: m_F = 3;  */
    // Add another F2 to array
    for (int q = 0; q < Index_F2; q++){
        for(int i=0; i< row_a; i++){
            for(int j=0; j<2; j++){
                if(arr_F2_Index[q] == ptr_arr_a[i][j]->m_Index){
                    ptr_arr_a[i][j]->m_F = 3;
                }
            }
        }
    }
    printf("\n");
    // -----------------------------
    /* Đánh F3 : Tìm hàng chứa F2 (m_F == 3) --> trong hàng đó nếu không là F0,F1,F2 thì chắc chắn là F3
     Nếu là F0,F1,F2 thì bỏ qua. F3: m_F = 4;  m_Severity = 1; */
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if(ptr_arr_a[j][k]->m_F == 3)
            {
                for (int m = 0; m< 2; m++){
                    if (ptr_arr_a[j][m]->m_F != 3 && ptr_arr_a[j][m]->m_F != 2 && ptr_arr_a[j][m]->m_F != 1){
                        ptr_arr_a[j][m]->m_F = 4;
                        ptr_arr_a[j][m]->m_Severity = 1; // Assign Severity = 1
                        Severity_arr_a = Severity_arr_a + 1;
                    }
                }
            }
        }
    }
    /* Tìm số lượng phần tử F3*/
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 4){
                Index_F3 ++;
            }
        }
    }
    printf("Index_F3 = %d ",Index_F3);
    /* Tạo mảng chứa Index F3 */
    int arr_F3_Index[Index_F3]; // Array of F3 index
    int count_3 = 0;
    // Assign arr_F3_Index[]
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if (ptr_arr_a[j][k]->m_F == 4){
                arr_F3_Index[count_3] = ptr_arr_a[j][k]->m_Index;
                count_3 ++;
            }
        }
    }
    // Print arr_F3_Index[]
    printf("\n");
    for ( int i = 0; i< Index_F3; i++){
        printf("%d ",arr_F3_Index[i]);
    }
    /* Tìm F2 có cùng Index F3 --> F3: m_F = 1;  */
    for (int q = 0; q < Index_F3; q++){
        for(int i=0; i< row_a; i++){
            for(int j=0; j<2; j++){
                if(arr_F3_Index[q] == ptr_arr_a[i][j]->m_Index){
                    ptr_arr_a[i][j]->m_F = 4;
                    ptr_arr_a[i][j]->m_Severity = 1; // Assign Severity = 1
                }
            }
        }
    }
    printf("\n");
    // -----------------------------
    /* Đánh F4 : Tìm hàng chứa F3 (m_F = 4) --> trong hàng đó nếu không là F2,F3 thì chắc chắn là F4
     Nếu là F2,F3 thì bỏ qua. F4: m_F = 5;  m_Severity = 1; */
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            if(ptr_arr_a[j][k]->m_F == 4)
            {
                for (int m = 0; m< 2; m++){
                    if ( (ptr_arr_a[j][m]->m_F != 3) && (ptr_arr_a[j][m]->m_F != 4)){
                        ptr_arr_a[j][m]->m_F = 5;
                        ptr_arr_a[j][m]->m_Severity = 1; // Assign Severity = 0
                        Severity_arr_a = Severity_arr_a + 1;
                    }

                }
            }
        }
    }

    printf("Index_F4 = %d ",Index_F4);
    int arr_F4_Index[Index_F4]; // Array of F3 index
    int count_4 = 0;
    printf("\n");
    // -----------------------------
    /* Tìm số lượng F0 ở mảng b  có ở mảng a */
    // Calculate Count_Group_F0 who don't contact with others
    int Count_Group_F0 =0;
    for ( int j = 0; j< length_b; j++){
        for ( int k = 0; k< row_a; k++){
                for (int m = 0; m< 2; m++){
                    if (ptr_arr_a[k][m]->m_Index == arr_b[j])
                        Count_Group_F0 ++;
                }
            }
        }
    /* Tìm số lượng F0 ở mảng b mà không có ở mảng a */
    int Count_F0_b = length_b - Count_Group_F0;
    int Severity_F0_b =10;
    printf("\n");
    printf("Count_Group_F0 = %d ",Count_Group_F0);
    Number_Group = Number_Group + (length_b-Count_Group_F0);
    /* Tìm số lượng Fx ở mảng a không phaỉ là F0, F1, F2, F3, F4 */

    // Calculate Count_Group_Fi who don't contact with others in Array
    int Count_Group_Fx =0;
    for ( int k = 0; k< row_a; k++){
        for (int m = 0; m< 2; m++){
            if ((ptr_arr_a[k][m]->m_F != 1) && (ptr_arr_a[k][m]->m_F != 2) && (ptr_arr_a[k][m]->m_F != 3) && (ptr_arr_a[k][m]->m_F != 4) && (ptr_arr_a[k][m]->m_F != 5))
                Count_Group_Fx ++;
        }
    }
    /* Khi Fx ở mảng a không phải là F1, F2, F3, F4, --> ít nhất có thêm 1 group lây nhiễm*/
    /* số lượng Fx = 2 thì sẽ có 1 group*/
    if (Count_Group_Fx = 2){
        Number_Group_Fx =1;
        Number_Group = Number_Group +1;
    }

    /* Tìm số lượng Fx ở mảng a không phaỉ là F0, F1, F2, F3, F4 */
    printf("\n");
    printf("Count_Group_Fi = %d \n",Count_Group_Fx);
    /* Nếu số lượng Fx là 1 hoặc 2 thì: có 1 Group mới với Severity = 0*/
    /* Tìm Fx thuộc n nhưng không xuất hiện trong chuỗi lây nhiễm*/
    /* Chuyển array a sang 1 chiều*/
    printf("Convert array a to 1 dimension: ");
    int arr_a_index[length_a];
    int k = 0;
    for (int i = 0; i < row_a; i++){
        for ( int j = 0; j<2; j++){
            arr_a_index[k] = arr_a[i][j];
            printf ("%d ", arr_a_index[k]);
            k ++;
        }
    }

    printf("\n");
    /* xóa index trùng lặp của array a */
    for(int i=0; i<length_a; i++)
    {
        for(int j=i+1; j<length_a; j++)
        {
            /* If any duplicate found */
            if(arr_a_index[i] == arr_a_index[j])
            {
                /* Delete the current duplicate element */
                for(int k=j; k < length_a - 1; k++)
                {
                    arr_a_index[k] = arr_a_index[k + 1];
                }

                /* Decrement size after removing duplicate element */
                length_a--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
    /* Tìm Fx thuộc n nhưng không xuất hiện trong chuỗi lây nhiễm */

    // Calculate Total Severity array a
    printf("Severity_arr_a = %d \n", Severity_arr_a);
    /* nối 2 mảng array a không trùng index + mảng b*/
    printf("Merge 2 arrays to 1 array: ");
    int total_length = length_a + length_b;
    int array_merge[total_length];
    for (int i = 0; i < length_a; i++) {
        array_merge[i] = arr_a_index[i];
    }
    for (int i = 0, j = length_a;
         j < total_length && i < length_b; i++, j++) {
        array_merge[j] = arr_b[i];
    }
    for (int i = 0; i < total_length; i++) {
        printf("%d ", array_merge[i]);
    }
    /* xóa index trùng lặp của array tổng */
    for(int i=0; i<total_length; i++)
    {
        for(int j=i+1; j<total_length; j++)
        {
            /* If any duplicate found */
            if(array_merge[i] == array_merge[j])
            {
                /* Delete the current duplicate element */
                for(int k=j; k < total_length - 1; k++)
                {
                    array_merge[k] = array_merge[k + 1];
                }

                /* Decrement size after removing duplicate element */
                total_length--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
    printf("\n");
    printf(" array tong - duplicate: ");
    for (int i = 0; i < total_length; i++) {
        printf("%d ", array_merge[i]);
    }

    /* Fx thuộc n nhưng không xuất hiện trong chuỗi lây nhiễm --> Group mới; Severity =0*/
    int count_Fa = 0;
    for (int i =0; i<total_length; i++){
        if (array_merge[i] != 0){
            count_Fa = count_Fa +1;
        }
    }
    Disappear_Person = n - count_Fa;
    Number_Group = Number_Group + Disappear_Person;
    /* Nếu toàn bộ Fx xuất hiện trong cả 2 mảng nhập vào a và b --> Không có Group mới; Severity =0*/
    /* Nếu có tồn tại Fx không xuất hiện trong cả 2 mảng nhập vào a và b --> có Group mới; Severity =0*/
    printf("\n");
    printf("%d",n - count_Fa);
    // Print F
    printf("\n");
    for ( int j = 0; j< row_a; j++){
        for ( int k = 0; k< 2; k++){
            printf("%d ",ptr_arr_a[j][k]->m_F);

        }
    }
    /* Xuất kết quả*/
    /* Copy giá trị từng group vào Group_Severity*/
    if(Count_Group_Fa ==1){
        for (int i =0; i< Count_Group_Fa; i++){
            Group_Severity[0]=Severity_arr_a;
        }
    }
    for(int i =Count_Group_Fa; i <(Count_Group_Fa+Count_F0_b); i++){
        Group_Severity[i] = Severity_F0_b;
    }
    for(int i =(Number_Group-Number_Group_Fx ); i <(Number_Group); i++){
        Group_Severity[Number_Group-Number_Group_Fx] = Severity_Fx;
    }




    printf("\nOutput: ");
    for ( int i=0; i<Number_Group; i++){
        printf(" [%d] ", Group_Severity[i]);
    }

    return 0;
}

