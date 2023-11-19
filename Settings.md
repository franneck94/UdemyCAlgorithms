# Tooling

## Compiler

Any GCC, Clang or MSVC Compiler

## IDE: Visual Studio Code

- [Visual Studio Code](https://code.visualstudio.com/)

### VSCode Extensions

- Coding Tools Extension Pack (franneck94)
- C/C++ Extension Pack (franneck94)

### Extra settings (for local .vscode/settings.json file)

```json
    // Linux Only
  "C_Cpp_Runner.linkerArgs": [
      "-lm"
  ],
```

## C/C++ Runner zum Kompilieren und Ausführen

### Windows and Linux

- Compile: Zahnrad unten in der Leiste
- Run: Play Icon unten in der Leiste

### Windows User mit MSVC Compiler

Euch steht es auch frei den MSVC Compiler (von z.b. VS2022) in meiner C/C++ Runner Erweiterung zu verwenden.  
Dazu müsst ihr in der .vscode/settings.json Datei die folgende Zeile haben:

```json
"C_Cpp_Runner.useMsvc": true,
```
