# Parhuzamos_algoritmusok
A féléves feladatnak a gyökkereső szelő módszert választottam. Ezt megcsináltam szekvenciálisan és párhuzamosan.
Párhuzamosítást Posix szálakkal és OpenMP függvénykönyvtárral értem el.

Az alábbi harmadfokú egyenletnek határoztam meg a gyökét 10^-8 -os pontosággal.

![függvénykép.png](https://github.com/HKristof2130/Parhuzamos_algoritmusok/blob/main/Feleves_feladat/f%C3%BCggv%C3%A9nyk%C3%A9p.png)

Itt azt mértem 1,2,3 szálon, hogy mennyi idő alatt fut le a program és ezt vetettem össze az OpenMP-s és szekvenciális futási idővel.

![mértem](https://github.com/HKristof2130/Parhuzamos_algoritmusok/blob/main/Feleves_feladat/Szel%C5%91%20m%C3%B3dszer%20posix%20sz%C3%A1l.png)

A 3. beadandó egy kódoló algoritmust az ún. Subtitution-Ciphernek egy kezdő változatát programoztam le.
Itt azt mértem, hogy egy "nagy" bemenet estén(egy random generált string ami a c fájlok elején kommentbe megtalálható) mennyi időbe telik 10 darab kódolás és dekódolás.


![mértem](https://github.com/HKristof2130/Parhuzamos_algoritmusok/blob/main/Feleves_feladat/Sub-Cipher.png)
