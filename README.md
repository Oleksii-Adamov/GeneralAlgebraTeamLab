# Командна лабораторна з Загальної Алгебри

## Інформація для команди:
### 1. КОМЕНТАРІ !!! Будь ласка коментуйте ваш код.
### 2. Швидкість, оптимальність роботи програми.
Пам'ятайте, що швидкість важлива і оцінюється, тому передавайте змінні по конст референсам (const type&), якщо не плануєте їх змінювати. Можна використовувати std::vector, він працює досить швидко, якщо правильно їм користуватися, а саме, використовуйте emplace_back замість push_back, якщо ви їх створюєте і передаєте у вектор (читайте документацію), також можете подивитись це відео:

https://www.youtube.com/watch?v=HcESuwmlHEY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=47

### 3. Для пункту 4, 5, 6(там я не дописав git clean -fd) записані відео (скинув у телеграм-каналі)

### 4. Найважливіше!! Правильно создавайте класи та файли у бібліотеці Lib. Алгоритм:

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

### 5. Важливо!! Алгоритм роботи з гітом:
#### Cloning repository:

git clone https://github.com/Oleksii-Adamov/University-assignments-2-nd-year-.git

#### Creating branch:

git checkout -b mybranch

/* commits*/

/* first push */

git push -u origin mybranch

/* subsequent (наступні) pushes*/

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

git push
 
/* Create pull request and merge pull request in Github (через Github) */

git checkout main

git pull

git chechout mybranch

#### Solving merge conflicts:

Я не знайшов у Qt mergetool, тому встановлював свою kdiff3, можете використовувати щось інше (тільки не забувайте видаляти .orig файли).

1. Встановлюємо kdiff3 за посиланням:
	http://kdiff3.sourceforge.net/
2. У git bash пишемо:

git config --global merge.tool kdiff3
	
git config --global mergetool.kdiff3.path "C:/Program Files/KDiff3/kdiff3.exe"

git config --global mergetool.kdiff3.trustExitCode false

git config --global diff.guitool kdiff3

git config --global difftool.kdiff3.path "C:/Program Files/KDiff3/kdiff3.exe"

git config --global difftool.kdiff3.trustExitCode false

3. Коли після git merge виникли конфлікти, пишемо у git bash:

git mergetool

/* Вирішуєш конфлікти, зберігаємо, закриваємо kdiff3 */

git commit -m ""

/*Видаляємо .orig файли за допомогою наступної команди (ну насправдні всі untracked, тому якщо у вас є інші потрібні untracked файли, використовуйте щось інше */

git clean -fd