#include <iostream>
using namespace std;
class diagonal_matrix
{
private:
    int *matrix = new int[size]{};

public:
    int size;
    void set_data(int i, int j, int element)
    {
        if (i == j)
        {
            matrix[i - 1] = element;
        }
    }
    int get_data(int i, int j)
    {
        if (i == j)
        {
            return matrix[i - 1];
        }
        else
        {
            return 0;
        }
    }
    void display(diagonal_matrix a)
    {
        for (int i = 0; i < a.size; i++)
        {
            for (int j = 0; j < a.size; j++)
            {
                if (i == j)
                {
                    cout << a.matrix[i] << "  ";
                }
                else
                {
                    cout << "0  ";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    diagonal_matrix a;
    a.size = 4;
    a.set_data(1, 1, 2);
    a.set_data(2, 2, 4);
    a.set_data(3, 3, 6);
    a.set_data(4, 4, 8);
    cout << a.get_data(2, 2) << endl;
    a.display(a);
    return 0;
}