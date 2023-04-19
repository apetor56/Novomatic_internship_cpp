# Zadanie 1
---
## 1. Treść polecenia
#### Zaimplementuj funkcję `isColliding` zwracającą `true` jeśli dwa trójkąty w przestrzeni 2D kolidują ze sobą. Następnie napisz wizualizator tej kolizji. Trójkąty powinny być widoczne na ekranie i co najmniej jeden z nich możliwy do sterowania przez użytkownika. Kolizja powinna być w jakiś sposób zasygnalizowana użytkownikowi.

## 2. Rozwiązanie
Implementacja funkcji `isColliding(t1, t2)` znajduje się w pliku `Triangle.cpp`. Funkcja ta wykorzystuje funkcję pomocniczą `isPointInside(t1, t2)`, która z wykorzystaniem własności iloczynu wektorowego sprawdza, czy któryś z wierzchołków trójkąta `t2` znajduje się wewnątrz trójkąta `t1`. Funkcja pomocznicza wywoływana jest dwukrotnie, ze zmienioną kolejnością trójkątów, podawanych jako argumenty.

Wizualizację zadania wykonałem za pomocą [napisanych już wcześniej przeze mnie klas](https://github.com/apetor56/Knights-Tour), które implementowały różne działania graficzne wykonywane z użyciem `OpenGL`. Do interakcji z trójkątami wykorzystałem bibliotekę [ImGui](https://github.com/ocornut/imgui). Jeśli dochodzi do kolozji trójkątów, to są one od siebie odsuwane.
