#include <stdio.h>
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
#elif TC == 6
s2 n =20;
s2 arr_b[] ={10,20,17};
s2 arr_a[20][2] = {{5,7},{10,11},{2,15},{10,5},{10,6},{15,12},{6,11},{13,16},{10,19},{13,14},{3,16},{13,1},{11,1},{9,3},{3,14},{3,5},{1,8},{4,13},{14,8},{14,8}};
#endif

#define MAX_GROUP 10
s2 length_b = sizeof(arr_b)/sizeof(arr_b[0]);
s2 length_a = sizeof (arr_a)/sizeof (arr_a[0][0]);
s2 row_a = (sizeof (arr_a)/sizeof (arr_a[0][0]))/2;
s2 Index_F0 =0;
s2 Index_F1 =0;
s2 Index_F2 =0;
s2 Index_F3 =0;
s2 Index_F4 =0;
s2 Severity_arr_a =0;
s2 Severity_Fx = 0;
s2 Number_Group = 0;
s2 Count_Group_Fa = 0;
s2 Disappear_Person = 0;
s2 Group_Severity[MAX_GROUP];
typedef struct Person{
    s2 m_Index;
    s2 m_F;
    s2 m_Severity;
} st_Person;
void fs_Merge_2arrays (s2 * ptr_merge, s2 *x, s2 * ptr_arr_a_index, s2 *y,s2 * ptr_arr_b, s2 *z );
void fs_Delete_Duplicate (s2 *a, s2 * ptr_array);
void fs_Count_Fa(s2 * ptr_array, s2 *a,  s2 *b);
int main() {

/* Tạo array 2 chiều các phần tử có kiểu dữ liệu struct Person để lưu trữ thông tin mảng a truyền vào */
/* arr_Person = {{1, 2}, {1, 3}, {2, 4}, {4, 6}, {2, 8}, {6, 9}, {7, 10}}*/
    st_Person arr_Person[row_a][2]; // Khai báo array 2 chiều
    for (s2 i =0; i<row_a; i++){
        for (s2 j =0; j<2; j++){
            arr_Person[i][j].m_Index = arr_a[i][j];
        }
    }

    /* Đánh F0 cho mảng array pointer vừa tạo F0: m_F = 1;  m_Severity = 10; */

    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            for ( s2 i = 0; i< length_b; i++){
                if(arr_Person[j][k].m_Index == arr_b[i]){
                    arr_Person[j][k].m_F = 1; /* arr_Person = {{, }, {, 1}, {, }, {, }, {, 1}, {, }, {, }}*/
                    arr_Person[j][k].m_Severity = 10;
                    Severity_arr_a = Severity_arr_a + 10; /* Severity tăng lên 10 */
                }
            }
        }
    }

    /* Tìm số lượng phần tử F0 */
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 1){
                Index_F0 ++; /* Index_F0 = 2 */
            }
        }
    }
    /* Khi F0 ở mảng b xuất hiện ở mảng a --> ít nhất có 1 group lây nhiễm*/
    /* Number_Group = 1 */
    if(Index_F0 != 0){
        Count_Group_Fa ++;
        Number_Group = Number_Group+ 1;
    }
    /* Đánh F1 : tìm hàng chứa F0 (m_F == 1) --> trong hàng đó nếu không là F0 thì chắc chắn là F1 Nếu là F0 thì bỏ qua. F1: m_F = 2;  m_Severity = 5; */

    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if(arr_Person[j][k].m_F == 1)
                {
                    for (s2 m = 0; m< 2; m++){
                        if (arr_Person[j][m].m_F != 1){
                            arr_Person[j][m].m_F = 2;           /* arr_Person = {{, }, {1, 1}, {, }, {, }, {1, 1}, {, }, {, }}*/
                            arr_Person[j][m].m_Severity = 5;
                            Severity_arr_a = Severity_arr_a + 5;
                        }
                    }
                }
            }
        }



    /* Tìm số lượng phần tử F1 trong arr_Person*/
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 2){
                Index_F1 ++;
            }
        }
    }

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

    /* Tìm F1 có cùng Index trong mảng  --> F1: m_F = 2;  */
    for (s2 q = 0; q < Index_F1; q++){
        for(s2 i=0; i<row_a; i++){
            for(s2 j=0; j<2; j++){
                if(arr_F1_Index[q] == arr_Person[i][j].m_Index){
                    arr_Person[i][j].m_F = 2;
                }
            }
        }
    }

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
    s2 arr_F2_Index[Index_F2]; // Array of F2 index
    s2 count_2 = 0;
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 3){
                arr_F2_Index[count_2] = arr_Person[j][k].m_Index;
                count_2 ++;
            }
        }
    }

    /* Tìm F2 có cùng Index F2 trong mảng --> F2: m_F = 3;  */
    for (s2 q = 0; q < Index_F2; q++){
        for(s2 i=0; i< row_a; i++){
            for(s2 j=0; j<2; j++){
                if(arr_F2_Index[q] == arr_Person[i][j].m_Index){
                    arr_Person[i][j].m_F = 3;
                }
            }
        }
    }

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
                        arr_Person[j][m].m_Severity = 1;
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
    /* Tạo mảng chứa Index F3 */
    s2 arr_F3_Index[Index_F3];
    s2 count_3 = 0;
    for ( s2 j = 0; j< row_a; j++){
        for ( s2 k = 0; k< 2; k++){
            if (arr_Person[j][k].m_F == 4){
                arr_F3_Index[count_3] = arr_Person[j][k].m_Index;
                count_3 ++;
            }
        }
    }
    /* Tìm F2 có cùng Index F3 --> F3: m_F = 1;  */
    for (s2 q = 0; q < Index_F3; q++){
        for(s2 i=0; i< row_a; i++){
            for(s2 j=0; j<2; j++){
                if(arr_F3_Index[q] == arr_Person[i][j].m_Index){
                    arr_Person[i][j].m_F = 4;
                    arr_Person[i][j].m_Severity = 1;
                }
            }
        }
    }

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


    /* Tìm số lượng F0 ở mảng b  có ở mảng a */
    s2 Count_F0_a =0;
    for ( s2 j = 0; j< length_b; j++){
        for ( s2 k = 0; k< row_a; k++){
                for (s2 m = 0; m< 2; m++){
                    if (arr_Person[k][m].m_Index == arr_b[j])
                        Count_F0_a ++;
                }
            }
        }

    s2 Count_F0_b = length_b - Count_F0_a;
    s2 Severity_F0_b =10;
    Number_Group = Number_Group + (length_b-Count_F0_a);

    /* Tìm số lượng Fx ở mảng a không phaỉ là F0, F1, F2, F3, F4 */
    s2 Count_Fx =0;
    for ( s2 k = 0; k< row_a; k++){
        for (s2 m = 0; m< 2; m++){
            if ((arr_Person[k][m].m_F != 1) && (arr_Person[k][m].m_F != 2) && (arr_Person[k][m].m_F != 3) && (arr_Person[k][m].m_F != 4) && (arr_Person[k][m].m_F != 5))
                Count_Fx ++;
        }
    }
    /* Khi Fx ở mảng a không phải là F1, F2, F3, F4, --> ít nhất có thêm 1 group lây nhiễm*/
    /* số lượng Fx = 2 thì sẽ có 1 Group mới với Severity = 0*/
    if (Count_Fx = 2){
        Number_Group = Number_Group +1;
    }

    /* Tìm Fx thuộc n nhưng không xuất hiện trong mảng a và b*/
    s2 arr_a_index[length_a];     /* Chuyển array a sang 1 chiều*/
    s2 k = 0;
    for (s2 i = 0; i < row_a; i++){
        for ( s2 j = 0; j<2; j++){
            arr_a_index[k] = arr_a[i][j];
            k ++;
        }
    }
    /* xóa index trùng lặp của array a */
    fs_Delete_Duplicate (&length_a, arr_a_index);
    /* nối 2 mảng array a không trùng index + mảng b*/
    s2 total_length = length_a + length_b;
    s2 array_merge[total_length];
    fs_Merge_2arrays (array_merge, &total_length, arr_a_index, &length_a, arr_b, &length_b );
    /* xóa index trùng lặp của array tổng */
    fs_Delete_Duplicate (&total_length, array_merge);

    /* Tìm số lượng người xuất hiện trong mảng a mà không lặp lại*/
    s2 count_Fa = 0;
    fs_Count_Fa(array_merge, &count_Fa, &total_length ); /* 10 7 3 6 2 5 8 4 9*/
    /* Nếu có n Fx không xuất hiện trong cả 2 mảng nhập vào a và b --> Có n group mới; Severity =0 */
    Disappear_Person = n - count_Fa;
    Number_Group = Number_Group + Disappear_Person;

    /* Xuất kết quả*/
    /* Copy giá trị từng group vào Group_Severity*/
    /* Copy giá trị Severity vào chuỗi lây nhiễm có trong mảng a*/
    if(Count_Group_Fa ==1){
        for (s2 i =0; i< Count_Group_Fa; i++){
            Group_Severity[0]=Severity_arr_a;
        }
    }
    /* Copy giá trị Severity vào nhóm có trong mảng a mà không có trong mảng b*/
    for(s2 i =Count_Group_Fa; i <(Count_Group_Fa+Count_F0_b); i++){
        Group_Severity[i] = Severity_F0_b;
    }
    /* Copy giá trị Severity vào nhóm FX không xuất hiện trong cả 2 mảng nhập vào a và b*/
    for(s2 i =(Count_Group_Fa+Count_F0_b); i <(Number_Group); i++){
        Group_Severity[Count_Group_Fa+Count_F0_b] = Severity_Fx;
    }




    printf("\nOutput: ");
    for ( s2 i=0; i<Number_Group; i++){
        printf(" [%d] ", Group_Severity[i]);
    }
    return 0;
}


void fs_Merge_2arrays (s2 * ptr_merge, s2 *x, s2 * ptr_arr_a_index, s2 *y,s2 * ptr_arr_b, s2 *z ){
    for (s2 i = 0; i < *y; i++) {
        *(ptr_merge+i) = *(ptr_arr_a_index+i);
    }
    for (s2 i = 0, j = length_a;
         j < *x && i < *z; i++, j++) {
        *(ptr_merge+j) = *(ptr_arr_b+i);
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

void fs_Count_Fa(s2 * ptr_array, s2 *a,  s2 *b ){
    for (s2 i =0; i<*b; i++){
        if (ptr_array[i] != 0){
            *a = *a +1;
        }
    }
}