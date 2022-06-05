#ifndef DIVISION_RESULT_H
#define DIVISION_RESULT_H

template <typename T>
struct DivisionResult {
    T* quotient; // Частка
    T* remainder; // Остача
};

#endif // DIVISION_RESULT_H
