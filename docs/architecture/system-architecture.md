
# Sensor & Signal Analysis Workbench
## System Architecture

### 1. Overview

SSAW is a modular desktop application designed
for sensor data ingestion, signal processing,
statistical analysis, and anomaly detection.

### 2. Architecture Layers

#### Presentation Layer
- Qt 6 desktop interface
- Dataset selection
- Signal visualization
- Analysis results and charts

#### Application Layer
- Application workflows
- Dataset management
- Analysis orchestration
- Export coordination

#### Core Layer
- Signal data models
- Statistical calculations
- Signal-processing algorithms
- Domain interfaces

#### Infrastructure Layer
- CSV file ingestion
- SQLite persistence
- Logging
- Filesystem operations

### 3. Design Principles

- Separation of concerns
- Modular development
- Testability
- Reusability
- Maintainability
- C++20 compatibility

### 4. Technology Stack

- C++20
- CMake
- Qt 6
- Catch2
- SQLite
- Python 3
- Git and GitHub

### 5. Testing Strategy

Unit tests will validate core algorithms
independently of the desktop interface.

Integration tests will validate interactions
between application and infrastructure layers.
