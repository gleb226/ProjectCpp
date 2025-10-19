# 🚌 Transport Schedule Management System

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.10+-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-lightgrey?style=for-the-badge)

**A beautiful console-based C++ application for managing public transport schedules**

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Project Structure](#-project-structure) • [Documentation](#-documentation)

</div>

---

## 📖 About

This project is a comprehensive **Transport Schedule Management System** built in C++17. It demonstrates professional software engineering practices including CRUD operations, file persistence, data validation, and an intuitive colored console interface. Perfect for learning advanced C++ concepts or managing real transport data!

The system manages four interconnected entities: **Stops**, **Transports**, **Routes**, and **Schedules**, providing a complete solution for tracking public transportation systems.

---

## ✨ Features

### 🎯 Core Functionality

- **🚏 Stops Management**
    - Add, view, edit, and delete transport stops
    - Track stop names and locations
    - View stops without assigned routes

- **🚎 Transport Management**
    - Manage different types of transport (buses, trams, trolleys)
    - CRUD operations for all transport units
    - Track transport usage across routes

- **🗺️ Routes Management**
    - Create complex routes with multiple stops
    - Assign transport vehicles to routes
    - Update route configurations dynamically

- **📅 Schedule Management**
    - Create time-based schedules for routes
    - Time format validation (HH:MM)
    - View and manage all schedules

### 📊 Advanced Features

- **Comprehensive Reports**
    - Most popular stops analysis
    - Most utilized transport vehicles
    - Route statistics (number of stops per route)
    - Top 5 routes by stop count
    - Unused stops identification

- **Data Persistence**
    - Automatic save/load from text files
    - Structured data format for reliability
    - Graceful handling of missing files

- **Beautiful UI**
    - 🎨 Color-coded console interface
    - Intuitive menu navigation
    - Clear success/error messages
    - User-friendly prompts

### 🛡️ Quality Features

- ✅ Input validation
- 🔍 Search and filtering capabilities
- 📈 Statistical analysis
- 💾 File-based persistence
- 🎯 Modular architecture

---

## 🚀 Installation

### Prerequisites

- **CMake** 3.10 or higher
- **C++ Compiler** with C++17 support (GCC 7+, Clang 5+, MSVC 2017+)
- **Terminal** with ANSI color support

### Build Steps

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/transport-schedule-system.git
cd transport-schedule-system
```

2. **Create build directory**
```bash
mkdir build
cd build
```

3. **Configure and build**
```bash
cmake ..
cmake --build .
```

4. **Run the application**
```bash
./ProjectCpp        # Linux/macOS
ProjectCpp.exe      # Windows
```

---

## 💻 Usage

### Main Menu

```
====== Transport System ======
1. Manage Stops
2. Manage Transports
3. Manage Routes
4. Manage Schedules
5. Reports
6. Save Data
7. Load Data
0. Exit
==============================
```

### Quick Start Guide

1. **Add Stops** - Create transport stops with names and locations
2. **Add Transports** - Register buses, trams, or other vehicles
3. **Create Routes** - Assign transports and stops to routes
4. **Set Schedules** - Define departure times for routes
5. **Generate Reports** - Analyze your transport network
6. **Save Data** - Persist all changes to files

### Example Workflow

```cpp
// 1. Add a stop
Manage Stops → Add Stop
Name: Central Station
Location: Downtown, Main Street

// 2. Add transport
Manage Transports → Add Transport
Name: Bus #42

// 3. Create route
Manage Routes → Add Route
Name: Downtown Express
Transport ID: 1
Stop IDs: 1 2 3 4

// 4. Set schedule
Manage Schedules → Add Schedule
Route ID: 1
Time: 08:30
```

---

## 📁 Project Structure

```
📦 Transport Schedule System
├── 📄 main.cpp                    # Entry point
├── 📄 menu.cpp / menu.h           # Main menu interface
│
├── 🚏 Stop Module
│   ├── stop.cpp / stop.h          # Stop entity
│   └── stop_manager.cpp / .h      # Stop CRUD operations
│
├── 🚎 Transport Module
│   ├── transport.cpp / transport.h
│   └── transport_manager.cpp / .h
│
├── 🗺️ Route Module
│   ├── route.cpp / route.h
│   └── route_manager.cpp / .h
│
├── 📅 Schedule Module
│   ├── schedule.cpp / schedule.h
│   └── schedule_manager.cpp / .h
│
├── 💾 File I/O Module
│   └── file_io.cpp / file_io.h    # Data persistence
│
├── 📊 Reports Module
│   └── reports.cpp / reports.h    # Analytics & statistics
│
├── 🔧 Utilities
│   ├── utils.cpp / utils.h        # Helper functions
│   └── colors.h                   # ANSI color definitions
│
└── 🏗️ Build Configuration
    └── CMakeLists.txt             # CMake configuration
```

---

## 🗃️ Data Storage

The application stores data in four text files:

### `stops.txt`
```
ID|Name|Location
1|Central Station|Downtown, Main Street
```

### `transports.txt`
```
ID|Name
1|Bus #42
```

### `routes.txt`
```
ID|Name|TransportID|StopIDs
1|Downtown Express|1|1,2,3,4
```

### `schedules.txt`
```
ID|RouteID|Time
1|1|08:30
```

---

## 🎨 Color Scheme

The application uses a sophisticated color palette for better UX:

| Color | Usage |
|-------|-------|
| 🟢 **Green** | Success messages |
| 🔵 **Blue** | Information |
| 🟡 **Yellow** | Warnings |
| 🔴 **Red** | Errors |
| 🟣 **Purple/Lavender** | Menu options |
| 🍑 **Peach/Mint** | Headers |
| ⚪ **Gray** | Secondary info |

---

## 📊 Reports & Analytics

The system provides five types of analytical reports:

1. **Most Popular Stops** - Shows which stops are used in most routes
2. **Most Popular Transport** - Identifies the most utilized vehicles
3. **Route Statistics** - Displays number of stops per route
4. **Stops Without Routes** - Lists unused stops in the system
5. **Top Routes** - Shows top 5 routes by stop count

---

## 🧩 Technical Highlights

### C++ Features Used

- ✅ **STL Containers** - `vector`, `map`, `string`
- ✅ **Smart Memory Management** - RAII principles
- ✅ **File I/O Streams** - `fstream`, `ifstream`, `ofstream`
- ✅ **Lambda Expressions** - Used in filtering and sorting
- ✅ **Algorithms** - `find_if`, `sort`, `remove_if`, `unique`
- ✅ **Regular Expressions** - For time/date validation
- ✅ **Structures** - Data modeling with `struct`
- ✅ **Modular Design** - Separated headers and implementations
- ✅ **C++17 Standard** - Modern C++ practices

### Design Patterns

- **Manager Pattern** - Separate managers for each entity
- **Separation of Concerns** - UI, Business Logic, Data layers
- **DRY Principle** - Reusable utility functions
- **Single Responsibility** - Each module has one clear purpose

---

## 🛠️ Configuration

### CMake Configuration

The project uses CMake 3.10+ with C++17 standard:

```cmake
cmake_minimum_required(VERSION 3.10)
project(ProjectCpp)
set(CMAKE_CXX_STANDARD 17)
```

### Customization

You can customize colors by modifying `colors.h`:

```cpp
#define YOUR_COLOR "\033[38;5;XXXm"
```

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. 🍴 Fork the repository
2. 🔨 Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. 💾 Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. 📤 Push to the branch (`git push origin feature/AmazingFeature`)
5. 🎉 Open a Pull Request

### Ideas for Contribution

- 🌍 Add internationalization (i18n)
- 🔍 Implement advanced search filters
- 📱 Create a GUI version
- 🗄️ Add database support (SQLite)
- 📧 Export reports to PDF/Excel
- 🧪 Add unit tests
- 🎯 Implement route optimization algorithms

---

## 📝 Requirements Met

This project fulfills all university requirements:

✅ **4+ interconnected entities** (Stop, Transport, Route, Schedule)  
✅ **CRUD operations** for all entities  
✅ **Search, filter, and sorting** capabilities  
✅ **Input validation** (time format, business rules)  
✅ **File persistence** (save/load from text files)  
✅ **Statistical reports** with file output  
✅ **Colored console interface** with ANSI codes  
✅ **Multi-file architecture** (headers + implementations)  
✅ **STL usage** (vectors, maps, algorithms)  
✅ **Lambda functions** in sorting/filtering  
✅ **Modern C++ practices** (C++17 standard)

---

## 🐛 Known Issues & Future Improvements

### Current Limitations

- ⚠️ No data validation for duplicate entries
- ⚠️ Limited error handling for corrupted files
- ⚠️ No undo/redo functionality

### Planned Features

- 🔄 Auto-save functionality
- 🔐 User authentication system
- 📊 Graph visualization of routes
- 🌐 REST API integration
- 📱 Mobile companion app
- 🤖 AI-powered route optimization

---

## 📚 Learning Outcomes

This project demonstrates:

- Object-oriented design in C++
- File I/O operations and data persistence
- Console UI development with colors
- Data validation and error handling
- Modular architecture and code organization
- STL containers and algorithms
- Memory management best practices
- Build system configuration (CMake)

---

## 🏆 Academic Context

**Course**: Programming in C/C++  
**Topic**: Final Course Project  
**Objectives**:
- Implement complex data structures
- Demonstrate CRUD operations
- File-based data persistence
- Console UI with validation
- Modular code organization

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

Created with ❤️ for learning C++ and software engineering principles.

---

## 🙏 Acknowledgments

- Color scheme inspired by modern terminal applications
- Project structure follows C++ best practices
- Built as part of university curriculum requirements

---

<div align="center">

### ⭐ If you found this project helpful, please give it a star!

**Made with C++17 | CMake | Terminal Colors**

</div>