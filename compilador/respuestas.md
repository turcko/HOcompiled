# Compilador-Respuestas

El archivo `calculator.c` es un programa sencillo, que suma
dos números y los imprime en pantalla; así y todo compilarlo 
requiere un montón de pasos intermedios. Estos pasos los podemos 
clasificar en 4:

1. Pre-procesador: `make preprocessing`
2. Compilacion I: `make assembler`
3. Compilacion II: `make object`
4. Linkeo: `make executable`

Ejecutando cada una de las instrucciones de `make` van a poder
construir cada uno de los pasos intermedios.

Ejercicios:

En un archivo de texto `respuestas.md`:

1. Escriban qué esperan de cada uno de los pasos
	a. Pre-procesador: `make preprocessing` 
gcc -E calculator.c -o calculator.pp.c
El pre procesador forma parte del front end de la etapa de compilación.
Este debe analizar todo lo que está con # (includes, macros), es decir, la expansión de los macros en el código.

	b. Compilacion I: `make assembler`
gcc -S calculator.c -o calculator.asm
gcc -S -masm=intel calculator.c -o calculator.asm  (para generar sintaxis de asemble de Intel)
El make assembler forma parte del back end. 
Transforma el código optimizado en la etapa del middle end a lenguaje ensamblador. En esta etapa se realizan optimizaciones de acuerdo al hardware donde se ejecuta la computador.

	c. Compilacion II: `make object`
gcc -c calculator.c -o calculator.o
make object genera los objetos en binario. 
Lo que se ve al ejecutar el comando nm (interpretador de archivos binarios) es:
-------------------------------------
000000000000003c T add_numbers
0000000000000000 T main
                 U printf
-------------------------------------
T: símbolos de texto global.
U: símbolos indefinidos.

	d. Linkeo: `make executable`
gcc -v calculator.o -o calculator.e
Genera el archivo ejecutable. 

2. ¿Qué agregó el preprocesador?
El preprocesador agrega los encabezados, y reemplaza los macros donde son necesarios.

3. Identificar en la rutina de assembler las funciones
gcc -S -masm=intel calculator.c -o calculator.asm  (para generar sintaxis de assembler de Intel, sino por defecto está el formato Bell)
----------------------------------------------------
.LC0:
	.string	"I know how to add! 31 + 11 is %d\n"
	.text
	.globl	main
	.type	main, @function
add_numbers:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], edi
	mov	DWORD PTR [rbp-8], esi
	mov	eax, DWORD PTR [rbp-8]
	mov	edx, DWORD PTR [rbp-4]
	add	eax, edx
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
----------------------------------------------------
4. Explicar qué quieren decir los símbolos que se crean en el objeto
Loe símbolos que se crean en el objeto son los descriptores. Algunos de estos son:

    A : Global absolute symbol.
    a : Local absolute symbol.
    B : Global bss symbol.
    b : Local bss symbol.
    D : Global data symbol.
    d : Local data symbol.
    f : Source file name symbol.
    L : Global thread-local symbol (TLS).
    l : Static thread-local symbol (TLS).
    T : Global text symbol.
    t : Local text symbol.
    U : Undefined symbol.

5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?
En esta etapa se agregan identificadores relacionados al change loading de ejecución del archivo, por ejemplo:
N
    The symbol is a debugging symbol.
p
    The symbols is in a stack unwind section.
R
r
    The symbol is in a read only data section.
S
s
    The symbol is in an uninitialized data section for small objects.
T
t
    The symbol is in the text (code) section.
U
    The symbol is undefined.
u
    The symbol is a unique global symbol. This is a GNU extension to the standard set of ELF symbol bindings. For such a symbol the dynamic linker will make sure that in the entire process there is just one symbol with this name and type in use.
-------------------------------------------
0000000000400569 T add_numbers
0000000000601040 B __bss_start
0000000000601040 b completed.6973
0000000000601030 D __data_start
0000000000601030 W data_start
0000000000400470 t deregister_tm_clones
00000000004004e0 t __do_global_dtors_aux
0000000000600e18 t __do_global_dtors_aux_fini_array_entry
0000000000601038 D __dso_handle
0000000000600e28 d _DYNAMIC
0000000000601040 D _edata
0000000000601048 B _end
00000000004005f4 T _fini
0000000000400500 t frame_dummy
0000000000600e10 t __frame_dummy_init_array_entry
0000000000400778 r __FRAME_END__
0000000000601000 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000004003e0 T _init
0000000000600e18 t __init_array_end
0000000000600e10 t __init_array_start
0000000000400600 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
0000000000600e20 d __JCR_END__
0000000000600e20 d __JCR_LIST__
                 w _Jv_RegisterClasses
00000000004005f0 T __libc_csu_fini
0000000000400580 T __libc_csu_init
                 U __libc_start_main@@GLIBC_2.2.5
000000000040052d T main
                 U printf@@GLIBC_2.2.5
00000000004004a0 t register_tm_clones
0000000000400440 T _start
0000000000601040 D __TMC_END__

(siéntanse libres, si quieren, de usar la sintaxis markdown. no hace falta)