#Multilenguaje

En esta carpeta hay 6 subdirectorios:

- **01-f-from-f**: Llamar una subrutina de FORTRAN desde un programa en FORTRAN
- **02-c-from-c**: Llamar una subrutina de C desde un programa en C
- **03-cpp-from-cpp**: Llamar una subrutina de C++ desde un programa en C++
- **04-c-from-f**: Llamar una subrutina de C desde un programa en FORTRAN
- **05-f-from-c**: Llamar una subrutina de FORTRAN desde un programa en C
- **06-cpp-from-c**: Llamar una subrutina de C++ desde un programa en C


Los primeros tres directorios son de referencia, y están completos.


Ejercicio:

Los otros tres subdirectorios están incompletos así que tienen que
crear los archivos de FORTRAN y de C (dependiendo el caso) para tener
un ejecutable en cada carpeta que cumpla los requisitos. Pueden usar
los directorios de referencia, copiar los archivos que necesiten a
cada carpeta y editarlos para poder comunicarlos entre sí.

En cada carpeta tienen que estar los archivos que agregaron y cómo los
compilaron. Pueden hacer un `Makefile`. Si no quieren escribir un
`Makefile`, o no están muy cómodos con la sintaxis, escriban un
archivo de texto `reglas.txt` en cada subdirectorio en el que digan
qué comandos usaron para compilar. En las reglas para compilar, tienen
que estar diferenciados los pasos de compilación y linkeo.
