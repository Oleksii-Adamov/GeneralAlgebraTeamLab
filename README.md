# Командна лабораторна з Загальної Алгебри

## Інформація для команди:
### 1. Швидкість, оптимальність роботи програми.
Пам'ятайте, що швидкість важлива і оцінюється, тому передавайте змінні по конст референсам (const type&), якщо не плануєте їх змінювати. Можна використовувати std::vector, він працює досить швидко, якщо правильно їм користуватися, а саме, використовуйте emplace_back замість push_back, якщо ви їх створюєте і передаєте у вектор (читайте документацію), також можете подивитись це відео:

https://www.youtube.com/watch?v=HcESuwmlHEY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=47

### 2. Для пункту 3 і 4 записані відео (скинув у телеграм-каналі)

### 3. Найважливіше!! Правильно создавайте класи та файли у бібліотеці Lib. Алгоритм:

1. Create folder task(номер вашого завдвння)

2. Create classes/headears within that folder. For each header add 
#include "Lib_global.h"

and in header before every name of class type LIB_EXPORT
for example:

class LIB_EXPORT MyClass {...};

and in header before every function type LIB_EXPORT
for example:

LIB_EXPORT void my_function();

Не забувайте про #include "Lib_global.h" та LIB_EXPORT !!!!

3. Create auto test project (for every major test case) in GeneralAlgebraTeamProject 
  (do not name it same as your class (there will be errors otherwise))

In .pro file after TEMPLATE = app

DEPENDPATH += . ../Lib

INCLUDEPATH += ../Lib

LIBS += -L../Lib/debug/ -lLib

LIBS += -L../Lib/release/ -lLib

### 4. Важливо!! Алгоритм роботи з гітом:
#### Cloning repository:

git clone https://github.com/Oleksii-Adamov/University-assignments-2-nd-year-.git

#### Creating branch:

git checkout -b mybranch

/* commits*/

/* first push */

git push -u origin mybranch

/* subsequent (последующие) pushes*/

git push

#### Merging with main:

/* now in branch mybranch (Зараз на гілці mybranch)*/

git push

git checkout main

git pull

git chechout mybranch

git merge main

/* solving merge conflicts and ensure everything work locally (unit tests) (Фіксимо мердж конфлікти і перевіряємо чи
 все працює локально (тести проходить))*/
 
/* Create pull request and merge pull request in Github (через Github) */

git checkout main

git pull

git chechout mybranch