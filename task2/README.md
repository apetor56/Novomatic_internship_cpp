# Zadanie 2

---

## 1. Treść polecenia
### Korzystając z załączonego kodu znajdującego się w main.cpp, napisz kod który przesunie piksel z punktu A(0, 0) do punktu B(40, 0) w czasie 2000ms. Następnie do punktu C(40, 10) w czasie 3000ms i na koniec powróci do punktu A w czasie 1000ms. Ścieżka (A->B->C->A) powinna być powtórzona 5 razy.

## 2. Rozwiązanie
Czas renderowania i czyszczenia obrazu powodowały, że pixel nie mógł między innymi pokonać całej trasy powrotnej w czasie 1000ms (jeśli weźmiemy pod uwagę poruszanie się tylko o jedno pole). Należało tu więc wykorzystać ten czas, aby przesunąć pixel o odpowiednią liczbę miejsc w przód/tył. Liczba ta była obliczana w następujący sposób:

$$x += {delta : {czasDrogi \over liczbaPunktów}}$$
Podany przykład dotyczy obliczania pozycji `x` w trakcie ruchu do przodu.

