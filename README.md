# Rozwiązania zadań stażowych c++ z Novomatic

***

## 1. Zawartość
Pliki z rozwiązaniami do poszczególnych zadań znajdują się w osobnych katalogach `task1`, `task2` oraz `task3`. Po pomyślnym skompilowaniu plików programy wynikowe umieszczane są w folderze `bin`, który znajduje się w katalogu każdego zadania, tj. `task1/bin`, etc. Ponadto dla zadania nr 3 tworzony jest test, którego lokalizacja to `task3/tests/test_task3.exe`.

## 2. Kompilacja
Kompilacja odbywa się z użyciem narzędzia CMake. Używałem tutaj kompilatora mingw (g++ 12.2.0) wraz z generatorem MinGW Makefiles, lecz powinno to również działać dla innych kompilatorów.

Aby prawidłowo zbudować projekt, należy przejść do głównego katalogu oraz uruchomić skrypt `setup.bat`, który uruchamia polecenie `cmake`.

1. `cd ./Novomatic_internship.cpp`

2. `./setup.bat`

Można również uruchomić kompilację ręcznie, przechodząc do głównego folderu i wydając komendę `cmake`.

1. `cd ./Novomatic_internship.cpp`
2. `cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release`