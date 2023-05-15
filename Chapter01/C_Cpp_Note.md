# Hinweis zu C/C++

## C90 Kompabilität des Kurses

Wenn ihr für euren Uni-Kurs C90 programmieren müsst, dann müsst ihr folgendes beachten, da wir hier in C99 programmieren:

- Verwendung von ```bool``` und ```#include <stdbool.h>``` existiert nicht in C90, anstatt dessen könnt ihr einfach ```int``` nehmen und anstatt ```true/false```: ```0/1``` returnen.
- Verwendung von ```uint32_t``` und ```#include <stdint.h>``` existiert nicht in C90, anstatt dessen könnt ihr einfach ```unsigned int``` nehmen.

## C++ Kompabilität des Kurses

Auch wenn wir innerhalb des Kurses in C (C99) implementieren, ist der code zu ~99% C++ kompatibel. Das heißt man kann ohne großen Aufwand den Code zu einem gültigen C++ Code umformen.
Dabei sind die folgenden Sachen zu beachten:

- Anstatt malloc, verwende ```new```, bzw. ```new[]```
- Anstatt free, verwende ```delete```, bzw. ```delete[]```
- Anstatt ```#include <stdint.h>```, verwende ```#include <cstdint.h>```
- Anstatt ```#include <string.h>```, verwende ```#include <cstring.h>```
- Die Dateiendung der Source Dateien sollte dann auch ```.cpp``` und nicht ```.c``` sein
- Nicht benötigter include: ```#include <stdbool.h>```
