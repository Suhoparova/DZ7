// DZ7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>

#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void ViewArr(int* mas, int* size)
{
    cout << endl;
    for (int i = 0; i < *size; i++)
        cout << *(mas + i) << "\t";
    cout << endl;
}
void CreateArr(int* mas, int* size)                      
{
    for (int i = 0; i < *size; i++)
        *(mas + i) = rand() % (20 - (-20) + (-20));
    ViewArr(mas, size);
    
}

void ViewArr2(int* mas, const int* size)
{
    cout << endl;
    for (int i = 0; i < *size; i++)
        cout << *(mas + i) << "\t";
    cout << endl;
}
void CreateArr2(int* mas, const int* size)
{
    for (int i = 0; i < *size; i++)
        *(mas + i) = rand() % (20 - (-20)) + (-20);
    ViewArr2(mas, size);

}

int* CreatArr1(int& size)                                    
{
    cout << "Введите размер массива: ";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        *(arr + i) = rand() % ((10 - 1) + 1);
    return arr;
}

int* udal(int* arrA, int sizeA)
{
    //создаем временный массив
    int* bufferArr = new int[sizeA];
    int newSize = 0;
    int kol_delitel = 0;

    for (int i = 0; i < sizeA; i++)
    {
        kol_delitel = 0;
        for (int j = 1; j < arrA[i]; j++)
        {
            if (arrA[i] % j == 0)
            {
                kol_delitel++;
            }
        }

        if (kol_delitel <= 1)
        {
            //если кол-во делителей <=1, значит простое число
            //и записываем во временный массив
            bufferArr[newSize] = arrA[i];
            newSize++;
        }
    }
    int* resultArr = new int[newSize];
    cout << endl << "НОВЫЙ МАССИВ без простых чисел: ";
    for (int i = 0; i < newSize; i++)
    {
        resultArr[i] = bufferArr[i];
        cout << resultArr[i] << " ";
    }
    cout << endl;
    delete[] bufferArr;
    return resultArr;
}

void DinamicARR(int* mas, int size)
{
    int* arr2 = new int[size];
    int* arr3 = new int[size];
    int* arr4 = new int[size];

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i = 0; i < size; i++)
    {
        if (mas[i] == 0)
        {
            arr2[a] = mas[i];
            a++;
        }
        else if (mas[i] < 0)
        {
            arr3[b] = mas[i];
            b++;
        }
        else if (mas[i] > 0)
        {
            arr4[c] = mas[i];
            c++;
        }
    }

    cout << endl << endl;
    cout << "Вывод динамического массива c нулевыми элементами: ";
    cout << endl << endl;

    for (int i = 0; i < a; i++)
    {
        cout << arr2[i] << "\t";
    }

    cout << endl << endl;
    cout << "Вывод динамического массива с отрицательными элементами: ";
    cout << endl << endl;

    for (int i = 0; i < b; i++)
    {
        cout << arr3[i] << "\t";
    }

    cout << endl << endl;
    cout << "Вывод динамического массива с положительнми элементами: ";
    cout << endl << endl;

    for (int i = 0; i < c; i++)
    {
        cout << arr4[i] << "\t";
    }
    cout << endl << endl;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}

