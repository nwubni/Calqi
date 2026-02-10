# Calqi - Command-Line Calculator

A fast, lightweight command-line calculator for Linux/Unix systems. Calqi provides natural mathematical expression evaluation with comprehensive function support, perfect for terminal users who need quick calculations without leaving the command line.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![C++20](https://img.shields.io/badge/C++-20-blue.svg)](https://en.cppreference.com/w/cpp/20)

## Features

### Basic Operations
- **Arithmetic**: `+`, `-`, `*`, `/`, `%`, `^` (exponentiation)
- **Parentheses**: Full support for nested expressions
- **Operator Precedence**: Follows standard mathematical order

### Mathematical Functions
- **Basic**: `abs`, `sqrt`, `neg`
- **Trigonometric**: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`
- **Hyperbolic**: `sinh`, `cosh`, `tanh`, `asinh`, `acosh`, `atanh`
- **Logarithmic**: `log` (base-10), `ln` (natural)
- **Rounding**: `floor`, `ceil`
- **Other**: `fact` (factorial), `rand` (random number generator)

### Constants
- **π (pi)**: Use `pi` in expressions
- **e**: Euler's number

### Interactive Mode
- GNU Readline integration with command history
- Persistent history across sessions (`.calc_history`)
- Arrow keys for navigation and history recall

## Installation

### From .deb Package (Debian/Ubuntu)

```bash
# Download the latest release
wget https://github.com/nwubni/Calqi/releases/download/v1.0.0/calqi-v1-00.deb

# Install
sudo dpkg -i calqi-v1-00.deb

# If dependencies are missing
sudo apt-get install -f
```

### Build from Source

**Requirements:**
- C++20 compatible compiler (GCC 10+ or Clang 10+)
- CMake 3.10+
- GNU Readline library

**Ubuntu/Debian:**
```bash
sudo apt-get install build-essential cmake libreadline-dev
```

**Build:**
```bash
# Clone the repository
git clone https://github.com/nwubni/Calqi.git
cd Calqi

# Build with CMake
mkdir build && cd build
cmake ..
make

# Create .deb package (optional)
cpack

# Install (optional)
sudo make install

# Or build manually
g++ -std=c++20 -o calqi src/main.cpp src/parsers/calculator_parser.cpp \
    src/library/calculator_functions.cpp src/utilities/function_validator.cpp -lreadline
```

## Usage

### Command-Line Mode

```bash
# Basic arithmetic
calqi "2 + 3"                    # 5
calqi "10 * (5 + 3)"            # 80
calqi "2^8"                      # 256

# Functions
calqi "sin(pi/2)"               # 1
calqi "sqrt(16)"                # 4
calqi "log(1000)"               # 3
calqi "fact(5)"                 # 120

# Complex expressions
calqi "(3 + 4) * 2 - 8 / 4"    # 12
calqi "sin(pi) + cos(0)"        # 1
calqi "floor(3.7) + ceil(2.1)" # 7

# Unary negation
calqi "8--2"                    # 10
calqi "7*-3"                    # -21
calqi "-3+5"                    # 2

# Random numbers
calqi "rand(100)"               # Random number 1-100
```

### Interactive Mode

```bash
# Start interactive mode
calqi

# Then type expressions
> 2 + 3
Answer: 5

> sin(pi/4)
Answer: 0.707106781186548

> exit
```

**Interactive Features:**
- Use ↑/↓ arrow keys to navigate history
- Ctrl+R for reverse search
- Tab completion (if configured)
- Type `exit`, `quit`, or `q` to quit (or press Ctrl+D)

## Examples

### Scientific Calculations
```bash
calqi "sin(pi/6)"               # 0.5
calqi "log(100) + ln(e)"        # 3
calqi "sinh(1)"                 # 1.1752
```

### Engineering
```bash
calqi "2^10"                    # 1024 (bytes in KB)
calqi "sqrt(2) * 100"           # 141.421 (diagonal)
```

### Quick Math
```bash
calqi "15 * 1.08"               # Tax calculation
calqi "(100 - 75) / 100 * 100"  # Percentage
calqi "fact(6) / (fact(2) * fact(4))" # Combinations
```

### Shell Scripting

Calqi can be used in shell scripts, but requires text processing to extract just the numeric result since it outputs `"Answer: <number>"`.

**Extracting the result:**
```bash
# Using awk to get the second field (the number after "Answer:")
result=$(calqi "2 + 3" | awk '{print $2}')
echo $result  # Output: 5

# Using awk + xargs to also trim any whitespace/newlines
result=$(calqi "pi * 5^2" | awk '{print $2}' | xargs)
echo $result  # Output: 78.5398163397448
```

**Explanation:**
- `awk '{print $2}'` - Splits output by whitespace and extracts the 2nd field (the number after "Answer:")
- `xargs` - Trims leading/trailing whitespace and newlines

**Complete example:**
```bash
#!/bin/bash

# Calculate tax in a script
price=100
tax=$(calqi "$price * 1.08" | awk '{print $2}' | xargs)
echo "Total with tax: $tax"

# Use in loops
for i in {1..5}; do
    result=$(calqi "$i^2" | awk '{print $2}' | xargs)
    echo "$i squared = $result"
done

# Conditional logic
area=$(calqi "pi * 5^2" | awk '{print $2}' | xargs)
if (( $(echo "$area > 75" | bc -l) )); then
    echo "Area is large: $area"
fi
```

**Output:**
```
Total with tax: 108
1 squared = 1
2 squared = 4
3 squared = 9
4 squared = 16
5 squared = 25
Area is large: 78.5398163397448
```

## Function Reference

### Arithmetic Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `+` | Addition | `5 + 3` = 8 |
| `-` | Subtraction | `5 - 3` = 2 |
| `*` | Multiplication | `5 * 3` = 15 |
| `/` | Division | `6 / 3` = 2 |
| `%` | Modulo | `7 % 3` = 1 |
| `^` | Exponentiation | `2 ^ 3` = 8 |

### Mathematical Functions
| Function | Description | Domain | Example |
|----------|-------------|--------|---------|
| `abs(x)` | Absolute value | All reals | `abs(-5)` = 5 |
| `sqrt(x)` | Square root | x ≥ 0 | `sqrt(16)` = 4 |
| `neg(x)` | Negation | All reals | `neg(5)` = -5 |
| `fact(n)` | Factorial | n ≥ 0, integer | `fact(5)` = 120 |
| `floor(x)` | Round down | All reals | `floor(3.7)` = 3 |
| `ceil(x)` | Round up | All reals | `ceil(3.2)` = 4 |
| `rand(n)` | Random 1 to n | n > 0, integer | `rand(10)` = 1-10 |

### Trigonometric Functions

**Note:** Trigonometric functions require radians as input.

| Function | Description | Example |
|----------|-------------|---------|
| `sin(x)` | Sine (radians) | `sin(pi/2)` = 1 |
| `cos(x)` | Cosine (radians) | `cos(0)` = 1 |
| `tan(x)` | Tangent (radians) | `tan(pi/4)` ≈ 1 |
| `asin(x)` | Arcsine, \|x\| ≤ 1 | `asin(0.5)` ≈ 0.524 |
| `acos(x)` | Arccosine, \|x\| ≤ 1 | `acos(0.5)` ≈ 1.047 |
| `atan(x)` | Arctangent | `atan(1)` ≈ 0.785 |

### Hyperbolic Functions
| Function | Description | Example |
|----------|-------------|---------|
| `sinh(x)` | Hyperbolic sine | `sinh(0)` = 0 |
| `cosh(x)` | Hyperbolic cosine | `cosh(0)` = 1 |
| `tanh(x)` | Hyperbolic tangent | `tanh(0)` = 0 |
| `asinh(x)` | Inverse hyperbolic sine | `asinh(0)` = 0 |
| `acosh(x)` | Inverse hyperbolic cosine, x ≥ 1 | `acosh(1)` = 0 |
| `atanh(x)` | Inverse hyperbolic tangent, \|x\| < 1 | `atanh(0)` = 0 |

### Logarithmic Functions
| Function | Description | Domain | Example |
|----------|-------------|--------|---------|
| `log(x)` | Base-10 logarithm | x > 0 | `log(100)` = 2 |
| `ln(x)` | Natural logarithm | x > 0 | `ln(e)` = 1 |

## Testing

Run the comprehensive test suite (78 tests):

```bash
# Build tests
g++ -std=c++20 tests/test_calculator.cpp src/parsers/calculator_parser.cpp \
    src/library/calculator_functions.cpp src/utilities/function_validator.cpp \
    -o test_calculator

# Run tests
./test_calculator
```

Test coverage includes:
- Basic arithmetic operations
- Operator precedence
- Parentheses handling
- All mathematical functions
- Negation
- Stress tests (large numbers, deep nesting, long chains)
- Edge cases and error handling

## Man Page

View the manual page:

```bash
man calqi
```

## Project Structure

```
calqi/
├── src/
│   ├── main.cpp                      # Entry point
│   ├── library/
│   │   ├── calculator_functions.cpp  # Core evaluation logic
│   │   ├── calculator_functions.h
│   │   └── math_functions.h          # Function implementations
│   ├── parsers/
│   │   ├── calculator_parser.cpp     # Expression parser
│   │   └── calculator_parser.h
│   └── utilities/
│       ├── function_validator.cpp    # Input validation
│       ├── function_validator.h
│       ├── function_error_messages.h # Error messages
│       ├── math_constants.h          # Constants (pi, e)
│       └── operator_list.h           # Recognized operators
├── tests/
│   └── test_calculator.cpp           # Unit tests
├── docs/
│   └── calqi.1                       # Man page
├── CMakeLists.txt                    # Build configuration
└── README.md
```

## Technical Details

- **Language**: C++20
- **Dependencies**: GNU Readline
- **Parsing**: Stack-based expression evaluation (not recursive descent)
- **Precision**: Double-precision floating-point (IEEE 754)
- **Epsilon handling**: Division by values < 1e-10 treated as division by zero
- **Factorial limit**: Returns infinity for n > 170 (double overflow)

## Error Handling

Calqi provides clear error messages for invalid inputs:

```bash
calqi "sqrt(-1)"
# Error: Square root function (sqrt) requires one operand greater than or equal to 0

calqi "log(0)"
# Error: Logarithm (log) function requires one operand greater than 0

calqi "10/0"
# Error: Division by zero

calqi "fact(3.5)"
# Error: Factorial function (fact) requires one non-negative integer operand
```

## Comparison with Alternatives

| Feature | Calqi | bc | Python | calc |
|---------|-------|----|----|------|
| Syntax | Natural | Awkward | Verbose | Natural |
| Functions | Built-in | Requires -l | Requires import | Many |
| Speed | Fast | Fast | Slower | Fast |
| Interactive | Yes | Yes | Yes | Yes |
| One-liner friendly | ✓ | ✗ | ✗ | ✓ |
| Shell scripting | ✓ | ✓ | ✓ | ✓ |

**Example comparison:**
```bash
# Calqi
calqi "sin(pi)"

# bc
echo "s(4*a(1))" | bc -l

# Python
python -c "import math; print(math.sin(math.pi))"

# calc
calc "sin(pi())"
```

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

**Nakuru Wubni**
- Email: nwubni@gmail.com
- GitHub: [@nwubni](https://github.com/nwubni)

## Acknowledgments

- GNU Readline for interactive input handling
- C++ Standard Library for mathematical functions
- The open-source community for inspiration

---
