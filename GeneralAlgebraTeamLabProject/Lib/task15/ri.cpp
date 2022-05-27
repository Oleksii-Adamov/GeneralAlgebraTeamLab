#include "ri.h"


//Fq Qn Ri

int NumberGCD(int a, int b) {
    if (a == 0) {
        return b;
    }
    return NumberGCD(b % a, a);
}

int m(int q, int n, int i)
{
    int m = 1;
    while((int)pow(q,m)%(n/NumberGCD(i,n)) != 1)
    {
        m++;
    }
    return m;
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

int d(int n, int q)
{
    int d=1;
    while((int)pow(n,d)%q != 1)
    {
        d++;
    }
    return d;
}

std::vector<Polinome> computePolynomialProductOfCyclotomicPlynomial(int q, int n)
{
    std::vector<Polinome> res;
    int i = 1;
    Polinome cyclotomic = *CyclotomicPolynomial(n,q).quotient;
    int dValue = d(q,n);

    bool isDivisor = false;

    std::queue<Polinome> queue;
    queue.push(cyclotomic);



    while(!queue.empty())
    {
        if(i%n == 0) i++;
        Polinome p = queue.front();
        
        //std::cout<<"P: "<<p.toString()<<std::endl;

        if(degreeOfPolinome(p) == dValue)
        {
            res.push_back(p);
            queue.pop();
            continue;
        }
        if(degreeOfPolinome(p)== 0)
        {
            queue.pop();
            continue;
        }
        else
        {
            int size = degreeOfPolinome(p);

            Polinome r = ri(q,n,i);
            for(int j = 0; j<q;j++)
            {
                Polinome t = p;
                Polinome r_t = r.add(Polinome(std::to_string(j)),q);
                t = *p.gcd(r_t, q);
                //std::cout<<"T"<<j<<": "<<t.toString()<<std::endl;

                if(degreeOfPolinome(t) >= 1 && degreeOfPolinome(t) < size)
                {
                    queue.push(t);
                    isDivisor = true;
                }
            }
            //std::cout<<std::endl;
            if(isDivisor)
            {
                queue.pop();
                isDivisor = false;
            }
            i++;
        }
    }   
    return res;
}