void removeChar(char* s, int c) 
{
    int j, n = strlen(s);
    for (int i = j = 0; i < n; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

bool polindrom(char str[100])
{
    int k = strlen(str);
    for (int i = 0; i < k / 2; ++i)
    {
        if (str[i] != str[k - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


/*Тема: Указатели.
Домашнее задание
Задание 1 :
    Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
    массив минимально возможного размера, в котором нужно собрать элементы массива A,
    которые не включаются в массив B, без повторений.*/

    /*int M, N, sizeC = 0;
    cout << "Введите размер массива A = ";
    cin >> M;
    int* A = new int[M];
    cout << "Введите размер массива B = ";
    cin >> N;
    int* B = new int[N];
    CreateArr(A, &M);
    CreateArr(B, &N);
    cout << endl;
    int np = 0;                             //узнаем размер массива C
    for (int i = 0; i < M; i++)
    {
        np = 0;
        for (int j = 0; j < N; j++)
            if (*(A + i) != *(B + j))
                np++;
        if (np == N)
            sizeC++;
    }
    cout << endl << "sizeC = " << sizeC << "\n";
    int* C = new int[sizeC];                   //объявляем массив C
    for (int i = 0, g = 0; i < M; i++)     //заполняем массив C
    {
        np = 0;
        for (int j = 0; j < N; j++)
            if (*(A + i) != *(B + j))
                np++;
        if (np == N)
        {
            *(C + g) = *(A + i);
            g++;
        } 
    }
    ViewArr(C, &sizeC);
    cout << endl;*/


    /*Задание 2 :
    Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
    массив минимально возможного размера, в котором нужно собрать элементы массивов A и B,
    которые не являются общими для них, без повторений.*/

    /*int M, N, sizeC = 0;
    cout << "Введите размер массива A = ";
    cin >> M;
    int* A = new int[M];
    cout << "Введите размер массива B = ";
    cin >> N;
    int* B = new int[N];
    CreateArr(A, &M);
    CreateArr(B, &N);
    cout << endl;
    int np = 0;                             //узнаем размер массива C
    for (int i = 0; i < M; i++)
    {
        np = 0;
        for (int j = 0; j < N; j++)
            if (*(A + i) != *(B + j))
                np++;
        if (np == N)
            sizeC++;
    }
    for (int i = 0; i < N; i++)
    {
        np = 0;
        for (int j = 0; j < M; j++)
            if (*(B + i) != *(A + j))
                np++;
        if (np == M)
            sizeC++;
    }
    cout << endl << "sizeC = " << sizeC << "\n";
    int* C = new int[sizeC];                               //объявляем массив C
    int g = 0;
    for (int i = 0; i < M; i++)
    {
        np = 0;
        for (int j = 0; j < N; j++)
            if (*(A + i) != *(B + j))
                np++;
        if (np == N)
        {
            *(C + g) = *(A + i);
            g++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        np = 0;
        for (int j = 0; j < M; j++)
            if (*(B + i) != *(A + j))
                np++;
        if (np == M)
        {
            *(C + g) = *(B + i);
            g++;
        }
    }
    ViewArr(C, &sizeC);
    cout << endl;*/

    /*Задание 3 :
    Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
    массив минимально возможного размера, в котором нужно собрать элементы обоих массивов.*/

    /*int M, N, sizeC = 0;
    cout << "Введите размер массива A = ";
    cin >> M;
    int* A = new int[M];
    cout << "Введите размер массива B = ";
    cin >> N;
    int* B = new int[N];
    CreateArr(A, &M);
    CreateArr(B, &N);
    cout << endl;
    sizeC = M + N;
    int* C = new int[sizeC];

    for (int i = 0, r = 0; i < sizeC; i++)
    {
        if (i < M)
            *(C + i) = *(A + i);
        else
        {
            *(C + i) = *(B + r);
            r++;
        }
    }
    ViewArr(C, &sizeC);
    cout << endl;*/


    /*Задание 4 :
    Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).Необходимо создать третий
    массив минимально возможного размера, в котором нужно собрать общие элементы двух
    массивов без повторений.*/

    //int M, N, sizeC = 0;
    //cout << "Введите размер массива A = ";
    //cin >> M;
    //int* A = new int[M];
    //cout << "Введите размер массива B = ";
    //cin >> N;
    //int* B = new int[N];
    //CreateArr(A, &M);
    //CreateArr(B, &N);
    //cout << endl;

    //int* C = new int[sizeC];                        //объявляем массив C
    //int r = 0;                                       //переменная для записи элементов в массив
    //int np = 0;
    //for (int i = 0; i < M; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //    {
    //        if (*(A + i) == *(B + j))                        //если значения в массивах равны, то пишем их в третий массив
    //        {
    //            np++;                                   //вычисляем размер массива
    //            *(C + r) = *(A + i);
    //            r++;
    //            *(B + j) = -M + -1;
    //            break;
    //        }
    //    }
    //    sizeC = np;
    //}  
    //cout << endl << "sizeC = " << sizeC << "\n"; 
    //ViewArr(C, &sizeC);
    //cout << endl;


    /*Задание 5 :
    Дан массив : А[M](M вводится с клавиатуры).Необходимо удалить из массива четные или
    нечетные значения.Пользователь вводит данные в массив, а также с помощью меню решает,
    что нужно удалить.*/

    /*int sizeA, sizeC=0;
    int znach;
    cout << "\nВведите размер массива A =\n";
    cin >> sizeA;
    int* A = new int[sizeA];
    CreateArr(A, &sizeA);
    cout << endl;
    int chet = 0;
    int nechet = 0;
    for (int i = 0; i < sizeA; i++)
    {
        if (*(A + i) % 2 == 0)
            chet++;
        else
            nechet++;
    }
    cout << endl << "нечетных = " << nechet << "\n";
    cout << endl << "четных = " << chet << "\n";
    cout << endl << "Введите четные убрать или нечетные - четные - 2, нечетные - 1:  znach = ";
    cin >> znach;

    if (znach == 1)
    {
        int* C = new int[chet];
        for (int i = 0,j=0; i < sizeA; i++)
        {
            if (*(A + i) % 2 == 0)
            {
                *(C + j) = *(A + i);
                j++;
            }
        }
       ViewArr(C, &chet);
       cout << endl;
    }
    else if (znach == 2)
    {
        int* C = new int[nechet];
        for (int i = 0, j = 0; i < sizeA; i++)
        {
            if (*(A + i) % 2 != 0)
            {
                *(C + j) = *(A + i);
                j++;
            }
        }
        ViewArr(C, &nechet);
        cout << endl;
    }*/


    /*Задание 6 :
    Написать функцию, которая получает указатель на динамический массив и его размер.Функция
    должна удалить из массива все простые числа и вернуть указатель на новый динамический
    массив.*/

    //int sizeA;
    //int* arrA = CreatArr1(sizeA);
    //ViewArr(arrA, &sizeA);
    //int* newArr;
    ////заполнение нового массива
    //newArr = udal(arrA, sizeA);
    //delete[] arrA;
    //delete[] newArr;
   

    /*Задание 7 :
    Написать функцию, которая получает указатель на статический массив и его размер.Функция
    распределяет положительные, отрицательные и нулевые элементы в отдельные динамические
    массивы.*/

    //const int size = 10;
    //int A[size];
    //int* pa = A;
    //CreateArr2(pa, &size);
    //DinamicARR(pa, size);
   


    /*Тема: Строки
    Домашнее задание
    Задание 1 :
    Написать функцию, которая удаляет из строки символ с заданным номером.*/

    /*char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    int k = strlen(str);
    char* pr = str;
    int i = 0;
    cout << "введите элемент, который надо удалить ";
    cin >> i;
    pr[i] = '\0';
    for (int j = 0; j < k; j++)
        cout << pr[j];
    cout << endl;*/

    /*Задание 2 :
    Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.*/

    /*char s[] = "cgcfvctcgvhvcvggg";
    cout << s;
    cout << endl << endl;
    removeChar(s, 'g');
    cout << s;
    cout << endl;*/


    /*Задание 3 :
    Написать функцию, которая вставляет в строку в указанную позицию заданный символ.*/

    /*string str;
    string n;
    cout << "введите строку - ";
    cin >> str;
    cout << str << endl;
    int v;
    cout << "введите позицию вставки нового элемента - ";
    cin >> v;
    cout << "введите новый элемент - ";
    cin >> n;
    str.insert(v, n);
    cout << str << endl;*/
   

    /*Задание 4 :
    Написать программу, которая заменяет все символы точки "." в строке, введенной
    пользователем, на символы восклицательного знака "!".*/

    /*string str;
    cout << "введите строку: \n";
    getline(cin, str);
    int k = str.length();
    for (int i = 0; i < k; i++)
    {
        if (str[i] == '.') 
            str[i] = '!';
    }
    cout << str << endl;*/
    

    /*Задание 5 :
    Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается
    в строке.*/

    /*char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    int k = strlen(str);
    int count = 0;
    char bukva;
    cout << "Введите букву: ";
    cin >> bukva;

    for (int i = 0; i < k; i++)
        if (str[i] == bukva)
            count++;
    cout << "В тексте буква " << bukva << " встречается " << count << " раз(а)." << endl;
    return 0;*/

    /*Задание 6 :
    Пользователь вводит строку.Определить количество букв, количество цифр и количество
    остальных символов, присутствующих в строке.
    Рекомендации :
    Для проверки, что символ является числом, не обязательно сравнивать его со всеми 10 - ю
    цифрами, достаточно сравнить код символа с диапазоном кодов цифр.Код символа 0 – 48, 1 –
    49, 2 – 50 …. 9 – 57.*/

    /*int i = 0, digit = 0, letter = 0;
    string str;
    cout << "введите строку: \n";
    getline(cin, str);
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9') digit++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')) letter++;
        i++;
    }
    cout << "цыфр = " << digit << "\nбукв = " << letter << "\nдругие символы = " << i - digit - letter << "\n";*/



    /*Задание 7 :
    Дана строка символов.Заменить в ней все пробелы на табуляции.*/

    /*char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    for (int i = 0; i < 100; i++)
    {
        if (str[i] == ' ')
            str[i] = '\t';
    }
    cout << str << endl;*/


    /*Задание 8 :
    Дана строка символов.Определить количество букв, цифр и остальных символов,
    присутствующих в строке.*/

   /* int i = 0, digit = 0, letter = 0;
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9') digit++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')) letter++;
        i++;
    }
    cout << "цыфр = " << digit << "\nбукв = " << letter << "\nдругие символы = " << i - digit - letter << "\n";*/

    /*Задание 9 :
    Подсчитать количество слов во введенном предложении.*/

    /*int slov = 0;
    string str;
    cout << "введите строку: \n";
    getline(cin, str);
    int k = str.length();
    for (int i = 0; i < k; i++)
    {
        if (str[i] == ' ')
            slov++;
    }
    cout << endl << "количество слов во введенном предложении - " << slov + 1;
    cout << endl;*/

    /*Задание 10 :
    Дана строка символов.Необходимо проверить является ли эта строка палиндромом*/

    /*char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);
    if (polindrom(str))
        cout << "строка является полиндромом";
    else
        cout << "строка не является полиндромом";*/
}


