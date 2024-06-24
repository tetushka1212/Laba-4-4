// Laba 4-4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Kramer.h"

int main()
{
    Matrix m1(2, 2);
    m1.setElement(0, 0, 1.0);
    m1.setElement(0, 1, 2.0);
    m1.setElement(1, 0, 3.0);
    m1.setElement(1, 1, 4.0);

    Matrix m2(2, 2);
    m2.setElement(0, 0, 5.0);
    m2.setElement(0, 1, 6.0);
    m2.setElement(1, 0, 7.0);
    m2.setElement(1, 1, 8.0);

    std::cout << "Matrix m1:" << std::endl;
    m1.Print();

    std::cout << "Matrix m2:" << std::endl;
    m2.Print();

    Matrix sum = m1.Add(m2);
    std::cout << "Sum of matrixes:" << std::endl;
    sum.Print();

    Matrix scaled = m1.Multiply(m2);
    std::cout << "Matrix m1 scaled by m2:" << std::endl;
    scaled.Print();
    

    std::vector<std::vector<double>> data = { {2, 1, -1}, {-3, -1, 2}, {-2, 1, 2} };
    std::vector<double> b = { 8, -11, -3 };
    Matrix A(data);

    Kramer cramer(A, b);

    ofstream outfile("solution.txt");
    outfile << cramer;
    outfile.close();

    std::cout << "Reshenie zapisano v file: solution.txt" << std::endl;
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
