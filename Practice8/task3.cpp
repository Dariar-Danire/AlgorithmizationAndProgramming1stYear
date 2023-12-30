#include <vector>
#include <algorithm>
std::vector<int**> current_array;

// Создаёт массив длины len, заполненный значениями val
int* new_array(int len, int value) {
    int* array = new int[len];
    current_array.push_back(&array);

    for (int i = 0; i < len; i++) {
        *(array + i) = value;
    }

    return array;
}

// Изменяет длину массива, при необходимости дополняя массив нулями
int set_new_length(int** array, int old_len, int new_len) {
    int* new_array = new int[new_len];

    for (int i = 0; i < new_len; i++) {
        if (i >= old_len) {
            new_array[i] = 0;
        }
        else {
            new_array[i] = **array;
        }
    }

    *array = new_array;
    return new_len;
}

// Добавляет элементы из массива-источника в массив-приёмник.
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array) {
    int* new_array = new int[len_dest_array + len_src_array];

    for (int i = 0; i < len_dest_array + len_src_array; i++) {
        if (i < len_dest_array) {
            new_array[i] = *((*dest_array) + i);
        }
        else {
            new_array[i] = src_array[i - len_dest_array];
        }
    }

    *dest_array = new_array;
    return len_dest_array + len_src_array;
}

// Вычисляет скалярное произведение двух массивов
int dot(const int* a, const int* b, int len) {
    int s = 0;
    for (int i = 0; i < len; i++) {
        s += a[i] * b[i];
    }

    return s;
}

// Находит первое вхождение value в массив. Возвращает либо nullptr, либо указатель на элемент массива
int* find(int* array, int len, int value) {
    for (int i = 0; i < len; i++) {
        if (array[i] == value) {
            return array + i;
        }
    }

    return nullptr;
}

// Удаление массива из кучи
void delete_array(int** array) {
    if (std::count(current_array.begin(), current_array.end(), array) != 0) {
        delete[] * array;
    }
}
