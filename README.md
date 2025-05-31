# 🧭 Maze Solver in C++

A console-based Maze Solver implemented in modern C++, demonstrating two fundamental graph traversal algorithms: **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**.



## 🚀 Features

- Accepts user-defined maze (2D grid)
- Supports both **BFS** and **DFS** traversal methods
- Object-Oriented design with a clean `MazeSolver` class
- Interactive command-line interface for ease of use
- Console-based maze visualization



## 🧠 How It Works

- The maze is modeled as a 2D grid where:
  - `1` represents an open cell
  - `0` represents a blocked cell (wall)
- The user provides:
  - Maze dimensions
  - Grid values
  - Start and goal coordinates
- The program then solves the maze using the chosen algorithm and shows whether the goal is reachable.



## 📦 Getting Started

 1. **Clone the Repository**


 ```sh
   git clone https://github.com/AyanMujawar/maze-solver-cpp.git
   cd maze-solver-cpp
   ```
2. **Compile the code:**
   ```sh
   g++ main.cpp -o maze_solver
   ```


3. **Run the program:**
   ```sh
   ./maze_solver
   ```

## 🧪 Example Run
Enter number of rows and columns: 3 3
Enter the maze (1 for open, 0 for blocked):
1 1 0
0 1 0
1 1 1
Enter starting point (x y): 0 0
Enter goal point (x y): 2 2

Menu:
1. Print the maze
2. Solve using BFS
3. Solve using DFS
4. Exit
Enter your choice: 2
Goal reached using BFS at: 2, 2

## 📁 File Structure

maze-solver-cpp/
├── main.cpp       # Main source code with MazeSolver class
├── README.md      # Project documentation
└── .gitignore     # Ignored files (optional)


## 📚 Algorithms Used
Breadth-First Search (BFS)
Finds the shortest path by exploring all neighbors level by level.

Depth-First Search (DFS)
Explores as far as possible along one path before backtracking.

## 🛠 Concepts Demonstrated
STL Data Structures: queue, stack, vector, pair

Graph traversal in 2D grid representation

Object-Oriented Programming in C++

Clean and modular code practices

## 🤝 Contributing
Contributions are welcome!
Feel free to open issues or submit pull requests for improvements, enhancements, or bug fixes.

## 📄 License
This project is open source.
You can add an appropriate license file as per your preference (e.g., MIT, Apache 2.0).

## 👨‍💻 Author
Ayan Mujawar
[GitHub Profile](https://github.com/AyanMujawar)

