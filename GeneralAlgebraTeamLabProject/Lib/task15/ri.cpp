#include "ri.h"


//Fq Qn Ri

long long NumberGCD(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    return NumberGCD(b % a, a);
}

long long m(long long q, long long n, long long i)
{
    long long m = 1;
    while((long long)pow(q,m)%(n/NumberGCD(i,n)) != 1)
    {
        m++;
    }
    return m;
}

Polinome ri(long long q, long long n, long long i)
{
    long long mValue = m(q,n,i);
    Polinome res = Polinome();
    for(long long j = 0; j < mValue; j++)
    {
        Polinome t = Polinome(i*pow(q,j));
        t.getCoefficients()->emplace_back(IntModulo(1));
        res = res.add(t,n);
    }
    return res;
}

long long d(long long n, long long q)
{
    long long d=1;
    while((long long)pow(n,d)%q != 1)
    {
        d++;
    }
    return d;
}

std::vector<Polinome> computePolynomialProductOfCyclotomicPlynomial(long long q, long long n)
{
    std::vector<Polinome> res;
    long long i = 1;
    Polinome cyclotomic = *CyclotomicPolynomial(n,q).quotient;
    long long dValue = d(q,n);

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
            long long size = degreeOfPolinome(p);

            Polinome r = ri(q,n,i);
            for(long long j = 0; j<q;j++)
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
