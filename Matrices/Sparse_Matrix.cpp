#include <iostream>
using namespace std;
class elements
{
public:
    int i, j, element;
};
class Sparse_Matrix
{
private:
    int m, n, num;
    elements *e;

public:
    void set_data(Sparse_Matrix *A);
    void display(Sparse_Matrix *A);
    Sparse_Matrix *Multiply(Sparse_Matrix A, Sparse_Matrix B);
    friend Sparse_Matrix *Add(Sparse_Matrix A, Sparse_Matrix B);
    ~Sparse_Matrix()
    {
        delete[] e;
    }
};
void Sparse_Matrix::display(Sparse_Matrix *A)
{
    int index_sum = 0;

    for (int i = 0; i < A->m; i++)
    {

        for (int j = 0; j < A->n; j++)
        {
            if (A->e[index_sum].i == i && A->e[index_sum].j == j)
            {
                std::cout << A->e[index_sum].element << "  ";
                index_sum++;
            }
            else
            {
                std::cout << "0  ";
            }
        }
        std::cout << endl;
    }
    std::cout << endl;
}
void Sparse_Matrix::set_data(Sparse_Matrix *A)
{
    cout << "Enter the dimension of the array\n Enter the number of rows : " << endl;
    cin >> A->m;
    cout << "Enter the number of columns : " << endl;
    cin >> A->n;
    cout << "Enter the number of number of non zero elements : " << endl;
    cin >> A->num;
    A->e = new elements[A->num];
    cout << "Enter all non zero elements : " << endl;
    for (int i = 0; i < A->num; i++)
    {
        cout << "enter  row : " << endl;
        cin >> A->e[i].i;
        cout << "enter  column : " << endl;
        cin >> A->e[i].j;
        cout << "enter  element : " << endl;
        cin >> A->e[i].element;
    }
}
Sparse_Matrix *Add(Sparse_Matrix A, Sparse_Matrix B)
{
    int index_A, index_B, index_sum;
    // cout << A.m << " " << B.m << endl;
    if (A.m != B.m || A.n != B.n)
    {
        return 0;
    }
    Sparse_Matrix *sum = new Sparse_Matrix;
    sum->m = A.m;
    sum->n = A.n;
    sum->num = A.num + B.num;
    index_A = index_B = index_sum = 0;
    sum->e = new elements[sum->num];
    // cout << sum->m << endl;
    // cout << sum->n << endl;
    // cout << sum->num << endl;
    while (index_A < A.num && index_B < B.num)
    {

        if (A.e[index_A].i < B.e[index_B].i)
        {
            // cout << "first if" << endl;
            sum->e[index_sum] = A.e[index_A];
            index_A++;
            index_sum++;
        }
        else if (A.e[index_A].i > B.e[index_B].i)
        {
            // cout << "first else if" << endl;
            sum->e[index_sum] = B.e[index_B];
            index_B++;
            index_sum++;
        }
        else
        {
            // cout << "first else" << endl;
            if (A.e[index_A].j < B.e[index_B].j)
            {
                // cout << "first if in else" << endl;
                sum->e[index_sum] = A.e[index_A];
                index_A++;
                index_sum++;
            }
            else if (A.e[index_A].j > B.e[index_B].j)
            {
                // cout << "first else if in else" << endl;
                sum->e[index_sum] = B.e[index_B];
                index_B++;
                index_sum++;
            }
            else
            {
                // cout << "first else in else" << endl;
                sum->e[index_sum] = B.e[index_B];
                sum->e[index_sum].element = (A.e[index_A].element) + (B.e[index_B].element);
                index_A++;
                index_B++;
                index_sum++;
            }
        }
    }
    for (; index_A < A.num; index_A++)
    {
        // cout << "for loop 1" << endl;
        sum->e[index_sum] = A.e[index_A];
        index_sum++;
    }
    for (; index_B < B.num; index_B++)
    {
        // cout << "For loop 2" << endl;
        sum->e[index_sum] = B.e[index_B];
        index_sum++;
    }
    sum->num = index_sum;
    // cout << "Add return " << endl;
    return sum;
}
Sparse_Matrix *Sparse_Matrix::Multiply(Sparse_Matrix A, Sparse_Matrix B)
{
    if (A.n != B.m)
    {
        return NULL;
    }
    else
    {
        int index_A, index_B, index_mul;
        index_A = index_B = index_mul = 0;
        Sparse_Matrix *Res;
        Res->n = A.m;
        Res->m = B.n;
        Res->num = A.num + B.num;
        Res->e = new elements[Res->num];
        while (index_A < A.num && index_B < B.num)
        {
            int result = 0;
            for (; index_A < A.num; index_A++)
            {
                for (; index_B < B.num; index_B++)
                {
                    if (A.e[index_A].element != 0 && A.e[index_B].element != 0)
                    {
                        result += (A.e[index_A].element * A.e[index_B].element);
                    }
                }
            }
        }
    }
}
int main()
{
    Sparse_Matrix X;
    Sparse_Matrix Y;
    X.set_data(&X);
    X.display(&X);
    Y.set_data(&Y);
    Y.display(&Y);
    Sparse_Matrix *Res = Add(X, Y);
    Res->display(Res);
    return 0;
}