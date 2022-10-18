#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef signed short s2;

#define TC 1
#if TC == 1
s2 n =10;
s2 arr_b[] ={3,8,5};
s2 arr_a[7][2] = {{1, 2}, {1, 3}, {2, 4}, {4, 6}, {2, 8}, {6, 9}, {7, 10}};
#elif TC == 2
s2 n =10;
s2 arr_b[] ={4,9,2,8};
s2 arr_a[5][2] = {{10, 7}, {3, 6}, {2, 10}, {5, 6}, {10, 8}};
#elif TC == 3
s2 n =10;
s2 arr_b[] ={5,3,7,2};
s2 arr_a[5][2] = {{9,4}, {6,7}, {2,8}, {3,10}, {8,10}};
#elif TC == 4
s2 n =6;
s2 arr_b[] ={2,6,5};
s2 arr_a[4][2] = {{1,5}, {2,5}, {1,4}, {4,6}};
#elif TC == 5
s2 n =6;
s2 arr_b[] ={4,3};
s2 arr_a[5][2] = {{1,6}, {5,1}, {6,4}, {4,3}, {5,3}};

#endif

#define MAX_GROUP 10
s2 length_b = sizeof(arr_b)/sizeof(arr_b[0]); // Calculate how many elements of array b
s2 length_a = sizeof (arr_a)/sizeof (arr_a[0][0]); // Calculate how many elements of array a
s2 row_a = (sizeof (arr_a)/sizeof (arr_a[0][0]))/2; // Calculate how many couples of array a
s2 Index_F0 =0;
s2 Index_F1 =0;
s2 Index_F2 =0;
s2 Index_F3 =0;
s2 Index_F4 =0;
s2 Severity_arr_a =0;
s2 Severity_Fx = 0;
s2 Number_Group = 0;
s2 Count_Group_Fa = 0;
s2 Number_Group_Fx =0;
s2 Disappear_Person = 0;
s2 Group_Severity[MAX_GROUP];
typedef struct Person{
    s2 m_Index;
    s2 m_F;
    s2 m_Severity;
} st_Person;
void fs_Merge_2arrays (s2 * ptr_merge, s2 *x, s2 * ptr_arr_a_index, s2 *y,s2 * ptr_arr_b, s2 *z );
void fs_Delete_Duplicate (s2 *a, s2 * ptr_array);
int main() {

/* Tạo array 2 chiều các phần tử có kiểu dữ liệu struct Person để lưu trữ thông tin mảng a truyền vào */
    st_Person arr_Person[row_a][2]; // Khai báo array 2 chiều
    for (s2 i =0; i<row_a; i++){
        for (s2 j =0; j<2; j++){
            arr_Person[i][j].m_Index = arr_a[i][j];
        }
    }

    printf("\n");

    // -----------------------------
    /* Đánh F0 cho mảng array pointer vừa tạo F0: m_F = 1;  m_Severity = 10; */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            for ( s2 i = 0; i< length_b; i++){
                if(arr_Person[j][k].m_Index == arr_b[i]){
                    arr_Person[j][k].m_F = 1; // Assign F0 = 1
                    arr_Person[j][k].m_Severity = 10;
                    Severity_arr_a = Severity_arr_a + 10; /* Severity tăng lên 10 */
                }
            }
            printf("%d ", arr_Person[j][k].m_Severity);
        }
    }
    printf("\n");

    /* Tìm số luượng phần tử F0 */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 1){
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

    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if(arr_Person[j][k].m_F == 1)
                {
                    for (s2 m = 0; m< 2; m++){
                        if (arr_Person[j][m].m_F != 1){
                            arr_Person[j][m].m_F = 2;
                            arr_Person[j][m].m_Severity = 5;
                            Severity_arr_a = Severity_arr_a + 5;
                        }
                    }
                }
            }
        }
    printf("\n");


    /* Tìm số lượng phần tử F1 */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 2){
                Index_F1 ++;
            }
        }
    }
    printf("Index_F1 = %d ",Index_F1);
    // Assign arr_F1_Index[]

    /* Tạo mảng chứa Index F1 */
    s2 arr_F1_Index [Index_F1];
    s2 count_1 = 0;
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 2){
                arr_F1_Index[count_1] = arr_Person[j][k].m_Index;
                count_1 ++;
            }
        }
    }


    // Print arr_F1_Index[]
    printf("\n");
    for ( s2 i = 0; i< Index_F1; i++){
        printf("%d ",arr_F1_Index[i]);
    }

    // Assign another F1 + Severity to array in arr_Person
    /* Tìm F1 có cùng Index F1 --> F1: m_F = 2;  */
    for (s2 q = 0; q < Index_F1; q++){
        for(s2 i=0; i<row_a; i++){
            for(s2 j=0; j<2; j++){
                if(arr_F1_Index[q] == arr_Person[i][j].m_Index){
                    arr_Person[i][j].m_F = 2;
                }
            }
        }
    }
    printf("\n");
    // -----------------------------
    /* Đánh F2 : Tìm hàng chứa F1 (m_F == 2) --> trong hàng đó nếu không là F0,F1 thì chắc chắn là F2
     Nếu là F1 thì bỏ qua F1: m_F = 2;  m_Severity = 3; */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if(arr_Person[j][k].m_F == 2)
            {
                for (s2 m = 0; m< 2; m++){
                    if (arr_Person[j][m].m_F != 2 && arr_Person[j][m].m_F != 1){
                        arr_Person[j][m].m_F = 3;
                        arr_Person[j][m].m_Severity = 3;
                        Severity_arr_a = Severity_arr_a + 3;
                    }

                }
            }
        }
    }
    /* Tìm số lượng phần tử F2*/
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 3){
                Index_F2 ++;
            }
        }
    }
    /* Tạo mảng chứa Index F2 */
    printf("Index_F2 = %d ",Index_F2);
    s2 arr_F2_Index[Index_F2]; // Array of F2 index
    s2 count_2 = 0;
    // Assign arr_F2_Index[]
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 3){
                arr_F2_Index[count_2] = arr_Person[j][k].m_Index;
                count_2 ++;
            }
        }
    }
    // Print arr_F2_Index[]
    printf("\n");
    for ( s2 i = 0; i< Index_F2; i++){
        printf("%d ",arr_F2_Index[i]);
    }
    /* Tìm F2 có cùng Index F2 --> F2: m_F = 3;  */
    // Add another F2 to array
    for (s2 q = 0; q < Index_F2; q++){
        for(s2 i=0; i< row_a; i++){
            for(s2 j=0; j<2; j++){
                if(arr_F2_Index[q] == arr_Person[i][j].m_Index){
                    arr_Person[i][j].m_F = 3;
                }
            }
        }
    }
    printf("\n");
    // -----------------------------
    /* Đánh F3 : Tìm hàng chứa F2 (m_F == 3) --> trong hàng đó nếu không là F0,F1,F2 thì chắc chắn là F3
     Nếu là F0,F1,F2 thì bỏ qua. F3: m_F = 4;  m_Severity = 1; */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if(arr_Person[j][k].m_F == 3)
            {
                for (s2 m = 0; m< 2; m++){
                    if (arr_Person[j][m].m_F != 3 && arr_Person[j][m].m_F != 2 && arr_Person[j][m].m_F != 1){
                        arr_Person[j][m].m_F = 4;
                        arr_Person[j][m].m_Severity = 1; // Assign Severity = 1
                        Severity_arr_a = Severity_arr_a + 1;
                    }
                }
            }
        }
    }
    /* Tìm số lượng phần tử F3*/
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 4){
                Index_F3 ++;
            }
        }
    }
    printf("Index_F3 = %d ",Index_F3);
    /* Tạo mảng chứa Index F3 */
    s2 arr_F3_Index[Index_F3]; // Array of F3 index
    s2 count_3 = 0;
    // Assign arr_F3_Index[]
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 4){
                arr_F3_Index[count_3] = arr_Person[j][k].m_Index;
                count_3 ++;
            }
        }
    }
    // Print arr_F3_Index[]
    printf("\n");
    for ( s2 i = 0; i< Index_F3; i++){
        printf("%d ",arr_F3_Index[i]);
    }
    /* Tìm F2 có cùng Index F3 --> F3: m_F = 1;  */
    for (s2 q = 0; q < Index_F3; q++){
        for(s2 i=0; i< row_a; i++){
            for(s2 j=0; j<2; j++){
                if(arr_F3_Index[q] == arr_Person[i][j].m_Index){
                    arr_Person[i][j].m_F = 4;
                    arr_Person[i][j].m_Severity = 1; // Assign Severity = 1
                }
            }
        }
    }
    printf("\n");
    // -----------------------------
    /* Đánh F4 : Tìm hàng chứa F3 (m_F = 4) --> trong hàng đó nếu không là F2,F3 thì chắc chắn là F4
     Nếu là F2,F3 thì bỏ qua. F4: m_F = 5;  m_Severity = 1; */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if(arr_Person[j][k].m_F == 4)
            {
                for (s2 m = 0; m< 2; m++){
                    if ( (arr_Person[j][m].m_F != 3) && (arr_Person[j][m].m_F != 4)){
                        arr_Person[j][m].m_F = 5;
                        arr_Person[j][m].m_Severity = 1; // Assign Severity = 0
                        Severity_arr_a = Severity_arr_a + 1;
                    }

                }
            }
        }
    }

    printf("Index_F4 = %d ",Index_F4);
    s2 arr_F4_Index[Index_F4]; // Array of F3 index
    s2 count_4 = 0;
    printf("\n");
    // -----------------------------
    /* Tìm số lượng F0 ở mảng b  có ở mảng a */
    // Calculate Count_Group_F0 who don't contact with others
    s2 Count_Group_F0 =0;
    for ( s2 j = 0; j< length_b; j++){
        for ( s2 k = 0; k< row_a; k++){
                for (s2 m = 0; m< 2; m++){
                    if (arr_Person[k][m].m_Index == arr_b[j])
                        Count_Group_F0 ++;
                }
            }
        }
    /* Tìm số lượng F0 ở mảng b mà không có ở mảng a */
    s2 Count_F0_b = length_b - Count_Group_F0;
    s2 Severity_F0_b =10;
    printf("\n");
    printf("Count_Group_F0 = %d ",Count_Group_F0);
    Number_Group = Number_Group + (length_b-Count_Group_F0);
    /* Tìm số lượng Fx ở mảng a không phaỉ là F0, F1, F2, F3, F4 */

    // Calculate Count_Group_Fi who don't contact with others in Array
    s2 Count_Group_Fx =0;
    for ( s2 k = 0; k< row_a; k++){
        for (s2 m = 0; m< 2; m++){
            if ((arr_Person[k][m].m_F != 1) && (arr_Person[k][m].m_F != 2) && (arr_Person[k][m].m_F != 3) && (arr_Person[k][m].m_F != 4) && (arr_Person[k][m].m_F != 5))
                Count_Group_Fx ++;
        }
    }
    /* Khi Fx ở mảng a không phải là F1, F2, F3, F4, --> ít nhất có thêm 1 group lây nhiễm*/
    /* số lượng Fx = 2 thì sẽ có 1 group*/
    if (Count_Group_Fx = 2){
        Number_Group = Number_Group +1;
    }

    /* Tìm số lượng Fx ở mảng a không phaỉ là F0, F1, F2, F3, F4 */
    printf("\n");
    printf("Count_Group_Fi = %d \n",Count_Group_Fx);
    /* Nếu số lượng Fx là 1 hoặc 2 thì: có 1 Group mới với Severity = 0*/
    /* Tìm Fx thuộc n nhưng không xuất hiện trong chuỗi lây nhiễm*/
    /* Chuyển array a sang 1 chiều*/
    printf("Convert array a to 1 dimension: ");
    s2 arr_a_index[length_a];
    s2 k = 0;
    for (s2 i = 0; i < row_a; i++){
        for ( s2 j = 0; j<2; j++){
            arr_a_index[k] = arr_a[i][j];
            printf ("%d ", arr_a_index[k]);
            k ++;
        }
    }

    printf("\n");
    /* xóa index trùng lặp của array a */
    fs_Delete_Duplicate (&length_a, arr_a_index);
    /* Tìm Fx thuộc n nhưng không xuất hiện trong chuỗi lây nhiễm */

    // Calculate Total Severity array a
    printf("Severity_arr_a = %d \n", Severity_arr_a);
    /* nối 2 mảng array a không trùng index + mảng b*/
    printf("Merge 2 arrays to 1 array: ");
    s2 total_length = length_a + length_b;
    s2 array_merge[total_length];
    fs_Merge_2arrays (array_merge, &total_length, arr_a_index, &length_a, arr_b, &length_b );

    /* xóa index trùng lặp của array tổng */
    fs_Delete_Duplicate (&total_length, array_merge);

    printf("\n");
    printf(" array tong - duplicate: ");
    for (s2 i = 0; i < total_length; i++) {
        printf("%d ", array_merge[i]);
    }

    /* Fx thuộc n nhưng không xuất hiện trong chuỗi lây nhiễm --> Group mới; Severity =0*/
    s2 count_Fa = 0;
    for (s2 i =0; i<total_length; i++){
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
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            printf("%d ",arr_Person[j][k].m_F);

        }
    }
    /* Xuất kết quả*/
    /* Copy giá trị từng group vào Group_Severity*/
    if(Count_Group_Fa ==1){
        for (s2 i =0; i< Count_Group_Fa; i++){
            Group_Severity[0]=Severity_arr_a;
        }
    }
    for(s2 i =Count_Group_Fa; i <(Count_Group_Fa+Count_F0_b); i++){
        Group_Severity[i] = Severity_F0_b;
    }
    for(s2 i =(Number_Group-Number_Group_Fx ); i <(Number_Group); i++){
        Group_Severity[Number_Group-Number_Group_Fx] = Severity_Fx;
    }




    printf("\nOutput: ");
    for ( s2 i=0; i<Number_Group; i++){
        printf(" [%d] ", Group_Severity[i]);
    }
    return 0;
}
void fs_Index_arr_Person (st_Person *arr){

    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
             st_Person *temp = arr+j*row_a + k; // Assign Index from array a
             temp->m_Index = arr_a[j][k];
            printf("%d ",temp->m_Index);
        }
    }

}

void fs_Merge_2arrays (s2 * ptr_merge, s2 *x, s2 * ptr_arr_a_index, s2 *y,s2 * ptr_arr_b, s2 *z ){
    for (s2 i = 0; i < *y; i++) {
        *(ptr_merge+i) = *(ptr_arr_a_index+i);
    }
    for (s2 i = 0, j = length_a;
         j < *x && i < *z; i++, j++) {
        *(ptr_merge+j) = *(ptr_arr_b+i);
    }
    for (s2 i = 0; i < *x; i++) {
        printf("%d ", *(ptr_merge+i));
    }
}

void fs_Delete_Duplicate (s2 *a, s2 * ptr_array){
    for(s2 i=0; i<*a; i++)
    {
        for(s2 j=i+1; j<*a; j++)
        {
            /* If any duplicate found */
            if((* (ptr_array+i)) == * (ptr_array+j))
            {
                /* Delete the current duplicate element */
                for(s2 k=j; k < *a - 1; k++)
                {
                    (* (ptr_array+k)) = (* (ptr_array+k+1));
                }

                /* Decrement size after removing duplicate element */
                (*a)--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
}