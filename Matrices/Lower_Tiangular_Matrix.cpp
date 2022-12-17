#include <iostream>
using namespace std;
class Lower_Triangular_matrix
{
private:
    int *matrix;

public:
    int size;
    Lower_Triangular_matrix();
    int calc_index(int i, int j);
    void set_data(int i, int j, int element);
    int get_data(int i, int j);
    void display(Lower_Triangular_matrix a);
};
Lower_Triangular_matrix::Lower_Triangular_matrix()
{
    cout << "Enter the dimensions of the array " << endl;
    cin >> size;

    matrix = new int[(size * (size + 1)) / 2];
}
void Lower_Triangular_matrix ::set_data(int i, int j, int element)
{
    if (i >= j)
    {
        matrix[calc_index(i, j)] = element;
    }
}
int Lower_Triangular_matrix::get_data(int i, int j)
{
    if (i >= j)
    {
        return matrix[calc_index(i, j)];
    }
    else
    {
        return 0;
    }
}
int Lower_Triangular_matrix::calc_index(int i, int j)
{
    return (((i * (i - 1)) / 2) + (j - 1));
}
void Lower_Triangular_matrix::display(Lower_Triangular_matrix a)
{
    for (int i = 1; i <= a.size; i++)
    {
        for (int j = 1; j <= a.size; j++)
        {
            if (i >= j)
            {
                cout << a.matrix[calc_index(i, j)] << "  ";
            }
            else
            {
                cout << "0  ";
            }
        }
        cout << endl;
    }
}
int main()
{
    Lower_Triangular_matrix a;
    int x;
    for (int i = 1; i <= a.size; i++)
    {
        for (int j = 1; j <= a.size; j++)
        {
            cout << "Enter element for " << i << " " << j << " \n";
            cin >> x;
            a.set_data(i, j, x);
        }
    }
    a.display(a);
    return 0;
}