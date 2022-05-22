#include "findgroup.h"

FindGroup::FindGroup(const std::string& multiplicativeGroup, IntModulo a)
{
    SetGroup(multiplicativeGroup);
    FindPrimeFactorization();
    IntModulo t = IntModulo(this->degree);

    std::map<IntModulo, IntModulo>::iterator it;
    for(it = this->factorizationMap.begin(); it != this->factorizationMap.end(); it++){
        IntModulo b = it->first.get_num();
        b.pow(it->second.get_num(), 1);
        t = IntModulo(t.get_num() / b.get_num());
        a.pow(t.get_num(), 1);
        while(a.get_num() != 1){
            a.pow(it->first.get_num(), 1);
            t.multiply(it->first, 1);
        }
    }
    groupOrder = t;
}

void FindGroup::SetGroup(const std::string& multiplicativeGroup){
    group.clear();
    group.resize(2);
    
    std::string substring = "";
    for(int i = 0; i <= multiplicativeGroup.length(); i++){
        if(multiplicativeGroup[i] != ' '){
            substring += multiplicativeGroup[i];
        }
        else{
            group[1].push_back(IntModulo(substring));
            substring.clear();
        }
    }
    group[1].push_back(IntModulo(substring));

    group[0].resize(group[1].size());
    for(int i = 0; i < group[1].size(); i++){
        group[0][i] = i + 1;
    }
    this->degree = group[1].size();
}

void FindGroup::FindPrimeFactorization(){
    std::vector<IntModulo> factorization;
        
    for (long long d = 2; d * d <= this->degree; d++) {
        while (this->degree % d == 0) {
            factorization.push_back(IntModulo(d));
            this->degree /= d;
        }
    }
    if (this->degree > 1)
        factorization.push_back(IntModulo(this->degree));

    for(int i = 0; i < factorization.size(); i++){
        std::map<IntModulo, IntModulo>::iterator item;
        item = factorizationMap.find(factorization[i]);

        if(item == factorizationMap.end()){
            int sum = 0;
            for(int j = i + 1; j < factorization.size(); j++){
                if(factorization[i].get_num() == factorization[j].get_num()){
                    sum++;
                }
            }
            this->factorizationMap.insert(std::pair<IntModulo, IntModulo>(item->first, IntModulo(sum)));
        }
    }    
}

int FindGroup::get_degree(){
    return this->degree;
}

IntModulo FindGroup::get_groupOrder(){
    return groupOrder;
}