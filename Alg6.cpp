/*
id: 19821526
������ ���������

������: 6_3
���� ��������������� ����� ����� n,k � ������ ����� ����� �� [0..10^9] ������� n. 
��������� ����� k-� ���������� ����������. �.�. ���������� �����, ������� �� ������ 
�� ������� � �������� k (0..n-1) � ��������������� �������. �������� ������������� ��������.

���������� ��������� ������ �������� �������� ���������� �������. 
������� Partition ���������� ������� ������� ����� ����������� �� ������ ������� � �����.
*/

#include <iostream>

template <typename T, class Compare>
int Partition(T *array, int left, int right, const Compare &compare);

template <typename T, class Compare>
T Find_value_order_statistics(T *array, int array_size, int order_stat_index, const Compare &compare);

int *Create_array(int array_size);


int main(void) {
    int array_size = 0, order_statistics = 0;
    std::cin >> array_size >> order_statistics;

    int *array = Create_array(array_size);

    std::cout << Find_value_order_statistics(array, array_size, order_statistics, [](int x, int y) {return x > y; });
    return 0;
}


template <typename T, class Compare>
int Partition(T *array, int left, int right, const Compare &compare) {
    int rand_ind = left;
    if (left != right)
        rand_ind = rand() % (right - left) + left;

    std::swap(array[rand_ind], array[right]);

    T pivot = array[right];
    int i = left, j = left;

    for (;;) {
        for (; compare(array[j], pivot); j++);
        if (j != right) {
            std::swap(array[j], array[i]);
            j++;
            i++;
        }
        if (j == right)
            break;
    }
    std::swap(array[right], array[i]);
    return i;
}

template <typename T, class Compare>
T Find_value_order_statistics(T *array, int array_size, int order_stat_index, const Compare &compare) {
    int left = 0, right = array_size - 1;
    int partition = 0;

    for (;;) {
        partition = Partition(array, left, right, compare);

        if (partition == order_stat_index)
            return array[partition];

        if (partition > order_stat_index) {
            right = partition - 1;
        }
        else {
            left = partition + 1;
        }
    }
}

int *Create_array(int array_size) {
    int *array = new int[array_size];

    for (size_t i = 0; i < array_size; i++) {
        std::cin >> array[i];
    }
    return array;
}