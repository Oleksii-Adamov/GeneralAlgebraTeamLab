#include "ri.h"


//Fq Qn Ri

int GCD(int a, int b) {
    if (a == 0) {
        return b;
    }
    return GCD(b % a, a);
}

int m(int q, int n, int i)
{
    int m = 1;
    while((int)pow(q,m)%(n/GCD(i,n)) != 1)
    {
        m++;
    }
    return m;
}

int euler(int n)
{
    int euler = 1;
    for(int i = 2; i <= n; i++)
    {
        if(GCD(i,n) == 1)
        {
            euler++;
        }
    }
    return euler;
}

int multCount(int q, int n, int i)
{
    return euler(n)/m(q,n,i);
}


Polinome ri(int q, int n, int i)
{
    int mValue = m(q,n,i);
    Polinome res = Polinome();
    for(int j = 0; j < mValue; j++)
    {
        Polinome t = Polinome(i*pow(q,j));
        t.getCoefficients()->emplace_back(IntModulo(1));
        res = res.add(t,n);
    }
    return res;
}

int d(int q, int n)
{
    int d=1;
    while((int)pow(n,d)%q != 1)
    {
        d++;
    }
    return d;
}

int degreeOfPolinome(Polinome p) {
    int degree = 0;
    for (int i = p.getCoefficients()->size()-1; i >= 0; i--)
    {
        if ((*p.getCoefficients())[i] != 0)
        {
            degree = i;
        }
    }
    return degree;
}


std::vector<Polinome> computePolynomialProductOfCyclotomicPlynomial(int q, int n, int i)
{
    std::vector<Polinome> res;
    int j = 1;
    Polinome cyclotomic = cyclotomicPolynomial(q,n);    
    int dValue = d(q,n);

    bool isDivisor = false;

    std::queue<Polinome> queue;
    queue.push(cyclotomic);

    while(!queue.empty())
    {
        Polinome p = queue.front();
        
        if(p.getCoefficients()->size() == dValue+1)
        {
            res.push_back(p);
            queue.pop();
        }
        if(p.getCoefficients()->size() == 1)
        {
            queue.pop();
            continue;
        }
        else
        {
            int size = p.getCoefficients()->size();
            Polinome p1 = PolynomialGCD(p,ri(q,n,i));
            if(p1.getCoefficients()->size() >= 1 && p1.getCoefficients()->size() < size)
            {
                queue.push(p1);
                isDivisor = true;
            }
            Polinome p2 = PolynomialGCD(p,ri(q,n,i).add(Polinome("1"),q));
            if(p2.getCoefficients()->size() >= 1 && p2.getCoefficients()->size() < size)
            {
                queue.push(p2);
                isDivisor = true;
            }
            
            Polinome p3 = PolynomialGCD(p,ri(q,n,i).add(Polinome("-1"),q));
            if(p3.getCoefficients()->size() >= 1 && p3.getCoefficients()->size() < size)
            {
                queue.push(p3);
                isDivisor = true;
            }

            if(isDivisor)
            {
                queue.pop();
                isDivisor = false;
            }
            i++;
        }
    }   
}
