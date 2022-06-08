#include "findgroup.h"
#include <iostream>
#include <algorithm>

FindGroup::FindGroup(IntModulo order)
{
    SetGroup(order.get_num());
    // FindPrimeFactorization();  
}

void FindGroup::SetGroup(int order){
    group.clear();
    
    for(int i = 1; i < order; i++){
        if(RelativelyPrime(order,i)){
            group.push_back(i);
        }
    }
    this->degree = order;
}


IntModulo FindGroup::ElementOrder(IntModulo elem){ 
    if(std::find(group.begin(), group.end(), elem) != group.end()){
        std::vector<int> groupDividers = findDivisors(group.size());

        for(int i = 0; i < groupDividers.size(); i++){
            auto elemC = elem;
            elemC.pow(groupDividers[i], this->degree);
            if(elemC.get_num() == 1){
                return groupDividers[i];
            }
        }
    } 
    else {
        return IntModulo(0);
    }
}

bool FindGroup::FindGroupGenerator(IntModulo elem){
    if(std::find(group.begin(), group.end(), elem) != group.end()){
        std::set<IntModulo> groupSet;
        for(int i = 1; i < degree; i++){
            IntModulo a = elem;
            a.pow(i, degree);
            groupSet.insert(a);
        }

        std::vector<IntModulo> setVectorCopy;
        std::set<IntModulo>::iterator it;
        for(it = groupSet.begin(); it != groupSet.end(); ++it){
            setVectorCopy.push_back(*it);
        }
        sort(setVectorCopy.begin(), setVectorCopy.end());
        if(setVectorCopy.size() == group.size()){
            for(int i = 0; i < group.size(); i++){
                if(setVectorCopy[i] != group[i]){
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

int FindGroup::get_degree(){
    return this->degree;
}

long long FindGroup::get_groupOrder(){
    return groupOrder.get_num();
}

std::vector<int> FindGroup::findDivisors(int n)
{
    std::vector<int> vec;
    for (int i=1; i<=n/2; i++)
    {
        if (n%i == 0)
        {
            vec.push_back(i);

        }

    }
    vec.push_back(n);
    return vec;
}

 void FindGroup::FindPrimeFactorization(){
     int degreeCopy = this->degree;
     std::vector<IntModulo> factorization;
    
     for (long long d = 2; d * d <= degreeCopy; d++) {
         while (degreeCopy % d == 0) {
             factorization.push_back(IntModulo(d));
             degreeCopy /= d;
         }
     }
     if (degreeCopy > 1)
         factorization.push_back(IntModulo(degreeCopy));


     for(int i = 0; i < factorization.size(); i++){
         std::map<IntModulo, IntModulo>::iterator item;
         item = factorizationMap.find(factorization[i]);

         if(item == factorizationMap.end()){
             int sum = 0;
             for(int j = i; j < factorization.size(); j++){
                 if(factorization[i].get_num() == factorization[j].get_num()){
                     sum++;
                 }
             }
             this->factorizationMap.insert(std::pair<IntModulo, IntModulo>(IntModulo(factorization[i]), IntModulo(sum)));
         }
     }
 }

bool FindGroup::isPrime(int n)
{
    // Corner cases
    if (n <= 1)
     return false;
    if (n <= 3)
     return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
     return false;

    // Using concept of prime number
    // can be represented in form of
    // (6*n + 1) or(6*n - 1) hence
    // we have to go for every multiple of 6 and
    // prime number would always be 1 less or 1 more then
    // the multiple of 6.
    for (int i = 5; i * i <= n; i = i + 6)
     if (n % i == 0 || n % (i + 2) == 0)
         return false;

    return true;
}

bool FindGroup::RelativelyPrime (int a, int b) { // Assumes a, b > 0
   return (a<b) ? RelativelyPrime(b,a) : !(a%b) ? (b==1) : RelativelyPrime (b, a%b);
}
