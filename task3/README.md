# Zadanie 3

---

## 1. Treść polecenia
#### Zaimplementuj obcinanie pewnego ciągu znaków z lewej i z prawej strony domomentu gdy podany predykat będzie spełniony.

#### Przykład : <br> Input: tekst: “ przykładowy string ”, <br> predykat: is whitespace <br> Output: “przykładowy string”
#### Im bardziej rozwiązanie będzie generyczne, tym lepiej. Testy mile widziane.

## 2. Rozwiązanie
Rozwiązanie problemu znajduje się w pliku `src/main.cpp`. Początkowe znaki obicnane są za pomocą metody `string::erase()` z wykorzystaniem iteratora `std::find_if_not()`, który przeszukuje podany string w celu znalezienia znaku, który nie spełnia predykatu. Ostatnie znaki podanego łańcucha znakowego są sprawdzane ręcznie, czy spełniają predykat i wtedy są usuwane.

Dodatkowo tworzony jest plik `src/task3.cpp`, który służy do utworzenie biblioteki. Jest ona następnie testowana w programie `tests/test_task3.exe` za pomocą [GoogleTest](https://github.com/google/googletest).

#### Program main.exe
Na wejściu podaje się dwa stringi. Pierwszy z nich to predykat, jego podanie zatwierdza się enterem. Drugi to string, z którego będą ucinane znaki - jego też zatwierdza się enterem. Na standardowym wyjściu wyświetlany jest przycięty string.
