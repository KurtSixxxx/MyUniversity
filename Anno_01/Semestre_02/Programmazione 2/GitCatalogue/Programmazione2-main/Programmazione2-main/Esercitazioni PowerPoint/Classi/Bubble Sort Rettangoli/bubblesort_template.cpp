#include <iostream>

class Rettangolo
{
private:
    int base;
    int altezza;

public:
    Rettangolo(int base, int altezza) : base(base), altezza(altezza) {}

    Rettangolo() : base(0), altezza(0){};

    void setBase(int b)
    {
        base = b;
    }

    int const getBase()
    {
        return base;
    }

    void setAltezza(int a)
    {
        altezza = a;
    }

    int const getAltezza()
    {
        return altezza;
    }

    int const getArea()
    {
        return base * altezza;
    }

    int const getPerimetro()
    {

        return 2 * base + 2 * +altezza;
    }
};

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void bubbleSort(T vec[], int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (typeid(T) == typeid(Rettangolo))
            {
                if (((Rettangolo *)vec[i])->getArea() < ((Rettangolo *)vec[c])->getArea())
                {
                    swap(vec[c], vec[i]);
                }
            }
            else if (vec[i] < vec[c])
            {
                swap(vec[c], vec[i]);
            }
        }
    }
}

int main()
{
    int arr1[5] = {2, 8, 12, 56, 32};
    char arr2[3] = {'d', 'a', 'e'};
    Rettangolo *arr3[3];

    arr3[0] = new Rettangolo(2, 4);
    arr3[1] = new Rettangolo(3, 5);
    arr3[2] = new Rettangolo(8, 10);

    std::cout << "Array non ordinato : [ ";

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << " ";
    }

    std::cout << "] " << std::endl;

    bubbleSort<int>(arr1, 3);

    std::cout << "Array ordinato : [ ";

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << " ";
    }

    std::cout << "] " << std::endl;

    std::cout << "Array non ordinato : [ ";

    for (int i = 0; i < 3; i++)
    {
        std::cout << arr2[i] << " ";
    }

    std::cout << "] " << std::endl;

    bubbleSort<char>(arr2, 3);

    std::cout << "Array ordinato : [ ";

    for (int i = 0; i < 3; i++)
    {
        std::cout << arr2[i] << " ";
    }

    std::cout << "] " << std::endl;
}
