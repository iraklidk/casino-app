# Tech Assignment for Europebet

Welcome to my submission for the tech assignment! This repository contains my solution to the task provided. Below you'll find an overview of the project and how to run it.

# Project Overview
- Objective: The objective of this assignment was to create a C++ application that simulates a casino's transaction processing system.
- Approach: I implemented the solution using object-oriented principles, focusing on efficiency and maintainability. The Customer class handles individual transactions, and the main cpp file(CasinoPromotionCoreSystem.cpp) orchestrates the application's flow.

# How to Run
### Prerequisites
- C++ Compiler (g++)
- Docker (optional, for containerized execution)

#### Build the Docker Image
```
docker build -t casino-app .
```
#### Run the Docker Container
```
docker run -v D:/[dir]:/data casino-app
```
