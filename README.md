# C-OOP---PHARMACY

A small object-oriented pharmacy management project in modern C++.  
Implements core domain models, repositories and managers, plus a test suite. It is intended as an example of OOP design.

## What it does
- Models clients, products (drugs & supplements) and orders.
- Provides in-memory repositories for clients and orders.
- Provides high-level managers to register/unregister and query data
- Basic file-based persistence helpers write to disk under the `dysk/` folder.
- Includes unit tests for core behavior in `library/test/` using Boost.Test.


