# QuantNet-Cpp-Homework

Homework submissions for the course **"C++ Programming for Financial Engineering"** on QuantNet.com, offered by Baruch College.

✅ Completed with **Distinction** (April 2025)  [PDF of Certificate](quantnet_c++_cert.pdf)
📘 Author: David Leather

---

## Final Project
- **Title**: Option Pricing Class Design  
- **Location**: [View Final Project Directory](Level%209/9.ab/9.ab)  
- **Full Report**: [View Technical Write-Up](Level%209/9.ab/readme.pdf)

---

## Overview

This final project implements a robust and extensible option pricing library focused on **European** and **Perpetual American** options. It leverages **object-oriented** and **generic programming** techniques with a heavy emphasis on **modularity**, **template design**, and **numerical accuracy**.

### ✅ Key Features:
- **Black-Scholes pricing** for European call/put options
- **Put-call parity** implementation and validation
- **Greeks** (Delta, Gamma, Vega, Theta) computed analytically and numerically
- **Perpetual American option** pricing using closed-form solutions
- **Matrix pricing engine** using flexible functors and mesh generation
- Uses both **Boost** and **C++ STL**, with fallback to `std::function` and lambdas for functional abstraction

### 🛠️ Design Architecture:
- Abstract base classes: `OptionContract`, `EuropeanOption`, `PerpetualAmericanOption`
- Concrete classes: `EuropeanCall`, `EuropeanPut`, `PerpetualAmericanCall`, `PerpetualAmericanPut`
- Utilities: `MatrixPricer`, `MeshGenerator`, `NormalDistribution`

### 🔬 Numerical Accuracy:
- Divided differences implemented for Delta and Gamma
- Detailed analysis of **step size sensitivity**
- Error minimized with optimal `h` ~ `1e-3` to `1e-4`

### 📊 Example Result:
| Batch | Parameters | Expected Call | Computed Call | Match |
|-------|------------|---------------|----------------|--------|
| 1 | T=0.25, K=65, σ=0.30, r=0.08, S=60 | 2.13337 | 2.13337 | ✅ |
| 2 | T=1.0, K=100, σ=0.20, r=0.00, S=100 | 7.96557 | 7.96557 | ✅ |

---

## Technical Highlights

- Implements the **Clone pattern** for polymorphic duplication
- Applies the **Strategy pattern** for pricing, Greeks, and matrix operations
- Uses **template metaprogramming** to support different numeric types
- Clean separation of concerns and modular class interfaces
- Fallback to `std::function` + lambda functions for flexible functor support

---

## Challenges Addressed

- Numerical instability in divided differences
- Accurate handling of edge cases in perpetual option pricing
- Template complexity and abstract base class inheritance in option hierarchy
- Parameter mesh generation and 2D grid computation using functors

---

## 💡 Lessons Learned

This project deepened my understanding of:
- C++ class design patterns in numerical computing
- The importance of balancing truncation vs. round-off error
- Generic programming for scalable quantitative libraries
- Functional abstraction for flexible simulation interfaces
