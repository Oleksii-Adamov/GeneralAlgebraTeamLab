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

//int euler(int n)
//{
//    int euler = 1;
//    for(int i = 2; i <= n; i++)
//    {
//        if(NumberGCD(i,n) == 1)
//        {
//            euler++;
//        }
//    }
//    return euler;
//}

//int multCount(int q, int n, int i)
//{
//    return euler(n)/m(q,n,i);
//}


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
        Polinome p = queue.front();
        
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
            int k = q-1;

//            std::cout<<"Ri: "<<ri(q,n,i).toString()<<std::endl;
//            std::cout<<"Ri+1: "<<ri(q,n,i).add(Polinome("1").toString(),q).toString()<<std::endl;
//            std::cout<<"Ri-1: "<<ri(q,n,i).add(Polinome(std::to_string(k)),q).toString()<<std::endl;
//            std::cout<<"P: "<<p.toString()<<std::endl;
//            std::cout<<std::endl;

            Polinome p1 = *p.gcd(ri(q,n,i), q);
            if(degreeOfPolinome(p1) >= 1 && degreeOfPolinome(p1) < size)
            {
                queue.push(p1);
                isDivisor = true;
            }
            Polinome p2 = *p.gcd(ri(q,n,i).add(Polinome("1"),q),q);
            p2=p2.add(p2,q);// :)

            if(degreeOfPolinome(p2) >= 1 && degreeOfPolinome(p2) < size)
            {
                queue.push(p2);
                isDivisor = true;
            }
            
            Polinome p3 = *p.gcd(ri(q,n,i).add(Polinome(std::to_string(k)),q),q);
            p3=p3.add(p3,q);// :)
            if(degreeOfPolinome(p3) >= 1 && degreeOfPolinome(p3) < size)
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
    return res;
}
