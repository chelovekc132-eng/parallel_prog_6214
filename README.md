# Parallel Programming — Laboratory Work 1

## Matrix multiplication

The program performs sequential multiplication of two square matrices.

### Requirements

- C++23 compiler
- CMake 3.20 or newer
- Python 3
- NumPy

### Project structure

```text
lab1/
├── cpp/
│   ├── main.cpp
│   ├── matrix.cpp
│   └── matrix.h
├── data/
│   ├── matrix_a.txt
│   ├── matrix_b.txt
│   └── result.txt
└── python/
    └── verify.py
```

### Input

The first line contains `N`, followed by `N*N` matrix elements.

### Output

The C++ program writes the resulting matrix to the specified output file
and prints:

- matrix size;
- number of elements;
- number of multiplications;
- number of additions;
- total arithmetic operations;
- approximate memory for the three matrices;
- execution time;
- performance in GFLOPS.

### Build

```bash
cmake -S . -B build
cmake --build build
```

### Run on Windows

```powershell
.\build\Debug\matrix_multiplication.exe lab1\data\matrix_a.txt lab1\data\matrix_b.txt lab1\data\result.txt
```

### Run on Linux/macOS

```bash
./build/matrix_multiplication lab1/data/matrix_a.txt lab1/data/matrix_b.txt lab1/data/result.txt
```

### Verification

Install NumPy:

```bash
python -m pip install numpy
```

Run:

```bash
python lab1/python/verify.py
```

The verification independently calculates `A @ B` using NumPy and compares
it with the result produced by the C++ program.

### Algorithm

Classical sequential matrix multiplication is used.

Time complexity: `O(N^3)`.

The loop order is `i-k-j`, which avoids repeatedly loading the same
`A[i][k]` value and provides a cache-friendly sequential implementation.
