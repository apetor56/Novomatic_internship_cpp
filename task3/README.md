# Zadanie 3

---

## 1. Treść polecenia
#### Zaimplementuj obcinanie pewnego ciągu znaków z lewej i z prawej strony domomentu gdy podany predykat będzie spełniony.

#### Przykład : <br> Input: tekst: “ przykładowy string ”, <br> predykat: is whitespace <br> Output: “przykładowy string”
#### Im bardziej rozwiązanie będzie generyczne, tym lepiej. Testy mile widziane.

## 2. Rozwiązanie
Rozwiązanie problemu znajduje się w pliku `src/main.cpp`. Początkowe znaki obicnane są za pomocą metody `string::erase()` z wykorzystaniem iteratora `std::find_if_not()`, który przeszukuje podany string w celu znalezienia znaku, który nie spełnia predykatu. Ostatnie znaki podanego łańcucha znakowego są sprawdzane ręcznie, czy spełniają predykat i wtedy są usuwane.

Dodatkowo tworzony jest plik `src/task3.cpp`, który służy do utworzenie biblioteki, która jest testowana w programie `tests/test_task3.exe` za pomocą [GoogleTest](https://github.com/google/googletest).