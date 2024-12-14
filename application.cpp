#include "application.h"
#include <iostream>

Application::Application() : array(3, number()) {
    std::cout << "Программа для работы с массивом комплексных чисел.\n";
}

void Application::run() {
    bool running = true;
    while (running) {
        print_menu();
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1: handle_input(); break;
        case 2: handle_mean_and_stddev(); break;
        case 3: handle_sort(true); break;
        case 4: handle_sort(false); break;
        case 5: handle_resize(); break;
        case 6: handle_modify_element(); break;
        case 7: handle_output(); break;
        case 0: running = false; break;
        default: std::cout << "Неверный выбор. Попробуйте снова.\n"; break;
        }
    }
}

void Application::print_menu() {
    std::cout << "\nМеню:\n"
              << "1. Ввод массива\n"
              << "2. Вычисление среднего и СКО\n"
              << "3. Сортировка по возрастанию\n"
              << "4. Сортировка по убыванию\n"
              << "5. Изменение размерности массива\n"
              << "6. Изменение значения элемента\n"
              << "7. Вывод массива\n"
              << "0. Выход\n"
              << "Введите ваш выбор: ";
}

void Application::handle_input() {
    std::cout << "Введите размер массива: ";
    size_t size;
    std::cin >> size;
    array.resize(size);
    std::cout << "Введите элементы массива:\n";
    std::cin >> array;
}

void Application::handle_mean_and_stddev() {
    std::cout << "Среднее значение модуля: " << array.mean() << "\n";
    std::cout << "СКО модуля: " << array.std_dev() << "\n";
}

void Application::handle_sort(bool ascending) {
    if (ascending) {
        array.sort_ascending();
        std::cout << "Массив отсортирован по возрастанию.\n";
    } else {
        array.sort_descending();
        std::cout << "Массив отсортирован по убыванию.\n";
    }
}

void Application::handle_resize() {
    std::cout << "Введите новый размер массива: ";
    size_t newSize;
    std::cin >> newSize;
    array.resize(newSize);
}

void Application::handle_modify_element() {
    std::cout << "Введите индекс изменяемого элемента: ";
    size_t index;
    std::cin >> index;
    std::cout << "Введите новое значение элемента:\n";
    number value;
    std::cin >> value;
    array.set_value(index, value);
}

void Application::handle_output() {
    std::cout << "Текущий массив:\n";
    std::cout << array;
}
