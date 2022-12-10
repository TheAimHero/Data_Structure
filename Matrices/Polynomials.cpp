#include <iostream>
#include <cmath>
using namespace std;
class Elements
{
public:
    int coeff, expo;
};
class Polynomials
{
private:
    int num;
    Elements *e;

public:
    void set_data();
    int evaluate(int x);
    void display();
    friend Polynomials *Add(Polynomials f1, Polynomials f2);
};
void Polynomials::set_data()
{
    cout << "Enter the number of non zero elements : ";
    cin >> num;
    cout << endl;
    e = new Elements[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the co-efficient and exponent of term number " << i + 1 << " : ";
        cin >> e[i].coeff >> e[i].expo;
        cout << endl;
    }
}
int Polynomials::evaluate(int x)
{
    int result = 0;
    for (int i = 0; i < num; i++)
    {
        result += (e[i].coeff * pow(x, e[i].expo));
    }
    return result;
}
Polynomials *Add(Polynomials f1, Polynomials f2)
{
    int index_f1, index_f2, index_add;
    index_f1 = index_f2 = index_add = 0;
    Polynomials *add = new Polynomials;
    add->num = f1.num + f2.num;
    add->e = new Elements[add->num];
    while (index_f1 < f1.num && index_f2 < f2.num)
    {
        if (f1.e[index_f1].expo < f2.e[index_f2].expo)
        {
            add->e[index_add] = f2.e[index_f2];
            index_add++;
            index_f2++;
        }
        else if (f1.e[index_f1].expo > f2.e[index_f2].expo)
        {
            add->e[index_add] = f1.e[index_f1];
            index_add++;
            index_f1++;
        }
        else
        {
            add->e[index_add] = f2.e[index_f2];
            add->e[index_add].coeff = f1.e[index_f1].coeff + f2.e[index_f2].coeff;
            index_add++;
            index_f1++;
            index_f2++;
        }
    }
    for (; index_f1 < f1.num; index_f1++)
    {
        add->e[index_add] = f1.e[index_f1];
        index_add++;
    }
    for (; index_f2 < f2.num; index_f2++)
    {
        add->e[index_add] = f2.e[index_f2];
        index_add++;
    }
    add->num = index_add;
    return add;
}
void Polynomials::display()
{
    for (int i = 0; i < num; i++)
    {
        cout << e[i].coeff << "*x^" << e[i].expo;
        if (i != (num - 1))
        {
            cout << "+";
        }
    }
}
int main()
{
    Polynomials P, Q;
    int result;
    cout << "Enter first polynomial : " << endl;
    P.set_data();
    P.display();
    return 0;
}
