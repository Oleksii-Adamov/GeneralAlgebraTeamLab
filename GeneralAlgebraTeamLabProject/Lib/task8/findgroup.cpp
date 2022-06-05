#include "findgroup.h"
#include <iostream>
#include <algorithm>

FindGroup::FindGroup(IntModulo order)
{
    SetGroup(order.get_num());
    FindPrimeFactorization();
}

void FindGroup::SetGroup(int order){
    group.clear();
    
    for(int i = 1; i < order; i++){
        int sum = 0;
        for(int j = 1; j <= order; j++){
            if(i % j == 0 && order % j == 0){
                sum++;
            }
        }
        if(sum == 1){
            group.push_back(i);
        }
    }
    this->degree = order;
}


IntModulo FindGroup::ElementOrder(IntModulo elem){ 
    if(std::find(group.begin(), group.end(), elem) != group.end()){
        std::map<IntModulo, IntModulo>::iterator itr = factorizationMap.begin();
        int result = 1;
        std::map<IntModulo, IntModulo> resMap;
        for(int i = 0; i < factorizationMap.size(); i++){
            auto elemC = elem;
            elemC.pow(itr->first.get_num(), this->degree);
            resMap.insert({elemC, itr->first});
        }
        std::map<IntModulo, IntModulo>::iterator it;
        it = resMap.find(IntModulo(1));
        if(it != resMap.end()){
            this->groupOrder = IntModulo(it->second);
        }
        else {
            this->groupOrder = IntModulo(0);
        }
        return this->groupOrder;
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
