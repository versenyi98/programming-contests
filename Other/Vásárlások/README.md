#### Téma: Dinamikus programozás, Feladat: Vásárlások

N termék
K nap

N^2 * K tömb   
```
    0 1 2 3 4 5 6 7 8 9 10 = K   
000   
001   
010   
100   

110   
101   
011   

111   
= N^2     
```
Mindegyik cellában az érték a legoptimálisabb költség amellyel el lehet oda jutni, minden értékhez annyi cellát kell megnézni, amennyi termék meg van már vásárolva, +1, az előző napi érték  